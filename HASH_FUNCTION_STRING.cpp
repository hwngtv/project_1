#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n,m,temp,len;
    cin>>n>>m;
    vector<int>res;
    int poww[200];
    poww[0]=1;
    for(int i=1;i<200;i++){
        poww[i]=256*poww[i-1]%m;
    }
    while(n--){
        cin>>s;
        len=s.length();
        temp=0;
        int nhan=0;
        for(int i=0;i<len;i++){
            temp+=s[i]*poww[len-1-i]%m;
        }
        cout<<temp%m<<'\n';
    }

    return 0;
}
