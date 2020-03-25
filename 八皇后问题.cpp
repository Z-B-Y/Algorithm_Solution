# include <iostream>
# include <stdio.h>
using namespace std;
int count;
bool hang[8];   //记录每一行是否被占用
int P[8];       //记录每一列皇后的行号

void hou(int y){
	   if (y == 9){         //合法方案，此时前8列均可放皇后
	   	cout++;
		return;
	   }
	   
	   for (int x = 1;x <= 8;i++){         //查第x行
			if(hang[x] == false){                      //第x行没有皇后
			bool flag = true;                          //先占用此行
			for (int pre = 1;pre < y;pre++){       //遍历之前每一列的皇后
				
			if(abs(y - pre)==abs(x - P[pre]))        //第index列皇后的行号为x，pre列皇后的行号为 P[pre]
		 {
		 	flag = false;            //和以前的皇后发生冲突，第x行不能放，释放已占用的行
		 	break;
         }
        }
            if(flag == true){                 //跟之前的皇后都没有冲突
			   P[y] =  x;                  //第y列皇后所在行为x
			   hang[x] = true;
			   hou(y+1);
			   hang[x] = false;
			}
  }

  }


			}
			
			
			
			
			


