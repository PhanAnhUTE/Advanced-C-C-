#ifndef ADD_STUDENT_HPP
#define ADD_STUDENT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
#include <vector>
#include "Constructor.hpp"
#include "printf_student.hpp"


void addStudent(std::list<Student>& students) {
    int choice;
    do {
        Student newStudent;
        newStudent.inputStudentDetails();
        students.push_back(newStudent);
        newStudent.printStudentDetails();

        std::cout << "1. Them sinh vien khac\n";
        std::cout << "0. Quay lai\n";
        std::cout << "Vui long chon chuc nang: ";
        std::cin >> choice;

        if (choice == 0) {
            return; // Thoat khoi ham addStudent, quay lai menu chinh
        }
    } while (true);
}

#endif // ADD_STUDENT_HPP
