#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x = 0) {
        data = x;
        next = nullptr;
    }
}

class SingleLinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    SingleLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~SingleLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insertFirst(int val) {
        Node* temp;
        temp.data = val;
        temp->next = head;
        head = temp;
    }
    void insertLast(int val) {
        Node* temp;
        temp.data = val;
        tail->next = temp;
        temp->next = nullptr;
        tail = temp;
    }
    void insertAfter(Node *p, int val) {
        Node* temp = head;
        bool check = false;
        while (temp != nullptr) {
            if (p.data == temp.data) {
                check = true;
                break;
            } else temp = temp->next;
        }
        if (!check) {
            cout << "Khong the them node!\n";
            return;
        }
        p->next = temp->next;
        temp->next = p;
    }
    void deleteFirst() {

    }
    void deleteLast() {

    }
    void deleteNode() {

    }
    void search() {

    }
    void display() {

    }
    void isEmpty() {

    }
    void clear() {

    }
}

int main() {
    return 0;
}
