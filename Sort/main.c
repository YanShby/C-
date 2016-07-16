//
//  main.c
//  Sort
//
//  Created by Yans on 16/6/5.
//  Copyright © 2016年 Yans. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 1.直接插入排序（稳定）
 接插入排序的过程为：
 在插入第i个记录时，R1,R2,..Ri-1已经排好序，
 将第i个记录的排序码Ki依次和R1,R2,..,Ri-1的排序码逐个进行比较，找到适当的位置。
 使用直接插入排序，对于具有n个记录的文件，要进行n-1趟排序。
*/
void directSort(int a[], int length) {
    int i,j,t;
    for (i = 1; i < length; i++) {
        t = a[i];
        j = i - 1;
        while (a[j] > t) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = t;
    }
}

/**
 2.希尔排序（不稳定）
 希尔(Shell)排序的基本思想是：
 先取一个小于n的整数d1作为第一个增量把文件的全部记录分成d1个组。
 所有距离为d1的倍数的记录放在同一个组中。先在各组内进行直接插入排序；
 然后，取得第二个增量d2<d1重复上述的分组和排序，直至所取的增量di=1，即所有记录放在同一组中进行直接插入排序为止。
 该方法实质上是一种分组插入方法。
 一般取d1=n/2，di+1=di/2。如果结果为偶数，则加1，保证di为奇数。
 希尔排序是不稳定的，希尔排序的执行时间依赖于增量序列，其平均时间复杂度为O(n^1.3).
 */
void shellSort(int a[], int length) {
    int i,j,delta,t;
    //保证增量delta为奇数。
    (delta/2)%2 == 0 ? delta = delta/2 + 1 : delta/2;
    while (delta > 0) {
        for (j = delta; j < length; j++) {
            t = a[j];
            i = j - delta;
            while (i >= 0 && a[i] > t) {
                a[i+delta] = a[i];
                i = i - delta;
            }
            a[i+delta] = t;
        }
        if (delta == 1) break;
        else
            (delta/2)%2 == 0 ? delta = delta/2 + 1 : delta/2;
    }
}

/**
 3.冒泡排序（稳定）
 冒泡排序将被排序的记录数组R[1..n]垂直排列，每个记录R[i]看作是重量为ki的气泡。
 根据轻气泡不能在重气泡之下的原则，从下往上扫描数组R；
 凡扫描到违反本原则的轻气泡，就使其向上"漂浮"。如此反复进行，直到最后任何两个气泡都是轻者在上，重者在下为止。
 */
