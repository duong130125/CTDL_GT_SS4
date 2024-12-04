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

// Hàm chèn phần tử vào danh sách liên kết tại vị trí chỉ định
void insertAtPosition(Node **head, int value, int position)
{
    Node *newNode = createNode(value);

    // Nếu danh sách trống và muốn chèn vào vị trí 0
    if (*head == NULL && position == 0)
    {
        *head = newNode;
        return;
    }

    // Nếu muốn chèn vào đầu danh sách (vị trí 0)
    if (position == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *temp = *head;
    int currentPosition = 0;

    // Duyệt đến vị trí cần chèn
    while (temp != NULL && currentPosition < position - 1)
    {
        temp = temp->next;
        currentPosition++;
    }

    // Kiểm tra nếu vị trí nằm ngoài phạm vi
    if (temp == NULL)
    {
        printf("Lỗi: Vị trí ngoài phạm vi danh sách.\n");
        free(newNode);
        return;
    }

    // Chèn node mới vào vị trí
    newNode->next = temp->next;
    temp->next = newNode;
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

    // In danh sách trước khi chèn
    printf("Danh sách liên kết trước khi chèn: ");
    printList(head);

    // Nhập giá trị và vị trí cần chèn
    printf("Nhập giá trị cần chèn: ");
    scanf("%d", &value);
    printf("Nhập vị trí cần chèn: ");
    scanf("%d", &position);

    // Chèn phần tử vào vị trí đã cho
    insertAtPosition(&head, value, position);

    // In danh sách sau khi chèn
    printf("Danh sách liên kết sau khi chèn: ");
    printList(head);

    // Giải phóng bộ nhớ
    freeList(head);

    return 0;
}
