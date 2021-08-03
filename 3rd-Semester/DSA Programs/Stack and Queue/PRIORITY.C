/* Program of priority queue using linked list*/
# include<stdio.h>
# include<malloc.h>

struct node
{
	int priority;
	int info;
	struct node *link;
}*front = NULL;

main()
{
	int choice;
	while(1)
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);

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
			exit(1);
		 default :
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}/*End of main()*/

insert()
{
	struct node *tmp,*q;
	int added_item,item_priority;
	tmp = (struct node *)malloc(sizeof(struct node));
	printf("Input the item value to be added in the queue : ");
	scanf("%d",&added_item);
	printf("Enter its priority : ");
	scanf("%d",&item_priority);
	tmp->info = added_item;
	tmp->priority = item_priority;
	/*Queue is empty or item to be added has priority more than first item*/
	if( front == NULL || item_priority < front->priority )
	{
		tmp->link = front;
		front = tmp;
	}
	else
	{
		q = front;
		while( q->link != NULL && q->link->priority <= item_priority )
			q=q->link;
		tmp->link = q->link;
		q->link = tmp;
	}/*End of else*/
}/*End of insert()*/

del()
{
	struct node *tmp;
	if(front == NULL)
		printf("Queue Underflow\n");
	else
	{
		tmp = front;
		printf("Deleted item is %d\n",tmp->info);
		front = front->link;
		free(tmp);
	}
}/*End of del()*/

display()
{
	struct node *ptr;
	ptr = front;
	if(front == NULL)
		printf("Queue is empty\n");
	else
	{	printf("Queue is :\n");
		printf("Priority       Item\n");
		while(ptr != NULL)
		{
			printf("%5d        %5d\n",ptr->priority,ptr->info);
			ptr = ptr->link;
		}
	}/*End of else */
}/*End of display() */




