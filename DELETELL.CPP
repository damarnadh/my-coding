#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node*next;
};

struct node*head=NULL;

void createll()
{
     cout<<"Enter the number nodes:";
     int n;
     cin>>n;
     for(int i=1;i<=n;i++)
     {
          head->data=i;
          cout<<head->data<<" ";
          head=head->next;
     }
}
void deletell()
{
     struct node*current,*next;
     current=head;
     while(head->next!=NULL)
     {
          next=current->next;
          free(current);
          current=next;
     }
     head=NULL;
     cout<<"\nThe linked list was deleted";
}
void main()
{
     clrscr();
     createll();
     deletell();
     getch();
}
