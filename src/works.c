#include <stdio.h>

int n;
int k;
int A[100000];


//「各人の仕事量がxを超えないとき，必要な人数はk人以下である．」という命題p
int p(int x){
  int wokers_required = 1;      //必要な人数
  int shigoto = 0;              //とある人に割り振られる仕事
  for(int i = 0; i < n; i++ ){   
    if(shigoto + A[i] <= x){    //既に割り振られたshigotoに新たにA[i]を加えてm時間以内に終わるか．
      shigoto += A[i];          //もし終わるなら割り振る．
    }else if(A[i] <= x){        //終わらないなら次の人に回す．ただしm時間以内の仕事なら．
      shigoto=A[i];
      wokers_required++;        //もう一人，人が必要です．
    }else{
      return 0;                 //m時間で終わらない仕事ならFalse
    }
  }
  return wokers_required <= k;  //workers_requiredがk人以下のときTrue．
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  
  //「一番仕事量が多い人の仕事量がx時間以下」はp(x)と同等
  //p(x)は単調非減少．p(x)=1なるxの最小値を求めたい．
  lb=0;
  ub=1e9; //一人で全部やるとき最悪 max(n)*max(a) の仕事．
  while(ub - lb > 1){
    int mid = (ub + lb)/2;
    if (p(mid)){
      ub = mid;
    }else{
      lb=mid;
    }
  }
  printf("%d\n",ub);
  return 0;
}
