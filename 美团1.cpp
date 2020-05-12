# include <iostream>
# include <set>
using namespace std;
int main (){
    int data[100][100];
    int m,n;
    while(cin>>m>>n){  
    for(int i = 0;i < m;i ++) //行
        for(int j = 0;j < n;j ++){  //列
            cin>>data[m][n];
        }

     int count = 0;
     set<int> res;
     int max = 0;
     for(int i = 0;i < n;i ++){  //列
        for(int j = 0;j < m;j ++){  //行
            if(data[j][i] > data[max][i])
                max = j;
        }
         res.insert(max);
         max = 0;
     }
    cout<<res.size()<<endl;
}
    return 0;
}
