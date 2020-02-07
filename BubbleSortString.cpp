#include <stdio.h>
#include<string.h>

int main()
{
    int  n, c, d;
  scanf("%d", &n);

  char array[100][100],swap[100];
  for (c = 0; c < n; c++)
    scanf("%s", &array[c]);

  for (c = 0 ; c < n - 1; c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (strcmp(array[d],array[d+1]) > 0)/* For decreasing order use < */
      {
        strcpy(swap,array[d]);//swap       = array[d];
        strcpy(array[d],array[d+1]);//rray[d]   = array[d+1];
        strcpy(array[d+1],swap);//array[d+1] = swap;
      }
    }
  }
  for (c = 0; c < n; c++)
     printf("%s ", array[c]);

  return 0;
}
