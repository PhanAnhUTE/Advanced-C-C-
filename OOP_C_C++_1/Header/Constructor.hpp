#ifndef CONSTRUCTOR_HPP
#define CONSTRUCTOR_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
#include <vector>


#include "add_student.hpp"
#include "delete_student.hpp"
#include "edit_student.hpp"
#include "save_student.hpp"
#include "search_student.hpp"
#include "printf_student.hpp"

class Student {
private:
    std::string name;
    int age;
    std::string gender;
    float mathScore;
    float physicsScore;
    float chemistryScore;
    int id;
    static int nextId;

public:
    // Constructors
    Student();
    Student(std::string name, int age, std::string gender, float mathScore, float physicsScore, float chemistryScore);
    
    // Getters
    std::string getName() const;
    int getAge() const;
    std::string getGender() const;
    float getMathScore() const;
    float getPhysicsScore() const;
    float getChemistryScore() const;
    int getId() const;

    // Setters
    void setName(const std::string& name);
    void setAge(int age);
    void setGender(const std::string& gender);
    void setMathScore(float score);
    void setPhysicsScore(float score);
    void setChemistryScore(float score);

    // Functions
    float calculateAverageScore() const;
    std::string determineGrade() const;
    void inputStudentDetails();
    void printStudentDetails() const;
    void saveToFile(std::ofstream& file) const;
    void addStudent(std::list<Student>& students);
    void searchStudent(const std::list<Student>& students);
    void deleteStudent(std::list<Student>& students);
    void editStudentInfo(std::list<Student>& students);




    bool compareByName(const Student& a, const Student& b) {
    return a.getName() < b.getName();
}

void sortStudentsByName(std::list<Student>& students) {
    students.sort(compareByName);
}



bool compareByMathScore(const Student& a, const Student& b) {
    return a.getMathScore() > b.getMathScore(); // Sắp xếp giảm dần theo điểm toán
}

void sortStudentsByMathScore(std::list<Student>& students) {
    students.sort(compareByMathScore);
}


bool compareByPhysicsScore(const Student& a, const Student& b) {
    return a.getPhysicsScore() > b.getPhysicsScore(); // Sắp xếp giảm dần theo điểm lý
}

void sortStudentsByPhysicsScore(std::list<Student>& students) {
    students.sort(compareByPhysicsScore);
}



bool compareByChemistryScore(const Student& a, const Student& b) {
    return a.getChemistryScore() > b.getChemistryScore(); // Sắp xếp giảm dần theo điểm hóa
}

void sortStudentsByChemistryScore(std::list<Student>& students) {
    students.sort(compareByChemistryScore);
}



bool compareByAverageScore(const Student& a, const Student& b) {
    return a.calculateAverageScore() > b.calculateAverageScore(); // Sắp xếp giảm dần theo điểm trung bình
}

void sortStudentsByAverageScore(std::list<Student>& students) {
    students.sort(compareByAverageScore);
}

};

// Static variable initialization
int Student::nextId = 202401;

// Implementations

Student::Student() {
    id = nextId++;
}

Student::Student(std::string name, int age, std::string gender, float mathScore, float physicsScore, float chemistryScore)
    : name(name), age(age), gender(gender), mathScore(mathScore), physicsScore(physicsScore), chemistryScore(chemistryScore) {
    id = nextId++;
}

std::string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

std::string Student::getGender() const {
    return gender;
}

float Student::getMathScore() const {
    return mathScore;
}

float Student::getPhysicsScore() const {
    return physicsScore;
}

float Student::getChemistryScore() const {
    return chemistryScore;
}

int Student::getId() const {
    return id;
}

void Student::setName(const std::string& name) {
    this->name = name;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setGender(const std::string& gender) {
    this->gender = gender;
}

void Student::setMathScore(float score) {
    this->mathScore = score;
}

void Student::setPhysicsScore(float score) {
    this->physicsScore = score;
}

void Student::setChemistryScore(float score) {
    this->chemistryScore = score;
}

float Student::calculateAverageScore() const {
    return (mathScore + physicsScore + chemistryScore) / 3.0f;
}



std::string Student::determineGrade() const {
    float avgScore = calculateAverageScore();
    if (avgScore >= 8.0f) {
        return "Gioi";
    } else if (avgScore >= 6.5f) {
        return "Kha";
    } else if (avgScore >= 5.0f) {
        return "Trung binh";
    } else {
        return "Yeu";
    }
}


void Student::inputStudentDetails() {
    std::cout << "Nhap ten: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    
    // Validate age
    do {
        std::cout << "Nhap tuoi (tu 18 den 50): ";
        std::cin >> age;
        if (age < 18 || age > 50) {
            std::cout << "Tuoi khong hop le. Vui long nhap lai.\n";
        }
    } while (age < 18 || age > 50);
    
    std::cout << "Gioi tinh: ";
    std::cin.ignore();
    std::getline(std::cin, gender);
    
    // Validate scores
    do {
        std::cout << "Nhap diem toan (tu 0.0 den 10.0): ";
        std::cin >> mathScore;
        if (mathScore < 0.0f || mathScore > 10.0f) {
            std::cout << "Diem toan khong hop le. Vui long nhap lai.\n";
        }
    } while (mathScore < 0.0f || mathScore > 10.0f);
    
    do {
        std::cout << "Nhap diem ly (tu 0.0 den 10.0): ";
        std::cin >> physicsScore;
        if (physicsScore < 0.0f || physicsScore > 10.0f) {
            std::cout << "Diem ly khong hop le. Vui long nhap lai.\n";
        }
    } while (physicsScore < 0.0f || physicsScore > 10.0f);
    
    do {
        std::cout << "Nhap diem hoa (tu 0.0 den 10.0): ";
        std::cin >> chemistryScore;
        if (chemistryScore < 0.0f || chemistryScore > 10.0f) {
            std::cout << "Diem hoa khong hop le. Vui long nhap lai.\n";
        }
    } while (chemistryScore < 0.0f || chemistryScore > 10.0f);
}

#endif // CONSTRUCTOR_HPP
