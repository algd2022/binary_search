#include <stdio.h>

int n;
int k;
int A[100000];


int max_work(int m) {
    int j, work_per = 0, member = 1;
    for (j = 0; j < n; j++) {           
        if (A[j] > m) {                 //����
            member = 100001;  //�K��member > k�@
            break;      
        }

        if (A[j] + work_per > m) {      //���
            member = member + 1;
            work_per = A[j];    
        }
        else {                          //�p��
            work_per = work_per + A[j]; 
        }
    }

    return (long long int) member <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  int h, sum_work = 0;
  for (h = 0; h < n; h++) {
      sum_work = sum_work + A[h];
  }

  lb = 0;            //x:��肤��ŏ�1 = �Ԃ�l0
  ub = sum_work;   //x:��肤��ő�sum_work = �Ԃ�l1


  while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (max_work(mid)) {
          ub = mid;
      }
      else {
          lb = mid;
      }
  }

  printf("%d\n", ub);       //�ォ��}����
  return 0;
}
