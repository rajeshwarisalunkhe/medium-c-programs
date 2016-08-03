/*Program to execute front and rear of queue
front is the first element of queue and rear is the last element*/

struct node
{
	int number;
	struct node *next;
};

#include <stdio.h>
#include <stdlib.h>

void add(struct node **front_add, struct node **rear_add, int num);
void display(struct node *front);
int delete(struct node **front_add, struct node **rear_add);
int main(void)
{
	struct node *front  = NULL, *rear=NULL , **rear_add, **front_add;
	int choice, num = 0, deleted_element;

	
	front_add = &front;
	rear_add = &rear;

	
	do
	{
		printf("press 1 to add:\n");
		printf("press 2 to display:\n");
		printf("press 3 to delete:\n");
		printf("press 4 to exit\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
			printf("Enter the number:");
			scanf("%d",&num);
			add(front_add, rear_add,num);
			break;

			case 2:
			if(front == NULL)
			{
				printf("No element present\n");
			}
			else
			{
				display(front);
			}			
			break;

			case 3:
			if(front == NULL)
			{
				printf("No element present\n");
				
			}
			else
			{
				deleted_element = delete(front_add, rear_add);
				printf("deleted_element is %d\n", deleted_element);
			}			
			break;

			case 4:
			printf("Exiting...\n");
			printf("\n");
		}
		printf("\n");
	}while(choice != 4);
}


void add(struct node **front_add, struct node **rear_add, int num)
{


	struct node *new;

	if(*front_add == NULL)
	{

		*front_add = malloc(sizeof(struct node));
		*rear_add = *front_add;
		(*front_add)->number = num;
		(*front_add)->next = NULL;
	}
	else
	{
		new = malloc(sizeof(struct node));
		new->number = num;
		new->next = NULL;
		(*rear_add)->next = new;
		*rear_add = new;
	}
	
	
}

int delete(struct node **front_add, struct node **rear_add)
{
	int deleted_element;
	struct node *address_to_free;

	deleted_element = (*front_add)->number;

	address_to_free = *front_add;
	if((*front_add)->next != NULL)
	{
		(*front_add) = (*front_add)->next ;
	}
	else
	{
		*front_add = NULL;
		*rear_add = NULL;
	}
	free(address_to_free);

	return deleted_element;
}


void display(struct node *front)
{
	struct node *ptr;

	ptr = front;

	while(ptr != NULL)
	{
		printf("%d\t", ptr->number);
		ptr = ptr->next;
	}
	printf("\n");
}

