# include <iostream>
# include <set>
# include <string>
# include <algorithm> 
using namespace std;
void find (set<string> &data,string s,int start);
int main (){
	set <string> data; //�洢���п��ܵ���� 
	string s;
	cin>>s;
	//if(s.size() == 0) return 0;
	int start = 0;
	find(data,s,start);
	int num = data.size();//�ݹ� 
	cout<<num<<endl;
	return 0;
} 
void find (set<string> &data,string s,int start){
	if(start == data.size()-1) //����������ַ��������һ���ַ�
	   {data.insert(s);//�γ�һ�����
	   return;
       } 
	for (int i = start;i <= s.size()-1;i++){
	//	if(i!=start && s[start] == s[i]) 
	//	    continue; //�������ظ����ַ���Ϊ�˱����ظ������������
		swap(s[i],s[start]);
		find(data,s,start+1);
		swap(s[i],s[start]); 
	} 
}

