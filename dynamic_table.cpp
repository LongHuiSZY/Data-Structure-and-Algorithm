#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MaxSize 10
typedef int Ele;

typedef struct
{
	Ele *data;
	int length;
	int listSize;
}sqList;


void init(sqList *L)	//��ʼ��һ��˳���length����ǰ˳����ȣ�listSize��ʾ��󳤶�
{
	L->data = (Ele *)malloc(MaxSize * sizeof(Ele));

	if (!L->data){
		printf("�ڴ����ʧ��\n");
		exit(0);
	}
	L->length = 0;
	L->listSize = MaxSize;
}

void Insertdata(sqList *L, int i, Ele x) //��˳����в���Ԫ�أ�i�������Ԫ�ص�λ�ã�x����������Ԫ��ֵ��
{
	Ele *base;

	int p, insertPtr;

	if (i<1 || i>L->length + 1)
	{
		printf("����λ�ô���\n");
		exit(0);
	}

	if (L->length >= L->listSize)	//˳����Ȳ��㣬����realloc()�������·���ռ�
	{
		base = (Ele *)realloc(L->data, (L->listSize + MaxSize)*sizeof(Ele));
		L->data = base;
		L->listSize = L->listSize + MaxSize;
	}

	insertPtr = i - 1;						//�ҵ�ָ������

	for (p = L->length - 1; p >= i - 1; p--)	//λ��i��������������ƶ�һ��
	{
		L->data[p] = L->data[p - 1];
	}
	L->data[insertPtr] = x;					//ָ��λ��						
	L->length++;							//����1
}



void Deldata(sqList *L, int i)// ��˳�����ɾ��Ԫ�أ�i����Ҫɾ����Ԫ��λ��
{
	int delItem;

	if (i<1 || i>L->length)
		exit(0);

	for (delItem = i - 1; delItem < L->length-1; ++delItem)	// ÿ��������ǰ��һ��
	{
		L->data[delItem] = L->data[delItem+1];
	}

	L->length--;
}

int main()
{
	sqList l;
	int i,num;
	Ele e;

	init(&l);
	printf("��ǰ������ݸ����ǣ�%d,��������ǣ�%d\n", l.length, l.listSize);
	printf("��˳������11��Ԫ��\n");
	for (i = 0; i < 11; i++)
	{
		scanf("%d", &e);
		Insertdata(&l, i + 1, e);
	}
	printf("\n\n");
	printf("��ɲ���󣬱��е������ǣ�");
	for (i = 0; i < l.length; i++)
	{
		printf("%d ", l.data[i]);
	}
	printf("\n\n");
	printf("��ָ��Ҫɾ����Ԫ�ص�λ��\n");
	scanf("%d", &num);
	Deldata(&l, num);

	printf("���ɾ���󣬱��е������ǣ�");
	for (i = 0; i < l.length; i++)
	{
		printf("%d ", l.data[i]);
	}
	printf("\n\n");
	printf("��ǰ������ݸ����ǣ�%d,��������ǣ�%d\n", l.length, l.listSize);

	return 0;
}
