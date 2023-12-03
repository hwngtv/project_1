//CPP
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    int a[n];
    cin>>a[0];int max=a[0],min=a[0],su=a[0];
    for(int i=1;i<n;i++){cin>>a[i];
        if(a[i]>max)max=a[i];
        if(a[i]<min)min=a[i];
        su+=a[i];
    }

    string s;cin>>s;
    while(1){
        cin>>s;
        if(s=="***")break;
        if(s=="find-max")cout<<max<<endl;
        if(s=="find-min")cout<<min<<endl;
        if(s=="sum")cout<<su<<endl;
        if(s=="find-max-segment"){
            int b,c;
            cin>>b>>c;
            int m=a[b-1];
            for(int i=b;i<c;i++){
                if(a[i]>m)m=a[i];
            }cout<<m<<endl;
        }
        if(s=="find-min-segment"){
            int b,c;
            cin>>b>>c;
            int m=a[b-1];
            for(int i=b;i<c;i++){
                if(a[i]<m)m=a[i];
            }cout<<m<<endl;
        }
    }
}
