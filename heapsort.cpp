#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;

void heapify(vector<double>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(vector<double>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Su dung: " << argv[0] << " <file_input> <file_output>" << endl;
        return argc + 1;
    }

    ifstream inFile(argv[1]);
    if (!inFile) {
        cerr << "Khong the mo file input" << endl;
        return 2;
    }

    vector<double> arr;
    double num;
    while (inFile >> num) {
        arr.push_back(num);
    }
    inFile.close();

    auto start = chrono::high_resolution_clock::now();
    heapsort(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    ofstream outFile(argv[2]);
    if (!outFile) {
        cerr << "Khong the mo file output" << endl;
        return 1;
    }

    outFile << elapsed.count() << endl;
    outFile.close();

    return 0;
}