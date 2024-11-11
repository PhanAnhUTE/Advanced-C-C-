### ADVANCE C

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
    
    ● Con trỏ hàm:
        Là 1 con trỏ trỏ tới 1 hàm, là 1 biến lưu trữ địa chỉ của hàm, gọi hàm thông qua con trỏ
        Ứng dụng trong những tình huống cần truyền các hàm như tham số cho một hàm khác. VD:
                      #include <stdio.h>
                      
                       int a = 15;
                       int b = 2;

                      int multiply(){
                      return a * b; 
                      }

                      void print(int (*funcptr)())
                      {
                          printf( "The value of the product is: " ,funcptr() );
                      }

                      int main()
                      {
                          print(multiply);
                          return 0;
                      }
               
    ● #Pointer to Constant:
        Con trỏ hằng: là 1 con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến,có thể thay đổi địa chỉ con trỏ trỏ tới
            const <kiểu dữ liệu> * < tên con trỏ>

    ● #Constant to Pointer
        Hằng con trỏ: Giống mảng 1 chiều, địa chỉ mà con trỏ trỏ tới không thể thay đổi, giá trị có thể thay đổi được
            <kiểu dữ liệu> * const <tên con trỏ>

    ● #Pointer to Pointer
        Là con trỏ trỏ tới 1 con trỏ khác, sử dụng để lưu địa chỉ của con trỏ

    ● #Null Pointer
        Là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào,kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa
		    Nên khởi tạo con trỏ là null nếu nó chưa trỏ đến một địa chỉ cụ thể nào

 </details> 


 <details>
   <summary>LESSON 4:MEMORY LAYOUT</summary>
   
      Memory layout gồm 5 phần chính: Text Segment, Initialized Data Segment, Uninitialized Data Segment, Heap và Stack
      
          ![image]([https://github.com/user-attachments/assets/6282fc99-c540-44c3-b2d7-91c3752e2931](https://khuenguyencreator.com/wp-content/uploads/2021/09/register-.jpg))
          
      ● Text Segment
        Sau khi compile chương trình thì sẽ có những file nhị phân (những file mà được dùng để execute chương trình khi đổ vào RAM), những file nhị phân (.o) này chứa những cái instructions. Và những cái instructions này sẽ stored ở Text Segment of the memory
		    Text segment chỉ có thể ở chế độ read
      
      ● Initialized Data
        Initialized Data (Data Segment - Dữ liệu đã được khởi tạo chứa:
		        Biến toàn cục được khởi tạo với giá # 0
		        Biến static được khởi tao với giá trị # 0
		        Có quyền đọc và ghi

      ● Uninitialized Data
        Uninitialized Data(BSS - Dữ liệu Chưa Khởi Tạo) chứa:
            Biến toàn cục khởi tọa với giá trị bằng 0 hoặc không gán giá trị
				    Chứa biến static được gán với giá trị khởi tạo là 0
    				Có quyền đọc, ghi
        
      ● Heap
      Dùng cho bộ nhớ để cấp phát động( trong thời gian chạy chương trình).
      Có thể điều khiển quá trình cấp phát hoặc giải phóng bộ nhớ bằng các câu lệnh như malloc, calloc, relloc. free, delete,...
      Khi dùng xong thì phải free nếu không sẽ bị leak memory
        Malloc: Cấp phát bộ nhớ có kích thước nhất định, giá trị trong bộ nhớ là ngẫu nhiên, giá trị rác
			  Calloc: Cấp phát 1 mảng n phần tử, mỗi phần tử có kích thước nhất định và khởi tạo tất cả phần tử về 0
			  Realloc: Thay đổi kích thước của bộ nhớ đã được cấp phát trước đó

      ● Stack
        Khác với Heap thì Stack là một vùng nhớ được cấp phát tự động
        Chứa các biến cục bộ, tham số truyền vào
		    Có quyền đọc,ghi 
        Mỗi khi các function được gọi thì nó sẽ được push vào vùng stack
    		Sau khi ra khỏi hàm sẽ thu hồi vùng nhớ

</details> 
     
<details>
  <summary>LESSON 5: Extern - Static - Volatile - Register</summary>

  ## Extern
      Là tham chiếu của 1 biến, hàm đã được định nghĩa ở file khác, phải là toàn cục

  ## Static
      ● Static với biến cục bộ:
				Chỉ có giá trị trong hàm nhưng khi ra khỏi hàm không bị mất đi	
      
    
			● Static với biến toàn cục:
				Được khai báo ở bên ngoài tất cả các hàm, có thể truy cập từ bất kỳ hàm nào trong file
				File khác không thể sử dụng biến này để tránh xung đột

  ## Volatile
      Thông báo cho compiler không được tối ưu hóa biến này
			Cho biết cho trình biên dịch rằng nó có thể thay đổi bất kỳ lúc 
   
				volatile int count;

					void ISR() {
					count++;
					}

					int main() {
					while (1) {
					// do something
					}
					return 0;
					}

					Trong ví dụ này, chúng ta khai báo biến "count" là volatile để cho biết rằng nó có thể được thay đổi bởi một ISR
					Nếu không có từ khóa volatile, trình biên dịch có thể tối ưu mã và giả định rằng "count" sẽ không bao giờ thay đổi,
					dẫn đến hành vi không mong muốn
  ## Register
        Là biến yêu cầu lưu nó vào thanh ghi trong PC, giúp tăng tốc độ thực thi chương trình
        ALU (2)  <=> Register (3) ->  <- (1)  Ram
					![image](https://github.com/user-attachments/assets/8722e556-0b65-405c-9c64-2caee0e0ea2a)

        
				  Khi thêm từ khóa register để khai báo biến, thì tức là ta đã yêu cầu trình biên dịch ưu tiên đặc biệt dành luôn vùng register để chứa biến đó. 
				  Và hiển nhiên khi thực hiện tính toán trên biến đó thì giảm được bước 1 và 3, 
				  Giảm bớt thủ tục thì hiệu năng nó tăng lên
      

     
     

      
        
     



















            
