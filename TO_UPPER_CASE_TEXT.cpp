
//CPP
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    while(getline(cin,s)){
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z')s[i]-=32;
        }if(s!="\n")s+="\n";
        cout<<s;
        s="";
    }
}
