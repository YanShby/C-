//
//  main.c
//  Fibonacci
//
//  Created by Yans on 7/13/16.
//  Copyright © 2016 Yans. All rights reserved.
//

#include <stdio.h>
/**
    斐波那契数列
    
    f(n) = 0, n=0;
         = 1, n=1;
         = f(n-1)+f(n-2), n>2;
 */
long long Fibonacci(unsigned n) {
    int result[2] = {0,1};
    if (n < 2) {
        return result[n];
    }
    long long NumberF0 = 0;
    long long NumberF1 = 1;
    long long Sum = 0;
    /**
        f0 + f1 = f2
        f1 + f2 = f3
        f2 + f3 = f4...
     */
    for (unsigned int i = 2; i <= n; i++) {
        Sum = NumberF0 + NumberF1;
        NumberF0 = NumberF1;
        NumberF1 = Sum;
    }
    return Sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, Fibonacci!\n");
    printf("%lld\n",Fibonacci(10));
    return 0;
}
