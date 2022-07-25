1181 단어정렬.c
//시간제한: 2초, 메모리제한: 256MB
//문제: 알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.
//1. 길이가 짧은 것부터
//2. 길이가 같으면 사전 순으로

//입력: 첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 
//둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 
//주어지는 문자열의 길이는 50을 넘지 않는다.

//출력: 조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.

//solved idea
//1. 입력받을 때 기존에 입력받은 같은 값이 없을 때만 arr에 저장한다.(중복값 전처리)
//2. merge sort(길이먼저 비교하고 길이가 같을 때는 word순서로 비교한다.)

//메모리: 3308KB, 시간: 668ms

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Word{
	int len;
    char word[52];
}Word;

Word * sorted;

void merge(Word list[], int left, int mid, int right){
  int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;

  /* 분할 정렬된 list의 합병 */
  while(i<=mid && j<=right){
    if(list[i].len<list[j].len)
        sorted[k++] = list[i++];
    else if(list[i].len==list[j].len){
        for(int a=0;a<list[i].len;a++){
            if(list[i].word[a]==list[j].word[a]) continue;
            
            if(list[i].word[a]<list[j].word[a]){
                sorted[k++] = list[i++];
                break;
            }
            else{
                sorted[k++] = list[j++];
                break;
            }
            
        }
    }else
      sorted[k++] = list[j++];
  }

  // 남아 있는 값들을 일괄 복사
  if(i>mid){
    for(l=j; l<=right; l++)
      sorted[k++] = list[l];
  }
  // 남아 있는 값들을 일괄 복사
  else{
    for(l=i; l<=mid; l++)
      sorted[k++] = list[l];
  }

  // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
  for(l=left; l<=right; l++){
    list[l] = sorted[l];
  }
}

// 합병 정렬
void merge_sort(Word list[], int left, int right){
  int mid;

  if(left<right){
    mid = (left+right)/2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
    merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
    merge_sort(list, mid+1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
    merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
  }
}

int main(){
    int N;
    scanf("%d",&N);
    
    Word * words = (Word*)malloc(sizeof(Word)*N);
    sorted= (Word*)malloc(sizeof(Word)*N);
    int count=0;
    for(int i=0;i<N;i++){
    	char new[52];
        scanf("%s", new);
        
        int k;
        
        int exist = 0;
        for(int j=0;j<i;j++){
            if(strcmp(words[j].word,new)==0){
                exist =1;
                break;
            }
        }
        if(exist==0){
            for(k=0;k<strlen(new);k++)
                words[count].word[k] = new[k];
            words[count].word[k] = '\0';
            
            words[count].len = strlen(new);
            count++;
        }

       
    }
    
	merge_sort(words, 0,count-1);
	
	for(int i=0;i<count;i++){
	    printf("%s\n", words[i].word);
	}
}