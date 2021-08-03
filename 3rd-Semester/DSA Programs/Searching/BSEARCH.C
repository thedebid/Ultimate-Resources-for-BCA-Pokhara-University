/*Program for binary search*/
#include <stdio.h>

main()
{
	int arr[20],start,end,middle,n,i,item;

	printf("How many elements you want to enter in the array : ");
	scanf("%d",&n);
	for(i=0; i < n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be searched : ");
	scanf("%d",&item);
	start=0;
	end=n-1;
	middle=(start+end)/2;
	while(item != arr[middle] && start <= end)
	{
		if(item > arr[middle])
			start=middle+1;
		else
			end=middle-1;
		middle=(start+end)/2;
	}
	if(item==arr[middle])
		printf("%d found at position %d\n",item,middle+1);
	if(start>end)
		printf("%d not found in array\n",item);
}/*End of main()*/
