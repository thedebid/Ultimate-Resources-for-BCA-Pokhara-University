/* Program of reverse linked list*/
# include <stdio.h>
# include <malloc.h>

struct node
{
	int info;
	struct node *link;
}*start;

main()
{
	int i,n,item;
	start=NULL;

	printf("How many nodes you want : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the item %d : ",i+1);
		scanf("%d",&item);
		create_list(item);
	}
	printf("Initially the linked list is :\n");
	display();
	reverse();
	printf("Linked list after reversing is :\n");
	display();
}/*End of main()*/

create_list(int num)
{
	struct node *q,*tmp;
	tmp= malloc(sizeof(struct node));
	tmp->info=num;
	tmp->link=NULL;

	if(start==NULL)
		start=tmp;
	else
	{
		q=start;
		while(q->link!=NULL)
			q=q->link;
		q->link=tmp;
	}
}/*End of create_list() */

display()
{
	struct node *q;
	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	q=start;
	while(q!=NULL)
	{
		printf("%d ", q->info);
		q=q->link;
	}
	printf("\n");
}/*End of display()*/

reverse()
{
	struct node *p1,*p2,*p3;
	if(start->link==NULL)    /*only one element*/
		return;
	p1=start;
	p2=p1->link;
	p3=p2->link;

	p1->link=NULL;
	p2->link=p1;

	while(p3!=NULL)
	{
		p1=p2;
		p2=p3;
		p3=p3->link;
		p2->link=p1;
	}
	start=p2;
}/*End of reverse() */

