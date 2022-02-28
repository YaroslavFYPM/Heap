#pragma once

typedef struct node {
    int key;
    int value;
} node_t;

typedef struct heap {
    node_t* data;
    int size;
    int capacity;
} heap_t;

typedef enum heap_error {
	SUCCESS,
	MALLOC_FAILED,
	HEAP_OVERFLOW,
	HEAP_EMPTY,
	INVALID_ARGUMENT
} heap_error_t;

/**
 * @brief Create a heap object
 * 
 * @param capacity Maximum number of elements in the heap
 * @param heap_error Parameter for bug tracking
 * @return heap* Returning a pointer to the created object
 */
heap_t* create_heap(int capacity, heap_error_t* heap_error);

/**
 * @brief Destroy a heap object
 * 
 * @param heap Pointer to the object we want to destroy
 * @param heap_error Parameter for bug tracking
 */
void destroy_heap(heap_t* heap, heap_error_t* heap_error);

/**
 * @brief Adding an element to the heap
 * 
 * @param heap Pointer to the object to which we want to add an element
 * @param node The element we want to add
 * @param heap_error Parameter for bug tracking
 */
void heap_add(heap_t* heap, node_t node, heap_error_t* heap_error);

/**
 * @brief Extracting the element with the smallest key value from the heap and finding out its value
 * 
 * @param heap Pointer to the object from which we want to extract the element
 * @param heap_error Parameter for bug tracking
 * @return int Returning the value of an element
 */
int  heap_extract_min(heap_t* heap, heap_error_t* heap_error);

/**
 * @brief Getting the value of the element with the smallest key value
 * 
 * @param heap Pointer to the object from which we want to get the element
 * @param heap_error Parameter for bug tracking
 * @return int Returning the value of an element
 */
int  heap_get_min(heap_t* heap, heap_error_t* heap_error);

void sift_down(heap_t* heap, int parent, heap_error_t* heap_error);

void sift_up(heap_t* heap, int child, heap_error_t* heap_error);