//C/C++
#include <bits/stdc++.h>
using namespace std;
int a[50];
int main()
{
int n;
cin>>n;
a[1]=1;
a[2]=1;
for(int i=2;i<=n;i++){
    a[i]=a[i-1]+a[i-2];
}
    cout<<a[n-1];
    return 0;
}
