//2. 利用栈结构，编程实现将一个十进制整数number转换成base进制
//（base为不同进制，参考取值为2 ≤ base ≤ 9）。

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
struct Stack {
    int top; // 栈顶指针，指向栈顶元素的下标
    int maxsize; // 顺序栈的最大空间
    DataType* elements; // 存放顺序栈的栈元素
};

// 1)初始化一个空的顺序栈
int initStack(struct Stack* s, int maxsize) {
    s->top = -1;
    s->maxsize = maxsize;
    s->elements = (DataType*)malloc(maxsize * sizeof(DataType));
    if (s->elements == NULL) {
        return 0;
    }
    return 1;
}

// 2)判断顺序栈是否为空
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// 3)判断顺序栈是否满
int isFull(struct Stack* s) {
    return s->top == s->maxsize - 1;
}

// 4)入栈
int push(struct Stack* s, DataType value) {
    if (isFull(s)) {
        printf("栈已满，无法入栈！\n");
        return 0;
    }
    s->elements[++s->top] = value;
    return 1;
}

// 5)出栈
int pop(struct Stack* s, DataType* value) {
    if (isEmpty(s)) {
        return 0;
    }
    *value = s->elements[s->top--];
    return 1;
}

// 6)获取栈顶元素值 
int getTop(struct Stack* s, DataType* value) {
    if (isEmpty(s)) {
        printf("栈为空，无法获取栈顶元素！\n");
        return 0;
    }
    *value = s->elements[s->top];
    return 1;
}

// 7)销毁栈
void destroyStack(struct Stack* s) {
    free(s->elements);
    s->elements = NULL;
    s->top = -1;
    s->maxsize = 0;
}

/* ---------------- 主程序 ---------------- */
int main(void) {
    long long number;
    int base;
    int neg;
    unsigned long long n;
    DataType digit;
    struct Stack s;

    printf("请输入您要转化的十进制整数：");
    if (scanf("%lld", &number) != 1) {
        printf("输入无效：number 必须是整数\n");
        return 1;
    }

    printf("请输入您想转化的进制（支持2~9进制）：");
    if (scanf("%d", &base) != 1) {
        printf("输入无效：base 必须是整数\n");
        return 1;
    }

    /* 1. 校验 base 范围 */
    if (base < 2 || base > 9) {
        printf("输入无效：base 必须在 2~9 之间\n");
        return 1;
    }

    /* 2. 特判 0 */
    if (number == 0) {
        printf("转换结果：0\n");
        return 0;
    }

    /* 3. 处理负数：先取绝对值，最后补负号 */
    neg = 0;
    if (number < 0) {
        neg = 1;
        // 修改这里：先给 long long 取反，再强转 unsigned long long
        n = (unsigned long long)(-number);
    }
    else {
        n = (unsigned long long)number;
    }

    /* 4. 初始化栈 */
    if (!initStack(&s, 100)) {
        printf("内存分配失败\n");
        return 1;
    }

    /* 5. 除基取余，余数入栈 */
    while (n > 0) {
        if (!push(&s, (DataType)(n % base))) {
            printf("栈溢出\n");
            destroyStack(&s);
            return 1;
        }
        n /= base;
    }

    /* 6. 出栈输出（高位到低位） */
    printf("转换结果：");
    if (neg) printf("-");

    while (pop(&s, &digit)) {
        printf("%d", digit);
    }
    printf("\n");

    /* 7. 释放栈空间 */
    destroyStack(&s);

    return 0;
}