#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *Next;
};
typedef int c;
typedef struct Node* RoL;

RoL getRol(int n){
	RoL s, p;
	RoL tail;			//ָ��β�ڵ㣬�������Ԫ��
	int i = 1;
	p = (RoL)malloc(sizeof(struct Node));
	p->data = i;
	p->Next = p;
	tail = p;
	while (i < n){
		i++;
		s = (RoL)malloc(sizeof(struct Node));
		s->data = i;
		s->Next = tail->Next;
		tail->Next = s;			//����ָ��β�ڵ�
		tail = s;
	}
	return p;					//����ͷָ��
}

int main(void){
	RoL s, p;
	int i = 0;
	p = getRol(41);	//����41λ��ѭ������pָ���ͷ
	while (p->Next != p){
		p = p->Next;	//��һ�֣���ʱpָ��ڶ����ˣ��ڶ��֣���ʱpָ�������ˣ�
		printf("%d->", p->Next->data);

		if (15 == i){		//ÿ15�ֽ������λ��У������������
			printf("\n\n");
			i = 0;
		}

		s = p->Next;	//��һ�֣���ʱsָ��������ˣ��ڶ��֣���ʱsָ��������ˣ�
		p->Next = s->Next;	
		free(s);		//��һ�֣������������أ��ڶ��֣������������أ�
		p = p->Next;	//��һ�֣���ʱpָ����ĸ��ˣ��ڶ��֣���ʱsָ����߸��ˣ�
		i++;
	}
	printf("%d", p->data);
	return 0;

}