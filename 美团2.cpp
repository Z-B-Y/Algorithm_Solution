# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int hammingDistance(int x, int y) {
        int z = x^y;
        int count = 0;
        while(z){
            ++ count;
            z &= z-1;
        }
        //cout << z << endl;
        return count;
    }

int main (){
    int n;
    while(cin>>n){
    int x;
    vector<int>input;
    for(int i = 0;i < n;i++){
        cin>>x;
        input.push_back(x);
    }
    vector<int> data;
    for(int i = 0;i < n;i++){
       for(int j = i + 1;i < n;i ++)
           {
               int y = hammingDistance(input[i],input[j]);
               data.push_back(y);
           }
    }
    sort(data.begin(),data.end());
    cout<<data[n-1]<<endl;
    return 0;
    }
}
