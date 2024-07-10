#ifndef PRINTF_STUDENT_HPP
#define PRINTF_STUDENT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
#include <vector>

#include "Constructor.hpp"





void printAllStudents(const std::list<Student>& students) {
    int choice;
    do {
        if (students.empty()) {
            std::cout << "Danh sach sinh vien hien tai rong." << std::endl;
        } else {
            std::cout << "\nDanh sach sinh vien\n\n";
            std::cout << "STT  |      ID        |      Ten       | GioiTinh | Toan | Ly | Hoa | DiemTrungBinh | Xep loai\n";
            std::cout << "-----------------------------------------------------------------------------------------------------\n";
            
            int stt = 1;
            for (const auto& student : students) {
                std::cout << stt << "    | " << student.getId() << "         | " << student.getName() << "       |    " 
                          << student.getGender() << "   | " << student.getMathScore() << "   | " 
                          << student.getPhysicsScore() << "  |   " << student.getChemistryScore() << " |    "
                          << student.calculateAverageScore() << "          |   " << student.determineGrade() << "      \n";
                stt++;
            }
        }

        std::cout << "\n";
        std::cout << "0. Quay lai\n";
        std::cout << "Vui long chon chuc nang: ";
        std::cin >> choice;

        if (choice == 0) {
            return; // Quay lai menu chinh
        }
    } while (true);
}

void Student::printStudentDetails() const {
    std::cout << "---------------------" << std::endl;
    std::cout << "ID:\t" << id << std::endl;
    std::cout << "Ten:\t" << name << std::endl;
    std::cout << "Tuoi:\t" << age << std::endl;
    std::cout << "Gioi tinh:\t" << gender << std::endl;
    std::cout << "Toan: " << mathScore << std::endl;
    std::cout << "Ly: " << physicsScore << std::endl;
    std::cout << "Hoa: " << chemistryScore << std::endl;
    std::cout << "Diem trung binh:\t" << calculateAverageScore() << std::endl;
    std::cout << "Loai:\t" << determineGrade() << std::endl;
}


void printStudentTable(const std::list<Student>& students) {
    // In ra bảng danh sách sinh viên
    std::cout << "Danh sach sinh vien:" << std::endl;
    std::cout << "=====================================================================================================" << std::endl;
    std::cout << "STT\t| ID\t\t| Ten\t\t| GioiTinh\t| DiemTrungBinh\t| Xep loai" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
    
    int stt = 1;
    for (const auto& student : students) {
        std::cout << stt++ << "\t| " << student.getId() << "\t\t| " << student.getName() << "\t\t| " << student.getGender() << "\t\t| ";
        std::cout << student.calculateAverageScore() << "\t\t| " << student.determineGrade() << std::endl;
    }
    std::cout << "=====================================================================================================" << std::endl;
}



void printStudentTableMath(const std::list<Student>& students) {
    // In ra bảng danh sách sinh viên
    std::cout << "Danh sach sinh vien:" << std::endl;
    std::cout << "=====================================================================================================" << std::endl;
    std::cout << "STT\t| ID\t\t| Ten\t\t| GioiTinh\t| DiemToan\t| Xep loai" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
    
    int stt = 1;
    for (const auto& student : students) {
        std::cout << stt++ << "\t| " << student.getId() << "\t\t| " << student.getName() << "\t\t| " << student.getGender() << "\t\t| ";
        std::cout << student.getMathScore() << "\t\t| " << student.determineGrade() << std::endl;
    }
    std::cout << "=====================================================================================================" << std::endl;
}

    void printStudentTablePhysics(const std::list<Student>& students) {
    // In ra bảng danh sách sinh viên
    std::cout << "Danh sach sinh vien:" << std::endl;
    std::cout << "=====================================================================================================" << std::endl;
    std::cout << "STT\t| ID\t\t| Ten\t\t| GioiTinh\t| DiemLy\t| Xep loai" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
    
    int stt = 1;
    for (const auto& student : students) {
        std::cout << stt++ << "\t| " << student.getId() << "\t\t| " << student.getName() << "\t\t| " << student.getGender() << "\t\t| ";
        std::cout << student.getPhysicsScore() << "\t\t| " << student.determineGrade() << std::endl;
    }
    std::cout << "=====================================================================================================" << std::endl;
}



    void printStudentTableChemistry(const std::list<Student>& students) {
    // In ra bảng danh sách sinh viên
    std::cout << "Danh sach sinh vien:" << std::endl;
    std::cout << "=====================================================================================================" << std::endl;
    std::cout << "STT\t| ID\t\t| Ten\t\t| GioiTinh\t| DiemHoa\t| Xep loai" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
    
    int stt = 1;
    for (const auto& student : students) {
        std::cout << stt++ << "\t| " << student.getId() << "\t\t| " << student.getName() << "\t\t| " << student.getGender() << "\t\t| ";
        std::cout << student.getChemistryScore() << "\t\t| " << student.determineGrade() << std::endl;
    }
    std::cout << "=====================================================================================================" << std::endl;
}



#endif // PRINTF_STUDENT_HPP
