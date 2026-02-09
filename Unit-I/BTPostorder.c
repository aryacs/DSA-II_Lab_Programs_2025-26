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
void postorder(struct node* root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(){
struct node* root = create(5);
root->left = create(10);
root->right = create(15);
root->left->left = create(20);
root->left->right = create(25);
root->right->left = create(40);
root->right->right = create(50);
printf("The Postorder Traversal is=>\n");
postorder(root);
return 0;
}
