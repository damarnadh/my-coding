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
void  endnode (struct node* start)
{
     struct node *fast,*slow;
     fast=slow=start;
     cout<<"\nEnter number of node from last in a list\n";
     int key,count = 0;
     cin>>key;
     if (start != NULL )
     {
	 while (count<key)
	 {
	      if(fast == NULL)
	      {
		   cout<<key<<" is greater than the number of nodes in the list";
		   return;
	      }
	      fast=fast->next;
	      count++;
	 }
	 while (fast!=NULL)
	 {
	      fast=fast->next;
	      slow=slow->next;
	 }
	 cout<<"\nThe node is:\n"<<slow->data;
     }
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
     endnode ( head_ref1 );
     getch();
}