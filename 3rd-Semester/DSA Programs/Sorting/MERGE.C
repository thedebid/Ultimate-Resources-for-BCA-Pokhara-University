/* Program of merging two sorted arrays into a third sorted array*/
#include<stdio.h>

main()
{
	int arr1[20],arr2[20],arr3[40];
	int i,j,k;
	int max1,max2;

	printf("Enter the number of elements in list1 : ");
	scanf("%d",&max1);
	printf("Take the elements in sorted order :\n");
	for(i=0;i<max1;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr1[i]);
	}
	printf("Enter the number of elements in list2 : ");
	scanf("%d",&max2);
	printf("Take the elements in sorted order :\n");
	for(i=0;i<max2;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr2[i]);
	}
	/* Merging */
	i=0;  	/*Index for first array*/
	j=0;  	/*Index for second array*/
	k=0;  	/*Index for merged array*/

	while( (i < max1) && (j < max2) )
	{
		if( arr1[i] < arr2[j] )
			arr3[k++]=arr1[i++];
		else
			arr3[k++]=arr2[j++];
	}/*End of while*/
	/*Put remaining elements of arr1 into arr3*/
	while( i < max1 )
		arr3[k++]=arr1[i++];
	/*Put remaining elements of arr2 into arr3*/
	while( j < max2 )
		arr3[k++]=arr2[j++];

	/*Merging completed*/
	printf("List 1 :  ");
	for(i=0;i<max1;i++)
		printf("%d ",arr1[i]);
	printf("\nList 2 :  ");
	for(i=0;i<max2;i++)
		printf("%d ",arr2[i]);
	printf("\nMerged list : ");
	for(i=0;i<max1+max2;i++)
		printf("%d ",arr3[i]);
	printf("\n");
}/*End of main()*/