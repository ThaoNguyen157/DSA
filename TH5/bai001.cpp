#include <iostream>
#include <numeric>
using namespace std;

// Định nghĩa cấu trúc Node của cây nhị phân
struct Node {
    int info;
    Node* pLeft;
    Node* pRight;
    Node(int x) : info(x), pLeft(NULL), pRight(NULL) {}
};

typedef Node* TREE;

// Hàm đếm số lượng nút trong cây
int DemNode(TREE Root) {
    if (Root == NULL)
        return 0;
    return DemNode(Root->pLeft) + DemNode(Root->pRight) + 1;
}

// Hàm tính tổng giá trị các nút trong cây
int TongNode(TREE Root) {
    if (Root == NULL)
        return 0;
    return TongNode(Root->pLeft) + TongNode(Root->pRight) + Root->info;
}

// Hàm tính trung bình cộng của tất cả các nút
float TrungBinhCong(TREE Root) {
    int s = TongNode(Root);
    int dem = DemNode(Root);
    if (dem == 0)
        return 0;
    return (float)s / dem;
}

// Hàm đếm số lượng nút dương
int DemDuong(TREE Root) {
    if (Root == NULL)
        return 0;
    int count = DemDuong(Root->pLeft) + DemDuong(Root->pRight);
    if (Root->info > 0)
        return count + 1;
    return count;
}

// Hàm tính tổng giá trị các nút dương
int TongDuong(TREE Root) {
    if (Root == NULL)
        return 0;
    int sum = TongDuong(Root->pLeft) + TongDuong(Root->pRight);
    if (Root->info > 0)
        return sum + Root->info;
    return sum;
}

// Hàm tính trung bình cộng các số dương
float TrungBinhDuong(TREE Root) {
    int s = TongDuong(Root);
    int dem = DemDuong(Root);
    if (dem == 0)
        return 0;
    return (float)s / dem;
}

// Hàm đếm số lượng nút âm
int DemAm(TREE Root) {
    if (Root == NULL)
        return 0;
    int count = DemAm(Root->pLeft) + DemAm(Root->pRight);
    if (Root->info < 0)
        return count + 1;
    return count;
}

// Hàm tính tổng giá trị các nút âm
int TongAm(TREE Root) {
    if (Root == NULL)
        return 0;
    int sum = TongAm(Root->pLeft) + TongAm(Root->pRight);
    if (Root->info < 0)
        return sum + Root->info;
    return sum;
}

// Hàm tính trung bình cộng các số âm
float TrungBinhCongAm(TREE Root) {
    int s = TongAm(Root);
    int dem = DemAm(Root);
    if (dem == 0)
        return 0;
    return (float)s / dem;
}

// Hàm tính tỉ số tổng số dương / tổng số âm
float TinhTySo(TREE Root) {
    int a = TongDuong(Root);
    int b = TongAm(Root);
    if (b == 0)
        return 0;
    return (float)a / b;
}

int main() {
    // Tạo cây nhị phân mẫu
    TREE root = new Node(5);
    root->pLeft = new Node(-3);
    root->pLeft->pLeft = new Node(1);
    root->pLeft->pRight = new Node(-2);
    root->pRight = new Node(8);
    root->pRight->pLeft = new Node(-7);
    root->pRight->pRight = new Node(4);

    // Xuất kết quả tính toán
    cout << "Trung bình cộng tất cả các nút: " << TrungBinhCong(root) << endl;
    cout << "Trung bình cộng các số dương: " << TrungBinhDuong(root) << endl;
    cout << "Trung bình cộng các số âm: " << TrungBinhCongAm(root) << endl;
    cout << "Tỉ số tổng số dương/tổng số âm: " << TinhTySo(root) << endl;
    
    return 0;
}
