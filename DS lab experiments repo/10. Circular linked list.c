#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
int count = 0;

// Function to create the list
void create(int n) {
    int val;
    struct Node *newNode, *temp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        count++;
    }
}

// Function to insert at a position
void insert(int x, int pos) {
    if (pos <= 0 || pos > count + 1) {
        printf("Position not found\n");
        return;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    if (pos == 1) {
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            struct Node* temp = head;
            while (temp->next != head) temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    } else {
        struct Node* temp = head;
        for (int i = 1; i < pos - 1; i++) temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    count++;
}

// Function to delete at a position
void deleteNode(int pos) {
    if (head == NULL) {
        printf("CLL is empty\n");
        return;
    }
    if (pos < 1 || pos > count) {
        printf("Position not found\n");
        return;
    }
    struct Node *temp = head, *prev = NULL;
    int val;
    if (pos == 1) {
        val = head->data;
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            struct Node* last = head;
            while (last->next != head) last = last->next;
            head = head->next;
            last->next = head;
            free(temp);
        }
    } else {
        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        val = temp->data;
        prev->next = temp->next;
        free(temp);
    }
    count--;
    printf("Deleted element: %d\n", val);
}

// Function to display the list
void display() {
    if (head == NULL) {
        printf("CLL is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Elements in CLL are: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, n, x, pos;
    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1: scanf("%d", &n); create(n); break;
            case 2: scanf("%d %d", &x, &pos); insert(x, pos); break;
            case 3: scanf("%d", &pos); deleteNode(pos); break;
            case 4: display(); break;
            default: exit(0);
        }
    }
    return 0;
}
