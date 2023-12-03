//C++
#include <bits/stdc++.h>
using namespace std;
struct node{
    int key;
    node*left;
    node*right;
};
node* makenode(int x){
    node*temp=new node;
    temp->key=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node* insertt(node*root,int x){
    if(root==NULL){
        return makenode(x);
    }
    if(x<root->key)root->left=insertt(root->left,x);
    else if(x>root->key)root->right=insertt(root->right,x);
    return root;
}
void duyet(node*root){
    if(root==NULL){
            return;

    }cout<<root->key<<" ";
    duyet(root->left);
    duyet(root->right);
}
int main()
{   string s;int a;
    node* root=NULL;
    while(1){
        cin>>s;
        if(s=="#")break;
        cin>>a;
        root=insertt(root,a);
    }
    duyet(root);
}
