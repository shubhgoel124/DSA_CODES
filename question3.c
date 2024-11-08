//implement radix sort algorithm using arrays in todays question
#include<stdio.h>

int getmax(int arr[], int n){
    int max = arr[0];
    for(int i =1 ; i< n ; i++ ){
        if (arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[n]; 
    int count[10] = {0}; 

 
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
   
    int max = getmax(arr, n);

   
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}


void printarray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n; 
    printf("enter the number of numbers in array");
    scanf("%d",&n);
    int arr[n];
    for(int i =0; i< n ; i++){
        scanf("%d", &arr[i]);
    }

    printf("Original array: \n");
    printarray(arr, n);

    radixSort(arr, n);

    printf("Sorted array: \n");
    printarray(arr, n);
    return 0;
}
