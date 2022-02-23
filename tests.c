#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

int main()
{
    int i = 0;
    heap* h = heap_create(10);
    for (i = 10; i > 0; --i) {
        node n;
        n.key = i;
        n.value = i;
        heap_add(h, n);
    }
    for (i = 0; i < 10; ++i) {
        printf("%d\n", heap_extract_min(h));
    }
    heap_remove(h);
    return 0;
}