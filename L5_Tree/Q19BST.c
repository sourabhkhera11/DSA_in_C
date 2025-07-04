#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * create(int item){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Malloc failed!");
        exit(0);
    }
    temp->data=item;
    temp->left=temp->right=NULL;
    return temp;
}

struct node * insert(struct node *root,int item){
    if(root==NULL){
        return create(item);
    }
    if(item < root->data){
        root->left=insert(root->left,item);
    }
    else{
        root->right=insert(root->right,item);
    }
    return root;
}

struct node *findMin(struct node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
struct node * delete(struct node *root, int item){
    if(root==NULL){
        return NULL;
    }
    if(item < root->data){
        root->left=delete(root->left,item);
    }
    else if(item > root->data){
        root->right=delete(root->right,item);
    }
    else{
        //0 child
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        } //1child
        else if(root->left==NULL){
            struct node *r=root->right;
            free(root);
            return r;
        }
        else if(root->right==NULL){
            struct node *l=root->left;
            free(root);
            return l;
        }
        else{
            struct node * minn=findMin(root->right);
            root->data=minn->data;
            //minn can have either 0 or 1 child
            root->right=delete(root->right,minn->data);
        }
    }
    return root;
}
//LNR
void inorder(struct node *root){
    if(root==NULL)  return ;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(struct node *root){
    if(root==NULL)  return ;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root){
    if(root==NULL)  return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int main(){
    struct node *root=NULL; 
    root=insert(root,30);
    root=insert(root,25);
    root=insert(root,20);
    root=insert(root,27);
    root=insert(root,35);
    root=insert(root,33);
    root=insert(root,37);
    root=insert(root,31);
    root=insert(root,36);
    root=insert(root,23);
    printf("\nInorder traversal=");
    inorder(root);
    printf("\nPreorder traversal=");
    preorder(root);
    printf("\nPostorder traversal=");
    postorder(root);
    root=delete(root,36);
    printf("\nInorder traversal=");
    inorder(root);
    root=delete(root,20);
    printf("\nInorder traversal=");
    inorder(root);
    root=delete(root,33);
    printf("\nInorder traversal=");
    inorder(root);
    root=delete(root,30);
    printf("\nInorder traversal=");
    inorder(root);
    return 0;
}