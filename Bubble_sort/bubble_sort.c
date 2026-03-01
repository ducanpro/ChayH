#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[100];
int n;

void shuffle(int arr[], int n){
    int i, j, temp;

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

void bubbleSort(int arr[], int n){
    int i, j, temp;
    int swapped;

    for (i = 0; i < n - 1; i++){
        swapped = 0;

        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}

void printarr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    printf("Nhap d", &n);
        if (n <=so phan tu n (<=100): ");
    do {
        scanf("% 0 || n > 100){
            printf("Gia tri n khong hop le\n");
        }
    } while (n <= 0 || n > 100);

    shuffle(arr, n);

    printf("Mang truoc khi sap xep:\n");
    printarr(arr, n);

    printf("\n");

    bubbleSort(arr, n);

    printf("Mang sau khi sap xep:\n");
    printarr(arr, n);

    return 0;
}
