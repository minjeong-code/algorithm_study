10814 나이순 정렬 - 기수 정렬.c

//문제: 온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다. 이때, 회원들을 나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오

/*입력: 첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)
둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다. 
나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수이고, 이름은 알파벳 대소문자로 이루어져 있고, 길이가 100보다 작거나 같은 문자열이다. 
입력은 가입한 순서로 주어진다.*/

/*출력: 첫째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 나이가 같으면 가입한 순으로 한 줄에 한 명씩 나이와 이름을 공백으로 구분해 출력한다.*/

//solved idea: 단순 블루투포스
//메모리: 22메가, 시간: 56ms

#include <stdio.h>
#include <stdlib.h>
typedef struct Person{
    int age;
    char name[102];
}Person;

void radixSortFun(Person * persons, int N){
	int maxValue = 0;

	Person* result =(Person*)malloc(sizeof(Person)*N);

	for(int i=0;i<N;i++){
		if(maxValue < persons[i].age)	
			maxValue = persons[i].age;
	}

	for(int exp=1;exp<=maxValue;exp*=10){

		int count[10]={0};
		for(int i=0;i<N;i++) {
			count[persons[i].age/exp%10]++;
		}

		for(int i=1;i<10;i++) count[i]+=count[i-1];
	
		for(int i=N-1;i>=0;i--){
			int j = persons[i].age/exp%10;
			result[count[j]-1] = persons[i];
			count[j]--;
		}

		for(int i=0;i<N;i++)
			persons[i] = result[i];
	}

	free(result);
}

int main(){
    int N;
    scanf("%d",&N);
    
    Person * persons = (Person*)malloc(sizeof(Person)*N);
    
    for(int i=0;i<N;i++)
        scanf("%d %s", &persons[i].age, persons[i].name);
    
	radixSortFun(persons,N);
	
	for(int i=0;i<N;i++){
	    printf("%d %s\n", persons[i].age, persons[i].name);
	}
}
