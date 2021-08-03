/*Program of sorting using address calculation sort*/
#include<stdio.h>
#include<malloc.h>
#define MAX 20

struct  node
{
	int info ;
	struct node *link;
};
struct node *head[10];
int n,i,arr[MAX];
main()
{

	int i;
	printf("Enter the number of elements in the list : ");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}/*End of for */

	printf("Unsorted list is :\n");
	for(i=0;i<n;i++)
		printf("%d  ",arr[i]);
	printf("\n");
	addr_sort();
	printf("Sorted list is :\n");
	for(i=0;i<n;i++)
		printf("%d  ",arr[i]);
	printf("\n");
}/*End of main()*/

addr_sort()
{
	int i,k,dig;
	struct node *p;
	int addr;
	k=large_dig();
	for(i=0;i<=9;i++)
		head[i]=NULL;
	for(i=0;i<n;i++)
	{
		addr=hash_fn( arr[i],k );
		insert(arr[i],addr);
	}

	for(i=0; i<=9 ; i++)
	{
		printf("head(%d) -> ",i);
		p=head[i];
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->link;
		}
		printf("\n");
	}

	/*Taking the elements of linked lists in array*/
	i=0;
	for(k=0;k<=9;k++)
	{
		p=head[k];
		while(p!=NULL)
		{
			arr[i++]=p->info;
			p=p->link;
		}
	}
}/*End of addr_sort()*/

/*Inserts the number in sorted linked list*/
insert(int num,int addr)
{
	struct node *q,*tmp;
	tmp= malloc(sizeof(struct node));
	tmp->info=num;
	/*list empty or item to be added in begining */
	if(head[addr] == NULL || num < head[addr]->info)
	{
		tmp->link=head[addr];
		head[addr]=tmp;
		return;
	}
	else
	{
		q=head[addr];
		while(q->link != NULL && q->link->info < num)
			q=q->link;
		tmp->link=q->link;
		q->link=tmp;
	}
}/*End of insert()*/

/* Finds number of digits in the largest element of the list */
int large_dig()
{

	int large = 0,ndig = 0 ;

	for(i=0;i<n;i++)
	{
		if(arr[i] > large)
			large = arr[i];
	}
	printf("Largest Element is %d , ",large);
	while(large != 0)
	{
		ndig++;
		large = large/10 ;
	}

	printf("Number of digits in it are %d\n",ndig);
	return(ndig);
} /*End of large_dig()*/

hash_fn(int number,int k)
{
	/*Find kth digit of the number*/
	int digit,addr,i;
	for(i = 1 ; i <=k ; i++)
	{
		digit = number % 10 ;
		number = number /10 ;
	}
	addr=digit;
	return(addr);
}/*End of hash_fn()*/

/*
hash_fn(int number,int k)
{

	int addr,i,large=0;
	float tmp;

	for(i=0;i<n;i++)
	{
		if(arr[i] > large)
			large = arr[i];
	}
	tmp=(float)number/large;
	addr=tmp*9;
	return(addr);
}/*End of hash_fn()*/



