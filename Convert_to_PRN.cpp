#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Initsize 30
#define Newsize 30

typedef char Ele;

struct Stack{
	Ele* Top;
	Ele* Base;
	int Stacksize;
};
typedef struct Stack* stk;


void init(stk);				//��������
void push(stk p, Ele e);	
Ele pop(stk p);

void init(stk p){			//��ʼ������
	p->Base = (Ele*)malloc(Initsize*sizeof(Ele));
	if (p->Base == NULL){
		printf("�ڴ����ʧ�ܡ�");
		exit(1);
	}
	p->Top = p->Base;
	p->Stacksize = Initsize;
}

void push(stk p, Ele e){	//��ջ
	int len;
	len	= p->Top - p->Base;
	if ( len >= p->Stacksize)
	{	//��̬����ռ�
		p->Base = (Ele*)realloc(p->Base, (p->Stacksize + Newsize)*sizeof(Ele));
		if (p->Base == NULL){
			printf("�ڴ����ʧ�ܡ�");
			exit(1);
		}
		p->Stacksize = p->Stacksize + Newsize;
		p->Top = p->Base + len;
	}
	*(p->Top) = e;
	p->Top++;
}

Ele pop(stk p){		//��ջ
	Ele e;
	if (p->Top == p->Base){
		printf("�Ѿ�����׶�");
		exit(0);
	}
	(p->Top)--;
	e = *(p->Top);
	return e;
}

int main(){
	struct Stack p;		//����ջ
	Ele c,e[3]="0 ";		//c���ڽ��ռ����ַ�
	//����e[]����Ϊʹ��strcat����Ҫ�����������������ַ�������Ҫ��\0��β��������ֱ�Ӽ���һ���ַ�
	Ele str[10],all[200]="";	//str���ڱ�������С��all���ڴ洢�õ��������׺���ʽ��
	int i = 0;					//temp��

	init(&p);					//��ʼ��

	printf("������һ����ʽ��");
	scanf("%c", &c);
	while (c != '#')
	{
		while ((c <= '9' && c >= '0') || c == '.'){		//����һ��С��
			str[i++] = c;
			if (i >= 10){
				printf("�������ݹ���");
				exit(1);
			}
			scanf("%c", &c);
			if (!(c <= '9' && c >= '0') && c != '.'){
				str[i++] = ' ';
				str[i] = '\0';
				strcat(all, str);
				i = 0;
				break;
			}
		}
		if (c == '#')
			break;
		switch (c)								//�������ж�
		{
		case '(':
		case '*':
		case '/':
			//�������������'('��'*'��'/'�����������ȼ��ϸߣ�ֱ�ӽ�����ջ��
			push(&p, c);
			break;
		case '+':
		case '-':
			//�����+�Ż���-�ţ����֮ǰ������'('ѹ��ջ����ȡ������'('֮������в���������ȡ��'('��
			//���֮ǰδ��'('ѹ��ջ����ȡ�����в���������Ϊ��ջ�е����в����������ȼ��������һ��'+'��'-'�ߡ�
			while (p.Base != p.Top){		
				e[0] = pop(&p);
				if (e[0] == '*' || e[0] == '/' || e[0] == '+' || e[0] == '-'){
					strcat(all, e);
				}
				else{
					push(&p, e[0]);
					break;
				}
			}
			push(&p, c);
			break;
		case')':
			//�������������')'����ȡ������'('֮������в�������ͬʱȡ��'('��
			while ((e[0] = pop(&p)) != '('){
				strcat(all, e);
			}
		default:
			break;
		}
		scanf("%c", &c);
	}
	//������뵽��ĩβ���������в�������
	while (p.Base != p.Top){
		e[0] = pop(&p);
		strcat(all, e);
	}
	printf("%s", all);
	return 0;
}