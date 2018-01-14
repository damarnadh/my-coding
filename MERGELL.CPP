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
struct node* merge(struct node*temp1,struct node*temp2)
{
     if (temp1==NULL)
     {
	  return temp2;
     }
     if (temp2==NULL)
     {
	  return temp1;
     }
     struct node*result;
     if ( temp1->data<temp2->data )
     {
	  result=temp1;
	  result->next=merge(temp1->next,temp2);
     }
     else
     {
	  result=temp2;
	  result->next=merge(temp1,temp2->next);
     }
     return result;
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
     cout<<"\nEnter number of elements of list2\n";
     int var2;
     cin>>var2;
     cout<<"\nenter elements\n";
     for (i=1;i<=var2;i++)
     {
	  int data2;
	  cin>>data2;
	  create(&head_ref2, data2);
     }
     printll ( head_ref2 );
     merge ( head_ref1, head_ref2);
     cout<<"\nafter merging: \n";
     printll ( head_ref1 );
     getch();
}