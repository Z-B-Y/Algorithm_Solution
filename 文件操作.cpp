#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string str;//����string�����ܶ����Դ����
    ifstream file("abc.cpp");
    int cnt=1;//��¼��ǰ�к�
    if(!file.is_open())
    {
        cout<<"�ļ���ʧ�ܣ�"<<endl;
    }
    else{
        while(getline(file,str))//ÿ�λ�ȡһ��Դ����
        {
            //�Խ��ܵ�str���д���ʹ�䲻����//���͵��ַ���
            int len=str.length();
            for(int i=0;i<len-1;i++)
            {
                if(str[i]=='/')
                {
                    if(str[i+1]=='/')
                    {
                        //˵����ע��Ϊ//���ͣ�ֱ��ȥ��//��������������ݼ��ɣ�string�����ֳɵĺ�������ֱ�ӵ���
                        str.erase(str.begin()+i,str.end());
                    }
                    else if(str[i+1]=='*')
                    {
                        //˵����ע��Ϊ"/*...*/���ͣ���ʱ���ܼ򵥵�ȥ��/*������������ݣ���Ϊ/*���ֲ����ܼ򵥶϶�ע��ֻ��һ�У�ע�Ϳ����ж���
                        str.erase(str.begin()+i,str.end());
                        cout<<cnt<<"  "<<str<<endl;//��������������Դ���뼰���к�
                        cnt++;//�кż�1
                        do
                        {
                            getline(file,str);
                            len=str.length();
                        }
                        while(!(str[len-2]=='*' && str[len-1]=='/')); //��ѭ���ķ�ʽȥ������ע��
                        getline(file,str);
                    }
                }
            }
            cout<<cnt<<"  "<<str<<endl;//ÿ������к��Լ�һ��Դ����
            cnt++;
        }
    }
    return 0;
}

