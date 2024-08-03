#include <iostream>
#include <list>
#include <string>


class Car {
private:
    std::string model;
    int year;

public:
    virtual void displayInfo() const = 0;
    virtual void inputInfo() = 0;

    
    std::string getModel() const {
        return model;
    }

    void setModel(std::string& m) {
        model = m;
    }

    
    int getYear() const {
        return year;
    }

    void setYear(int y) {
        year = y;
    }
};


class Sedan : public Car {
public:
    void displayInfo() const override {
        std::cout << "Sedan - Model: " <<  getModel() << ", Year: " << getYear() << std::endl;
    }

    void inputInfo() override {
        std::string model;
        int year;
        std::cout << "Enter Sedan model: ";
        std::cin >> model;
        setModel(model);
        std::cout << "Enter Sedan year: ";
        std::cin >> year;
        setYear(year);
    }
};



class SUV : public Car {
public:
    void displayInfo() const override {
        std::cout << "SUV - Model: " << getModel() << ", Year: " << getYear() << std::endl;
    }

    void inputInfo() override {
        std::string model;
        int year;
        std::cout << "Enter SUV model: ";
        std::cin >> model;
        setModel(model);
        std::cout << "Enter SUV year: ";
        std::cin >> year;
        setYear(year);
    }
};


int main() {
    std::list<Car*> cars;

    Sedan* sedan = new Sedan();
    sedan->inputInfo();
    cars.push_back(sedan);

    SUV* suv = new SUV();
    suv->inputInfo();
    cars.push_back(suv);


    for (Car* car : cars) {
    car->displayInfo();
}




    return 0;
}
