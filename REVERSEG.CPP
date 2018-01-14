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
struct node* reverse (struct node* start,int key)
{
     struct node *current,*next,*head,*prev=NULL;
     current=start;
     int pass_key=key;
     while (key!=0)
     {
	 next=current->next;
	 current->next=prev;
	 prev=current;
	 current=next;
	 key--;
     }
     head=prev;
     while (prev->next!=NULL)
     {
	 prev=prev->next;
     }
     if (current!=NULL)
     {
	 prev->next=reverse( current,pass_key);
     }
     return head;

}
struct node* reverse_groups (struct node* start)
{
     struct node *current,*next,*head,*prev=NULL;
     current=start;
     cout<<"\nEnter number of elements in a group\n";
     int key;
     cin>>key;
     int pass_key=key;
     while (key!=0)
     {
	 next=current->next;
	 current->next=prev;
	 prev=current;
	 current=next;
	 key--;
     }
     head=prev;
     while (prev->next!=NULL)
     {
	 prev=prev->next;
     }
     prev->next=reverse( current,pass_key);
     return head;
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
     head_ref2=reverse_groups( head_ref1 );
     printll ( head_ref2 );
     getch();
}