# README.md

📌 Sinh viên thực hiện: Nguyễn Thị Thảo Nguyên
📌 MSSV: 3121411150
📌 Trường: Đại Học Sài Gòn (SGU)
📌 Môn học: Cấu Trúc Dữ Liệu & Giải Thuật## 

🚀 Ý TƯỞNG
- **init**: Tạo một danh sách rỗng ban đầu.
- **insertFirst**: Thêm một phần tử mới vào đầu danh sách.
- **insertAfter**: Chèn phần tử mới sau một node đã có trong danh sách.
- **insertOrder**: Thêm phần tử sao cho danh sách luôn có thứ tự tăng dần.
- **showList**: Xuất toàn bộ danh sách ra màn hình.
- **listSize**: Đếm số phần tử trong danh sách.
- **isEmpty**: Xác định xem danh sách có phần tử nào không.
- **isFull**: Xác định xem danh sách có đầy không.
- **find**: Xác định xem phần tử có tồn tại không.
- **retrieve**: Trả về node tại vị trí cụ thể.
- **deleteFirst**: Loại bỏ phần tử đầu tiên.
- **deleteAfter**: Xóa node đứng ngay sau một node đã có.
- **removeOrder**: Loại bỏ phần tử mà vẫn giữ thứ tự danh sách.
- **selectionSort**: Sắp xếp danh sách theo thứ tự tăng dần.
- **clearList**: Giải phóng toàn bộ bộ nhớ của danh sách.

## 📥 INPUT
1. **Khởi tạo** danh sách liên kết rỗng.
2. **Thêm các phần tử** vào danh sách theo thứ tự (chèn vào đầu danh sách):
   - `10`
   - `5`
   - `15`
   - `7`
   - `12`
   - `20` _(Thay thế một phần tử tại vị trí cụ thể)_
3. **Hiển thị danh sách** sau khi thêm các phần tử.
4. **Lấy kích thước** danh sách.
5. **Kiểm tra danh sách có rỗng không**.
6. **Kiểm tra danh sách có đầy không**.
7. **Tìm kiếm phần tử** có giá trị `10`.
8. **Lấy phần tử tại vị trí `2`** trong danh sách.
9. **Xóa phần tử có giá trị `5`** _(phần tử không có trong danh sách nên không bị ảnh hưởng)_.
10. **Hiển thị danh sách** sau khi xóa phần tử.
11. **Sắp xếp danh sách** theo thứ tự tăng dần (**selectionSort**).
12. **Hiển thị danh sách** sau khi sắp xếp.
13. **Xóa toàn bộ danh sách**.
14. **Hiển thị danh sách** sau khi xóa toàn bộ.

## 📤 OUTPUT
```plaintext
📌 DANH SÁCH SAU KHI CHÈN: 7 -> 15 -> 20 -> 10 -> 12 -> NULL
📏 KÍCH THƯỚC DANH SÁCH: 5
❓ DANH SÁCH CÓ RỖNG KHÔNG? KHÔNG
📌 DANH SÁCH CÓ ĐẦY KHÔNG? KHÔNG
🔍 TÌM THẤY PHẦN TỬ: 10
📍 PHẦN TỬ TẠI VỊ TRÍ 2: 20
🗑️ DANH SÁCH SAU KHI XÓA 5: 7 -> 15 -> 20 -> 10 -> 12 -> NULL
📌 DANH SÁCH SAU KHI SẮP XẾP: 7 -> 10 -> 12 -> 15 -> 20 -> NULL
🗑️ DANH SÁCH SAU KHI XÓA TOÀN BỘ: NULL
```