#include<bits/stdc++.h>
using namespace std;
int n, s[100][100] = {};
void la(int u, int v){
    for(int i = 1; i <= n; i++)
        if(s[v][i])
            if(!s[u][i] || s[u][i] > s[u][v] + s[v][i]){
                s[u][i] = s[u][v] + s[v][i];
                la(u, i);
            }

    for(int i = 1; i <= n; i++)
        if(s[i][u])
            if(!s[i][v] || s[i][v] > s[u][v] + s[i][u]){
                s[i][v] = s[u][v] + s[i][u];
                la(i, v);
            }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int m, u, v, w;
    cin >> n >> m;
    while(m--){
        cin >> u >> v >> w;
        if(!s[u][v] || s[u][v] > w){
            s[u][v] = w;
            la(u, v);
        }
    }
    for(int i = 1; i <= n; i++)
        s[i][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            printf("%d ", s[i][j]);
        cout << endl;
    }
}