#ifndef LIBTHREADPOOL_H
#define LIBTHREADPOOL_H

int init(int thread_count_start);
int destroy();
int start();
int stop();
int queue_process(char* message);

#endif // LIBTHREADPOOL_H
