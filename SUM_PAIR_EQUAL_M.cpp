#include<bits/stdc++.h>
using namespace std;
int timkiemnhiphan(int a[],int l,int r,int k){
    if(r>=l){
        int mid=l+(r-l)/2;
        if(a[mid]==k)return mid;
        if(a[mid]>k)return timkiemnhiphan(a,l,mid-1,k);
        return timkiemnhiphan(a,mid+1,r,k);
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,res=0,index;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }    sort(a,a+n);
 for(int i=0;i<n;i++){
        if(a[i]>m/2){
            index=i;
            break;
        }
    }


    for(int i=0;i<=index;i++){
        if(timkiemnhiphan(a,index,n,m-a[i])>i)res++;
    }cout<<res;
return 0;
}
