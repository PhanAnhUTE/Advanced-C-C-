<details>
  <summary>LESSION 1: Compiler - Macro C</summary>
  
    - Định nghĩa Macro bằng lệnh chỉ thị #define kèm theo với một tên hoặc một hàm bất kỳ
        VD: #define var 100 
    - Trong quá trình tiền xủ lý(preprocessors), nếu xuất hiện một macro var thì bộ preprocessors sẽ thay thế các macro đó bằng 100
    - Macro có thể chứa hàm số, các tham số ở trong macro có thể là bất kì kiểu dữ liệu nào
  
</details>

<details>
  <summary>LESSON 2: STDARG - ASSERT C</summary>
  
    - Thư viện stdarg được sử dụng làm việc với các input parameter không xác định. VD: printf, scanf.
        Các tham số:
          1. va_list:là một kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi
          2. va_start: Bắt đầu một danh sách đối số biến đổi. Nó cần được gọi trước khi truy cập các đối số biến đổi đầu tiên
          3. va_arg: Truy cập một đối số trong danh sách. Hàm này nhận một đối số của kiểu được xác định bởi tham số thứ
          4. va_end: Kết thúc việc sử dụng danh sách đối số biến đổi. Nó cần được gọi trước khi kết thúc hàm
    - Thư viện assert 
          1. Cung cấp macro assert.
          2. Macro này được sử dụng để kiểm tra một điều kiện.
          3. Nếu điều kiện đúng (true), không có gì xảy ra và chương trình tiếp tục thực thi.
          4. Nếu điều kiện sai (false), chương trình dừng lại và thông báo một thông điệp lỗi.
          5. Dùng trong debug, dùng #define NDEBUG để tắt debug
 </details>  
 
<details>
  <summary>LESSON 3: POINTER C</summary>

    - Mỗi một biến sẽ có một địa chỉ khác nhau
    - Con trỏ là một biến được khai báo dùng để trỏ tới địa chỉ khác, được khai báo: datatype *ptr. VD: int *p
    - Khi khai báo p = &a thì p sẽ trỏ tới và lưu địa chỉ của biến a. Dùng deference(*) để lấy giá trị mà con trỏ trỏ tới

 
  
