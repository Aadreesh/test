#include "list.h"
#include "stdio.h"
#include <string.h>

node* ac [FLOOR_NO];
node* ac_temp [FLOOR_NO];
node* high_power [FLOOR_NO];
node* high_temp [FLOOR_NO];

const char ON[2] = "ON";
const char OFF[3] = "OFF"; 

node* find_rt(node* head,float value)
{
    
    if(head == NULL)
        return NULL;
    else
    {
        while(head != NULL)
        {
            if(head->data.temp == value)
                return head;
            head = head->next;
        }
    }
    return NULL;
}

node* find_power(node* head,float value)
{
    if(head == NULL)
        return NULL;
    else
    {
        while(head != NULL)
        {
            if(head->data.power == value)
                return head;
            head = head->next;
        }
    }
    return NULL;
}


void ac_on(node* head)
{   int index = -1;
    while(head != NULL)
    {   
        if(!(strcmp( head->data.ac_stat, ON)))
        {
            index++;
            ac[index] = head;
        }           
        head = head->next; 
    }    
}

void ac_off_temp(node* head)
{
    int index = -1;
    while(head != NULL)
    {
        if((!(strcmp(head->data.ac_stat,OFF))) && (head->data.temp >= TEMP))  
        {
            index++;
            ac_temp[index] = head;
        }
        head = head->next; 
    }
} 

node* high_p(node* head)
{
    node* temp = head; 
    float val = 0;
    while(temp != NULL)
    {
        if(temp->data.power > val)   
        {
            val = temp->data.power;
        }
        head = temp->next;
    }
    find_power(head,val);
}

node* high_rt(node* head)
{
    float val = 0;
    while(head != NULL)
    {
        if(head->data.temp > val)   
        {
            val = head->data.temp;
        }
        head = head->next;
    }
    find_rt(head,val);
}

