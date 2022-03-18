#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

int main()
{
    int i = 0;
    heap_t* heap;
    heap_error_t heap_error;


    printf("Test 1: CREATE\n");

    heap = create_heap(-1, &heap_error);
    if (heap_error != INVALID_ARGUMENT)
        fprintf(stdout, "Test 1.1 \tfailed\n");
    else
        fprintf(stdout, "Test 1.1 \tpassed\n");

    heap = create_heap(10, &heap_error);
    if (heap_error != SUCCESS)
        fprintf(stdout, "Test 1.2 \tfailed\n");
    else
        fprintf(stdout, "Test 1.2 \tpassed\n");


    printf("Test 2: ADD\n");

    for (i = 10; i > 0; --i) {
        node_t node;
        heap_error_t heap_error;
        node.key = i;
        node.value = i;

        heap_add(heap, node, &heap_error);
        if (heap_error == SUCCESS)
            fprintf(stdout, "Test 2.%d \tpassed\n", 11-i);
        else
            fprintf(stdout, "Test 2.%d \tfailed\n", 11-i);
    }

    node_t node;
    node.key = 11;
    node.value = 11;

    heap_add(heap, node, &heap_error);
    if (heap_error == HEAP_OVERFLOW)
        fprintf(stdout, "Test 2.11 \tpassed\n");
    else
        fprintf(stdout, "Test 2.11 \tfailed\n");

    heap_add(NULL, node, &heap_error);
    if (heap_error == INVALID_ARGUMENT)
        fprintf(stdout, "Test 2.11 \tpassed\n");
    else
        fprintf(stdout, "Test 2.11 \tfailed\n");


    printf("Test 3: MIN\n");

    if ((heap_get_min(heap, &heap_error) == 1) && (heap_error == SUCCESS))
        fprintf(stdout, "Test 3.1 \tpassed\n");
    else
        fprintf(stdout, "Test 3.1 \tfailed\n");

    printf("Test 4: EXTRACT_MIN\n");

    for (i = 1; i <= 10; ++i) {
        int tmp = heap_extract_min(heap, &heap_error);
        if ((tmp == i) && (heap_error == SUCCESS))
            fprintf(stdout, "Test 4.%d \tpassed\n", i);
        else
            fprintf(stdout, "Test 4.%d \tfailed\n", i);
    }

    int tmp = heap_get_min(heap, &heap_error);
    if (heap_error == HEAP_EMPTY)
        printf("Test 3.2 \tpassed\n");
    else
        printf("Test 3.2 \tfailed\n");

    tmp = heap_extract_min(heap, &heap_error);
    if (heap_error == HEAP_EMPTY)
        printf("Test 4.11 \tpassed\n");
    else
        printf("Test 4.11 \tfailed\n");

    tmp = heap_get_min(NULL, &heap_error);
    if (heap_error == INVALID_ARGUMENT)
        printf("Test 3.3 \tpassed\n");
    else
        printf("Test 3.3 \tfailed\n");

    tmp = heap_extract_min(NULL, &heap_error);
    if (heap_error == INVALID_ARGUMENT)
        printf("Test 4.12 \tpassed\n");
    else
        printf("Test 4.12 \tfailed\n");


    printf("Test 5: SHIFTUP\n");

    heap_add(heap, node, &heap_error);
    heap_add(heap, node, &heap_error);

    sift_up(heap, 5, &heap_error);
    if (heap_error == INVALID_ARGUMENT)
        printf("Test 5.1\t passed\n");
    else
        printf("Test 5.1\t failed\n");

    sift_up(NULL, 1, &heap_error);
    if (heap_error == INVALID_ARGUMENT)
        printf("Test 5.2\t passed\n");
    else
        printf("Test 5.2\t failed\n");


    printf("Test 6: CHECKDOWN\n");

    sift_down(heap, 5, &heap_error);
    if (heap_error == INVALID_ARGUMENT)
        printf("Test 6.1\t passed\n");
    else
        printf("Test 6.1\t failed\n");

    sift_down(NULL, 1, &heap_error);
    if (heap_error == INVALID_ARGUMENT)
        printf("Test 6.2\t passed\n");
    else
        printf("Test 6.2\t failed\n");


    printf("Test 7: DESTROY\n");

    destroy_heap(NULL, &heap_error);
    if (heap_error == INVALID_ARGUMENT)
         printf("Test 7.1\t passed\n");
    else
        printf("Test 7.1\t failed\n");

    destroy_heap(heap, &heap_error);
    if (heap_error == SUCCESS)
         printf("Test 7.2\t passed\n");
    else
        printf("Test 7.2\t failed\n");

    return 0;
}