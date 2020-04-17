# include <iostream>
# include <string>
using namespace std;
typedef struct person{
  char name[20];
  int score;
}person;
int main (){
  person data[100];
  int i = 0;
  while(scanf("%s:%d",&data[i].name,&data[i].score)!=EOF){
    i ++;
  }
  person temp;
  for(int j = 0;j < i; j++){
    for(int k = 0; k < i - j; k ++){
      if(data[k].score > data[k+1].score){
        temp = data[k];
        data[k] = data[k+1];
        data[k+1] = temp;
    }
    }
  }
   for(int j = i;j >= 0;j --){
       cout<<data[j].name<<":"<<data[j].score<<" ";
   }
    return 0;
  }
