#ifndef _LINKEDLIST_HPP_
#define _LINKEDLIST_HPP_

#include <iostream>
#include "Item.hpp"

using namespace std;
//Hermela Gebretsion

class Link {
    public:
    //constructor, destructor, member functions
    Link(); 
    ~Link();

    Item* get_head();
    void set_head(Item* head);
    
    //private member variables 
    private: 
    Item *p_head;
    

};

#endif