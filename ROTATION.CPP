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
void create(struct node* *temp, int var)
{
     struct node * new_node=(struct node*)malloc(sizeof(struct node));
     new_node->data=var;
     if(*temp==NULL)
     {
	  new_node->next=NULL;
	  *temp=new_node;
     }
     else
     {
	  new_node->next=*temp;
	  *temp=new_node;
     }
}
struct node* rotate (struct node* start)
{
     struct node *prev=NULL,*current,*next,*temp;
     prev=current=start;
     cout<<"\nEnter node from which rotation should begin:\n";
     int key;
     cin>>key;
     while(key!=1)
     {
	  current=current->next;
	  key--;
     }
     next=current->next;
     current->next=NULL;
     temp=next;
     while(temp->next!=NULL)
     {
	  temp=temp->next;
     }
     temp->next=prev;
     return next;
}
void main()
{
     clrscr();
     struct node*head_ref1=NULL;
     struct node*head_ref2=NULL;
     cout<<"\nEnter number of elements of list1\n";
     int i,var1;
     cin>>var1;
     cout<<"\nenter elements\n";
     for (i=1;i<=var1;i++)
     {
	  int data1;
	  cin>>data1;
	  create(&head_ref1, data1);
     }
     printll ( head_ref1 );
     head_ref2=rotate( head_ref1 );
     printll ( head_ref2 );
     getch();
}