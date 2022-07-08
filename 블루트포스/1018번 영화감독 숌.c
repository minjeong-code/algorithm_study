#include <stdio.h>
#define swap(x) x = (x == 0) ? 1 : 0;

int main(){
	int n,m;
	int min;
	
	scanf("%d %d",&n,&m);
	char arr[51][51];
	int chess[51][51];
	
	for(int i=0;i<n;i++){
		scanf("%s",&arr[i][0]);
		for(int j=0;j<n;j++){
		    chess[i][j] = (arr[i][j] == 'W')? 0 : 1;
		}
	}
	
	for(int i=0;i<n-7;i++){
	    for(int j=0;j<m-7;j++){
	        
	        for(int startColor = 0; startColor<2 ; startColor++){
	            int start = startColor;
	            int count=0;
	            for(int l=i;l<i+8;l++){
            	    int cur = start;
            	    for(int k=j;k<j+8;k++){
            	          printf("%d %d, ",cur,chess[l][k]);
            	        	if(cur != chess[l][k]){
            	        	    count++;
            	        	}
            	        	    
            	        	swap(cur);
            	    }
            	    printf("\n");
            	    swap(start);
        	    }
        	      printf("count: %d, ",count);
        	    if(i==0 && j==0 && startColor ==0) min = count;
               
        	    if(min > count) {
        	        min = count;
        	    }
        	    printf("min: %d, \n",min);
	        }
	    }
	}
    printf("%d",min);
	
}