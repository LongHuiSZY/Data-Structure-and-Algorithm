#include <stdio.h>
#include <stdlib.h>
#define Maxsize 10
typedef double Ele;

struct stack
{
	Ele* top;
	Ele* bottom;
	int stacksize;
};

typedef struct stack* Stack;

void init(Stack s){
	Ele *p;
	p = (Ele*)malloc(Maxsize * sizeof(Ele));
	if (p == NULL){
		printf("error");
		exit(1);
	}
	s->top = s->bottom = p;
	s->stacksize = Maxsize;
}

void PUSH(Stack s, Ele data){
	int length;
	length = s->top - s->bottom;
	if (length >= s->stacksize){
		s->bottom = (Ele*)realloc(s->bottom,(s->stacksize + Maxsize) * sizeof(Ele));
		if (s->bottom == NULL){
			printf("�ڴ����ʧ��\n");
			exit(1);
		}
	}
	*(s->top) = data;
	s->top++;
}
Ele POP(Stack s){
	Ele num;
	if (s->top == s->bottom){
		printf("ջ��û��Ԫ���ˣ�\n");
		exit(1);
	}
	s->top--;
	num = *(s->top);
	return num;
}

int main(){
	struct stack s;			//����ջ
	char c = 0,str[10];		//c���ڴӼ��̻�ȡ�ַ���str���ڴ洢ÿһ����������֣�֮���ת����double����
	Ele a1, a2, num;		//a1��a2����ջ������
	int i = 0;				//temp��


	init(&s);				//��ʼ��ջ
	printf("������һ����ʽ��");		

	scanf("%c", &c);		//����һ���ַ�
	while (c != '#')
	{
		while ((c <= '9' && c >= '1') || c == '.'){	//�ò������ڻ�ȡһ��double���͵�����
			str[i++] = c;
			str[i] = '\0';
			if (i >= 10){
				printf("�������ݹ���");
				exit(1);
			}
			scanf("%c", &c);
			if (!(c <= '9' && c >= '1') && !(c == '.')){
				a1 = atof(str);						//�ú������ڽ��ַ���ת��λdouble
				PUSH(&s, a1);
				i = 0;
				break;
			}
		}
		switch (c)								//�ж��Ƿ����ڼӼ��˳�
		{
		case '+': 
			a1 = POP(&s);
			a2 = POP(&s); 
			PUSH(&s, a2 + a1);
			break;
		case '-': 
			a1 = POP(&s);
			a2 = POP(&s); 
			PUSH(&s, a2 - a1);
			break;
		case '*': 
			a1 = POP(&s);
			a2 = POP(&s); 
			PUSH(&s, a2 * a1);
			break;
		case '/': 
			a1 = POP(&s);
			a2 = POP(&s); 
			PUSH(&s, a2 / a1);
			break;
		case ' ':
			break;
		case '#':
			break;
		default:
			printf("������Ŵ���\n");
			break;
		}
		scanf("%c", &c);
	}
	num = POP(&s);
	printf("%.3f\n", num);

	return 0;
}