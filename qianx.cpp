# include <iostream>
using namespace std;
int main (){
   int n;
   int price[10] = {1,2,2,2,5,3};   //按照性价比进行排序
   int data[10] = {5,3,3,2,4,1};
    while (cin>>n){
        int count = 0;//口罩数量
        if(n == 2)
            cout<<3;
        else {            int i = 0;
            while(n >= 0){
                n = n - price[i];
                if(n < 0) break;
                count = count + data[i];
                i ++;
            }
             }
                cout << count<<endl;
    }
    return 0;
}
