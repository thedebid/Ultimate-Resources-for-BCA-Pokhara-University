/* Program for traversing a graph through BFS and DFS */
#include<stdio.h>
#define MAX 20

typedef enum boolean{false,true} bool;
int adj[MAX][MAX];
bool visited[MAX];
int n;    /* Denotes number of nodes in the graph */
main()
{
	int i,v,choice;

	create_graph();
	while(1)
	{
		printf("\n");
		printf("1. Adjacency matrix\n");
		printf("2. Depth First Search using stack\n");
		printf("3. Depth First Search through recursion\n");
		printf("4. Breadth First Search\n");
		printf("5. Adjacent vertices\n");
		printf("6. Components\n");
		printf("7. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Adjacency Matrix\n");
			display();
			break;
		 case 2:
			printf("Enter starting node for Depth First Search : ");
			scanf("%d",&v);
			for(i=1;i<=n;i++)
				visited[i]=false;
			dfs(v);
			break;
		 case 3:
			printf("Enter starting node for Depth First Search : ");
			scanf("%d",&v);
			for(i=1;i<=n;i++)
				visited[i]=false;
			dfs_rec(v);
			break;
		 case 4:
			printf("Enter starting node for Breadth First Search : ");
			scanf("%d", &v);
			for(i=1;i<=n;i++)
				visited[i]=false;
			bfs(v);
			break;
		 case 5:
			printf("Enter node to find adjacent vertices : ");
			scanf("%d", &v);
			printf("Adjacent Vertices are : ");
			adj_nodes(v);
			break;
		 case 6:
			components();
			break;
		 case 7:
			exit(1);
		 default:
			printf("Wrong choice\n");
			break;
		 }/*End of switch*/
	}/*End of while*/
}/*End of main()*/

create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of nodes : ");
	scanf("%d",&n);
	max_edges=n*(n-1);

	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d( 0 0 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);

		if((origin==0) && (destin==0))
			break;

		if( origin > n || destin > n || origin<=0 || destin<=0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin]=1;
		}
	}/*End of for*/
}/*End of create_graph()*/

display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%4d",adj[i][j]);
		printf("\n");
	}
}/*End of display()*/

dfs_rec(int v)
{
	int i;
	visited[v]=true;
	printf("%d ",v);
	for(i=1;i<=n;i++)
		if(adj[v][i]==1 && visited[i]==false)
			dfs_rec(i);
}/*End of dfs_rec()*/

dfs(int v)
{
	int i,stack[MAX],top=-1,pop_v,j,t;
	int  ch;

	top++;
	stack[top]=v;
	while (top>=0)
	{
		pop_v=stack[top];
		top--;                      /*pop from stack*/
		if( visited[pop_v]==false)
		{
			printf("%d ",pop_v);
			visited[pop_v]=true;
		}
		else
			continue;

		for(i=n;i>=1;i--)
		{
			if( adj[pop_v][i]==1 && visited[i]==false)
			{
				top++;    /* push all unvisited neighbours of pop_v */
				stack[top]=i;
			}/*End of if*/
		}/*End of for*/
	}/*End of while*/
}/*End of dfs()*/

bfs(int v)
{
	int i,front,rear;
	int que[20];
	front=rear= -1;

	printf("%d ",v);
	visited[v]=true;
	rear++;
	front++;
	que[rear]=v;

	while(front<=rear)
	{
		v=que[front];	 /* delete from queue */
		front++;
		for(i=1;i<=n;i++)
		{
			/* Check for adjacent unvisited nodes */
			if( adj[v][i]==1 && visited[i]==false)
			{
				printf("%d ",i);
				visited[i]=true;
				rear++;
				que[rear]=i;
			 }
		}
	}/*End of while*/
}/*End of bfs()*/

adj_nodes(int v)
{
	int i;
	for(i=1;i<=n;i++)
	if(adj[v][i]==1)
		printf("%d ",i);
	printf("\n");
}/*End of adj_nodes()*/

components()
{
	int i;
	for(i=1;i<=n;i++)
		visited[i]=false;
	for(i=1;i<=n;i++)
	{
		if(visited[i]==false)
			dfs_rec(i);
	}
	printf("\n");
}/*End of components()*/

