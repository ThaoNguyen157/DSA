#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

#define MAX 100

// ==============================
// Cài đặt QueueInt dùng mảng
int stackArr[MAX];
int topArr = -1;

void InitStackArr() {
    topArr = -1;
}

bool IsEmptyArr() {
    return topArr == -1;
}

bool IsFullArr() {
    return topArr == MAX - 1;
}

void PushStackArr(int value) {
    if (IsFullArr()) {
        cerr << "Error: Stack is full! Cannot push value." << endl;
    } else {
        stackArr[++topArr] = value;
    }
}

int PopStackArr() {
    if (IsEmptyArr()) {
        cerr << "Error: Stack is empty! Cannot pop value." << endl;
        return -1;
    } else {
        return stackArr[topArr--];
    }
}

int PeekStackArr() {
    if (IsEmptyArr()) {
        cerr << "Error: Stack is empty! Cannot peek value." << endl;
        return -1;
    } else {
        return stackArr[topArr];
    }
}

void ClearStackArr() {
    topArr = -1;
}

// ==============================
// Cài đặt LinkedQueueInt dùng danh sách liên kết
struct Node {
    int data;
    Node* next;
};

Node* topLinked = nullptr;

void InitStackLinked() {
    topLinked = nullptr;
}

bool IsEmptyLinked() {
    return topLinked == nullptr;
}

void PushStackLinked(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        cerr << "Error: Memory allocation failed!" << endl;
        return;
    }
    newNode->data = value;
    newNode->next = topLinked;
    topLinked = newNode;
}

int PopStackLinked() {
    if (IsEmptyLinked()) {
        cerr << "Error: Stack is empty! Cannot pop value." << endl;
        return -1;
    } else {
        Node* temp = topLinked;
        int value = temp->data;
        topLinked = topLinked->next;
        delete temp;
        return value;
    }
}

int PeekStackLinked() {
    if (IsEmptyLinked()) {
        cerr << "Error: Stack is empty! Cannot peek value." << endl;
        return -1;
    } else {
        return topLinked->data;
    }
}

void ClearStackLinked() {
    while (!IsEmptyLinked()) {
        PopStackLinked();
    }
}

// ==============================
// Thuật toán RadixSort sử dụng Queue
int GetDigit(int num, int digitPos) {
    return (num / static_cast<int>(pow(10, digitPos))) % 10;
}

void RadixSort(int arr[], int n) {
    if (n <= 0) {
        cerr << "Error: Array size must be greater than 0!" << endl;
        return;
    }

    int maxElem = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElem) {
            maxElem = arr[i];
        }
    }

    int maxDigits = 0;
    while (maxElem > 0) {
        maxDigits++;
        maxElem /= 10;
    }

    for (int d = 0; d < maxDigits; d++) {
        queue<int> buckets[10];

        for (int i = 0; i < n; i++) {
            int digit = GetDigit(arr[i], d);
            buckets[digit].push(arr[i]);
        }

        int idx = 0;
        for (int i = 0; i < 10; i++) {
            while (!buckets[i].empty()) {
                arr[idx++] = buckets[i].front();
                buckets[i].pop();
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ==============================
// Ứng dụng quản lý xếp hàng múa
struct Dancer {
    char Name[100];
    char Sex[10];
};

void GetName(Dancer &d, const char *s) {
    strcpy(d.Name, s);
}

const char* ToString(Dancer &d) {
    return d.Name;
}

struct Queue {
    queue<Dancer> q;

    bool IsEmpty() {
        return q.empty();
    }

    void Enqueue(const Dancer &d) {
        q.push(d);
    }

    Dancer Dequeue() {
        if (q.empty()) {
            cerr << "Error: Queue is empty! Cannot dequeue." << endl;
            return {"", ""};
        }
        Dancer d = q.front();
        q.pop();
        return d;
    }

    Dancer Peek() {
        if (q.empty()) {
            cerr << "Error: Queue is empty! Cannot peek." << endl;
            return {"", ""};
        }
        return q.front();
    }

    int Count() {
        return q.size();
    }

    void Clear() {
        while (!q.empty()) {
            q.pop();
        }
    }
};

void NewDancers(Queue &male, Queue &female) {
    if (male.Count() > 0 && female.Count() > 0) {
        Dancer m = male.Dequeue();
        Dancer w = female.Dequeue();
        printf("Cap dien vien: %s va %s\n", m.Name, w.Name);
    } else if (male.Count() > 0 && female.Count() == 0) {
        printf("Dang cho dien vien nu.\n");
    } else if (female.Count() > 0 && male.Count() == 0) {
        printf("Dang cho dien vien nam.\n");
    } else {
        printf("Khong co dien vien nao trong hang cho.\n");
    }
}

void StartDancing(Queue &male, Queue &female) {
    printf("Cac cap dien vien:\n");
    while (male.Count() > 0 && female.Count() > 0) {
        Dancer m = male.Dequeue();
        Dancer w = female.Dequeue();
        printf("%s \t %s\n", m.Name, w.Name);
    }

    if (male.Count() > 0) {
        printf("Van con %d dien vien nam trong hang cho.\n", male.Count());
    }
    if (female.Count() > 0) {
        printf("Van con %d dien vien nu trong hang cho.\n", female.Count());
    }
}

void ShowQueue(Queue &q) {
    if (q.IsEmpty()) {
        printf("Hang doi trong.\n");
        return;
    }

    queue<Dancer> tempQueue = q.q;
    while (!tempQueue.empty()) {
        Dancer d = tempQueue.front();
        tempQueue.pop();
        printf("%s\n", d.Name);
    }
}

void FormLines(Queue &male, Queue &female) {
    male.Clear();
    female.Clear();

    int n;
    cout << "Nhap so luong dien vien: ";
    cin >> n;

    if (n <= 0) {
        cerr << "Error: So luong dien vien phai lon hon 0!" << endl;
        return;
    }

    Dancer d;
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin dien vien thu " << i + 1 << " (gioi tinh M/F va ten): ";
        cin >> d.Sex >> d.Name;
        if (strcmp(d.Sex, "M") == 0) {
            male.Enqueue(d);
        } else if (strcmp(d.Sex, "F") == 0) {
            female.Enqueue(d);
        } else {
            cerr << "Error: Gioi tinh khong hop le! Vui long nhap lai." << endl;
            i--; // Retry current input
        }
    }
}

int main() {
    Queue males;
    Queue females;

    int choice;

    do {
        cout << "==============================\n";
        cout << "Menu\n";
        cout << "1. Quan ly xep hang mua\n";
        cout << "2. RadixSort\n";
        cout << "3. Thoat\n";
        cout << "==============================\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                FormLines(males, females);

                cout << "\nDanh sach dien vien nam:\n";
                ShowQueue(males);
                cout << "\nDanh sach dien vien nu:\n";
                ShowQueue(females);

                StartDancing(males, females);
                break;
            }
            case 2: {
                int n;
                cout << "Nhap so luong phan tu: ";
                cin >> n;

                if (n <= 0) {
                    cerr << "Error: So luong phan tu phai lon hon 0!" << endl;
                    break;
                }

                int arr[n];
                cout << "Nhap cac phan tu: ";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }

                RadixSort(arr, n);
                break;
            }
            case 3: {
                cout << "Thoat chuong trinh. Tam biet!\n";
                break;
            }
            default:
                cerr << "Error: Lua chon khong hop le. Vui long nhap lai." << endl;
        }
    } while (choice != 3);

    return 0;
}
