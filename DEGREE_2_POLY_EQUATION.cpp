//CPP
#include <bits/stdc++.h>

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a==0){
        if(b==0){
            printf("NO SOLUTION ");
        }
        else printf("%.2f",(-c*1.0)/b);
    }
    else {
        int denta=b*b-4*a*c;
        if(denta<0)printf("NO SOLUTION ");
        else if(denta==0)printf("%.2f",(-b*1.0)/(2*a));
        else{float d;
            if (a>0)d=sqrt(denta);
            else d=-sqrt(denta);
            printf("%.2f %.2f",(-b-d)/(2*a),(-b+d)/(2*a));
        }
    }
    return 0;
}
