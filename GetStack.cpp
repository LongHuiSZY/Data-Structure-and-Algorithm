#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define maxsize 100 //���sizeΪ100
typedef char EleType; //����ط�Ҫ��typedef����������define
struct stack{		//stacksize�����͡�
	int stacksize;  //ָ�������ջ�����size
	EleType* top;	//topָ��ָ�������һλ���ݵĺ�һ��
	EleType* base;  //baseָ��ָ�������λ��ָ�롣
};

void init(struct stack* STA){
	STA->base = (EleType *)malloc(maxsize * sizeof(EleType));	//Ϊbase�����ڴ�ռ䡣
	if (!STA->base){											//���û�������ϣ����Ƴ�
		exit(1);
	}
	STA->stacksize = maxsize;	//����stacksize�Ĵ�С��
	STA->top = STA->base;		//��ʼ����ʱ�򶥶�ָ��β��
}

void insert(struct stack* STA, EleType e){	//��������
	int len;
	EleType* m;
	len = STA->top - STA->base;				//�������峤��
	if (len >= STA->stacksize){ //���

		m = (EleType *)realloc(STA->base, (STA->stacksize + maxsize)*sizeof(EleType));
		if (!m){
			exit(1);
		}
		STA->stacksize = STA->stacksize + maxsize;//����stacksize��ֵ
		STA->base = m; //����base��ֵ
		STA->top = m + len; //����top��ֵ
	}
	*(STA->top) = e; //STA->top��ֵ���£����º�top++
	(STA->top)++;
}

EleType pop(struct stack* STA){
	char c;
	if (STA->top == STA->base){
		exit(1);	//�Ƿ����ʣ��쳣�˳�
	}
	STA->top--;		//Ӧ���Ƚ�top--���ٽ���ȡֵ
	c = *(STA->top);	//topΪָ��
	return c;

}

int main(void){

	struct stack STA, STA_8; //����ط�����ֱ�Ӷ���ָ�룬ָ��ҪҪָ��
	EleType a;

	init(&STA); //ʹ�õ�ַ
	init(&STA_8);

	printf("������һ���ַ�����");
	scanf("%c", &a); //��Ҫʹ���ַ�����Ч�����á�
	while (a != '#'){
		insert(&STA, a);
		scanf("%c", &a);
	}
	while (STA.top != STA.base){
		a = pop(&STA);
		printf("%c", a);
	}
	printf("\n");
	return 0;
}