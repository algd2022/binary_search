#include <stdio.h>

int n;
int k;
int A[100000];

//仕事量x以下で仕事を振ることができるか判定する
int CanAllocateWork(int x) {
  int i;
  int work = 0;//仕事量の記録
  int countWorker = 1;//今何人動員しているか

  for(i = 0; i < n; i++){
    //各時間の仕事がそもそもxを超えていないかチェックする
    //（1時間内で仕事を割り振れないため1つでもxを超える時間があるとx以下で割り振れなくなる）
    if(A[i] > x) {
      return 0;
    }
    //まだA[i]分働ける場合その仕事量を追加
    if(work + A[i] <= x) {
      work += A[i];
    }
    //もう働けない場合次の人に交代する
    //countWorker（動員数）を1増やし、workをリセットしA[i]分の仕事を追加
    else {
      countWorker += 1;
      work = A[i];
    }
  }
  return countWorker <= k;//k人以下で割り振れたならOK
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  //初期値をそれぞれ定めるlb,ubをそれぞれ+1,-1するとCanAllocateWorkが常に不成立、成立しなくなる
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if(CanAllocateWork(mid)) {
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
