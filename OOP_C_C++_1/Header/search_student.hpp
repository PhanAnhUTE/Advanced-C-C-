#ifndef SEARCH_STUDENT_HPP
#define SEARCH_STUDENT_HPP

#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <vector>



#include "Constructor.hpp"
#include "printf_student.hpp"




void searchStudent(const std::list<Student>& students) {
    int choice;
    do {
        std::cout << "\n1. Tim kiem theo ten\n";
        std::cout << "2. Tim kiem theo ID\n";
        std::cout << "0. Quay lai\n";
        std::cout << "Vui long chon chuc nang: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                std::cout << "Nhap ten sinh vien: ";
                std::cin.ignore();
                std::getline(std::cin, name);

                std::vector<const Student*> results;
                for (const auto& student : students) {
                    if (student.getName() == name) {
                        results.push_back(&student);
                    }
                }

                if (!results.empty()) {
                    std::cout << "\nKet qua tim kiem:\n";
                    std::cout << "STT\t|\tID\t|\tTen\n";
                    std::cout << "---------------------------------\n";
                    for (size_t i = 0; i < results.size(); ++i) {
                        std::cout << (i + 1) << "\t|\t" << results[i]->getId() << "\t|\t" << results[i]->getName() << "\n";
                    }
                } else {
                    std::cout << "Khong tim thay sinh vien voi ten: " << name << std::endl;
                }
                break;
            }
            case 2: {
                int id;
                std::cout << "Nhap ID sinh vien: ";
                std::cin >> id;

                auto it = std::find_if(students.begin(), students.end(), [id](const Student& student) {
                    return student.getId() == id;
                });

                if (it != students.end()) {
                    it->printStudentDetails();
                } else {
                    std::cout << "Khong tim thay sinh vien voi ID: " << id << std::endl;
                }
                break;
            }
            case 0:
                return; // Quay lai menu chinh
            default:
                std::cout << "Chuc nang khong hop le. Vui long chon lai.\n";
        }
    } while (true);
}

#endif // SEARCH_STUDENT_HPP
