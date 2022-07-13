#include <stdio.h>

int n;
int k;
int A[100000];
int p (int hold){// means if one bag can hold (hold) apples, how many(bag) bag should be used.
  int bag = 0;
  for (int i=0;i<n;i++){
    bag += (A[i]+hold-1)/hold;

  }
  return (bag<=k);
}

int main(){
  int i, lb=0, ub=1000000000;
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
    printf("%d\n", ub);

  return 0;
}
