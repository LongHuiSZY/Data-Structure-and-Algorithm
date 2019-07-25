#include<stdio.h>

int count = 0;

int noDanger(int row, int col, int (*chess)[8]){
	int i,j,flag1 = 0,flag2 = 0,flag3 = 0,flag4 = 0,flag5=0;
	for (i = 0; i < 8; i++){			//�жϸ����Ƿ��������ʺ�
		if (chess[i][col] != 0){	
			flag1 = 1;
			break;
		}
	}
	for (i = row, j = col; i >= 0 && j >= 0; i--,j--){		//�ж����Ͻ��Ƿ��������ʺ�
		if (chess[i][j] != 0){
			flag2 = 1;
			break;
		}
	}
	for (i = row, j = col; i < 8 && j < 8; i++, j++){		//�ж����½��Ƿ��������ʺ�
		if (chess[i][j] != 0){
			flag3 = 1;
			break;
		}
	}
	for (i = row, j = col; i >= 0 && j < 8; i--, j++){		//�ж����½��Ƿ��������ʺ�
		if (chess[i][j] != 0){
			flag4 = 1;
			break;
		}
	}	
	for (i = row, j = col; i < 8 && j >= 0; i++, j--){		//�ж����Ͻ��Ƿ��������ʺ�
		if (chess[i][j] != 0){
			flag5 = 1;
			break;
		}
	}
	if (flag1 || flag2 || flag3 || flag4 || flag5){			//����������ʺ�������������return 0��
		return 0;
	}
	else{
		return 1;
	}
}

void EightQueen(int row,int chess[][8]){
	int chess2[8][8],i,j;
	for (i = 0; i < 8; i++){		//������chess����ֲ�����chess2���������Բ��ı�ԭchess��ֵ
		for (j = 0; j < 8; j++){
			chess2[i][j] = chess[i][j];
		}
	}
	if (8 == row){					//�������row = 8 �����ڰ��е����̶��Ѿ����ϻʺ��������ж������˻ʺ󡣴�ӡ���̳���
		printf("��%d�֣�\n", ++count);
		for (i = 0; i < 8; i++){
			for (j = 0; j < 8; j++){
				
				printf("%d ", chess2[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	else{
		for (j = 0; j < 8; j++){
			if (noDanger(row, j, chess2))	//�ж��Ƿ���Σ�գ�û��Σ���������һ��
			{
				for (i = 0; i < 8; i++)		//�����ǰ�У���һ��ѭ�����µ�Ӱ�죬��j=0��j=1��Ӱ�졣
					chess2[row][i] = 0;		
				chess2[row][j] = 1;				//��λ�ð�ȫ������һ���ʺ�
				EightQueen(row + 1, chess2);	//��ѯ��һ�����
			}
		}
	}

}

void main(){
	int chess[8][8], i, j;
	for (i = 0; i < 8; i++){
		for (j = 0; j < 8; j++){
			chess[i][j] = 0;				//�������̳�ֵ��ȫ��0��
		}
	}
	EightQueen(0,chess);
}