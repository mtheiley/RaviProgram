#include <iostream>

using namespace std;

template <class T>
struct Node {
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
    T value;

    Node(T value) {
        this->value = value;
    }
};

//Depth First Search - To Walk Through Tree
template <class T>
void walkTree(Node<T>* node) {
    if(node == nullptr) return;
    cout << node->value << endl;
    walkTree(node->left);
    walkTree(node->right);
}

int main() {
    auto n1 = new Node(1);
    auto n2 = new Node(2);
    auto n3 = new Node(3);
    auto n4 = new Node(4);
    auto n5 = new Node(5);
    auto n6 = new Node(6);
    auto n7 = new Node(7);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    walkTree(n1);
}