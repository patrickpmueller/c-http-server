#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 128;

typedef struct {
    char *http_method;
    char *path;
    char *http_version;
} req;

typedef struct node {
    struct node *next;
    struct node *prev;
    job val;
} node;

typedef struct {
    node *head;
    node *tail;
    int len;
} queue;

extern bool queue_initialized;

// Function declarations
void initializeQueue(queue *q);
bool is_empty(queue *q);
bool is_full(queue *q);
int enqueue(queue *q, req value);
req dequeue(queue *q);
req peek(queue *q);

#endif // QUEUE_H
