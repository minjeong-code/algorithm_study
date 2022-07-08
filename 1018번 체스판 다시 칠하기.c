#include <stdio.h>
#define swap(x) x = (x == 0) ? 1 : 0;

int main(){
	int n,m;
	int min =999;
	
	scanf("%d %d",&n,&m);
	char arr[51][51];
	int chess[51][51];
	
	for(int i=0;i<n;i++){
		scanf("%s",&arr[i][0]);
		for(int j=0;j<m;j++){
		    chess[i][j] = (arr[i][j] == 'W')? 0 : 1;
		}
	}
	
	for(int i=0;i<n-7;i++){
	    for(int j=0;j<m-7;j++){
	        
	        int startPoint = 0;
	        while(startPoint<2){
	            int start = startPoint;
	            int count =0;
	            
	            for(int l=i;l<i+8;l++){
            	    int cur = start;
            	    
            	    for(int k=j;k<j+8;k++){
        	        	if(cur != chess[l][k])
        	        	    count++;
        	        	swap(cur);
            	    }
            	    swap(start);
        	    }
        	    
    	        if(min > count)
    	            min = count;
    	        
    	        startPoint++;
    	    }
    	    
	    }
	}
    printf("%d",min);
	
}