#include<iostream>
#include<string>
using namespace std;

template <typename T>
class LinkedList {
public:
    class Node {
    public:
        T data;
        Node* next;

        Node() { this->data = 0; this->next = nullptr; }

        Node(T value) { this->data = value; this->next = nullptr; }
    };

    Node* Head;

    LinkedList() { this->Head = nullptr; }
    LinkedList(Node* head) { this->Head = head; }

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

            while (current->next != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << current->data << " ";
            cout << endl;
        }
    }
    T get(int index) {
        if (Head == nullptr) {
            return 0;
        }
        else {
            Node* current = Head;

            while (current->next != nullptr && index > 0) {
                current = current->next;
                index--;
            }
            return current->data;
        }
    }
    void remove(T data) {
        Node* current = Head;

        while (current->next != nullptr && current->next->data != data) {
            current = current->next;
        }
        Node* buffer = current->next->next;
        delete current->next;
        current->next = buffer;
    }
    void removeAt(int index) {

        Node* current = Head;

        while (current->next != nullptr && index > 1) {
            current = current->next;
            index--;
        }
        Node* buffer = current->next->next;
        delete current->next;
        current->next = buffer;
    }
    LinkedList<T> subList(int indexStart, int indexEnd) {
        LinkedList<T> newList;
        Node* current = Head;
        int currentIndex = 0;

        while (current != nullptr && currentIndex < indexStart) {
            current = current->next;
            currentIndex++;
        }

        while (current != nullptr && currentIndex < indexEnd) {
            newList.push(current->data);
            current = current->next;
            currentIndex++;
        }

        return newList;
    }
    void clear() {
        Node* current = Head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        Head = nullptr;
    }
};


int main() {
    setlocale(LC_ALL, "rus");
    LinkedList<string>* list = new LinkedList<string>();
    list->push("10.5asdd");
    list->push("15.5asdasd");
    list->push("20.5adsad");
    list->push("25.5asdasd");
    list->push("30.5asdasd");
    list->print();
    cout << list->get(2) << endl;
    list->removeAt(2);
    list->print();

    LinkedList<string> subList = list->subList(1, 3);
    cout << "Подсписок от 1 до 3: ";
    subList.print();

    list->clear();
    cout << "Список после очистки: ";
    list->print();

    delete list;
    return 0;
}
