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

char pop(struct stack* STA){
	char c;
	if (STA->top == STA->base){
		exit(1);	//�Ƿ����ʣ��쳣�˳�
	}
	STA->top--;		//Ӧ���Ƚ�top--���ٽ���ȡֵ
	c = *STA->top;	//topΪָ��
	return c;

}

void count(struct stack* STA, struct stack* STA_8){
	int len,signal=0;
	int num = 0;
	char c;
	len = STA->top - STA->base;

	for (int i = 0; i < len; i++){
		c = pop(STA);	//ȡ��STA�ڵ�ֵ
		if (c == '1')	//��c=='1'��ʱ�����num
		{
			num = num + (int)pow(2.0, i%3);
		}
		else if (c == '0'){	//��c=='0'��ʱ��num����
			num = num;
		}
		else				//��������������������˳�
		{
			printf("���������������\n");
			return;
		}
		signal++;
		if (signal == 3 || i == len-1){ //���ź���Ϊ3���ߵ����β��ʱ�򣬼�¼��ʱ��numֵ��ѹջ����ʼ��signal��num
			signal = 0;
			insert(STA_8, (char)(num + 48));
			num = 0;
		}
	}

}

void getanswer(struct stack* STA_8){
	char c;
	while (STA_8->top != STA_8->base){	//�ж�ʱ��ջ����ջ�ף�����Ļ����˳�ѭ��
		STA_8->top--;
		c = *STA_8->top;
		printf("%c", c);
	}
	printf("\n", c);
}


int main(void){

	struct stack STA,STA_8; //����ط�����ֱ�Ӷ���ָ�룬ָ��ҪҪָ��
	EleType a;
	
	init(&STA); //ʹ�õ�ַ
	init(&STA_8);

	printf("������һ�ζ���������");
	scanf("%c", &a); //��Ҫʹ���ַ�����Ч�����á�
	while (a != '#'){
		insert(&STA, a);
		scanf("%c", &a);
	}

	count(&STA,&STA_8);
	getanswer(&STA_8);
	return 0;
}