import matplotlib.pyplot as plt
import numpy as np

# Dữ liệu
labels = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, "Trung bình"]
quicksort = [305, 606, 371, 366, 363, 375, 367, 372, 374, 372, 390]
heapsort = [662, 643, 892, 889, 893, 890, 905, 891, 887, 1031, 860]
mergesort = [907, 789, 985, 1012, 981, 1027, 986, 1010, 980, 990, 970]
sort_cpp = [195, 206, 473, 470, 471, 473, 470, 471, 484, 471, 420]
sort_numpy = [8, 9, 344, 340, 341, 343, 343, 343, 377, 344, 280]

# Số lượng nhóm (hàng dữ liệu) trên trục X
x = np.arange(len(labels))

# Độ rộng của mỗi cột
width = 0.15

# Vẽ các cột cho từng thuật toán, mỗi nhóm lệch nhau một khoảng width
plt.bar(x - 2*width, quicksort,  width, label='Quicksort')
plt.bar(x - width,   heapsort,   width, label='Heapsort')
plt.bar(x,           mergesort,  width, label='Mergesort')
plt.bar(x + width,   sort_cpp,   width, label='sort (C++)')
plt.bar(x + 2*width, sort_numpy, width, label='sort (numpy)')

# Gán nhãn cho trục X (tên các nhóm: 1, 2, 3, ..., 10, Trung bình)
plt.xticks(ticks=x, labels=labels)

# Thêm tiêu đề và nhãn cho trục
plt.title("Kết quả thử nghiệm trên bộ dữ liệu")
plt.xlabel("Dữ liệu")
plt.ylabel("Thời gian thực hiện (ms)")

# Hiển thị chú thích (legend)
plt.legend()

# Canh chỉnh layout cho gọn
plt.tight_layout()

# Hiển thị biểu đồ
plt.show()

# Nếu muốn lưu biểu đồ ra file ảnh, bỏ comment dòng dưới:
# plt.savefig("ket_qua_bieu_do.png", dpi=300)
