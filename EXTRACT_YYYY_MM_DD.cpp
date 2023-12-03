
//CPP
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    bool t=true;
    if(s.size()!=10||s[4]!='-'||s[7]!='-') t=false;
    for(int i=1;i<4;i++)if(s[0]<'0'||i>'9')t=false;
    if(s[5]!='1'&&s[5]!='0')t=false;
    if(s[5]=='1'&&(s[6]>'2'||s[6]<'0'))t=false;
    if(s[8]!='1'&&s[8]!='0'&&s[8]!='2'&&s[8]!='3')t=false;
    if(s[8]=='3'&&(s[9]>'1'||s[9]<'0'))t=false;
    if(!t)cout<<"INCORRECT";
    else{
        s[4]=' ';
        s[7]=' ';

        if(s[5]=='0'){s.erase(5,1);
            if(s[7]=='0')s.erase(7,1);
        }

        else if(s[8]=='0')s.erase(8,1);
                cout<<s;
    }
    return 0;
}
