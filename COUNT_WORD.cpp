//CPP
#include <bits/stdc++.h>
using namespace std;
int main()
{   string s;int cnt=0;
    while(getline(cin,s)){
        stringstream ss(s);
        string word;
        while(ss>>word)cnt++;
    }
    cout<<cnt;
}
