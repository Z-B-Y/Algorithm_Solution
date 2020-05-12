# include <iostream>
# include <vector>
using namespace std;
bool judge(int m,int n){
    vector<int> x,y;
    int a[100],b[100];
    int i = m;
    int j = 0;
    while(i)
   {
    a[j]=i%2;
    i/=2;
    j++;
   }
    for(i=j-1;i>=0;i--){
        x.push_back(a[i]);
    }
    i = n;
    j = 0;
    while(i)
   {
    b[j]=i%2;
    i/=2;
    j++;
   }
    for(i=j-1;i>=0;i--){
        y.push_back(b[i]);
    }
    int len1 = x.size();
    int len2 = y.size();
    int len;
    if (len1 < len2) 
        len = len1;
    else len = len2;
    for(int i = 0;i < len;i ++){
        if(x[i]&y[i] != 0)  //按位与结果不为0
            return true;
    }
    return true;
}
int main (){
    int n;
    vector<int> data;
    while(cin>>n){
        int x;
        cin>>x;
        data.push_back(x);
    }
    for(int i = 0;i < data.size();i ++){
        for(int j = i;j < data.size();j ++){
            if(judge(data[i],data[j])){
                cout<<1<<endl;
                continue;
            }
        }
        cout<<-1<<endl;
    }
    return 0;
}
