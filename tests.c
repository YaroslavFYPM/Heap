#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

int main()
{
    int i = 0;
    heap* h;
    HEAP_ERR err;

    printf("Test 1: CREATE\n");   
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
    for (i = 10; i > 0; --i) {
        node n;
        HEAP_ERR err;
        n.key = i;
        n.value = i;
        heap_add(h, n, &err);
        if (err == ESUCCESS) 
            fprintf(stdout, "Test 2.%d \tpassed\n", 11-i);
        else
            fprintf(stdout, "Test 2.%d \tfailed\n", 11-i);   
    }
    node n;
    n.key = 11;
    n.value = 11;
    heap_add(h, n, &err);
    if (err == EFULL) 
        fprintf(stdout, "Test 2.11 \tpassed\n");
    else
        fprintf(stdout, "Test 2.11 \tfailed\n");  
    heap_add(NULL, n, &err);
    if (err == EINVARG) 
        fprintf(stdout, "Test 2.11 \tpassed\n");
    else
        fprintf(stdout, "Test 2.11 \tfailed\n");      

    printf("Test 3: MIN\n");
    if ((heap_min(h, &err) == 1) && (err == ESUCCESS))
        fprintf(stdout, "Test 3.1 passed\n");
    else
        fprintf(stdout, "Test 3.1 failed\n");
    
    printf("Test 4: EXTRACT_MIN\n");
    for (i = 1; i <= 10; ++i) {
        int tmp = heap_extract_min(h, &err);
        if ((tmp == i) && (err == ESUCCESS)) 
            fprintf(stdout, "Test 4.%d passed\n", i);
        else 
            fprintf(stdout, "Test 4.%d failed\n", i);
    }
    
    int tmp = heap_min(h, &err);
    if (err == EEMPTY)
        printf("Test 3.2 passed\n");
    else 
        printf("Test 3.2 failed\n");

    tmp = heap_extract_min(h, &err);
    if (err == EEMPTY)
        printf("Test 4.11 passed\n");
    else 
        printf("Test 4.11 failed\n");

 
    tmp = heap_min(NULL, &err);
    if (err == EINVARG)
        printf("Test 3.3 passed\n");
    else 
        printf("Test 3.3 failed\n"); 

    tmp = heap_extract_min(NULL, &err);
    if (err == EINVARG)
        printf("Test 4.12 passed\n");
    else 
        printf("Test 4.12 failed\n");   
    
    printf("Test 5: REMOVE\n");
    heap_remove(NULL);
    heap_remove(h);
    printf("Test 5: passed\n");
    return 0;
}