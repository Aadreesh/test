#include "room.h"
#include "unity.h"
#include "stdlib.h"



/**
 * @brief Set the Up object
 * Required by the unity test framework
 */
void setUp() {}

/**
 * @brief Release the objects that are setup for tests
 * Required by the unity test framework
 */
void tearDown() {}

Room *head = NULL;
int no_nodes = 0;

void test_ll_creation()
{

    head = CreateLL(&no_nodes);
    TEST_ASSERT_NOT_EQUAL(NULL,head);
    TEST_ASSERT_EQUAL(5,no_nodes);
}

void test_ll_ac_turn_on()
{
    Room * details = (Room*)calloc(no_nodes,sizeof(Room));
    int ac_room_no = AC_turn_on(head,details);
    TEST_ASSERT_EQUAL(3,ac_room_no);
    free(details);
}

void test_ll_chk_temperature()
{
    Room * details = (Room*)calloc(no_nodes,sizeof(Room));
    float temperature = 25.50;
    int temp_room_no = Chk_temperature(head, details,temperature);
    TEST_ASSERT_EQUAL(2,temp_room_no);
    free(details);
}

void test_ll_chk_highest_power()
{
    Room *maximum = Chk_highest_power(head);
    TEST_ASSERT_EQUAL( "Second", maximum->floor); 
    TEST_ASSERT_EQUAL( 205 , maximum->room_no);
    TEST_ASSERT_EQUAL( 123.650002, maximum->power_consumption);
    TEST_ASSERT_EQUAL(" ON" , maximum->ac_switch);
    TEST_ASSERT_EQUAL( 25.400000, maximum->room_temp);
    free(maximum);
}

void test_ll_chk_highest_temperature()
{
    char s[] = "First";
    char s1[] = " OFF";
    Room *highest = Chk_highest_temperature(head);
    // TEST_ASSERT_EQUAL(0,strcmp(s,highest->floor));
    TEST_ASSERT_STREQUAL("First", *highest->floor); 
    TEST_ASSERT_EQUAL( 1 , highest->room_no);
    TEST_ASSERT_EQUAL( 25.000000, highest->power_consumption);
    // TEST_ASSERT_EQUAL(0,strcmp(s1,highest->ac_switch));
    TEST_ASSERT_EQUAL("OFF" , highest->ac_switch);
    TEST_ASSERT_EQUAL( 40.299999, highest->room_temp);
    free(highest);

}
void test_ll_sort()
{
    bubblesort(head);
    TEST_ASSERT_NOT_EQUAL(NULL,head);
}


int main()
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();
     /* Run Test functions */
    RUN_TEST(test_ll_creation);
    RUN_TEST(test_ll_ac_turn_on);
    RUN_TEST(test_ll_chk_temperature);
    RUN_TEST(test_ll_chk_highest_power);
    RUN_TEST(test_ll_chk_highest_temperature);
    RUN_TEST(test_ll_sort);
    /* Close the Unity Test Framework */    

    // int no_nodes = 0;
    // Room *head = CreateLL(&no_nodes);
    // printf("Np of nodes : %d\n",no_nodes);
    // Room * details = (Room*)calloc(no_nodes,sizeof(Room));
    // int ac_room_no = AC_turn_on(head,details);
    // printf("AC\n %d",ac_room_no);
    // for(int i=0; i<ac_room_no; i++)
    // {
    //     printf("%s\n %d\n %f\n %s\n %f\n",details[i].floor,details[i].room_no,details[i].power_consumption,details[i].ac_switch,details[i].room_temp);
    // }
    // printList();
    // free details
    // float temperature = 25.50;
    // int temp_room_no = Chk_temperature(head, details,temperature);
    // printf("\nTemperature");
    // for(int i=0; i<temp_room_no; i++)
    // {
    //     printf("%s\n %d\n %f\n %s\n %f\n",details[i].floor,details[i].room_no,details[i].power_consumption,details[i].ac_switch,details[i].room_temp);
    // }
    // Room *highest = Chk_highest_temperature(head);
    // printf("\nHighest");
    // printf("%s\n %d\n %f\n %s\n %f\n",highest->floor, highest->room_no, highest->power_consumption, highest->ac_switch, highest->room_temp);
    //free highest
    // Room *maximum = Chk_highest_power(head);
    // printf("\nMaximum");
    // printf("%s\n %d\n %f\n %s\n %f\n",maximum->floor, maximum->room_no, maximum->power_consumption, maximum->ac_switch, maximum->room_temp);    

    // printf("\nAfter Sorting");
    // bubblesort(head);
    // printList(head);
    

    return UNITY_END();
}