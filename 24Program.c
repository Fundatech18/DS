// Online C compiler to run C program online
#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    
    if(largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr,n,largest);
    }
}


void heapSort(int arr[],int n){
    for(int i = n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    
    for(int i = n-1;i>0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

int main() {
    int arr[] = {50,10,25,18,100,29};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    heapSort(arr,size);
    
    printArray(arr,size);

    return 0;
}
