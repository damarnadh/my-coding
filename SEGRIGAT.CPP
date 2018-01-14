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
void segrigate_even_odd(struct node*temp)
{
     struct node *current=temp;
     struct node *even_head=NULL, *odd_head=NULL, *last_even=NULL, *last_odd=NULL;
     while (current != NULL)
     {
	  if (current->data%2 == 0)
	  {
	      if (even_head == NULL)
	      {
		   even_head=last_even=current;
	      }
	      else
	      {
		   last_even->next=current;
		   last_even=current;
	      }
	  }
	  else
	  {
	      if (odd_head == NULL)
	      {
		   odd_head=last_odd=current;
	      }
	      else
	      {
		   last_odd->next=current;
		   last_odd=current;
	      }
	  }
	  current=current->next;
     }
     cout<<"\nAfter segrigation :\n";
     if (even_head==NULL)
     {
	   printll(odd_head);
     }
     last_even->next=odd_head;
     last_odd->next=NULL;
     printll(even_head);
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
     segrigate_even_odd (head_ref1);
     getch();
}