//
//  main.c
//  ConstructBiTree
//
//  Created by Yans on 16/6/4.
//  Copyright © 2016年 Yans. All rights reserved.
//

#include <stdio.h>

typedef struct BiTreeNode{
    int value;
    struct BiTreeNode *left;
    struct BiTreeNode *right;
}BiTreeNode;

void Postorder(BiTreeNode* root) {
    if (root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        printf("%2d",root->value);
    }
}
void Preorder(BiTreeNode* root) {
    if (root != NULL) {
        printf("%2d",root->value);
        Preorder(root->left);
        Preorder(root->right);
    }
}
void Inorder(BiTreeNode* root) {
    if (root != NULL) {
        Inorder(root->left);
        printf("%2d",root->value);
        Inorder(root->right);
    }
}

/*
    已知前序遍历和中序遍历重建二叉树
 */
BiTreeNode* ConstructCore1(int *startPreorder, int *endPreorder,int *startInorder, int *endInorder) {
    int rootValue = startPreorder[0];
    BiTreeNode* root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    root->value = rootValue;
    root->left = root->right = NULL;
    
    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startPreorder == *startInorder) {
            return root;
        }
        else {
            printf("error@");
        }
    }
    int* rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue) {
        ++rootInorder;
    }
    if (rootInorder == endInorder && *rootInorder != rootValue) {
        printf("error!");
    }
    
    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if (leftLength > 0) {
        root->left = ConstructCore1(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }
    if (leftLength < endPreorder - startPreorder) {
        root->right = ConstructCore1(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }
    return  root;
}

//BiTreeNode* ConstructCore2(int *startPreorder, int *endPreorder,int *startInorder, int *endInorder) {
//    int rootValue = *endPreorder;
//    printf("%d",rootValue);
//    BiTreeNode* root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
//    root->value = rootValue;
//    root->left = root->right = NULL;
//    
//    if (startPreorder == endPreorder) {
//        if (startInorder == endInorder && *startPreorder == *startInorder) {
//            return root;
//        }
//        else {
//            printf("error@");
//        }
//    }
//    int* rootInorder = startInorder;
//    while (rootInorder <= endInorder && *rootInorder != rootValue) {
//        ++rootInorder;
//    }
//    if (rootInorder == endInorder && *rootInorder != rootValue) {
//        printf("error!");
//    }
//    
//    int leftLength = rootInorder - startInorder;
//    int* leftPreorderEnd = startPreorder + leftLength - 1;
//    if (leftLength > 0) {
//        root->left = ConstructCore2(startPreorder, leftPreorderEnd, startInorder, rootInorder - 1);
//    }
//    if (leftLength < endPreorder - startPreorder) {
//        root->right = ConstructCore2(startPreorder, leftPreorderEnd + 1, rootInorder + 1, endInorder - 1);
//    }
//    return  root;
//}
//
BiTreeNode* Construct(int* preorder, int* inorder, int length) {
    if (preorder == NULL || inorder == NULL || length <= 0) {
        return NULL;
    }
    else {
        return ConstructCore1(preorder, preorder + length - 1, inorder, inorder + length -1);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int preorder[] = {1,2,4,7,3,5,6,8};
    int inorder[] = {4,7,2,1,5,3,8,6};
    int postorder[] = {7,4,2,5,8,6,3,1};
    int length = 8;

    Construct(postorder, inorder, length);
    return 0;
}
