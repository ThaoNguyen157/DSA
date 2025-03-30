#include <iostream>
#include <fstream>

using namespace std;

// Định nghĩa NODE cho cây nhị phân
struct NODE {
    float info;
    NODE* pLeft;
    NODE* pRight;
};

typedef NODE* TREE;

// Hàm tạo một nút mới
NODE* createNode(float x) {
    NODE* newNode = new NODE;
    newNode->info = x;
    newNode->pLeft = newNode->pRight = NULL;
    return newNode;
}

// Hàm chèn một giá trị vào cây nhị phân
void Insert(TREE& t, float x) {
    if (t == NULL) {
        t = createNode(x);
        return;
    }
    if (x < t->info)
        Insert(t->pLeft, x);
    else
        Insert(t->pRight, x);
}

// Hàm duyệt cây theo LNR và ghi vào file văn bản
void LNR(TREE t, ofstream& file) {
    if (t == NULL) return;

    LNR(t->pLeft, file);          // Duyệt cây con trái
    file << t->info << " ";       // Ghi giá trị của nút vào file
    LNR(t->pRight, file);         // Duyệt cây con phải
}

// Hàm xuất cây ra file văn bản
int Xuat(const char* filename, TREE t) {
    ofstream file(filename);  // Mở file ở chế độ văn bản
    if (!file) {
        cout << "Loi mo file!" << endl;
        return 0;
    }

    LNR(t, file);             // Duyệt cây và ghi dữ liệu
    file.close();             // Đóng file
    cout << "Da ghi du lieu vao file " << filename << endl;
    return 1;
}

// Chương trình chính
int main() {
    TREE t = NULL;

    // Thêm một số số thực vào cây
    Insert(t, 5.5);
    Insert(t, 2.2);
    Insert(t, 8.8);
    Insert(t, 1.1);
    Insert(t, 3.3);

    // Xuất dữ liệu cây ra tập tin data.out.txt
    if (Xuat("data.out.txt", t)) {
        cout << "File data.out.txt da duoc tao thanh cong!\n";
    } else {
        cout << "Loi ghi file!\n";
    }

    return 0;
}
