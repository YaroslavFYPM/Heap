#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "heap.h"

void set_error(heap_error_t* heap_error, heap_error_t error, const char* message) {
    fprintf(stderr, "%s", message);
    if (heap_error != NULL)
        *heap_error = error;
}

heap_t* create_heap(int capacity, heap_error_t* heap_error)
{
    if (capacity < 1) {
        set_error(heap_error, INVALID_ARGUMENT, "Invalid argument: size\n");
        return NULL;
    }

    heap_t* heap = (heap_t*)calloc(1, sizeof(heap_t));
    if (heap == NULL) {
        set_error(heap_error, MALLOC_FAILED, "Not enough memory\n");
        return NULL;
    }

    heap->data = (node_t*)calloc(capacity, sizeof(node_t));
    if (heap->data == NULL) {
        set_error(heap_error, MALLOC_FAILED, "Not enough memory\n");
        free(heap);
        return NULL;
    }

    heap->size = 0;
    heap->capacity = capacity;

    *heap_error = SUCCESS;
    return heap;
}

void destroy_heap(heap_t* heap, heap_error_t* heap_error)
{
    if (heap == NULL) {
        set_error(heap_error, INVALID_ARGUMENT, "Invalid argument: heap is null pointer\n");
        return;
    }

    if (heap->data)
        free(heap->data);
    free(heap);

    *heap_error = SUCCESS;
}

int heap_get_min(heap_t* heap, heap_error_t* heap_error)
{
    if (heap == NULL) {
        set_error(heap_error, INVALID_ARGUMENT, "Invalid argument: heap\n");
        return 0;
    }

    if ((heap->size) < 1) {
        set_error(heap_error, HEAP_EMPTY, "Heap is empty\n");
        return 0;
    }

    *heap_error = SUCCESS;
    return heap->data[0].value;
}

void sift_down(heap_t* heap, int parent, heap_error_t* heap_error) 
{   
    if (heap == NULL) {
        set_error(heap_error, INVALID_ARGUMENT, "Invalid argument: heap\n");
        return;
    } 

    if (parent > heap->size) {
        set_error(heap_error, INVALID_ARGUMENT, "Invalid argument: parent\n");
        return;        
    }

    int left = (1 + parent)*2 - 1;                                 //////////????
    int right = (1 + parent)*2;        
    int least = parent;

    if (left < (heap->size) && ((heap->data[left].key) < (heap->data[parent].key)))
        least = left; 
    else 
        least = parent;

    if (right < (heap->size) && ((heap->data[right].key) < (heap->data[least].key)))
        least = right;

    if (least != parent) {
        node_t tmp = heap->data[parent];
        heap->data[parent] = heap->data[least];
        heap->data[least] = tmp;

        sift_down(heap, least, heap_error); 
    }

    *heap_error = SUCCESS;      
}

int heap_extract_min(heap_t* heap, heap_error_t* heap_error) 
{
    if (heap == NULL) {
        set_error(heap_error, INVALID_ARGUMENT, "Invalid argument: heap\n");
        return 0;
    }

    if ((heap->size) < 1) {                                                 //////////????
        set_error(heap_error, HEAP_EMPTY, "Heap is empty\n");
        return 0;
    }

    int min = heap->data[0].value;
    heap->data[0] = heap->data[(heap->size)-1];
    heap->size -= 1;                                               //////????????
                                        
    sift_down(heap, 0, heap_error);

    *heap_error = SUCCESS;
    return min;
}

void sift_up(heap_t* heap, int child, heap_error_t* heap_error)
{
    if (heap == NULL) {
        set_error(heap_error, INVALID_ARGUMENT, "Invalid argument: heap\n");
        return;
    } 

    if (child > heap->size) {
        set_error(heap_error, INVALID_ARGUMENT, "Invalid argument: parent\n");
        return;        
    }    

    int parent;
    for (parent = (child - 1) / 2; parent >= 0; child = parent, parent = (child - 1) / 2) {

        if ( heap->data[parent].key > heap->data[child].key ) {
            node_t tmp = heap->data[parent];
            heap->data[parent] = heap->data[child];
            heap->data[child] = tmp;
        } else 
            break; 

    }

    heap_error = SUCCESS;
} 

void heap_add(heap_t* heap, node_t node, heap_error_t* heap_error)
{
	if (heap == NULL) {
        set_error(heap_error, INVALID_ARGUMENT, "Invalid argument: heap\n");
		return;
	}

    if (heap->size == heap->capacity) {
        set_error(heap_error, HEAP_OVERFLOW, "Heap is full\n");
        return;
    }

    *heap_error = SUCCESS;
    heap->data[heap->size] = node;
    heap->size += 1;

    *heap_error = SUCCESS;

    sift_up(heap, heap->size - 1, heap_error);
}
