#include <stdio.h>

int n;
int k;
int A[100000];

int p(int spear_length);

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000001;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      lb = mid;
    }
    else{
      ub = mid;
    }
  }

  printf("%d\n", lb);

  return 0;
}

int p(int spear_length){
  int spear_num = 0;
  int i;

  for(i = 0; i < n; i++){
    spear_num += A[i] / spear_length;
  }
  
  if(spear_num >= k) return 1;
  else return 0;
}