import sys
import time

def main():
    # Kiểm tra số lượng tham số dòng lệnh
    if len(sys.argv) < 3:
        print("Su dung: python pythonsort.py <file_input> <file_output>")
        sys.exit(1)

    input_file = sys.argv[1]  # Đường dẫn file input
    output_file = sys.argv[2]  # Đường dẫn file output

    # Đọc dữ liệu từ file input
    try:
        with open(input_file, 'r') as inFile:
            arr = list(map(float, inFile.read().split()))  # Đọc và chuyển đổi thành danh sách số thực
    except FileNotFoundError:
        print(f"Loi: File input '{input_file}' khong ton tai.")
        sys.exit(1)
    except ValueError:
        print(f"Loi: File input '{input_file}' chua du lieu khong hop le.")
        sys.exit(1)

    # Bắt đầu đo thời gian
    start_time = time.time()

    # Sắp xếp dữ liệu
    arr.sort()

    # Kết thúc đo thời gian
    end_time = time.time()
    elapsed_time = end_time - start_time

    # Ghi thời gian chạy vào file output
    try:
        with open(output_file, 'w') as outFile:
            outFile.write(f"{elapsed_time:.6f}")
    except IOError:
        print(f"Loi: Khong the ghi vao file output '{output_file}'.")
        sys.exit(1)

    #print(f"Da sap xep va ghi thoi gian chay vao file: {output_file}")

if __name__ == "__main__":
    main()