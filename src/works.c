#include <stdio.h>

int n;
int k;
int A[100000];

int p(m){
//�d����m�ȉ���k�l�Ɏd����U��邩����

int worker = 1;//�����������l��
int i = 0;
int capacity = m;//��l������̎d���̃L���p
while(i < n){//����if��True�ɂȂ����Ƃ������J�E���g�ł���悤��while���g�p
  
  if(worker > k){//for���g��Ȃ����߁A�J�E���g��������worker������������ꍇ�̑΍�Ƃ���k�𒴂����ꍇ�ɋ����I��
    return 0;  
  }
  if(capacity - A[i]>= 0){//���̂P���ԂŃL���p���}�C�i�X�ɂȂ�������
    capacity -= A[i];//�L���p���ꎞ�ԕ��������炷
    i++;
   }
  else{
   capacity = m;//�L���p��m�ɖ߂�
   
   worker++;//��サ����J�E���g+1
  }
 }
return 1; //���[�v�𔲂�����K��True
 
}
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
lb = 0;
ub =1000000000;
while(ub - lb > 1){
 
 int mid = (lb + ub )/ 2;  
  if (p(mid)){
      ub = mid;
      }
  else{
      lb = mid;
    }
    
 }
 printf("%d\n", ub);
 return 0;
}