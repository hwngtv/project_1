#include <bits/stdc++.h>
using namespace std;

int sodinh, socanh;
vector<int> dscanh[1000];
bool danhdau[1000];

void input() {
    cin >> sodinh >> socanh;
    int dinh1, dinh2;
    for(int i = 1; i <= socanh; i++) {
        cin >> dinh1 >> dinh2;
        dscanh[dinh2].push_back(dinh1);
        dscanh[dinh1].push_back(dinh2);
    }
    for(int i = 1; i <= sodinh; i++) {
        sort(dscanh[i].begin(), dscanh[i].end());
    }
}

void bfs(int k) {
    queue<int> que;
    que.push(k);
    danhdau[k] = true;
    while(!que.empty()) {
        int dinh = que.front();
        que.pop();
        cout << dinh << " ";
        for(int u : dscanh[dinh]) {
            if(!danhdau[u]) {
                que.push(u);
                danhdau[u] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    for(int i=1;i<=sodinh;i++)if(!danhdau[i])bfs(i);
    return 0;
}
