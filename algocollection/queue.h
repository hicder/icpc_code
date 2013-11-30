#ifndef __QUEUE_H
#define __QUEUE_H
#define MAX_Q 1000
typedef struct queue{
	int a[MAX_Q];
	int front, back;
	int size;
}queue_t;

void init_queue(queue_t * q);
int dequeue(queue_t * q);
int peak(queue_t * q);
void enqueue(queue_t *q, int val);

#endif
