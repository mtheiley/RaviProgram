#include <iostream>
#include <memory>
#include <initializer_list>

using namespace std;

template <class T>
struct Node{
    unique_ptr<Node<T>> next;
    T value;

    Node(T value) {
        this->value = value;
        cout << "Node ID: " << (long) this << " created" << endl; 
    }
    ~Node() {
        cout << "Node ID: " << (long) this << " destroyed" << endl; 
    }
};

template <class T>
unique_ptr<Node<T>> gen_node(T value) {
    return make_unique<Node<int>>(value);    
}

template <class T>
unique_ptr<Node<T>> gen_list(initializer_list<T> list) {
    if(list.size() == 0) return {};
    auto dummy = gen_node(*(list.begin())); //Makes it easier to work with LL
    Node<T>* head = dummy.get();
    for(auto e : list) {
        auto next = gen_node(e);
        head->next = std::move(next);
        head = head->next.get();
    }
    return std::move(dummy->next);
}

int main() {
    auto n1 = gen_list({1, 2, 3, 4});
    Node<int>* n = n1.get();
    while(n != nullptr) {
        cout << n->value << endl;
        n = n->next.get();
    }
}