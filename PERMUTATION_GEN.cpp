//C/C++
#include <bits/stdc++.h>
using namespace std;
int n,a[1000],b[1000]={};
void solution(){
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    }
bool check(int i,int k){
            return !b[i];
    }
void Try(int k){

        for(int i=1;i<=n;i++){
                if(k==n){
                    solution();
                    break;}
                if(check(i,k)){
                    a[k]=i;
                    b[i]=1;
                    Try(k+1);
                    b[i]=0;
            }
        }
}


int main()
{
    cin>>n;
    Try(0);
}
