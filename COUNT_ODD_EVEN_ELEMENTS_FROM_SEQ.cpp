//CPP
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    int t,od=0,ev=0;
    while(n--){
        cin>>t;
        if(t%2==0)ev++;
        else od++;
    }
    cout<<od<<" "<<ev;
}
