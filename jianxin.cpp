# include <iostream>
# include <stdio.h>
# include <vector>
# include <algorithm>
using namespace std;
int main (){
    int n,hit,t;
    while(scanf("%d %d %d",&n,&hit,&t) != EOF){
        vector <int> data;
        for(int i = 0;i < n;i++){
            int temp;
            cin>>temp;
            data.push_back(temp);
        }
        //按照杀死所需的次数排序
       // vector <int> time;
       // for(int i = 0;i < n;i++){
       //     time[i] = temp[i]/hit;
       // }
        sort(data.begin(),data.end());
        int result = 0;
        int j = 0;
        for(int i = 0;i < t;i ++){
            data[j] = data[j] - hit;
            if(data[j]<=0){
                j++;
                result++;
            }
        }
        cout<<result<<endl;
        return 0;
    }
}
