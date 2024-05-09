#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#include <iostream>
using namespace std;
//Hermela Gebretsion
class Item {
    public:
    //member variables, function
    Item(int t, const std::string& w);
    ~Item();
    Item *get_next_Item();
    int get_token();
    std::string get_word();
    void set_next(Item* next);
    private: 
    int token;
    std::string word;
    Item *p_next;
    
};


#endif


