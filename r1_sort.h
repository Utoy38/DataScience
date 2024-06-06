//
// ���|�[�g�ۑ�1�p�w�b�_�t�@�C��
//

#ifndef _R1_SORT_H_
#define _R1_SORT_H_

#include <stdlib.h> // for rand(), srand(), malloc(), free()
#include <time.h> // for clock()
#include <limits.h> // for constants

clock_t r1_start_time;

//
// �z��p�f�[�^�𐶐�����֐�
//
int *gen_data(int n, int seed, int mode, float r)
{
  int i;
  int *data;

  srand(seed);
  data = (int *)malloc(sizeof(int) * n); // �z��p�̃������m��

  switch(mode) {

  case 1: // �S�ė������i�[
    for (i=0; i<n; i++) {
      data[i] = rand();
    }
    break;

  case 2: // �����\�[�g�ς݃f�[�^���i�[
    if (r<0 || r>1) {
      printf("error: in gen_data(), 'r' should be set between 0 and 1.\n");
      exit(1);
    }
    for (i=0; i<(int)(n*r); i++) {
      data[i] = i;
    }
    for (i=(int)(n*r); i<n; i++) {
      data[i] = rand();
    }
    break;

  case 3: // �t���\�[�g�ς݃f�[�^���i�[
    for (i=0; i<n; i++) {
      data[i] = n-i;
    }
    break;

  default: // ���̑�
    printf("error: in gen_data(), 'mode' should be set between 1 and 3.\n");
    exit(1);
  }

  return data;
}

//
// �f�[�^���폜����
//
void free_data(int *data)
{
  free(data); // �m�ۂ������������������
}

//
// �X�g�b�v�E�H�b�`���Z�b�g����֐�
//
void sw_set()
{
  r1_start_time = clock();
}

//
// �X�g�b�v�E�H�b�`�̌o�ߎ��Ԃ�Ԃ��֐�
//
float sw_get() 
{
  return (float)(clock() - r1_start_time) / (float)CLOCKS_PER_SEC;
}

#endif
