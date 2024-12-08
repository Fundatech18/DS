// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Graph{
    int noOfVertexes;
    struct Node **adjList;
};

struct Graph *createGraph(int noOfVertex){
    struct Graph *newGraph = (struct Graph *)malloc(sizeof(struct Graph));
    newGraph->noOfVertexes = noOfVertex;
    
    newGraph->adjList = (struct Node **)malloc(noOfVertex * sizeof(struct Node));
    
    for(int i=0;i<noOfVertex;i++){
        newGraph->adjList[i] = NULL;
    }
    return newGraph;
}


struct Node *createNode(int element){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;
    return newNode;
}


void addEdge(struct Graph *graph,int src,int dest){
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    
    // newNode = createNode(src);
    // newNode->next = graph->adjList[dest];
    // graph->adjList[dest] = newNode;
}


void print(struct Graph *graph){
    for(int i=0;i<graph->noOfVertexes;i++){
        printf("Vertex %d -- ",i);
        struct Node *temp = graph->adjList[i];
        while(temp){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    
    }
}


int checkVisited(int arr[],int top,int element){
    if(top == -1){
        return 0;
    }
    for(int i=0;i<=top;i++){
        if(arr[i] == element){
            return 1;
        }
    }
    return 0;
}

int checkVisitedInQueue(int arr[],int front,int rear,int element){
    if(front == -1){
        return 0;
    }
    for(int i=front;i<=rear;i++){
        if(arr[i] == element){
            return 1;
        }
    }
    return 0;
}


void BFS(struct Graph *graph,int startPoint){
    int queue[100], front=-1, rear = -1, visited[100],visitedTop = -1;
    queue[++rear] = startPoint;
    front=0;
    while(front != -1){
        int x = queue[front];
        visited[++visitedTop] = x;
        if(front == rear){
            front = rear = -1;
        }else if(rear == 0){
            front = 0;
        }else{
            front += 1;
        }
        printf("%d  ",x);
        struct Node *temp = graph->adjList[x];
        while(temp){
            
            if(!checkVisited(visited,visitedTop,temp->data) && !checkVisitedInQueue(queue,front,rear,temp->data)){
                
                queue[++rear] = temp->data;
                if(rear == 0 && front == -1){
                    front = 0;
                }
                // printf("%d - %d - %d \n",temp->data,front,rear);
            }
            temp = temp->next;
        }
    }
    
    
}

void DFS(struct Graph *graph,int startPoint){
    int stack[100],visited[100],stackTop=-1,visitedTop=-1,LowPoint=0;
    stack[++stackTop] = startPoint;
    while(stackTop != -1){
        int x = stack[stackTop--];
        visited[++visitedTop] = x;
        printf("%d  ",x);
        struct Node *temp = graph->adjList[x];
        while(temp){
            if(!(checkVisited(visited,visitedTop,temp->data)) && !(checkVisited(stack,stackTop,temp->data))){
                stack[++stackTop] = temp->data;
            }
            temp = temp->next;
        }
        
    }
}


int main() {
    struct Graph *graph = createGraph(5);
    addEdge(graph,0,3);
    addEdge(graph,0,2);
    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,2,4);
    
    print(graph);
    printf("DFS : " );
    DFS(graph,0);
    printf("\nBFS : ");
    BFS(graph,0);
}
