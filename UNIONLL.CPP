#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node* next;
};
void printll(struct node*temp)
{
     while(temp!=NULL)
     {
	  cout<<temp->data<<" ";
	  temp=temp->next;
     }
}
int present (struct node *head, int data)
{
    struct node *temp = head;
    while (temp != NULL)
    {
	if (temp->data == data)
	{
	    return 1;
	}
	temp = temp->next;
    }
    return 0;
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
void unionlist(struct node *head1, struct node *head2)
{
    struct node *result = NULL;
    struct node *temp1 = head1, *temp2 = head2;
    int x;
    while (temp1 != NULL)
    {
	create(&result, temp1->data);
	temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
	 if (!present(result, temp2->data))
	 {
	      create(&result, temp2->data);
	 }
	 temp2 = temp2->next;
    }
    printll (result);
}
void intersectionlist(struct node *head1, struct node *head2)
{
    struct node *result = NULL;
    struct node *temp1 = head1;
    int x;
    while (temp1 != NULL)
    {
	if (present(head2, temp1->data))
	{
	     create (&result, temp1->data);
	}
	temp1 = temp1->next;
    }
    printll (result);
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
     printll (head_ref1);
     cout<<"\nEnter number of elements of list2\n";
     int j,var2;
     cin>>var2;
     cout<<"\nenter elements \n";
     for (j=1;j<=var2;j++)
     {
	  int data2;
	  cin>>data2;
	  create(&head_ref2, data2);
     }
     printll (head_ref2);
     cout<<"\nUnion is \n";
     unionlist (head_ref1, head_ref2);
     cout<<"\nintersection is \n";
     intersectionlist (head_ref1, head_ref2);
     getch();
}