#include <stdio.h>

//10689 수 정렬하기3
//제한시간: 3초, 메모리: 8M

//첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.
//해석: N을 다저장하면 10M 메모리가 소모되므로 모든 입력값을 저장하는 것은 배제하고 생각해봐야한다.

//counting 정렬

int main(){
	int N;
	int count[10001]={0};

	scanf("%d",&N);

	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		count[temp]++;
	}

	for(int i=0;i<10001;i++){
		for(int j=count[temp];j>0;j--){
			printf("%d\n",i);
		}
	}
}