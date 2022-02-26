#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "heap.h"

heap* heap_create(int initial_size, HEAP_ERR *err)
{
    if (initial_size < 1) {
        fprintf(stderr, "Invalid argument: size\n");
        if (err != NULL) 
            *err = EINVARG;
        return NULL;
    }
    
    heap* h = (heap*)malloc(sizeof(heap));

    if (h == NULL) {
        fprintf(stderr, "Not enough memory\n");
        if (err != NULL) 
            *err = EMALLOC;
        return NULL;
    }
    h->data = (node*)malloc(sizeof(node)*initial_size);
    if (h->data == NULL) {
        free(h);
        fprintf(stderr, "Not enough memory\n");
        if (err != NULL) {
            *err = EMALLOC;
        }
        return NULL;
    }
    *err = ESUCCESS;
    h->length = initial_size;
    h->heap_size = 0;
    return h;
}

void heap_remove(heap* h)
{
    if (h == NULL) 
        return;
    if (h->data)
        free(h->data);
    free(h);
}

int heap_min(heap* h)
{
    if ((h->heap_size) < 1)
        return 0;
    return h->data[0].value;
}

void heap_checkdown(heap* h, int parent) 
{
    int left = (1 + parent)*2 - 1;
    int right = (1 + parent)*2;
    int least = parent;
    if (left < (h->heap_size) && ((h->data[left].key) < (h->data[parent].key)))
        least = left; 
    else 
        least = parent;
    if (right < (h->heap_size) && ((h->data[right].key) < (h->data[least].key)))
        least = right;
    if (least != parent) {
        node tmp = h->data[parent];
        h->data[parent] = h->data[least];
        h->data[least] = tmp;
        heap_checkdown(h, least); 
    }      
}

int heap_extract_min(heap* h)
{
    if ((h->heap_size) < 1)
        return 0;
    int min = h->data[0].value;
    h->data[0] = h->data[(h->heap_size)-1];
    h->heap_size -= 1;
    heap_checkdown(h, 0);
    return min;
}

void heap_checkup(heap* h, int child)
{
    int parent;
    for (parent = (child - 1)/2; parent >= 0; child = parent, parent = (child - 1) /2) {
        if ( h->data[parent].key > h->data[child].key ) {
            node tmp = h->data[parent];
            h->data[parent] = h->data[child];
            h->data[child] = tmp;
        } else 
            break;   
    }
} 

void heap_add(heap* h, node n, HEAP_ERR* err)
{
	if (h == NULL) {
		fprintf(stderr, "Invalig argument: heap\n");
		if (err != NULL)
			*err = EINVARG;
		return;
	}

    if (h->heap_size == h->length) {
        fprintf(stderr, "Heap is full\n");
        if (err != NULL) 
            *err = EFULL;
        return;
    }
    *err = ESUCCESS;
    h->data[h->heap_size] = n;
    h->heap_size += 1;
    heap_checkup(h, h->heap_size - 1);
}
