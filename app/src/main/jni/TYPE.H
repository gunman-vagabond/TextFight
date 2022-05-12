extern struct ch_dat {
	int no;
	char *charag;
	char *movedt;
	int maxcount;
	/* random(maxcount)�@�ɂďo������ movedt �̃|�C���^�H������
		�O�Ȃ� movedt[0]�@����ǂ�*/
	int shotp,tamatype;
	/*	shotp : random(100)>shotp �Œe���� 
		10 ���ƌ��\�o���@
		0 �ł�movedt ��p�������Ă����Βe����*/
	int katasa;
	int xw,yw;
	int shutugen_x,shutugen_y;
	int waitcount;
	/* waitcount : ���ɏo������L�����܂ł̑҂��J�E���g
					�O�̎��� random(15)�@
		�p�~�Ă������オ���Ă���*/
	
	
} ch_data[];

extern struct shutu_p {
	int chara_no;
	int loc_x,loc_y;
	int count;
	int wait;
} shutu_patarn[];

extern char bom[16][3];
extern char kabe[];
