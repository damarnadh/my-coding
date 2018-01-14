#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node*next;
};
void printll(struct node * temp)
{
     while(temp!=NULL)
     {
	  cout<<temp->data<<" ";
	  temp=temp->next;
     }
}
struct node*front=NULL;
struct node*rear=NULL;
void enqueue()
{
     struct node * new_node=(struct node*)malloc(sizeof(struct node));
     int var;
     cin>>var;
     new_node->data=var;
     if(front==NULL&&rear==NULL)
     {
	  new_node->next=NULL;
	  front=rear=new_node;
	  printll ( front );
	  return;
     }
     else
     {
	  rear->next=new_node;
	  rear=new_node;
     }
     printll ( front );
}
void dequeue ()
{
     struct node *temp;
     if (front==NULL)
     {
	  return;
     }
     temp=front;
     front=front->next;
     free(temp);
     printll( front );
}
void operation()
{
     cout<<"\n1.ENQUEUE\n2.DEQUEUE\nEnter your choice\n";
     int var1;
     cin>>var1;
     if ( var1==1)
     {
	  cout<<"\nenter elements to push\n";
	  enqueue();
	  operation();
     }
     else if (var1==2)
     {
	  dequeue();
	  operation();
     }
     else
     {
	  return;
     }
}
void main()
{
     clrscr();
     operation();
     getch();
}