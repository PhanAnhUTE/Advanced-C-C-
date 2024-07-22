#include <iostream>
#include "restaurant.hpp"

int main() {
    Restaurant restaurant;
    while (true) {
        restaurant.displayMainMenu();
        int option;
        std::cin >> option;
        switch (option) {
            case 1:
                restaurant.managementSection();
                break;
            case 2:
                restaurant.displayEmployeeMenu();
                break;
            case 0:
                std::cout << "Thoat chuong trinh\n";
                return 0;
            default:
                std::cout << "Lua chon khong hop le\n";
                break;
        }
    }
}
