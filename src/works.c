#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int tmp = 0;
  int used = 1;
  for (int i=0; i<n; i++){
    if (tmp + A[i] <= m){
      tmp += A[i];
    }else if(A[i] <= m){
      used += 1;
      tmp = A[i];
    }else{
      return 0;
    }
  }
  return used <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  //p(m): 一番仕事量の多い人の仕事量はm以下であるとき, 必要な人数はk人以下である.
  //ub : k人以下で済む最小の「最大の仕事量X」を見つければok.
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
