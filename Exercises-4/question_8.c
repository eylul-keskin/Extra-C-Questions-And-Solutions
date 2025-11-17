#include <stdio.h>

void find(int *nums,int size, int **addr) {

    *addr = nums;
    size--;
    nums++;

    while(size > 0) {

        if(*nums > **addr) {
            *addr = nums;
        } 
        nums++;
        size--;
    }
}

int main() {
    int nums[] = {1,2,3,4,5};
    int size = sizeof(nums) / sizeof(nums[0]);
    int *max_addr = NULL;

    find(nums,size, &max_addr);

    if(max_addr != NULL) {
        printf("Dizideki Maksimum Değer: %d\n", *max_addr);
        printf("Maksimum Değerin Adresi: %p\n", (void *)max_addr);
    } else {
        printf("Hata: Dizi Boş Veya Hatalı.\n");
    }
    return 0;
}