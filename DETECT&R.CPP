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
void createloop(struct node*head1)
{
    head1->next->next->next->next->next=head1->next->next;
    cout<<"\nloop created";
}
void detectandremoveloop(struct node *head)
{
    if (head == NULL || head->next == NULL)
    {
	return;
    }
    struct node *slow = head, *fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while (fast && fast->next)
    {
	if (slow == fast)
	{
	     break;
	}
	slow = slow->next;
	fast = fast->next->next;
    }
    if (fast != NULL)
    {
	cout<<"\nloop not detected";
	cout<<"\npress 1 to create loop";
	int var3;
	cin>>var3;
	if (var3 == 1)
	{
	     createloop(head);
	}
    }
    else
    {
	cout<<"\nloop detected";
    }
    if (slow == fast)
    {
	slow = head;
	while (slow->next != fast->next)
	{
	    slow = slow->next;
	    fast = fast->next;
	}
	fast->next = NULL;
	cout<<"\nloop detected is removed";
    }
}
void main()
{
     clrscr();
     struct node*head_ref1=NULL;
     cout<<"\nEnter number of elements of list1";
     int i,var1,var2;
     cin>>var1;
     cout<<"\nenter elements\n";
     for (i=1;i<=var1;i++)
     {
	  int data1;
	  cin>>data1;
	  create(&head_ref1, data1);
     }
     printll (head_ref1);
     cout<<"\n1.create loop \n2.Detect and remove loop\nEnter your choice\n";
     cin>>var2;
     switch (var2)
     {
	  case 1:
	  {
	       createloop(head_ref1);
	       cout<<"\npress 1 to Detect and remove loop";
	       int var3;
	       cin>>var3;
	       if (var3 == 1)
	       {
		    detectandremoveloop(head_ref1);
	       }
	       break;
	  }
	  case 2:
	  {
	       detectandremoveloop(head_ref1);
	       break;
	  }
	  default :
	  {
	       break;
	  }
     }
     getch();
}