#include<stdio.h>
#include<string.h>

void quickSort (char items[][10], int left, int right){ 
    int i, j;
  char *x;
  char temp[10];
  
  i = left;
  j = right;
  x = items[(left+right)/2];
 
do {
    while((strcmp(items[i],x) < 0) && (i < right)) {
       i++;
    }
    while((strcmp(items[j],x) > 0) && (j > left)) {
        j--;
    }
    if(i <= j) {
      strcpy(temp, items[i]);
      strcpy(items[i], items[j]);
      strcpy(items[j], temp);
      i++;
      j--;
   }
  } while(i <= j);

  if(left < j) {
     quickSort(items, left, j);
  }
  if(i < right) {
     quickSort(items, i, right);
  }
}

void quickSortMain(char items[][10], int count)
{
  quickSort(items, 0, count-1);
}

int main(){
	int jumlah;
	char a[][10]={};
	scanf("%d",&jumlah);
	int i,j;
	for(i=0;i<jumlah;i++){
		scanf("%s",a[i]);
		getchar();
	}
	quickSortMain(a,jumlah);
	for(j=0;j<jumlah;j++){
		printf("%s ",a[j]);
	}
}
