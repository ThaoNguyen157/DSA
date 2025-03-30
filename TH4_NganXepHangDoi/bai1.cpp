#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <cctype>

using namespace std;

#define MAX 100 // Giới hạn kích thước của ngăn xếp

// ----------------------------
// (a) Cài đặt ngăn xếp bằng mảng (StackInt)
int stackArr[MAX];
int topArr = -1;

bool IsEmptyArr() {
    return topArr == -1;
}

bool IsFullArr() {
    return topArr == MAX - 1;
}

void PushArr(int value) {
    if (IsFullArr()) {
        cout << "Stack is full!" << endl;
    } else {
        stackArr[++topArr] = value;
    }
}

int PopArr() {
    if (IsEmptyArr()) {
        cout << "Stack is empty!" << endl;
        return -1;
    } else {
        return stackArr[topArr--];
    }
}

int PeekArr() {
    if (IsEmptyArr()) {
        cout << "Stack is empty!" << endl;
        return -1;
    } else {
        return stackArr[topArr];
    }
}

void ClearArr() {
    topArr = -1;
}

// ----------------------------
// (b) Cài đặt ngăn xếp bằng danh sách liên kết (LinkedStackInt)
struct Node {
    int data;
    Node* next;
};

Node* topLinked = nullptr;

bool IsEmptyLinked() {
    return topLinked == nullptr;
}

void PushLinked(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = topLinked;
    topLinked = newNode;
}

int PopLinked() {
    if (IsEmptyLinked()) {
        cout << "Stack is empty!" << endl;
        return -1;
    } else {
        Node* temp = topLinked;
        int value = temp->data;
        topLinked = topLinked->next;
        delete temp;
        return value;
    }
}

int PeekLinked() {
    if (IsEmptyLinked()) {
        cout << "Stack is empty!" << endl;
        return -1;
    } else {
        return topLinked->data;
    }
}

void ClearLinked() {
    while (!IsEmptyLinked()) {
        PopLinked();
    }
}

// ----------------------------
// (c) Ứng dụng ngăn xếp để đảo số (Sử dụng ngăn xếp mảng)
void ReverseNumber(int num) {
    ClearArr();
    while (num > 0) {
        PushArr(num % 10); // Đẩy từng chữ số vào stack
        num /= 10;
    }

    int reversedNum = 0;
    int multiplier = 1;

    while (!IsEmptyArr()) {
        reversedNum += PopArr() * multiplier;
        multiplier *= 10;
    }

    cout << "Reversed number: " << reversedNum << endl;
}

// ----------------------------
// (d) Ứng dụng ngăn xếp để kiểm tra xâu đối xứng (StackString)
bool IsPalindrome(const string& str) {
    ClearArr();
    int len = str.length();
    // Đẩy các ký tự vào ngăn xếp
    for (int i = 0; i < len; i++) {
        PushArr(str[i]);
    }
    // Kiểm tra tính đối xứng
    for (int i = 0; i < len; i++) {
        if (str[i] != PopArr()) {
            return false;
        }
    }
    return true;
}

// ----------------------------
// (e) Ứng dụng ngăn xếp để đổi từ số thập phân sang nhị phân
void DecimalToBinary(int num) {
    ClearArr();
    while (num > 0) {
        PushArr(num % 2);
        num /= 2;
    }

    cout << "Binary: ";
    while (!IsEmptyArr()) {
        cout << PopArr();
    }
    cout << endl;
}

// ----------------------------
// (f) Chuyển đổi biểu thức từ tiền tố sang hậu tố và tính giá trị biểu thức
// Hàm kiểm tra nếu một ký tự là toán tử
bool IsOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Hàm tính toán
int ApplyOperator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

// Hàm kiểm tra độ ưu tiên của toán tử
int Precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Chuyển đổi biểu thức từ trung tố sang hậu tố
string InfixToPostfix(string expr) {
    stack<char> operators;
    string postfix = "";

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        
        if (isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        } else if (IsOperator(c)) {
            while (!operators.empty() && Precedence(operators.top()) >= Precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Tính giá trị của biểu thức hậu tố
int EvaluatePostfix(string expr) {
    stack<int> values;

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];

        if (isdigit(c)) {
            values.push(c - '0');
        } else if (IsOperator(c)) {
            int val2 = values.top(); values.pop();
            int val1 = values.top(); values.pop();
            values.push(ApplyOperator(val1, val2, c));
        }
    }

    return values.top();
}

// ----------------------------
// Hàm main
int main() {
    int choice, num;
    string expr, str;

    do {
        cout << "Menu:" << endl;
        cout << "1. Reverse a number using stack" << endl;
        cout << "2. Check if a string is palindrome using stack" << endl;
        cout << "3. Convert decimal to binary using stack" << endl;
        cout << "4. Infix to Postfix conversion and evaluate the expression" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a number: ";
                cin >> num;
                ReverseNumber(num);
                break;

            case 2:
                cout << "Enter a string: ";
                cin >> str;
                if (IsPalindrome(str)) {
                    cout << "The string is a palindrome." << endl;
                } else {
                    cout << "The string is not a palindrome." << endl;
                }
                break;

            case 3:
                cout << "Enter a decimal number: ";
                cin >> num;
                DecimalToBinary(num);
                break;

            case 4:
                cout << "Enter an infix expression (e.g., 3+(2*5)): ";
                cin >> expr;
                {
                    string postfix = InfixToPostfix(expr);
                    cout << "Postfix expression: " << postfix << endl;
                    cout << "Result of the postfix expression: " << EvaluatePostfix(postfix) << endl;
                }
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
