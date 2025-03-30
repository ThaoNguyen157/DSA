#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// Hàm tạo một nút mới
TreeNode* taoNut(int val) {
    TreeNode* node = new TreeNode();
    node->val = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Duyệt cây theo mức (level-order) không dùng đệ quy
void duyetTheoMuc(TreeNode* root, int ketQua[], int &chiMuc) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        ketQua[chiMuc++] = node->val;  // Lưu vào mảng kết quả

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

// Hàm in kết quả
void inMang(int arr[], int kichThuoc) {
    for (int i = 0; i < kichThuoc; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Chương trình chính
int main() {
    // Tạo cây mẫu
    TreeNode* root = taoNut(1);
    root->left = taoNut(2);
    root->right = taoNut(3);
    root->left->left = taoNut(4);
    root->left->right = taoNut(5);
    root->right->left = taoNut(6);
    root->right->right = taoNut(7);

    // Mảng kết quả
    int ketQua[100], chiMuc = 0;

    // Gọi hàm duyệt cây
    duyetTheoMuc(root, ketQua, chiMuc);

    // In kết quả
    cout << "Duyệt theo mức: ";
    inMang(ketQua, chiMuc);

    return 0;
}
