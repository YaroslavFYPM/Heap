typedef struct {
    int key;
    int value;
} node;

typedef struct {
    node* data;
    int length;
    int heap_size;
} heap;

void heap_add(heap* heap, node node);

int heap_extract_min(heap* heap);

heap* heap_create(int length);

void heap_remove(heap* heap);

int heap_min(heap* heap);

void heap_checkdown(heap* heap, int parent);

