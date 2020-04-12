# include <iostream>
# include <string>
# include <stack>
# include <vector>
using namespace std;
int main (){
   string s;
   while(cin>>s){
        stack<char> data;
     //  int data = 0;
       int count = 0;
       for(int i = 0;i < s.length();i++){
           if(s[i] == '(')
              data.push(s[i]);
           if(s[i] == ')'){
                if(!data.empty()){
                   data.pop();
                   count ++;
               }
             }
           }
       int left = 0;
       int right = 0;
       for(int i = 0;i < s.length();i++){
           if(s[i] == '(')
               left ++;
           if(s[i] == ')')
               right ++;
       }
       left = left - count;
       right = right - count;
       cout<<count<<" "<<left<<" "<<right<<endl;
       }
    return 0;
}
