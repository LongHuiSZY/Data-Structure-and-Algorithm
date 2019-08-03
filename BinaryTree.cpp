#include <stdio.h>
#include <stdlib.h>

typedef char Ele;

struct Node{
	Ele data;		//data���ڴ洢��Ϣ
	struct Node* LeftChild;
	struct Node* RightChild;
};

typedef struct Node Node, *Tree;

void init(Tree* t){	//��������ַ�Ϊ�ո��ʱ�򣬴���Ҷ�ӽ��
					//�����������ַ�����ǰ����dataֵ
					//����˳��Ϊ��ǰ��㡢���㡢�ҽ�㡣
	Ele c;
	scanf("%c", &c);
	if (' '== c){
		*t = NULL;
	}
	else{
		*t = (Tree)malloc(sizeof(Node));
		if (*t == NULL){
			printf("�ڴ����ʧ��");
			exit(1);
		}
		(*t)->data = c;
		init(&(*t)->LeftChild);		//��������
		init(&(*t)->RightChild);	//�����ҽ��
	}
}


void visit(Tree t, int level){
	printf("%cλ�ڵ�%d��\n", t->data, level);
}

void scan(Tree t,int level){
	if (t != NULL){
		scan(t->LeftChild, level + 1);
		scan(t->RightChild, level + 1);
		visit(t, level);
	}
}

int main(){
	Tree BiTree = NULL;
	init(&BiTree);
	scan(BiTree,1);
	return 0;
}


