#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

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
    sort(arr.begin(), arr.end());
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