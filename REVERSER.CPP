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
void reverse_recursion(struct node*temp)
{
     struct node*first;
     struct node*rest;
     if(temp==NULL)
     {
	  return;
     }
     first=temp;
     rest=first->next;
     if(rest==NULL)
     {
	  return;
     }
     reverse_recursion(rest);
     first->next->next=first;
     first->next=NULL;
     temp=rest;
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
     cout<<"After revering:";
     reverse_recursion ( head_ref1 );
     printll(head_ref1);
     getch();
}