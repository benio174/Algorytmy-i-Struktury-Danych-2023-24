#include <iostream>

using namespace std;

const int MAX = 100;
const int MIN = -100000000;

class Lista{
    private:
    int tablica[MAX];
    int last;

    public:
   Lista() : last(-1){
        for(int i = 0; i < MAX; i++){
            tablica[i] = MIN;
        }
    }

    int First(){
        if (last == -1){
            return -1;
        } else {
        return 0;
        }
    }

    int END(){
        return last + 1;
    }

    int Next(int p){
        if(p >= 0 && p < END()){
            return p + 1;
        }
        else{
            return -1;
        }
    }

    int Previous(int p){
        if (p > 0 && p <= END()){
            return p - 1;
        }
        else{
            return -1;
        }
    }

    bool Insert(int x, int p){

        if (p >= 0 && p <= END()){
            if (END() + 1 < MAX){
                for(int i = END() + 1; i > p; i--){
                    tablica[i] = tablica[i - 1];
                }
                tablica[p] = x;
                last++;
                return true;
            }
            else{
                cout << "Tablica jest juz pelna" << endl;
                return false;
            }
        }
        else{
            cout << "Podano nieprawidlowa pozycje" << endl;
            return false;
        }
    }

    bool Delete(int p){
        if (p >= 0 && p <= END()){
          for (int i = p; i < END(); i++){
            tablica[i] = tablica[i + 1];
          }
          tablica[END()] = MIN;
          last--;
          return true;  
        }
        else{
            cout << "Podano nieprawidlowa pozycje" << endl;
            return false;
        }
    }

    int Locate(int x){
        for(int i = 0; i <= END(); i++){
            if(x == tablica[i]){
                return i;
            }
        }
        return END();
    }
    
    int Retreive(int p){
        if(p >= 0 && p <= END()){
            int i = tablica[p];
            return i;
        }
        else{
            cout << "Podano nieprawidlowa pozycje" << endl;
            return MIN;
        }
    }

    void RemoveDuplicates(){
        for (int i = 0; i <= END(); i++){
            int liczba = tablica[i];
            for(int j = i + 1; j <= END(); j++){
                if (liczba == tablica[j]){
                    Delete(j);
                    j--;
                }
            }
        }
    }

};

int main(){

    Lista lista;

    lista.Insert(1, lista.END());
    lista.Insert(2, lista.END());
    lista.Insert(3, lista.END());
    lista.Insert(2, lista.END());
    lista.Insert(4, lista.END());
    lista.Insert(7, lista.END());
    lista.Insert(6, lista.END());

    lista.RemoveDuplicates();
    for (int i = lista.First(); i < lista.END(); i++){
        cout << "Element na pozycji " << i << ": " << lista.Retreive(i) << endl;

    }
    cout << "Indeks pierwszego elementu listy: " << lista.First() << endl;
    cout <<"Pozaycja za ostatnim elementem: " << lista.END() << endl;

    return 0;
}