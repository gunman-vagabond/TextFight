#pragma inline

extern int nowx,nowy;
extern int shotf;
extern int renshakankaku;
extern int pause;

void keyin(){}

/*
void _keyin()
{
	char key26,key48;
	char shift;
	char esc;
	static char maeshift;
	static int count;
	
	asm MOV AX,0C00H
	asm INT 21H

	asm MOV AX,0408H
	asm INT 18H
	asm MOV key48,AH
	asm MOV AX,0409H
	asm INT 18H
	asm MOV key26,AH
	asm MOV AX,040EH
	asm INT 18H
	asm MOV shift,AH
	asm MOV AX,0400H
	asm INT 18H
	asm MOV esc,AH
	
	if(key26 & 0x08)
		nowy ++;
	if(key26 & 0x01)
		nowx ++;
	if(key48 & 0x40)
		nowx --;
	if(key48 & 0x08)
		nowy --;
	if(shift & 0x01){
		if(maeshift == 1){
			count ++;
			if(count >= renshakankaku){
				count = 0;
				shotf = 1;
			}
		} else {
			shotf = 1;
		}
		maeshift = 1;
	} else {
		maeshift = 0;
	}
	pause = esc & 0x01;
}
 */