#include <stdio.h>

#include <stdlib.h>



struct node//declaring the structure

{

    struct node *prev;

    int number;

    struct node *next;

}*head=NULL,*newNode=NULL,*tail=NULL,*ptr=NULL,*p=NULL,*temp=NULL;



struct node* createNewNode()//returning the new created node

{

    int data;

    newNode=(struct node*)malloc(sizeof(struct node));

    if(newNode==NULL)

    {

    	printf("Heap Memory full!");

    	exit(0);

	}

    newNode->prev=newNode->next=NULL;

    printf("\nEnter the data : ");

    scanf("%d", &(newNode->number));

    return newNode;

}

void InsertEnd()
{
	newNode=createNewNode();
	if(tail==NULL)
	head=tail=newNode;
	
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
}

void reverseDLL() 
{
	p=head;
    while (p!=NULL) 
     { 
       temp = p->prev; 
       p->prev = p->next; 
       p->next = temp;               
       p=p->prev; 
     }       
       
     if(temp != NULL) 
     {
     	head->next=NULL;
        head= temp->prev;
	}
} 
void display()
{

    p=head;

    printf("\nCurrent Double linked list:\n ");

    for(p=head;p!=NULL;p=p->next)

    printf("%d->", p->number);

}     

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Add data\n2.Reverse DLL\n3.Display\nEnter anyything else to exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				InsertEnd();
				break;
			case 2:
				reverseDLL();
				break;
			case 3:
				display();
				break;
		}
	}
	return 0;
}
