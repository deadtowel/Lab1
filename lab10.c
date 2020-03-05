#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 40
#define MAX_NUM 28
int main(void)
{
	struct stud_type
	{
		char surname[MAX_SIZE];
		char name[MAX_SIZE];
		int birth_day;
		int birth_month;
		int birth_year;
		int marks[5];
		struct stud_type *next;
	};
	struct stud_type *p=(struct stud_type*)calloc(1, sizeof(struct stud_type));
	struct stud_type *start=NULL;
	
	FILE *fp;
	fp=fopen("D:/lab8/input.txt", "r");
	
	//int count_el=0;
	for(int i=0; i<MAX_NUM; i++)
	{
		fscanf(fp, "%s %s %d.%d.%d %d, %d, %d, %d, %d\n", &p->surname, &p->name, &p->birth_day, &p->birth_month, \
			&p->birth_year, &p->marks[0], &p->marks[1], &p->marks[2], &p->marks[3], &p->marks[4]);
		if(!start) start=p;
		struct stud_type *pp=(struct stud_type*)calloc(1, sizeof(struct stud_type));		
		p->next=pp;
		p=pp;	
		//count_el++;
	}
	p->next=NULL;
	p=start;
	
	fclose(fp);
	
	printf("----------------------------------------------------\n");
	printf("|           |         |             |%12s  |\n", "Subject #");
	printf("|%9s  |%7s  |%10s|--------------|\n", "Surname", "Name", "Date of Birth");
	printf("|           |         |             |%2d|%2d|%2d|%2d|%2d|\n", 1, 2, 3, 4, 5);
	printf("----------------------------------------------------\n");
	
	while(p->next!=NULL)
	{
		printf("|%11s|%9s|%2d.%2d.%4d   |%2d|%2d|%2d|%2d|%2d|\n", p->surname, p->name, p->birth_day, p->birth_month, \
			p->birth_year, p->marks[0], p->marks[1], p->marks[2], p->marks[3], p->marks[4]);
		printf("----------------------------------------------------\n");	
		p=p->next;
	}
	

	
//	struct stud_type *add=(struct stud_type*)malloc(sizeof(struct stud_type));
//	add->next=start;
//	start=add;
	char ch; 
	int previous=0;
	puts("Press 'a' to add element, press 'r' to remove elements with 3 in second subject or press 'e' to exit.");
	if((ch=getchar())=='a'){
		puts("Enter element you want to add after: ");
		scanf("%d", &previous);
		p=start;
		for(int i=1; i<previous; i++)
		{
			struct stud_type *pp;//=(struct stud_type*)calloc(1, sizeof(struct stud_type));
			pp=p;
			p=p->next;	
		}
		struct stud_type *add=(struct stud_type*)calloc(1, sizeof(struct stud_type));
		puts("Enter data written like this: %s %s %d.%d.%d %d, %d, %d, %d, %d");
		scanf("%s %s %d.%d.%d %d, %d, %d, %d, %d", &add->surname, &add->name, &add->birth_day, &add->birth_month, &add->birth_year, \
		&add->marks[0], &add->marks[1], &add->marks[2], &add->marks[3], &add->marks[4]);
		add->next=p->next;
		p->next=add;
	}
	else if(ch=='r'){
		p=start;
		struct stud_type *pp;
		//struct stud_type *pr;
		for(int i=0; i<MAX_NUM; i++)
		{
			pp=p;
			p=p->next;
			if(p->marks[1]==3){
				if(!p->next)
					{
						pp->next=NULL;
						break;
					}
				pp->next=p->next;
				free(p);
				p=pp;
			}					
		}
	
	}
	else {
		puts("Program have successefully ended.");
		exit(EXIT_SUCCESS);
	}
	system("cls");
	
	p=start;
	printf("----------------------------------------------------\n");
	printf("|           |         |             |%12s  |\n", "Subject #");
	printf("|%9s  |%7s  |%10s|--------------|\n", "Surname", "Name", "Date of Birth");
	printf("|           |         |             |%2d|%2d|%2d|%2d|%2d|\n", 1, 2, 3, 4, 5);
	printf("----------------------------------------------------\n");
	
	while(p->next!=NULL)
	{
		printf("|%11s|%9s|%2d.%2d.%4d   |%2d|%2d|%2d|%2d|%2d|\n", p->surname, p->name, p->birth_day, p->birth_month, \
			p->birth_year, p->marks[0], p->marks[1], p->marks[2], p->marks[3], p->marks[4]);
		printf("----------------------------------------------------\n");	
		p=p->next;
	}
	puts("Program have successefully ended.");
	return 0;
}
