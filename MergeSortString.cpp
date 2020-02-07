#include<stdio.h>
#include<string.h>
 
void merge(char a[][30],int i1,int j1,int i2,int j2)
{
	char temp[30][30];	//array used for merging
	int i,j,k;
	i=i1;	//beginning of the first list
	j=i2;	//beginning of the second list
	k=0;
	
	while(i<=j1 && j<=j2)	//while elements in both lists
	{
		if(strcmp(a[i],a[j])<0)//a[i]<a[j])
			strcpy(temp[k++],a[i++]);//temp[k++]=a[i++];
		else
			strcpy(temp[k++],a[j++]);//temp[k++]=a[j++];
	}
	
	while(i<=j1)	//copy remaining elements of the first list
		strcpy(temp[k++],a[i++]);//temp[k++]=a[i++];
		
	while(j<=j2)	//copy remaining elements of the second list
		strcpy(temp[k++],a[j++]);//temp[k++]=a[j++];
		
	//Transfer elements from temp[] back to a[]
	for(i=i1,j=0;i<=j2;i++,j++)
		strcpy(a[i],temp[j]);//a[i]=temp[j];
}

void mergesort(char a[][30],int i,int j)
{
	int mid;
		
	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(a,i,mid);		//left recursion
		mergesort(a,mid+1,j);	//right recursion
		merge(a,i,mid,mid+1,j);	//merging of two sorted sub-arrays
	}
}

int main()
{
	int n,i;
	char a[30][30];
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%s",&a[i]);
		
	mergesort(a,0,n-1);
	
	for(i=0;i<n;i++)
		printf("%s ",a[i]);
		
	return 0;
}
