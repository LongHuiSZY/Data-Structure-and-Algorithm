#include <stdio.h>
#include <stdlib.h>

struct Node{ //����ṹ��
	int data;
	struct Node* Next;
};

typedef struct Node* Linked_List;	//���ṹ��ָ�붨������������Linked_List
//���ʹ��һ��*������ǽṹ���ָ�룬����Ըı��ڲ�Ԫ��,data,Next


void getNode(Linked_List p){		//���ڻ��Node��dataֵ����addNode����
	printf("���������֣�");
	scanf("%d", &p->data);
}

void addNode(Linked_List* library, Linked_List* tail){		//β�巨����
	Linked_List p;

	p = (Linked_List)malloc(sizeof(struct Node));
	if (p == NULL)
	{
		printf("error");
		exit(1);
	}

	getNode(p);

	if (*library == NULL){	//���ͷ���Ϊ�գ���ͷ���ָ��Ķ�Ӧ�ĵ�ַ��Ϊp�����Ҫ�õ�ָ���ָ�롣
		p->Next = NULL;
		*library = p;
		*tail = *library;	//��ʱβ�ڵ����ͷ���

	}
	else{
		p->Next = NULL;
		(*tail)->Next = p;
		*tail = p;			//β�ڵ����
	}

}

void scanLibrary(Linked_List library){		//������������
	int i = 0;
	Linked_List p;

	p = (Linked_List)malloc(sizeof(struct Node));
	p = library;

	while (p != NULL){
		printf("����%d��%d\n", i, p->data);
		p = p->Next;
	}
}

void release(Linked_List library){
	Linked_List temp = library->Next;
	while (library != NULL){
		free(temp);
		library = library->Next;
	}
	free(library);
}

void getElem(Linked_List library, int num, int* e){
	int i = 0;
	while (i < num - 1){
		library = library->Next;
		if (library == NULL){
			printf("��������������Χ��\n");
			exit(1);
		}
		i++;
	}
	*e = library->data;
}

void addElem(Linked_List* library, int num, int* e){ //���ض�λ�ò���Ԫ��
	int i = 0;
	Linked_List p, s;
	p = (Linked_List)malloc(sizeof(struct Node));
	if (p == NULL)
	{
		printf("�ڴ����ERROR");
		exit(1);
	}
	p->data = *e;
	if (num == 1){					//����ڵ�һ���ڵ����
		p->Next = *library;
		*library = p;
	}
	else{
		s = *library;
		while (i < num - 2){		//�ҵ��ض�λ��
			s = s->Next;
			i++;
		}
		p->Next = s->Next;
		s->Next = p;
	}
}

void delElem(Linked_List* library, int num, int* e){	//ɾ���ض�λ�ýڵ�
	int i = 0;
	Linked_List p, s;
	if (*library == NULL){
		printf("����һ���ձ�\n");
		exit(1);
	}
	if (num == 1){
		p = *library;
		*library = (*library)->Next;
		free(p);
	}
	else{
		s = *library;
		while (i < num - 2){
			s = s->Next;
			i++;

		}
		p = s->Next;
		*e = p->data;
		s->Next = p->Next;
	}
	free(p);
}

void main()
{
	Linked_List head = NULL, tail = NULL;
	int e, num;

	printf("������Ҫ���뼸�����֣�");
	scanf("%d", &num);
	for (int i = 0; i<num; i++){
		addNode(&head, &tail);
	}

	printf("����������Ҫȡ�õڼ�������");
	scanf("%d", &num);
	getElem(head, num, &e);
	printf("��ȡ�õ�����%d\n", e);

	printf("����������Ҫ���������");
	scanf("%d", &e);

	printf("����������Ҫ�����λ�ã�");
	scanf("%d", &num);
	addElem(&head, num, &e);
	scanLibrary(head);

	printf("����������Ҫɾ����λ�ã�");
	scanf("%d", &num);
	delElem(&head, num, &e);
	printf("��ɾ��������%d\n", e);
	scanLibrary(head);
}