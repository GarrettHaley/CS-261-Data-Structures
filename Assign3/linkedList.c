#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>


struct Link* listInsertionSort(struct Link* head) {

  /*
   * This function should perform an insertion sort on the list whose head is
   * provided as the function's argument, so that the values in the list are
   * sorted in ascending order, starting at the head.
   *
   * The sort should be done without allocating any new Link structs or any
   * other auxiliary data structures.
   *
   * Return a pointer to the new head of the list.
   */
struct Link * headNext = head->next;
while( headNext != NULL ) {
	struct Link *previousHead = head;
	int tempValue = headNext->value;
	while(headNext != previousHead) {
		if(previousHead->value > tempValue) {
			tempValue = headNext->value;
			headNext->value = previousHead->value; 
			previousHead->value = tempValue;
		}
	previousHead = previousHead->next;

	} 
headNext = headNext->next;
}
return head;


}

struct Link* reverseList(struct Link* head) {

  /*
   * This function should iteratively reverse the list whose head is provided
   * as the function's argument.
   *
   * The reversal must be done totally in place, i.e. you may not allocate any
   * new Link structs or any other auxiliary data structures.
   *
   * Return a pointer to the new head of the list.
   *
  */
    struct Link* nextLink;
    struct Link* currentLink = head;
    struct Link* previousLink = NULL;
    while (currentLink != NULL)
    {
        nextLink  = currentLink->next;  
        currentLink->next = previousLink;   
        previousLink = currentLink;
        currentLink = nextLink;
    }
    head = previousLink;

  return head;
}

struct Link* reverseListRecursive(struct Link* head){

  /*
   * Write this function for extra credit.  It should do the exact same thing
   * as reverseList() above, except it should do it recursively instead of
   * iteratively (i.e. no loops allowed).
   *
   * Again, you may not allocate any new Link structs or any other auxiliary
   * data structures.  You may, however, define an auxiliary function to help
   * you do the recursion.
   *
   * Return a pointer to the new head of the list.
   */
struct Link* nextLink;
    struct Link* currentLink = head;
    struct Link* previousLink = NULL;
    while (currentLink != NULL)
    {
        nextLink  = currentLink->next;
        currentLink->next = previousLink;
        previousLink = currentLink;
        currentLink = nextLink;
    }
    head = previousLink;

  return head;

}