void bubbleSort(int a[], int length) {
    int i,j,t;
    for (i = 1; i < length; i++) {
        for (j = 0; j < length - i; j++) {
            if (a[j] > a[j+1]) {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

/**
 4.快速排序（不稳定）
 快速排序采用了一种分治的策略，通常称其为分治法，其基本思想是：
 将原问题分解为若干个规模更小但结构与原问题相似的子问题。递归地解这些子问题，然后将这些子问题的解组合为原问题的解。
 快速排序的具体过程如下：
 第一步，在待排序的n个记录中任取一个记录，以该记录的排序码为准，将所有记录分成两组，
 第1组各记录的排序码都小于等于该排序码，
 第2组各记录的排序码都大于该排序码，并把该记录排在这两组中间。
 第二步，采用同样的方法，对左边的组和右边的组进行排序，直到所有记录都排到相应的位置为止。
 */
int *QKPass(int a[], int *low, int *high) {
    int key = *low;
    while (low < high) {
        while (*high > key) {
            high --;
        }
        if (low < high) {
            *low = *high;
            *high = key;
            low ++;
        }
        while (*low < key) {
            low ++;
        }
        if (low < high) {
            *high = *low;
            *low = key;
            high --;
        }

    }
    return low;
}

void QKSort(int a[], int *low, int *high) {
    if (low < high) {
        int *pos = QKPass(a, low, high);
        QKSort(a,low,pos - 1);
        QKSort(a,pos + 1,high);
    }
}

/**
 5.选择排序（不稳定）
 直接选择排序的过程是：首先在所有记录中选出序码最小的记录，把它与第1个记录交换，
 然后在其余的记录内选出排序码最小的记录，与第2个记录交换......依次类推，直到所有记录排完为止。
*/
void selectSort(int a[], int length) {
    int t;
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (a[j] < a[i]) {
                t = a[j];
                a[j] = a[i];
                a[i] = t;
            }
        }
    }
}

/**
 6.堆排序（不稳定）
 堆排序是一种树形选择排序，是对直接选择排序的有效改进。n个关键字序列K1,K2,...,Kn称为堆，
 当且仅当该序列满足(Ki<=K2i且Ki<=K2i+1)或(Ki>=K2i且Ki>=K2i+1),(1<=i<=n/2)。
 根结点(堆顶)的关键字是堆里所有结点关键字中最小者，称为小根堆（最小堆）；
 根结点的关键字是堆里所有结点关键字中最大者，称为大根堆（最大堆）。
 
 步骤：
 一是如何建立初始堆。
 二是当堆的根结点与堆的最后一个结点交换后，如何对少了一个结点后的结点序列做调整，使之重新成为堆。
*/
void heapAdjust(int a[], int root, int heapSize) {
    int left = 2*root + 1;
    int right = 2*root + 2;
    int min = root; //min标记最小元素的位置（求最小堆）
    if (root <= heapSize/2) {
        if (left <= heapSize && a[left] < a[min]) {
            min = left;
        }
        if (right <= heapSize && a[right] < a[min]) {
            min = right;
        }
        if (min != root) {
            int temp = a[min];
            a[min] = a[root];
            a[root] = temp;
            heapAdjust(a, min, heapSize); //为了避免调整之后以min为父节点的子树不成堆
        }
    }
}
void bulidHeap(int a[], int length) {
    int root;
    int heapSize = length - 1;
    for ((heapSize%2 == 0 ? root = (heapSize-1)/2 : heapSize/2); root >= 0; root--) {
        heapAdjust(a, root, heapSize);
    }
}
void heapSort(int a[], int length) {
    int i;
    bulidHeap(a, length);
    for (i = length-1; i >= 0; i--) {
        printf("%d ",a[0]);
        a[0] = a[i];
        heapAdjust(a, 0, i-1);
    }
}

/**
 7.归并排序（稳定）
*/
//void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex) {
//    int i = startIndex, j = midIndex+1, k = startIndex;
//    while (i != midIndex+1 && j != endIndex+1) {
//        if (sourceArr[i] >= sourceArr[j]) {
//            tempArr[k++] = sourceArr[j++];
//        }
//        else
//            tempArr[k++] = sourceArr[i++];
//    }
//    while (i != midIndex+1) {
//        tempArr[k++] = sourceArr[i++];
//    }
//    while (j != endIndex+1) {
//        tempArr[k++] = sourceArr[j++];
//    }
//    for (i = startIndex; i <= endIndex; i++) {
//        sourceArr[i] = tempArr[i];
//    }
//}
void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex) {
    int low = startIndex, high = midIndex+1;
    int i = startIndex;
    while (low <= midIndex && high <= endIndex) {
        if (sourceArr[low] < sourceArr[high]) {
            tempArr[i++] = sourceArr[low++];
        }
        else {
            tempArr[i++] = sourceArr[high++];
        }
    }
    while (low <= midIndex) {
        tempArr[i++] = sourceArr[low++];
    }
    while (high <= endIndex) {
        tempArr[i++] = sourceArr[high++];
    }
    for (i = startIndex; i <= endIndex; i++) {
        sourceArr[i] = tempArr[i];
    }
    
}
void mergeSort(int a[], int t[], int startIndex, int endIndex) {
    int midIndex;
    if (startIndex < endIndex) {
        midIndex = (startIndex + endIndex)/2;
        mergeSort(a, t, startIndex, midIndex);
        mergeSort(a, t, midIndex+1, endIndex);
        Merge(a, t, startIndex, midIndex, endIndex);
    }
}

/**
   基数排序，又名桶子法。
*/
//找到数组中的最大值，这将是获取数组中最高位数的依据。
int findMaxNumber(int a[], int length) {
    int i;
    int max = 0;
    for (i = 0; i <length; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}
//通过最大数字，来计算出它所在最高位是多少，方便获取排序次数。
int getLoopTimes(int num) {
    int count = 1;
    int temp = num/10;
    while (temp != 0) {
        count++;
        temp /= 10;
    }
    return count;
}
//将原数组中的元素放置桶中，其中参数loop传进来，计算出本次通过数字的哪位来进行放置。
void putBuckets(int a[], int length, int loop) {
    //创建一个二维数组当做桶。
    int buckets[10][20] = {};
    //1,10,100...个位，十位，百位...
    int temp = (int)pow(10,loop-1);
    int i,j;
    for (i = 0; i < length; i++) {
        int row = (a[i]/temp) % 10;
        for (j = 0; j < 20; j++) {
            if (buckets[row][j] == NULL) {
                buckets[row][j] = a[i];
                break;
            }
        }
    }
    
    int k = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 20; j++) {
            if (buckets[i][j] != NULL) {
                a[k++] = buckets[i][j];
                buckets[i][j] = NULL;
            }
        }
    }
}
//调用上述方法来进行基数排序。
void bucketSort(int a[], int length) {
    int max = findMaxNumber(a, length);
    int loopTimes = getLoopTimes(max);
    int i;
    for (i = 1; i <= loopTimes; i++) {
        putBuckets(a, length, i);
    }
}
void testBucketSort(int a[], int length) {
    
    bucketSort(a, length);
    int i;
    for (i = 0; i < length; i++) {
        printf("%d ",a[i]);
    }
}

