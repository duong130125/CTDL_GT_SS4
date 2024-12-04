#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Hàm tạo một node mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm một node vào cuối danh sách liên kết
void append(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Hàm xóa phần tử tại vị trí chỉ định
void deleteAtPosition(Node **head, int position)
{
    if (*head == NULL)
    {
        printf("Danh sách trống.\n");
        return;
    }

    Node *temp = *head;

    // Xóa phần tử đầu tiên
    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    // Duyệt qua danh sách để tìm phần tử cần xóa
    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    // Nếu vị trí không hợp lệ
    if (temp == NULL || temp->next == NULL)
    {
        printf("Vị trí không hợp lệ\n");
        return;
    }

    // Xóa phần tử tại vị trí
    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

// Hàm in danh sách liên kết
void printList(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sách trống\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
        {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Hàm giải phóng bộ nhớ của danh sách
void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *head = NULL;
    int n, value, position;

    // Nhập số lượng phần tử trong danh sách
    printf("Nhập vào số lượng phần tử n: ");
    scanf("%d", &n);

    // Nhập các phần tử cho danh sách liên kết
    printf("Nhập vào các phần tử của danh sách: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        append(&head, value);
    }

    // In danh sách trước khi xóa
    printf("Danh sách liên kết trước khi xóa: ");
    printList(head);

    // Nhập vị trí cần xóa
    printf("Vị trí cần xóa: ");
    scanf("%d", &position);

    // Xóa phần tử tại vị trí
    deleteAtPosition(&head, position);

    // In danh sách sau khi xóa
    printf("Danh sách liên kết sau khi xóa: ");
    printList(head);

    // Giải phóng bộ nhớ
    freeList(head);

    return 0;
}
