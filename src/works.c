#include <stdio.h>

int n;
int k;
int A[100000];

// 全ての人の仕事量をnum以下にして配分できるか判定する関数
int work_check(int num);

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1e9;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(work_check(mid) == 1) ub = mid;
    else lb = mid;
  }

  printf("%d\n", ub);

  return 0;
}

int work_check(int num){
  int cnt, sum, i;
  cnt = 0;
  sum = 0;
  for(i = 0; i < n; i++){
    sum += A[i];

    // numよりも大きい仕事量を持つ時間があった場合は0を返す
    if(A[i] > num) return 0;

    // 仕事量がnumを超えたらi時間目の仕事を次の人に交代する
    if(sum > num){
      cnt += 1;
      sum = A[i];
    }
  }

  // k人で仕事を分配できなかった場合は0を返す
  if(cnt >= k) return 0;
  else return 1;
}