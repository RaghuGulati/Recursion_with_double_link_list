#ifndef SORTED_LIST_H_INCLUDED
#define SORTED_LIST__H_INCLUDED
/* ^^ these are the include guards */

/* Prototypes for the functions */


#include <stdio.h>  
#include <stdlib.h>  
#include<string.h>
#include "a.h"
typedef Fraction  value_t;
typedef double key_lt;
// A linked list node  
struct Node {  
    value_t value;
    key_lt key;
    struct Node* prev;
    struct Node* next;
    struct Node* prev_sorted;
    struct Node* sort;
};  

//Sorted_list data type
typedef struct {
    struct Node* head;
    struct Node* head_sort;
    struct Node* tails;
    struct Node* tails_sort;
    int size ;//store the node count
}Sorted_list;

//size function to calculate the size of linked list
int size(Sorted_list * list_detail);
 
/*push function to add the node to the head of the list*/
int push(Sorted_list * list_detail, value_t  value, key_lt  key)  ;

int append(Sorted_list * list_detail, value_t  value, key_lt  key);

//Function to print the list according to insertion order as well as key sort order
void printList(Sorted_list * list_detail, int mode)  ;

void printList_sort(Sorted_list * list_detail, int mode);



/*
 *function to remove first node
 *@param Sorted_list *
 *@param value_t
 *@param key_lt *
 */
int remove_first(Sorted_list * list_detail,value_t * value, key_lt * key);

/*
 *function to remove last  node
 *@param Sorted_list *
 *@param value_t
 *@param key_lt *
 */
int remove_last(Sorted_list * list_detail,value_t * value, key_lt * key);

/*
 *function to remove node having smallest value
 *@param Sorted_list *
 *@param value_t
 *@param key_lt *
 */
int remove_smallest_key(Sorted_list * list_detail,value_t * value, key_lt * key);

/*
 *function to remove node having largest key
 *@param Sorted_list *
 *@param value_t
 *@param key_lt *
 */
int remove_largest_key(Sorted_list * list_detail,value_t * value, key_lt * key);
void empty_list(Sorted_list * list_detail);
void destroy_list(Sorted_list * list_detail);
#endif
