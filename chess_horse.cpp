#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define X 8
#define Y 8

int chess[X][Y];

//�ҵ�����λ��(x��y)λ�õ�ʱ����һ�����ߵ�λ��
int nextxy(int *x, int *y, int count)
{
	switch (count){

	case 0:
		if (*x + 2 < X && *y - 1 >= 0 && !chess[*x + 2][*y - 1]){
			*x += 2;
			*y -= 1;
			return 1;
		}
		return 0;
		break;
	case 1:
		if (*x + 2 < X && *y + 1 < Y && !chess[*x + 2][*y + 1]){
			*x += 2;
			*y += 1;
			return 1;
		}
		return 0;
		break;
	case 2:
		if (*x + 1 < X && *y - 2 >= 0 && !chess[*x + 1][*y - 2]){
			*x += 1;
			*y -= 2;
			return 1;
		}
		return 0;
		break;
	case 3:
		if (*x + 1 < X && *y + 2 < Y && !chess[*x + 1][*y + 2]){
			*x += 1;
			*y += 2;
			return 1;
		}
		return 0;
		break;
	case 4:
		if (*x - 2 >= 0 && *y - 1 >= 0 && !chess[*x - 2][*y - 1]){
			*x -= 2;
			*y -= 1;
			return 1;
		}
		return 0;
		break;
	case 5:
		if (*x - 2 >= 0 && *y + 1 <Y && !chess[*x - 2][*y + 1]){
			*x -= 2;
			*y += 1;
			return 1;
		}
		return 0;
		break;
	case 6:
		if (*x - 1 >= 0 && *y - 2 >= 0 && !chess[*x - 1][*y - 2]){
			*x -= 1;
			*y -= 2;
			return 1;
		}
		return 0;
		break;
	case 7:
		if (*x - 1 >= 0 && *y + 2 < Y && !chess[*x - 1][*y + 2]){
			*x -= 1;
			*y += 2;
			return 1;
		}
		return 0;
		break;
	default :
		return 0;
		break;
	}
}

// ������ȱ���
// (x,y)Ϊλ������
// tag��һ����Ǳ�����ÿ��һ����tag+1
int travel(int x,int y,int tag){
	int x1 = x, y1 = y, flag = 0, count = 0;
	chess[x][y] = tag;

	if (tag == X*Y){ //�������Ѿ�������ʱ��
		// ��ӡ����
		for (int i = 0; i < X; i++){
			for (int j = 0; j < Y; j++){
				printf("%2d ", chess[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		return 1;
	}
	//����8��λ��
	flag = nextxy(&x1, &y1, count);
	while (0 == flag&&count < 7){
		count++;
		flag = nextxy(&x1, &y1, count);
	}

	while (flag){
		if(travel(x1, y1, tag + 1)){
			return 1;
		}
		//������һ���㣬���ԡ�
		x1 = x;
		y1 = y;
		count++;
		flag = nextxy(&x1, &y1, count);
		while (0 == flag && count < 7){
			count++;
			flag = nextxy(&x1, &y1, count);
		}
		//�ҵ������һ���������꣬��flag = 1������Ϊ0��
	}
	if (flag == 0){
		chess[x][y] = 0;
	}
	return 0;
}

void main(){
	clock_t start, finish;
	start = clock();
	for (int i = 0; i < X; i++){
		for (int j = 0; j < Y; j++){
			chess[i][j] = 0;
		}
	}
	if (!travel(2, 0, 1)){
		printf("����ʼ���޷�����ȫ�֡�");
	}
	for (int i = 0; i < X; i++){
		for (int j = 0; j < Y; j++){
			printf("%2d ", chess[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	finish = clock();
	printf("���μ��㹲��%f", double(finish-start)/CLOCKS_PER_SEC);

}