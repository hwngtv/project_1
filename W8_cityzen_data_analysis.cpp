#include<bits/stdc++.h>
using namespace std;
int born[1200000] = {}, was_born[1200000] = {}, will_born[1200000], ancestor[100001][2];
int parents[100001][2], rela[21] = {}, x[22] = {}, n, kt = 0, num = 0;
bool check(){
    for(int i = 1; i < n; ++i)
        if(rela[parents[x[i]][0]] || rela[parents[x[i]][1]])
            return false;
    return true;
}
void Try(int k){
    if(k == n){
        if(check())
            kt = 1;
        return;
    }
    for(int i = x[k-1]+1; i <= num-(n-1-k); ++i){
        x[k] = i;
        rela[i] = 1;
        Try(k+1);
        rela[i] = 0;
    }
}
int convert_int(string s){
    int num = 0, j = s.length();
    for(int i = 0; i < j; ++i)
        if(s[i] < 58 && s[i] > 47) num = num * 10 + s[i] - 48; 
    return num;
}
int convert_date(int date){
    return date / 10000 * 372 + (date % 10000) / 100 * 31 + date % 100;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    string codee, date, father, mother, aliv, reg, query, date1;
    cin >> codee;
    while(codee[0] != '*'){
        ++num;
        cin >> date >> father >> mother >> aliv >> reg;
        int code = convert_int(codee);
        ++born[convert_date(convert_int(date))];
        parents[code][0] = convert_int(father);
        parents[code][1] = convert_int(mother);
        cin >> codee;
    }
    for(int i = 1; i < 1200000; ++i){
        was_born[i] = was_born[i-1] + born[i-1];
        will_born[i-1] = num - was_born[i];
    }
    cin >> query;
    while(query[0] != '*'){
        if(query[1] == 'U'){
            if(query[13] == '\0'){
                cout << num << endl;
            }
            else if(query[19] == 'A'){
                cin >> date;
                cout << born[convert_date(convert_int(date))] << endl;
            }
            else{
                cin >> date >> date1;
                cout << num - was_born[convert_date(convert_int(date))] - will_born[convert_date(convert_int(date1))] << endl;
            }
        }
        else if(query[1] == 'O'){
            cin >> codee;
            int p = -1, k = 0;
            ancestor[0][0] = convert_int(codee);
            while(++p <= k){
                for(int i = 0; i < 2; ++i){
                    if(parents[ancestor[p][0]][i]){
                        ancestor[++k][0] = parents[ancestor[p][0]][i];
                        ancestor[k][1] = ancestor[p][1] + 1;
                    }
                }
            }
            cout << ancestor[k][1] << endl;
        }
        else if(query[1] == 'A'){
            n = num + 1;
            for(n; n >= 0; --n){
                Try(1);
                if(kt)
                    break;
            }
            cout << n - 1 << endl;
        }
        cin >> query;
    }
}