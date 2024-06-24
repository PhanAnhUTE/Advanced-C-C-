#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char uid[20];
    char roomNumber[10];
    char name[50];
    char licensePlate[20];
} Member;

typedef struct MemberNode {
    Member data;
    struct MemberNode* next;
} MemberNode;


MemberNode* createMemberNode(Member member);
void addMember(const char* filename, Member member);
void deleteMember(const char* filename, const char* uid);
void editMember(const char* filename, Member updatedMember);
Member searchMember(const char* filename, const char* searchValue, int (*searchFunc)(const Member*, const char*));
int searchByUID(const Member* member, const char* uid);
int searchByLicensePlate(const Member* member, const char* licensePlate);
void clearNewline(char* str);


MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}

void addMember(const char* filename, Member member) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error_File\n");
        return;
    }
    fprintf(file, "%s,%s,%s,%s\n", member.uid, member.roomNumber, member.name, member.licensePlate);
    fclose(file);
}

void deleteMember(const char* filename, const char* uid) {
    FILE* file = fopen(filename, "r");
    FILE* tempFile = fopen("tempfile.csv", "w"); 
    char line[256];

    if (file == NULL || tempFile == NULL) {
        printf("Error_File\n");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        char tempUID[20];
        sscanf(line, "%[^,]", tempUID);

        if (strcmp(tempUID, uid) != 0) {
            fputs(line, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(filename);
    rename("tempfile.csv", filename);
}

void editMember(const char* filename, Member updatedMember) {
    FILE* file = fopen(filename, "r");
    FILE* tempFile = fopen("tempfile.csv", "w"); 
    char line[256];

    if (file == NULL || tempFile == NULL) {
        printf("Error_File\n");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        char tempUID[20];
        sscanf(line, "%[^,]", tempUID);

        if (strcmp(tempUID, updatedMember.uid) == 0) {
            fprintf(tempFile, "%s,%s,%s,%s\n", updatedMember.uid, updatedMember.roomNumber, updatedMember.name, updatedMember.licensePlate);
        } else {
            fputs(line, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(filename);
    rename("tempfile.csv", filename);
}

Member searchMember(const char* filename, const char* searchValue, int (*searchFunc)(const Member*, const char*)) {
    FILE* file = fopen(filename, "r");
    char line[256];
    Member member;

    if (file == NULL) {
        printf("Error_File\n");
    }

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%[^,],%[^,],%s", member.uid, member.roomNumber, member.name, member.licensePlate);

        if (searchFunc(&member, searchValue)) {
            fclose(file);
            return member;
        }
    }

    fclose(file);
    strcpy(member.uid, "NOT_FOUND");
    return member;
}

int searchByUID(const Member* member, const char* uid) {
    return strcmp(member->uid, uid) == 0;
}

int searchByLicensePlate(const Member* member, const char* licensePlate) {
    return strcmp(member->licensePlate, licensePlate) == 0;
}

void clearNewline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

#endif 

