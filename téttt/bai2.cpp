#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define MAX 100  // Giới hạn kích thước của hàng đợi

// ==========================
// Hàng đợi sử dụng mảng (QueueInt)
int queueArr[MAX];
int front = -1;
int rear = -1;

bool IsEmptyArr() {
    return front == -1;
}

bool IsFullArr() {
    return (rear + 1) % MAX == front;
}

void EnqueueArr(int value) {
    if (IsFullArr()) {
        cout << "Queue is full!" << endl;
    } else {
        if (front == -1) front = 0;  // Đặt front khi hàng đợi bắt đầu
        rear = (rear + 1) % MAX;
        queueArr[rear] = value;
    }
}

int DequeueArr() {
    if (IsEmptyArr()) {
        cout << "Queue is empty!" << endl;
        return -1;
    } else {
        int value = queueArr[front];
        if (front == rear) {
            front = rear = -1;  // Reset khi hàng đợi trống
        } else {
            front = (front + 1) % MAX;
        }
        return value;
}

int PeekArr() {
    if (IsEmptyArr()) {
        cout << "Queue is empty!" << endl;
        return -1;
    } else {
        return queueArr[front];
    }
}

void ClearArr() {
    front = rear = -1;
}

// ==========================
// Hàng đợi sử dụng danh sách liên kết (LinkedQueueInt)
struct Node {
    int data;
    Node* next;
};

Node* frontLinked = nullptr;
Node* rearLinked = nullptr;

bool IsEmptyLinked() {
    return frontLinked == nullptr;
}

void EnqueueLinked(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (IsEmptyLinked()) {
        frontLinked = rearLinked = newNode;
    } else {
        rearLinked->next = newNode;
        rearLinked = newNode;
    }
}

int DequeueLinked() {
    if (IsEmptyLinked()) {
        cout << "Queue is empty!" << endl;
        return -1;
    } else {
        Node* temp = frontLinked;
        int value = temp->data;
        frontLinked = frontLinked->next;
        delete temp;
        if (frontLinked == nullptr) {
            rearLinked = nullptr;
        }
        return value;
}

int PeekLinked() {
    if (IsEmptyLinked()) {
        cout << "Queue is empty!" << endl;
        return -1;
    } else {
        return frontLinked->data;
    }
}

void ClearLinked() {
    while (!IsEmptyLinked()) {
        DequeueLinked();
    }
}

// ==========================
// Ứng dụng 1: Xếp lịch cặp múa nam/nữ
void DancePairing(int n) {
    // Khởi tạo hàng đợi cho nam và nữ
    int maleQueue[MAX], femaleQueue[MAX];
    int maleFront = -1, maleRear = -1, femaleFront = -1, femaleRear = -1;

    // Thêm các nam và nữ vào hàng đợi
    for (int i = 1; i <= n; i++) {
        EnqueueArr(maleQueue, maleFront, maleRear, i);   // Thêm các nam vào hàng đợi
        EnqueueArr(femaleQueue, femaleFront, femaleRear, i); // Thêm các nữ vào hàng đợi
    }

    // Ghép cặp
    cout << "Dance Pairings: " << endl;
    while (!IsEmptyArr(maleQueue, maleFront)) {
        int male = DequeueArr(maleQueue, maleFront, maleRear);
        int female = DequeueArr(femaleQueue, femaleFront, femaleRear);
        cout << "Pair: Male " << male << " - Female " << female << endl;
    }
}

// ==========================
// Ứng dụng 2: Thuật toán RadixSort
int GetDigit(int num, int digitPos) {
    return (num / static_cast<int>(pow(10, digitPos))) % 10;
}

void RadixSort(int arr[], int n) {
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

    // Sắp xếp theo từng chữ số
    for (int d = 0; d < maxDigits; d++) {
        vector<queue<int>> buckets(10);  // 10 hàng đợi, mỗi hàng đợi chứa các phần tử có chữ số giống nhau

        // Phân loại các phần tử vào các hàng đợi
        for (int i = 0; i < n; i++) {
            int digit = GetDigit(arr[i], d);
            buckets[digit].push(arr[i]);
        }

        // Lấy các phần tử ra từ hàng đợi theo thứ tự và đưa vào mảng
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

// ==========================
// Hàm main
int main() {
    int choice, num, n;
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    do {
        cout << "Menu:" << endl;
        cout << "1. Reverse a number using queue" << endl;
        cout << "2. Check if a string is palindrome using queue" << endl;
        cout << "3. Convert decimal to binary using queue" << endl;
        cout << "4. Infix to Postfix conversion and evaluate the expression" << endl;
        cout << "5. Dance Pairing Problem" << endl;
        cout << "6. Radix Sort" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Call your functions for reversing numbers using queue here
                break;

            case 2:
                // Call your functions for palindrome checking here
                break;

            case 3:
                // Call your functions for decimal to binary conversion here
                break;

            case 4:
                // Call your functions for postfix expression evaluation here
                break;

            case 5:
                cout << "Enter the number of dancers: ";
                cin >> n;
                DancePairing(n);
                break;

            case 6:
                RadixSort(arr, arrSize);
                break;

            case 0:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
