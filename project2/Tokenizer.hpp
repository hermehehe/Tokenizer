#ifndef _TOKENIZER_HPP_
#define _TOKENIZER_HPP_
#include "Dictionary.hpp"
#include "Hashtable.hpp"
#include <iostream>
using namespace std;

//Hermela Gebretsion
class Tokenizer {
    public:
    //member variables, functions
    Tokenizer(int m);
    ~Tokenizer();
    bool insert(const std::string& input_word);
    bool tokenizeFile(std::fstream& fin);
    int tokenize(std::string input_word);
    int computeKey(const std::string& input_word);
    std::string print(int k);
    std::string retrieve(int tok);


    private: 
    Dictionary* dict;
    Hashtable* hash;
    
};


#endif


