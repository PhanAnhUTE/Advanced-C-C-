#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include <iostream>
#include <vector>
#include <string>

class Dish {
public:
    int id;
    std::string name;
    double price;
    int quantity;

    Dish(int id, const std::string &name, double price, int quantity = 0) 
        : id(id), name(name), price(price), quantity(quantity) {}
};

class Restaurant {
private:
    int tableCount;
    int nextDishID;
    std::vector<Dish> dishes;
    std::vector<char> tableStatus; // O: trống, X: đang phục vụ
    std::vector<std::vector<Dish>> tableOrders; // danh sách món đã gọi theo từng bàn

public:
    Restaurant() : tableCount(0), nextDishID(2000) {}

    void setTableCount(int count) {
        if (count <= 0) {
            std::cout << "So ban phai lon hon 0, vui long nhap lai.\n";
        } else {
            tableCount = count;
            tableStatus.resize(count, 'O');
            tableOrders.resize(count);
            std::cout << "Set up so ban phuc vu thanh cong\n";
        }
    }

    void addDish(const std::string &name, double price) {
        dishes.push_back(Dish(nextDishID++, name, price));
        std::cout << "Them mon thanh cong\n";
        listDishes();
    }

    void deleteDish(int index) {
        if (index >= 0 && index < dishes.size()) {
            dishes.erase(dishes.begin() + index);
            std::cout << "Xoa mon thanh cong\n";
        } else {
            std::cout << "Mon khong ton tai\n";
        }
    }

    void listDishes() const {
        std::cout << "Danh sach mon: \n";
        std::cout << "STT\tID\tTen Mon\t Gia\n";
        for (size_t i = 0; i < dishes.size(); ++i) {
            std::cout << i + 1 << "\t" << dishes[i].id << "\t" << dishes[i].name << "\t" << dishes[i].price << " VND\n";
        }
    }

    void editDishById(int id, double price) {
        for (size_t i = 0; i < dishes.size(); ++i) {
            if (dishes[i].id == id) {
                dishes[i].price = price;
                std::cout << "STT\tID\tTen Mon\tGia\n";
                std::cout << i + 1 << "\t" << dishes[i].id << "\t" << dishes[i].name << "\t" << dishes[i].price << " VND\n";
                std::cout << "Cap nhat thong tin mon thanh cong\n";
                return;
            }
        }
        std::cout << "Mon khong ton tai\n";
    }

    void listTableStatus() const {
        std::cout << "So ban:    ";
        for (int i = 1; i <= tableCount; ++i) {
            printf("%-8d", i);
        }
        std::cout << std::endl;
        std::cout << "Trang thai:  ";
        for (int i = 0; i < tableCount; ++i) {
            printf("%-8c", tableStatus[i] ? 'X' : 'O');
        }
        std::cout << std::endl;
    }

    void callDish(int tableID, int dishID, int quantity) {
        if (tableID >= 1 && tableID <= tableCount) {
            for (const Dish &dish : dishes) {
                if (dish.id == dishID) {
                    if (tableStatus[tableID - 1] == 'O') {
                        tableStatus[tableID - 1] = 'X';
                    }

                    // Kiểm tra xem món đã được gọi chưa
                    bool found = false;
                    for (Dish &orderedDish : tableOrders[tableID - 1]) {
                        if (orderedDish.id == dishID) {
                            // Nếu món đã được gọi, cập nhật số lượng
                            orderedDish.quantity += quantity;  // Cộng dồn số lượng
                            found = true;
                            break;
                        }
                    }

                    // Nếu món chưa được gọi, thêm mới vào danh sách
                    if (!found) {
                        tableOrders[tableID - 1].push_back(Dish(dishID, dish.name, dish.price, quantity));
                    }

                    // Hiển thị thông tin tất cả các món đã gọi cho bàn này
                    std::cout << "STT\tTen mon\t Gia\t So luong\n";
                    for (size_t i = 0; i < tableOrders[tableID - 1].size(); ++i) {
                        const Dish &orderedDish = tableOrders[tableID - 1][i];
                        std::cout << i + 1 << "\t" << orderedDish.name << "\t" << orderedDish.price << "\t" << orderedDish.quantity << "\n";
                    }

                    std::cout << "Goi mon thanh cong\n";
                    return;
                }
            }
            std::cout << "Mon khong ton tai\n";
        } else {
            std::cout << "ID ban khong hop le\n";
        }
    }

    void displayTableStatus() const {
        std::cout << "So ban:        ";
        for (int i = 1; i <= tableCount; ++i) {
            std::cout << i << "\t";
        }
        std::cout << std::endl;

        std::cout << "Trang thai:    ";
        for (int i = 0; i < tableCount; ++i) {
            std::cout << tableStatus[i] << "\t";
        }
        std::cout << std::endl;
    }

