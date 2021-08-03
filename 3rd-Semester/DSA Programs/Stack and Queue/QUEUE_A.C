/*Program of queue using array*/
# include<stdio.h>
# define MAX 5

int queue_arr[MAX];
int rear = -1;
int front = -1;

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
		scanf("%d",&choice);

		switch(choice)
		{
		case 1 :
			insert();
			break;
		case 2 :
			del();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(1);
		default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}/*End of main()*/

insert()
{
	int added_item;
	if (rear==MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if (front==-1)  /*If queue is initially empty */
			front=0;
		printf("Input the element for adding in queue : ");
		scanf("%d", &added_item);
		rear=rear+1;
		queue_arr[rear] = added_item ;
	}
	return;
}/*End of insert()*/

del()
{
	if (front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		return ;
	}
	else
	{
		printf("Element deleted from queue is : %d\n", queue_arr[front]);
		front=front+1;
	}
	return ;
}/*End of del() */

display()
{
	int i;
	if (front == -1)
		printf("Queue is empty\n");
	else
	{
		printf("Queue is :\n");
		for(i=front;i<= rear;i++)
			printf("%d  ",queue_arr[i]);
		printf("\n");
	}
	return;
}/*End of display() */
