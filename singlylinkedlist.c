#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node* createNode(int data)
{
    struct Node* nd=(struct Node*)malloc(sizeof(struct Node));
    if(nd==NULL)
        printf("Failed");
    nd->data=data;
    nd->next=NULL;
    return nd;
}
void insertNode(struct Node** head,int data)
{
    struct Node* nd=createNode(data);
    if(*head == NULL)
        *head=nd;
    else{
        struct Node* curr=*head;
        while(curr->next!=NULL){
            curr=curr->next;
    }
    curr->next=nd;
    }
    printf("Inserted in %d",data);
}
void deleteNode(struct Node** head,int pos)
{
    if(*head==NULL){
        printf("List is empty");
        return ;
    }
    if(pos==0)
    {
        struct Node* temp=*head;
        *head=(*head)->next;
        free(temp);
        printf("Node deleted");
        return ;
    }
    struct Node* curr=*head;
    int i=0;
    while(i<pos-1 && curr!=NULL)
    {
        curr=curr->next;
        i++;
    }
    if(curr==NULL || curr->next==NULL)
    {
        printf("Invalid pos");
        return;
    }
    struct Node* nxt=curr->next;
    curr->next=nxt->next;
    free(nxt);
    printf("Deleted the node at position %d",pos);
}
void displayList(struct Node* head)
{
    if(head==NULL){
        printf("List is empty");
        return;
    }
    struct Node* curr=head;
    printf("The elements are:");
    while(curr!=NULL)
    {
        printf("%d ",curr->data);
        curr=curr->next;
    }

}
int main()
{
    struct Node* head = NULL;

    // Testing createNode and insertNode
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);

    // Testing displayList
    displayList(head);
    printf("\n");

    // Testing deleteNode at position 1
    deleteNode(&head, 1);
    
    // Testing displayList after deletion
    displayList(head);
    printf("\n");

    // Testing deleteNode at position 0
    deleteNode(&head, 0);

    // Testing displayList after another deletion
    displayList(head);
    printf("\n");

    // Testing deleteNode at invalid position
    deleteNode(&head, 2);

    // Testing displayList after an invalid deletion
    displayList(head);
    printf("\n");

    return 0;
}
