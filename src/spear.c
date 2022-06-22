#include <stdio.h>

int n;
int k;
int A[100000];

int p(int A[], unsigned int x){
    int t = 0;
    int i = 0;
    for (i = 0; i < n; i++){
        t += A[i] / x;  /*�؂�̂Ă̌v�Z�����Ęa���Ƃ�*/
    }
    return t < k;

}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1e9 + 1;  /*1e9�̒����̑��͍���̂ŁA���Ȃ����̂̂����ŏ��̒���*/

  while(ub - lb > 1){
        int mid = (ub + lb)/2;

        if(p(A, mid)) ub = mid;
        else lb = mid;
  }
  printf("%d\n", lb);

  return 0;
}

