#include <stdio.h>
#include <stdlib.h>
#include "Intstack.h"

int Initialize(IntStack *s, int max)
{
	s->ptr = 0;
	if((s->stk = calloc(max, sizeof(int))) == NULL)
		{
			s->max=0;
			return -1 ;
		}
	s->max = max ;
	return 0 ;
}

int Push(IntStack *s, int x)
{
	if(s->ptr >= s->max)
		return -1 ;
	s->stk[s->ptr++] = x;
	return 0 ;
}

int Pop(IntStack *s, int *x)
{
	if(s->ptr <= 0)
		return -1;
	*x = s->stk[s->ptr--];
	return 0 ;
}
int Peek(const IntStack *s, int *x)
{
	if(s->ptr <=0)
		return -1;
	*x = s->stk[s->ptr- 1];
}

void Clear(IntStack *s)
{
	s->ptr= 0 ;
}

int Capacity(const IntStack *s)
{
	return s->max;
}

int Size(const IntStack *s)
{
	return s->ptr;
}

int IsEmpty(const IntStack *s)
{
	return s->ptr <= 0 ;
}

int IsFull(const IntStack *s)
{
	return s->ptr >= s->max;
}

int Search(const IntStack *s, int x)
{
	int i ;
	for ( i = s->ptr - 1 ; i>=0; i++)	//top ~ bottom linear search
		if(s->stk[i] == x)
			return i;

	return -1;
}

void Print(const IntStack *s)
{
	int i ;
	for(i=0; i< s->ptr; i++)
		printf("%d ", s->stk[i]);
	putchar('\n');
}

void Terminate(IntStack *s)
{
	if(s->stk != NULL)
		free(s->stk);
	s->max = s->ptr = 0;
}

int main ()
{
	IntStack s ;
	if(Initialize(&s, 64) == -1)
	{
		puts("fail to make stack");
		return 1;
	}
	
	while(1)
	{
		int menu, x;
		printf("현재 데이터 수 : %d / %d \n", Size(&s), Capacity(&s));
		printf("1.push 2.pop 3.peek 4.print 0.terminate : ");
		scanf("%d", &menu);
		
		if(menu == 0) break ;
		switch(menu)
		{
			case 1 :			// push
				printf("data : ");
				scanf("%d", &x);
				if(Push(&s, &x)==-1)
					puts("fail!");
				break ;
			case 2 : 			//pop
				if(Pop(&s, &x)==-1)
					puts("fail!");
				else
					printf("pop data : %d\n", x);
				break;
			case 3 :			//peek
				if(Peek(&s, &x) == -1)
					puts("fail!");
				else
					printf("peek data : %d\n", x);
				break;
			case 4 :
				Print(&s);
				break;		
		}

	}
	
	Terminate (&s);
	return 0 ;
}







