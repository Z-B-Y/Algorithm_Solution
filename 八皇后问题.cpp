# include <iostream>
# include <stdio.h>
using namespace std;
int count;
bool hang[8];   //��¼ÿһ���Ƿ�ռ��
int P[8];       //��¼ÿһ�лʺ���к�

void hou(int y){
	   if (y == 9){         //�Ϸ���������ʱǰ8�о��ɷŻʺ�
	   	cout++;
		return;
	   }
	   
	   for (int x = 1;x <= 8;i++){         //���x��
			if(hang[x] == false){                      //��x��û�лʺ�
			bool flag = true;                          //��ռ�ô���
			for (int pre = 1;pre < y;pre++){       //����֮ǰÿһ�еĻʺ�
				
			if(abs(y - pre)==abs(x - P[pre]))        //��index�лʺ���к�Ϊx��pre�лʺ���к�Ϊ P[pre]
		 {
		 	flag = false;            //����ǰ�Ļʺ�����ͻ����x�в��ܷţ��ͷ���ռ�õ���
		 	break;
         }
        }
            if(flag == true){                 //��֮ǰ�Ļʺ�û�г�ͻ
			   P[y] =  x;                  //��y�лʺ�������Ϊx
			   hang[x] = true;
			   hou(y+1);
			   hang[x] = false;
			}
  }

  }


			}
			
			
			
			
			


