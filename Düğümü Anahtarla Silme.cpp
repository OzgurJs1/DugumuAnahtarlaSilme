#include <stdio.h>
#include <stdlib.h>
//Düðümü anahtarla silme
struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void deleteNode(int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void insertNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void printList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    head = NULL;
    insertNode(4);
    insertNode(3);
    insertNode(2);
    insertNode(1);
    printf("Orjinal liste: ");
    printList();
    int key = 1;
    deleteNode(key);
    printf("Dugumu anahtarla sildikten sonra liste %d: ", key);
    printList();
    return 0;
}

