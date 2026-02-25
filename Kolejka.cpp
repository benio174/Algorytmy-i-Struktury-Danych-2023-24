/*Poniższy kod zawiera implementacje kolejki za pomocą listy jednokierunkowej oraz kolejki
cyklicznej za pomocą tablicy. W liście jednokierunkowej zostały lekko zmodyfikowane metody
Insert oraz Delete aby działały zgodnie z założeniami kolejki. Obydwie klasy korzystają
szablonów do przechowywania różnych typów danych. W kolejce cyklicznej określono zmienne:
MAX - rozmiar tablicy, MIN - wartość, która na pewno nie wystąpi w naszej kolejce
first - "wskaznik" na początek kolejki oraz s - "wskaźnik" na ostatni element kolejki. 
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
                if(!header){
                    header = newcell;
                } else {
                    cell * last = Last();
                    last->next = newcell;
                }
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

template <typename T>
class KolejkaLista{
    private:
        ListaJednokierunkowa<T> list;

    public:
        KolejkaLista() {}
        ~KolejkaLista() {}

        bool empty(){
            if(list.First() == nullptr){
                return true;
            }
            return false;
        }

        void put(const T& x){
            list.Insert(x);
        }

        T get(){
            if (empty()){
                cerr << "Kolejka jest pusta" << endl;
                exit(EXIT_FAILURE);
            }
            T value = list.Retrieve(list.First());
            list.Delete();
            return value;
            
        }

        T front(){
            if(empty()){
                cerr << "Kolejka jest pusta" << endl;
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
class KolejkaTablica{
    private:
        static const int MAX = 100;
        static const int MIN = -1000000;
        T tablica[MAX];
        int s;
        int first;

    public:
        KolejkaTablica() : s(-1), first(-1) {}
        ~KolejkaTablica() {}

        bool empty(){
            if(first == -1){
                return true;
            }
            return false;
        }

        bool put(const T& x){
            if((s + 1) % MAX == first){
                cerr << "Kolejka jest już pełna" << endl;
                return false;
            }
            if (empty()){
                s = first = 0;

            } else {
            s = (s + 1) % MAX;
            }

            tablica[s] = x;
            return true;
        }


        T get(){
            if(empty()){
                cerr << "Kolejka jest pusta" << endl;
                exit(EXIT_FAILURE);
            }
            T x = tablica[first];
            tablica[first] = MIN;
            if(first == s){
                first = s = -1;
            } else {
                first = (first + 1) % MAX;
            }
            return x;
        }

        T front(){
            if(empty()){
                cerr << "Kolejka jest pusta" << endl;
                exit(EXIT_FAILURE);
            }
            return tablica[first];
        }

        void makenull(){
            if(!empty()){
                tablica[first] = MIN;
                first = (first + 1) % MAX;
            } else {
                first = s;
            }
        }
};

int main(){

    KolejkaLista<int> kolejka;

    cout << "KOLEJKA Z WYKORZYSTANIEM LISTY JEDNOKIERUNKOWEJ" << endl;
    
    kolejka.put(1);
    kolejka.put(2);
    kolejka.put(3);

    cout << "Metoda front: " << kolejka.front() << endl;
    cout << "Metoda get: " << kolejka.get() << endl;
    cout << "Metoda front po get: " << kolejka.front() << endl;

    kolejka.makenull();

    KolejkaTablica<int> kolejka1;

    cout << "KOLEJKA CYKLICZNA Z WYKORZYSTANIEM TABLICY" << endl;

    kolejka1.put(1);
    kolejka1.put(2);
    kolejka1.put(3);

    cout << "Metoda front: " << kolejka1.front() << endl;
    cout << "Metoda get: " << kolejka1.get() << endl;
    cout << "Metoda front po get: " << kolejka1.front() << endl;

    kolejka1.makenull();

    return 0;
}
