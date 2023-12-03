//C++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<char> st;
    string s;
    cin>>s;
    int res=1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{') st.push(s[i]);
        else   {
            if(st.empty()||(s[i]==')'&&st.top()!='(')||(s[i]==']'&&st.top()!='[')||(s[i]=='}'&&st.top()!='{')){
                res=0;break;
            }
            else st.pop();
        }
    }
    if(!st.empty())res=0;
    cout<<res;
}
