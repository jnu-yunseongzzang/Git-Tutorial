#include <stdio.h>

typedef struct point 
{
	int xpos;
	int ypos;
}Point ;

typedef struct rectangle
{
	Point Lp ;
	Point Sp ;
	Point Lspx;
	Point Lspy;
}Rectangle;

typedef struct circle
{
	Point cen ; 
	double rad;
}Circle;

void ShowCircleInfo(Circle * cptr)
{
	printf("[%d,%d]\n", (cptr->cen).xpos, (cptr->cen).ypos);
	printf("radius: %g\n\n", cptr->rad);
}
void SwapPoint(Point *ptr1, Point *ptr2)
{
	printf("swap...\n");
	Point temp ;
	temp.xpos = ptr1->xpos;
	temp.ypos = ptr1->ypos;
	ptr1->xpos = ptr2->xpos;
	ptr1->ypos = ptr2->ypos;
	ptr2->xpos = temp.xpos;
	ptr2->ypos = temp.ypos;
}

void ShowPoint(Point pos1, Point pos2)
{
	printf("pos1: [%d,%d]\n", pos1.xpos, pos1.ypos);
	printf("pos2: [%d,%d]\n", pos2.xpos, pos2.ypos);	
}

void ShowRectanglePoint(Rectangle rec)
{
	printf("pos1:[%d,%d]\n",rec.Lp.xpos, rec.Lp.ypos);
	printf("pos2:[%d,%d]\n",rec.Lspx.xpos, rec.Lspx.ypos);
	printf("pos3:[%d,%d]\n",rec.Lspy.xpos, rec.Lspy.ypos);
	printf("pos4:[%d,%d]\n",rec.Sp.xpos, rec.Sp.ypos);
}

void RectanglePoint(Rectangle * rec, Point pos1, Point pos2)
{
	rec->Sp.xpos = pos1.xpos ;
	rec->Sp.ypos = pos1.ypos ;
	rec->Lp.xpos = pos2.xpos ;
	rec->Lp.ypos = pos2.ypos ;
	rec->Lspx.xpos= pos2.xpos-pos1.xpos;
	rec->Lspx.ypos = pos2.ypos;
	rec->Lspy.xpos =pos2.xpos;
	rec->Lspy.ypos =pos2.ypos-pos1.ypos;
}

int main()
{
	Rectangle rec ; 
	Rectangle * rptr=&rec;
	Point pos1;
	Point pos2;
	
	Circle c1= {{1,2}, 3.5};
	Circle c2= {{2,4}, 3.9};
	Circle * cptr1= &c1;
	Circle * cptr2= &c2;
	
	printf("range : (0,0)~~(100,100)\n");
	printf("smaller position(pos1): ");	
	scanf("%d %d", &pos1.xpos, &pos2.ypos);
	printf("lager position(pos2): ");
	scanf("%d %d", &pos2.xpos, &pos2.ypos);
	
	RectanglePoint(rptr,pos1,pos2);
	ShowRectanglePoint(rec);
	
	return 0 ;
}
