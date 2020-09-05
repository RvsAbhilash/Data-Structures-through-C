#include <stdio.h>
#include<stdlib.h>
struct node {
  int data;
  struct node *next;
}*head;
void createSLL();
void display();
void insertatbeg();
void insertatend();
void insertatpos();
void reverseSLL();
int getlength();
int main(void) {
  int ch=0;
  createSLL();
  printf("\nEnter 1. To display Linked List:\n 2. To insert at beginning 3. To insert at end 4. To insert a position 5. To reverse Linked List: ");
  scanf("%d",&ch);
  if(ch==1) display();
  else if(ch==2) insertatbeg();
  else if(ch==3) insertatend();
  else if(ch==4) insertatpos();
  else if(ch==5) reverseSLL();
  
  return 0;
}
void createSLL(){
  struct node *newnode,*temp;
  head=0;
  int choice=1;
  while(choice){
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=0;
    printf("Enter Data:");
    scanf("%d",&newnode->data);
    if (head==0){
      head=temp=newnode;
    }
    else{
      temp->next=newnode;
      temp=temp->next;
    }
    printf("Enter 1 to add data or 0 to stop(1/0):");
    scanf("%d",&choice);
  }
}
void display(){
  struct node *temp;
  temp=head;
  while(temp->next!=0)
  {
    printf("%d-->",temp->data);
    temp=temp->next;
  }
  printf("%d\n",temp->data);
}
int getlength(){
  struct node *temp;
  temp=head;
  int c=0;
  while(temp->next!=0){
      c++;
      temp=temp->next;
  }
  return c+1;
}
void insertatbeg(){
    struct node *newnode;
    int l;
    l=getlength();
    if(l==0){
      printf("List empty");
      }
     else{
       newnode=(struct node *)malloc(sizeof(struct node));
       printf("Enter Data:");
       scanf("%d",&newnode->data);
       newnode->next=head;
       head=newnode;
      }
  display();     
}
void insertatend(){
    struct node *newnode,*temp;
    int l;
    l=getlength();
    if(l==0){
      printf("List empty");
      }
     else{
       newnode=(struct node *)malloc(sizeof(struct node));
       printf("Enter Data:");
       scanf("%d",&newnode->data);
       temp=head;
       while(temp->next!=0){
         temp=temp->next;
       }
       temp->next=newnode;
       newnode->next=0;
      }
  display();     
}
void insertatpos(){
  struct node *temp,*newnode;
  int pos,i=1,l;
  printf("Enter Position:");
  scanf("%d",&pos);
  temp=head;
  l=getlength();
  if(pos<1 || pos>l){
    printf("Invalid Position");
  }
  else if(pos==1){
    insertatbeg();
  }
  else {
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    while(i<pos-1){
      temp=temp->next;
      i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;


  }
  display();
  
}
void reverseSLL(){
  struct node *nextnode,*current,*prev;
  if(head==0) printf("List is Empty");
  else{
  prev=0;
  current=nextnode=head;
  while(nextnode!=0){
    nextnode=nextnode->next;
    current->next=prev;
    prev=current;
    current=nextnode;
  }
  head=prev;
  }
  display();
}
