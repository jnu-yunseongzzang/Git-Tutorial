#ifndef ___IntStack
#define ___IntStack

typedef struct 
{
	int max ;	//stack 's capacity
	int ptr ;	// stack pointer 
	int *stk;	//stack pointer of first content
}IntStack;

/* ���� �ʱ�ȭ */ 
int Initialize(IntStack *s, int max);

/* ���ÿ� ������ Ǫ�� */ 
int Push(IntStack *s, int x);

/* ���ÿ� ������ �� */ 
int Pop(IntStack *s, int*x);

/* ���ÿ��� ������ ��ũ*/
int Peek(const IntStack *s, int *x);

/* stack clear */
void Clear(IntStack *s);

/* stack max capacity */
int Capacity(const IntStack *s);

/* piece of stack data */
int Size(const IntStack *s);

/* stack empty?? */
int IsEmpty(const IntStack *s);

/* stack is full? */
int IsFull(const IntStack *s);

/* Search on stack */
int Search(const IntStack *s, int x);

/*show all data */
void Print(const IntStack *s);

/* finish stack */
void Terminate(IntStack *s);

#endif
 
