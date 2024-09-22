#include <threadpool.h>

bool queue_initialized = false;

// Function to initialize the queue
void initializeQueue(queue *q)
{
	q->head = NULL; 
	q->tail = NULL;
	q->len = 0;
}

// Function to check if the queue is empty
bool is_empty(queue *q) 
{ 
	return q->len == 0; 
}

// Function to check if the queue is full
bool is_full(queue *q) 
{ 
	return q->len >= MAX_SIZE; 
}

// Function to add an element to the queue (Enqueue
// operation)
int enqueue(queue *q, req value)
{
	if (!queue_initialized) {
		return 1;
	}
	if (is_full(q)) {
		return 2;
	}

	node new_node = { .next = NULL, .prev = (q->tail), .val = value };
	q->tail->prev = &new_node;
	q->tail = &new_node;
	return 0;
}

req dequeue(queue *q) 
{
	if (!queue_initialized || is_empty) {
		req empty = { 0 };
		return empty;
	}
	
	req ret = peek(q);
	q->head = q->head->prev;
	q->head->next = NULL;
	
	return ret;
}

req peek(queue *q) 
{
	if (!queue_initialized || is_empty) {
		req empty = { 0 };
		return empty;
	}
	
	return q->head->val;
}
