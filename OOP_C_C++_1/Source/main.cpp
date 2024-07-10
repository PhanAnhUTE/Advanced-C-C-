#include <iostream>
#include <list>


#include "Constructor.hpp"
#include "add_student.hpp"
#include "delete_student.hpp"
#include "edit_student.hpp"
#include "save_student.hpp"
#include "search_student.hpp"
#include "printf_student.hpp"


using namespace std;



void displayMainMenu() {
    cout << "=== CHUONG TRINH QUAN LY SINH VIEN ===" << endl;
    cout << "1. Them sinh vien" << endl;
    cout << "2. In danh sach sinh vien" << endl;
    cout << "3. Luu danh sach sinh vien vao file CSV" << endl;
    cout << "4. Chinh sua thong tin sinh vien" << endl;
    cout << "5. Xoa sinh vien" << endl;
    cout << "6. Tim kiem sinh vien" << endl;
    cout << "7. Sap xep sinh vien" << endl;
    cout << "0. Thoat chuong trinh" << endl;
    cout << "=====================================" << endl;
    cout << "Vui long chon chuc nang: ";
}


int main() {
    std::list<Student> students; 
    int choice;
    do {
        displayMainMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                printStudentTable(students);
                break;
            case 3:
                saveAllStudentsToFile(students, "database_sv.csv");
                cout << "Da luu danh sach sinh vien vao file database_sv.csv." << endl;
                break;
            case 4:
                editStudentInfo(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                searchStudent(students);
                break;
            case 7: {
                int sortChoice;
                do {
                    cout << "=== Sap xep sinh vien ===" << endl;
                    cout << "1. Sap xep theo ten" << endl;
                    cout << "2. Sap xep theo diem toan" << endl;
                    cout << "3. Sap xep theo diem ly" << endl;
                    cout << "4. Sap xep theo diem hoa" << endl;
                    cout << "5. Sap xep theo diem trung binh" << endl;
                    cout << "0. Quay lai" << endl;
                    cout << "Vui long chon chuc nang: ";
                    cin >> sortChoice;

                    switch (sortChoice) {
                        case 1:
                            sortStudentsByName(students);
                            printStudentTable(students);
                            break;
                        case 2:
                            sortStudentsByMathScore(students);
                            printStudentTableMath(students);
                            break;
                        case 3:
                            sortStudentsByPhysicsScore(students);
                            printStudentTablePhysics(students);
                            break;
                        case 4:
                            sortStudentsByChemistryScore(students);
                            printStudentTableChemistry(students);
                            break;
                        case 5:
                            sortStudentsByAverageScore(students);
                            printStudentTable(students);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                            break;
                    }
                } while (sortChoice != 0);
                break;
            }
            case 0:
                cout << "Cam on ban da su dung chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
