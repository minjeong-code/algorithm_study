#include <stdio.h>
#include <math.h>

int main(){
	int N,sum =0;
	int count[8001] = {0};
	scanf("%d",&N);

	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		sum += temp;
		count[temp+4000]++;
	}
	
	int minCheck = 1;
	int maxValue = 0;
	int minValue = 0;

    int maxFreq = 0;
	int maxFreqValue = 0;
    
	int order=0;
	int center=-1;

	for(int i=0;i<8001;i++){
		if(count[i]==0) continue;
        
		if(minCheck){
		    minCheck = 0;
		    minValue = i;
		}
		maxValue = i;
        
		if(maxFreq<count[i]) {
			maxFreq = count[i];
			maxFreqValue = i;
		}
        
    	for(int j=0;j<count[i] && center==-1;j++){
            if(order == N/2) {
                center = i;
                break;
            }
            order++;
        }	
	}
    
	for(int i=maxFreqValue+1;i<8001;i++){
		if(maxFreq==count[i]){
			maxFreqValue = i;
			break;
		}
	}
	printf("%d\n", (int)round((double)sum/N));  //하나의 변수를 실수로 만들어주는 것이 중요
	printf("%d\n", center-4000);
	printf("%d\n", maxFreqValue-4000);
	printf("%d\n", maxValue - minValue);
}