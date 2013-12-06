#include "testUtils.h"
#include "queueLib.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


int areEqual(Queue* src, Queue* expected){
	int res = (src->queueInfo.elementSize == expected->queueInfo.elementSize) 
				&& (src->queueInfo.front == expected->queueInfo.front)
				&& (src->queueInfo.rear == expected->queueInfo.rear)
				&& (src->queueInfo.length == expected->queueInfo.length);
	if(!res)
		return res;
	res = memcmp(src->base,expected->base,src->queueInfo.length*src->queueInfo.elementSize);
	return 0==res;
}

void DebugArray(Queue* st){
	printf("Address = %p",st->base);
	printf("Element Size=%d",st->queueInfo.elementSize);
	printf("Front = %d\n", st->queueInfo.front);
	printf("Rear = %d\n", st->queueInfo.rear);
	printf("Length = %d\n", st->queueInfo.length);
}

void test_to_create_int_Queue(){
	int expArr[2]={0,0};
	Queue expected = {expArr,{2,sizeof(int),-1,-1}};
	Queue* queue=create(sizeof(int), 2);
	ASSERT(areEqual(queue, &expected));
	free(queue->base);
	free(queue);
}

void test_to_create_float_Queue(){
	float expArr[2]={0,0};
	Queue expected = {expArr,{2,sizeof(float),-1,-1}};
	Queue* queue=create(sizeof(float), 2);
	ASSERT(areEqual(queue, &expected));
	free(queue->base);
	free(queue);
}

void test_to_create_char_Queue(){
	char expArr[2]={'\0','\0'};
	Queue expected = {expArr,{2,sizeof(char),-1,-1}};
	Queue* queue=create(sizeof(char), 2);
	ASSERT(areEqual(queue, &expected));
	free(queue->base);
	free(queue);
}

void test_to_create_double_Queue(){
	double expArr[2]={0,0};
	Queue expected = {expArr,{2,sizeof(double),-1,-1}};
	Queue* queue=create(sizeof(double), 2);
	ASSERT(areEqual(queue, &expected));
	free(queue->base);
	free(queue);
}

void test_to_create_string_Queue(){
	String expArr[2]={"Prateek","Kajal"};
	Queue expected = {expArr,{2,sizeof(String),-1,-1}};
	Queue* queue=create(sizeof(String), 2);
	memcpy(queue->base, expected.base, sizeof(String)*2);
	ASSERT(areEqual(queue, &expected));
	free(queue->base);
	free(queue);
}

void test_to_enqueue_an_int_element(){
	int element = 4;
	Queue* queue = create(sizeof(int), 3);
	ASSERT(enQueue(queue, &element));
	free(queue->base);
	free(queue);	
}

void test_to_enqueue_an_float_element(){
	float element = 4;
	Queue* queue = create(sizeof(float), 3);
	ASSERT(enQueue(queue, &element));
	free(queue->base);
	free(queue);	
}

void test_to_enqueue_an_char_element(){
	char element = '4';
	Queue* queue = create(sizeof(char), 3);
	ASSERT(enQueue(queue, &element));
	free(queue->base);
	free(queue);	
}

void test_to_enqueue_an_string_element(){
	String element = "Prateek";
	Queue* queue = create(sizeof(String), 3);
	ASSERT(enQueue(queue, &element));
	free(queue->base);
	free(queue);	
}

void test_to_enqueue_an_double_element(){
	double element = 3.455;
	Queue* queue = create(sizeof(double), 3);
	ASSERT(enQueue(queue, &element));
	free(queue->base);
	free(queue);	
}

void test_to_enqueue_an_int_element_when_queue_is_full(){
	int element = 4;
	Queue* queue = create(sizeof(int), 2);
	enQueue(queue, &element);
	enQueue(queue, &element);
	ASSERT(0==enQueue(queue, &element));
	free(queue->base);
	free(queue);	
}

void test_to_dequeue_an_int_element(){
	int element = 2;
	int element2 = 3;
	void *dequeuedElement;
	Queue* queue = create(sizeof(int), 3);
	enQueue(queue, &element);
	enQueue(queue, &element2);
	dequeuedElement = deQueue(queue); 
	ASSERT(2==*(int*)dequeuedElement);
	ASSERT(3==((int*)queue->base)[0]);
	ASSERT(0==queue->queueInfo.rear);
	free(queue->base);
	free(queue);	
}

void test_to_dequeue_an_float_element(){
	float element = 2.6f;
	float element2 = 3.6f;
	void *dequeuedElement;
	Queue* queue = create(sizeof(float), 3);
	enQueue(queue, &element);
	enQueue(queue, &element2);
	dequeuedElement = deQueue(queue); 
	ASSERT(2.6f==*(float*)dequeuedElement);
	ASSERT(3.6f==((float*)queue->base)[0]);
	ASSERT(0==queue->queueInfo.rear);
	free(queue->base);
	free(queue);	
}

void test_to_dequeue_an_int_element_when_it_is_already_empty(){
	void *dequeuedElement;
	Queue* queue = create(sizeof(int), 3);
	dequeuedElement = deQueue(queue); 
	ASSERT(NULL==dequeuedElement);
	free(queue->base);
	free(queue);	
}