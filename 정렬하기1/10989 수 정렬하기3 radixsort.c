#include <stdio.h>
#include <stdlib.h>

int N = 0;
int * arr=NULL;

//10989번 수 정렬 하기
//제한시간: 3초, 메모리: 8M

//첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.
//해석: N을 다저장하면 10M 메모리가 소모되므로 모든 입력값을 저장하는 것은 배제하고 생각해봐야한다.

//기수정렬: 추가적인 메모리공간이 많이 필요하기 때문에 메모리 초과 현상이 일어난다. 시간 복잡도는 dN

void radixSortFun(){
	int maxValue = 0;
	

	int* result =(int*)malloc(sizeof(int)*N);

	for(int i=0;i<N;i++){
		if(maxValue < arr[i])	
			maxValue = arr[i];
	}

	for(int exp=1;exp<=maxValue;exp*=10){

		int count[10]={0};
		for(int i=0;i<N;i++) {
			count[arr[i]/exp%10]++;
		}

		for(int i=1;i<10;i++) count[i]+=count[i-1];
	
		for(int i=N-1;i>=0;i--){
			int j = arr[i]/exp%10;
			result[count[j]-1] = arr[i];
			count[j]--;
		}

		for(int i=0;i<N;i++)
			arr[i] = result[i];
	}

	free(result);
}

int main(){
	scanf("%d",&N);

	arr = (int*)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);
	
	radixSortFun();

	for(int i=0;i<N;i++)
		printf("%d\n",arr[i]);

	return 0;
}