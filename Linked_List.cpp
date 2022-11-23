#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};
struct node* root = NULL;
void deletefirst();
void deletelast();
void deletenth();
void insertatend();
void display();
int length();
void insertatbeg();
void insertafter();
int len;

//avoid using void main
//use int main instead
int main()
{   int ch;
    while(ch!=0)
    {
    printf("\n0. Quit\n");
    printf("1. Enter element at end\n");
    printf("2. Display\n");
    printf("3. Length\n");
    printf("4. Insert node at begining \n");
    printf("5. Insert node after perticular loaction \n");
    printf("6. Delete first node \n");
    printf("7. Delete last node \n");
    printf("8. Delete the nth node \n");
   // printf("9. Delete the whole list \n\n");


    printf("Enter no. ");
    scanf("%d", &ch);
    switch (ch)

    {
    case 1 :
     insertatend();
     break;

    case 2 :
        display();
        break;
    case 3 :
       {
        //missing %d
        printf("Length is = %d",length());
        break;
       }
    case 4 : insertatbeg();
                break;
    case 5 : insertafter();
                break;
    case 6 : deletefirst();
                  break;
    case 7 : deletelast();
                    break;
    case 8 : deletenth();
                  break;
    }
}

return 0;
}

void insertatend()
{
    int a;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter element to be inserted ");
    scanf("%d",&temp->data);
    temp->link = NULL;

    if(root == NULL)
            root=temp;
    else{
    struct node *p;
    p=root;
    while(p->link != NULL)
    {
        p=p->link;
    }
    p->link = temp;
}
}

int length()
{
    struct node* temp;
    temp=start;
    int count=0;


    while(temp!=NULL)
    {
        count++;
        temp = temp->link;
    }

    return count;
}

void display()
{
   struct node *temp;
   temp=root;
   if (length() == 0)
        printf("List is empty \n");
   else
   {
       while(temp != NULL)
       {
       printf("%d-->",temp->data);
       temp=temp->link;
       }
   }

  // printf("Length is : %d ", length());
}

void insertatbeg()
{
    struct node* temp;
    //struct node*
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Please enter number");
    scanf("%d",&temp->data);
    temp->link=NULL;
    struct node *p;
    p=root;
    if(p==NULL)
        root = temp;
    else
    {
        temp->link = root;
        root = temp;
    }
}

void insertafter()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    int loc,c=1;
    printf("Please enter location : ");
    scanf("%d",&loc);
    printf("Please enter number : ");
    scanf("%d",&temp->data);
    temp->link = NULL;
    struct node *p;
    p=root;
    if(loc>length())
    {
        printf("Invalid entry \n Total Elements are %d", length());
    }
    else if(p==NULL)
        root = temp;
    else
    {
        while(c<loc)
        {
            p=p->link;
             c++;
        }
        temp->link = p->link;
        p->link = temp;
    }
}

void deletefirst()
{
    struct node *temp;
    temp=root;
    if(temp==NULL)
        printf("List is empty");
    else
    {
        root=temp->link;
        temp->link=NULL;
        free(temp);
    }


}

void deletelast()
{
    struct node *temp, *p;
    //temp=(struct node*)malloc(sizeof(struct node));
    p=root;
    if(root==NULL)
    {
        printf("List is Empty");
    }
    else{
    while(p->link!=NULL)
    {
        temp=p;
        p=p->link;
    }
    temp->link=NULL;
    free(p);
    }
}

void deletenth()
{
    struct node *temp,*p;
    int loc,c=1;
    printf("Please enter nth Node to delete :");
    scanf("%d",&loc);
    temp=root;
    if(loc>length())
    {
        printf("Invalid entry. \n");
        printf("Total elements are in list is %d",length());
    }
    else
    {
    while (c<loc-1)
    {
        temp=temp->link;
        c++;
    }
    p = temp->link;
    temp->link=p->link;
    p->link = NULL;
    free(p);
    }
}
