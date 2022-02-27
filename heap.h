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
 * @param capacity 
 * @param heap_error 
 * @return heap* 
 */
heap_t* create_heap(int capacity, heap_error_t* heap_error);

/**
 * @brief 
 * 
 * @param heap 
 * @param heap_error 
 */
void destroy_heap(heap_t* heap, heap_error_t* heap_error);

/**
 * @brief 
 * 
 * @param heap 
 * @param node 
 * @param heap_error 
 */
void heap_add(heap_t* heap, node_t node, heap_error_t* heap_error);

/**
 * @brief 
 * 
 * @param heap 
 * @param heap_error 
 * @return int 
 */
int  heap_extract_min(heap_t* heap, heap_error_t* heap_error);

/**
 * @brief 
 * 
 * @param heap 
 * @param heap_error 
 * @return int 
 */
int  heap_get_min(heap_t* heap, heap_error_t* heap_error);

void sift_down(heap_t* heap, int parent, heap_error_t* heap_error);

void sift_up(heap_t* heap, int child, heap_error_t* heap_error);