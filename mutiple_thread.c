#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>  
#include <semaphore.h>

#define MAX_NUM 100
 
struct queue {
    int mob_num[MAX_NUM];
    int rear;
    int front;
};

struct queue bad;
struct queue product;
pthread_mutex_t mutex_lock0;
pthread_mutex_t mutex_lock1; 
pthread_cond_t cond; 

pthread_rwlock_t rw_lock;

sem_t sem;
int child_id[10];
 
static void push_queue(struct queue *bad, int num)
{
    int position;
 
    if ((bad->rear + 1) % MAX_NUM == bad->front) {
    //     printf("the queue is full\n");
         return;
    }
 
     bad->mob_num[bad->rear] = num;
     bad->rear = (bad->rear + 1) % MAX_NUM;
      
}
 
static int pop_queue(struct queue *bad)
{
    int data;
 
    if (bad->rear == bad->front) {
  //      printf("the queue is empty\n");
        return -1;
    }
     
    data = bad->mob_num[bad->front];
    bad->front = (bad->front + 1) % MAX_NUM;
 
    return data;   
}
 
void *func_creat(void *data)
{
    int num = 0;
    int bad_num;
 
    while (1) {
         pthread_mutex_lock(&mutex_lock0);  
         bad_num = pop_queue(&bad);
         pthread_mutex_unlock(&mutex_lock0);
         if (bad_num != -1) {
                bad_num++;
                pthread_mutex_lock(&mutex_lock1);
                push_queue(&product, bad_num);
                pthread_mutex_unlock(&mutex_lock1);
		printf("back a bad num\n");
         } else {
             pthread_mutex_lock(&mutex_lock1);
             push_queue(&product, num);
             pthread_mutex_unlock(&mutex_lock1);
             printf("product a new num\n");
             num++;
	     pthread_cond_signal(&cond);
             sleep(6);
         } 
    }
}
 
void *func_check(void *data)
{
    int num;
 
    while (1) {
        pthread_mutex_lock(&mutex_lock1);
        num = pop_queue(&product);
	if (num == -1) {
		pthread_cond_wait(&cond, &mutex_lock1);
	}
        pthread_mutex_unlock(&mutex_lock1);

	if (num != -1) {
		if (num % 2) {
		    pthread_mutex_lock(&mutex_lock0);
		    push_queue(&bad, num);
		    pthread_mutex_unlock(&mutex_lock0);
		    printf("check one bad num\n");
		} else {
		    printf("check pass\n");
		}
		sleep(2);    
	}
    }
}

static void *rw_test0(void *data)
{
	while (1) {
		pthread_rwlock_rdlock(&rw_lock);
		printf("enter rw_test0\n");
		sleep(6);
		pthread_rwlock_unlock(&rw_lock);
		sleep(1);
	}
}

static void *rw_test1(void *data)
{
	while (1) {
		pthread_rwlock_rdlock(&rw_lock);
		printf("enter rw_test1\n");
		sleep(6);
		pthread_rwlock_unlock(&rw_lock);
		sleep(1);
	}
}

static void *rw_test2(void *data)
{
	while (1) {
		pthread_rwlock_wrlock(&rw_lock);
		printf("enter rw_test2\n");
		sleep(6);
		pthread_rwlock_unlock(&rw_lock);
		sleep(1);
	}
}

void *server(void *data)
{
	int i = *(int *)data;

	printf("custor %d coming\n", i);

	if (sem_wait(&sem) == 0) {
		sleep(6);
		printf("custor %d leve\n", i);
		sem_post(&sem);
	}
}

int main(int argc, void *argv[])
{
	pthread_t pthread1;
	pthread_t pthread2;
	pthread_t pthread3;
	pthread_t child[10];
	int i, ret;
	
	bad.front = bad.rear = 0;
	product.front = product.rear = 0;


	pthread_mutex_init(&mutex_lock0, NULL);
	pthread_mutex_init(&mutex_lock1, NULL);

	pthread_rwlock_init(&rw_lock, NULL);

	pthread_cond_init(&cond, NULL);

	sem_init(&sem, 0, 2);

	for (i = 0; i < 10; i++) {
		ret = pthread_create(&child[i], NULL, server, &child_id[i]);
		if (ret) {
			printf("pthread create error\n");
			return -1;
		}
		sleep(1);
	}
	
	for (i = 0; i < 10; i++) {
		pthread_join(child[i], NULL);
	}

//	pthread_create(&pthread2, NULL, func_check, NULL);
//	pthread_create(&pthread1, NULL, func_creat, NULL);
	//pthread_create(&pthread1, NULL, rw_test0, NULL);
	//pthread_create(&pthread2, NULL, rw_test1, NULL);
	//pthread_create(&pthread3, NULL, rw_test2, NULL);

	while (1) {

	}
}