    int getTableCount() const {
        return tableCount;
    }

    const std::vector<Dish>& getDishes() const {
        return dishes;
    }

    // Các hàm điều khiển giao diện
    void displayMainMenu() const {
        std::cout << "Quan ly nha hang\n";
        std::cout << "1. Quan ly\n";
        std::cout << "2. Nhan vien\n";
        std::cout << "0. Thoat\n";
        std::cout << "Vui long chon tinh nang: ";
    }

    void displayManagementMenu() const {
        std::cout << "Quan ly\n";
        std::cout << "1. Set up so ban\n";
        std::cout << "2. Them mon\n";
        std::cout << "3. Sua mon\n";
        std::cout << "4. Xoa mon\n";
        std::cout << "5. Danh sach mon\n";
        std::cout << "0. Quay lai\n";
        std::cout << "Vui long chon tinh nang: ";
    }

    void managementSection() {
        while (true) {
            displayManagementMenu();
            int option;
            std::cin >> option;
            switch (option) {
                case 1:
                    setTableCount();
                    break;
                case 2:
                    addDish();
                    break;
                case 3:
                    editDish();
                    break;
                case 4:
                    deleteDish();
                    break;
                case 5:
                    listDishes();
                    break;
                case 0:
                    return;
                default: 
                    std::cout << "Lua chon khong hop le\n";
                    break;
            }
        }
    }

    void displayEmployeeMenu() {
        displayTableStatus();
        int tableID;
        std::cout << "Vui long nhap ID ban (1-" << getTableCount() << "): ";
        std::cin >> tableID;

        if (tableID < 1 || tableID > getTableCount()) {
            std::cout << "ID ban khong hop le\n";
            return;
        }

        std::cout << "Nhan vien\n";
        std::cout << "1. Goi mon\n";
        std::cout << "2. Huy mon\n";
        std::cout << "3. Doi mon\n";
        std::cout << "4. Danh sach mon da dat\n";
        std::cout << "5. Thanh toan\n";
        std::cout << "0. Quay lai\n";
        std::cout << "Vui long chon tinh nang: ";
        int option;
        std::cin >> option;
        switch (option) {
            case 1:
                callDish(tableID);
                break;
            case 2:
                cancelDish(tableID);
                break;
            case 3:
                
                break;
            case 4:
                listOrderedDishes(tableID);
                break;
            case 5:
                processPayment(tableID);
                break;
            case 0:
                return;
            default:
                std::cout << "Lua chon khong hop le\n";
                break;
        }
    }

    void setTableCount() {
        std::cout << "Set up so ban\n";
        int count;
        std::cout << "Nhap so ban se phuc vu: ";
        std::cin >> count;
        setTableCount(count);
        std::cout << "1. Quay lai\n";
        std::cout << "0. Thoat\n";
        std::cout << "Vui long chon tinh nang: ";
        int option;
        std::cin >> option;
        if (option == 1) {
            return;
        } else if (option == 0) {
            exit(0);
        }
    }

    void addDish() {
        std::string name;
        double price;
        std::cout << "Them mon\n";
        std::cout << "Nhap ten mon: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Nhap gia: ";
        std::cin >> price;
        addDish(name, price);
        std::cout << "Ban co muon them mon khac khong?\n";
        std::cout << "1. Them mon khac\n";
        std::cout << "0. Quay lai\n";
        std::cout << "Vui long chon tinh nang: ";
        int option;
        std::cin >> option;
        if (option == 1) {
            addDish();
        } else if (option == 0) {
            return;
        }
    }

    void deleteDish() {
        int index;
        listDishes();
        std::cout << "Xoa mon\n";
        std::cout << "Nhap so thu tu cua mon can xoa: ";
        std::cin >> index;
        deleteDish(index - 1);
    }

    void editDish() {
        int id;
        double newPrice;
        listDishes();
        std::cout << "Vui long nhap ID mon ban muon sua: ";
        std::cin >> id;
        std::cout << "Nhap gia moi: ";
        std::cin >> newPrice;
        editDishById(id, newPrice);

        std::cout << "Ban co muon thay doi thong tin mon khac khong?\n";
        std::cout << "1. Thay doi thong tin mon khac\n";
        std::cout << "0. Quay lai\n";
        std::cout << "Vui long chon tinh nang: ";
        int option;
        std::cin >> option;
        if (option == 1) {
            editDish();
        } else if (option == 0) {
            return;
        }
    }

    void callDish(int tableID) {
        int dishID, quantity;
        listDishes();
        std::cout << "Goi mon\n";
        std::cout << "Vui long nhap ID mon: ";
        std::cin >> dishID;
        std::cout << "Vui long nhap so luong mon: ";
        std::cin >> quantity;
        callDish(tableID, dishID, quantity);
        std::cout << "Ban co muon goi mon khac khong?\n";
        std::cout << "1. Goi them mon khac\n";
        std::cout << "0. Quay lai\n";
        std::cout << "Vui long chon tinh nang: ";
        int option;
        std::cin >> option;
        if (option == 1) {
            callDish(tableID);
        } else if (option == 0) {
            return;
        }
    }




