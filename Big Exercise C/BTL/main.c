#include "main.h"

void displayMenu() {
    printf("Quan ly thong tin cu dan chung cu\n");
    printf("1. Them cu dan\n");
    printf("2. Xoa cu dan\n");
    printf("3. Tim cu dan theo UID\n");
    printf("4. Tim cu dan theo bien so xe\n");
    printf("5. Cap nhat thong tin cu dan\n");
    printf("0. Dung chuong trinh\n");
    printf("Vui long chon tinh nang: ");
}

int main() {
    const char* filename = "temp.csv";
    int choice;
    char uid[20];
    Member member;

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhap UID: ");
                fgets(member.uid, sizeof(member.uid), stdin);
                clearNewline(member.uid);

                printf("Nhap so phong: ");
                fgets(member.roomNumber, sizeof(member.roomNumber), stdin);
                clearNewline(member.roomNumber);

                printf("Nhap ten: ");
                fgets(member.name, sizeof(member.name), stdin);
                clearNewline(member.name);

                printf("Nhap bien so xe: ");
                fgets(member.licensePlate, sizeof(member.licensePlate), stdin);
                clearNewline(member.licensePlate);

                addMember(filename, member);
                break;
            case 2:
                printf("Nhap UID cua cu dan can xoa: ");
                fgets(uid, sizeof(uid), stdin);
                clearNewline(uid);
                deleteMember(filename, uid);
                break;
            case 3:
                printf("Nhap UID can tim: ");
                fgets(uid, sizeof(uid), stdin);
                clearNewline(uid);
                member = searchMember(filename, uid, searchByUID);
                if (strcmp(member.uid, "NOT_FOUND") == 0) {
                    printf("Khong tim thay cu dan.\n");
                } else {
                    printf("Thong tin cu dan: %s, %s, %s, %s\n", member.uid, member.roomNumber, member.name, member.licensePlate);
                }
                break;
            case 4:
                printf("Nhap bien so xe can tim: ");
                fgets(uid, sizeof(uid), stdin);
                clearNewline(uid);
                member = searchMember(filename, uid, searchByLicensePlate);
                if (strcmp(member.uid, "NOT_FOUND") == 0) {
                    printf("Khong tim thay cu dan.\n");
                } else {
                    printf("Thong tin cu dan: %s, %s, %s, %s\n", member.uid, member.roomNumber, member.name, member.licensePlate);
                }
                break;
            case 5:
                printf("Nhap UID cua cu dan can cap nhat: ");
                fgets(uid, sizeof(uid), stdin);
                clearNewline(uid);
                printf("Nhap thong tin moi:\n");
                printf("Nhap so phong: ");
                fgets(member.roomNumber, sizeof(member.roomNumber), stdin);
                clearNewline(member.roomNumber);

                printf("Nhap ten: ");
                fgets(member.name, sizeof(member.name), stdin);
                clearNewline(member.name);

                printf("Nhap bien so xe: ");
                fgets(member.licensePlate, sizeof(member.licensePlate), stdin);
                clearNewline(member.licensePlate);

                strcpy(member.uid, uid);
                editMember(filename, member);
                break;
            case 0:
                printf("Dung chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
