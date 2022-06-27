#include <stdio.h>

int n;
int k;
int A[100000];

/*
  p が [0 0, ..., 0, 1, 1, ..., 1] となるようにしたいので、今回は lb を返すことにした。
  よって最終的な ub を槍をk本作れない長さの最小値にするために、p は （槍の総数）< k とする。
*/

int p(int m){
  int i, spear;
  spear = 0;
  for(i = 0; i < n; i++){
    spear += A[i]/ m;
  }
  return (long long int) spear < k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1e9 + 1;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }

  printf("%d\n", lb);

  return 0;
}
