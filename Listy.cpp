/*Ponizszy kod zawiera dwie klasy (pierwsza reprezentuje listę jednokierunkową, natomiast druga dwukierunkową).
Klasy korzystają z szablonów, po to aby mogły przechowywać rózne typy danych. Klasy zawierają wszystkie
metody z treści zadania(lista dwukierunkowa zawiera dodatkową metodę cell * Previous(cell * p), która zwraca wskaźnik
do komórki poprzedzającej komórkę o wskaźniku p). W funkcji main przedstawione jest działanie metod Insert oraz print
dla obydwu rodzaju list.*/

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

        void Insert(const T& x, cell * p){
            if(!p){                
                header = new cell(x);
            } else {
                cell * newcell = new cell(x);
                newcell->next = p->next;
                p->next = newcell;
            }
        }
        bool Delete(cell * p){
            if(!p || !p->next){
                return false;
            }
            cell * temp = p->next;
            p->next = temp->next;
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

template <typename T>
class ListaDwukierunkowa{
    protected:
        struct cell{
            T data;
            cell * next;
            cell * prev;
            cell(const T& val) : data(val), next(nullptr), prev(nullptr){}
        };
        cell * header;
    public:
        ListaDwukierunkowa() : header(nullptr){}
        ~ListaDwukierunkowa(){
            while(header){
                cell * temp = header;
                header = header->next;
                delete temp;
            }
        }
        void Insert(const T& x, cell * p){
            if (!p){
                header = new cell(x);
            } else {
                cell * newcell = new cell(x);
                newcell->next = p->next;
                p->next = newcell;
                if (newcell->next){
                    newcell->next->prev = newcell;
                }
                newcell->prev = p;
            }
        }
        bool Delete(cell * p){
            if(!p || !p->next){
                return false;
            }
            cell * temp = p->next;
            p->next = temp->next;
            if(temp->next){
                temp->next->prev = p;
            }
            delete temp;
            return true;
        }
        T Retrieve(cell * p){
            if (!p){
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
        cell * Previous(cell * p){
            if(!p || p == header){
                return nullptr;
            }
            return p->prev;
        }
        cell * Last(){
            cell * current = header;
            while(current && current->next){
                current = current->next;
            }
            return current;
        }
        void print(){
            cout << "Elementy listy dwukierunkowej:" << endl;
            cell * current = header;
            while(current){
                cout << current->data <<", ";
                current = current->next;
            }
            cout << endl;
        }       
};

int main(){
    ListaJednokierunkowa<int> lista1;
    lista1.Insert(1, lista1.First());
    lista1.Insert(2, lista1.First());
    lista1.Insert(3, lista1.First());
    lista1.print();
    lista1.Delete(lista1.First());
    lista1.Delete(lista1.First());
    lista1.print();

    ListaDwukierunkowa<int> lista2;
    lista2.Insert(4, nullptr);
    lista2.Insert(8, lista2.First());
    lista2.print();

    return 0;
}