#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  //sum:1人当たりの仕事量を加算
  //counts:mを仕事量の上限として必要な人数をカウント
  int j, sum = 0, counts = 0;
  for(j = 0; j < n; j++){
    if(A[j] > m){
      return 0;
    }
    else{
      sum += A[j];
      if(sum > m){
        counts++;
        sum = A[j];
      }
      else if(sum == m){
        counts++;
        sum = 0;
      }
    }
  }
  if(sum != 0){
    counts++;
  }
  return counts <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000000;

  while(ub -lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }

  printf("%d\n", ub);
  return 0;
}
