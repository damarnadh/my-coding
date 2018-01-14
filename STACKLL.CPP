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
struct node*top=NULL;
void push()
{
     struct node * new_node=(struct node*)malloc(sizeof(struct node));
     int var;
     cin>>var;
     new_node->data=var;
     if(top==NULL)
     {
	  new_node->next=NULL;
	  top=new_node;
     }
     else
     {
	  new_node->next=top;
	  top=new_node;
     }
     printll ( top );
}
void pop ()
{
     struct node *temp;
     if (top==NULL)
     {
	  return;
     }
     temp=top;
     top=top->next;
     free(temp);
     printll( top );
}
void operation()
{
     cout<<"\n1.PUSH\n2.POP\nEnter your choice\n";
     int var1;
     cin>>var1;
     if ( var1==1)
     {
	  cout<<"\nenter elements to push\n";
	  push();
	  operation();
     }
     else if (var1==2)
     {
	  pop();
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