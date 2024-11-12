##### ADVANCE C

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
      
</details> 

<details>
	<summary>LESSON 6: GOTO - SETJMP </summary>
	
		*Goto* là một từ khóa trong ngôn ngữ lập trình C cho phép người dùng nhảy đến một label đã được đặt trước đó trong cùng một. Không được khuyến khích dùng vì nó làm cho chương trình trở nên khó đọc và bảo 			trì. >- Ví dụ về từ khóa *go to*
                        #include <stdio.h>
                        void delay(double second)
                        {
                            double start = 0;
                            while (start < second * 6000000)
                            {
                                start++;
                            }
                        }
                        // Khai báo các trạng thái đèn giao thông
                        typedef enum //1 thời điểm chỉ có 1 đèn để 
                        {
                            RED,
                            YELLOW,
                            GREEN
                        } TrafficLightState;
                        int main() {
                            // Ban đầu, đèn giao thông ở trạng thái đỏ
                            TrafficLightState state = RED;
                        
                            // Vòng lặp vô hạn để mô phỏng đèn giao thông
                            while (1) {
                                switch (state) {
                                    case RED:
                                        printf("RED Light\n");
                                        delay(50);  // Giữ trạng thái đèn đỏ trong x giây
                                        
                                        // Chuyển đến trạng thái đèn xanh
                                        state = GREEN;
                                        goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái
                                    case YELLOW:
                                        printf("YELLOW Light\n");
                                        delay(20);  // Giữ trạng thái đèn vàng trong y giây
                                        
                                        // Chuyển đến trạng thái đèn đỏ
                                        state = RED;
                                        goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái
                                    case GREEN:
                                        printf("GREEN Light\n");
                                        delay(100);  // Giữ trạng thái đèn xanh trong z giây
                                        
                                        // Chuyển đến trạng thái đèn vàng
                                        state = YELLOW;
                                        goto skip_sleep;  // Nhảy qua sleep() khi chuyển trạng thái
                                }
                                // Nhãn để nhảy qua sleep() khi chuyển trạng thái
                                skip_sleep:;
                            }
                            return 0;
                        }
		Trong ví dụ trên trạng thái đèn đỏ đầu tiên, khi chờ khoảng 50s thì trạng thái đèn xanh, nó sẽ thoát ra khỏi switch và bắt đầu switch case khác vì nó đã dùng label skip_Spleep (cái này được đặt ngoài hàm 		nên nôn na sẽ thoát khỏi hàm, lần lượt chuyển sang đèn khác thứ tự là ĐỎ - XANH - VÀNG Setjmp.h là một thư viện trong ngôn ngữ lập trình C cung cấp 2 hàm là setjmp và longjmp dùng để xử lí ngoại lệ 			trong( nó không tiêu biểu để xử lí ngoại lệ trong ngôn ngữ này).
		Ví dụ về Setjmp.h
                   #include <stdio.h>
                   #include <setjmp.h>
                   
                   jmp_buf buf;
                   int exception_code;
                   
                   #define TRY if ((exception_code = setjmp(buf)) == 0) 
                   #define CATCH(x) else if (exception_code == (x)) 
                   #define THROW(x) longjmp(buf, (x))
                   
                   
                   double divide(int a, int b) {
                       if (b == 0) {
                           THROW(1); // Mã lỗi 1 cho lỗi chia cho 0
                       }
                       return (double)a / b;
                   }
                   
                   int main() {
                       int a = 10;
                       int b = 0;
                       double result = 0.0;
                   
                       TRY {
                           result = divide(a, b);
                           printf("Result: %f\n", result);
                       } CATCH(1) {
                           printf("Error: Divide by 0!\n");
                       }
                   
                   
                       // Các xử lý khác của chương trình
                       return 0;
                   }
</details> 


<details>
	<summary>LESSON 7: BITMASK </summary>
	
 
 		Được sử dụng để tối ưu hóa bộ nhớ

      ● NOT biswise: Khi thực hiện phép toán này thì kết quả của nó là đão của nó. Ví dụ: 1 not bitwise được kết quả là 0
      ● AND biswise: Kết quả là 1 nếu 2 bit đều là 1, còn lại là 0.
		    Có 1 phép toán hay. Ví dụ nếu ta muốn coi 1 số là chẵn lẽ thì mình có thể dùng %2 nhưng ngoài ra mình cũng có thể sử dụng bitwise AND(&). Mình chỉ cần & số đó với 1(&1).
		    Nếu kết quả là 1 thì số đó là số lẻ, còn kết quả là 0 thì số đó là số chẵn
		    Giải thích: tại vì số lẻ là số có bit bên trái ngoài cùng là 1, còn số chẵn thì là số 0. Khi &1 thì tất cả 7 bit trong đều về 0, còn trạng thái của bit cuối &1 thôi. Nên nếu 1&1 sẽ ra 1=>số chẵn, 		                ngược lại số lẻ.
      ● OR biswise: 0 OR 0 là 0, còn lại là 1.
      ● XOR bitwise: giống nhau thì bằng 0, khác nhau = 1.
      ● Shift Left và Shif Right bitwise: << (dịch trái) , >> (dịch phải).
					 Thường ta sẽ bù bit 0 nhưng khi dịch phải có 1 lưu ý đó là: phải chú ý đến bit cao nhất(bit dấu).
					 Bit dấu: nếu bit max là 1 thì đó là số âm nên khi dịch phải mình bù vào số 1.
					 Còn nếu là số dương (bit dấu = 0) thì khi dịch phải truyền vào số 0.
					      

</details> 

<details>	
	<summary>LESSON 8: Struct - Union </summary>
	
   ## Struct
   	Là kiểu dữ kiệu tự tạo do người dùng tự định nghĩa, kích thước là tổng byte của các kiểu DL
    	Struct Alignment là cách sắp xếp và truy cập dữ liệu trong bộ nhớ, căn chỉnh theo phần tử có kích thước lớn nhất
     	khi tạo một struct sẽ dẫn đến việc sẽ cần phải chèn một số vùng nhớ trống giữa các member để đảm bảo rằng mỗi phần tử được đặt tại địa chỉ phù hợp với kích thước,việc chèn thêm các vùng nhớ trống này được gọi là 	padding
      	VD: 
             struct{struct example_struct
		{
		  uint8_t  member1;
		  uint32_t member2;
		} ExampleStruct_t;
		
		int main(void) 
		{
		  printf("Size of example struct: %lu bytes\n", sizeof(ExampleStruct_t));
		  
		  return 0;
		}

    	Theo lý thuyết thì size của một biến thuộc kiểu struct trên phải bằng tổng của các member của nó, tức là 4 + 1 = 5 bytes. Nhưng khi chạy thử chương trình, kích thước của struct là 8 bytes
     	Khi tạo một struct sẽ dẫn đến việc sẽ cần phải chèn một số vùng nhớ trống giữa các member để đảm bảo việc dữ liệu trong struct được natually aligned. Việc chèn thêm các vùng nhớ trống này được gọi là padding

  ## Union
  	Là kiểu dữ liệu tự tạo do người dùng tự định nghĩa, dùng chung vùng nhớ có kích thước với thành phần lớn nhất
	kích thước của union sẽ được căn chỉnh theo phần tử có kích thước lớn nhất
      
 ## Dùng kết hợp Union && Struct
 	● Dùng để chia nhỏ dữ liệu ra để dễ xử lý hơn
  		typedef union
		      {
		          struct 
		          {
		              uint8_t ID[2];
		              uint8_t data[4];
		              uint8_t PRB[2];     //  Struct data này có chiều dài là 8 byte
		          }data;
		          uint8_t frame[8];       // biến này chiếm 1 byte
		      } DT_frame;                 => Union này lấy 8 byte cùng nhớ
	 	 
   	
</details>


<details>
	<summary>LESSON 9: Json in C </summary>
 		● JSON được thiết kế để dễ đọc và dễ viết cho con người, cũng như dễ dàng để phân tích và tạo ra cho máy tính. Nó sử dụng một cú pháp nhẹ dựa trên cặp key - value, tương tự như các đối tượng và mảng 				trong javascript. Mỗi đối tượng JSON bao gồm một tập hợp các cặp "key" và "value", trong khi mỗi mảng JSON là một tập hợp các giá trị.
   		● Định dạng: luôn bắt đầu bằng dấu "........." Một object luôn nằm trong dấu {........} "<key (luôn là kiểu String)>" : " value "
			VD:
		              char *json = "
		              {
		                "name" : "Nguyen",
		                "age" : 23,
		                "City" : "BinnDinh",
		                "Job"  : "Embedded"
		                "SLR"  : [20, 30, 50]
		              } "
			
		● Các kiểu của JSON typedef enum { JS_NULL, JS_Boolean, JS_Number, JS_String, JS_Array, JS_Ọpect } JS_type;
</details>

<details>
	<summary>LESSON 10: Linked List </summary>
		Việc xóa hay chèn phần tử vào vị trí bất kỳ rất phức tạp khi chúng ta phải, giả sử muốn xóa 1 phần tử bất kỳ 
		Cho giá trị đó là null xong sẽ tăng giá trị hiện tại lên, giá trị phần tử cuối cùng reallocate để chuỗi còn (n-1) phần tử
		Nếu như mảng có 1000, 10000 100000 phần tử khi muốn xóa ở vị trí bất kỳ phải dịch chuyển 999,9999,99999 vòng lặp
		Cho nên Linked List đã ra đời để giải quyết vấn đề đó
	
	● Linked List là một cấu trúc dữ liệu trong lập trình máy tính dùng để tổ chức và lưu trữ dữ liệu. Một linked list bao gồm một chuỗi các nút (node), mỗi nút chứa một giá trị dữ liệu hoặc một con trỏ(pointer) tới 	  nút tiếp theo trong chuỗi. Note cuối thì con trỏ NULL
 

	  Muốn thêm một node vào cuối một mảng thì mình tạo ra một note trước, giá trị của con trỏ là null, sau đó mình lưu địa chỉ của nó vào pointer của note trước nó

   	  Ví dụ: thêm node vào vị trí thứ 2 của mảng: ta chỉ cần thay đổi pointer của nút cần thêm vào là dịa chỉ của phần từ tiếp theo , và thay đổi pointer của nút trước đó thành địa chỉ của nút mình muốn thêm vào

      	  Muốn xóa một phần tử tại vị trí bất kì ta chỉ cần gì note của phần tử đó vào node của phần tử đứng trước đó (tương đương với ghi địa chỉ của phần tử tiếp theo vào vị trí của phần tử đứng trước đó vì note của 	  phần tử đó lưu địa chỉ của phần tử đứng sau)
 	
</details>

<details>
	<summary>LESSON 11: Stack and Queue </summary>

## Stack
 	● Là một cấu trúc dữ liệu được xếp theo nguyên tắc LIFO (Last in Firt out), nghĩa là phần từ đầu tiên được đưa vào thì sẽ được lấy ra sau cùng và phần tử được đưa vào cuối cùng sẽ được lấy ra đầu tiên
  	● Thao tác trên Stack: - Push - Pop - Top
   		PUSH : Đưa phần tử vào
		POP : Lấy phần tử trên cùng ra
		TOP : Lấy giá trị trên cùng

  		VD:
                          typedef struct Stack {      // Khởi tạo struct chứa các kiểu dữ liệu của stack
                              int* items;
                              int size;
                              int top;
                          } Stack;
                          
                          void initialize( Stack *stack, int size) {                // khởi tạo stack và size của nó
                              stack->items = (int*) malloc(sizeof(int) * size);     // cấp phát ô nhớ cho mảng stack có size ổ nhớ của phân từ và mỗi ô nhớ của phần tử đó kích thước kiểu int
                                                                                      // Vd size = 5 thì mảng stack đó có 5 phần tử và mỗi phần tử có kích thước 4byte kiểu int. size của mảng sẽ là 20 byte
                                                                                      // kích thước mảng= kích thước của mỗi phần tử X số lượng phần tử    
                              stack->size = size;  
                              stack->top = -1;
                          }
                          
                          int is_empty( Stack stack) {
                              return stack.top == -1;
                          }
                          
                          int is_full( Stack stack) {
                              return stack.top == stack.size - 1;          // Kiểm tra vị trí hiện tại có bằng với size đó ko. VD: stach.top = 4, stack.size-1 = 5 - 1 2 cái bằng nhau thì trả về 1.
                          }
                          
                          void push( Stack *stack, int value) {
                              if (!is_full(*stack)) {                      // kiểm tra xem stack đó đã max phần tử hay chưa
                                  stack->items[++stack->top] = value;
                              } else {
                                  printf("Stack overflow\n");
                              }
                          }
                          
                          int pop( Stack *stack) {
                              if (!is_empty(*stack)) {
                                  return stack->items[stack->top--];       // trả về giá trị item và top - 1 VD: top = 3,   stack->top-- = 3-1 = 2,  return imtems[2].
                              } else {
                                  printf("Stack underflow\n");
                                  return -1;
                              }
                          }
                          
                          int top( Stack stack) {
                              if (!is_empty(stack)) {
                                  return stack.items[stack.top];
                              } else {
                                  printf("Stack is empty\n");
                                  return -1;
                              }
                          }
                          
                          int main() {
                              Stack stack1;
                              initialize(&stack1, 5);
                          
                          
                              push(&stack1, 10);
                              push(&stack1, 20);
                              push(&stack1, 30);
                              push(&stack1, 40);
                              push(&stack1, 50);
                              push(&stack1, 60);
                          
                              printf("Top element: %d\n", top(stack1));
                          
                              printf("Pop element: %d\n", pop(&stack1));
                              printf("Pop element: %d\n", pop(&stack1));
                          
                              printf("Top element: %d\n", top(stack1));
                          
                              return 0;
                          }

## Queue
	● Một cấu trúc dữ liệu được xếp theo nguyên tắc FIFO (Fast in Firt out), nghĩa là phần từ đầu tiên được thêm vào sẽ được lấy ra đầu tiên.
 	● "enqueue” (thêm phần tử vào cuối hàng đợi) ( nếu đã full mà enqueue nữa thì sẽ bị Stack overflow )
  	● “dequeue” (lấy phần tử từ đầu hàng đợi). ( nếu ko có phần tử nào trong mảng đó thì khi dequeue thì sẽ báo lỗi )
   	● “front” để lấy giá trị của phần tử đứng đầu hàng đợi.
    
    		VD:

                          typedef struct Queue {
                              int* items;
                              int size;
                              int front, rear;
                          } Queue;
                          
                          void initialize(Queue *queue, int size) 
                          {
                              queue->items = (int*) malloc(sizeof(int)* size);    // cấp phát ô nhớ cho mảng queue có size ổ nhớ của phân từ và mỗi ô nhớ của phần tử đó kích thước kiểu int
                                                                                      // Vd size = 5 thì mảng queue đó có 5 phần tử và mỗi phần tử có kích thước 4byte kiểu int. size của mảng sẽ là 20 byte
                                                                                      // kích thước mảng= kích thước của mỗi phần tử X số lượng phần tử 
                              queue->front = -1;                                  // khởi tạo phần từ
                              queue->rear = -1;                                   // khởi tạo phần từ
                              queue->size = size;                                 // khởi tạo kích thước
                          }
                          
                          int is_empty(Queue queue) {
                              return queue.front == -1;
                          }
                          
                          int is_full(Queue queue) {
                              return (queue.rear + 1) % queue.size == queue.front;           // (4 + 1) % 5 = 0 => đủ bộ nhớ
                          }
                          
                          void enqueue(Queue *queue, int value) {                            // Thêm phần tử vào
                              if (!is_full(*queue)) {                                        // kiểm tra có bị full hay ko
                                  if (is_empty(*queue)) {                                    // kiểm tra có bị rỗng hay ko
                                      queue->front = queue->rear = 0;                            // nếu rỗng thì gán front và rear = 0 để chỉ tới ô thứ tự đầu tiên trong mảng
                                  } else {
                                      queue->rear = (queue->rear + 1) % queue->size;             // nếu không rỗng thì gán vào rear để chỉ tới ô thứ tự rear trong mảng. VD: (0 + 1) % 5 = 0.1 dư 1 => rear = 1
                                  }                                                                                                                                          (1 + 1) % 5 = 0.2 dư 2 => rear = 2
                                  queue->items[queue->rear] = value;                         // gán giá trị vào ô thứ tự rear đó. VD: rear =0 thì items[0] = 4.
                              } else {                                                                                                            items[1] = 5.
                                  printf("Queue overflow\n");
                              }
                          }
                          
                          int dequeue(Queue *queue) {
                              if (!is_empty(*queue)) {
                                  int dequeued_value = queue->items[queue->front];
                                  if (queue->front == queue->rear) {
                                      queue->front = queue->rear = -1;
                                  } else {
                                      queue->front = (queue->front + 1) % queue->size;
                                  }
                                  return dequeued_value;
                              } else {
                                  printf("Queue underflow\n");
                                  return -1;
                              }
                          }
                          
                          int front(Queue queue) {
                              if (!is_empty(queue)) {
                                  return queue.items[queue.front];
                              } else {
                                  printf("Queue is empty\n");
                                  return -1;
                              }
                          }
                          
                          int main() {
                              Queue queue;
                              initialize(&queue, 3);
                          
                              enqueue(&queue, 10);
                              enqueue(&queue, 20);
                              enqueue(&queue, 30);}
	 
</details>


#### ADVANCED C++     
 <details>  
	<summary>LESSON 1: Class </summary>
 		● Class là 1 lớp hoặc là một cấu trúc dữ liệu tự định nghĩa có thể chứa dữ liệu và các hàm thành viên liên quan
   		● Các phạm vi truy cập: public, protected, private
     		● Có các: thuộc tính (property), method, phương thức khởi tạo (constructor), hàm hủy (destructor)
       		● Constructor là một method sẽ được tự động gọi khi khởi tạo object,Constructor sẽ có tên trùng với tên của class
	 	● Destructor là một method sẽ được tự động gọi khi object được giải phóng (ở trong phân vùng stack)
   		● Khi obj được khởi tạo, constructor sẽ được gọi, hiển thị "Constructor called"
     		● Khi chương trình kết thúc hoặc obj ra khỏi phạm vi, destructor sẽ tự động được gọi, hiển thị "Destructor called"
	 
       	Static trong class:
		Nếu như một property được khai báo với từ khóa static thì các object trong class sẽ dùng chung địa chỉ với property này
	Static sử dụng trong class: là biến dùng chung, một property trong class được khai báo với từ khóa static, thì tất cả các object sẽ dùng chung địa chỉ của property này.
		Khi một method trong class được khai báo với từ khóa static: Method này độc lập với bất kỳ đối tượng nào của lớp. Method này có thể được gọi ngay cả khi không có đối tượng nào của class tồn tại. Method 		này có thể được truy cập bằng cách sử dụng tên class thông qua toán tử :: . Method này có thể truy cập các static property và các static method bên trong hoặc bên ngoài class. Method có phạm vi bên trong 		class và không thể truy cập con trỏ đối tượng hiện tại.
 </details>

<details>
	<summary>LESSON 2: OOP </summary>

 ## Encapsulation
 	Encapsulation (tính đóng gói), các property sẽ bị ẩn đi bằng cách khai báo nó ở phân vùng private, không thể truy cập trực tiếp với các property này
	Để truy cập được vào các property này thì phải thông qua các method như getter hoặc setter ở phân vùng public
		class Student
               {
                   private:
                       string Name;
                       double GPA;
                       int StudentID;
                   public:
                   Student(string name);
               
                   string getName()
                   {
                       return Name;
                   }
               
                   void setGPA(double gpa)
                   {
                       GPA = gpa;
                   }
                   double getGPA()
                   {
                       return GPA;
                   }
               
                   int getID()
                   {
                       return StudentID;
                   }               
               };

## Inheritance
	Tính kế thừa, class con sẽ được kế thừa các property và method của class cha, dùng toán tử : và có tính tái sử dụng
 	Có 3 kiểu kế thừa ( private, protected, public)
  		class Person
            {
            protected:
              string Name;
              int Age;
              string Home_Address;
            
            public:
              string getName()
              {
                return Name;
              }
              void setName(string name)
              {
                Name = name;
              }
            
              int getAge()
              {
                return Age;
              }
              void setAge(int age)
              {
                Age = age;
              }
            
              string getAddress()
              {
                return Home_Address;
              }
              void setAddress(string address)
              {
                Home_Address = address;
              }
            
              void displayInfo()
              {
                cout << "Name: " << Name << endl;
                cout << "Age: " << Age << endl;
                cout << "Address: " << Home_Address << endl;
              }};
            
            class Student : public Person
            {
            private:
              string School_Name;
              double GPA;
              int StudentID;
            
            public:
              Student()
              {
                static int id = 1000;
                StudentID = id;
                id++;
              }
            
              string getSchoolName()
              {
                return School_Name;
              }
              void setSchoolName(string school_name)
              {
                School_Name = school_name;
              }
            
              double getGPA()
              {
                return GPA;
              }
              void setGPA(double gpa)
              {
                GPA = gpa;
              }
            
              int getID()
              {
                return StudentID;
              }
            
              void displayInfo() // overriding
              {
                cout << "Name: " << Name << endl;
                cout << "Age: " << Age << endl;
                cout << "Address: " << Home_Address << endl;
                cout << "School name: " << School_Name << endl;
                cout << "GPA: " << GPA << endl;
              }
            };

## Polymorphism
	Tính đa hình có 2 loại là Đa hình tĩnh(Compiler): function overloading và operator overloading và Đa hình động(runtime) : function overriding 
 	● Đa hình tĩnh
  		Đa hình tĩnh không thực hiện được tính đa hình thông qua kế thừa,một hàm có thể có nhiều định nghĩa với cùng tên, nhưng có khác biệt về số lượng hoặc kiểu tham số. Trình biên dịch sẽ chọn đúng hàm dựa 		trên cách bạn gọi hàm đó 
			`			void display(int a) {
							cout << "Integer: " << a << endl;
						}

						void display(double b) {
							cout << "Double: " << b << endl;
						}

						void display(int a, int b) {
							cout << "Sum: " << a + b << endl;
						}

						int main() {
							display(5);        // Gọi hàm display(int)
							display(3.14);     // Gọi hàm display(double)
							display(3, 7);     // Gọi hàm display(int, int)
	● Đa hình động:
 		Thực hiện đa hình thông qua kế thừa (overriding, ví dụ: có 1 class con kế thừa từ class cha, class cha có 1 hàm sum rồi, class con cũng có thể định nghĩa lại 1 hàm sum khác 1 lần nữa) => Tính đa hình chủ 		yếu dùng cho các method, tính kế thừa dùng cho các class
   		Khi các lớp con kế thừa lại từ lớp cha, các phương thức lớp con trùng tên với các phương thức lớp cha
     		Từ khóa virtual là từ khóa giúp cho lớp con ghi đề được lên lớp cha khi kế thừa
       		VD:
		   class Person
		   {
		   protected:
		     string Name;
		     int Age;
		     string Home_Address;
		   
		   public:
		     virtual string test()
		     {
		       return "Hello person";
		     }
		   
		     void displayInfo()
		     {
		       cout << test() << endl;
		     }  
		   };
		   
		   class Student : public Person
		   {
		   private:
		     string School_Name;
		     double GPA;
		     int StudentID;
		   
		   public:
		     string test()
		     {
		       return "Hello student";
		     }
		   };
     
## Abstract
	Abstract (tính trừ tượng) là việc ẩn đi các chi tiết cụ thể của một đối tượng và chỉ hiển thị những gì cần thiết để sử dụng đối tượng đó
        VD:

       {
          private:
              double a;
              double b;
              double c;
              double x1;
              double x2;
              double delta;
              void tinhNghiem()    // ẩn đi hàm tính ko cho người dùng thấy
              {
                  delta = b*b - 4*a*c;
                  if (delta < 0)
                  {
                      delta = -1;
                  }
                  else if (delta == 0)
                  {
                      x1 = x2 = -b/ (2*a);
                  }
                  else if (delta > 0)
                  {
                      x1 = (-b + sqrt(delta))/(2*a);
                      x2 = (-b - sqrt(delta))/(2*a);
                  }
              }
              
          public:
      
              void enterNumber(double num_a, double num_b, double num_c);
              void printResult();
      
      };
      
      void GiaiPhuongTrinh::enterNumber(double num_a, double num_b, double num_c)
      {
          a = num_a;
          b = num_b;
          c = num_c;
      }
      
      void GiaiPhuongTrinh::printResult()
      {
          tinhNghiem();
          if (delta == -1)
          {
              cout << "PT vo nghiem" << endl;
          }
          else if (delta == 0)
          {
              cout << "PT co nghiem chung: " << x1 << endl;
          }
          else if (delta > 0)
          {
              cout << "PT co 2 nghiem: \n";
              cout << "x1: " << x1 << endl;
              cout << "x2: " << x2 << endl;
          }
          
          
      }
      
      
      int main()
      {
        GiaiPhuongTrinh phuongtrinh1;
        phuongtrinh1.enterNumber(1,5,4);
        phuongtrinh1.printResult();
      
        return 0;
      }

</details>
    
<details>  
	<summary>LESSON 3: Standard template library C </summary>     
 	 STL - Standard Template Library là một thư viện trong ngôn ngữ lập trình C++ cung cấp một số tập hợp các template classes và function để thực hiện các cấu trúc dữ liệu và một số thuật toán phổ biến. Một 		 số thành phần chính của STL:
		Container
		Iterator
		Algorithms
		Funtors
		Container là một cấu trúc dữ liệu chứa nhiều phần tử theo một cách cụ thể . Một số container tiêu biểu:
		
		Vector
		Map
		List
		Array
		Vector là một trong những container quan trọng nhất của C++. Nó cấp một mảng động với khả năng thay đổi kích thước một cách linh hoạt.	
## Iterator: 
	Trong C++, iterator là một khái niệm giúp truy cập các phần tử của một container,
	một cách tuần tự mà không cần phải biết cấu trúc nội bộ của container. Nó đóng vai trò như một con trỏ, nhưng mạnh mẽ và an toàn hơn.
	Iterator giúp dễ dàng duyệt qua và thao tác với các phần tử trong container một cách linh hoạt
 
 </details>

 <details>   
	<summary>LESSON 4: Template </summary>
		Có 2 loại template là template function và template class, được sử dụng khi chúng ta có nhiều function, class giống nhau nhưng khác kiểu dữ liệu, tính đa hình theo kiểu compiler
		template <typename T>
			T myFunction(T a, T b) {
				return a + b;
			}
			int result1 = myFunction(5, 10);       // Tự động suy luận T là int
			double result2 = myFunction(3.14, 2.71);  // Tự động suy luận T là double
 </details> 

 <details>
       <summary>LESSON 5: Smart Pointer </summary>
       		Là một cơ chế quản lý bộ nhớ tự động, Tự động giải phóng tài nguyên khi không còn sử dụng
		Sử dụng đặc tính destructor trong class để tự động giải phóng khi không xài nữa
	 
		Có 3 loại: unique pointer, shared pointer, weak pointer
		● unique pointer: 
			1 con trỏ chỉ đc trỏ tới 1 đối tượng. VD: 
							unique_ptr<int> p1(new int(100));
							unique_ptr<int> p2 = p1  Sai

			Khi có 2 unique_ptr quản lý 1 tài nguyên thì sẽ vi phạm nguyên tắc. Để chuyển tài nguyên của 1 unique_ptr này sang unique_ ptr khác ta dùng lệnh move()

   		● shared pointer: 
     			có thể chia sẻ tính sở hữu, có thể có nhiều shared ptr trở tới 1 đối tượng tại cùng 1 thời điểm
			khi mà tất cả các shared ptr bị giải phóng thì đối tượng đó mới đc giải phóng
				       #include<iostream>
			               #include<memory>			               
			               using namespace std;
			               
			               class Tinhdientich
			               {
			               private:
			                   int chieudai;
			                   int chieurong;
			               
			               public:
			                   Tinhdientich(int num_cd, int num_cr)
			                   {
			                       chieudai = num_cd;
			                       chieurong = num_cr;
			                       cout << "constuct is call" << endl;
			                   }
			                   void dientich()
			                   {
			                       cout << "Dien tich: " << chieudai * chieurong << endl;
			                   }	        
			                   ~Tinhdientich()
			                   {
			                       cout << " Destructer " << endl;
			                   };
			               };
			               
			               int main()
			               {
			                   shared_ptr <Tinhdientich> ptr1(new Tinhdientich(20,10));
			               
			                   (*ptr1).dientich();
			               
			                   cout << ptr1.use_count();
			               
			                   return 0;
			               }
		  ● weak ptr: Chỉ có quyền đọc đối tượng mà được shared ptr trỏ tới , k có quyền truy cập

   ## Lambda: 
	Cho phép  định nghĩa các hàm mà không cần đặt tên.linh hoạt, 
				 có thể được định nghĩa trực tiếp tại nơi sử dụng, thường được dùng trong các ngữ cảnh yêu cầu một hàm ngắn gọn và cục bộ
				 [capture](parameters) -> return_type {
						// function body
					};
					[capture]: Là cách để  bắt biến từ phạm vi bên ngoài lambda, cho phép  sử dụng những biến này bên trong lambda
							[&]: Bắt tất cả biến từ phạm vi ngoài theo kiểu tham chiếu.
							[=]: Bắt tất cả biến từ phạm vi ngoài theo kiểu giá trị.
							[this]: Bắt con trỏ this từ đối tượng hiện tại (thường trong class)

		

</details>

<details>
	<summary>LESSON 6: Design Pattern </summary>
 		Có 4 loại phổ biến là : singleton, obsever, factory và decorator
	   		● Singleton: Một lớp chỉ có 1 đối tượng duy nhất
			      VD: truy cập tới vùng địa chỉ của GPIO thì địa chỉ của GPIO là cố định
			      Nếu  khởi tạo nhiều đối tượng để truy cập GPIO, mỗi đối tượng sẽ chiếm một vùng nhớ khác nhau nhưng đều trỏ tới cùng địa chỉ GPIO, gây lãng phí bộ 
			      singleton khởi tạo 1 lần, những thằng khác chỉ là con trỏ trỏ tới địa chỉ của object, giúp tối ưu bộ nhớ, tránh khởi tạo nhiều object
	 		● Obsever: 1 object thay đổi sẽ thông báo cho các đối tượng
			      VD: Com VĐK đọc giá trị cảm biến nhiệt độ. Vd: cảm biến nhiệt độ thực hiện việc bật quạt, bật máy lạnh, hiển thị lên LCD => làm nhiều việc cùng lúc với dữ liệu đó 
			      Ví dụ, khi cảm biến phát hiện nhiệt độ cao, nó có thể kích hoạt cả việc ghi log và cảnh báo mà không cần làm thêm bước lập trình cho từng hành động
    			● Factory: Khởi tạo 1 object mà lớp con sẽ quyết định loại đối tượng nào
			      VD: Có rất nhiều loại cảm biến, việc mỗi lần khai báo object cho từng loại cảm biến rất khó để quản lý, chỉ cần khởi tạo object sensor
       			● Decorator: Thêm tính năng mới vào object mà không làm thay đổi cấu trúc, kết cấu bên trong của class
			      VD: Cảm biến nhiệt độ có chức năng là đo nhiệt độ, sử dụng decorator để thêm vào những thứ như chuyển đổi sang độ F, lọc nhiễu mà không làm thay đổi tính năng ban đầu
		
</details>

<details>
	<summary>LESSON 6: Thread </summary>
		Process: Là chương trình, khởi tạo và chạy trên ram, bên trong chương trình là những task, khi những task chạy // thì là thread
		Thread:  Nằm trong process, Có 1 hoặc nhiều thread chạy cùng lúc. Mỗi thread chạy 1 công việc khác nhau
		Thread có tham số đầu vào và thread k có tham số đầu vào: thread NAME (NAME_FUNCTION)
				
						void myFunction() {
							std::cout << "Hello from thread!" << std::endl;
						}
						int main() {
							std::thread t1(myFunction); // Tạo một luồng và chạy hàm myFunction
							t1.join(); // Đợi luồng hoàn thành trước khi kết thúc chương trình
							}
							
						Truyền tham số
							void printMessage(const std::string& message) {
								std::cout << "Message: " << message << std::endl;
							}
							int main() {
								std::string message = "Hello from thread!";
								std::thread t1(printMessage, message);
								t1.join();
							
				Phương thức join() được sử dụng để chờ đợi luồng hoàn thành trước khi tiếp tục thực thi chương trình.
				Nếu k có join, Cả hai luồng sẽ chạy song song và cạnh tranh tài nguyên CPU

		Sử dụng Function Object Là một đối tượng có thể được gọi như một hàm, nhờ vào việc overload operator(). Điều này cho phép bạn truyền đối tượng đó như một hàm vào các API yêu cầu hàm Là 1 lớp có toán tử 		operator, Đây là nơi bạn định nghĩa công việc mà bạn muốn thực hiện trong thread.

     VD:        #include<iostream>
                #include<thread>
                
                using namespace std;
                
                class FunOBJ
                {
                private:
                    
                public:
                    void operator() ()
                    {
                        this_thread::sleep_for(chrono::seconds(2)); // giống hàm delay
                        cout << "this is Function object" << endl;
                    }
                };
                
                void task_1()
                {
                    this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                    cout << "this is Function task_1" << endl;
                }
                
                int main()
                {
                    FunOBJ myFunction;
                    
                    myFunction();
                
                    thread thread_OBJ(myFunction);
                    thread thread_1(task_1);
                
                    thread_OBJ.join();
                    thread_1.join();
                
                    return 0;
                }
		● Sử dụng Function Pointer
		
		  VD:     #include<iostream>
		          #include<thread>
		          using namespace std;
		          void task_1()
		          {
		              //do something
		          }
		          int main()
		          {
		              thread thread_1(task_1);       // Khởi tạo 1 thread có tên là thread_1 và thread này có nhiệm vụ thực thi hàm task_1
		              thread_1.join();               // câu lệnh này để thread_1 thực thi hàm task_1 để tránh lỗi bỏ qua lệnh.
		              return 0;
		          }
		● Sử dụng Lambda Function
		
		   VD:
		     auto fun = [] (int x)
		     {
		         while(x-- > 0)
		         {
		             std::cout << x << std::endl;
		         }
		     };
		     std::thread t1(fun, 10);
		     t1.join();
		● Sử dụng Non_static function
		
		  VD:
		        class Base
		         {
		         public:
		             void non_func(int x)
		             {
		                 while(x-- > 0)
		                 {
		                     std::cout << x << std::endl;
		                 }
		             }
		         };
		         int main()
		         {
		             Base b1;
		             std::thread t1(&Base::non_func, &b1, 10);
		             t1.join();
		         
		             return 0;
		         }
		● Sử dụng Static Function
		
		  VD:
		     class Base
		      {
		      public:
		          static void non_func(int x)
		          {
		              while(x-- > 0)
		              {
		                  std::cout << x << std::endl;
		              }
		          }
		      };
		      
		      int main()
		      {
		          Base b1;
		          std::thread t1(&Base::non_func, 10);
		          t1.join();
		      }
  
    		Mutex: Đảm bảo rằng chỉ có một luồng truy cập vào tài nguyên chia sẻ tại 1 thời điểm
					   Với thao tác lock: khóa" mutex lại, và tất cả các luồng khác không thể truy cập tài nguyên được bảo vệ bởi mutex cho đến khi mutex được "mở khóa"
							unlock: Khi công việc của luồng đang giữ mutex hoàn thành, nó gọi unlock() để mở khóa mutex, cho phép các luồng khác tiếp tục truy cập vào tài nguyên
					   Nếu một luồng đã khóa mutex, các luồng khác muốn sử dụng tài nguyên phải chờ cho đến khi mutex được mở khóa
					   đảm bảo rằng chỉ có một luồng duy nhất có thể truy cập tài nguyên tại bất kỳ thời điểm nào, tránh việc tranh chấp tài nguyên và các vấn đề về dữ liệu
	
## Các vấn đề thường gặp trong đa luồng:

Data Race: đồng bộ hóa dữ liệu.

 VD: Phần mềm vscode bản chất là 1 tiến trình và terminal là 1 tài nguyên, thì tất các các luồng đều truy cập đến tài nguyên chung.

     Mà đối với các tài nguyên sử dụng chung, trong 1 thời điểm chỉ cho phép 1 luồng truy cập vào nó.

     + TH1: Nếu ko sử dụng mutex thì cả 3 luồng sẽ truy cập đến tài nguyên chung sẽ gây ra lỗi đầu ra dữ liệu ko mong muốn.

     + TH2: Nếu sử dụng mutex thì mutex giúp 1 trong 3 luồng truy cập đến tài nguyên chung. (task_1 truy cập đến tài nguyên chung thì task_2 và task_3 ko đc truy cập đến và ngược lại).

            Cách ct thực hiện:  task_1 tới hàm mutex_cout.lock() thì ko khóa thì khóa lại, rồi thực thi lệnh tiếp theo in ra .... và nhảy tới hàm task_2
                                task_2 tới hàm mutex_cout.lock() kiểm tra thì đã khóa ở trên và đứng chờ và nhảy tới hàm task_3
                                tash_3 tới hàm mutex_cout.lock() kiểm tra thì đã khóa ở trên và đứng chờ và nhảy trở về lại hàm task_1

                                task_1 tới hàm mutex_cout.unlock() và mở khóa ra và nhảy tới hàm task_2.
                                task_2 tới hàm mutex_cout.lock() kiểm tra thì đã mở khóa ở trên thì khóa lại, rồi thực thi lệnh tiếp theo in ra .... và nhảy tới hàm task_3
                                tash_3 tới hàm mutex_cout.lock() kiểm tra thì đã khóa ở trên và đứng chờ và nhảy trở về lại hàm task_1

                                task_1 tới hàm mutex_cout.lock() và kiểm tra thấy đã khóa ở trên và đứng chờ và nhảy tới hàm task_2.
                                task_2 tới hàm mutex_cout.unlock() và mở khóa ra và nhảy tới hàm task_3.
                                tash_3 tới hàm mutex_cout.lock() kiểm tra thì đã mở khóa ở trên thì khóa lại, rồi thực thi lệnh tiếp theo in ra .... và nhảy tới hàm task_1

                                task_1 tới hàm mutex_cout.lock() và kiểm tra thấy đã khóa ở trên và đứng chờ và nhảy tới hàm task_2.
                                task_2 tới hàm mutex_cout.lock() kiểm tra thì đã khóa ở trên và đứng chờ và nhảy tới hàm task_3
                                tash_3 tới hàm mutex_cout.unlock() và mở khóa ra và nhảy tới hàm task_1.
                                 

                         #include<thread>
                         #include<mutex>
                         using namespace std;
                         mutex mutex_cout;
                         void task_1()
                         {
                             this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                             mutex_cout.lock();                              // Nếu luồng truy cập đến mà lock này đã khóa thì chờ ở dòng này, còn ko thì khóa lại và thực thi tiếp dòng tiếp theo.
                             cout << "this is Function task_1" << endl;
                             mutex_cout.unlock();                            // Mở khóa
                         }
                         
                         void task_2()
                         {
                             this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                             mutex_cout.lock();
                             cout << "this is Function task_2" << endl;
                             mutex_cout.unlock();
                         }
                         
                         void task_3()
                         {
                             this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                             mutex_cout.lock();
                             cout << "this is Function task_3" << endl;
                             mutex_cout.unlock();
                         }
                         
                         int main()
                         {
                             while (1)
                             {
                                 thread thread_1(task_1);
                                 thread thread_2(task_2);
                                 thread thread_3(task_3);
                         
                                 thread_1.join();
                                 thread_2.join();
                                 thread_3.join();
                             }
                             return 0;
                         }
DeadLock:

      -Khi ta đặt nhiều khóa trong luồng và ta đặt thứ tự khóa chéo nhau trong các luồng thì sẽ xảy ra hiện tượng deadLock.
    
                    VD:     mutex mutex_cout, mutex2;
                            void task_1()
                            {
                                this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                                mutex_cout.lock();                              // Bước 1
                                mutex2.lock();                                  // Bước 4
                                cout << "this is Function task_1" << endl;
                                mutex_cout.unlock();
                            }
                            
                            void task_2()
                            {
                                this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                                mutex2.lock();                                  // Bước 2
                                mutex_cout.lock();                              // Bước 3
                                cout << "this is Function task_2" << endl;

      - CT sẽ bị deadlock vì task_1 sẽ bị đứng chờ ở lệnh mutex2.lock() và task_2 bị đứng ở lệnh mutex_cout.lock()

     => Vậy nên phải đặt đúng thứ tự các khóa lại với nhau.

                           VD:     mutex mutex_cout, mutex2;
                            void task_1()
                            {
                                this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                                mutex_cout.lock();                              // Bước 1
                                mutex2.lock();                                  // Bước 4
                                cout << "this is Function task_1" << endl;
                                mutex_cout.unlock();
                            }
                            
                            void task_2()
                            {
                                this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                                mutex_cout.lock();                              // Bước 3
                                mutex2.lock();                                  // Bước 2
                                cout << "this is Function task_2" << endl;
				
Race Condition:

Là điều kiện thực thi luồng, kiểu như là ta muốn luồng nào đc thực thi trước luồng nào thực thi tiếp theo.

                      VD:    #include<condition_variable>
                             mutex mutex_cout, mutex2;
                             
                             condition_variable make_cake;
                             bool Ready = false;
                             
                             void task_1()
                             {
                                 this_thread::sleep_for(chrono::seconds(2));     // giống hàm delay
                             
                                 lock_guard<mutex> lock(mutex_cout);           // giống smart poiter và chức năng giống như lock() nếu khóa thì đứng chờ, chưa khóa thì khóa và thực hiện lệnh tiếp theo
                                 Ready = true;
                                 cout << "Function task_1 is done" << endl;
                                 make_cake.notify_one();                        // tự mở khi thực hiện xong hàm, báo cho luồng khác là đã xong.
                             }
                             void task_2()
                             {
                                 unique_lock<mutex>  lock(mutex2);
                                 make_cake.wait(lock, [] {return Ready; });      //chờ khi có luồng khác báo đã thực thi xong và thực thi hàm của mình đi. 
                                 Ready = false;
                                 cout << "this is Function task_2" << endl;
                             }
			Ví dụ trên thực thi xong luồng task_1 thì luồng task_2 mới được thực thi

   ## Sử dụng lock khi trong thread nhiều thằng cùng truy cập để lấy dữ liệu, sử dụng khi nhiều thằng cùng vào gây xung đột, tranh chấp tài nguyên
   	Các loại lock: 
    		Lock guard: Sẽ tự động mở khóa khi đối tượng ra khỏi phạm vi trong 1 khối lệnh, 1 hàm.  std::lock_guard<std::mutex> guard(mtx);
      		unique lock: Có thê unlock lúc nào cũng được, nó có thể mở khóa tạm thời lại và khóa lại khi cần thiết 
									std::unique_lock<std::mutex> lock(mtx);
									lock.unlock();
									lock.unlock();
							 linh hoạt trong việc chuyển đổi quyền sở hữu 
									std::unique_lock<std::mutex> lock1(mtx);
									std::unique_lock<std::mutex> lock2(std::move(lock1));


  		● Luồng có 2 loại: (đồng bộ và bất dồng bộ)
    			Đồng bộ là luồng hoạt động bình thường, sử dụng các tài nguyên chung truy cập cùng nhau cùng 1 thời điểm. Làm việc chung với nhau
       			Bất đồng bộ là luồng hoạt động không cần chờ đợi kết quả trước khi tiếp tục thực hiện luồng khác. Các luồng làm việc độc lập và ko phụ thuộc vào nhau
	  			Bất động bộ gồm future và shared future:
					future: 1 funtion thì chỉ có future, chỉ có thể get(lấy giá trị) một lần. Sau khi get để lấy kết quả từ future, trạng thái của future sẽ bị xóa và không thể lấy lại kết quả từ nó
					shared future: Cho phép nhiều đối tượng get( lấy giá trị, kết quả), có nhiều shared future khác trong cái luồng đó, get giá trị về thì luồng k bị mất đi	
     
</details>


            
