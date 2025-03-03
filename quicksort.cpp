#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

int partition(vector<double>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);
    double pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<double>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Su dung: " << argv[0] << " <file_input> <file_output>" << endl;
        return 1;
    }

    srand(time(0));

    ifstream inFile(argv[1]);
    if (!inFile) {
        cerr << "Khong the mo file input: " << argv[1] << endl;
        return 1;
    }

    vector<double> arr;
    double num;
    while (inFile >> num) {
        arr.push_back(num);
    }
    inFile.close();

    auto start = high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;

    ofstream outFile(argv[2]);
    if (!outFile) {
        cerr << "Khong the mo file output: " << argv[2] << endl;
        return 1;
    }
    
    outFile << elapsed.count() << endl;
    outFile.close();
    return 0;
}