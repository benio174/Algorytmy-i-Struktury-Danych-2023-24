#include <iostream>
using namespace std;

template<typename T>
class Drzewo{
    private:
        struct Node{
            T data;
            Node * left;
            Node * right;

            Node(const T& value) : data(value), left(nullptr), right(nullptr) {}

        };
        Node<T> * root;

        void Preorder(Node<T> * node) const {
            if (node){
                cout << node->data << endl;
                Preorder(node->left);
                Preorder(node->right);
            }
        }

        void Inorder(Node<T> * node) const {
            if (node){
                Inorder(node->left);
                cout << node->data << endl;
                Inorder(node->right);
            }
        }

        void Postorder(Node<T> * node){
            Postorder(node->left);
            Postorder(node->right);
            cout << node->data << endl;
        }

        void addElement(Node<T>*& node, const T& value){
            if (!node){
                node = new Node<T>(value);
            } else {
                if (value < node->data) {
                    addElement(node->left, value);
                } else {
                    addElement(node->right, value);
                }
            }
        }

        void Destroy(Node<T> * node){
            if (node){
                Destroy(node->left);
                Destroy(node->right);
                delete node;
            }
        }
    
    public:
        Tree() : root(nullptr) {}
        ~Tree(){
            Destroy(root);
        }

        void add(const T& value){
            addElement(root, value);
        }

        void preorder() const {
            cout << "Preorder:" << endl;
            Preorder(root);
            cout << endl;
        }

        void inorder() const {
            cout << "Inorder:" << endl;
            Inorder(root);
            cout << endl;
        }

        void postorder() const {
            cout << "Postorder:" << endl;
            Postorder(root);
            cout << endl;
        }
};

int main(){

    Drzewo<int> drzewo;

    drzewo.add(1);
    drzewo.add(2);
    

    return 0;
}