    void cancelDish(int tableID) {
    if (tableID < 1 || tableID > tableCount) {
        std::cout << "ID ban khong hop le\n";
        return;
    }

    // In ra danh sách món đã gọi cho bàn
    std::cout << "Huy mon\n";
    std::cout << "STT\tID\tTen mon\tGia\tSo luong\n";
    for (size_t i = 0; i < tableOrders[tableID - 1].size(); ++i) {
        const Dish &orderedDish = tableOrders[tableID - 1][i];
        std::cout << i + 1 << "\t" << orderedDish.id << "\t" << orderedDish.name << "\t" << orderedDish.price << "\t" << orderedDish.quantity << "\n";
    }
    std::cout << "------------------\n";

    // Nhập ID món cần hủy
    int dishID;
    std::cout << "Vui long nhap ID mon ban muon huy: ";
    std::cin >> dishID;

    // Tìm món trong danh sách và in ra thông tin
    for (size_t i = 0; i < tableOrders[tableID - 1].size(); ++i) {
        if (tableOrders[tableID - 1][i].id == dishID) {
            const Dish &orderedDish = tableOrders[tableID - 1][i];
            std::cout << "STT\tID\tTen mon\tGia\tSo luong\n";
            std::cout << "1\t" << orderedDish.id << "\t" << orderedDish.name << "\t" << orderedDish.price << "\t" << orderedDish.quantity << "\n";
            std::cout << "Vui long nhap so luong muon huy: ";
            int cancelQuantity;
            std::cin >> cancelQuantity;

            // Cập nhật số lượng món hoặc xóa món nếu số lượng hủy bằng hoặc lớn hơn số lượng hiện tại
            if (cancelQuantity >= orderedDish.quantity) {
                tableOrders[tableID - 1].erase(tableOrders[tableID - 1].begin() + i);
            } else {
                tableOrders[tableID - 1][i].quantity -= cancelQuantity;
            }

            std::cout << "Huy mon thanh cong\n";
            return;
        }
    }

    std::cout << "Mon khong ton tai trong danh sach\n";
}



void listOrderedDishes(int tableID) const {
    if (tableID < 1 || tableID > tableCount) {
        std::cout << "ID ban khong hop le\n";
        return;
    }

    std::cout << "Danh sach mon da dat\n";
    std::cout << "STT\tID\tTen mon\tGia\tSo luong\n";
    for (size_t i = 0; i < tableOrders[tableID - 1].size(); ++i) {
        const Dish &orderedDish = tableOrders[tableID - 1][i];
        std::cout << i + 1 << "\t" << orderedDish.id << "\t" << orderedDish.name << "\t" << orderedDish.price << "\t" << orderedDish.quantity << "\n";
    }
    std::cout << "\n0. Quay lai\n";
    std::cout << "Vui long nhan 0 de quay lai: ";
    int option;
    std::cin >> option;
    if (option == 0) {
        return;
    }
}



void processPayment(int tableID) {
    if (tableID < 1 || tableID > tableCount) {
        std::cout << "ID ban khong hop le\n";
        return;
    }

    double totalAmount = 0.0;

    std::cout << "Thanh toan\n";
    std::cout << "Danh sach mon da dat\n";
    std::cout << "STT\tTen mon\tGia\tSo luong\n";
    for (size_t i = 0; i < tableOrders[tableID - 1].size(); ++i) {
        const Dish &orderedDish = tableOrders[tableID - 1][i];
        std::cout << i + 1 << "\t" << orderedDish.name << "\t" << orderedDish.price << "\t" << orderedDish.quantity << "\n";
        totalAmount += orderedDish.price * orderedDish.quantity;
    }

    double vat = 0.1 * totalAmount;
    double finalAmount = totalAmount + vat;

    std::cout << "---------------------\n";
    std::cout << "Tong : " << totalAmount << "\n";
    std::cout << "VAT: 10%\n";
    std::cout << "Thanh tien: " << finalAmount << "\n";
    std::cout << "\n1. Thanh toan\n";
    std::cout << "0. Quay lai\n";
    std::cout << "Vui long chon chuc nang: ";
    
    int option;
    std::cin >> option;
    if (option == 1) {
        // Thanh toán thành công
        tableStatus[tableID - 1] = 'O';  // Đặt lại trạng thái bàn thành trống
        tableOrders[tableID - 1].clear();  // Xóa đơn hàng của bàn
        std::cout << "Thanh toan thanh cong\n";
    }
}



};

#endif // RESTAURANT_HPP
