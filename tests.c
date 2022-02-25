#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

int main()
{
    int i = 0;
    heap* h;
    HEAP_ERR err;
    
    h = heap_create(-1, &err);
    if (err != EINVARG) 
        fprintf(stdout, "Test 1.1 \tfailed\n");
    else 
        fprintf(stdout, "Test 1.1 \tpassed\n");

    h = heap_create(10, &err);    
    if (err != ESUCCESS)
        fprintf(stdout, "Test 1.2 \tfailed\n");
    else 
        fprintf(stdout, "Test 1.2 \tpassed\n");

    printf("Test 2: ADD\n");
    for (i = 10; i >= 0; --i) {
        node n;
        n.key = i;
        n.value = i;
        heap_add(h, n);
    }

    printf("Test 2 passed\n");

    printf("Test 3: MIN\n");
    if (heap_min(h) == 1)
        printf("Test 3.1 passed\n");
    else
        printf("Test 3.1 failed\n");
    
    printf("Test 4: EXTRACT_MIN\n");
    for (i = 1; i <= 10; ++i) {
        int tmp = heap_extract_min(h);
        if (tmp == i) 
            printf("Test 4.%d passed\n", i);
        else 
            printf("Test 4.%d failed\n", i);
    }
    
    if (heap_min(h) == 0)
        printf("Test 3.2 passed\n");
    else 
        printf("Test 3.2 failed\n");


    if (heap_extract_min(h) == 0)
        printf("Test 4.11 passed\n");
    else 
        printf("Test 4.11 failed\n");

    printf("Test 5: REMOVE\n");
    heap_remove(NULL);
    heap_remove(h);
    printf("Test 5: passed\n");
    return 0;
}