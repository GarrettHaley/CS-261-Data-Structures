/*
 * This file contains the implementation of a priority queue.
 *
 * You must complete the implementations of these functions:
 *   pq_insert()
 *   pq_first()
 *   pq_remove_first()
 */

#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "dynarray.h"
#include "pq.h"
// This is the initial capacity that will be allocated for the heap.
#define INITIAL_HEAP_CAPACITY 16

/*
 * This is the definition of the structure we will use to represent the
 * priority queue.  It contains only a dynamic array, which will be used to
 * store the heap underlying the priority queue.
 */
struct pq {
  struct dynarray* heap;
};


/*
 * This is an auxiliary structure that we'll use to represent a single element
 * in the priority queue.  It contains two fields:
 *
 *   priority - the priority value assigned to the item
 *   item - the pointer to the data item represented by this element
 *
 * Both of these will come directly from the corresponding values passed to
 * pq_insert().
 */
struct pq_elem {
  int priority;
  void* item;
};


/*
 * This function allocates and initializes a new priority queue.
 *
 * You should not modify this function.
 */
struct pq* pq_create() {
  struct pq* pq = malloc(sizeof(struct pq));
  assert(pq);
  pq->heap = dynarray_create(INITIAL_HEAP_CAPACITY);
  return pq;
}


/*
 * This function frees the memory associated with a priority queue.
 *
 * You should not modify this function.
 */
void pq_free(struct pq* pq) {
  assert(pq);
  dynarray_free(pq->heap);
  free(pq);
}

/*
 * This function returns 1 if the given priority queue is empty or 0
 * otherwise.
 *
 * You should not mofidy this function.
 */
int pq_isempty(struct pq* pq) {
  assert(pq);
  return dynarray_size(pq->heap) > 0;
}


/*
 * This function inserts a new item with a specified priority into a priority
 * queue.
 *
 * You should complete the implementation of this function.  The first part
 * is done for, where a new element is created to be placed into the dynamic
 * array underlying the priority queue.
 */
void pq_insert(struct pq* pq, void* item, int priority) {
  assert(pq);

  /*
   * Allocate space for the new element to be placed into the priority queue
   * and initialize it with the provided values.
   */

  /*
   * Figure out where in the heap array to insert the new element represented
   * by new_elem and insert it.
   */

  /*
   * Restore the heap so that it has the property that every node's priority
   * value is less than the priority values of its children.  This can be
   * done by "percolating" the newly added element up in the heap array.  To
   * perform the percolation, you will have to compare the priority values of
   * the struct pq_elems in the heap array (i.e. by comparing the
   * elem->priority values).
   */

struct pq_elem *tempElem;
struct pq_elem* new_elem = malloc(sizeof(struct pq_elem));
  new_elem->item = item;
  new_elem->priority = priority;
  dynarray_insert(pq->heap,dynarray_size(pq->heap),new_elem);
		for(int x = dynarray_size(pq->heap);x>0;x--){
		int k = (x-1)/2;
		if(k < 0)
			break;
		struct pq_elem* kValue =(dynarray_get(pq->heap,k));
		struct pq_elem* xValue =(dynarray_get(pq->heap,x)); 
		if(kValue->priority > xValue->priority){
			tempElem = xValue;
			dynarray_insert(pq->heap,x,kValue);
			dynarray_insert(pq->heap,k,tempElem);

		}
	}

}

/*
 * This function returns the first (highest-priority) item from a priority
 * queue without removing it.
 *
 * You should complete the implementation of this function.
 */

void* pq_first(struct pq* pq) {
  assert(pq);
  assert(dynarray_size(pq->heap) > 0);

  struct pq_elem* first_elem = NULL;
  for(int x = 0; x<dynarray_size(pq->heap)-1;x++){
	struct pq_elem* getCurrent = dynarray_get(pq->heap,x);
	struct pq_elem* getNext = dynarray_get(pq->heap,x+1);
	if(getNext->priority <= getCurrent->priority )
		first_elem = getNext;
  else{
	first_elem = getCurrent;
  }
  }

	
  /*
   * Determine what index in the heap array corresponds to the highest-priority
   * element (i.e. the one with the lowest priority value), and store the
   * value there in first_elem.
   */

  /*
   * Return the extracted item, if the element taken out of the priority
   * queue is not NULL.
   */
  if (first_elem != NULL) {
    return first_elem->item;
  } else {
    return NULL;
  }
}


/*
 * This function removes the first (highest-priority) element from a priority
 * queue and returns its value.
 *
 * You should complete this function.
 */
void* pq_remove_first(struct pq* pq) {

  assert(pq);
  assert(dynarray_size(pq->heap) > 0);
  struct pq_elem*  tempElem;
  struct pq_elem* first_elem = NULL;
   struct pq_elem* last_elem = NULL;
  first_elem = dynarray_get(pq->heap,0);
  last_elem = dynarray_get(pq->heap,dynarray_size(pq->heap));
  dynarray_set(pq->heap,0,last_elem);
  
   
for(int x = dynarray_size(pq->heap);x>0;x--){
		int k = 2*x+1;
		if(k<dynarray_size(pq->heap))
			break;
		struct pq_elem* kValue =(dynarray_get(pq->heap,k));
		struct pq_elem* xValue =(dynarray_get(pq->heap,x)); 
		if(kValue->priority <= xValue->priority){
			tempElem = xValue;
			dynarray_insert(pq->heap,x,kValue);
			dynarray_insert(pq->heap,k,tempElem);

		}
}
  /*
   * Determine what index in the heap array corresponds to the highest-priority
   * element (i.e. the one with the lowest priority value), and store the
   * value there in first_elem.
   */

  /*
   * Replace the highest-priority element with the appropriate one from within
   * the heap array.  Remove that replacement element from the array after
   * copying its value to the location of the old highest-priority element..
   */

  /*
   * Restore the heap so that it has the property that every node's priority
   * value is less than the priority values of its children.  This can be
   * done by "percolating" the element that replaced the highest-priority
   * element down in the heap array.  To perform the percolation, you will
   * have to compare the priority values of the struct pq_elems in the heap
   * array (i.e. by comparing the elem->priority values).  It may be helpful
   * to write a helper function to accomplish this percolation down.
   */

  /*
   * Return the extracted item, if the element taken out of the priority
   * queue is not NULL.
   */
  if (first_elem != NULL) {
    return first_elem->item;
  } else {
    return NULL;
  }
}
