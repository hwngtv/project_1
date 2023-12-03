//C++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;

    while(1){
    string s;
    cin>>s;
    if(s=="PUSH"){
        int temp;
        cin>>temp;
        st.push(temp);
    }
    else if(s=="POP"){
        if(st.empty())cout<<"NULL\n";
        else {
            cout<<st.top()<<endl;
            st.pop();
        }
    }
    else if(s=="#")break;
    }
}
