//
//  main.c
//  saddle
//
//  Created by Yans on 16/6/1.
//  Copyright © 2016年 Yans. All rights reserved.
//

#include <stdio.h>

/*求saddle鞍点。行上最小，列上最大。*/
/*
    参数说明。
    m：行数 n：列数
    i，j分别为行列索引数。k、p分别保存做小元素所在的行和最大元素所在的列。
    min保存在行上的最小值。
 */
void saddle(int A[][3], int m, int n) {
    int i,j,k = 0,p = 0,min = 0;
    for (i = 0; i < m; i++) {
        min = A[i][0];
        for (j = 1; j < n; j++) {
            if (A[i][j] < min) {
                min = A[i][j];
                k = j;
            }
        }
        while(p < m && A[p][k] < min) {
            p++;
        }
    }
    printf("%d,%d,%d\n",p,k,min);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int array[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    saddle(array, 3, 3);
    
    return 0;
}
