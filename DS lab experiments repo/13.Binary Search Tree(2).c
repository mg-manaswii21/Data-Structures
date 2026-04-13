#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return createNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (root->data < data)
        return search(root->right, data);
    return search(root->left, data);
}

void processOperations(struct Node* root, int op, int val) {
    if (op == 1) {
        if (search(root, val) == NULL) {
            root = insert(root, val);
        }
    } else if (op == 2) {
        if (search(root, val) != NULL) {
            root = deleteNode(root, val);
        }
    } else if (op == 3) {
        if (search(root, val) != NULL) {
            printf("found\n");
        } else {
            printf("not found\n");
        }
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int N, op, val;

    if (scanf("%d", &N) != 1) return 1;

    for (int i = 0; i < N; i++) {
        if (scanf("%d %d", &op, &val) != 2) return 1;
        if (op == 1) {
            if (search(root, val) == NULL) {
                root = insert(root, val);
            }
        } else if (op == 2) {
            if (search(root, val) != NULL) {
                root = deleteNode(root, val);
            }
        } else if (op == 3) {
            if (search(root, val) != NULL) {
                printf("found\n");
            } else {
                printf("not found\n");
            }
        }
    }

    inorder(root);
    printf("\n");

    return 0;
}