#include <stdio.h>

int n;
int k;
int A[100000];

int bag(int m){
    int j, bag_count=0;
    for (j = 0; j < n; j++) {
        bag_count = bag_count + (A[j] + m - 1) / m; //�؂�グ
    }
    return (long long int) bag_count <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;               //x:��肤��ŏ�1 = �Ԃ�l0
  ub = 1000000000;      //x:��肤��ő�10^9 = �Ԃ�l1

  while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (bag(mid)) {
          ub = mid;
      }
      else {
          lb = mid;
      }
  }

  printf("%d\n", ub);       //�ォ��}����
  return 0;
}
