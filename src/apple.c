#include <stdio.h>

int n;
int k;
int A[100000];

int p(x){
  unsigned int sum=0;
  for(int i=0; i<n; i++){
    sum += (A[i] + x -1)/x;
    //printf("num:%d, i:%d\n", num, i);
    if(k<sum) return 0;
  }
  return 1;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0; //1個も入らないバッグなら、何も持ち帰れない。
  ub = 1000000000; //最大数が入るバッグなら、必ず持ち帰れるはず
  while(ub-lb>1){
    int mid = (lb + ub)/2;
    if(p(mid)) ub = mid;
    else lb = mid;
    //printf("ub:%d, mid:%d, lb:%d\n", ub, mid, lb);
  }

  printf("%d\n", ub);

  return 0;
}
