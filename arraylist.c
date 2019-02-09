#include <stdlib.h>
#include "arraylist.h"

arraylist_t *arraylist_new(unsigned int initial_capacity) {
	arraylist_t *l = malloc(sizeof(arraylist_t *));
	l->capacity = initial_capacity;
	l->length = 0;
	l->data = calloc(sizeof(void *), initial_capacity);}

void arraylist_append(arraylist_t *l, void *val) {
	if (l->length >= l->capacity) {
		unsigned int new_capacity = l->capacity * 2;
		l->capacity = new_capacity;
		l->data = realloc(l->data, new_capacity);}

	l->data[l->length] = val;
	l->length++;
	return;}

void arraylist_iter(arraylist_t *l, void *context, int (*f)(void *context, void *val)) {
	for (unsigned int i = 0; i < l->length; i++) {
		if (!f(context, l->data[i])) {
			return;}}}

void arraylist_free(arraylist_t *l) {
	for (unsigned int i = 0; i < l->length; i++) {
		free(l->data[i]);}

	free(l->data);
	free(l);}
