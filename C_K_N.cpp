//C/C++
#include <bits/stdc++.h>
int k,n;
const int p=1e9+7;
using namespace std;
int m[1000][1000]={};
int Try(int i,int j){
    if(i==0||i==j)m[i][j]=1;
    else{
        if(m[i][j]==0)
            m[i][j]=(Try(i-1,j-1)%p+Try(i,j-1)%p)%p;
    }
    return m[i][j];

}

int main()
{

    cin>>k>>n;
    cout<<Try(k,n);
}
