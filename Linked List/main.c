#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node* next;
} node;

node* createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

void push_back(node** array, int value) // thêm node vào cuối
{
    node* temp = createNode(value);

    if (*array == NULL)
    {
        *array = temp;
    }
    else
    {
        node* p = *array;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void push_front(node** array, int value) // thêm node vào đầu tiên
{
    node* temp = createNode(value);
    temp->next = *array;
    *array = temp;
}

void pop_back(node** array)// xóa phần tử cuối
{
    if (*array == NULL)
        return;

    node* p = *array;

    if (p->next == NULL)
    {
        free(p);
        *array = NULL;
        return;
    }

    while (p->next->next != NULL)
    {
        p = p->next;
    }
    node* temp = p->next;
    p->next = NULL;
    free(temp);
}

void pop_front(node** array)  // xóa phần tử đầu tiên
{
    if (*array == NULL)
        return;

    node* temp = *array;
    *array = (*array)->next;
    free(temp);
}

int get(node* array, int pos) // lấy giá trị từ vị trí pos
{
    int i = 0;

    while (array != NULL && i < pos)
    {
        array = array->next;
        i++;
    }

    if (array == NULL)
    {
        printf("Error: List has less elements than position %d\n", pos);
        return -1;
    }

    return array->value;
}

int front(node* array)  // lấy giá trị của node đầu tiên
{
    if (array == NULL)
    {
        printf("Error: List is empty\n");
        return -1;
    }

    return array->value;
}

int back(node* array) // lấy giá trị cuối
{
    if (array == NULL)
    {
        printf("Error: List is empty\n");
        return -1;
    }

    while (array->next != NULL)
    {
        array = array->next;
    }

    return array->value;
}

bool empty(node** array) // kiểm tra rỗng
{
    return *array == NULL;
}

int size(node** array) // lấy kích thước
{
    int count = 0;
    node* temp = *array;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void insert(node** array, int value, int pos) // thêm vào phân từ bất kì
{
    node* temp = createNode(value);
    node* p = *array;
    node* front = NULL;
    int i = 0;

    if (pos == 0) // Trường hợp chèn vào đầu danh sách
    {
        temp->next = *array;
        *array = temp;
        return;
    }

    while (p != NULL && i < pos)
    {
        front = p;
        p = p->next;
        i++;
    }

    if (p == NULL && i == pos) // Chèn vào cuối danh sách
    {
        front->next = temp;
    }
    else if (p != NULL) // Chèn vào giữa danh sách
    {
        front->next = temp;
        temp->next = p;
    }
    else // Vị trí pos vượt quá độ dài danh sách
    {
        printf("Error: List has less elements than position %d\n", pos);
        free(temp);
    }
}


int main()
{
    node* arr = NULL;
    push_back(&arr, 2);
    push_back(&arr, 3);
    push_back(&arr, 5);
    push_back(&arr, 7);
    push_back(&arr, 10);
    push_back(&arr, 11);
    push_back(&arr, 20);

    printf("Value at position 0: %d\n", get(arr, 0));
    printf("Value at position 2: %d\n", get(arr, 2));
    printf("Value at position 4: %d\n", get(arr, 4));

    pop_front(&arr); // Xóa node đầu tiên
    printf("Value at 0 : %d\n", get(arr, 0)); 

    printf("Back value: %d\n", back(arr));

    printf("List empty? %s\n", empty(&arr) ? "true" : "false");

    printf("Size of list: %d\n", size(&arr));


    insert(&arr, 4, 3);
    printf("\nList after insert:\n");
    for (int i = 0; i < 7; ++i)
    {
        printf("Value at position %d: %d\n", i, get(arr, i));
    }

    return 0;
}
