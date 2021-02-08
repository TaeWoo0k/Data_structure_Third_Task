#include<stdio.h>
#include<stdlib.h>
//string.h�� �ʿ���⶧���� ����

typedef struct ListNode{
	//�ܼ����Ḯ��Ʈ�ǳ�屸�� ���� 
	int data;
	struct ListNode* link;
} listNode;

typedef struct{
	//����Ʈ��������Ǳ������� 
	listNode* head;
} linkedList_h;


linkedList_h* createLinkedList_h(void){
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL; //���鸮��Ʈ�̹Ƿ�NULL ���� 
	return L;
}

void addLastNode(linkedList_h*L, int x) //���������� �ϱ����� char *x�������� ����
{
	listNode*newNode;
	listNode*temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x; //strcpy�Լ��� ������ ������ ����Ǳ⶧���� ����� newNode�� �����Ϳ� x�� ����

	newNode->link = NULL;

	if (L->head == NULL)
	{
		L->head = newNode;
		return;
	}

	temp = L->head;
	while (temp->link != NULL)

	temp = temp->link;
	temp->link = newNode;
}

void printList(linkedList_h* L)
{//����Ʈ ����ϴ� �Լ��� 2�������� ��絥���͸� ���ϴ°��� �߰�
	int sum = 0; //�������� sum
	listNode* p;
	printf("L = (");
	p = L->head;//p�� �� head�� �����Ѵ�.
	while (p != NULL)
	{//p�� ��� �ڷ� �ű�� ������ p�� NULL�̶�� �Ǹ������̴�.
		printf("%d", p->data);
		sum += p->data;
		p = p->link;
		
		if (p != NULL)
			printf(", ");
	}
	printf(") \n");
	printf("��� �������� ���� %d �Դϴ�.\n", sum);//�������� ���� ����Ѵ�.

}

void serchNode(linkedList_h*L, int x)// ������ int�� ����
{
	int count = 0; //�ߺ��� Ȯ���ϱ����� ���� count
	listNode*temp;//temp�� ����� ������ L�� ����ϰԵǸ� ��ó������ ������� ����.
	temp = L->head;
	while (temp != NULL)
	{
		if (temp->data == x)
		{
			printf("\n Ž������ %d.", x);
			count++;
		}
			temp = temp->link;				
	}	
	printf(" \n Ž������! %d. ", x); //
	printf("\n %d�� %d���� ����Ʈ�� �����մϴ�.\n", x, count);
}

void deleteLastNode(linkedList_h * L){ // ����Ʈ�� ������ ��� ���� ����
	listNode *p; // �� �Լ��� printlist�Լ��� �߰��ϱ� ����.
	listNode* previous;
	listNode* current;
	if (L->head == NULL) return; // ���� ����Ʈ�� ���, ���� ���� �ߴ�
	if (L->head->link == NULL) { // ����Ʈ�� ��尡 �� ���� �ִ� ���
		free(L->head); // ù ��° ����� �޸𸮸� ����
		L->head = NULL; // ����Ʈ ���� �����͸� null�� ����
		return;
	}
	else { // ����Ʈ�� ��尡 ���� �� �ִ� ���
		previous = L->head;
		current = L->head->link;
		while (current->link != NULL)
		{
			previous = current;
			current = current->link;
		}
		free(current);
		previous->link = NULL;
	}
	printf("L = (");//printList�Լ��� �߰�.
	p = L->head;
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->link;

		if (p != NULL)
			printf(", ");
	}
	printf(") \n");
}
int main()
{
	linkedList_h* L;
	L = createLinkedList_h();
	//1.����Ʈ�� 12���� ���������͸� ����,�Ϻΰ� �ߺ��ǵ��� �Ѵ�.

	addLastNode(L, 1);
	addLastNode(L, 2);
	addLastNode(L, 2);
	addLastNode(L, 3);
	addLastNode(L, 3);
	addLastNode(L, 3);
	addLastNode(L, 3);
	addLastNode(L, 4);
	addLastNode(L, 4);
	addLastNode(L, 4);
	addLastNode(L, 5);
	addLastNode(L, 5);
	
	printList(L);//1���� ���Ḯ��Ʈ�� ���.
				// 2���� ��� �����Ͱ��� ���ϴ°͵� ���� �Լ��� ����

	//3�� serchNode�Լ��� �̿��Ͽ� �ߺ��� ����� ������ ���Ѵ�.
	serchNode(L, 1);
	serchNode(L, 2);
	serchNode(L, 3);
	serchNode(L, 4);
	serchNode(L, 5);
	printf("\n ");
	//4�� deleteLastNode�Լ��� �̿��Ͽ� ������ �ΰ��� ��带 �����ϰ� ����Ѵ�.
	deleteLastNode(L);
	deleteLastNode(L);
	getchar();
}