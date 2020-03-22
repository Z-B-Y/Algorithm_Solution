# include <iostream>
# include <set>
# include <string>
# include <algorithm> 
using namespace std;
void find (set<string> &data,string s,int start);
int main (){
	set <string> data; //存储所有可能的情况 
	string s;
	cin>>s;
	//if(s.size() == 0) return 0;
	int start = 0;
	find(data,s,start);
	int num = data.size();//递归 
	cout<<num<<endl;
	return 0;
} 
void find (set<string> &data,string s,int start){
	if(start == data.size()-1) //如果到达了字符串的最后一个字符
	   {data.insert(s);//形成一种情况
	   return;
       } 
	for (int i = start;i <= s.size()-1;i++){
	//	if(i!=start && s[start] == s[i]) 
	//	    continue; //当遇到重复的字符，为了避免重复的情况，跳过
		swap(s[i],s[start]);
		find(data,s,start+1);
		swap(s[i],s[start]); 
	} 
}

