#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x = 0) {
        data = x;
        next = nullptr;
    }
};

class SingleLinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    // Constructor
    SingleLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Destructor
    ~SingleLinkedList() {
        clear();
    }

    // Kiểm tra rỗng
    bool isEmpty() {
        return head == nullptr;
    }

    // Thêm đầu
    void insertFirst(int val) {
        Node* temp = new Node(val);
        if (isEmpty()) {
            head = tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    // Thêm cuối
    void insertLast(int val) {
        Node* temp = new Node(val);
        if (isEmpty()) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    // Chèn sau node p
    void insertAfter(Node* p, int val) {
        if (p == nullptr) {
            cout << "Node khong ton tai!\n";
            return;
        }
        Node* temp = new Node(val);
        temp->next = p->next;
        p->next = temp;
        if (tail == p) tail = temp;
        size++;
    }

    // Xóa đầu
    void deleteFirst() {
        if (isEmpty()) {
            cout << "Danh sach rong!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        if (head == nullptr) tail = nullptr;
    }

    // Xóa cuối
    void deleteLast() {
        if (isEmpty()) {
            cout << "Danh sach rong!\n";
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            size = 0;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
        size--;
    }

    // Xóa node theo giá trị
    void deleteNode(int val) {
        if (isEmpty()) {
            cout << "Danh sach rong!\n";
            return;
        }
        if (head->data == val) {
            deleteFirst();
            return;
        }
        Node* prev = head;
        Node* cur = head->next;
        while (cur != nullptr && cur->data != val) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr) {
            cout << "Khong tim thay node!\n";
            return;
        }
        prev->next = cur->next;
        if (cur == tail) tail = prev;
        delete cur;
        size--;
    }

    // Tìm kiếm
    Node* search(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    // Hiển thị
    void display() {
        if (isEmpty()) {
            cout << "Danh sach rong!\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Xóa toàn bộ danh sách
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Lấy số lượng node
    int getSize() {
        return size;
    }
};

int main() {
    SingleLinkedList list;

    cout << "Them dau:\n";
    list.insertFirst(20);
    list.insertFirst(10);
    list.display();

    cout << "\nThem cuoi:\n";
    list.insertLast(30);
    list.insertLast(40);
    list.display();

    cout << "\nChen 25 sau 20:\n";
    Node* p = list.search(20);

    if (p != nullptr) list.insertAfter(p, 25);

    list.display();

    cout << "\nXoa dau:\n";
    list.deleteFirst();
    list.display();

    cout << "\nXoa cuoi:\n";
    list.deleteLast();
    list.display();

    cout << "\nXoa node 25:\n";
    list.deleteNode(25);
    list.display();

    cout << "\nTim kiem 30:\n";
    Node* q = list.search(30);

    if (q != nullptr) cout << "Tim thay " << q->data << "\n";
    else cout << "Khong tim thay!\n";

    cout << "\nSo luong node: " << list.getSize() << "\n";

    cout << "\nXoa toan bo:\n";
    list.clear();
    list.display();

    return 0;
}
