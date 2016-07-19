//
//  main.c
//  ReorderOddEven
//
//  Created by Yans on 16/7/19.
//  Copyright © 2016年 Yans. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 *      Reorder(int *a, int length, bool (*func)(int)) 实现特定排序。
 */
void Reorder(int *a, int length, bool (*func)(int)) {
    if (length <= 0 || a == NULL) {
        return;
    }
    
    int *start = a;
    int *end = a + length - 1;
    
    while (start < end) {
        
        while (start < end && !func(*start)) {
            start++;
        }
        
        while (start < end && func(*end)) {
            end--;
        }
        
        if (start < end) {
            int temp = *start;
            *start = *end;
            *end = temp;
        }
    }
    
}
/**
 *      isEven实现奇数在偶数前面
 */
bool isEven(int n) {
    //(n & 0x1) == 0   -----   判断偶数条件
    //(n & 0x1) != 0   -----   判断奇数条件
    return (n & 0x1) == 0;
}
/**
 *      isPositive实现负数在正数前面
 */
bool isPositive(int n) {
    return n > 0;
}
/**
 *      isDevide3实现不被3整除在前面，被3整除在后面
 */
bool isDevide3(int n) {
    return n % 3 == 0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, ReorderOddEven!\n");
    int a[] = {2,4,3,5,9,-2,-5,20};
    int length = 8;
    Reorder(a, length, isDevide3);
    for (int i = 0; i < length; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    Reorder(a, length, isPositive);
    for (int i = 0; i < length; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    Reorder(a, length, isEven);
    for (int i = 0; i < length; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    
    return 0;
}
