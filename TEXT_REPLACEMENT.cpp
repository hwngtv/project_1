//CPP
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2,text;
    getline(cin,s1);
    getline(cin,s2);
    while(getline(cin,text)){
            string res=text;
        while(res.find(s1)<res.size())
        res=res.replace(res.find(s1),s1.size(),s2);
        cout<<res;
    }

}
