#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int spear = 0;
  for(int i = 0; i < n; i++){
	spear += A[i]/x;
  }
  return (long long int) spear >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000 + 1;
  while(ub - lb > 1){
	int mid = (ub + lb) / 2;
	if(p(mid)){
		lb = mid;
	} /* lbはp(lb)が成り立つことがわかっている最大の数*/
	else{
		ub = mid;
	};/* ubはp(ub)が成り立たないことがわかっている最小の数*/
  }
  printf("%d\n",lb);
  return 0;
}
