#include<iostream>
#include<bits/stdc++.h>
#include "setList.h"
using namespace std;

int setList::getSize(){
    return vec.size();
}

void setList::printSet(){
    for(const auto &element : vec){
        cout << element << " ";
    }
    cout << endl;
}

void setList::insert(int x){
    if(!isInSet(x)){
        vec.push_back(x);
    }
}

void setList::withdraw(int x){
    vec.erase(remove(vec.begin(), vec.end(), x), vec.end());
}

bool setList::isInSet(int x){
    return find(vec.begin(), vec.end(), x) != vec.end();
}

setList setList::operator+(setList& obj){
    setList result;
    
    result.vec.insert(result.vec.end(), vec.begin(), vec.end());
    for(const auto& element : obj.vec){
        if(!isInSet(element)){
            result.vec.push_back(element);
        }
    }
    return result;
}

setList setList::operator*(setList& obj){
    setList result;

    for(const auto& element : vec){
        if(obj.isInSet(element)){
            result.insert(element);
        }
    }
    return result;
}

setList setList::operator-(setList& obj){
    setList result;

    for(const auto& element : vec){
        if(!obj.isInSet(element)){
            result.insert(element);
        }
    }
    return result;
}

bool setList::operator==(setList& obj){
    return vec == obj.vec;
}

bool setList::operator<=(setList& obj){
    for(const auto& element : vec){
        if(!obj.isInSet(element)){
            return false;
        }
    }
    return true;
}

bool setList::operator>=(setList& obj){
    for(const auto& element : obj.vec){
        if(!isInSet(element)){
            return false;
        }
    }
    return true;
}

void setList::clearSet(){
    vec.clear();
}

int main(){

    setList set1;
    setList set2;

    set1.insert(1);
    set1.insert(3);
    set1.insert(8);

    set2.insert(1);
    set2.insert(5);
    set2.insert(7);
    set2.insert(12);

    set1.printSet();
    set2.printSet();
    cout << "Size of first set: " << set1.getSize() << endl;
    cout << "Size of second set: " << set2.getSize() << endl;

    set1.withdraw(3);
    set2.withdraw(5);
    set1.printSet();
    set2.printSet();

    setList sum = set1 + set2;
    setList substraction = set1 - set2;
    setList cp = set1 * set2;
    cout << "Sum: " << endl;
    sum.printSet();
    cout << "Common part:" << endl;
    cp.printSet();
    cout << "Substraction:" << endl;
    substraction.printSet();
    
    if(set1 == set2){
        cout << "Sets are equal" << endl;
    } else {
        cout << "Sets are not equal" << endl;
    }

    if(set1 <= set2){
        cout << "Set 1 contains set 2" << endl;
    } else {
        cout << "Set 1 does not contain set 2" << endl;
    }

    if(set1 >= set2){
        cout << "Set 2 contains set 1" << endl;
    } else {
        cout << "Set 2 does not contain set 1" << endl;
    }
    
    set1.clearSet();
    set2.clearSet();

    return 0;
}
