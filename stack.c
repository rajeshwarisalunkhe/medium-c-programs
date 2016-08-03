/* adding and removing element from stack*/

struct node
{
	int number;
	struct node *next;
};

#include <stdio.h>
#include <stdlib.h>
struct node *push(struct node *head, int num);
void display(struct node *head);
int pop(struct node **head_add);

int main(void)
{
	struct node *head = NULL, **head_add;
	int choice, num, pop_element;
	do
	{
		printf("enter 1 to add element\n");
		printf("enter 2 to delete upper element\n");
		printf("enter 3 to display\n");
		printf("enter 4 to exit\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
			printf("Enter the number:");
			scanf("%d", &num);

			head = push(head,num);
			break;

			case 2:
			if(head == NULL)
			{
				printf("No element in linked list\n");
			}
			else
			{
				head_add = &head;
				pop_element = pop(head_add);
				printf("Deleted number is %d\n", pop_element);
				
			}
			break;

			case 3:
			if(head == NULL)
			{
				printf("No element in linked list\n");
			}
			else
			{
				display(head);
			}			
			break;

			case 4:
			printf("Exiting...\n");
		}
		printf("\n");
	}while(choice != 4);
}

struct node *push(struct node *head, int num)
{
	struct node *new;
	
	
	if(head == NULL)
	{	
		head = malloc(sizeof(struct node));
		head->number = num;
		head->next = NULL;
		
	}
	else
	{
		new = malloc(sizeof(struct node));
		new->number = num;
		new->next = head;
		head = new;
	}
	
	return head;	
}

int pop(struct node **head_add)
{
	struct node *head;
	int deleted_number;

	head = *head_add;

	if(head->next == NULL)
	{
		deleted_number = head->number;
		*head_add = NULL;
		free(head);
		
	}
	else
	{
		deleted_number = head->number;
		*head_add = head->next;
		free(head);
	}

	return deleted_number;
}
void display(struct node *head)
{
	struct node *ptr;

	ptr = head;
	
	while(ptr != NULL)
	{
		printf("%d\t", ptr->number);
		ptr = ptr->next;
	}
}


