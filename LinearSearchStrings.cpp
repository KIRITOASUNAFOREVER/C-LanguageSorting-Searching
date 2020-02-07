#include <stdio.h>
#include<string.h>
int main()
{
  char array[100][100], search;
  int c, n;

  printf("Enter number of elements in array\n");
  scanf("%d", &n);

  printf("Enter %d String(s)\n", n);

  for (c = 0; c < n; c++)
    scanf("%s", &array[c]);

  printf("Enter a word to search\n");
  scanf("%s", &search);

  for (c = 0; c < n; c++)
  {
    if (strcmp(array[100][c],search)==0)//array[c] == search)    /* If required element is found */
    {
      printf("%s is present at location %d.\n", search, c+1);
      break;
    }
  }
  if (c == n)
    printf("%s isn't present in the array.\n", search);

  return 0;
}
