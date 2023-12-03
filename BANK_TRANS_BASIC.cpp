#include<bits/stdc++.h>
using namespace std;

int s[100001] = {}, come[100001], num_trans = 0, total_money = 0, m, n, kt = 0, p = 0;
bool vi[100001];
set<string> li;
map<string, int> mp;
vector<int> ss[100001];

void thu(int k){
    if(kt){
        return;
    }
    if(k == m){
        for(int i : ss[come[k-1]])
            if(i == n)
                kt = 1;
        return;
    }
    for(int i : ss[come[k - 1]]){
        if(!vi[i]){
            come[k] = i;
            vi[i] = true;
            thu(k+1);
            vi[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string x, y, z;
    cin >> x;
    while(x[0] != '#'){
        cin >> y >> m >> z >> z;
        num_trans++;
        total_money += m;
        if(li.find(x) == li.end()){
            mp[x] = p++;
        }      
        if(li.find(y) == li.end()){
            mp[y] = p++;
        }
        s[mp[x]] += m;
        li.insert(x);
        li.insert(y);
        ss[mp[x]].push_back(mp[y]);
        cin >> x;
    }
    cin >> x;
    while(x[0] != '#'){
        if(x[1] == 't'){
            if(x[24] == '_'){
                cin >> x;
                if(li.find(x) != li.end()){
                    cout << s[mp[x]] << endl;
                }
                else
                    cout << 0 << endl;
            }
            else{
                cout << total_money << endl;
            }
        }
        else if(x[1] == 'i'){
            cin >> x >> m;
            kt = 0;
            n = mp[x];
            come[0] = n;
            vi[n] = true;
            thu(1);
            vi[n] = false;
            if(kt){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else if(x[1] == 'l'){
            for(string i : li)
                cout << i << " ";
            cout << endl;
        }
        else if(x[1] == 'n'){
            cout << num_trans << endl;
        }
        cin >> x;
    }
}