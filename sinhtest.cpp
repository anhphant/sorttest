#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>
using namespace std;

// Hàm tạo số thực ngẫu nhiên trong khoảng [0, 1000]
double generateRandomDouble() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_real_distribution<> dis(0.0, 1000.0);
    return dis(gen);
}

// Hàm tạo dãy số thực
vector<double> generateSequence(int size, string type) {
    vector<double> sequence(size);

    if (type == "ascending") {
        for (int i = 0; i < size; i++) {
            sequence[i] = (i + 1) * (1000.0 / size); // Dãy tăng dần từ 0 đến 1000
        }
    } else if (type == "descending") {
        for (int i = 0; i < size; i++) {
            sequence[i] = 1000.0 - (i * (1000.0 / size)); // Dãy giảm dần từ 1000 đến 0
        }
    } else if (type == "random") {
        for (int i = 0; i < size; i++) {
            sequence[i] = generateRandomDouble(); // Dãy ngẫu nhiên
        }
    }

    return sequence;
}

// Hàm lưu dãy số vào file
void saveToFile(const vector<double>& sequence, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Không thể mở file " << filename << endl;
        return;
    }

    outFile << sequence.size() << endl;
    for (double num : sequence) {
        outFile << num << " ";
    }
    outFile.close();
}

int main() {
    const int n = 1000000; // Số lượng phần tử trong mỗi dãy
    vector<vector<double>> datasets(10);

    // Tạo dãy thứ nhất: tăng dần
    datasets[0] = generateSequence(n, "ascending");

    // Tạo dãy thứ hai: giảm dần
    datasets[1] = generateSequence(n, "descending");

    // Tạo 8 dãy còn lại: ngẫu nhiên
    for (int i = 2; i < 10; i++) {
        datasets[i] = generateSequence(n, "random");
    }

    // Lưu các dãy vào file
    for (int i = 0; i < 10; i++) {
        string filename = "test" + to_string(i + 1) + ".inp";
        saveToFile(datasets[i], filename);
        cout << "Đã lưu dãy " << i + 1 << " vào file " << filename << endl;
    }

    return 0;
}