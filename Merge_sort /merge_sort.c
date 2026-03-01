
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[100];
int n;

void shuffle(int arr[],int n){
    int i, j , temp;
 	
    for (i = 0; i < n; i++){
        arr[i] = i + 1;
    }

    for(i = n - 1; i > 0; i--){
        j = rand() % (i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void merge(int arr[], int l, int m, int r){
    
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
}


}

void mergeSort(int arr[], int l, int r){
    
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
void printarr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    printf("Nhap so phan tu n (<=100): ");
    do {
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("Gia tri n khong hop le\n");
        }
    } while (n <= 0 || n > 100);

    shuffle(arr, n);
    printarr(arr, n);
    printf("\n");
    mergeSort(arr, 0, n - 1);
    printarr(arr, n);
    return 0;
}
