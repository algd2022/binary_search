#include <stdio.h>

int n;
int k;
int A[100000];

// (x時間以下の時間ずつ仕事量を分割したときの最小分割数) <= k を満たすとき p = 1 とする 
int p(int x){
  // 一番仕事量が多い人の仕事量は　(A[i]の最大値)　時間以上である
  for (int i = 0; i < n; i++){
    if (A[i] > x)  return 0; 
  }
  
  // x時間以下の時間ずつ仕事量を分割したときの最小分割数を求める
  int count = 0;  // count は (分割数) - 1 を表す
  int sum = 0;
  int b[100000];    
  
  b[0] = 0;

  for (int i = 0; i < n; i++){
    sum += A[i];
    if (sum - b[count] > x){
      b[++count] = sum - A[i];
    }
  }

  return count < k; 
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000000;

  while (ub - lb > 1) {
    int mid = (ub + lb) / 2;
    if (p(mid))  ub = mid;
    else lb = mid;
  }

  printf("%d\n", ub);  

  return 0;
}