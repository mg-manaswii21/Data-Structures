
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList() {
    struct Node *head = NULL, *temp, *newNode;
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter value: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

void display(struct Node* head) {
    struct Node* temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* concatenate(struct Node* list1, struct Node* list2) {
    if(list1 == NULL)
        return list2;

    struct Node* temp = list1;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = list2;

    return list1;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int choice;

    while(1) {
        printf("\nMENU\n");
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Display Lists\n");
        printf("4. Concatenate List2 to List1\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Creating List 1\n");
                list1 = createList();
                break;

            case 2:
                printf("Creating List 2\n");
                list2 = createList();
                break;

            case 3:
                printf("List 1: ");
                display(list1);
                printf("List 2: ");
                display(list2);
                break;

            case 4:
                list1 = concatenate(list1, list2);
                printf("Lists concatenated successfully.\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}