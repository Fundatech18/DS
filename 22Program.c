// Online C compiler to run C program online
#include <stdio.h>


void QuickSort(int arr[],int low,int high){
    int i,j,key,flag=1;
    if(low < high){
        
        i =low;
        j = high;
        key=arr[low];
      
        while(flag == 1){
            i=i+1;
            while(arr[i] < key && i <= high){
                i++;
            }
            while(arr[j] > key && j >= low){
                j--;
            }
            
            if(i < j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }else{
                int temp = arr[low];
                arr[low] = arr[j];
                arr[j] = temp;
                flag = 0;
            }
        }
        
        QuickSort(arr,low,j-1);
        QuickSort(arr,j+1,high);
    }
}

int main() {
    int arr[10]={50,100,10,90,20,80,30,70,40,60},limit=10;
    int i;
    int choice;
    
    QuickSort(arr,0,limit-1);
    for(int i=0;i<limit;i++){
        printf("%d   ",arr[i]);
    }
    

}
