#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;

void merge(vector<double>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<double> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<double>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Su dung: " << argv[0] << " <file_input> <file_output>" << endl;
        return 1;
    }

    ifstream inFile(argv[1]);
    if (!inFile) {
        cerr << "Khong the mo file input" << endl;
        return 1;
    }

    vector<double> arr;
    double num;
    while (inFile >> num) {
        arr.push_back(num);
    }
    inFile.close();

    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
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