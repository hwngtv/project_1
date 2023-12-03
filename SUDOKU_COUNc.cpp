//C/C++
#include <bits/stdc++.h>
using namespace std;
int a[9][9],res=0;
bool ro[9][10]={},co[9][10]={},sub[3][3][10]={};
bool check(int r,int c,int i){
    return ro[r][i]==0&&co[c][i]==0&&sub[r/3][c/3][i]==0;
}

void Try(int r,int c){
    if(a[r][c]>0){
        if(r==8&&c==8)res++;
        else{
            if(c==8)Try(r+1,0);
            else Try(r,c+1);
        }
    }

    else for(int i=1;i<=9;i++){
        if(check(r,c,i)){
            if(r==8&&c==8)res++;
            else{
                ro[r][i]=1;
                co[c][i]=1;
                sub[r/3][c/3][i]=1;
                a[r][c]=i;
                if(c==8)Try(r+1,0);
                else Try(r,c+1);
                a[r][c]=0;
                ro[r][i]=0;
                co[c][i]=0;
                sub[r/3][c/3][i]=0;
            }
        }
    }
}
int main()
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>a[i][j];
            if(a[i][j]>0){
                ro[i][a[i][j]]=1;
                co[j][a[i][j]]=1;
                sub[i/3][j/3][a[i][j]]=1;
            }
        }
    }
    Try(0,0);
    cout<<res;
    return 0;
}
