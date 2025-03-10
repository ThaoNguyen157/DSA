#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip> // Thư viện để định dạng bảng
#include <map>     // Thư viện để lưu kết quả

using namespace std;
using namespace std::chrono;

// Hàm tạo 30.000 số ngẫu nhiên và lưu vào file
void generateRandomNumbers(const string &filename, int count, int minVal, int maxVal) {
    ofstream outFile(filename);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(minVal, maxVal);

    for (int i = 0; i < count; i++) {
        outFile << dist(gen) << " ";
    }
    outFile.close();
}

// Hàm đọc số từ file vào vector
vector<int> readNumbersFromFile(const string &filename) {
    vector<int> numbers;
    ifstream inFile(filename);
    int num;
    while (inFile >> num) {
        numbers.push_back(num);
    }
    inFile.close();
    return numbers;
}

// Hàm ghi kết quả vào file
void writeResultToFile(const string &filename, const vector<int> &sortedNumbers, double timeTaken, const string &algoName) {
    ofstream outFile(filename, ios::app);
    outFile << algoName << " - Time: " << timeTaken << " ms\n";
    outFile << "Sorted Data: ";
    for (int num : sortedNumbers) {
        outFile << num << " ";
    }
    outFile << "\n\n";
    outFile.close();
}

// Interchange Sort (Sắp xếp đổi chỗ trực tiếp)
void interchangeSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

// Selection Sort (Sắp xếp chọn trực tiếp)
void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Insertion Sort (Sắp xếp chèn trực tiếp)
void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort (Sắp xếp nổi bọt)
void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Quick Sort (Sắp xếp nhanh)
void quickSort(vector<int> &arr, int left, int right) {
    if (left >= right) return;
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[++i], arr[right]);
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

// Merge Sort (Sắp xếp trộn)
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Heap Sort (Sắp xếp cây)
void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Hàm thực hiện sắp xếp và đo thời gian
map<string, double> results; 
void sortAndMeasure(vector<int> arr, void (*sortFunc)(vector<int>&), const string &name) {
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto end = high_resolution_clock::now();
    double duration = duration_cast<milliseconds>(end - start).count();
    results[name] = duration; // Lưu kết quả vào map
    writeResultToFile("output.txt", arr, duration, name);
}

// void sortAndMeasure(vector<int> arr, void (*sortFunc)(vector<int>&), const string &name) {
//     auto start = high_resolution_clock::now();
//     sortFunc(arr);
//     auto end = high_resolution_clock::now();
//     double duration = duration_cast<milliseconds>(end - start).count();
// }

void displayResultsTable() {
    cout << "\n================= Sorting Performance =================\n";
    cout << left << setw(25) << "Algorithm" << setw(15) << "Time (ms)" << "\n";
    cout << "------------------------------------------------------\n";
    for (const auto &entry : results) {
        cout << left << setw(25) << entry.first << setw(15) << entry.second << "\n";
    }
    cout << "======================================================\n";
}

int main() {
    generateRandomNumbers("input.txt", 30000, 1, 1000000);
    vector<int> numbers = readNumbersFromFile("C:/Users/ASUS/Desktop/input.txt");

    ofstream outFile("output.txt");
    outFile << "Sorting Results:\n";
    outFile.close();

    sortAndMeasure(numbers, interchangeSort, "Interchange Sort");
    sortAndMeasure(numbers, selectionSort, "Selection Sort");
    sortAndMeasure(numbers, insertionSort, "Insertion Sort");
    sortAndMeasure(numbers, bubbleSort, "Bubble Sort");

    // Quick Sort
    vector<int> quickNumbers = numbers;
    auto startQuick = high_resolution_clock::now();
    quickSort(quickNumbers, 0, quickNumbers.size() - 1);
    auto endQuick = high_resolution_clock::now();
    results["Quick Sort"] = duration_cast<milliseconds>(endQuick - startQuick).count();

    sortAndMeasure(numbers, heapSort, "Heap Sort");

    // Merge Sort
    vector<int> mergeNumbers = numbers;
    auto startMerge = high_resolution_clock::now();
    mergeSort(mergeNumbers, 0, mergeNumbers.size() - 1);
    auto endMerge = high_resolution_clock::now();
    results["Merge Sort"] = duration_cast<milliseconds>(endMerge - startMerge).count();

    displayResultsTable(); // Hiển thị bảng kết quả

    cout << "Sorting complete. Check output.txt for results.\n";
    return 0;
}