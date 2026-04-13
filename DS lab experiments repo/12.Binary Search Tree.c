#include <stdio.h>
#include <stdlib.h>

// Structure for BST Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Option 1: Insert Node
// Note: Per instructions, duplicates are inserted into the right subtree.
struct Node* Insert(struct Node* node, int value) {
    if (node == NULL) return newNode(value);

    if (value < node->data)
        node->left = Insert(node->left, value);
    else // value >= node->data (Duplicates go right)
        node->right = Insert(node->right, value);

    return node;
}

// Option 2: In-order Traversal (Left, Root, Right)
void Inorder(struct Node* root) {
    if (root != NULL) {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

// Option 3: Pre-order Traversal (Root, Left, Right)
void Preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

// Option 4: Post-order Traversal (Left, Right, Root)
void Postorder(struct Node* root) {
    if (root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ", root->data);
    }
}

// Helper: Find the node with the minimum value (for deletion)
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Option 5: Delete Node
struct Node* Delete(struct Node* root, int value) {
    if (root == NULL) return root;

    if (value < root->data)
        root->left = Delete(root->left, value);
    else if (value > root->data)
        root->right = Delete(root->right, value);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, val;

    while (1) {
        printf("\nMenu Options:\n");
        printf("1. Insert Node\n2. In-order Traversal\n3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n5. Delete Node\n6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Data: ");
                scanf("%d", &val);
                root = Insert(root, val);
                break;
            case 2:
                if (root == NULL) printf("Tree is empty.");
                else Inorder(root);
                printf("\n");
                break;
            case 3:
                if (root == NULL) printf("Tree is empty.");
                else Preorder(root);
                printf("\n");
                break;
            case 4:
                if (root == NULL) printf("Tree is empty.");
                else Postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = Delete(root, val);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
