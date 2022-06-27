#include <stdio.h>

int n;
int k;
int A[100000];

int p(m){
//仕事量m以下でk人に仕事を振れるか判定

int worker = 1;//今動員した人数
int i = 0;
int capacity = m;//一人当たりの仕事のキャパ
while(i < n){//下のifがTrueになったときだけカウントできるようにwhileを使用
  
  if(worker > k){//forを使わないため、カウントが増えずworkerが増え続ける場合の対策としてkを超えた場合に強制終了
    return 0;  
  }
  if(capacity - A[i]>= 0){//次の１時間でキャパがマイナスになったら交代
    capacity -= A[i];//キャパを一時間分だけ減らす
    i++;
   }
  else{
   capacity = m;//キャパをmに戻す
   
   worker++;//交代したらカウント+1
  }
 }
return 1; //ループを抜けたら必ずTrue
 
}
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
lb = 0;
ub =1000000000;
while(ub - lb > 1){
 
 int mid = (lb + ub )/ 2;  
  if (p(mid)){
      ub = mid;
      }
  else{
      lb = mid;
    }
    
 }
 printf("%d\n", ub);
 return 0;
}