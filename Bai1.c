#include <stdio.h>
#include <stdlib.h>

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

// Hàm tạo danh sách liên kết
struct Node *createLinkedList(int n)
{
    if (n == 0)
        return NULL; // Trả về NULL nếu không có phần tử

    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        printf("Nhập phần tử %d: ", i + 1);
        scanf("%d", &value);
        struct Node *newNode = createNode(value);
        if (!head)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
    }
    return head;
}

// Hàm in danh sách liên kết
void printLinkedList(struct Node *head)
{
    if (!head)
    {
        printf("Danh sách trống\n");
        return;
    }
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
    int n;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);

    struct Node *list = createLinkedList(n);
    printLinkedList(list);
    freeLinkedList(list);

    return 0;
}
