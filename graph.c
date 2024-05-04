#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
typedef struct _queue
{
    int* A;
    int front;
    int rear;
    int size;
    int length;
}Queue;
Queue* createQueue(int capacity)
{
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->A=(int*)malloc(sizeof(int)*capacity);
    q->size=capacity;
    q->length=q->front=0;
    q->rear=-1;
    return q;
}
bool isEmpty(Queue* q)
{
    return q->length==0;
}
int dequeue(Queue* q)
{
    if(isEmpty(q))
        return INT_MIN;
    int del=q->A[q->front];
    q->front=(q->front+1)%q->size;
    q->length--;
    return del;
}
bool isFull(Queue* q)
{
    return q->length==q->size;
}
void enqueue(Queue* q,int data)
{
    if(isFull(q))
        return;
    q->rear=(q->rear+1)%q->size;
    q->A[q->rear]=data;
    q->length++;   
}
typedef struct _graph
{
    int v;
    int e;
    bool** adjacencymatrix;
}Graph;

Graph* createGraph(int v)
{
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->v = v;
    g->e=0;
    g->adjacencymatrix=(bool**)malloc(sizeof(bool*)*v);
    for(int i=0;i<v;i++)
    {
        g->adjacencymatrix[i] = (bool*)calloc( sizeof(bool),v);
    }
    return g;
}
void addEdge(Graph* g, int v1, int v2)
{
    g->adjacencymatrix[v1][v2]=true;
    g->adjacencymatrix[v2][v1]=true;
    g->e++;
}
void bfs(Graph* g)
{
    //This is a Breadth First Search algorithm. It uses Queue data structure to keep track of the vertices that are yet to be visited
    Queue* q=createQueue(g->v);
    bool visited[g->v];
    for(int i=0;i<g->v;i++)
    {
        visited[i]=false;
    }
    enqueue(q,0);
    visited[0]=true;
    int v=dequeue(q);
    while(!isEmpty(q))
    {
        printf("%d ",v);
        for(int i=0;i<g->v;i++)
        {
            if(g->adjacencymatrix[v][i]==true && !visited[i])
            {
                enqueue(q,i);
                visited[i]=true;
            }
        }
    }
} 
int main()
{
    Graph* g=createGraph(5);
    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 2, 3);
    addEdge(g, 1, 4);
    addEdge(g, 3, 4);
    bfs(g);

}