/* Program of queue using linked list*/
# include<stdio.h>
# include<malloc.h>

struct node
{
	int info;
	struct node *link;
}*front=NULL,*rear=NULL;

main()
{
	int choice;
	while(1)
	{       printf("1.Insert\n");
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
	struct node *tmp;
	int added_item;
	tmp = (struct node *)malloc(sizeof(struct node));
	printf("Input the element for adding in queue : ");
	scanf("%d",&added_item);
	tmp->info = added_item;
	tmp->link=NULL;
	if(front==NULL)		 /*If Queue is empty*/
		front=tmp;
	else
		rear->link=tmp;
	rear=tmp;
}/*End of insert()*/

del()
{
	struct node *tmp;
	if(front == NULL)
		printf("Queue Underflow\n");
	else
	{
		tmp=front;
		printf("Deleted element is  %d\n",tmp->info);
		front=front->link;
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
	{
		printf("Queue elements :\n");
		while(ptr != NULL)
		{
			printf("%d ",ptr->info);
			ptr = ptr->link;
		}
		printf("\n");
	}/*End of else*/
}/*End of display()*/
