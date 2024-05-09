#ifndef _DICTIONARY_HPP_
#define _DICTIONARY_HPP_

#include <iostream>
using namespace std;
// Hermela Gebretsion

class Dictionary
{
public:
    // member variables, functions
    Dictionary(int m);
    ~Dictionary();

    void resizeArray();

    //getters
    int get_size();
    int get_index();
    void add_index();
    std::string* get_array();

    //setters
    void set_size(int updated_size);


private:
    int size;
    int index;
    std::string *words;
};



#endif