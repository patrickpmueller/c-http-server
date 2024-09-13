// A threadpool manager 
#include <threadpool.h>

bool threadpool_initialized = false;
bool threadpool_running = false;
thread *threads;
int thread_count;
queue *thread_request_queue;
bool have_non_working = true;


int init(int thread_count_start) 
{
	if (threadpool_initialized) {
		return 1;
	}

	if (thread_count_start == -1) {
		thread_count_start = THREADPOOL_SIZE;	
	}

	threads = (thread *)malloc(thread_count_start * sizeof(threads));
	thread_count = thread_count_start;
	thread_request_queue = (queue *)malloc(sizeof(thread_request_queue));

	for (int i = 0; i < thread_count; i++) {
	}

	return 0;
}

int destroy() 
{
	if (!threadpool_initialized) {
		return 1;
	}
	free(threads);
	free(thread_request_queue);
	thread_count = 0;
	return 0;
}

int start() 
{
	if (!threadpool_initialized) {
		return 1;
	}
	threadpool_running = true;
	have_non_working = false;

	for (int i = 0; i < thread_count; i++) {
		thread t = threads[i];
		if (is_empty(thread_request_queue)) {
			t.running = false;
			have_non_working = true;
		} else {
			job todo = dequeue(thread_request_queue);
			pthread_create(&t.id, NULL, todo.run, NULL);	
			t.running = true;
		}
	}

	return 0;
}

int queue_process(void *(*process) (void *)) {
	if (have_non_working) {
		for (int i = 0; i < thread_count; i++) {
			thread t = threads[i];
			if (!t.running) {
				void *(*__start_routine) (void *)
				t.running = true;
				t.callback = process;
				pthread_create(&t.id, NULL, process, NULL)
				break;
			}
		}
	} else {
		enqueue(thread_request_queue, { .run = process });
	}
}

void continue_after_finished(void (*process)) {
	process();
	if (!is_empty(thread_request_queue)) {
		dequeue(thread_request_queue)->run();
	}
}
