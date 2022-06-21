#include <stdio.h>

int n;
int k;
int A[100000];

int p(int A[], int x){ //仕事量がx以下になるようにする  
  int member = 0;
  int work = 0;
  int i=0;
  while((member<k)&&(i<n)){
    if(work+A[i]<=x){
      work += A[i];
      i++;
    }else{
      member++;
      work = 0;
    }
  }
  //printf("%d %d\n", i, member);
  return i == n ? 1 : 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1e4;
  while (ub-lb>1){
    int mid = (lb+ub)/2;
    if(p(A, mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n",ub);
  return 0;
}
