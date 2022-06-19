#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int j;
  int humannumber = 1;
  int workquority = 0;
  for(j = 0; j < n; j++){
    if(A[j] > m){
      return 0; /* A[j]がmより大きいなら関数pは0を返す */
    } else if(workquority + A[j] <= m){
      workquority = workquority + A[j]; /* 「workquority + A[j] <= m」を満たすなら同じ人に仕事を振り分ける */
    } else{
      workquority = A[j];
      humannumber = humannumber + 1; /* それ以外なら新しい人に仕事を振り分ける */
    }
    }
  return humannumber <= k; /* 仕事を振り分けた人数がk人以下かどうか判断する */

}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
lb = 0;
ub = 1000000000;

while (ub - lb > 1){
  int mid = (lb + ub) / 2;
  if(p(mid)) ub = mid;
  else lb = mid;
}

printf("%d\n", ub);

  return 0;
}
