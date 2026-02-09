#include<stdio.h>
#include<stdlib.h>  
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* create(int val)
{
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}
int Height(struct node* root)
{
    if (root == NULL)
        return 0;
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    return 1 + (leftHeight > rightHeight?leftHeight:rightHeight);
}


int main(){
struct node* root = create(5);
root->left = create(10);
root->right = create(15);
root->left->left = create(20);
root->left->right = create(25);
root->right->left = create(40);
root->right->right = create(50);

printf("\nThe Height of Binary Tree is=>%d\n", Height(root));
return 0;
}
