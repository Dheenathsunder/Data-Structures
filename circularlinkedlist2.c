#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) {
        printf("Memory error\n");
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void insert(struct Node** head, int data) {
    struct Node* nd = createNode(data);
    if (*head == NULL) {
        *head = nd;
        nd->next = *head;  // Circular link
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = nd;
        nd->next = *head;  // Circular link
    }
}

void deleteNode(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prevNode = NULL;

    // Handle the case for deleting the first node at position 0
    if (pos == 0) {
        while (current->next != *head) {
            current = current->next;
        }
        *head = (*head)->next;
        current->next = *head;  // Update the circular link
        free(current);
        return;
    }

    int i = 0;
    do {
        prevNode = current;
        current = current->next;
        i++;
    } while (current != *head && i < pos);

    if (i != pos) {
        printf("\nPosition not found in the list\n");
        return;
    }

    prevNode->next = current->next;
    free(current);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* curr = head;
    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("Circular\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);

    // Display the circular linked list
    printf("Circular Linked List: ");
    display(head);

    // Delete a node at position 1 (0-based indexing)
    int pos_to_delete = 1;
    printf("Deleting node at position %d\n", pos_to_delete);
    deleteNode(&head, pos_to_delete);

    // Display the circular linked list after deletion
    printf("Circular Linked List after deletion: ");
    display(head);

    return 0;
}
