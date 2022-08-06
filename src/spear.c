#include <stdio.h>

int n;
int k;
int A[100000];

int dlength(int x){
    int s = 0;
    for (int i = 0; i < n; i++){
      s = s + A[i]/x;
    }
    return s < k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000+1;
  while (ub - lb > 1){
    int m = (lb + ub)/2;
    if(dlength(m)){
      ub = m;
    }
    else{
      lb = m;
    }
  }
  printf("%d\n", lb);
  return 0;
}
