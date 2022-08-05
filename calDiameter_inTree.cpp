#include<iostream>
#include<queue>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int  calcheight(struct node* root){
    if(root==NULL){
        return 0;
    }
    int lHeight=calcheight(root->left);
    int rHeight=calcheight(root->right);
    return max(lHeight,rHeight)+1;
}

int calcDiameter(struct node* root){
    if(root==NULL){
        return 0;
    }
    int lHeight=calcheight(root->left);
    int rHeight=calcheight(root->right);
    int currDiameter=lHeight+rHeight+1;

    int lDiameter=calcDiameter(root->left);
    int rDiameter=calcDiameter(root->right);

    return max(currDiameter,max(lDiameter,rDiameter));
}
int main(){
    struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);

    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    cout<<(root);
    cout<<calcDiameter(root);
    return 0;
}