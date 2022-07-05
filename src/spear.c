#include <stdio.h>

int n;
int k;
int A[100000];
int p (int m){// means if they want to create m cm's spear, how many (spear) spear can they create.
  int spear = 0;
  for (int i=0;i<n;i++){
    spear += (A[i])/m;

  }
  return (spear<k);//if spear<k, means they need reduce m
}

int main(){
  int i, lb=0, ub=100000;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  while (ub-lb>1){
      int mid = (ub+lb)/2;
      if (p(mid)){
        ub = mid;
      }else{
        lb = mid;
      }
    }
    printf("%d\n", lb);

  return 0;
}
