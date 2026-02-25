#pragma once
#include<iostream>
#include <vector>

class setList
{
    std::vector<int> vec;

public:

    int getSize();  
    void printSet(); 
    void insert(int x);
    void withdraw(int x);
    void clearSet();
    bool isInSet(int x); 
    setList operator+(setList& obj);  
    setList operator*(setList& obj);   
    setList operator-(setList& obj);
    bool operator==(setList& obj);  
    bool operator<=(setList& obj);
    bool operator>=(setList& obj);
    
};


