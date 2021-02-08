#include<stdio.h>
#include<stdlib.h>
//string.h는 필요없기때문에 삭제

typedef struct ListNode{
	//단순연결리스트의노드구조 정의 
	int data;
	struct ListNode* link;
} listNode;

typedef struct{
	//리스트의헤드노드의구조정의 
	listNode* head;
} linkedList_h;


linkedList_h* createLinkedList_h(void){
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL; //공백리스트이므로NULL 설정 
	return L;
}

void addLastNode(linkedList_h*L, int x) //정수형으로 하기위해 char *x였던것을 변경
{
	listNode*newNode;
	listNode*temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x; //strcpy함수는 문자형 변수에 적용되기때문에 지우고 newNode의 데이터에 x를 대입

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
{//리스트 출력하는 함수에 2번문제인 모든데이터를 더하는것을 추가
	int sum = 0; //덧셈변수 sum
	listNode* p;
	printf("L = (");
	p = L->head;//p를 맨 head로 지정한다.
	while (p != NULL)
	{//p를 계속 뒤로 옮기기 때문에 p가 NULL이라면 맨마지막이다.
		printf("%d", p->data);
		sum += p->data;
		p = p->link;
		
		if (p != NULL)
			printf(", ");
	}
	printf(") \n");
	printf("모든 데이터의 합은 %d 입니다.\n", sum);//데이터의 합을 출력한다.

}

void serchNode(linkedList_h*L, int x)// 정수형 int로 변경
{
	int count = 0; //중복을 확인하기위한 변수 count
	listNode*temp;//temp를 사용한 이유는 L을 사용하게되면 맨처음값이 사라지기 때문.
	temp = L->head;
	while (temp != NULL)
	{
		if (temp->data == x)
		{
			printf("\n 탐색성공 %d.", x);
			count++;
		}
			temp = temp->link;				
	}	
	printf(" \n 탐색실패! %d. ", x); //
	printf("\n %d는 %d개가 리스트에 존재합니다.\n", x, count);
}

void deleteLastNode(linkedList_h * L){ // 리스트의 마지막 노드 삭제 연산
	listNode *p; // 이 함수에 printlist함수를 추가하기 위함.
	listNode* previous;
	listNode* current;
	if (L->head == NULL) return; // 공백 리스트인 경우, 삭제 연산 중단
	if (L->head->link == NULL) { // 리스트에 노드가 한 개만 있는 경우
		free(L->head); // 첫 번째 노드의 메모리를 해제
		L->head = NULL; // 리스트 시작 포인터를 null로 설정
		return;
	}
	else { // 리스트에 노드가 여러 개 있는 경우
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
	printf("L = (");//printList함수를 추가.
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
	//1.리스트에 12개의 정수데이터를 삽입,일부가 중복되도록 한다.

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
	
	printList(L);//1번의 연결리스트를 출력.
				// 2번인 모든 데이터값을 더하는것도 같은 함수가 수행

	//3번 serchNode함수를 이용하여 중복된 노드의 갯수를 구한다.
	serchNode(L, 1);
	serchNode(L, 2);
	serchNode(L, 3);
	serchNode(L, 4);
	serchNode(L, 5);
	printf("\n ");
	//4번 deleteLastNode함수를 이용하여 마지막 두개의 노드를 삭제하고 출력한다.
	deleteLastNode(L);
	deleteLastNode(L);
	getchar();
}