//
//  main.c
//  MergeArray
//
//  Created by Yans on 16/5/31.
//  Copyright © 2016年 Yans. All rights reserved.
//

#include <stdio.h>

/*    合并两个排序的数组,其中一个数组容量足够大去容纳另外一个数组,合并完也需要时排序的数组
 *    array1[],array2[]两个整型数组
 *    i,j分别是两个数组的现容量
 *    length是第一个数组的总容量
 */
void MergeArray(int array1[], int array2[], int i, int j, int length) {
    
    if (array1 == NULL || array2 == NULL || length <= 0) {
        return;
    }
    
    int newLength = i + j;
    
    if (newLength > length) {
        return;
    }
    
    int k = newLength - 1;
    i--;j--;
    
    while (i >= 0 && j>= 0 && k >= i) {
        if (array1[i] > array2[j]) {
            array1[k] = array1[i];
            k--;i--;
        }
        else {
            array1[k] = array2[j];
            k--;j--;
        }
    }
    if (i >= 0) {
        while (i >= 0) {
            array1[k--] = array1[i--];
        }
    }
    if (j >= 0) {
        while (j >= 0) {
            array1[k--] = array2[j--];
        }
    }
    
}

int main(int argc, const char * argv[]) {
    
    int array1[20] = {1,2,4,7,10,12};
    int array2[] = {0,5};
    MergeArray(array1, array2, 6, 2, 20);
    for (int i = 0; i <= 7; i++) {
        printf("%4d",array1[i]);
    }
    printf("Hello, World!\n");
    return 0;
}
