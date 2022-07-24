#include <stdio.h>

//2751번 수 정렬하기 2
//시간제한: 2초 , 메모리제한 256MB

/*문제*/ 
//첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 
//이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

//해결
//힙정렬 알고리즘을 사용했다.
//시간복잠도: NlogN , 메모리: 4M
#include <stdio.h>

int heapSize =0;
int arr[1000001];
void push(int n){

	int i = heapSize;
	while(i!=1 && arr[i/2] >n){
		arr[i] = arr[i/2];
		i = i/2;
	}
	arr[i] = n;
	
}

int pop(){
	int min = arr[1];
	int temp = arr[heapSize--];
	int i = 1;
	while(i<heapSize){
	    
	    if(i*2 <= heapSize && arr[i*2] < temp && arr[i*2] < arr[i*2+1]){
		    arr[i] = arr[i*2];
			i = i*2;
		}else if(i*2+1 <= heapSize && arr[i*2+1] < temp && arr[i*2] > arr[i*2+1]){
		     arr[i] = arr[i*2+1];
			i = i*2+1;
		}else 
			break;
	}
	arr[i] =  temp;
	return min; 
}

int main(){
	int N,n;

	scanf("%d",&N);
	
	for(int i=1;i<N+1;i++){
		heapSize++;
		scanf("%d",&n);
		push(n);
	}
	
	for(int i=1;i<N+1;i++){
		printf("%d\n", pop());
	}
}