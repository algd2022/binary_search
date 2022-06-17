#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int used = 0;
    for (int i=0; i<n; i++){
      used += (A[i]+m-1)/m;
    }
  return used <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  // p(m) : りんごバッグに入れられるりんごがm個のとき, りんごを全部持ち帰れる袋の数がK個以下
  // ub : K袋以下でりんごを全部持ち帰れる最小のX
  ub = 1000000000;
  lb = 0;
  while (ub-lb>1){
    int mid = (ub+lb)/2;
    if (p(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
