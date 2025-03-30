#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    return new Node{value, NULL};
}

void add(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void remove(Node*& head, int value) {
    Node* current = head;
    Node* prev = NULL;
    while (current) {
        if (current->data == value) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void addList(Node*& head, Node* other) {
    Node* temp = other;
    while (temp) {
        add(head, temp->data);
        temp = temp->next;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteList(Node*& head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = NULL;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    int value;
    
    cout << "Nhập 10 số nguyên vào danh sách thứ nhất:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> value;
        add(list1, value);
    }
    
    cout << "Danh sách thứ nhất: ";
    display(list1);
    
    cout << "Nhập số nguyên cần xóa: ";
    cin >> value;
    remove(list1, value);
    
    cout << "Danh sách sau khi xóa: ";
    display(list1);
    
    cout << "Nhập 5 số nguyên vào danh sách thứ hai:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> value;
        add(list2, value);
    }
    
    addList(list1, list2);
    cout << "Danh sách thứ nhất sau khi thêm danh sách thứ hai: ";
    display(list1);
    
    deleteList(list1);
    deleteList(list2);
    
    return 0;
}
