//
//  main.c
//  FindNumberAtMartix
//
//  Created by Yans on 16/5/30.
//  Copyright © 2016年 Yans. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>


bool Find(int *Martix, int rows, int columns, int number) {
    bool found = false;
    if (Martix != NULL && rows > 0 && columns >0) {
        //从数组的右上角开始查找
        int row = 0;
        int column = columns - 1;
        
        while (row < rows && column >= 0) {
            if (Martix[row * columns + column] == number) {
                found = true;
                break;
            }
            else if (Martix[row * columns + column] > number) {
                -- column;
            }
            else {
                ++ row;
            }
        }
        //从数组的左下角开始查找
//        int row = rows - 1;
//        int column = 0;
//        while (row < rows && column >= 0) {
//            if (Martix[row * columns + column] == number) {
//                found = true;
//                break;
//            }
//            else if (Martix[row * columns + column] < number) {
//                ++ column;
//            }
//            else {
//                -- row;
//            }
//        }
    }
    
    return found;
}

void Test(char* testName, int* matrix, int rows, int columns, int number, bool expected)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);
    
    bool result = Find(matrix, rows, columns, number);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

/*    
 *     1   2   8   9
 *
 *     4   7   10  13
 *
 *     6   8   11  15
 **/

void Test1()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test1", (int*)matrix, 4, 4, 7, true);
}

int main(int argc, const char * argv[]) {
    
    Test1();
    return 0;
}
