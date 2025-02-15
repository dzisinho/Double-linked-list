
 
#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void print() {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void remove(T data) {
        Node<T>* temp = head;
        while (temp) {
            if (temp->data == data) {
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                if (temp == head) head = temp->next;
                if (temp == tail) tail = temp->prev;
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    ~DoubleLinkedList() {
        Node<T>* temp = head;
        while (temp) {
            Node<T>* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    DoubleLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.print();

    list.remove(2);
    list.print();

    return 0;
}
