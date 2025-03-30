#include <iostream>
#include <stack>

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

// Duyệt cây theo thứ tự NLR không dùng đệ quy
void duyetTienTu(TreeNode* root, int ketQua[], int &chiMuc) {
    if (!root) return;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        ketQua[chiMuc++] = node->val;  // Lưu vào mảng kết quả

        // Đẩy phải trước, trái sau để trái được xử lý trước
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
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
    duyetTienTu(root, ketQua, chiMuc);

    // In kết quả
    cout << "Duyệt tiền tự (NLR): ";
    inMang(ketQua, chiMuc);

    return 0;
}
