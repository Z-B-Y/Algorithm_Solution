#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string str;//利用string来接受读入的源代码
    ifstream file("abc.cpp");
    int cnt=1;//记录当前行号
    if(!file.is_open())
    {
        cout<<"文件打开失败！"<<endl;
    }
    else{
        while(getline(file,str))//每次获取一行源代码
        {
            //对接受的str进行处理，使其不包含//类型的字符串
            int len=str.length();
            for(int i=0;i<len-1;i++)
            {
                if(str[i]=='/')
                {
                    if(str[i+1]=='/')
                    {
                        //说明此注释为//类型，直接去掉//及其后面所有内容即可，string中有现成的函数可以直接调用
                        str.erase(str.begin()+i,str.end());
                    }
                    else if(str[i+1]=='*')
                    {
                        //说明此注释为"/*...*/类型，这时不能简单地去掉/*后面的所有内容，因为/*出现并不能简单断定注释只有一行，注释可能有多行
                        str.erase(str.begin()+i,str.end());
                        cout<<cnt<<"  "<<str<<endl;//输出处理过的这行源代码及其行号
                        cnt++;//行号加1
                        do
                        {
                            getline(file,str);
                            len=str.length();
                        }
                        while(!(str[len-2]=='*' && str[len-1]=='/')); //用循环的方式去掉多行注释
                        getline(file,str);
                    }
                }
            }
            cout<<cnt<<"  "<<str<<endl;//每次输出行号以及一行源代码
            cnt++;
        }
    }
    return 0;
}

