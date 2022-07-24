1427 소트인사이드.c

#include<stdio.h>
#include<math.h>
int main(){
	int N,tempN,len;
	int arr[10];

	scanf("%d",&N);
	
	tempN = N;

	for(len = 1;tempN!=0;len++){
		arr[len-1] = tempN % 10;
		tempN = tempN * 0.1;
	}

	for(int i=0;i<len-2;i++){
		for(int j=0;j<len-2-i;j++){
            if(arr[j]<arr[j+1]){
        		int temp = arr[j];
        		arr[j] = arr[j+1];
        		arr[j+1] = temp;
            }
        }
	}

	for(int i=0;i<len-1;i++)
		printf("%d",arr[i]);

	return 0;
}