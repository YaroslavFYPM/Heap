typedef struct {
    int key;
    int value;
} node;

typedef struct {
    node* data;
    int length;
    int heap_size;
} heap;

typedef enum {
	ESUCCESS = 0,
	EMALLOC,
	EFULL,
	EEMPTY,
	EINVARG
} HEAP_ERR;

void heap_add(heap* heap, node node, HEAP_ERR* err);

int heap_extract_min(heap* heap);

heap* heap_create(int length, HEAP_ERR* err);

void heap_remove(heap* heap);

int heap_min(heap* heap);

void heap_checkdown(heap* heap, int parent);

void heap_checkup(heap* heap, int child);

