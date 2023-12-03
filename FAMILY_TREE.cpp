#include<bits/stdc++.h>
using namespace std;

map<string,vector<string>>tree;
int sohaudue(string name){
    if(tree[name].empty())return 0;
    int maxx=0;
    for(int i=0;i<tree[name].size();i++)
    {if(maxx<1+sohaudue(tree[name][i]))maxx=1+sohaudue(tree[name][i]);
    }return maxx;
}
int demnguoi(string name){
    if(tree[name].empty())return 0;
    int countt=0;
    for(int i=0;i<tree[name].size();i++)
    countt+=1+demnguoi(tree[name][i]);
    return countt;
}
int main() {
    string s,name,child,parent;
    while(1){
        cin>>child;
        if(child=="***")break;
        cin>>parent;
        tree[parent].push_back(child);
    }
    while(1){
        cin>>s;
        if(s=="***")break;
        cin>>name;
        if(s=="generation")cout<<sohaudue(name)<<endl;
        if(s=="descendants")cout<<demnguoi(name)<<endl;
    }
}
