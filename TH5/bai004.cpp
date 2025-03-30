#include <iostream>
using namespace std;

struct node {
    int info;
    struct node *pLeft, *pRight;
};

typedef struct node NODE;
typedef NODE* TREE;

// Hàm tìm phần tử nhỏ nhất trong cây BST
NODE* NhoNhat(TREE Root) {
    if (Root == NULL)
        return NULL;
    NODE* lc = Root;
    while (lc->pLeft)
        lc = lc->pLeft;
    return lc;
}

// Hàm tìm phần tử lớn nhất trong cây BST
NODE* LonNhat(TREE Root) {
    if (Root == NULL)
        return NULL;
    NODE* lc = Root;
    while (lc->pRight)
        lc = lc->pRight;
    return lc;
}

// Hàm thêm một phần tử vào cây BST
void InsertNode(TREE &Root, int x) {
    if (Root == NULL) {
        Root = new NODE;
        Root->info = x;
        Root->pLeft = Root->pRight = NULL;
    } else {
        if (x < Root->info)
            InsertNode(Root->pLeft, x);
        else if (x > Root->info)
            InsertNode(Root->pRight, x);
    }
}

// Hàm kiểm tra
void Test() {
    TREE Root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr) {
        InsertNode(Root, x);
    }
    
    NODE* minNode = NhoNhat(Root);
    NODE* maxNode = LonNhat(Root);
    
    if (minNode)
        cout << "Phan tu nho nhat: " << minNode->info << endl;
    if (maxNode)
        cout << "Phan tu lon nhat: " << maxNode->info << endl;
}

int main() {
    Test();
    return 0;
}
