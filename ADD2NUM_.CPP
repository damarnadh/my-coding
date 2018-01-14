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
struct node* newnode(int var)
{
     struct node*temp=NULL;
     struct node * new_node=(struct node*)malloc(sizeof(struct node));
     new_node->data=var;
     if(temp==NULL)
     {
	  new_node->next=NULL;
	  temp=new_node;
     }
     else
     {
	  new_node->next=temp;
	  temp=new_node;
     }
     return temp;
}
struct node* add(struct node*temp1,struct node*temp2)
{
     if (temp1==NULL)
     {
	  return temp2;
     }
     if (temp2==NULL)
     {
	  return temp1;
     }
     struct node*result=NULL,*temp,*prev=NULL;
     int carry=0,sum;
     while ( temp1!=NULL||temp2!=NULL )
     {
	  sum=carry+(temp1?temp1->data:0)+(temp2?temp2->data:0);
	  carry=(sum>=10)?1:0;
	  sum=sum%10;
	  temp = newnode(sum);
	  if ( result==NULL )
	  {
	       result=temp;
	  }
	  else
	  {
	       prev->next=temp;
	  }
	  prev=temp;
	  if (temp1)
	  {
	       temp1=temp1->next;
	  }
	  if (temp2)
	  {
	       temp2=temp2->next;
	  }
     }
     if (carry>0)
     {
	  temp->next=newnode(carry);
     }
     cout<<"\nafter adding: \n";
     printll(result);
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
     add ( head_ref1, head_ref2);
     getch();
}