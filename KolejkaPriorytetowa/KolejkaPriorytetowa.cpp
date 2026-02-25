#include <iostream>
#include "KolejkaPriorytetowa.h"
using namespace std;

const int MAX_SIZE = 100;

class KolejkaPriorytetowa1{
private:
    array<int, MAX_SIZE> heap;
    int size;
    void heapifyUp(int i){
        int parent = (i - 1) / 2;
        while(i > 0 && heap[i] > heap[parent]){
            swap(heap[i], heap[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }
    void heapifyDown(int i){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size && heap[left] > heap[largest]){
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]){
            largest = right;
        }
        if (largest != i){
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    KolejkaPriorytetowa1(){
        size = 0;
    }

    void insert(int x){
        if (size >= MAX_SIZE){
        cout << "Kolejka jest pelna" << endl;
        return;
    }

    heap[size] = x;
    heapifyUp(size);
    size++;
    }

    int RemoveRootElem(){
         if (size <= 0){
        cerr << "Kolejka jest pusta" << endl;
         }
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
    }

    void print(){
        for (int i = 0; i < size; i++){
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    int getRootElem(){
        if (size <= 0){
            cerr << "Kolejka jest pusta" << endl;
        }
        return heap[0];
    }
};


int main(){

KolejkaPriorytetowa1 kolejka;

kolejka.insert(4);
kolejka.insert(6);
kolejka.insert(8);
kolejka.insert(14);
kolejka.insert(3);
kolejka.insert(8);

kolejka.print();
kolejka.RemoveRootElem();
kolejka.print();
kolejka.getRootElem();


    return 0;
}