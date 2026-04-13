#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

// Function prototypes
struct Node* createNode(int data);
void insertEnd(struct Node** head, int data);
void deleteNode(struct Node** head, int data);
void display(struct Node* head);
void reverse(struct Node** head);
void concatenate(struct Node** head1);

int main() {
    struct Node* head = NULL;
    int choice, value;
    while (1) {
        printf("\nEnter operation\n1: Insert\n2: Delete\n3: Display\n4: Reverse\n5: Concatenate\n6: Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1: printf("Enter number to insert: "); scanf("%d", &value); insertEnd(&head, value); break;
            case 2: printf("Enter number to delete: "); scanf("%d", &value); deleteNode(&head, value); break;
            case 3: display(head); break;
            case 4: reverse(&head); break;
            case 5: concatenate(&head); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

