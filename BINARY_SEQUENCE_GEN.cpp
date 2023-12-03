//C/C++
#include <bits/stdc++.h>
using namespace std;
int n,a[21];
void inra(){
    for(int i=0;i<n;i++)cout<<a[i];
    cout<<endl;
    }

void Try(int k){
    if(k==n)inra();
    else
    for(int i=0;i<=1;i++){
        a[k]=i;
        Try(k+1);
    }
}
int main()
{

cin>>n;
Try(0);
}
