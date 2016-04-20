#include <stdio.h>

struct student
{
	int student_id;
	char name[20];
	int roll_no;
	char address[50];
}record[100];

int count = 0;

int add();
int display();
int search();
int main(void)
{

	int choice, id, flag = 0, index;
	do
	{
		printf("\n");
		printf("1.Add:\n");
		printf("2.Display:\n");
		printf("3.Delete:\n");
		printf("4.Search:\n");
		printf("5.Exit\n\n");
		printf("enter choice\n");
		scanf("%d", &choice);
		

		switch(choice)
		{
			case 1:
			add();
			break;

			case 2:
			display();
			break;

			case 3:
			printf("Enter ID of the entry which need to delete:");
			scanf("%d", &id);
			flag = delete(id);
			if(flag == 1)
			{
				printf("entry deleted of id %d\n", id);
			}
			else
			{
				printf("no such id\n");
			}
			break;

			case 4:
			printf("Enter ID:");
	    		scanf("%d", &id);
			index = search(id);
			if(index >= 0)
			{
				printf("student id:%d\n", record[index].student_id);
				printf("name:%s\n", record[index].name);
				printf("roll no:%d\n", record[index].roll_no);
				printf("address:%s\n", record[index].address);
			}
			else
			{
				printf("record not found for given id");
			}
			break;

			case 5:
			printf("exiting\n");
			break;

			default:
			printf("invalid choice\n");
			break;
		}
	}while(choice != 5);

}

int add()
{
	printf("enter student id:");
	scanf("%d", &record[count].student_id);
	printf("enter name:");
	scanf("%s", record[count].name);
	printf("enter roll number:");
	scanf("%d", &record[count].roll_no);
	printf("enter address:");
	scanf("%s", record[count].address);	
	
	count++;
}

int display()
{
	int i;
	
	for(i = 0;i < count;i++)
	{
		printf("student id:%d\n", record[i].student_id);
		printf("name:%s\n", record[i].name);
		printf("roll no:%d\n", record[i].roll_no);
		printf("address:%s\n", record[i].address);	
		printf("\n");
	}
	
}

int search(int id)
{
	int i, index = -1;

	for(i = 0;i < count;i++)
	{
		if(record[i].student_id == id)
		{
			index = i;
		}
		
	}
	
	return index;

}


int delete(int id)
{
	int i, flag = 0,j;

	
	for(i = 0;i < count;i++)
	{
		if(record[i].student_id == id)
		{
			count--;
			flag = 1;
			for(j = i; j < count;j++)
			{			
				// replacing element with the next element				
				record[j] = record[j + 1];
			}
		}
	}
	
	return flag;
}
