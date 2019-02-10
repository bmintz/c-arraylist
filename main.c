#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

int print_iter(void *context, void *val) {
	printf("%s\n", (char *) val);
	return 1; /* always keep going */}

void eval_tracefile(char *filename) {
	FILE *infile;
	unsigned int list_capacity, i;
	char buf[80], *val;
	arraylist_t *l;

	if ((infile = fopen(filename, "r")) == NULL) {
		printf("Error opening tracefile %s\n", filename);
		exit(1);}

	fscanf(infile, "%u", &list_capacity);
	printf("Creating arraylist of capacity %u\n", list_capacity);
	l = arraylist_new(list_capacity);

	while (fscanf(infile, "%s", buf) != EOF) {
		switch(buf[0]) {
		case 'a':
			fscanf(infile, "%s", buf);
			val = strdup(buf);
			printf("Appending %s to the arraylist\n", val);
			arraylist_append(l, val);
			break;
		case 'd':
			fscanf(infile, "%u", &i);
			printf("Deleting l[%u]\n", i);
			arraylist_del(l, i);
			break;
		case 'p':
			printf("Printing all values\n");
			arraylist_iter(l, NULL, print_iter);
			break;
		default:
			printf("Bad tracefile directive (%c)", buf[0]);
			exit(1);}}

	arraylist_free(l);
	fclose(infile);}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: %s TRACEFILE_NAME\n", argv[0]);
		return 1;}
	eval_tracefile(argv[1]);
	return 0;}
