#ifndef EDIT_STUDENT_HPP
#define EDIT_STUDENT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
#include <vector>


#include "Constructor.hpp"
#include "save_student.hpp"
#include "printf_student.hpp"




void editStudentInfo(std::list<Student>& students) {
    std::string name;
    int choice;
    
    do {
        std::cout << "Nhap ten sinh vien can sua: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::vector<Student*> results;
        for (auto& student : students) {
            if (student.getName() == name) {
                results.push_back(&student);
            }
        }

        if (!results.empty()) {
            std::cout << "\nDanh sach sinh vien:\n";
            std::cout << "STT\t|\tID\t|\tTen\n";
            std::cout << "---------------------------------\n";
            for (size_t i = 0; i < results.size(); ++i) {
                std::cout << (i + 1) << "\t|\t" << results[i]->getId() << "\t|\t" << results[i]->getName() << "\n";
            }

            int id;
            std::cout << "Vui long nhap ID sinh vien muon sua thong tin: ";
            std::cin >> id;

            auto it = std::find_if(students.begin(), students.end(), [id](const Student& student) {
                return student.getId() == id;
            });

            if (it != students.end()) {
                Student& student = *it;
                do {
                    student.printStudentDetails();
                    std::cout << "\n1. Sua ten\n";
                    std::cout << "2. Sua tuoi\n";
                    std::cout << "3. Sua gioi tinh\n";
                    std::cout << "4. Sua diem toan\n";
                    std::cout << "5. Sua diem ly\n";
                    std::cout << "6. Sua diem hoa\n";
                    std::cout << "0. Quay lai\n";
                    std::cout << "Vui long chon chuc nang: ";
                    std::cin >> choice;

                    switch (choice) {
                        case 1: {
                            std::string newName;
                            std::cout << "Nhap ten moi: ";
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::getline(std::cin, newName);
                            student.setName(newName);
                            std::cout << "Cap nhat thong tin thanh cong.\n";
                            break;
                        }
                        case 2: {
                            int newAge;
                            std::cout << "Nhap tuoi moi: ";
                            std::cin >> newAge;
                            student.setAge(newAge);
                            std::cout << "Cap nhat thong tin thanh cong.\n";
                            break;
                        }
                        case 3: {
                            std::string newGender;
                            std::cout << "Nhap gioi tinh moi: ";
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::getline(std::cin, newGender);
                            student.setGender(newGender);
                            std::cout << "Cap nhat thong tin thanh cong.\n";
                            break;
                        }
                        case 4: {
                            float newMathScore;
                            std::cout << "Nhap diem toan moi: ";
                            std::cin >> newMathScore;
                            student.setMathScore(newMathScore);
                            std::cout << "Cap nhat thong tin thanh cong.\n";
                            break;
                        }
                        case 5: {
                            float newPhysicsScore;
                            std::cout << "Nhap diem ly moi: ";
                            std::cin >> newPhysicsScore;
                            student.setPhysicsScore(newPhysicsScore);
                            std::cout << "Cap nhat thong tin thanh cong.\n";
                            break;
                        }
                        case 6: {
                            float newChemistryScore;
                            std::cout << "Nhap diem hoa moi: ";
                            std::cin >> newChemistryScore;
                            student.setChemistryScore(newChemistryScore);
                            std::cout << "Cap nhat thong tin thanh cong.\n";
                            break;
                        }
                        case 0:
                            break;
                        default:
                            std::cout << "Chuc nang khong hop le. Vui long chon lai.\n";
                    }

                    saveAllStudentsToFile(students, "database_sv.csv"); // Lưu lại sau khi sửa đổi

                } while (choice != 0);
            } else {
                std::cout << "Khong tim thay sinh vien voi ID: " << id << std::endl;
            }
        } else {
            std::cout << "Khong tim thay sinh vien voi ten: " << name << std::endl;
        }

        std::cout << "\n1. Sua sinh vien khac\n";
        std::cout << "0. Quay lai\n";
        std::cout << "Vui long chon chuc nang: ";
        std::cin >> choice;

    } while (choice != 0);

#endif // EDIT_STUDENT_HPP
