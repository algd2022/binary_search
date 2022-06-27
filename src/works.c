#include <stdio.h>

int n;
int k;
int A[100000];

/*
  一人当たりの仕事量がx以下となるように仕事を配分したとき
  必要な人数がk人以下か判定する
*/
int p(int x) {
  int res = 1;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] > x) return 0;
    if (sum + A[i] > x) {
      sum = 0;
      res++;
    }
    sum += A[i];
  }
  return res <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 100000000;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (p(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n", ub);
  return 0;
}
