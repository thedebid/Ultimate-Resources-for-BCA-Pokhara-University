/*Program of sorting using selection sort*/
#include <stdio.h>
#define MAX 20

main()
{
	int arr[MAX], i,j,k,n,temp,smallest;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d", &arr[i]);
	}
	printf("Unsorted list is : \n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	/*Selection sort*/
	for(i = 0; i< n - 1 ; i++)
	{
		/*Find the smallest element*/
		smallest = i;
		for(k = i + 1; k < n ; k++)
		{
			if(arr[smallest] > arr[k])
				smallest = k ;
		}
		if( i != smallest )
		{
			temp = arr [i];
			arr[i] = arr[smallest];
			arr[smallest] = temp ;
		}
		printf("After Pass %d elements are :  ",i+1);
		for (j = 0; j < n; j++)
			printf("%d ", arr[j]);
		printf("\n");
	}/*End of for*/
	printf("Sorted list is : \n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}/*End of main()*/



