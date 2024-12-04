#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một node trong danh sách liên kết
struct Node
{
    int data;
    struct Node *next;
};

// Hàm tạo một node mới
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm một phần tử vào cuối danh sách liên kết
void append(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Hàm xóa phần tử đầu danh sách liên kết
void deleteFirst(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Hàm hiển thị danh sách liên kết
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("Danh sách trống\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
        {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int n;

    // Nhập số lượng phần tử của danh sách
    printf("Nhập vào số lượng phần tử của danh sách (0 <= n <= 1000): ");
    scanf("%d", &n);

    // Nhập các phần tử của danh sách
    if (n > 0)
    {
        printf("Nhập các phần tử:\n");
        for (int i = 0; i < n; i++)
        {
            int value;
            scanf("%d", &value);
            append(&head, value);
        }
    }

    // Xóa phần tử đầu
    deleteFirst(&head);

    // Hiển thị danh sách sau khi xóa
    display(head);

    return 0;
}
