NOTE: + Dữ liệu thực nghiệm đều được generate ra trong các file mã nguồn. <br>
BÁO CÁO KẾT QUẢ THỬ NGHIỆM <br>
Sinh viên thực hiện: Ngô Viết Tuệ Đăng <br>
Lớp: TTNT.2025 <br>
Nội dung báo cáo: Thực nghiệm các giải thuật sắp xếp nối <br>
Lưu ý: + CPU được sử dụng cho thửc nghiệm: Ryzen 9 8945HX. <br>
	+ Các chương trình Python đều được random bằng seed 42 để có thể tạo bộ dữ liệu giống nhau giữa các lần chạy, chương trình C++ không sử dụng seed do 2 bộ sinh của Python và C++ là khác nhau. <br>
I.	Kết quả thử nghiệm <br>
1.	Bảng thời gian thực hiện (Wall time): <br>
<img width="983" height="458" alt="image" src="https://github.com/user-attachments/assets/ae94b0c3-36e1-41ff-8b35-5b783634f92d" />
Chú thích:  <br>
1: Mảng số thực 1 triệu phần tử có thứ tự tăng dần. <br>
2: Mảng số thực 1 triệu phần tử có thứ tự giảm dần. <br>
Từ 3 – 6: Mảng số thực 1 triệu phần tử thứ tự ngẫu nhiên. <br>
Từ 7 – 10: Mảng số thực 1 triệu phần tử thứ tự ngẫu nhiên. <br>
2.	Biểu đồ (cột) thời gian trung bình thực hiện: <br>
<img width="925" height="529" alt="image" src="https://github.com/user-attachments/assets/9876d29c-3c87-42cc-984c-a2bd74be903c" />
II.	Kết luận: <br>
1. Kết luận chung: <br>
Biểu đồ cho thấy có sự chênh lệch cực kỳ lớn về hiệu suất giữa các thuật toán tự cài đặt thủ công và các hàm sắp xếp được tối ưu hóa sẵn trong các thư viện chuẩn (C++ và Numpy). <br>
2. Phân tích chi tiết <br> <br>
Thuật toán chậm nhất: Heapsort mất nhiều thời gian nhất (8691 ms), chậm hơn khoảng 3.2 lần so với Quicksort trong cùng điều kiện thử nghiệm. <br>
Hiệu suất của các thuật toán kinh điển: <br>
+ Quicksort (2678 ms) tỏ ra ưu việt hơn hẳn so với Mergesort (3795 ms) và Heapsort. Điều này phản ánh đúng thực tế trong hầu hết các trường hợp dữ liệu ngẫu nhiên, Quicksort thường có hệ số hằng số nhỏ hơn. <br>
+ Sort (C++) (202.2 ms) nhanh hơn các bản tự cài đặt gấp hàng chục lần. <br>
+ Sort (numpy) (35.0 ms) là nhanh nhất, nhanh hơn Quicksort tự cài đặt khoảng 76 lần. <br>
3. Nhận định chuyên sâu <br>
Tối ưu hóa mã nguồn: Các hàm std::sort của C++ hoặc numpy.sort không chỉ đơn thuần là một thuật toán đơn lẻ; chúng thường là các thuật toán lai (như Introsort hoặc Timsort) và được tối ưu hóa ở mức ngôn ngữ máy, tận dụng tốt bộ nhớ đệm (cache) và các tập lệnh xử lý song song của CPU.
