#include "queue.h"

void init_queue(queue_t *q){
	q->front = 0;
	q->back = 0;
	q->size = 0;
}

int dequeue(queue_t *q){
	int ret;
	if(q->size == 0) return -100000000;
	ret = q->a[q->front];
	q->front = (q->front + 1) % MAX_Q;
	q->size--;
	return ret;
}

void enqueue(queue_t *q, int val){
	if(q->size == MAX_Q) return;

	q->a[q->back] = a;
	q->back = (q->back + 1) % MAX_Q;
	q->size++;
}


int peak(queue_t *q){
	if(q->size == 0) return -10000000000;
	return q->a[q->front];
}
