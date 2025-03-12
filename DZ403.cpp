#include <iostream>
#include <string>
using namespace std;

template <typename T>
class LinkedList {
public:
    class Node {
    public:
        T data;
        Node* next;

        Node() : data(0), next(nullptr) {}
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* Head;

    LinkedList() : Head(nullptr) {}
    LinkedList(Node* head) : Head(head) {}
    LinkedList(const LinkedList& other) : Head(nullptr) {
        Node* current = other.Head;
        while (current != nullptr) {
            this->push(current->data);
            current = current->next;
        }
    }

    ~LinkedList() {
        while (Head != nullptr) {
            Node* temp = Head;
            Head = Head->next;
            delete temp;
        }
    }

    void push(T value) {
        if (Head == nullptr) {
            Head = new Node(value);
        }
        else {
            Node* current = Head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(value);
        }
    }

    void print() {
        if (Head == nullptr) {
            cout << "Список пустой";
        }
        else {
            Node* current = Head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
        }
        cout << endl;
    }

    T get(int index) {
        if (Head == nullptr || index < 0) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = Head;
        while (current->next != nullptr && index > 0) {
            current = current->next;
            index--;
        }

        if (index > 0) {
            throw std::out_of_range("Index out of range");
        }

        return current->data;
    }

    void remove(T data) {
        if (Head == nullptr) return;

        if (Head->data == data) {
            Node* temp = Head;
            Head = Head->next;
            delete temp;
            return;
        }

        Node* current = Head;
        while (current->next != nullptr && current->next->data != data) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void removeAt(int index) {
        if (Head == nullptr || index < 0) return;

        if (index == 0) {
            Node* temp = Head;
            Head = Head->next;
            delete temp;
            return;
        }

        Node* current = Head;
        while (current->next != nullptr && index > 1) {
            current = current->next;
            index--;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    T& operator[] (int i) {
        Node* current = Head;
        while (i > 0) {
            current = current->next;
            i--;
        }
        return current->data;
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
        if (list.Head == nullptr) {
            os << "Список пустой";
        }
        else {
            Node* current = list.Head;
            while (current != nullptr) {
                os << current->data << " ";
                current = current->next;
            }
        }
        return os;
    }

    LinkedList& operator= (const LinkedList& list) {
        if (this == &list) return *this;

        while (Head != nullptr) {
            Node* temp = Head;
            Head = Head->next;
            delete temp;
        }

        Node* currentSecond = list.Head;
        while (currentSecond != nullptr) {
            this->push(currentSecond->data);
            currentSecond = currentSecond->next;
        }
        return *this;
    }
};
