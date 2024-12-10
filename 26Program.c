// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}

void insertSort(struct Node **head,int arr){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = arr;
    newNode->next = NULL;
    
    if(*head == NULL || (*head)->data >= arr){
        newNode->next = *head;
        *head = newNode;
    }else{
        struct Node *temp = *head;
        while(temp->next != NULL && temp->next->data < arr){
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


void addressSort(int arr[],int n){
    struct Node *bucket[10] = {NULL};
    for(int i=0;i<n;i++){
        int digit = arr[i]/10;
        insertSort(&bucket[digit],arr[i]);
    }
    int index = -1;
    for(int i=0;i<10;i++){
        struct Node *temp = bucket[i];
        while(temp != NULL){
            arr[++index] = temp->data;
            temp = temp->next;
        }
    }
}

int main() {
    int arr[] = {50,25,90,14,55,36,77,88,41,51,61};
    int size = sizeof(arr)/sizeof(arr[0]);
    addressSort(arr,size);
    printArray(arr,size);
    return 0;
}
