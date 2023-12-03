#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>>tree;
void PreOrder(int x){
    cout<<x<<" ";
    for(int i=0;i<tree[x].size();i++){
        PreOrder(tree[x][i]);
    }
}
void PostOrder(int x){
    for(int i=0;i<tree[x].size();i++){
        PostOrder(tree[x][i]);
    }cout<<x<<" ";
}
void InOrder(int x){
    if(tree[x].empty())cout<<x<<endl;
    else{
        InOrder(tree[x][0]);
        cout<<x<<" ";
        for(int i=1;i<tree[x].size();i++)InOrder(tree[x][i]);
    }
}
int main() {
    string s;int a,b,root;
    while(1){
        cin>>s;
        if(s=="*")break;
        if(s=="MakeRoot"){
            cin>>root;
        }
        if(s=="Insert"){
            cin>>a>>b;
            tree[b].push_back(a);
        }
        if(s=="PreOrder"){
            PreOrder(root);
            cout<<endl;

        }
        if(s=="PostOrder"){
            PostOrder(root);
            cout<<endl;
        }
        if(s=="InOrder"){
            InOrder(root);
            cout<<endl;

        }
    }
}
