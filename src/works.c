#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int woker_num = 1;//仕事量をx以下に抑えるために必要な人数を数える
  int work_amount = 0;//仕事量　初期値0
  int i;
  for(i = 0; i < n; i++){
    if(A[i] > x) return 0;//１回でxを超える仕事量がある場合0
    //次の時間の仕事量を足してもxを超えないなら仕事を追加
    if(work_amount + A[i] <= x){
      work_amount = work_amount + A[i];
    }
    //超えてしまうなら人数を一人増やし仕事量をA[i]にリセット
    else{
      woker_num++;
      work_amount = A[i];
    }
  }
  //最終的に使った人数がk以下なら1を返す
  return woker_num <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  //A[i]*nの最大値がub
  lb = 0;
  ub = 1000000000;
  while(ub -lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
