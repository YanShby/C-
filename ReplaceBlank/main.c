//
//  main.c
//  ReplaceBlank
//
//  Created by Yans on 16/5/30.
//  Copyright © 2016年 Yans. All rights reserved.
//

#include <stdio.h>
/*  给出一个字符串,将其中的空格替换成%20;
 *
 *
 */

void ReplaceBlank(char String[], int Length) {
    
    if (String == NULL && Length <= 0) {
        return;
    }
    
    int originLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    
    while (String[i] != '\0') {
        ++originLength;
        if (String[i] == ' ') {
            ++numberOfBlank;
        }
        ++i;
    }
    
    int newLength = originLength + numberOfBlank * 2;
    if (newLength > Length) {
        return;
    }
    
    int indexOfNew = newLength;
    int indexOfOrigin = originLength;
    while (indexOfOrigin >= 0 && indexOfNew > indexOfOrigin) {
        if (String[indexOfOrigin] == ' ') {
            String[indexOfNew--] = '0';
            String[indexOfNew--] = '2';
            String[indexOfNew--] = '%';
        }
        else {
            String[indexOfNew--] = String[indexOfOrigin];
        }
        --indexOfOrigin;
    }
    
}


int main(int argc, const char * argv[]) {
    
    int length = 20;
    char String[20] = "    ";
    ReplaceBlank(String, length);
    for (int i = 0; i < 12; i++) {
        printf("%c",String[i]);
    }
    printf("\n");
    return 0;
}
