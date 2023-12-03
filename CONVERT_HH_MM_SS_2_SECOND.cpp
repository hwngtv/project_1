//CPP
#include <bits/stdc++.h>
using namespace std;
int main()
{ string s;
cin>>s;
int h,m,se;
if(s[2]!=':'&&s[5]!=':'){
    cout<<"INCORRECT";return 0;
}
   h=(s[0]-'0')*10+(s[1]-'0');
   m=(s[3]-'0')*10+(s[4]-'0');
   se=(s[6]-'0')*10+(s[7]-'0');
   if((h>23||h<0)||(m>59||m<0)||se<0||se>59){
    cout<<"INCORRECT";return 0;
}
    cout<<h*3600+m*60+se;
}
