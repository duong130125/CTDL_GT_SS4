#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc node
struct Node
{
    int data;
    struct Node *next;
};

// Hàm tạo node mới
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm phần tử vào đầu danh sách
struct Node *addToHead(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// Hàm in danh sách liên kết
void printLinkedList(struct Node *head)
{
    for (struct Node *current = head; current; current = current->next)
        printf("%d -> ", current->data);
    printf("NULL\n");
}

// Hàm giải phóng bộ nhớ
void freeLinkedList(struct Node *head)
{
    while (head)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int n, valueToAdd;
    printf("Nhập số lượng phần tử n (0 <= n <= 1000): ");
    scanf("%d", &n);

    struct Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        printf("Nhập phần tử %d: ", i + 1);
        scanf("%d", &value);
        head = addToHead(head, value); // Thêm vào đầu danh sách
    }

    // Đảo ngược danh sách vì đang thêm vào đầu
    struct Node *reversedHead = NULL;
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        temp->next = reversedHead;
        reversedHead = temp;
    }

    head = reversedHead;

    printf("Nhập giá trị cần chèn vào đầu danh sách: ");
    scanf("%d", &valueToAdd);
    head = addToHead(head, valueToAdd);

    printf("Danh sách sau khi thêm giá trị mới: ");
    printLinkedList(head);

    freeLinkedList(head);
    return 0;
}
