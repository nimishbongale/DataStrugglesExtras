#include<stdio.h>
#include<stdlib.h>

struct node//declaring the structure 

{

	int data;

	struct node *link;

}*head=NULL,*ptr,*p;



struct node* createNode()//function to return the created node

{

	struct node *newNode=(struct node*)malloc(sizeof(struct node));

	if(newNode==NULL)

	{

	printf("Heap full!");

	exit(0);

	}

	else

	{

		printf("Enter the data\n");

		scanf("%d",&(newNode->data));

		newNode->link=NULL;

	}

	return newNode;

}

//functions to insert data into various locations 



void InsertEnd()

{
	ptr=createNode();
	if(head==NULL)
	head=ptr;
	else
	{
		p=head;
		while(p->link!=NULL)
		p=p->link;

		p->link=ptr;
	}

}

void reverseSLL() 
{ 
    struct node* cur=head;  
    while (cur!=NULL) 
    { 
        ptr= cur->link;   
  		cur->link = p;    
  		p = cur; 
        cur = ptr; 
    } 
    head=p; 
} 

void display()

{

	p=head;

	while(p!=NULL)

	{

		printf("%d ->",p->data);

		p=p->link;

	}

}
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Add data\n2.Reverse SLL\n3.Display\nEnter anyything else to exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				InsertEnd();
				break;
			case 2:
				reverseSLL();
				break;
			case 3:
				display();
				break;
		}
	}
	return 0;
}