int main(int argc, const char * argv[]) {
    printf("Hello, 快速排序!\n");
    int a[] = {12,43,25,32,03,14,56,20,10,23};
    int length = 10;
    QKSort(a, &a[0], &a[length-1]);
    for (int i = 0; i < length; i++) {
        printf("%d ",a[i]);
    }
    printf("\nHello, 选择排序!\n");
    int b[] = {12,43,25,32,03,14,56,20,10,23};
    selectSort(b, length);
    for (int i = 0; i < length; i++) {
        printf("%d ",b[i]);
    }
    printf("\nHello, 堆排序!\n");
    int c[] = {12,43,25,32,03,14,56,20,10,23};
    int cLength = 10;
    heapSort(c, cLength);
    printf("\nHello, 直接插入排序!\n");
    int d[] = {12,43,25,32,03,14,56,20,10,23};
    directSort(d, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ",d[i]);
    }
    printf("\nHello, 希尔排序!\n");
    int e[] = {12,43,25,32,03,14,56,20,10,23};
    shellSort(e, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ",e[i]);
    }
    printf("\nHello, 冒泡排序!\n");
    int f[] = {12,43,25,32,03,14,56,20,10,23};
    bubbleSort(f, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ",f[i]);
    }
    printf("\nHello, 归并排序!\n");
    int g[] = {12,43,25,32,03,14,56,20,10,23};
    int t[10];
    mergeSort(g, t, 0, 10);
    for (int i = 1; i < 11; i++) {
        printf("%d ",g[i]);
    }
    printf("\nHello, 基数排序!\n");
    int h[] = {12,43,25,32,03,14,56,20,10,23};
    testBucketSort(h,10);
    
    char p[]={'a','b'};char q[10]={'a','b','c'};
    
    printf("\n%lu,%lu\n",strlen(p),strlen(q));
    

    return 0;
}
