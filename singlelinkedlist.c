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
    struct Node* new_node = createNode(data);
    if (!*head) {
        *head = new_node;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void deleteNode(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    } else if (pos == 0) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node* current = *head;
    int i = 0;
    while (current != NULL && i < pos - 1) {
        current = current->next;
        i++;
    }
    if (i == pos - 1) {
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);

    // Display the linked list
    printf("Linked List: ");
    display(head);

    // Delete a node at position 1 (0-based indexing)
    int pos_to_delete = 1;
    printf("Deleting node at position %d\n", pos_to_delete);
    deleteNode(&head, pos_to_delete);

    // Display the linked list after deletion
    printf("Linked List after deletion: ");
    display(head);

    // Free allocated memory
    //while (head != NULL) {
        //struct Node* temp = head;
        //head = head->next;
        //free(temp);
    //}

    return 0;
}
