#include <stdio.h>

int n;
int k;
int A[100000];

int dlength(int x){
  if (x != 0){
    int s = 0;
    for (int i = 0; i < n; i++){
      s = s + A[i]/x;
    }
    return s < k;
  }
  else{
    return 0;
  }
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = -1;
  ub = 100000000+1;
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
