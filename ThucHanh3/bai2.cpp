#include <iostream>
#include <cstring>
using namespace std;

struct SinhVien {
    char hoTen[50];
    char diaChi[70];
    char lop[10];
    int khoa;
    SinhVien* next;
};

SinhVien* createSinhVien(const char* hoTen, const char* diaChi, const char* lop, int khoa) {
    SinhVien* sv = new SinhVien;
    for (int i = 0; hoTen[i] != '\0'; i++) sv->hoTen[i] = hoTen[i];
    sv->hoTen[strlen(hoTen)] = '\0';
    for (int i = 0; diaChi[i] != '\0'; i++) sv->diaChi[i] = diaChi[i];
    sv->diaChi[strlen(diaChi)] = '\0';
    for (int i = 0; lop[i] != '\0'; i++) sv->lop[i] = lop[i];
    sv->lop[strlen(lop)] = '\0';
    sv->khoa = khoa;
    sv->next = NULL;
    return sv;
}

void addSinhVien(SinhVien*& head, SinhVien* sv) {
    if (!head) {
        head = sv;
    } else {
        SinhVien* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = sv;
    }
}

void displayList(SinhVien* head) {
    SinhVien* temp = head;
    while (temp) {
        cout << "Họ Tên: " << temp->hoTen << ", Địa Chỉ: " << temp->diaChi
             << ", Lớp: " << temp->lop << ", Khóa: " << temp->khoa << endl;
        temp = temp->next;
    }
}

void removeSinhVien(SinhVien*& head, const char* key, bool byName) {
    SinhVien* current = head;
    SinhVien* prev = NULL;
    while (current) {
        if ((byName && strcmp(current->hoTen, key) == 0) ||
            (!byName && strcmp(current->diaChi, key) == 0)) {
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

void deleteList(SinhVien*& head) {
    while (head) {
        SinhVien* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    SinhVien* list = NULL;
    
    cout << "Nhập 10 sinh viên:" << endl;
    for (int i = 0; i < 10; i++) {
        char hoTen[50], diaChi[70], lop[10];
        int khoa;
        cout << "Nhập họ tên: "; cin.getline(hoTen, 50);
        cout << "Nhập địa chỉ: "; cin.getline(diaChi, 70);
        cout << "Nhập lớp: "; cin.getline(lop, 10);
        cout << "Nhập khóa: "; cin >> khoa;
        cin.ignore();
        addSinhVien(list, createSinhVien(hoTen, diaChi, lop, khoa));
    }
    
    cout << "Danh sách sinh viên:" << endl;
    displayList(list);
    
    removeSinhVien(list, "Nguyen Van Teo", true);
    removeSinhVien(list, "Nguyen Van Cu", false);
    
    addSinhVien(list, createSinhVien("Tran Thi Mo", "25 Hong Bang", "TT0901", 2009));
    
    cout << "Danh sách sau khi cập nhật:" << endl;
    displayList(list);
    
    deleteList(list);
    return 0;
}
