# include  <iostream>
using namespace std;
int main (){
  double m,n;
  int perv[10] = {10000,5000,1000,500,100,50,10,5,1};
  double temp[10] = {100,50,10,5,1,0.5,0.1,0.05,0.01};
    while(cin>>m>>n){
    double data = n - m;
    double r = data;
    data = data * 100;
    int flag = 0;
    int result [10] = {0};
    while(data > 0){
      if(data >= perv[flag]){
        data = data - perv[flag];
        result[flag] ++;
      }else{
        flag ++;
      }
    }
   cout<<r<<" ";
   for(int i = 0;i < 10;i ++){
     if(result[i] != 0)
     cout<<temp[i]<<":"<<result[i]<<";";
   }
      cout<<endl;
    }
  return 0;
}
