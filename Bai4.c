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

// Hàm tìm kiếm phần tử trong danh sách liên kết
int search(Node *head, int value)
{
    int index = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1; // Trả về -1 nếu không tìm thấy
}

// Hàm in danh sách liên kết
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
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
    int n, value, searchValue;

    // Nhập số lượng phần tử trong danh sách
    printf("Nhập vào số lượng phần tử (0 <= n <= 1000): ");
    scanf("%d", &n);

    if (n == 0)
    {
        printf("Danh sách trống\n");
        return 0;
    }

    // Nhập các phần tử cho danh sách liên kết
    printf("Nhập vào các phần tử của danh sách: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        append(&head, value);
    }

    // Nhập giá trị cần tìm kiếm
    printf("Nhập giá trị cần tìm kiếm: ");
    scanf("%d", &searchValue);

    // Tìm kiếm và in kết quả
    int index = search(head, searchValue);
    if (index == -1)
    {
        printf("-1\n");
    }
    else
    {
        printf("Vị trí tìm thấy: %d\n", index);
    }

    // Giải phóng bộ nhớ
    freeList(head);

    return 0;
}
