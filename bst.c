#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node {
    int data;
    struct _node* left;
    struct _node* right;
} Node;

typedef struct _bst {
    Node* root;
    int len;
} BST;

Node* createNode(int val) {
    Node* nd = (Node*)malloc(sizeof(Node));
    nd->data = val;
    nd->left = nd->right = NULL;
    return nd;
}

BST* createBST() {
    BST* b = (BST*)malloc(sizeof(BST));
    b->root = NULL;
    b->len = 0;
    return b;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    else if (data < root->data)
        root->left = insertNode(root->left, data);
    return root;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL)
        return root;
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else if (data < root->data)
        root->left = deleteNode(root->left, data);
    else {
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        else {
            Node* succParent = root;
            Node* succ = root->right;
            while (succ != NULL && succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }
            root->data = succ->data;
            if (succParent != root)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;
        }
    }
    return root;
}

bool search(Node* root, int data) {
    if (root == NULL)
        return false;
    else if (data > root->data)
        return search(root->right, data);
    else if (data < root->data)
        return search(root->left, data);
    else
        return true;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    // Create a BST
    BST* myBST = createBST();

    // Insert nodes into the BST
    myBST->root = insertNode(myBST->root, 50);
    myBST->root = insertNode(myBST->root, 30);
    myBST->root = insertNode(myBST->root, 70);
    myBST->root = insertNode(myBST->root, 20);
    myBST->root = insertNode(myBST->root, 40);
    myBST->root = insertNode(myBST->root, 60);
    myBST->root = insertNode(myBST->root, 80);

    // Print the inorder traversal of the BST
    printf("Inorder Traversal: ");
    inorder(myBST->root);
    printf("\n");

    return 0;
}
