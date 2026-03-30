#include<stdio.h>
#include<stdlib.h>
struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};  
struct BSTNode* create(int val)
{
    struct BSTNode* root = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    root->data = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}
struct BSTNode* insert(struct BSTNode* root, int key)
{
    if (root == NULL)
        return create(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}
void inorder(struct BSTNode* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main(){
struct BSTNode* root = NULL;
root = insert(root, 50);
insert(root, 30);
insert(root, 20);
insert(root, 40);
insert(root, 70);
insert(root, 60);
insert(root, 80);
printf("Inorder Traversal of the BST is=>\n");
inorder(root);
return 0;
}
