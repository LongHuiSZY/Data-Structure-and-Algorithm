#include <stdio.h>
#include <stdlib.h>

typedef char Ele;

//Link����0����ʾ��ʱָ�����Һ���
//Thread����1����ʾ��ʱָ��ǰ����̵�ָ��
typedef enum {Link,Thread} PointerTag;

struct Node{
	Ele data;		//data���ڴ洢��Ϣ
	struct Node* LeftChild;
	struct Node* RightChild;
	PointerTag ltag;
	PointerTag rtag;
};

typedef struct Node Node, *Tree;

Tree pre;

void init(Tree* t){	//��������ַ�Ϊ�ո��ʱ�򣬴���Ҷ�ӽ��
	//�����������ַ�����ǰ����dataֵ
	//����˳��Ϊ��ǰ��㡢���㡢�ҽ�㡣
	Ele c;
	scanf("%c", &c);
	if (' ' == c){
		*t = NULL;
	}
	else{
		*t = (Tree)malloc(sizeof(Node));
		if (*t == NULL){
			printf("�ڴ����ʧ��");
			exit(1);
		}
		(*t)->data = c;
		(*t)->ltag = Link;
		(*t)->rtag = Link;
		init(&(*t)->LeftChild);		//��������
		init(&(*t)->RightChild);	//�����ҽ��
	}
}

void Threading(Tree t){
	if (t != NULL){
		Threading(t->LeftChild);
		if (!t->LeftChild){			//���û�����ӣ�������ָ����һ�����ʵĽ��
			t->ltag = Thread;
			t->LeftChild = pre;
		}
		if (!pre->RightChild){			//���û�����ӣ�������ָ����һ�����ʵĽ��
			pre->rtag = Thread;
			pre->RightChild = t;
		}
		pre = t;

		Threading(t->RightChild);
	}
}

void InitThreading(Tree *p, Tree T){
	*p = (Tree)malloc(sizeof(Node));
	(*p)->ltag = Link;
	(*p)->rtag = Thread;		
	(*p)->RightChild = *p;		//p���������ָ������
	if (!T){
		(*p)->LeftChild = *p;	//����Ϊ��ʱ��p��������������ָ������
	}
	else{
		(*p)->LeftChild = T;	//p���������ָ����ڵ�
		pre = *p;				//����������preָ��p
		Threading(T);
		pre->RightChild = *p;
		pre->rtag = Thread;		//ʹ������������һ������������ָ����p
		(*p)->RightChild = pre;		//ʹ�ý��p��������ָ������������һ����㡣

	}  
}
void visit(Ele e){
	printf("%c", e);
}

void scan(Tree p){
	Tree temp;
	temp = p->LeftChild;		//ȡ�ø��ڵ�
	while (temp != p){
		while (temp->ltag == Link){		//ȡ�����������������ĵ�һ�����
			temp = temp->LeftChild;
		}
		visit(temp->data);
		while (temp->rtag == Thread && temp->RightChild != p){
			temp = temp->RightChild;

			visit(temp->data);
		}
		temp = temp->RightChild;
	}
}
int main(){
	Tree p,BiTree = NULL;
	init(&BiTree);
	InitThreading(&p,BiTree);
	printf("��������Ľ��Ϊ��");
	scan(p);
	printf("\n");
	return 0;
}


