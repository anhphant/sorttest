import matplotlib.pyplot as plt
import pandas as pd

# Dữ liệu
data = {
    "Dữ liệu": [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, "Trung bình"],
    "Quicksort": [305, 606, 371, 366, 363, 375, 367, 372, 374, 372, 390],
    "Heapsort": [662, 643, 892, 889, 893, 890, 905, 891, 887, 1031, 860],
    "Mergesort": [907, 789, 985, 1012, 981, 1027, 986, 1010, 980, 990, 970],
    "sort (C++)": [195, 206, 473, 470, 471, 473, 470, 471, 484, 471, 420],
    "sort (numpy)": [8, 9, 344, 340, 341, 343, 343, 343, 377, 344, 280]
}

# Tạo DataFrame
df = pd.DataFrame(data)

# Vẽ bảng bằng Matplotlib
fig, ax = plt.subplots(figsize=(8, 4))  # Điều chỉnh kích thước hình ảnh
ax.axis('tight')
ax.axis('off')
table = ax.table(cellText=df.values, colLabels=df.columns, cellLoc='center', loc='center')

# Tùy chỉnh kích thước font chữ
table.auto_set_font_size(False)
table.set_fontsize(10)
table.auto_set_column_width([i for i in range(len(df.columns))])  # Canh chỉnh độ rộng cột

# Lưu bảng thành ảnh
file_path = "ket_qua_bang.png"
plt.savefig(file_path, dpi=300, bbox_inches='tight')

print(f"Đã tạo bảng và lưu vào file {file_path}")
