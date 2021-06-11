/**
 * @file room.h
 * @author Ashwani Kumar Dubey  (ashwani26061999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
 
#ifndef _ROOM_H_
#define _ROOM_H_

#include "stdio.h"
/**
 * @brief Structure of Room which contains a char array named floor and room_no which of int types, power_consumption of float types, ac_switch of char array, and a pointer named next which points to structure named Room
 * 
 */
typedef struct room{
    char floor[50];
    int room_no;
    float power_consumption;
    char ac_switch[50];
    float room_temp;
    struct room* next;
}Room;

/**
 * @brief Create a Node object of Room Structure
 * 
 * @return Room* 
 */
Room* createNode();

/**
 * @brief Append a node in Single Linked List
 * @param char** array of strings to assign value to each element of structure "Room"
 * @return Room* 
 */
Room* addNode(char **, Room *);

/**
 * @brief Create Linked List from the strings readed from file.
 * @param int* to count the number of nodes in the linked list
 * @return Room* 
 */
Room *CreateLL(int *);

/**
 * @brief Print all the elements of structure
 * 
 */
void printList(Room *);

/**
 * @brief checks in which nodes ac_switch is turned on 
 * @param Room * contain the head of the linked list
 * @param Roo * stored all the nodes details whose ac_switch is turned on
 * @return int count the number of rooms has switched on
 */
int AC_turn_on(Room *, Room *);

/**
 * @brief Check the rooms which has higher temperature than the given temperature
 * @param Room * contain the head of the linked list
 * @param Room * stores all the nodes details whose temperature is higher than the given temperature
 * @param int denotes the threshold temperature
 * @return int denotes the number of rooms has temperature higher than the given threshold temperature
 */
int Chk_temperature(Room *, Room *, int);

/**
 * @brief Check the room which has the highest temperature
 * @param Room* contain the head of the linked list
 * 
 * @return Room* contain the address of the room which has the highest temperature
 */
Room* Chk_highest_temperature(Room *);

/**
 * @brief Check the room which has the highest power consumption
 * @param Room* Contain the head of the linked list
 * @return Room* contain the address of the node which has the highest power consumption
 */
Room* Chk_highest_power(Room *);

/**
 * @brief swaps the two nodes
 * @param Room* node 1 which we want to swap with the node2
 * @param Room* node 2 which we want to swap with the node1
 */
void swap(Room *, Room *);

/**
 * @brief sort the linked list 
 * @param Room* Contain the address of the head node which we want to sort the linked list
 */
void bubblesort(Room *);



#endif