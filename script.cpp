#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <cstdlib> // for system()
using namespace std;
using namespace std::chrono;

// Ham de chay mot chuong trinh sap xep va do thoi gian
void chayChuongTrinhSapXep(const string& chuongTrinh, const string& fileInput, const string& fileOutput) {
    cout << "Dang xu ly file input: " << fileInput << endl;

    // Kiem tra xem file input co ton tai khong
    ifstream kiemTraFile(fileInput);
    if (!kiemTraFile) {
        cerr << "Loi: File input khong ton tai hoac khong the mo - " << fileInput << endl;
        return;
    }
    kiemTraFile.close();

    auto batDau = high_resolution_clock::now();
    string lenh = chuongTrinh + " \"" + fileInput + "\" \"" + fileOutput + "\"";
    cerr << "command : " << lenh << '\n';
    int ketQua = system(lenh.c_str());
    auto ketThuc = high_resolution_clock::now();
    duration<double> thoiGianChay = ketThuc - batDau;

    if (ketQua == 0) {
        ofstream fileOut(fileOutput, ios::app); // Mo file de ghi them thoi gian chay
        if (fileOut) {
            //fileOut << "Thoi gian chay: " << thoiGianChay.count() << " giay\n";
            fileOut.close();
        } else {
            cerr << "Khong the mo file output: " << fileOutput << endl;
        }
    } else {
        cerr << "Loi khi chay chuong trinh: " << chuongTrinh << endl;
    }
}

int main() {
    // Danh sach cac chuong trinh sap xep (bao gom ca Python)
    vector<string> cacChuongTrinh = {
        "heapsort.exe",
        "mergesort.exe",
        "quicksort.exe",
        "cppsort.exe",
        "pythonsort.exe" // Chuong trinh Python
    };

    // Thu muc chua cac file input
    string thuMucInput = "F:\\TranLeAnhPha\\Storage\\Areas\\GPA\\DSAdl\\sorting\\sources\\output";

    // Thu muc de luu cac file output
    string thuMucOutput = "F:\\TranLeAnhPha\\Storage\\Areas\\GPA\\DSAdl\\sorting\\sources\\results";

    // Tao thu muc output neu chua ton tai
    string lenhTaoThuMuc = "if not exist \"" + thuMucOutput + "\" mkdir \"" + thuMucOutput + "\"";
    system(lenhTaoThuMuc.c_str());

    // Duyet qua tung file input
    for (int i = 1; i <= 10; i++) {
        string fileInput = thuMucInput + "\\test" + to_string(i) + ".inp";

        // Kiem tra xem file input co ton tai khong
        ifstream kiemTraFile(fileInput);
        cerr << fileInput << '\n';
        if (!kiemTraFile) {
            cerr << "Loi: File input khong ton tai - " << fileInput << endl;
            continue; // Bo qua file nay va chuyen sang file tiep theo
        }
        kiemTraFile.close();

        // Duyet qua tung chuong trinh sap xep
        for (const string& chuongTrinh : cacChuongTrinh) {
            string fileOutput = thuMucOutput + "\\test" + to_string(i) + "_" + chuongTrinh.substr(0, chuongTrinh.find('.')) + ".out";
            string fileChuongTrinh = thuMucInput + "\\" + chuongTrinh;
            chayChuongTrinhSapXep(fileChuongTrinh, fileInput, fileOutput);
        }
    }

    cout << "Da chay xong tat ca cac chuong trinh sap xep." << endl;
    return 0;
}