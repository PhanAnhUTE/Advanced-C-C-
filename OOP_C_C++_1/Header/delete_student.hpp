#ifndef DELETE_STUDENT_HPP
#define DELETE_STUDENT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
#include <vector>


#include "Constructor.hpp"
#include "save_student.hpp"
#include "printf_student.hpp"



void deleteStudent(std::list<Student>& students) {
    int choice;
    do {
        std::string name;
        std::cout << "Nhap ten sinh vien can xoa: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::vector<Student> results;
        for (const auto& student : students) {
            if (student.getName() == name) {
                results.push_back(student);
            }
        }

        if (!results.empty()) {
            std::cout << "\nKet qua tim kiem:\n";
            for (const auto& student : results) {
                student.printStudentDetails();
            }

            int id;
            std::cout << "Nhap ID sinh vien can xoa: ";
            std::cin >> id;

            auto it = std::find_if(students.begin(), students.end(), [id](const Student& student) {
                return student.getId() == id;
            });

            if (it != students.end()) {
                students.erase(it);
                std::cout << "Da xoa sinh vien voi ID: " << id << std::endl;
                saveAllStudentsToFile(students, "database_sv.csv"); // Lưu lại sau khi xóa
            } else {
                std::cout << "Khong tim thay sinh vien voi ID: " << id << std::endl;
            }
        } else {
            std::cout << "Khong tim thay sinh vien voi ten: " << name << std::endl;
        }

        std::cout << "1. Xoa sinh vien khac\n";
        std::cout << "0. Quay lai\n";
        std::cout << "Vui long chon chuc nang: ";
        std::cin >> choice;

        if (choice == 0) {
            return; // Quay lai menu chinh
        }
    } while (true);
}



#endif // DELETE_STUDENT_HPP
