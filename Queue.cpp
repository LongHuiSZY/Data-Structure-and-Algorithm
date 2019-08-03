#include <stdio.h>
#include <stdlib.h>

typedef int Ele;

struct Node{
	Ele data;
	struct Node* Next;		//data���ڴ洢��Ϣ��Next���ڴ洢��һ��������һ��Ԫ�صĵ�ַ��
};

typedef struct Node* LinkedList;

struct Queue{
	LinkedList head;
	LinkedList tail;		//headΪ��ͷ��tailΪ��β��
};

typedef struct Queue QueueList;

void init(QueueList* q){
	q->head = q->tail = (LinkedList)malloc(sizeof(struct Node));
	if (q->head == NULL){
		printf("�ڴ�ռ����ʧ��");
		exit(1);
	}
	q->head->Next = NULL;
}

void push(QueueList* q,Ele e){
	LinkedList p;
	p = (LinkedList)malloc(sizeof(struct Node));
	if (p == NULL){
		printf("�ڴ�ռ����ʧ��");
		exit(1);
	}
	p->Next = NULL;
	p->data = e;

	q->tail->Next = p;	//��Ԫ��ѹ����С�����βָ��ָ���½ڵ�
	q->tail = p;
}

void pop(QueueList* q, Ele* e){
	LinkedList p;
	if (q->head == q->tail){
		printf("�����ѿ�");
		exit(1);
	}
	p = q->head->Next;
	q->head->Next = p->Next;	//����pȡ����ͷ
	*e = p->data;				//��Ϣ����Ԫ��e
	if (q->tail == p){
		q->tail = q->head;		//�ж��Ƿ�ȡ������Ԫ�أ����ȡ������Ԫ�أ���ͷָ���β
	}
	free(p);					//�ͷ��м�ڵ�
}

void release(QueueList* q){
	LinkedList p;
	p = q->head;
	while (p){
		q->head = q->head->Next;
		free(p);
		
		p = q->head;
	}
}

int main(){
	QueueList q;
	int num,i;
	Ele e;
	init(&q);
	printf("��������Ҫ���뼸�����֣�");
	scanf("%d", &num);
	for (i = 0; i < num; i++){
		scanf("%d", &e);
		push(&q, e);
	}
	for (i = 0; i < num; i++){
		pop(&q, &e);
		printf("%d\n", e);
	}



	return 0;
}