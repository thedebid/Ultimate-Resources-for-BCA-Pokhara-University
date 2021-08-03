/* Program of queue using circular linked list*/
# include <stdio.h>
# include <malloc.h>

struct node
{
	int info;
	struct node *link;
}*rear=NULL;

main()
{
	int choice;
	while(1)
	{
		printf("1.Insert \n");
		printf("2.Delete \n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			insert();
			break;
		 case 2:
			del();
			break;
		 case 3:
			display();
			break;
		 case 4:
			exit();
		 default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}/*End of main()*/

insert()
{
	int num;
	struct node *q,*tmp;
	printf("Enter the element for insertion : ");
	scanf("%d",&num);
	tmp= malloc(sizeof(struct node));
	tmp->info = num;

	if(rear == NULL) /*If queue is empty */
	{
		rear = tmp;
		tmp->link = rear;
	}
	else
	{
		tmp->link = rear->link;
		rear->link = tmp;
		rear = tmp;
	}
}/*End of insert()*/

del()
{
	struct node *tmp,*q;
	if(rear==NULL)
	{
		printf("Queue underflow\n");
		return;
	}
	if( rear->link == rear )  /*If only one element*/
	{
		tmp = rear;
		rear = NULL;
		free(tmp);
		return;
	}
	q=rear->link;
	tmp=q;
	rear->link = q->link;
	printf("Deleted element is %d\n",tmp->info);
	free(tmp);
}/*End of del()*/

display()
{
	struct node *q;
	if(rear == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	q = rear->link;
	printf("Queue is :\n");
	while(q != rear)
	{
		printf("%d ", q->info);
		q = q->link;
	}
	printf("%d\n",rear->info);
}/*End of display()*/
