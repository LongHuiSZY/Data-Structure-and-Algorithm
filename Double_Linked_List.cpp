#include <stdio.h>
#include <stdlib.h>

struct Node{
	char c;
	struct Node* Next;
	struct Node* Before;
};

typedef struct Node* List;

//��������
List createList();
void ScanList(List list);
void mission(int num, List list);

int main(void){
	List ok;
	int num;
	ok = createList();
	printf("������һ�����֣�");
	scanf("%d", &num);
	mission(num, ok);
}

List createList(){
	List s, p;
	List Head;
	char c = 'A';
	
	int i;
	Head= (List)malloc(sizeof(struct Node));
	s = Head;				//ͷ���ڵ��ʼ��
	s->c = c;
	s->Next = s;		
	s->Before = s;
	for (i = 1; i < 26; i++){	
		c = c + 1;
		p = (List)malloc(sizeof(struct Node));
		s->Next = p;		//�˴�һ����������List�ڵ㣬headʼ��ָ��ͷ��
		p->Before = s;		//p�ڵ�����ʱ�ڵ㣬����ÿһ�β����½ڵ㡣
		Head->Before = p;	//s�ڵ�ÿ�ζ�����s=s->Next���£�ʼ��ָ��β�ڵ㡣
		p->Next = Head;
		s = s->Next;
		p->c = c;
	}
	return Head;
}

void ScanList(List list){
	List s = list;
	printf("%c ", s->c);	//��ͷ��β��������
	s = s->Next;
	while (s != list){
		printf("%c ", s->c);
		s = s->Next;
	}
}

void mission(int num, List list){
	List s = list;
	if (num > 0)
	{
		for (int i = 0; i < num; i++){	//num�������������
			s = s->Next;
		}
	}
	else{
		for (int i = 0; i < -num; i++){	//num�������������
			s = s->Before;
		}
	}
	ScanList(s);
}