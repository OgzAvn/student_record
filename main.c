#include <stdio.h>
#include <stdint.h>
#include <string.h>


typedef struct{

	int rollNumber;
	char name[50];
	char branch[50];
	int dob; //day of birth
	int semister;

}STUDENT_INFO_t;

int max_record=10;

//Global array of records
STUDENT_INFO_t students[10];

void display_menu(void);
int read_menu_code(void);
void decode_menu_code(int8_t menu_code);
void display_all_record(STUDENT_INFO_t *record,int8_t max_record);
int check_roll_number(int roll_number,STUDENT_INFO_t *record,int8_t max_record);
int add_new_record(STUDENT_INFO_t *record,int8_t max_record);
int delete_record(STUDENT_INFO_t *record,int8_t max_record);

int main(){

	int8_t app_continue=1;
	int8_t menu_code;

	while(app_continue){

		display_menu();  //display the menu code

		menu_code=read_menu_code();

		if(menu_code){

			decode_menu_code(menu_code);

		}
		else{
			printf("Exiting application\n");
			app_continue=0;
		}
	}

	return 0;
}

void display_menu(void){

	printf("Display all record -->1\n");
	printf("Add new record     -->2\n");
	printf("Delete a record    -->3\n");
	printf("Exit application   -->0\n");
	printf("Please enter your option here :\n");

}

int read_menu_code(void){

	int input;
	scanf("%d",&input);

	return input;
}

void decode_menu_code(int8_t menu_code){

	int8_t ret;

	switch(menu_code)
	{
	case 1: printf("Displaying all students records\n");
	display_all_record(students, max_record);
	break;
	case 2:printf("Add a new record\n");
	ret = add_new_record(students, max_record);
	!ret ? printf("Record add unsuccessful") : printf("Record added succesfully\n");
	break;
	case 3:printf("Delete a record\n");
	ret=delete_record(students, max_record);
	ret ? printf("Record deleted successfully\n") : printf("Record not found\n");
	break;
	default:
		printf("invalid input\n");
	}
}

void display_all_record(STUDENT_INFO_t *record,int8_t max_record){

	int record_found=0;

	for(int i=0;i<max_record;++i){

		if(record[i].rollNumber)
		{
			record_found=1;
			//display the record
			printf("***********\n");
			printf("rollNumber : %u\n",record[i].rollNumber);
			printf("name       : %s\n",record[i].name);
			printf("branch     : %s\n",record[i].branch);
			printf("dob        : %u\n",record[i].dob);
			printf("semister   : %u\n",record[i].semister);
			printf("***********\n");
		}

	}
	if(! record_found)
	        printf("No records found\n");

}

int check_roll_number(int roll_number,STUDENT_INFO_t *record,int8_t max_record){

	int is_exist=0;

	for(int i=0;i<max_record;++i){
		if(record[i].rollNumber==roll_number)
		{
			is_exist=1;
			break;
		}
	}

	return is_exist;
}


int add_new_record(STUDENT_INFO_t *record,int8_t max_record){

	int i;
	int roll_number;
	int is_exist=0;
	int add_status=0;

	for(i=0;i<max_record;++i){

		if(!record[i].rollNumber)
		{
			//add the record
			printf("Enter the rollNumber:\n");
			scanf("%d",&roll_number);
			is_exist=check_roll_number(roll_number, students, max_record);
			if(!is_exist)
			{
               	add_status = 1; //adding new record
                record[i].rollNumber = roll_number;
                printf("Enter the studentSemister   : ");
                scanf("%d",&record[i].semister);
                printf("Enter the studentDOB        : ");
                scanf("%d",&record[i].dob);
                getchar();
                printf("Enter the StudentBranch     : ");
                scanf("%50[^\n]s",record[i].branch);
                getchar();
                printf("Enter the studentName       : ");
                scanf("50%[^\n]s",record[i].name);
			}
			else
			{
				printf("roll_number already exist\n");
			}

			break;

		}
	}

	if(i==max_record)
		printf("No SPACE available\n");

	return add_status;

}

int delete_record(STUDENT_INFO_t *record,int8_t max_record){

	int roll_number;
	int8_t delete_flag=0;

	printf("Enter the roll_number of the student:");
	scanf("%d",&roll_number);

	for(int i=0;i<max_record;++i){
		if(roll_number==record[i].rollNumber)
			delete_flag=1;
		memset(&record[i],0,sizeof(STUDENT_INFO_t));
		break;
	}

	return delete_flag;
}








