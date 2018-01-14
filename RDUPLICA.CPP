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
     struct node*new_node=(struct node*)malloc(sizeof(struct node));
     int m;
     cout<<"\n ENTER ELEMENT TO INSERT";
     cin>>m;
     new_node->data=m;
     if(*a==NULL)
     {
          new_node->next=NULL;
         *a=new_node;
     }
     else
     {
          new_node->next=*a;
         *a=new_node;
     }
}
void printll(struct node*n)
{
     while(n!=NULL)
     {
          cout<<n->data<<" ";
          n=n->next;
     }
}
void rduplicate(struct node*a)
{
     struct node*ptr1,*ptr2,*dup;
     ptr1=a;
     while(ptr1!=NULL&&ptr1!=NULL)
     {
          ptr2=ptr1;
          while(ptr2->next!=NULL)
          {
               if(ptr1->data==ptr2->next->data)
               {
                    dup=ptr2->next;
                    ptr2->next=ptr2->next->next;
                    free(dup);
               }
               else
               {
                    ptr2=ptr2->next;
               }
          }
          ptr1=ptr1->next;
     }
}
void operation(struct node*head_r)
{
     cout<<"1.INSERTION\n2.REmove dUPLIcate\nENTER YOUR CHOICE";
     int x;
     cin>>x;
     switch(x)
     {
          case 1:
          {
               insbegin(&head_r);
               printll(head_r);
               operation(head_r);
               break;
          }
          case 2:
          {
               rduplicate(head_r);
               printll(head_r);
               operation(head_r);
               break;
          }
          default:
          {
               return;
          }
     }
}
void main()
{
     clrscr();
     struct node*head=NULL;
     operation(head);
     getch();
}