2750 수 정렬하기.c

#include <stdio.h>

int main(){
	int N;
	int arr[1000];

	scanf("%d",&N);

	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
    /*버블정렬*/
	for(int i=0;i<N-1;i++){
		for(int j=0;j<N-1-i;j++){
            if(arr[j]>arr[j+1]){
        		int temp = arr[j];
        		arr[j] = arr[j+1];
        		arr[j+1] = temp;
            }
        }
	}

	for(int i=0;i<N;i++)
		printf("%d\n",arr[i]);
}