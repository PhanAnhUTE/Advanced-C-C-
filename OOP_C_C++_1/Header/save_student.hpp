#ifndef SAVE_STUDENT_HPP
#define SAVE_STUDENT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
#include <vector>


#include "Constructor.hpp"





void Student::saveToFile(std::ofstream& file) const {
    file << id << "," << name << "," << age << "," << gender << ","
         << mathScore << "," << physicsScore << "," << chemistryScore << "\n";
}


void saveAllStudentsToFile(const std::list<Student>& students, const std::string& filename) {
    std::ofstream file(filename, std::ios::out); // Mở file ở chế độ ghi
    if (!file) {
        std::cerr << "Khong the mo file " << filename << " de ghi du lieu.\n";
        return;
    }

    // Ghi tiêu đề
    file << "ID,Ten,Tuoi,Gioi tinh,Toan,Ly,Hoa\n";

    for (const auto& student : students) {
        student.saveToFile(file);
    }

    file.close();
    std::cout << "Da luu danh sach sinh vien vao file " << filename << std::endl;
}

#endif // SAVE_STUDENT_HPP
