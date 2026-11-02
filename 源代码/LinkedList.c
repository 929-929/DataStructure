//用C / C++语言编程实现建立一个单链表，并实现下列功能（每个功能独立成函数）。

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 定义元素类型为整型

// 定义线性表的链式存储结构
typedef struct LNode {
	ElemType data; //数据域
	struct LNode *next; //指针域
} LNode, *LinkList;

//1.初始化一个带有头节点的单链表。
LinkList InitList() {
	LinkList head = (LNode*)malloc(sizeof(LNode)); //申请头节点
	if (!head) return NULL; //申请失败
	head->next = NULL; //头节点的指针域置为空
	return head; //返回头节点
}


//2.采用头插法建立单链表。
LinkList CreateListHead(LinkList head) {
	int n, i;
	printf("请输入要插入的元素个数: ");
	scanf_s("%d", &n);
	
	for (i = 0; i < n; i++) {
		LinkList newNode = (LNode*)malloc(sizeof(LNode)); //申请新节点
		if (!newNode) return NULL; //申请失败
		printf("请输入第%d个元素: ", i + 1);
		scanf_s("%d", &newNode->data); //输入数据
		newNode->next = head->next; //新节点指向原来的第一个节点
		head->next = newNode; //头节点指向新节点
	}

	return head; //返回头节点
}

//3.采用尾插法建立单链表。
LinkList CreateListRear(LinkList head) {
	int n, i;
	printf("请输入要插入的元素个数: ");
	scanf_s("%d", &n);

	LNode *q = head; //用q表示当前表尾的节点，初始值为头节点

	for (i = 0; i <= n - 1; i++) {
		LinkList newNode = (LNode*)malloc(sizeof(LNode)); //申请新节点
		if (!newNode) return NULL; //申请失败
		printf("请输入第%d个元素: ", i + 1);
		scanf_s("%d", &newNode->data); //输入数据

		newNode->next = NULL; //newNode将插入表尾，所以指针域为空
		q->next = newNode; // 将newNode插入表尾
		q = newNode; //当前表尾的节点变为newNode
	}

	return head;
}

//4.判断链表是否为空。
int ListEmpty(LinkList head)
{
	return (head->next == NULL) ? 1 : 0;
}

//5.计算链表的长度。
int Length_LinkList(LinkList head) { //形参为头节点
	LNode* p = head;
	int length = 0;
	while (p->next) {
		p = p->next;
		length++;
	}
	return length;
}
//6.输出链表的内容。
void Print_LinkList(LinkList L) {
	LNode* p;
	p = L->next;
	printf("该链表内容为：");
	while (p) {
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {
	//1.初始化一个带有头节点的单链表。
	LinkList L = InitList();

	//2.采用头插法建立单链表。
	printf("采用头插法建立单链表----------\n");
	CreateListHead(L);

	//4.判断链表是否为空。
	if (ListEmpty(L)) {
		printf("链表为空\n");
	}
	else {
		printf("链表不为空\n");
	}

	//5.计算链表的长度。
	int len = Length_LinkList(L);
	printf("链表的长度为: %d\n", len);

	//6.输出链表的内容。
	Print_LinkList(L);

	printf("\n");

	//3.采用尾插法建立单链表。
	printf("采用尾插法建立单链表---------\n");
	CreateListRear(L);

	//4.判断链表是否为空。
	if (ListEmpty(L)) {
		printf("链表为空\n");
	}
	else {
		printf("链表不为空\n");
	}

	//5.计算链表的长度。
	len = Length_LinkList(L);
	printf("链表的长度为: %d\n", len);

	//6.输出链表的内容。
	Print_LinkList(L);
}