/* Write a menu driven program to add numbers in linked list and to display it*/

#include <stdio.h>
#include <stdlib.h>
struct menu
{
	int number;
	struct menu *next;
};

struct menu *add(struct menu *head);
void display(struct menu *head);
int count(struct menu *head);
struct menu *search(struct menu *head, int input);
int insert_after(struct menu *head, int input, int new_element);
struct menu *delete(struct menu *head, struct menu *ptr);
struct menu *previous_element(struct menu *head, struct menu *ptr);
int main(void)
{
	struct menu *head = NULL, *ptr;
	int choice, counter = 0, input,flag = 0, new_element, delete_element;
	do
	{
		printf("Enter 1 to add number\n");
		printf("Enter 2 to display list\n");
		printf("Enter 3 to count the entered numbers\n");
		printf("Enter 4 to insert number after another number\n");
		printf("Enter 5 to delete number\n");
		printf("Enter 6 to exit\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
			head = add(head);
			break;
			
			case 2:
			display(head);
			break;

			case 3:
			counter = count(head);
			if(counter != 0)
			{
				printf("There are %d element in linked list\n", counter);
			}
			else
			{
				printf("Zero element in linked list\n");
			}
			break;

			case 4:
			if(head == NULL)
			{
				printf("List is empty, first add one element with first option \n");
			}
			else
			{
				printf("Enter number after which new number need to be insert:");
				scanf("%d", &input);
				printf("Enter new element to be insert:");
				scanf("%d", &new_element);
				flag = insert_after(head, input, new_element);
				if(flag == 1)
				{
					printf("The number you entered is not present in the list\n");
				}
				else
				{
					printf("Number successfully inserted\n");
				}
			}
			break;

			case 5:
			if(head == NULL)
			{
				printf("List is empty, first add one element with first option \n");
			}
			else
			{
				printf("Enter which number to be deleted:");
				scanf("%d", &delete_element);
				ptr = search(head, delete_element);
				if(ptr == 0)
				{
					printf("The number you entered is not present in the list\n");
				}
				else
				{	head = delete(head, ptr);
					printf("Number successfully deleted\n");
				}
			}
			break;

			case 6:
			printf("Exiting....\n");
		}
		printf("\n");
	}while(choice != 6);
}

struct menu *add(struct menu *head)
{
	struct menu *ptr, *node;
	int num;
	printf("Enter the number:");
	scanf("%d", &num);	
	if(head == NULL)
	{
		head = malloc(sizeof(struct menu));
		head->number = num;	
		head->next = NULL;
	}
	else
	{
		ptr = head;		
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		node = malloc(sizeof(struct menu));
		node->number = num;
		ptr->next = node;
		node->next = NULL; 
	}

	return head;	
}

void display(struct menu *head)
{
	struct menu *ptr;
	if(head == NULL)
	{
		printf("No element in linked list\n");
	}
	else
	{
		ptr = head;
		while(ptr != NULL)
		{
			printf("%d\t", ptr->number);
			ptr= ptr->next;
		}
	}
}


int count(struct menu *head)
{
	struct menu *ptr;
	int counter = 0;
	if(head == NULL)
	{
		counter = 0;
	}
	else
	{
		ptr = head;
		while(ptr != NULL)
		{
			counter++;
			ptr= ptr->next;
		}
	}
	return counter;
}

struct menu *search(struct menu *head, int input)
{
	struct menu *ptr;
	int flag = 0;
	
	ptr = head;
	while(ptr != NULL)
	{
		if(ptr->number == input)
		{
			flag = 1;				
			break;
			
		}
		
		ptr= ptr->next;
	}
	if(flag == 1)
	{
		return ptr;
	}
	else
	{
		return 0;
	}
}


int insert_after(struct menu *head, int input, int new_element)
{
	
	struct menu *address, *node;
	
	
	address = search(head, input);
	if(address == 0)
	{
		return 1;	
	}
	
	node = malloc(sizeof(struct menu));
	node->number = new_element;
	node->next = address->next;
	address->next = node;
	return 0;
}


struct menu *delete(struct menu *head, struct menu *ptr)
{
	struct menu *address,*node;
	

	if(ptr == head)
	{
		head = ptr->next;
		free(ptr);
	}
	else if(ptr->next  == NULL)
	{
		node = previous_element(head, ptr);
		node->next = NULL;
		free(ptr);
	}
	else
	{
		node = previous_element(head, ptr);		
		node->next = node->next->next;
		free(ptr);
	}	
	return head;
}

struct menu *previous_element(struct menu *head, struct menu *ptr)
{
	struct menu *node;
	
	node = head;

	while(node != NULL)
	{
		if(node->next == ptr)
		{				
			break;
			
		}
		
		node= node->next;
	}
	
	return node;
	
}















