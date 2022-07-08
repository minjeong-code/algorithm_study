#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int x;
	int y;
	int count;
}Per;


int main() {
	int N;
	scanf("%d", &N);
	Per * per = (Per *)malloc(sizeof(Per) *N);
	for (int i = 0; i<N; i++) {
		scanf("%d %d", &(per[i].x), &(per[i].y));
		per[i].count = 1;
	}

	for(int i=0;i<N;i++){
	    for(int j=0;j<N;j++){
	        if(i==j) continue;

        	if(per[i].x < per[j].x && per[i].y < per[j].y)
        	    (per[i].count)++;
    	}
	}

	for(int i=0;i<N;i++){
    	printf("%d ", per[i].count);
	}

}