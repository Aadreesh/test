#include "list.h"
#include "stdio.h"

node* create_list()
{
    return (node*)malloc(sizeof(node));
}  

void file_to_node(node* head)
{
    char * line = NULL;
    size_t len = 0;
    ssize_t read;  
    FILE *fptr;
    fptr = fopen("sensor.csv","r");
    if (fptr == NULL)
       exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fptr)) != -1) 
    {
        CSV_info buf; 
        int index = 0;
        int item = 1;
        char dummy[20];
        while(item <= FLOOR_NO)
        {
            int dummy_index = 0;
            switch(item)
            {
                case 1: while(line[index] != ',')
                        {
                            buf.floor[index] = line[index];
                            index++;     
                        }
                        index++;
                        item++;
                        break;
                case 2: while(line[index] != ',')
                        {
                            dummy[dummy_index] = line[index];
                            index++;
                            dummy_index++;
                        }
                        index++;
                        buf.room = atoi(dummy);
                        break;
                case 3: while(line[index] != ',')
                        {
                            dummy[dummy_index] = line[index];
                            index++;
                            dummy_index++;                                                      
                        }
                        index++;
                        buf.power = atof(dummy);
                        break;
                case 4: while(line[index] != ',')
                        {
                            buf.ac_stat[dummy_index] = line[index];
                            index++;
                            dummy_index++;
                        }
                        index++;
                        break;
                case 5: while(line[index] != ',')
                        {
                            dummy[dummy_index] = line[index];
                            index++;
                            dummy_index++;                                                      
                        }
                        index++;
                        buf.temp = atof(dummy);
                        break;
                default: break;         
            }
        }
        node* temp = (node *)malloc(sizeof(node));
        temp->data = buf;
        add_node(head,temp);
    }
    fclose(fptr); 
}

void add_node(node* head, node* new)
{
    node* temp;
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
}

