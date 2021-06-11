#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "room.h"
#include "limits.h"

Room* createNode(){
    Room *temp; // declare a node
    temp = (Room*)malloc(sizeof(Room)); // allocate memory using malloc()
    temp->next = NULL;// make next point to NULL
    return temp;//return the new node
}


Room* addNode(char **s, Room *head)
{   
    char s1[50];
    strcpy(s1,s[0]);
    int r = atoi(s[1]);
    float pc  = atof(s[2]);
    char s2[50];
    strcpy(s2,s[3]);
    float rt = atof(s[4]);
    Room *p;// declare two nodes temp and p
    Room *temp = (Room*)malloc(sizeof(Room));
    strcpy(temp->floor,s1);
    temp->room_no = r;
    temp->power_consumption = pc;
    strcpy(temp->ac_switch,s2);
    temp->room_temp = rt;
    temp->next = NULL;
    if(head == NULL){
        head = temp;     //when linked list is empty
    }
    else{
        p  = head;//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last node.The last node always points to NULL.
        }
        p->next = temp;//Point the previous last node to the new node created.
    }
    return head;
}



Room *CreateLL(int *no_nodes)
{    
    FILE *file = fopen("sensor.txt", "r");
    Room *head = NULL;
    // int no_nodes=0;
    if(file != NULL)
    {

        char line[500];

        while (fgets(line, sizeof(line), file))
        {


            // printf("%s", line);
            char **strings = (char**)malloc(5*sizeof(char*));
            int i = 0;
            for(i = 0; i < 5; i++){
                strings[i] = (char*)malloc(50*sizeof(char));
            }

            int init_size = strlen(line);
	        char delim[] = ",";

	        char *ptr = strtok(line, delim);
            i=0;
	        while(ptr != NULL)
	        {
                strcpy(strings[i], ptr);
	        	// printf("'%s'\n", ptr);
		        ptr = strtok(NULL, delim);
                i+=1;
        	}

            *no_nodes = *no_nodes + 1;
            head = addNode(strings, head);
            for(i=0; i<5; i++)
                memset(strings[i],0,strlen(strings[i]));

        }
        // printList(head);
    }
    return head;
}

void printList(Room *root)
{
    Room *temp = root;
    while (temp != NULL) {
        printf("%s\n %d\n %f\n %s\n %f\n",temp->floor,temp->room_no,temp->power_consumption,temp->ac_switch,temp->room_temp);

        temp = temp->next;
    }
}


int AC_turn_on(Room *head, Room *details)
{
    int i=0;
    Room *temp=head;
    char s[]= " ON";
    while(temp != NULL)
    {
        if(strcmp(temp->ac_switch, s) == 0)
        {
            details[i].room_no = temp->room_no;
            details[i].power_consumption = temp->power_consumption;
            details[i].room_temp = temp->room_temp;
            strcpy(details[i].floor,temp->floor);
            strcpy(details[i].ac_switch,temp->ac_switch);
            i += 1;        
        }
        temp = temp->next;
    }
    return i;

}


int Chk_temperature(Room *head, Room *details, int temperature)
{
    int i=0;
    Room *temp = head;
    char s[] = " OFF";
    while(temp != NULL)
    {
        if(temp->room_temp > temperature && strcmp(temp->ac_switch, s) == 0)
        {
            details[i].room_no = temp->room_no;
            details[i].power_consumption = temp->power_consumption;
            details[i].room_temp = temp->room_temp;
            strcpy(details[i].floor,temp->floor);
            strcpy(details[i].ac_switch,temp->ac_switch);           
            i += 1;
        }
        temp = temp->next;
    }
    return i;
}

Room* Chk_highest_temperature(Room *head)
{
    int max=INT_MIN;
    Room *high = (Room*)calloc(1,sizeof(Room));
    Room *temp = head;
    while(temp != NULL)
    {
        if(temp->room_temp > max)
        {
            max = temp->room_temp;
            high = temp;
        }
        temp = temp->next;
    }

    return high;
}

Room* Chk_highest_power(Room *head)
{
    int max=INT_MIN;
    Room *high = (Room*)calloc(1,sizeof(Room));
    Room *temp = head;
    while(temp != NULL)
    {
        if(temp->power_consumption > max)
        {
            max = temp->power_consumption;
            high = temp;
        }
        temp = temp->next;
    }

    return high;
}


void swap(Room *a, Room *b)
{
    Room temp;
    temp.room_no = a->room_no;
    temp.power_consumption = a->power_consumption;
    temp.room_temp = a->room_temp;
    strcpy(temp.floor,a->floor);
    strcpy(temp.ac_switch,a->ac_switch);

    a->room_no = b->room_no;
    a->power_consumption = b->power_consumption;
    a->room_temp = b->room_temp;
    strcpy(a->floor,b->floor);
    strcpy(a->ac_switch,b->ac_switch);

    b->room_no = temp.room_no;
    b->power_consumption = temp.power_consumption;
    b->room_temp = temp.room_temp;
    strcpy(b->floor,temp.floor);
    strcpy(b->ac_switch,temp.ac_switch);
    
}

void bubblesort(Room *start)
{
    int swapped, i;
    Room *ptr1;
    Room *lptr = NULL;
  
    /* Checking for empty list */
    if (start == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->power_consumption > ptr1->next->power_consumption)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
