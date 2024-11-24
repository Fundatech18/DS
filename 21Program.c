// Online C compiler to run C program online
#include <stdio.h>


void merge(int a[],int low,int mid,int high){
    int l1 = low,l2 = mid+1;
    int i=low;
    int b[high+1];
    
    while(l1 <= mid && l2 <= high){
        if(a[l1] <=  a[l2]){
            b[i] = a[l1];
            l1++;
        }else {
            b[i] = a[l2];
            l2++;
        }
        i++;
    }
    
    while(l1 <= mid){
        b[i] = a[l1];
            l1++;
            i++;
    }
    
    while(l2 <= high){
         b[i] = a[l2];
            i++;
            l2++;
            
    }
    
    
    for(int i=low;i<=high;i++){
        a[i] = b[i];
    }
}



void mergeSort(int arr[],int low,int high){
    int mid;
    if(low < high){
        mid = (low+high) / 2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main() {
    int arr[10]={50,100,10,90,20,80,30,70,40,60},limit=10;
    int i;
    int choice;
    
    mergeSort(arr,0,limit-1);
    for(int i=0;i<limit;i++){
        printf("%d   ",arr[i]);
    }
    

}
