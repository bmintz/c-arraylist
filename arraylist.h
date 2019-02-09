typedef struct arraylist arraylist_t;

struct arraylist {
	unsigned int capacity;
	unsigned int length;
	void **data;};

arraylist_t *arraylist_new(unsigned int capacity);
void arraylist_free(arraylist_t *);
void arraylist_append(arraylist_t *, void *);
void arraylist_insert(arraylist_t *, unsigned int i, void *);
void arraylist_del(arraylist_t *, unsigned int i);
void arraylist_iter(arraylist_t *, void *context, int (*)(void *context, void *));
void arraylist_clear(arraylist_t *);
