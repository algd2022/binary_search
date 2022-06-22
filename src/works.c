#include <stdio.h>

int n;
int k;
int A[100000];

int p(x){
  unsigned int mem = 0, works = 0, i = 0;
  while((mem<k) && (i<n)){
    works += A[i];
    if(works <= x) i++; //最大仕事量をxで抑える
    else{ //抑えられない時は次の人を呼ぶ
      mem++;
      works = 0;
    }
  }
  if(i==n) return 1; //i==nの時は全ての仕事の分配をxで抑えられているのでxは小さくできる。
  else return 0; //人数がkを超えているので、xを増やす。
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0; 
  ub = 1000000001; 
  while(ub-lb>1){
    int mid = (lb + ub)/2;
    if(p(mid)) ub = mid;
    else lb = mid;
    //printf("ub:%d, mid:%d, lb:%d\n", ub, mid, lb);
  }

  printf("%d\n", ub);

  return 0;
}
