/* Program of stack using array*/
#include<stdio.h>
#define MAX 5

int top = -1;
int stack_arr[MAX];

main()
{
	int choice;
	while(1)
	{
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1 :
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
		 default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}/*End of main()*/

push()
{
	int pushed_item;
	if(top == (MAX-1))
		printf("Stack Overflow\n");
	else
	{
		printf("Enter the item to be pushed in stack : ");
		scanf("%d",&pushed_item);
		top=top+1;
		stack_arr[top] = pushed_item;
	}
	return 0;
}/*End of push()*/

pop()
{
	if(top == -1)
		printf("Stack Underflow\n");
	else
	{
		printf("Popped element is : %d\n",stack_arr[top]);
		top=top-1;

		 }
	return 0;
}/*End of pop()*/

display()
{
	int i;
	if(top == -1)
		printf("Stack is empty\n");
	else
	{
		printf("Stack elements :\n");
		for(i = top; i >=0; i--)
			printf("%d\n", stack_arr[i] );
	}
	return 0;
}/*End of display()*/
