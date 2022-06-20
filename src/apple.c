#include <stdio.h>

int n;
int k;
int A[100000];

int bag(int m){
    int j, bag_count=0;
    for (j = 0; j < n; j++) {
        bag_count = bag_count + (A[j] + m - 1) / m; //Ø‚èã‚°
    }
    return (long long int) bag_count <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;               //x:æ‚è‚¤‚éÅ¬1 = •Ô‚è’l0
  ub = 1000000000;      //x:æ‚è‚¤‚éÅ‘å10^9 = •Ô‚è’l1

  while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (bag(mid)) {
          ub = mid;
      }
      else {
          lb = mid;
      }
  }

  printf("%d\n", ub);       //ã‚©‚ç—}‚¦‚é
  return 0;
}
