#include <iostream>
#include "Tokenizer.hpp"
#include <cmath>
#include <cctype>

//////////*************Item Definitons*************//////////////////
// constructor
Item::Item(int t, const std::string &w)
{
    token = t;
    word = w;

    p_next = nullptr;
}
// destructor
Item::~Item()
{
}

// getters
Item *Item::get_next_Item()
{
    return p_next;
}
int Item::get_token()
{
    return token;
}
std::string Item::get_word()
{
    return word;
}

// setter
void Item::set_next(Item *next)
{
    p_next = next;
}
//////////*************LinkedList Definitons*************//////////////////
//constructor
Link::Link()
{
    p_head = nullptr;
}
//destructor 
Link::~Link()
{
    Item *current = p_head;
    while (current != nullptr)
    {
        // create temporary pointers to walk through linked list
        Item *p_temp = current;
        current = current->get_next_Item();
        delete p_temp;
    }
    p_head = nullptr;
}
//getters and setters
Item *Link::get_head()
{
    return p_head;
}
void Link::set_head(Item *head)
{
    p_head = head;
}

//////////*************Hashtable Definitons*************//////////////////
// Constructor
Hashtable::Hashtable(int m)
{
    hashArray = nullptr;
    hashArray = new Link *[m];
    for (int i = 0; i < m; i++)
    {
        hashArray[i] = new Link();
    }
    hashArraySize = m;
}

// Destructor
Hashtable::~Hashtable()
{
    if (hashArray != nullptr)
    {
        for (int i = 0; i < hashArraySize; i++)
        {
            delete hashArray[i];
        }
        delete[] hashArray;
        hashArray = nullptr;
    }
}

//getters
int Hashtable::get_hashArraySize()
{
    return hashArraySize;
}

Link **Hashtable::get_hashArray()
{
    return hashArray;
}

//////////*************Dictionary Definitons*************//////////////////
// Constructor//
Dictionary::Dictionary(int m)
{
    index = 0;
    size = m;
    words = new std::string[size]; 
}
//Destructor
Dictionary::~Dictionary()
{
    delete[] words;
    words = nullptr;
}
//setters and getters
std::string *Dictionary::get_array()
{
    return words;
}

int Dictionary::get_size()
{
    return size;
}
int Dictionary::get_index()
{
    return index;
}
void Dictionary::add_index()
{
    index++;
}

void Dictionary::set_size(int updated_size)
{
    size = updated_size;
    return;
}

void Dictionary::resizeArray()
{
    // resize array if poisiton = size member variable
    // typical runtime of O(1) worst case O(n)

    if (index < size)
    {
        return;
    }

    std::string *temp_array = words;
    int capacity = size * 10;
    std::string *bigger_dictionary = new std::string[capacity];

    for (int i = 0; i < size; i++)
    {
        bigger_dictionary[i] = temp_array[i];
    }
    if (words != nullptr)
    {
        delete[] words;
        words = nullptr;
    }

    words = bigger_dictionary;

    size = capacity;
    return;
}

// Member Functions//

//////////*************Tokenizer Definitons*************//////////////////
// Constructor
Tokenizer::Tokenizer(int m)
{
    dict = new Dictionary(m);
    hash = new Hashtable(m);
}
//Destructor
Tokenizer::~Tokenizer()
{

    if (dict != nullptr)
    {
        delete dict;
        dict = nullptr;
    }
    if (hash != nullptr)
    {
        delete hash;
        hash = nullptr;
    }
}

//Member functions

int Tokenizer::computeKey(const std::string &input_word)
{ // computs key value
    int asciiValue = 0;

    for (int i = 0; i < input_word.length(); i++)
    {
        asciiValue = asciiValue + (int)input_word.at(i);
    }

    return asciiValue;
}

std::string Tokenizer::retrieve(int tok)
{
    std::string *wordArray = dict->get_array();

    if (tok > dict->get_size() || tok <= 0)
    {
        return "UNKNOWN";
    }
    if (wordArray[tok - 1].empty())
    {
        return "UNKNOWN";
    }

    else
    {
        return wordArray[tok - 1];
    }
}

int Tokenizer::tokenize(std::string input_word)
{
    int m = hash->get_hashArraySize();
    int k = this->computeKey(input_word);
    int hash_index = k % m;

    Link **hashArray = hash->get_hashArray();
    Link *linked_list = hashArray[hash_index];

    if (linked_list != nullptr)
    { // if the linked list is not empty, search for the word
        Item *link_head = linked_list->get_head();
        Item *temp = link_head;

        while (temp != nullptr)
        {
            if (temp->get_word() == input_word)
            { // once the word is found return its token
                return temp->get_token();
            }
            else
            {
                temp = temp->get_next_Item();
            }
        }
    }
    else
        return 0;

    return 0;
}

bool Tokenizer::insert(const std::string &input_word)
{
    // checking for valid string
    for (int i = 0; i < input_word.length(); i++)
    { // check all chars of 1 string
        if (!isalpha(input_word.at(i)))
        {
            return false;
        }
    }
    // find key of word
    if (this->tokenize(input_word) == 0)
    {
        dict->resizeArray();
        std::string *wordArray = dict->get_array();

        int current_index = dict->get_index();

        // checking size of dictionary before inserting word
        wordArray[current_index] = input_word; // add word to dictionary
        Item *hashWord = new Item(current_index + 1, input_word);

        // add word hashtable
        int m = hash->get_hashArraySize();
        int k = this->computeKey(input_word);

        int hash_index = k % m;
        // if p_head of linked list is nullptr, assignit to held, else assign to next
        // available spot
        Link **hashArray = hash->get_hashArray();
        Link *linked_list = hashArray[hash_index];
        Item *link_head = linked_list->get_head();

        if (link_head == nullptr)
        { // if linked list is empty set head to new word
            linked_list->set_head(hashWord);
        }
        else
        { // if linked list is not empty insert new word at the front, making it the new head
            hashWord->set_next(link_head);
            linked_list->set_head(hashWord);
        }

        dict->add_index(); // update index position

        return true;
    }

    else
    { // return
        return false;
    }
}

bool Tokenizer::tokenizeFile(std::fstream &fin) 
{                                               
    std::string toRead;
    char current_char;
    bool valid_string;
    bool word_added = false;
    // other variables?
    while (fin >> toRead)
    { // to read contains next word in file
        valid_string = true;
        for (int i = 0; i < toRead.length(); i++)
        { // check all chars of 1 string
            if (!isalpha(toRead.at(i)))
            {
                valid_string = false;
                break;
            }
        }

        if (valid_string)
        {
            this->insert(toRead);

            if (!word_added){
                word_added = true;
            }
        }
      
    }

    return word_added;
}

std::string Tokenizer::print(int k)
{

    // get to linked list at hash_index of the hashtable
    if (k >= hash->get_hashArraySize() || k<0){
        return "chain is empty";
    }

    else{
    Link **hashArray = hash->get_hashArray();
    Link *linked_list = hashArray[k];
    Item *link_head = linked_list->get_head();
    Item *temp = link_head;
    if (link_head == nullptr)
    {
        return "chain is empty";
    }

    else
    {
        
        int key;
        string all_keys;
        while (temp != nullptr)
        {
            cout<<"working"<<endl;
            key = this->computeKey(temp->get_word());
            all_keys = all_keys + to_string(key)+ " " ;

            temp = temp->get_next_Item();
        }

        return all_keys;
    }
    }
    
}
