#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
stuct node *create(int val){
    struct node *root = (struct node*)malloc(sizeof(struct node));
    root->data = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}
void Inorder(struct node *root){
    if(root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}
int main(){
struct node* root = create(5);
root->left = create(10);
root->right = create(15);
root->left->left = create(20);
root->left->right = create(25);
root->right->left = create(40);
root->right->right = create(50);
root->left->right->left = create(30);
root->left->right->right = create(35);
printf("\nThe Inorder Traversal of Binary Tree is=>\n");
Inorder(root);
return 0;
}