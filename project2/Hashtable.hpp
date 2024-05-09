#ifndef _HASHTABLE_HPP_
#define _HASTABLE_HPP_
#include "Link.hpp"
#include <iostream>
#include <fstream>

using namespace std;
//Hermela Gebretsion
class Hashtable {
    public:
    //member variables, functions
    Hashtable(int m);
    ~Hashtable();

    //getter
    int get_hashArraySize();
    Link** get_hashArray();
    private: 
    Link** hashArray; //an array of linked lists
    int hashArraySize;
};


#endif


