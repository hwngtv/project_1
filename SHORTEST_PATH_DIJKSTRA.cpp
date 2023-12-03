#include<bits/stdc++.h>
using namespace std;
struct node{
    int v, w;
    node *n;
    node (int v1, int w1, node *n1){
        v = v1;
        w = w1;
        n = n1;
    }
};
node *s[100001];
int wi[100001] = {}, x[1000001] = {};

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, u, v, w, p = -1, k = 1, mn = 1e9;
    cin >> n >> m;
    while(m--){
        cin >> u >> v >> w;
        s[u] = new node(v, w, s[u]);
    }
    cin >> u >> v;
    x[0] = u; 
    while(++p < k){
        node *tmp = s[x[p]];
        int wt = x[++p];
        while(tmp){
            if(!wi[tmp->v] || wi[tmp->v] > wt + tmp->w){
                if(mn > wt + tmp->w){
                    if(tmp->v == v)
                        mn = wt + tmp->w;
                    x[++k] = tmp->v;
                    x[++k] = wt + tmp->w;
                    wi[tmp->v] = wt + tmp->w;
                }
            }
            tmp = tmp->n;
        }
    }
    cout << wi[v];
}