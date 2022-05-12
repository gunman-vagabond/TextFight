#include "stdlib.h"

#define _vram_atr(x,y) \
	((int far *)MK_FP(0xa200, 2*(x) +  160*(y)))
#define _vram_adr(x,y) \
	((int far *)MK_FP(0xa000, 2*(x) +  160*(y)))

extern char atr_dummy;
extern char screen[];

#define vram_atr(x,y) &atr_dummy
/*#define vram_adr(x,y) \
	&((screen[(x) + 80*(y)])) */
#define vram_adr(x,y) \
	(screen + (x) + 80*(y))

#define my_random(x) rand()%(x)
#define beep(x) {}
#define getch() 'q'

#define min(x,y) ((x<y)?x:y)
#define max(x,y) ((x>y)?x:y)

void keyin();

void NTmain();

/*
 *  �t�@���N�V�����L�[�̕\��������
 */
void funcclear()
{
	int i;
	
	for(i=0; i<80; i++){
		*vram_adr(i,24) = ' ';
		*vram_atr(i,24) = 0;
	}
}

/*
 *�@���W(x,y)�� ������ s �������o��
 */
void putsxy(int x,int y, char *s)
{
	int xnow;
	char c;
	
	xnow = x;
	for((c = *s); c != '\0'; xnow++){
		*vram_adr(xnow, y) = c;
		c = * ++s;
	}
}

/*
 *  �͈� (x1,y1)-(x2,y2) ������
 */
void boxclear(int x1, int y1, int x2, int y2)
{
	int xnow, ynow;
	
	for(ynow = y1; ynow <= y2; ynow++){
		for(xnow = x1; xnow <= x2; xnow++){
			*vram_adr(xnow,ynow) = ' ';
		}
	}
}
