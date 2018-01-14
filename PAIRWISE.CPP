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
void swap (struct node* start)
{
     struct node *temp,*temp1,*temp2,*new_start;
     temp1=start;
     new_start=start->next;
     while (1)
     {
	  temp2=temp1->next;
	  temp=temp2->next;
	  temp2->next=temp1;
	  if (temp==NULL || temp->next==NULL)
	  {
	       temp1->next=NULL;
	       break;
	  }
	  temp1->next=temp->next;
	  temp1=temp;
     }
     printll ( new_start );
}
void main()
{
     clrscr();
     struct node*head_ref1=NULL;
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
     cout<<"\nAfter swapping:\n";
     swap ( head_ref1 );
     getch();
}