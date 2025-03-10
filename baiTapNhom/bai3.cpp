#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

struct SortStats {
    long long comparisons;
    long long swaps;
};

// Biến toàn cục để đếm số lần so sánh và đổi chỗ
long long comparisons = 0, swaps = 0;

// Hàm tạo mảng ngẫu nhiên
vector<int> generateArray(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;
    return arr;
}

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    comparisons = swaps = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swaps++;
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    comparisons = swaps = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i) {
            swaps++;
            swap(arr[i], arr[minIdx]);
        }
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    comparisons = swaps = 0;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            swaps++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;

    while (i < left.size() && j < right.size()) {
        comparisons++;
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            swaps++;
            swap(arr[++i], arr[j]);
        }
    }
    swaps++;
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Heap Sort
void heapify(vector<int>& arr, int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) {
        comparisons++;
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        comparisons++;
        largest = right;
    }
    if (largest != i) {
        swaps++;
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    comparisons = swaps = 0;
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swaps++;
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Hàm đo số lần so sánh và đổi chỗ
SortStats measureSort(void (*sortFunction)(vector<int>&), vector<int>& arr) {
    sortFunction(arr);
    return {comparisons, swaps};
}

// Hàm hiển thị tiêu đề bảng
void printHeader() {
    cout << left << setw(10) << "Size"
         << setw(15) << "Algorithm"
         << setw(15) << "Comparisons"
         << setw(15) << "Swaps" << endl;
    cout << string(55, '-') << endl;
}

// Hàm hiển thị kết quả theo dạng bảng
void printResult(int size, const string& algorithm, SortStats stats) {
    cout << left << setw(10) << size
         << setw(15) << algorithm
         << setw(15) << stats.comparisons
         << setw(15) << stats.swaps << endl;
}

int main() {
    srand(time(0));
    vector<int> sizes = {10, 100, 200, 500, 1000, 5000, 10000};
    int t = 5;

    printHeader();

    for (int n : sizes) {
        for (auto sortPair : vector<pair<string, void(*)(vector<int>&)>>{
            {"BubbleSort", bubbleSort}, 
            {"SelectionSort", selectionSort}, 
            {"InsertionSort", insertionSort}, 
            {"MergeSort", [](vector<int>& arr) { mergeSort(arr, 0, arr.size() - 1); }},
            {"QuickSort", [](vector<int>& arr) { quickSort(arr, 0, arr.size() - 1); }},
            {"HeapSort", heapSort}
        }) {
            long long totalComparisons = 0, totalSwaps = 0;
            for (int i = 0; i < t; i++) {
                vector<int> arr = generateArray(n);
                SortStats stats = measureSort(sortPair.second, arr);
                totalComparisons += stats.comparisons;
                totalSwaps += stats.swaps;
            }
            printResult(n, sortPair.first, {totalComparisons / t, totalSwaps / t});
        }
    }
    return 0;
}
