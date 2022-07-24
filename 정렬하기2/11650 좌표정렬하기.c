11650 좌표정렬하기.c

//문제:2차원 평면 위의 점 N개가 주어진다. 좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

//입력:첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000) 
//좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

//출력:첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.


//solved idea: merge sort(nlogn)
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int x;
    int y;
}Coord;

Coord *sorted; // 추가적인 공간이 필요

void merge(Coord list[], int left, int mid, int right){
  int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;

  /* 분할 정렬된 list의 합병 */
  while(i<=mid && j<=right){
    if(list[i].x<list[j].x ||(list[i].x==list[j].x && list[i].y < list[j].y))
      sorted[k++] = list[i++];
    else
      sorted[k++] = list[j++];
  }

  // 남아 있는 값들을 일괄 복사
  if(i>mid){
    for(l=j; l<=right; l++)
      sorted[k++] = list[l];
  }
  // 남아 있는 값들을 일괄 복사
  else{
    for(l=i; l<=mid; l++)
      sorted[k++] = list[l];
  }

  // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
  for(l=left; l<=right; l++){
    list[l] = sorted[l];
  }
}

// 합병 정렬
void merge_sort(Coord list[], int left, int right){
  int mid;

  if(left<right){
    mid = (left+right)/2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
    merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
    merge_sort(list, mid+1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
    merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
  }
}

int main(){
	int N,x,y;
	scanf("%d",&N);
	
	Coord* arr = (Coord*)malloc(sizeof(Coord)*N);
    sorted =  (Coord*)malloc(sizeof(Coord)*N);
	    
	for(int i=0;i<N;i++){
		scanf("%d %d",&arr[i].x,&arr[i].y);
	}
	
	merge_sort(arr, 0, N-1);
	
    for(int i=0; i<N; i++){
        printf("%d %d\n",arr[i].x, arr[i].y);
    }
}
