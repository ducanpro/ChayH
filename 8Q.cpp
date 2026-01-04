#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

int a[9];
int count = 0;

// void inketqua(int pos[]){
//     printf("Ket qua %d: ", count++);
//     for(int i = 1; i <= 8;i++){
//         printf("%d",pos[i]);
//     }
//     printf("\n");
// }
void inketqua(int pos[]) {
    printf("\nPhuong an %d:\n", ++count);
    printf("-----------------\n"); 
    for (int hang = 1; hang <= 8; hang++) {
        printf("|"); // Canh trai
        for (int cot = 1; cot <= 8; cot++) {
            if (pos[cot] == hang) {
                printf("Q|"); // // In quan hau
            } else {
                printf(".|"); //canh phai
            }
        }
        printf("\n-----------------\n"); // 
    }
    printf("Nhan Enter de xem tiep...");
    getchar(); // Dung man hinh de ban kip quan sat
}

int check(int hang,int cot, int pos[]){
    //kiem tra trung hang pos[i] == hang
    //kiem tra trung duong cheo abs(pos[i] - hang) == abs(i - cot)
    //abs tri tuyet doi
    for(int i = 1; i < cot; i++){
        if(pos[i] == hang || abs(pos[i] - hang) == abs(i - cot)){
            return 0;
        }
    }
    return 1;
}

void giaihau(int cot, int pos[]){
    for(int hang = 1; hang <= 8;hang++){
        if(check(hang, cot, pos)){
            pos[cot] = hang;// dat hau

            if(cot == 8){
                inketqua(pos);
            } else {
                giaihau(cot + 1, pos);
            }
        }
    }
}



int main(){
    giaihau(1, a);
    printf("tong cong co %d cach xep", count);
    return 0;
}