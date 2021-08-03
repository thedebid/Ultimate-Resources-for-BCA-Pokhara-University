/* Program of list using array */
# include<stdio.h>
# define MAX 20

int arr[MAX];
int n;  /*Total number of elements in the list */

main()
{
	int  choice,item,pos;
	while(1)
	{
		printf("1.Input list\n");
		printf("2.Insert\n");
		printf("3.Search\n");
		printf("4.Delete\n");
		printf("5.Display\n");
		printf("6.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter the number of elements to be entered : ");
			scanf("%d",&n);
			input(n);
			break;
		 case 2:
			insert();
			break;
		 case 3:
			printf("Enter the element to be searched : ");
			scanf("%d", &item);
			pos = search(item);
			if(pos >= 1)
				printf("%d found at position %d\n",item,pos);
			else
				printf("Element not found\n");
			break;
		 case 4:
			del();
			break;
		 case 5:
			display();
			break;
		 case 6:
			exit();
			break;
		 default:
			printf("Wrong choice\n");
		} /*End of switch */
	}/*End of while */
}/*End of main() */

input()
{
	int i;
	for(i = 0; i< n ; i++)
	{
		printf("Input value for element %d : ", i+1);
		scanf("%d", &arr[i]);
	}
}/*End of input()*/

int search(int item)
{
	int i;
	for(i=0; i < n; i++)
	{
		if(item == arr[i])
			return(i+1);
	}
	return(0);  /* If element not found */
}/*End of search()*/

insert()
{
	int temp,item,position;
	if(n == MAX)
	{
		printf("List overflow\n");
		return;
	}
	printf("Enter position for insertion : ");
	scanf("%d", &position);
	printf("Enter the value : ");
	scanf("%d",&item);
	if(position > n+1 )
	{
		printf("Enter position less than or equal to %d\n",n+1);
		return;
	}
	if( position == n+1 )  /*Insertion at the end */
	{
		arr[n] = item;
		n = n+1;
		return;
	}
	/* Insertion in between */
	temp=n-1;
	while( temp >= position-1)
	{
		arr[temp+1] = arr[temp];  /* shifting right */
		temp --;
	}
	arr[position-1] = item;
	n = n +1 ;
}/*End of insert()*/

del()
{
	int temp,position,item;
	if(n == 0)
	{
		printf("List underflow\n");
		return;
	}
	printf("Enter the element to be deleted : ");
	scanf("%d",&item);
	if(item==arr[n-1]) /*Deletion at the end*/
	{
		n = n-1;
		return;
	}
	position=search(item);
	if(position==0)
	{
		printf("Element not present in array\n");
		return;
	}
	/*Deletion in between */
	temp=position-1;
	while(temp <= n-1)
	{
		arr[temp] = arr[temp+1];  /* Shifting left */
		temp ++;
	}
	n = n - 1 ;
}/*End of del()*/

display()
{
	int i;
	if(n==0)
	{
		printf("List is empty\n");
		return;
	}
	for(i = 0; i< n; i++)
		printf("Value at position %d : %d\n", i+1, arr[i]);
}/*End of display()*/


