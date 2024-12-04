#include <iostream>

using namespace std;

template <class T>
struct Node {
    Node<T>* next;
    T value;

    Node(T value) {
        this->value = value;
    }
};

int main() {
    auto n1 = new Node(3);
    auto n2 = new Node(5);
    auto n3 = new Node(7);
    auto n4 = new Node(9);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    auto n = n1;
    while(n != nullptr) {
        cout << n->value << endl;
        n = n->next;
    }
}