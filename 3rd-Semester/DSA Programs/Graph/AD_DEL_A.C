/* Program for addition and deletion of nodes and edges in a graph
   using adjacency matrix */
#include<stdio.h>
#define max 20
int adj[max][max];
int n;
main()
{
	int choice;
	int node,origin,destin;

	create_graph();
	while(1)
	{
		printf("1.Insert a node\n");
		printf("2.Insert an edge\n");
		printf("3.Delete a node\n");
		printf("4.Delete an edge\n");
		printf("5.Dispaly\n");
		printf("6.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			insert_node();
			break;
		 case 2:
			printf("Enter an edge to be inserted : ");
			fflush(stdin);
			scanf("%d %d",&origin,&destin);
			insert_edge(origin,destin);
			break;
		 case 3:
			printf("Enter a node to be deleted : ");
			fflush(stdin);
			scanf("%d",&node);
			delete_node(node);
			break;
		 case 4:
			printf("Enter an edge to be deleted : ");
			fflush(stdin);
			scanf("%d %d",&origin,&destin);
			del_edge(origin,destin);
			break;
		 case 5:
			display();
			break;
		 case 6:
			exit();
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
	max_edges=n*(n-1); /* Taking directed graph */

	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d( 0 0 ) to quit : ",i);
		scanf("%d %d",&origin,&destin);
		if((origin==0) && (destin==0))
			break;
		if( origin > n || destin > n || origin<=0 || destin<=0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
			adj[origin][destin]=1;
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

insert_node()
{
	int i;
	n++;    /*Increase number of nodes in the graph*/
	printf("The inserted node is %d \n",n);
	for(i=1;i<=n;i++)
	{
		adj[i][n]=0;
		adj[n][i]=0;
	}
}/*End of insert_node()*/

delete_node(char u)
{
	int i,j;
	if(n==0)
	{
		printf("Graph is empty\n");
		return;
	}
	if( u>n )
	{
		printf("This node is not present in the graph\n");
		return;
	}
	for(i=u;i<=n-1;i++)
	   for(j=1;j<=n;j++)
	   {
		adj[j][i]=adj[j][i+1];  /* Shift columns left */
		adj[i][j]=adj[i+1][j];  /* Shift rows up */
	   }
	n--; /*Decrease the number of nodes in the graph */
}/*End of delete_node*/

insert_edge(char u,char v)
{
	if(u > n)
	{
		printf("Source node does not exist\n");
		return;
	}
	if(v > n)
	{
		printf("Destination node does not exist\n");
		return;
	}
	adj[u][v]=1;
}/*End of insert_edge()*/

del_edge(char u,char v)
{
     if(u>n || v>n || adj[u][v]==0)
     {
	printf("This edge does not exist\n");
	return;
     }
     adj[u][v]=0;
}/*End of del_edge()*/


