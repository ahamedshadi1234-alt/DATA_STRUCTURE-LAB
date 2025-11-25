#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *header=NULL;
/*struct createnode(int item)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=10;
	newnode->link=NULL;
	
}*/
void insertAtFront(int item)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=item;
	newnode->link=NULL;
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
void insertAtEnd(int item)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=item;
	newnode->link=NULL;
	if(header==NULL)
	{
		header=newnode;
	}
	else
	{ 
		struct node *ptr;
		ptr=header;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=newnode;
	}
}
void insertAtAny(int item,int key)
{
	
	
		struct node *ptr,*ptr1;
		ptr=ptr1=header;
		while(ptr->data!=key)
		{
			ptr1=ptr;
			ptr=ptr->link;
			
		}
		if(ptr->data==key)
		{
			struct node *newnode;
			newnode=(struct node *)malloc(sizeof(struct node));
			newnode->data=item;
			newnode->link=NULL;
			if(header==NULL)
			{
				header=newnode;
			}
			else
			{
				ptr1->link=newnode;
				newnode->link=ptr;
			}
		}
		
		else
		{
			printf("Key not found,insertion not possible");
		
		}

}
void deleteAtFront(){
	struct node *ptr;
	if(header==NULL)
	{
		printf("the linkedlist is empty");
	}
	else{
	ptr=header;
	header=header->link;
	//printf("Delted element is %d",ptr->data);
	free(ptr);
	}
}
void deleteAtEnd(){
	struct node *ptr,*ptr1;
	if(header==NULL)
	{
		printf("the linkedlist is empty");
	}
	else{
		ptr=header;
		ptr1=header;
		while(ptr->link!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->link;
		}
		//printf("Delted element is %d",ptr->data);
		free(ptr);
		ptr1->link=NULL;
	}
}
void deleteAtAny(int key)
{
	
	
		struct node *ptr,*ptr1;
		ptr=header;
		ptr1=NULL;
		while(ptr!=NULL && ptr->data!=key)
		{
			ptr1=ptr;
			ptr=ptr->link;
			
		}
		if(ptr==NULL)
		{
			printf("Key not found.Deletion not possible.\n");
		}
		else
		{
			if(ptr->data==key)
			{
				printf("Deleted Item is: %d\n",ptr->data);
				
				if(ptr1==NULL)
					header=ptr->link;
				
				else
					ptr1->link=ptr->link;
				free(ptr);

				
			}
		}

}
void traversalList()
{
	struct node *ptr;
	ptr=header;
	if(ptr == NULL)
		printf("List is empty\n");
	else
	{
	while(ptr!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->link;
	}
	}
	printf("\n");
}
int main()
{
	/*int choice,item;
	do
	{
		printf("1.Insert At Front\n2.Insert At End\n3.Insert At Any\n4.Delete At Front\n5.Delete At End\n6.Delete At Any\n7.Search\n8.Traversal\n9.Exit");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:("Enter the element to insert:");
				scanf("%d",&item);
				insertAtFront(item);
				break;
			case 2:("Enter the element to insert:");
				scanf("%d",&item);
				insertAtEnd(item);
				break;
			case 3:("Enter the element to insert:");
				scanf("%d",&item);
				insertAtAny(item);
				break;
		
				
		}
	}*/
	insertAtFront(10);
	insertAtFront(20);
	insertAtFront(30);
	insertAtFront(40);
	traversalList();
	insertAtEnd(50);
	insertAtEnd(60);
	traversalList();
	insertAtAny(70,20);
	traversalList();
	deleteAtFront();
	traversalList();
	deleteAtEnd();
	traversalList();
	deleteAtAny(10);
	traversalList();
	return(0);
} 
