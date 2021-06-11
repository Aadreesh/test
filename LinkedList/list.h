#include <stdlib.h>
#include <stdbool.h>

#define FLOOR_NO 5 
#define TEMP 25.0
#define FILENAME "sensor.csv" 


typedef struct IOT_data
{
    char floor[16];
    int room;
    float power;
    char ac_stat[3];
    float temp;
} CSV_info;

typedef struct NODE
{
    CSV_info data;
    struct NODE* next;
} node;

typedef enum error_t
{
    FAILURE,
    SUCCESS
} error_t;

node* create_list();

void file_to_node(node* head); 

void add_node(node* head, node* new);

node* find_rt(node* head,float value);

node* find_power(node* head,float value);


//void powersort();

void ac_on(node* head);

void ac_off_temp(node* head);

node* high_p(node* head);

node* high_rt(node* head);
