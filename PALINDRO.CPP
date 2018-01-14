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
struct node* reverse (struct node* start)
{
     struct node *prev=NULL,*current,*next;
     current=start;
     while(current!=NULL)
     {
	  next=current->next;
	  current->next=prev;
	  prev=current;
	  current=next;
     }
     return prev;
}
void check_palindrome (struct node*temp1,struct node*temp2)
{
     while (temp1!=NULL &&temp2!=NULL)
     {
	  if(temp1->data==temp2->data)
	  {
	       temp1=temp1->next;
	       temp2=temp2->next;
	  }
	  else
	  {
	       cout<<"\nit is not palindrome";
	       return;
	  }
     }
     cout<<"\nit is palindrome";
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
     check_palindrome ( head_ref1, reverse( head_ref1 ) );
     getch();
}