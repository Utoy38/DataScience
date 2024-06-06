//
// バブルソート
//
#include <stdio.h>
#include "r1_sort.h"
int main()
{
	int *data;
	int i, j; // カウンタ
	int tmp; // データの一時保管用
	float elapsed_time; // 経過時間
	
	int n = 10000; // 配列の長さ 
    int seed = 38; // 乱数のシード 
    int mode = 1; // 生成するデータのモード (1: 全てランダム、2: 部分ソート済み、3:逆順ソート済み)
    float r = 0.5; // mode=2の部分ソート済データ生成時のソート済みデータの割合
  
	// データ生成
	data = gen_data(n, seed, mode, r); 
    printf("data is genereated (n=%d, seed=%d, mode=%d, r=%f)\n", n, seed, mode, r);
	
	// ストップウォッチをセット
    sw_set();
	
	// ここからバブルソート	
    for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(data[j]>data[j+1]){
				tmp=data[j];
				data[j]=data[j+1];
			    data[j+1]=tmp;
			}
		}
	}
	// ここまでバブルソート
	
	// ストップウォッチの経過時間を取得
    elapsed_time = sw_get();
	
	// 配列後の表示
	printf("Sorted data:\n");
    for (i=0; i<n; i++) 
		printf("%d ", data[i]);
    printf("\n");

    // 結果を表示
    printf("bubble sort is finished (%f sec)\n", elapsed_time);

    // データを削除
    free_data(data);
}