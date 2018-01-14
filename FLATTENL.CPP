#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node*right;
     struct node*down;
};
void printll(struct node * temp)
{
     while(temp!=NULL)
     {
	  cout<<temp->data<<" ";
	  temp=temp->down;
     }
}
void create(struct node* *temp )
{
     struct node * new_node=(struct node*)malloc(sizeof(struct node));
     new_node->right=NULL;
     int var;
     cin>>var;
     new_node->data=var;
     if(*temp==NULL)
     {
	  new_node->down=NULL;
	  *temp=new_node;
     }
     else
     {
	  new_node->down=*temp;
	  *temp=new_node;
     }
}
struct node*merge(struct node*temp1,struct node*temp2)
{
     if (temp1==NULL)
     {
	  return temp2;
     }
     if (temp2==NULL)
     {
	  return temp1;
     }
     struct node *result;
     if (temp1->data<temp2->data)
     {
	  result=temp1;
	  result->down=merge(temp1->down,temp2);
     }
     else
     {
	  result=temp2;
	  result->down=merge(temp1,temp2->down);
     }
     return result;
}
struct node*flatten(struct node*root)
{
     if (root==NULL || root->right ==NULL)
     {
	  return root;
     }
     return merge(root,flatten(root->right));
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
	  create( &head_ref1 );
     }
     cout<<"right list";
     cin>>var1;
     cout<<"\nenter elements\n";
     for (i=1;i<=var1;i++)
     {
	  create( &head_ref1->right );
     }
     cout<<"Right list";
     cin>>var1;
     cout<<"\nenter elements\n";
     for (i=1;i<=var1;i++)
     {
	  create( &head_ref1->right->right );
     }
     cout<<"right list";
     cin>>var1;
     cout<<"\nenter elements\n";
     for (i=1;i<=var1;i++)
     {
	  create( &head_ref1->right->right->right );
     }
     printll ( head_ref1 );
     printll ( head_ref1->right );
     printll ( head_ref1->right->right );
     printll ( head_ref1->right->right->right );
     flatten ( head_ref1 );
     cout<<"\nafter flattening :\n";
     printll ( head_ref1 );
     getch();
}