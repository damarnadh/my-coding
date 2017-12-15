#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
     int data;
     struct node *next;
};
int i, n, p, m, key;
void insbegin( struct node* *temp )
{
     struct node*new_node = (struct node*)malloc(sizeof(struct node));
     cout<<"ENTER ELEMENT TO INSERT";
     cin>>m;
     new_node->dat a= m;
     if ( *temp == NULL )
     {
	  new_node->next = NULL;
	  *temp = new_node;
     }
     else
     {
	  new_node->next = *temp;
	  *temp = new_node;
     }
}
void insmid( struct node* a )
{
     if( a == NULL )
     {
	  return;
     }
     struct node *new_node = (struct node*)malloc(sizeof(struct node));
     cout<<"ENTER ELEMENT TO INSERT";
     cin>>m;
     cout<<"ENTER POSITION TO INSERT";
     cin>>key;
     for(i = 1; i <= key; i++)
     {
	  if ( i == key )
	  {
	       new_node->data = m;
	       new_node->next = a->next;
	       a->next = new_node;
	  }
	  a = a->next;
     }
}
void inslast( struct node *a )
{
     struct node *new_node = (struct node*)malloc(sizeof(struct node));
     cout<<"ENTER ELEMENT TO INSERT";
     cin>>m;
     new_node->data = m;
     new_node->next = NULL;
     struct node *last = a;
     if ( a == NULL)
     {
	  a = new_node;
	  return;
     }
     while ( last->next != NULL )
     {
	  last = last->next;
	  last->next = new_node;
	  return;
     }
}
void deletion(struct node *a)
{
     cout<<"\n1.Delete node by element \n2.Delete node by position \n";
     int x;
     cin>>x;
     if(x == 1)
     {
	  struct node *temp = a,*prev;
	  cout<<"Enter the element to delete";
	  cin>>key;
	  if(temp != NULL && temp->data==key)
	  {
	       a = temp->next;
	       free ( temp );
	       return;
	  }
	  while ( temp != NULL && temp->data != key )
	  {
	       prev = temp;
	       temp = temp->next;
	  }
	  if (temp == NULL)
	  {
	       return;
	  }
	  prev->next = temp->next;
	  free(temp);
     }
     else
     {
	  if (a == NULL)
	  {
	       return;
	  }
	  struct node *temp = a;
	  cout<<"Enter the position to delete";
	  cin>>key;
	  if ( key == 0 )
	  {
	       a = temp->next;
	       free(temp);
	       return;
	  }
	  for(i = 0; temp != NULL && i < key-1; i++)
	  {
	       temp = temp->next;
	  }
	  if(temp == NULL ||temp->next == NULL)
	  {
	       return;
	  }
	  struct node *next=temp->next->next;
	  free(temp->next);
	  temp->next = next;
     }
}
void printll(struct node *n)
{
     while(n != NULL)
     {
	  cout<<n->data<<" ";
	  n = n->next;
     }
}
void operation(struct node *head)
{
     cout<<"\n1.insertion at begining \n2.insertion at middle \n3.insertion at last \n4.deletion at given position\n";
     cout<<"Enter your choice";
     cin>>p;
     {
	  switch( p )
	  {
	       case 1:
	       {
		    insbegin( &head );
		    printll( head );
		    operation( head );
		    break;
	       }
	       case 2:
	       {
		    insmid( head );
		    printll( head );
		    operation( head );
		    break;
	       }
	       case 3:
	       {
		    inslast( head );
		    printll( head );
		    operation( head );
		    break;
	       }
	       case 4:
	       {
		    deletion( head );
		    printll( head );
		    operation( head );
		    break;
	       }
	       default:
	       {
		    break;
	       }
	  }
     }
}
void main()
{
     clrscr();
     struct node * head_ref = NULL;
     operation( head_ref );
     getch();
}
