//
// レポート課題1用ヘッダファイル
//

#ifndef _R1_SORT_H_
#define _R1_SORT_H_

#include <stdlib.h> // for rand(), srand(), malloc(), free()
#include <time.h> // for clock()
#include <limits.h> // for constants

clock_t r1_start_time;

//
// 配列用データを生成する関数
//
int *gen_data(int n, int seed, int mode, float r)
{
  int i;
  int *data;

  srand(seed);
  data = (int *)malloc(sizeof(int) * n); // 配列用のメモリ確保

  switch(mode) {

  case 1: // 全て乱数を格納
    for (i=0; i<n; i++) {
      data[i] = rand();
    }
    break;

  case 2: // 部分ソート済みデータを格納
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

  case 3: // 逆順ソート済みデータを格納
    for (i=0; i<n; i++) {
      data[i] = n-i;
    }
    break;

  default: // その他
    printf("error: in gen_data(), 'mode' should be set between 1 and 3.\n");
    exit(1);
  }

  return data;
}

//
// データを削除する
//
void free_data(int *data)
{
  free(data); // 確保したメモリを解放する
}

//
// ストップウォッチをセットする関数
//
void sw_set()
{
  r1_start_time = clock();
}

//
// ストップウォッチの経過時間を返す関数
//
float sw_get() 
{
  return (float)(clock() - r1_start_time) / (float)CLOCKS_PER_SEC;
}

#endif
