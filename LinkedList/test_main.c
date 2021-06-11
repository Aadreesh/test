#include "list.h"

node* first = NULL;

void main(void)
{
    first = create_list();
    file_to_node(first);
}