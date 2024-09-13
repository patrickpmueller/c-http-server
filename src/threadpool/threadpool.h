#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <unistd.h>
#include <queue.h>

#ifndef THREADPOOL_H
#define THREADPOOL_H

#define THREADPOOL_SIZE sysconf(_SC_NPROCESSORS_ONLN)

typedef struct {
    pthread_t id;
    void (*callback)();
    bool running;
} thread;

extern thread *threads;
extern int thread_count;
extern bool threadpool_initialized; 
extern bool threadpool_running;
extern queue *thread_request_queue;

int init(int thread_count_start);
int destroy();
int start();
int stop();
int queue_process(void *(*process) (void *));

#endif // THREADPOOL_H
