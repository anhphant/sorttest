#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Hàm đọc thời gian từ file, trả về giá trị dạng double
double readTimeFromFile(const string& filepath) {
    ifstream fin(filepath);
    if (!fin) {
        cerr << "Lỗi khi mở file: " << filepath << endl;
        return 0.0; // Nếu không mở được file thì trả về 0
    }
    double value = 0.0;
    fin >> value;
    return value;
}

int main() {
    // Đường dẫn đến thư mục chứa các file kết quả
    const string basePath = "F:\\TranLeAnhPha\\Storage\\Areas\\GPA\\DSAdl\\sorting\\sources\\results\\";
    // Danh sách các thuật toán (theo thứ tự cột)
    vector<string> algorithms = {"quicksort", "heapsort", "mergesort", "cppsort", "pythonsort"};
    const int numTests = 10; // Số lượng bài test
    
    // Khởi tạo ma trận lưu kết quả: mỗi dòng ứng với một bài test,
    // mỗi cột ứng với một thuật toán
    vector<vector<double>> results(numTests, vector<double>(algorithms.size(), 0.0));
    
    // Đọc dữ liệu từ các file
    for (int i = 0; i < numTests; ++i) {
        for (size_t j = 0; j < algorithms.size(); ++j) {
            // Tên file theo mẫu: test{i+1}_{algo}.out
            string filename = "test" + to_string(i + 1) + "_" + algorithms[j] + ".out";
            string filepath = basePath + filename;
            results[i][j] = readTimeFromFile(filepath);
        }
    }
    
    // Mở file output để ghi kết quả bảng
    ofstream fout("statistic.txt");
    if (!fout) {
        cerr << "Không mở được file statistic.txt để ghi kết quả." << endl;
        return 1;
    }
    
    // In tiêu đề bảng
    fout << "Dữ liệu\tQuicksort\tHeapsort\tMergesort\tsort (C++)\tsort (numpy)" << "\n";
    
    // In dữ liệu từng bài test
    for (int i = 0; i < numTests; ++i) {
        fout << (i + 1) << "\t";
        for (size_t j = 0; j < algorithms.size(); ++j) {
            fout << results[i][j] << "\t\t";
        }
        fout << "\n";
    }
    
    // Tính trung bình cho mỗi thuật toán
    vector<double> avg(algorithms.size(), 0.0);
    for (size_t j = 0; j < algorithms.size(); ++j) {
        double sum = 0.0;
        for (int i = 0; i < numTests; ++i) {
            sum += results[i][j];
        }
        avg[j] = sum / numTests;
    }
    
    // In dòng trung bình
    fout << "Trung bình\t";
    for (size_t j = 0; j < avg.size(); ++j) {
        fout << fixed << setprecision(2) << avg[j] << "\t\t";
    }
    fout << "\n";
    
    fout.close();
    cout << "Đã ghi kết quả vào file statistic.txt" << endl;
    return 0;
}
