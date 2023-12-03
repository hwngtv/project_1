#include<bits/stdc++.h>
using namespace std;

int convert_int(char *s){
    int num = 0;
    char *i = s - 1;
    while(*(++i) != 0)
        if(*i < 58 && *i > 47) num = num * 10 + *i - 48; 
    return num;
}

int time_to_int(char *s){
    return (*s * 10 + *(s+1)) * 3600 + (*(s+3) * 10 + *(s+4)) * 60 + *(s+6) * 10 + *(s+7) - 1933008;
}

int cs[1001][1001] = {}, m[1001], p[86401] = {};

int main(){
    int sl = 0, cost = 0, r;
    char s[10], x[10], query[50];
    scanf("%s", query);
    while(query[0] != '#'){
        scanf("%s%d%s%s", s, &r, s, x);
        ++sl;
        cost += r;
        cs[convert_int(query)][convert_int(s)] += r;
        m[convert_int(s)] += r;
        p[time_to_int(x)] += r;
        scanf("%s", query);
    }
    for(int i = 1; i < 86401; ++i)
        p[i] += p[i-1];

    scanf("%s", query);
    while(query[0] != '#'){
        if(query[7] == 'r'){
            if(query[14] == 0)
                printf("%d\n", cost);
            else{
                scanf("%s%s", x, s);
                printf("%d\n", p[time_to_int(s)] - p[time_to_int(x) - 1]);
            }
        }
        else if(query[7] == 'c'){
            scanf("%s%s", x, s);
            printf("%d\n", cs[convert_int(x)][convert_int(s)]);
        }
        else if(query[7] == 'e'){
            scanf("%s", s);
            printf("%d\n", m[convert_int(s)]);
        }
        else if(query[7] == 'n')
            printf("%d\n", sl);
        scanf("%s", query);
    }
}