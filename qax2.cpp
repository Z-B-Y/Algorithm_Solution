# include <iostream>
# include <vector>
# include <stdlib.h>
using namespace std;
int main (){
    int x1,x2,x3,x4,x5,x6,x7,x8,x9;
    while(scanf("%d,%d,%d,d,%d,%d,d,%d,%d",&x1,&x2,&x3,&x4,&x5,&x6,&x7,&x8,&x9)){
        int y1 = x1 + x2 + x3 + x4;
        int y2 = x4 + x5 + x6 + x7;
        int y3 = x7 + x8 + x9 + x1;
        if(y1==y2 && y2==y3)
            cout<<"yes"<<endl;
        else 
            cout<<"no"<<endl;
    }
    return 0;
}
