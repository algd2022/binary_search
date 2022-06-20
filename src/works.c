#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){ // 連続作業量がmを超えたら交代し. 作業人数がk人を超えたらアウト
  int i;
  int l = 0;  // 連続作業量
  int s = 1;  // 作業人数
  for(i = 0;i < n; i++){
    if(A[i] > m) return 0; // 一時間の作業量がmを超えたらアウト
    l += A[i];  // 連続作業量をプラス
    if(l > m){
      i--;  // 時間を戻す
      s++;  // 作業人数をプラス
      l = 0; // 連続作業料をリセット
    }
    if(s > k) return 0;
  }
  return 1;
}

int main(){
  int i, lb, ub;
  lb = 1;
  ub = 1000000000;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }

  if(p(ub)){
    printf("%d", ub);
  }
  else{
    printf("%d", lb);
  }
  return 0;
}