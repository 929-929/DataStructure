//	用C / C++语言编程实现一个顺序栈，并实现下列功能（要求每个功能独立成函数）：
//	1)初始化一个空的顺序栈
//	2)判断顺序栈是否为空
//	3)判断顺序栈是否满
//	4)入栈
//	5)出栈
//	6)获取栈顶元素值 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
struct Stack {
	int top; // 栈顶指针，指向栈顶元素的下标
	int maxsize; // 顺序栈的最大空间
	DataType* elements; // 存放顺序栈的栈元素
};

//	1)初始化一个空的顺序栈
int initStack(struct Stack* s, int maxsize) {
	s->top = -1; // 初始化栈顶指针为-1，表示栈为空
	s->maxsize = maxsize; // 设置顺序栈的最大空间
	s->elements = (DataType*)malloc(maxsize * sizeof(DataType)); // 动态分配顺序栈的存储空间
	if (s->elements == NULL) {
		return 0; // 分配失败，返回0
	}
	return 1; // 初始化成功，返回1
}

//	2)判断顺序栈是否为空
int isEmpty(struct Stack* s) {
	return s->top == -1; // 如果栈顶指针为-1，表示栈为空，返回1，否则返回0
}

//	3)判断顺序栈是否满
int isFull(struct Stack* s) {
	return s->top == s->maxsize - 1; // top指向栈顶元素，而不是指向栈顶的下一个元素
}

//	4)入栈
int push(struct Stack* s, DataType value) {
	if (isFull(s)) {
		printf("栈已满，无法入栈！\n");
		return 0; // 栈已满，返回0
	}
	s->elements[++s->top] = value; // 栈顶指针加1，然后将元素入栈
	return 1; // 入栈成功，返回1
}

//	5)出栈
int pop(struct Stack* s, DataType* value) {
	if (isEmpty(s)) {		//注意出栈要先判断栈是否为空
		printf("栈为空，无法出栈！\n");
		return 0; // 栈为空，返回0
	}
	*value = s->elements[s->top--]; // 将栈顶元素出栈，并将栈顶指针减1
	return 1; // 出栈成功，返回1
}

//	6)获取栈顶元素值 
int getTop(struct Stack* s, DataType* value) {
	if (isEmpty(s)) {		//注意获取栈顶元素要先判断栈是否为空
		printf("栈为空，无法获取栈顶元素！\n");
		return 0; // 栈为空，返回0
	}
	*value = s->elements[s->top]; // 将栈顶元素赋值给value
	return 1; // 获取栈顶元素成功，返回1
}

struct Stack printStack(struct Stack* s) {
	if (isEmpty(s)) {
		printf("栈为空，无法打印栈元素！\n");
		return *s; // 栈为空，返回空栈
	}
	printf("当前栈元素为：");
	for (int i = s->top; i >= 0; i--) {
		printf("%d ", s->elements[i]);
	}
	printf("\n");
	return *s; // 返回顺序栈
}

int main() {
	printf("顺序栈测试程序\n");
	printf("请输入顺序栈的最大空间：");
	int m;	// 用m存储顺序栈的最大空间		
	scanf("%d", &m);
	struct Stack s;

	//	1)初始化一个空的顺序栈
	if (!initStack(&s, m)) {
		printf("顺序栈初始化失败！\n");
		return 0;
	}
	printf("顺序栈初始化成功！\n");

	//	2)判断顺序栈是否为空
	if(isEmpty(&s)) {
		printf("顺序栈为空！\n");
	} else {
		printf("顺序栈不为空！\n");
	}

	//	3)判断顺序栈是否满
	if(isFull(&s)) {
		printf("顺序栈已满！\n");
	} else {
		printf("顺序栈未满！\n");
	}

	//	4)入栈
	DataType v;	// 用v存储入栈的元素值
	for(int i = 0; i < m; i++) {
		printf("请输入第%d个入栈元素的值(按9999退出）：", i + 1);
		scanf("%d", &v);
		if (v == 9999) {
			break; // 如果输入9999，则退出循环
		}
		else push(&s, v); 
	}
	
	printStack(&s);

	//	6)获取栈顶元素值
	DataType topValue;
	getTop(&s, &topValue);
	printf("栈顶元素的值为：%d\n", topValue);

	//	5)出栈
	printf("\n开始出栈（直到栈为空）：\n");
	DataType poppedValue;
	while (pop(&s, &poppedValue)) {
		printf("出栈元素：%d\n", poppedValue);
	}

	printStack(&s);

	free(s.elements);
	printf("程序结束。\n");
	return 0;
}