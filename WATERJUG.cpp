#include<bits/stdc++.h>
using namespace std;

int ucln(int a,int b){
    if(b==0)return a;
    return ucln(b,a%b);
}
int donuoc(int a,int b,int c){
int buoc=1,binhA=a,binhB=0,temp;
while(binhA!=c&&binhB!=c){
    temp=min(binhA,b-binhB);
    binhB+=temp;
    binhA-=temp;
    buoc+=1;
    if (binhA == c || binhB == c)
            break;
    if(binhA==0){
        binhA=a;
        buoc+=1;
    }
    if(binhB==b){
        binhB=0;
        buoc+=1;
    }

}return buoc;
}
int slove(int a,int b,int c){
    if(a>b)swap(a,b);
    if(c>b)return -1;
    if((c%ucln(a,b))!=0)return -1;
    return min(donuoc(a,b,c),donuoc(b,a,c));
}
int main() {
    int a,b,c;
    cin>>a>>b>>c;
    cout<<slove(a,b,c);
}
