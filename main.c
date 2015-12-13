#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};
struct Node *head;

void insert(int,int);
void delete(int);
void display();
void reverse();

int main()
{
  head = NULL; //Empty list
  int data,pos;
  char choice='y';
  while(choice=='y'||choice=='Y')
  {
    printf("Enter the data to be inserted and\nPosition of insertion: ");
    scanf("%d%d",&data,&pos);
    insert(data,pos);
    printf("\nThe list is:\n");
    display();
    printf("Do you want to insert more elements?(y/n): ");
    scanf(" %c",&choice);
  }
  do
  {
    printf("\nThe list is:\n");
    display();
    printf("Enter the nPosition of deletion: ");
    scanf("%d",&pos);
    delete(pos);
    printf("Do you want to delete more elements?(y/n): ");
    scanf(" %c",&choice);
  }while(choice=='y'||choice=='Y');
  printf("The list is:\n");
  display();
  printf("The list after reversal is:\n");
  reverse();
  display();
}

void insert(int data , int n)
{
  struct Node *t1 = (struct Node*)malloc(sizeof(struct Node));
  t1->data=data;
  t1->next=NULL;
  if(!n)
  {
    t1->next=head;
    head=t1;
    return;
  }
  struct Node *t2 = head;
  int i;
  for(i=0;i<n-1;i++)
  {
    t2=t2->next;
  }
  t1->next = t2->next;
  t2->next = t1;
}

void display()
{
  struct Node *t = head;
  while(t!=NULL)
  {
    printf("%d->",t->data);
    t=t->next;
  }
  printf("!!!\n");
}

void delete(int n)
{
  struct Node *t1 = head;
  if(!n)
  {
    head = head->next;
    free(t1);
    return;
  }
  int i;
  for(i=0;i<n-2;i++)
    t1 = t1->next;
  struct Node *t2 = t1->next;
  t1->next = t1->next->next;
  free(t2);
}

void reverse()
{
  struct Node *current,*next,*prev;
  prev = NULL;
  current = head;
  while(current!=NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head=prev;
}
