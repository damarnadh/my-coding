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
void create(struct node* *temp )
{
     struct node * new_node=(struct node*)malloc(sizeof(struct node));
     int var;
     cin>>var;
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
void sort (struct node*head)
{
     int count[3]={0,0,0};
     struct node*ptr=head;
     while (ptr != NULL )
     {
	  count[ptr->data]+=1;
	  ptr=ptr->next;
     }
     int i=0;
     ptr=head;
     while (ptr != NULL)
     {
	  if (count[i]==0)
	  {
	       i++;
	  }
	  else
	  {
	       ptr->data=i;
	       count[i]--;
	       ptr=ptr->next;
	  }
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
	  create(&head_ref1 );
     }
     printll ( head_ref1 );
     sort (head_ref1 );
     cout<<"\nAfter sorting \n";
     printll ( head_ref1 );
     getch();
}