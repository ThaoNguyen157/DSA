#include <iostream>
using namespace std;

// Định nghĩa cấu trúc NODE cho cây nhị phân
struct NODE {
    int data;
    NODE* pLeft;
    NODE* pRight;
};

// Hàm đếm số lượng nút có đúng một con
int DemMotCon(NODE* t) {
    if (t == NULL) return 0;

    // Kiểm tra nếu nút có một con
    if ((t->pLeft && !t->pRight) || (!t->pLeft && t->pRight)) 
        return 1 + DemMotCon(t->pLeft) + DemMotCon(t->pRight);
    
    // Nếu nút có hai con hoặc không có con
    return DemMotCon(t->pLeft) + DemMotCon(t->pRight);
}

// Hàm tạo một nút mới
NODE* createNode(int data) {
    NODE* newNode = new NODE;
    newNode->data = data;
    newNode->pLeft = newNode->pRight = NULL;
    return newNode;
}

// Hàm kiểm tra với một cây mẫu
int main() {
    // Tạo cây nhị phân
    NODE* root = createNode(10);
    root->pLeft = createNode(5);
    root->pRight = createNode(20);
    root->pLeft->pRight = createNode(7);
    root->pRight->pLeft = createNode(15);
    root->pRight->pRight = createNode(25);



    cout << "So nut co mot con: " << DemMotCon(root) << endl; 
    return 0;
}
