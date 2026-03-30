#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 
struct node
{
    char book_title[50];
    struct node *left;
    struct node *right;
};
struct node* create(char book_title[])
{
    struct node* root = (struct node*)malloc(sizeof(struct node));
    strcpy(root->data,book_title);
    root->left = NULL;
    root->right = NULL;
    return root;
}
void inorder(struct node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main(){
struct node* root = create("Java");
root->left = create("Programming");
root->right = create(15);
root->left->left = create(20);
root->left->right = create(25);
root->right->left = create(40);
root->right->right = create(50);
root->left->right->left = create(30);
root->left->right->right = create(35);
printf("The Inorder Traversal is=>\n");
inorder(root);
return 0;
}
