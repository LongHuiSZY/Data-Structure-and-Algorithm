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

void addNode(Linked_List* library, Linked_List* tail){
	Linked_List p;

	p = (Linked_List)malloc(sizeof(Linked_List));
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

void scanLibrary(Linked_List library){
	int i = 0;
	Linked_List p;

	p = (Linked_List)malloc(sizeof(Linked_List));
	p = library;

	while (p != NULL){
		printf("����%d��%d\n", i, p->data);
		p = p->Next;
		i++;
	}
	free(p);
}

void release(Linked_List library){
	Linked_List temp = library->Next;
	while (library != NULL){
		free(temp);
		library = library->Next;
	}
	free(library);
}

void main()
{
	Linked_List head = NULL,tail = NULL;
	int num;
	printf("����Ҫ���뼸�����֣�");
	scanf("%d", &num);
	for (int i = 0; i<num; i++){
		addNode(&head,&tail);
	}
	scanLibrary(head);
}