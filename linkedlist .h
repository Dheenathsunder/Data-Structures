#include<stdio.h>
#include<stdbool.h>
typedef struct _node
{
    int data;
    struct _node* next;
} Node;

typedef struct _linkedlist
{
  Node* headNode;
  Node* lastNode;
  int len;
}LinkedList;
LinkedList*  createLinkedList()
{
    LinkedList* LL=(LinkedList*)malloc(sizeof(LinkedList));
    LL->headNode=LL->lastNode=NULL;
    LL->len=0;
    return LL;
}
Node* createNode(int data)
{
    Node* nd=(Node*)malloc(sizeof(Node));
    nd->data=data;
    nd->next=NULL;
    return nd;
    
}
bool isLLEmpty(LinkedList* LL)
{
    return LL->headNode==NULL;
}
void insertNewNodeInLL(LinkedList* LL, int data)
{
    Node* nd=createNode(data);
    if(isLLEmpty(LL))
    {
        LL->headNode=LL->lastNode=nd;
    }
    else
    {
        LL->lastNode->next=nd;
        LL->lastNode=nd;
    }
    LL->len++;
}
void displayLL(LinkedList* LL)
{
    Node* temp=LL->headNode;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void extendList(LinkedList* LL1, LinkedList* LL2)
{
    Node* temp=LL2->headNode;
    while(temp!=NULL)
    {
        insertNewNodeInLL(LL1,temp->data);
        temp=temp->next;
    }
}
void insertNodeAtPos(LinkedList* LL, int data, int pos) 
{
    if(pos<0 || pos>LL->len)
    {
        return;
    }
    Node* temp=LL->headNode;
    Node* nd=createNode(data);
    if(isLLEmpty(LL))
    {
        insertNewNodeInLL(LL,data);
        return;
    }
    if(pos==0)
    {
        nd->next=temp;
        LL->headNode=nd;
    }
    else
    {
        for(int i=1;i<=pos-1;i++)
        {
            temp=temp->next;
        }
        nd->next=temp->next;
        temp->next=nd;
    }
    if(pos==LL->len)
        LL->lastNode=nd;
    LL->len++;
}
void insertNodeInSortedLL(LinkedList* LL, int data) 
{
    Node* temp=LL->headNode;
    int pos=0;
    while(temp!=NULL && data>temp->data)
    {
        temp=temp->next;
        pos+=1;
    }
    insertNodeAtPos(LL,data,pos);
}