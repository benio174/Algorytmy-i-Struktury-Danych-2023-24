#include <iostream>
#include "setArr.h"
using namespace std;

setArr::setArr() : universeSize(100){
    table = new bool[universeSize]();
}

bool setArr::checkRangeCorrectness(int x){
    return (x >= 0 && x < universeSize);
}

void setArr::insert(int x){
    if(checkRangeCorrectness(x)){
        table[x] = true;
    } else {
        cerr << "Wrong number typed" << endl;
    }
}

void setArr::withdraw(int x){
    if(checkRangeCorrectness(x)){
        table[x] = false;
    } else {
        cerr <<"Wrong number typed" << endl;
    }
}

bool setArr::isInSet(int i){
    return checkRangeCorrectness(i) && table[i];
}

int setArr::getSize(){
    size = 0;
    for(int i = 0; i < universeSize; i++){
        if(table[i] == true){
            size++;
        }
    }
    return size;
}

void setArr::clearSet(){
    for(int i = 0; i < universeSize; i++){
        table[i] = false;
    }
    size = 0;
}

void setArr::printSet(){
    cout << "Content of the set:" << endl;
    if(size == 0){
        cout << "Set is empty" << endl;
    } else {
        for(int i = 0; i < universeSize; i++){
            if(table[i] == true){
                cout << i << " ";
            }
        }
    cout << endl;
    }
}

setArr setArr::operator+(setArr& object){
    setArr result;

    for(int i = 0; i < universeSize; i++){
        if(table[i]){
            result.insert(i);
        }
    }

    for(int i = 0; i < object.universeSize; i++){
        if(object.table[i] && !table[i]){
            result.insert(i);
        }
    }
    return result;
}

setArr setArr::operator*(setArr& object){
    setArr result;

    for(int i = 0; i < universeSize; i++){
        if(table[i] && object.table[i]){
            result.insert(i);
        }
    }
    return result;
}

setArr setArr::operator-(setArr& object){
    setArr result;

    for(int i = 0; i < universeSize; i++){
        if(table[i]){
            result.insert(i);
        }
    }

    for (int i = 0; i < object.universeSize; i++){
        if(table[i] && object.table[i]){
            result.withdraw(i);
        }
    }
    return result;
}

bool setArr::operator==(setArr& object){
    int newsize = max(universeSize, object.universeSize);

    for(int i = 0; i < newsize; i++){
        if(table[i] && !object.table[i] || !table[i] && object.table[i]){
            return false;
        }
    }
    return true;
}

bool setArr::operator>=(setArr& object){
    for(int i = 0; i < object.universeSize; i++){
        if(!table[i] && object.table[i]){
            return false;
        }
    }
    return true;
}

bool setArr::operator<=(setArr& object){
    for(int i = 0; i < universeSize; i++){
        if(table[i] && !object.table[i]){
            return false;
        }
    }
    return true;
}

int main(){

    setArr set1;
    setArr set2;

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

    cout << "Sum:" << endl;
    set1.operator+(set2).printSet();
    cout << "Common part:" << endl;
    set1.operator*(set2).printSet();
    cout << "Substraction:" << endl;
    set1.operator-(set2).printSet();
    
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