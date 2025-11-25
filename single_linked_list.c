#include<stdio.h>
#include<stdlib.h>

struct node
{
      int data;
      struct node *link;
      
};

struct node *header = NULL;


/*
void createnode(int intem)
{
         struct node *newnode;
         newnode = (struct node *)malloc(sizeof(struct node));
         newnode->data = 10;
         newnode->link = NULL;
         header = newnode;
}
*/
void insertAtFront(int item)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = NULL;
    
    if(header==NULL)
    {
            header=newnode;
    }
    else
    {
            newnode->link=header;
            header=newnode;
    }
     
}
void traverseList() {
    struct node *ptr = header;
    printf("Linked List: ");
    while (ptr != NULL) {
        printf("%d  ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}
  
 void insertAtLast(int item)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = NULL;
    
    if(header==NULL)
    {
            header=newnode;
    }
    else
    {
           struct node *ptr;
     	   ptr=header;
           while(ptr->link !=NULL)
           {
           ptr=ptr->link;
          }       
          ptr->link=newnode;
   }       
     
}   
void insertAtAny(int key, int item) {
   
    if (header == NULL) {
        printf("List is empty, insertion not possible\n");
        return;
    }

    
    if (header->data == key) {
        insertAtFront(item);
        return;
    }

    struct node *ptr = header;
    struct node *prev = NULL;

   
    while (ptr != NULL && ptr->data != key) {
        prev = ptr;
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Key not found, insertion not possible\n");
        return;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;

    prev->link = newnode;
    newnode->link = ptr;
}

void deleteAtFront() {
    if (header == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct node *temp = header;
    header = header->link;
    free(temp);
}
void deleteAtEnd() {
    if (header == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    if (header->link == NULL) {
        free(header);
        header = NULL;
    } else {
        struct node *ptr = header;
        struct node *prev = NULL;

        while (ptr->link != NULL) {
            prev = ptr;
            ptr = ptr->link;
        }
        prev->link = NULL;
        free(ptr);
    }
}

                 
int main()
{
        insertAtFront(10);
        insertAtFront(20);
        insertAtFront(30);
        insertAtFront(40);
        insertAtLast(9);
        insertAtLast(8);
        traverseList();
        deleteAtFront();
        deleteAtEnd(0);
        traverseList();
        return(0);
}        
                      
