#include<stdio.h>
#define MAX 5


void insertRear(int queue[],int *rear,int *front,int element){
    if((*rear == MAX-1 && *front == 0) || *front == *rear+1){
        printf("Queue is Full");
    }else{
        if(*rear == -1){
            *rear = *front = 0;
        }else if(*rear == MAX-1){
            *rear = 0;
        }else{
            *rear += 1;
        }
        
        queue[*rear] = element;
    }
}

void insertFront(int queue[],int *rear,int *front, int element){
    if((*rear == MAX-1 && *front == 0) || *front == *rear+1 ){
        printf("Queue is full");
    }else{
        if(*front == -1){
            *front = *rear =0;
        }else if(*front == 0){
            *front = MAX-1;
        }else{
            *front-=1;
        }
        
        queue[*front] = element;
    }
}

void deleteFront(int queue[],int *rear,int *front){
    if(*front == -1){
        printf("queue is empty");
    }else{
        queue[*front] = 0;
        if(*front == *rear){
            *front = *rear = -1;
        }else if(*front == MAX-1){
            *front = 0;
        }else{
            *front += 1;
        }
    }
}

void deleteRear(int queue[],int *rear,int *front){
    if(*front == -1){
        printf("Queue is empty");
    }else{
        queue[*rear] = 0;
        if(*rear == *front){
            *front = *rear = -1;
        }else if(*rear == 0){
            *rear = MAX-1;
        }else{
            *rear-=1;
        }
    }
}

void display(int queue[]){
    for(int i=0;i<MAX;i++){
        printf("%d  ",queue[i]);
    }
}

void main(){
    int choice,element,queue[MAX],r=-1,f=-1,*rear = &r,*front = &f;
    
    while(1){
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Modify\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &element);
                insertFront(queue,rear,front,element);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &element);
                insertRear(queue,rear,front,element);
                break;
                
            case 3:
                deleteFront(queue,rear,front);
                break;
            case 4:
                deleteRear(queue,rear,front);
                break;
                
            case 6:
                display(queue);
                break;
        }
    }
}
