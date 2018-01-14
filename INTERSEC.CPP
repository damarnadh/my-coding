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
void intersect_node (struct node*temp1,struct node*temp2)
{
     struct node*head1=temp1;
     struct node*head2=temp2;
     int count1=0;
     int count2=0;
     while (temp1!=NULL)
     {
	  temp1=temp1->next;
	  count1++;
     }
     cout<<"\nlength of list1="<<count1;
     while (temp2!=NULL)
     {
	  temp2=temp2->next;
	  count2++;
     }
     cout<<"\nlength of list2="<<count2;
     if (count1>count2)
     {
	  int d=count1-count2;
	  int i;
	  for ( i=1;i<=d;i++ )
	  {
	       head1=head1->next;
	  }
     }
     else
     {
	  int d=count2-count1;
	  int i;
	  for ( i=1;i<=d;i++ )
	  {
	       head2=head2->next;
	  }
     }
     while ( head1->data!=head2->data )
     {
	  head1=head1->next;
	  head2=head2->next;
     }
     cout<<"\nThe intersection node is"<<head1->data;
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
     head_ref1->next->next->next->next=head_ref2->next->next;
     cout<<"\nafter intersection\n";
     printll ( head_ref1 );
     cout<<"\n";
     printll ( head_ref2 );
     intersect_node( head_ref1, head_ref2 );
     getch();
}