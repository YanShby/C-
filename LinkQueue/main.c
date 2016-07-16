//
//  main.c
//  LinkQueue
//
//  Created by Yans on 16/5/30.
//  Copyright © 2016年 Yans. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node {
   
    datatype data;
    struct node *next;
}LinkQueueNode;

typedef struct {
    
    LinkQueueNode *front, *rear;
}LinkQueue;

//初始化
LinkQueue *initLinkQueue() {
   
    LinkQueue *lq;
    LinkQueueNode *node;
    lq = (LinkQueue *)malloc(sizeof(LinkQueue));
    node = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    
    node->next = NULL;
    lq->rear = lq->front = node;
    
    return lq;
}

//判断空
int isEmpty(LinkQueue *lq) {
    if (lq->front == lq->rear) {
        printf("LinkQueue is empty!\n");
        return 1;
    }
    else {
        return 0;
    }
}

//入队
LinkQueue *inLinkQueue(LinkQueue *lq, datatype data) {
   
    LinkQueueNode *node;
    node = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    node->data = data;
    node->next = NULL;
    lq->rear->next = node;
    lq->rear = node;
    printf("%d in LinkQueue!\n",data);
    return lq;
}

//出队
LinkQueue *outLinkQueue(LinkQueue *lq) {
    
    if (isEmpty(lq)) {
        return lq;
    }
    else {
        LinkQueueNode *node;
        node = lq->front->next;
        lq->front->next = node->next;
        printf("%d out LinkQueue!\n",node->data);
        free(node);
        if (lq->front == NULL) {
            lq->rear = lq->front;
        }
        return lq;
    }
}

//遍历元素
void printElments(LinkQueue *lq) {
    if (isEmpty(lq)) {
        return;
    }
    else {
        LinkQueueNode *node;
        node = lq->front->next;
        while (node) {
            printf("%3d",node->data);
            node = node->next;
        }
        printf("\n");
    }
}


int main(int argc, const char * argv[]) {
    printf("Hello, LinkQueue!\n");
    LinkQueue *queue;
    queue = initLinkQueue();
    isEmpty(queue);
    inLinkQueue(queue, 10);
    inLinkQueue(queue, 20);
    inLinkQueue(queue, 30);
    inLinkQueue(queue, 40);
    outLinkQueue(queue);
    printElments(queue);
    return 0;
}
