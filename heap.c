#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "stack.h"

heap* heap_create(int initial_size)
{
    heap* h = (heap*)malloc(sizeof(heap));
    h->data = (node*)malloc(sizeof(node)*initial_size);
    h->length = initial_size;
    h->heap_size = 0;
    return h;
}

void heap_remove(heap* h)
{
    free(h->data);
    free(h);
}

int heap_min(heap* h)
{
    if ((h->heap_size) < 1)
        return;
    return h->data[0].value;
}

void heap_checkdown(heap* h, int parent) 
{
    left = (1 + parent)*2 - 1;
    right = (1 + parent)*2;
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
        heap_checkdown(&h, least); 
    }      
}

int heap_extract_min(heap* h)
{
    if ((h->heap_size) < 1)
        return;
    min = h->data[0].value;
    h->data[0] = h->data[(h->heap_size)-1];
    h->heap_size -= 1;
    heap_checkdown(&h, 0);
    return min;
}

void heap_checkup(heap* h, int child)
{
    int parent;
    for (parent = (child - 1)/2; parent >= 0; child = parent, parent = (child - 1) /2) {
        if ( h->data[parent].key > h->data[child].key] ) {
            node tmp = h->data[parent];
            h->data[parent] = h->data[child];
            h->data[child] = tmp;
        } else 
            break;   
    }
} 

void heap_add(heap* h, node n)
{
    if (h->heap_size == h->length) 
        return 0;
    h->data[h->heap_size] = n;
    h->heap_size += 1;
    heap_checkup(h, h->heap_size - 1);
}
