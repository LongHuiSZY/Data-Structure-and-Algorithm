#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"huffman.h"
#include"queue.h"

htTree *buildTree(char *inputString)
{
	int *probility = (int*)malloc(sizeof(int)* 256);	//����256���ռ����ڴ��ÿ��ascii�������

	for (int i = 0; i < 256; i++){
		probility[i] = 0;
	}

	for (int j = 0; inputString[j] != '\0'; j++){
		probility[(unsigned char)inputString[j]]++;		//����char��0~256��ת����ɼ���
	}

	pQueue * huffmanqueue;								//�������
	initpQueue(&huffmanqueue);							//��ʼ������

	for (int k = 0; k < 256; k++){
		if (probility[k] != 0)							//��������ascii�룬���ĳ��ascii���������Ϊ0
		{												//����������С��������
			htNode* aux = (htNode*)malloc(sizeof(htNode));
			aux->left = NULL;							
			aux->right = NULL;
			aux->symbol = (char)k;						
			addpQueue(&huffmanqueue, aux, probility[k]);
		}
	}

	free(probility);									//�����ݴ�����к��ͷ�����

	while (huffmanqueue->size!=1){
		int priority = huffmanqueue->first->priority;	//ȡ��������ǰ����ascii��
		priority += huffmanqueue->first->Next->priority;

		htNode* left = getQueue(&huffmanqueue);
		htNode* right = getQueue(&huffmanqueue);

		htNode* newNode = (htNode*)malloc(sizeof(htNode));	//�����½�㣬���������ֱ�Ϊǰ����ascii��
		newNode->left = left;
		newNode->right = right;
		addpQueue(&huffmanqueue, newNode, priority);		//���½��������
	}
	htTree *tree = (htTree *)malloc(sizeof(htTree));		
	tree->root = getQueue(&huffmanqueue);					//���ڵ�Ϊ���н�ʣ�����һ�����
	return tree;
}

void traverseTree(htNode* node, hlTable** table, int k, char code[256]){
	if (node->left == NULL&&node->right == NULL){		//���Ǹ��ڵ��ʱ��
		code[k] = '\0';									//Ϊĩβ����ֹͣ����
		hlNode *aux = (hlNode*)malloc(sizeof(hlNode));	//����Table���Ŀռ�
		aux->core = (char *)malloc(sizeof(char)*(strlen(code) + 1));	//aux->coreָ����ĳһ����ĸ�ı�����
		strcpy(aux->core, code);										//������������aux->core
		aux->symbol = node->symbol;										//��ascii�����aux->symbol
		aux->next = NULL;
		if ((*table)->first == NULL){									//�����Table�Ŀ�ͷ�����ʼ��
			(*table)->first = aux;
			(*table)->last = aux;
		}
		else{
			(*table)->last->next = aux;									//������ĩβ���
			(*table)->last = aux;
		}
	}
	if (node->left != NULL){											//�������Ϊ���������һ��0
		code[k] = '0';
		traverseTree(node->left, table, k + 1, code);
	}		
	if (node->right != NULL){											//���ұ���Ϊ���������һ��1
		code[k] = '1';
		traverseTree(node->right, table, k + 1, code);
	}

}

hlTable* buildTable(htTree *huffmanTree){
	hlTable* table = (hlTable*)malloc(sizeof(hlTable));		//����hlTable�Ŀռ�
	table->first = NULL;									//first��last��Ϊ��
	table->last = NULL;

	char code[256];											//��ʼ��code
	int k = 0;												//��ʼ��kΪ0
	traverseTree(huffmanTree->root, &table, k, code);		//���ɹ���������
	return table;
}

void encode(hlTable* huffmanTable, char* stringToEncode){
	hlNode *traversal;

	printf("\n\nEncoding����\n\nInput string:\n%s\n\nDecoded string:\n", stringToEncode);
	for (int i = 0; stringToEncode[i] != '\0'; i++){
		traversal = huffmanTable->first;			//�����Table���ҵ���Ӧ��ascii�룬���ӡ��������
		while (traversal->symbol != stringToEncode[i]){
			traversal = traversal->next;
		}
		printf("%s ", traversal->core);
	}
	printf("\n");
}

void decode(htTree* huffmanTree, char* stringToDecode){
	htNode *traversal = huffmanTree->root;
	printf("\n\nDecoding����\n\nInput string:\n%s\n\nDecoded string:\n",stringToDecode);
	for (int i = 0; stringToDecode[i] != '\0'; i++){
		if (traversal->left == NULL&&traversal->right == NULL){		//����ִ�Ҷ�ӽ�㣬���ӡascii��
			printf("%c", traversal->symbol);
			traversal = huffmanTree->root;
		}
		if (stringToDecode[i] == '0')		//�����������Ϊ0����������Ѱ��
			traversal = traversal->left;
		if (stringToDecode[i] == '1')		//�����������Ϊ1����������Ѱ��
			traversal = traversal->right;
		if (stringToDecode[i] != '0'&&stringToDecode[i] != '1'){
			return;
		}
	}
	if (traversal->left == NULL&&traversal->right == NULL){
		printf("%c", traversal->symbol);
		traversal = huffmanTree->root;
	}
	printf("\n");
	
}


