#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node
struct Node {
    int info;
    Node* next;
};

// Khởi tạo danh sách rỗng
void Init(Node*& pHead) {
    pHead = NULL;
}

// Kiểm tra danh sách có rỗng không
bool kiemTraRong(Node* pHead) {
    return (pHead == NULL);
}

// Tạo một Node mới
Node* CreateNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

// Thêm vào đầu danh sách
void themPhanTuDauTien(Node*& pHead, int x) {
    Node* p = CreateNode(x);
    p->next = pHead;
    pHead = p;
}

// Thêm một phần tử sau một nút cụ thể
void themPhanTu(Node* p, int x) {
    if (p != NULL) {
        Node* q = CreateNode(x);
        q->next = p->next;
        p->next = q;
    }
}

// Duyệt danh sách và hiển thị các phần tử
void showList(Node* pHead) {
    Node* p = pHead;
    while (p != NULL) {
        cout << p->info << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

// Tìm kiếm một phần tử trong danh sách
Node* timPhanTu(Node* pHead, int x) {
    Node* p = pHead;
    while (p != NULL) {
        if (p->info == x) return p;
        p = p->next;
    }
    return NULL;
}

// Xóa phần tử đầu tiên của danh sách
void xoaPhanTuDauTien(Node*& pHead) {
    if (kiemTraRong(pHead)) return;
    Node* p = pHead;
    pHead = pHead->next;
    delete p;
}

// Xóa phần tử sau một nút cụ thể
void deleteNodeCuThe(Node* p) {
    if (p == NULL || p->next == NULL) return;
    Node* q = p->next;
    p->next = q->next;
    delete q;
}

// Xóa phần tử có nội dung x
void Remove(Node*& pHead, int x) {
    if (kiemTraRong(pHead)) return;
    
    if (pHead->info == x) {
        xoaPhanTuDauTien(pHead);
        return;
    }
    
    Node* p = pHead;
    while (p->next != NULL && p->next->info != x) {
        p = p->next;
    }
    if (p->next != NULL) {
        deleteNodeCuThe(p);
    }
}

// Xóa toàn bộ danh sách
void clearList(Node*& pHead) {
    while (!kiemTraRong(pHead)) {
        xoaPhanTuDauTien(pHead);
    }
}

// Sắp xếp danh sách bằng Selection Sort
void selectionSort(Node*& pHead) {
    for (Node* p = pHead; p != NULL && p->next != NULL; p = p->next) {
        Node* min = p;
        for (Node* q = p->next; q != NULL; q = q->next) {
            if (q->info < min->info) {
                min = q;
            }
        }
        swap(p->info, min->info);
    }
}

int main() {
    Node* myList;
    Init(myList);
    
    themPhanTuDauTien(myList, 10);
    themPhanTuDauTien(myList, 5);
    themPhanTuDauTien(myList, 15);
    themPhanTu(myList, 7);
    
    cout << "Danh sách sau khi chèn: ";
    showList(myList);
    
    Node* found = timPhanTu(myList, 10);
    if (found) cout << "Tìm thấy phần tử: " << found->info << endl;
    else cout << "Không tìm thấy phần tử!" << endl;
    
    Remove(myList, 5);
    cout << "Danh sách sau khi xóa 5: ";
    showList(myList);
    
    selectionSort(myList);
    cout << "Danh sách sau khi sắp xếp: ";
    showList(myList);
    
    clearList(myList);
    cout << "Danh sách sau khi xóa toàn bộ: ";
    showList(myList);
    
    return 0;
}
