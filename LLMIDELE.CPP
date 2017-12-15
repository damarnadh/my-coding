#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
     int data;
     struct node*next;
};
void insbegin(struct node* * a)
{
     struct node*new_node = (struct node*)malloc(sizeof(struct node));
     int m;
     cout<<"\n ENTER ELEMENT TO INSERT";
     cin>>m;
     new_node->data = m;
     if(*a == NULL)
     {
          new_node->next = NULL;
          *a = new_node;
     }
     else
     {
          new_node->next = *a;
          *a = new_node;
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
void middle(struct node*a)
{
     struct node*x = a;
     struct node*y = a;
     if(a->next == NULL)
     {
          return;
     }
     while(x!=NULL&x->next!=NULL)
     {
          x = x->next->next;
          y = y->next; 
     }
     cout<<"THE mid element is"<<y->data;
}
void sortedinsert(struct node* a)
{
     struct node* current;
     struct node* new_node;
     cout<<"Enter the element";
     cin>>new_node->data;
     if ( a == NULL || a->data >= new_node->data)
     {
          new_node->next = a;
          a = new_node;
     }
     else
     {
          current = a;
          while( current->next != NULL && current->next->data < new_node->data)
          {
               current = current->next;
          }
          new_node->next = current->next;
          current->next = new_node;
     }
     printll(a);
}
void secondlast(struct node*a)
{
     struct node *x, *y; 
     x = a->next;
     y = a;
     if( a->next == NULL )
     {
          return;
     }
     while( x != NULL & x->next != NULL)
     {
          x=x->next;
          y=y->next;
     }
     cout<<"THE second last element is"<<y->data;
}
void rlliteration( struct node *a )
{
     struct node *prev = NULL;
     struct node *current = a;
     struct node *next;
     while (current != NULL)
     {
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
     }
     a=prev;
     printll(a);
 }
 void rllrecursion(struct node *a)
 {
      struct node *f;
      struct node *r;
      if(a == NULL)
      {
           return;
      }
      f=a;
      r = f->next;
      if(r == NULL)
      {
           return;
      }
      rllrecursion(r);
      f->next->next = f;
      f->next = NULL;
      a = r;
      printll(a);
 }
void operation(struct node *head)
{
     cout<<"\n1.insertion \n2.middle element \n3.second last element\n4.reverse ll with iteration\n5.reverse ll with recursion\n6.sortedinsert\nenter your choice";
     int p;
     cin>>p;
     if ( p == 1 ) 
     {
          insbegin( &head );
          printll( head );
          operation( head );
     }
     else if( p == 2 )
     {
          middle( head );
          operation( head );
     }
     else if( p == 3 )
     {
          secondlast( head );
          operation( head );
     }
     else if( p == 4 )
     {
          rlliteration( head );
          operation( head );
     }
     else if( p == 5 )
     {
          rllrecursion( head );
          operation( head );
     }
     else if(p == 6 )
     {
          sortedinsert( head );
          operation( head );
     }
     else
     { 
          return;
     }
}
void main()
{
     clrscr();
     struct node* head_ref = NULL;
     operation( head_ref );
     getch();
}
