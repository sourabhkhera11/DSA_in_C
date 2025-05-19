#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * create(int item){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Malloc Failed! Memory Full!");
        exit(0);
    }
    temp->data=item;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node *insert(struct node *root,int item){
    if(root==NULL){
        return create(item);
    } 
    if(item < root->data){
        root->left=insert(root->left,item);
    }
    else if(item > root->data){
        root->right=insert(root->right,item);
    }
    return root;
}
struct node *findMin(struct node *root){
    while (root->left!=NULL)
    {
        root=root->left;
    }
    return root;
    
}
struct node * delete(struct node *root,int item){
    if(root == NULL){
        printf("Empty BST Or Not Found !");
        exit(0);
    }
    if(item < root->data){
        root->left=delete(root->left,item);
    }
    else if( item > root->data){
        root->right=delete(root->right,item);
    }
    else{//0 Child
        if(root->left==NULL && root->right==NULL){
            printf("\nRemoving element: %d",root->data);
            free(root);
            return NULL;
        }
        else if(root->left==NULL){
            printf("\nRemoving element: %d",root->data);
            struct node *r=root->right;
            free(root);
            return r;
        }
        else if(root->right==NULL){
            printf("\nRemoving element: %d",root->data);
            struct node *l=root->left;
            free(root);
            return l;
        }
        else{
            //2Child
            printf("\nRemoving element: %d",root->data);
            struct node *min=findMin(root->right);
            root->data=min->data;
            root->right=delete(root->right,min->data);
        }

    }
    return root;
}
//LNR
void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
//NLR
void preorder(struct node *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
//LRN
void postorder(struct node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void preorderWR(struct node *root){
    #define max 100
    struct node * stack[max];
    int top=-1;
    stack[++top]=root;
    while (top!=-1)
    {
        struct node * cur=stack[top--];
        printf("%d ",cur->data);
        if(cur->right) {
            stack[++top]=cur->right;
        }
        if(cur->left) {
            stack[++top]=cur->left;
        }
    }
}
void inorderWR(struct node *root){
    #define max 100
    struct node* stack[max];
    int top=-1;
    struct node *cur=root;
    while (cur != NULL || top>=0)
    {
        while (cur!=NULL)
        {
            stack[++top]=cur;
            cur=cur->left;
        }

        cur=stack[top--];
        printf("%d ",cur->data);
        cur=cur->right;
    }
    
}
void postorderWR(struct node *root){
    #define max 100
    struct node *stack1[max];
    struct node *stack2[max];
    int top1=-1;
    int top2=-1;
    stack1[++top1]=root;
    while(top1>=0){
        struct node *cur=stack1[top1--];
        stack2[++top2]=cur;
        if(cur->left) stack1[++top1]=cur->left;
        if(cur->right) stack1[++top1]=cur->right;
    }
    while (top2>=0)
    {
        printf("%d ",stack2[top2--]->data);
    }
    
}
int totalNodes(struct node *root){
    if(root==NULL){
        return 0;
    }
    return 1+totalNodes(root->left)+totalNodes(root->right);
}
int leafNodes(struct node *root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    return leafNodes(root->left)+leafNodes(root->right);
}
int nonleafNodes(struct node *root){
    return totalNodes(root)-leafNodes(root);
}
int smallest(struct node *root){
    if(root==NULL){
        printf("Empty BST!");
        exit(0);
    }
    while (root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
    
}
int largest(struct node *root){
    if(root==NULL){
        printf("Empty BST!");
        exit(0);
    }
    while (root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}
bool search(struct node *root,int item ){
    if(root==NULL){
        return false;
    }
    if(item < root->data ){
        return search(root->left,item);
    }
    else if(item > root->data){
        return search(root->right,item);
    }
    else if( item == root->data){
        return true;
    }
}
int sumOfNodes(struct node *root){
    if(root==NULL){
        return 0;
    }
    return root->data+sumOfNodes(root->left)+sumOfNodes(root->right);
}

int main(){
    int ch,item;
    struct node *root=NULL;
    while (1)
    {
        printf("\n-----------BST Operations------------");
        printf("\n1)Insert \n2)Delete \n3)Preorder \n4)Inorder \n5)Postorder \n6)Total no of nodes \n7)Total no of leaft nodes \n8)Total no of non leaf nodes \n9)Smallest nodes \n10)Largest Node \n11)Search for a given node \n12)Sum of all nodes \n13)Preorder without recurssion \n14)Inorder without recurssion \n15)Postorder Without recurssion \n16)Exit");
        printf("\nEnter you choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the value to be inserted:");
            scanf("%d",&item);
            root=insert(root,item);
            break;
        case 2:
            printf("\nEnter the value to be deleted:");
            scanf("%d",&item);
            root=delete(root,item);
            break;
        case 3:
            printf("\nPreorder: ");
            preorder(root);
            break;
        case 4:
            printf("\nInorder: ");
            inorder(root);
            break;
        case 5:
            printf("\nPostorder: ");
            postorder(root);
            break;
        case 6:
            printf("\nTotal no of nodes :%d",totalNodes(root));
            break;
        case 7:
            printf("\nTotal no of leaf nodes :%d",leafNodes(root));
            break;
        case 8:
            printf("\nTotal no of non leaf nodes :%d",nonleafNodes(root));
            break;
        case 9:
            printf("\nSmallest nodes :%d",smallest(root));
            break;
        case 10:
            printf("\nLargest nodes :%d",largest(root));
            break;
        case 11:
            printf("\nEnter the value to be searched:");
            scanf("%d",&item);
            printf("Value exits in the tree : %d",search(root,item));
            break;
        case 12:
            printf("\nSum of all nodes :%d",sumOfNodes(root));
            break;
        case 13:
            preorderWR(root);
            break;
        case 14:
            inorderWR(root);
            break;
        case 15:
            postorderWR(root);
            break;
        case 16:
            exit(0);
        default:
            break;
        }
    }
    
}