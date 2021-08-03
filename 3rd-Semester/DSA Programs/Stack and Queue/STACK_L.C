/* Program of stack using linked list*/
# include<stdio.h>
# include<malloc.h>

struct node
{
	int info;
	struct node *link;
} *top=NULL;

main()
{
	int choice;
	while(1)
	{      	printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice : ") ;
		scanf("%d", &choice);

		switch(choice)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(1);
		default :
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}/*End of main() */

push()
{
	struct node *tmp;
	int pushed_item;
	tmp = (struct node *)malloc(sizeof(struct node));
	printf("Input the new value to be pushed on the stack : ");
	scanf("%d",&pushed_item);
	tmp->info=pushed_item;
	tmp->link=top;
	top=tmp;
}/*End of push()*/

pop()
{
	struct node *tmp;
	if(top == NULL)
		printf("Stack is empty\n");
	else
	{       tmp=top;
		printf("Popped item is %d\n",tmp->info);
		top=top->link;
		free(tmp);
	}

}/*End of pop()*/

display()
{       struct node *ptr;
	ptr=top;
	if(top==NULL)
		printf("Stack is empty\n");
	else
	{
		printf("Stack elements :\n");
		while(ptr!= NULL)
		{
			printf("%d\n",ptr->info);
			ptr = ptr->link;
		}/*End of while */
	}/*End of else*/
}/*End of display()*/
