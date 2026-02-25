/*Poniższy kod zawiera implementacje stosu za pomocą listy jednokierunkowej oraz tablicy.
W liście jednokierunkowej zostały lekko zmodyfikowane metody Insert oraz Delete aby działały
zgodnie z założeniami stosu. Obydwie klasy korzystają szablonów do przechowywania różnych typów danych. 
W stosie zaimplementowanym prz pomocy tablicy określono zmienne: MAX - rozmiar tablicy,
MIN - wartość, która na pewno nie wystąpi w stosie oraz s - "wskaźnik" na ostatno włożony element stosu. 
Na końcu programu znajduje się funkcja main z przykladami użycia metod zaimplementowanych
w obydwu klasach */

#include <iostream>
using namespace std;

template<typename T>
class ListaJednokierunkowa
{
    protected:
        struct cell{
            T data;
            cell * next;
            cell(const T& val) : data(val), next(nullptr){}
        };

        cell * header;

    public:
        ListaJednokierunkowa() : header(nullptr){}
        ~ListaJednokierunkowa() {
            while(header){
                cell * temp = header;
                header = header->next;
                delete temp;
            }
        }

        void Insert(const T& x){

                cell * newcell = new cell(x);
                newcell->next = header;
                header = newcell;
        }

        bool Delete(){
            if(!header){
                return false;
            }
            cell * temp = header;
            header = temp->next;
            delete temp;
            return true;
        }
        T Retrieve(cell * p){
            if(!p){
                cerr << "Niepoprawny wskaźnik do komórki" << endl;
                exit(EXIT_FAILURE);
            }
            return p->data;
        }
        cell * Locate(const T& x){
            cell * current = header;
            while(current && current->data != x){
                current = current->next;
            }
            return current;
        }
        cell * First(){
            return header;
        } 
        cell * Next(cell * p){
            if(!p){
                return nullptr;
            }
            return p->next;
        }
        cell * Last(){
            cell * current = header;
            while(current && current->next){
                current = current->next;
            }
            return current;
        }
        void print(){
            cell * current = header;
            cout << "Elementy listy jednokierunkowej:" << endl;
            while(current){
                cout << current->data << ", ";
                current = current->next;
            }
            cout << endl;
        }
};

template<typename T>
class StosLista{
    private:
        ListaJednokierunkowa<T> list;

    public:
        
        bool empty(){
            if(list.First() == nullptr){
                return true;
            }
                return false;
            }

        void push(const T& x){

            list.Insert(x);
        }

        T pop(){
            if (empty()){
                cerr << "Stos jest pusty" <<endl;
                exit(EXIT_FAILURE);
            }
            T value = list.Retrieve(list.First());
            list.Delete();
            return value;
        }

        T top(){
            if (empty()){
                cerr << "Stos jest pusty" <<endl;
                exit(EXIT_FAILURE);
            }
            return list.Retrieve(list.First());
        }

        void makenull(){
            while(!empty()){
                list.Delete();
            }
        }


};

template<typename T>
class StosTablica {
    private:
        static const int MAX = 100;
        static const int MIN = -100000000;
        T tablica[MAX];
        int s;
    
    public:
        StosTablica() : s(-1) {}
        ~StosTablica() {}

        bool empty(){
            if(s == -1){
                return true;
            }
            return false;
        }

        bool push(const T& x){
            if(s == MAX - 1){
                cerr << "Stos jest już pełny" << endl;
                return false;
            }
            s++;
            tablica[s] = x;
            return true;
        }

        T pop(){
            if(empty()){
                cerr << "Stos jest pusty" << endl;
                exit(EXIT_FAILURE);
            }
            T x;
            x = tablica[s];
            tablica[s] = MIN;
            s--;
            return x;
        }

        T top(){
            if(empty()){
                cerr << "Stos jest pusty" << endl;
                exit(EXIT_FAILURE);
            }
            return tablica[s];
        }

        void makenull(){
            while(s != -1){
                tablica[s] = MIN;
                s--;
            }
        }



};

int main(){

    StosLista<int> stos;
    StosTablica<int> stos1;

    cout << "STOS Z WYKORZYSTANIEM LISTY JEDNOKIERUNKOWEJ" << endl;

    stos.push(1);
    stos.push(2);
    stos.push(3);

    cout << "Metoda top: " << stos.top() << endl;
    cout <<"Meotda pop: " << stos.pop() << endl;
    cout <<"Metoda top po pop: " << stos.top() << endl;

    stos.makenull();

    cout << "STOS Z WYKORZYSTANIEM LISTY TABLICOWEJ" << endl;

    stos1.push(1);
    stos1.push(2);
    stos1.push(3);

    cout << "Metoda top: " << stos1.top() << endl;
    cout << "Metoda pop: " << stos1.pop() << endl;
    cout << "Metoda top po pop " << stos1.top() << endl;


    
    return 0;
}