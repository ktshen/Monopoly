#include<stdio.h>
#include <time.h>
#include <iostream>
#include <windows.h>
#define SIZE 22
using namespace std;

const char *land[SIZE] = {"�Ȯa�ǰ|","���j��","�z�ǰ|","�y������","�P���","�R�B","�ժ��x��","����",
						  "���j�ժ�","§  ��","�C���]","�k�Q�T��","���׮ѧ�","�k�Q�|��","�d�]��","�k�T��",
						  "���|","�k�@��|","�q�T�t�]","�̤���","�x�y��","��a��",}; 

const int positionxy[22][2]={{37,4},{54,4},{71,4},{88,4},{105,4},
							{122,4},{122,9},{122,14},{122,19},{122,24},{122,29},{122,34},
							{105,34},{88,34},{71,34},{54,34},{37,34},
							{37,29},{37,24},{37,19},{37,14},{37,9}};
							
	
const int land_price[SIZE]={ 0, 1000, 1200, 3000, 2000, 0,2000, 3000, 5000, 2000, 1000, 
								3500, 2000, 3000, 1000, 2000, 0,3000,4000, 2000, 1500,6000};

void printmono(void) ;
void start(int *playersturn1 , int *playersturn2 ) ;
int gameover(int p1 , int p2);
void map(void);
void movepos(int play,int *pyr,int player1 ,int player2 , int playerturn1, int playerturn2 , int *playermoney1 , int *playermoney2, int playerland1[] , int playerland2[], int land_bought[],int playercar    );
void land_buy(int player, int position , int *player_money, int playerland[],int land_bought[]);
void changeplayer(int *pt1 , int *pt2);
void fee(int player, int *playermoney , int *oplayermoney, int oplayerland[], int position);
void buyfunc( int player ,int position, int land_bought[] , int *playermoney, int playerland[] );
void destiny (int *position, int player);
void opport (int player ,int *playermoney, int *oplayermoney);
void print(void);
void save(int player1 ,int player2 , int playerturn1, int playerturn2 , int playermoney1 , int playermoney2, int playerland1[] , int playerland2[], int land_bought[]  );
void load(int *player1 ,int *player2 , int *playerturn1, int *playerturn2 , int *playermoney1 , int *playermoney2, int playerland1[] , int playerland2[], int land_bought[]);
void rowdicemusic(void);
void changeplayercar(int *playercar);
void gotoxy(int xpos, int ypos);
void delay(int time);
void printplayer1position(int player1);
void printplayer2position(int player2);
void printplayer1money(int playermoney1);
void printplayer2money(int playermoney2);
void printplayer1car(int playercar1);
void printplayer2car(int playercar2);
void clear1(void);
void dicedisplay(int a);
void runbike(int player , int kind);
void getbike(int *playercar, int player);
void losebike(int *playercar ,int player);



int main(void)
{
	system("mode con cols=167 lines=150");        
                                                                                                                                                                                             
	printmono();
	
	
                                                                                                                                                                                                    
	int Delay = 400;
	short Hz[] = { 0, 131, 147, 165, 175, 196, 220, 247, 262, 294, 330, 349, 392, 440, 494, 523, 659, 698, 783, 880, 988, };
	char Tone[] =  {   8,  5,  8,  8,  7,    7,   6,   5,  6,  6,  7,  7,  7,  8,  9,  8,  0 }, *t;
	float Beat[] = {2.5f,.5f,.8f,.8f,1.f,1.25f,.75f,2.5f,2.f,.5f,1.f,.5f,.5f,.5f,.5f,3.f,-1.f}, *b;
	t = Tone; b = Beat;
	while (*b >= 0)
	if (*t) Beep(Hz[*t++], *b++ * Delay);
	else { Sleep(*b++ * Delay); t++; }
		
	system("pause");
	system("CLS");
	system("color 0a");
	
	
	print();
	
	system("pause");
	system("cls");
		
	int player1=0 , player2=0 ;  //position
	int playersturn1=0 , playersturn2=0;
	int playermoney1=20000 , playermoney2 = 20000 ;
	int playerland1[19]={0}, playerland2[19]={0} ;                // 0 �N��S��  1�N��A  2�N��B .....  �����[1 
	int land_bought[SIZE] = {0};                                  // ��ܭ��Ǥg�a�w�Q�ʶR 
	int playercar1 = 0 , playercar2 = 0 ;
	
	
	
	start(&playersturn1 , &playersturn2 );
	
	
	
	system("pause");
	system("cls");
	
	system("mode con cols=170 lines=500");							
	
	map();
	printplayer1position(player1);
	printplayer2position(player2);
	printplayer1money(playermoney1);
	printplayer2money(playermoney2);
	runbike(1 , 0);
	runbike(2, 0);
	
	//==========================================================================================================================================================
	
	while(gameover(playermoney1, playermoney2)==1)
	{
		
		
		if(playersturn1==1)
		{
			gotoxy(60,9);
			cout<<"�йC����1 �Y��                  ";
			
			
			movepos(1,&player1,player1 ,player2 , playersturn1, playersturn2 , &playermoney1 , &playermoney2,  playerland1 , playerland2,land_bought,playercar1 );
			getbike(&playercar1, 1);
			losebike(&playercar1, 1);
			
			buyfunc( 1 ,player1, land_bought , &playermoney1 ,playerland1 );
			
			if(player1==5)
			destiny (&player1,1);
			if(player1==16)
			opport(1, &playermoney1, &playermoney2);
							  // buy
			
			fee(1,&playermoney1 , &playermoney2 ,playerland2, player1);
						
			changeplayer(&playersturn1, &playersturn2);
			
			gotoxy(33,39);
			
			
		}
		else if(playersturn2==1)
		{
			gotoxy(60,9);
			cout<<"�йC����2 �Y��               ";
			movepos(2,&player2,player1 ,player2 , playersturn1, playersturn2 , &playermoney1 , &playermoney2,  playerland1 , playerland2,land_bought,playercar2);			
			getbike(&playercar2, 2);
			losebike(&playercar2, 2);
			
			buyfunc( 2 ,player2, land_bought , &playermoney2 ,playerland2 );
			
			if(player2 == 5)															 //buy
			destiny (&player2,2);
			if(player2==16)
			opport(2,&playermoney2, &playermoney1);
			
			fee(2,&playermoney2 , &playermoney1, playerland1, player2);     	 
			changeplayer(&playersturn2, &playersturn1);
			
			gotoxy(33,39);
			
		}	
		system("pause");
		clear1();
		
	
}

		if(playermoney1<=0)
		MessageBox(0,"�C����1�S����F��~\n\n~~~~~~�C����2 ���!!~~~~~~","�C������",0);
		else if (playermoney2<=0)
		MessageBox(0,"�C����2�S����F��~\n\n~~~~~~�C����1 ���!!~~~~~~","�C������",0);
		
		gotoxy(0,40);
}

void printmono(void)
{
	printf("		                                                                                                                               \n");
	printf("		                                                          `@@+                                                                 \n");
	printf("		                  `@`                                        @@`                                   @#.`       ;@@@;            \n");
	printf("		                  +@@@                                       .,'#@@@@++@@@@;                        @@          `''`           \n");
	printf("		                   @@@                               +  `@@@@;.        :@@@@@                      ,@@ `,:`                    \n");
	printf("		                   @@@                               @@@                                           @@   @@'                    \n");
	printf("		                   @@@                               @@@   `:@@@@@                                      @@     @@+             \n");
	printf("		                   @@@ :#@@@@@@@                      @@   '+.                                         @@   `'  .@@;           \n");
	printf("		                 :#@@@@@@@@@@'.                              '@@@@@@@                                +@@ :@@      ,            \n");
	printf("		         `+@@@@@@@@@@@                                   '   `  @@@;                                @@@@@.       '             \n");
	printf("		            +@@#   @@@@                                   @@`  ;@@@                                 ,         :@@@@@@          \n");
	printf("		                   @@@@@                                   @@.,+@@'                                  ,@@@@'@@@@ .@@@`          \n");
	printf("		                   @@@@@@                                   .@,                                 :#@@,,@@@@ @     @@#           \n");
	printf("		                   @# @@#+                                   `      .+@#+                             @@@  @@@@+ ,@'           \n");
	printf("		                  `@@  +@@+                                `,@@@@@@@;'@@@@@@                   `@@,   ;@.   .#@   @'           \n");
	printf("		                  @@@   +@@@                           ` `, `'+@@     @@@@`                     :@;   ;@          @+           \n");
	printf("		                  @@     +@@@                         +@@@     +@     @@@@                       `    ;@     ,'   @#           \n");
	printf("		                ,@@;      :@@@@                        @@@@@#@@@@@@@; @@@+                       '    ;@    @@`   @@           \n");
	printf("		               @@#          '@@@@#`                     @@@;.``'@     @@@                      `@@    ;@  @@@,    @@           \n");
	printf("		             @@.               +@@@@@;                  ,@@'   @.     @@@                     @@@;    +@   ;@     @+           \n");
	printf("		          .@.                      `,+@@@:               ,@@      .,'+@@@                     ,@@     @@          @            \n");
	printf("		        ``                                                 @@@@@@@'.`,;@                       ,     ,@@        `@@            \n");
	printf("		                                                                                                      @+         @@            \n");                                                                                                                                                                                                     
	printf("                                                                                                                                                                      \n");
	printf("                                       ;+.                      :            .':    .     ;@@+:',``               ;'        '++;,:,;,'.                               \n");
	printf("                                  .#@'`@@+`.   `@@@@:+.       @@@@@;`   '.@+.'@#.. '@#@+` #+:;+++:@,#`      ;`#@:.@@'``     # ## @                                    \n");
	printf("      `,@;`          `';;      `#`@`.',   @@`+`  @@+'+;'       @+@    ' @, ;;   #+',:  .+,@#@##@+;'+:,+   ,:++ :+.  `#@ '   # #@+@             . .                    \n");
	printf("    `,;;. @          @,'##+    ++@+       #@@` `  ##'@ ;;      #@    .,@#;      ,@@' ' :#+@,:       @+@+  :@@#       #@@ :  + #@@@           `+:::    `.@@@@@@##`     \n");
	printf("      `+ #@@        @.:.@;    #@@@`       #@#@@#  '+'@  @,     #.`  .@@@+       ,@@+@; `@@@ +       '@@# @@@@        @@;#;. + +@@@              ;+      ++ @#         \n");
	printf("       ``##,,`     # ,#.@     @@#@.       :@@ @+  :#,@  ,+:    @,`  +@@@+       `@@`@.  @+@ @       #@@#.@@'@        @@:`', `++@@@               :@    :@.;,.`        \n");
	printf("        :'+` .'  `,: ;;.+    ,@@+@;       ,@@ ##  ;:@@   # ,   #, ` @@@##        @@`'@ `@@@ @      `@'@'@@@;@        @@; @.  +'@@@+              ``+`  #@`#.,         \n");
	printf("        +;@`   @.''`;, `;   .#@,@@#       ;@@ +@ ``.#@`   `+   +:`.,@:@@@       `@@.+@  @@@ @      '+@@'@@#@@`       @@# #, ;+,+@@,               ``; '' +,`          \n");
	printf("       `;,@.    `+,@   .+    #@ @@+       :@@ '+  .`:@`    @   ',` ,@ @'@       `@@.@#  @@@ @     ,@,.@ @:';@`       @@#,.` `;:@@'`                  ,@;+,.           \n");
	printf("       `;:#:      :    :@    #@`'@#       +@@.#:  ``,@ `   `#  #,. :@`@#@       .@@`@#  +@# @;;@;`. `` `@'+.@.       @@'''    ,#@+`                 ,;;'+`            \n");
	printf("       ,,'@+           .@    `@`'+@       '@@:@.  ..@@      ,. #.,  @,@.@       `@@`@+  :''.;           #@+ @:       @#;@@ ` `,@@+                 ;,@.;              \n");
	printf("       .;,#@            '     @+'+@       :@#'@`  ,,;@`      @`@,+  '@@`@.       @@`@;  `@#,:           .@+ @+       @@,@@ ` .,@@,                #@@'#               \n");
	printf("       `.,+@            '     +@+:@       '@+#:  `.:@@       ``+,;  .@@ @,      `@@#@   ,@@:+            @@`@#       @@,'    '+@@` `      @      '#@@,                \n");
	printf("      ` ``;@            +,    .@@#@       ;'''   ;,:+@        ,;,    @@@@;      `@##    :@@@@            +@@@@       @:;     '@@@        ;@     ;@@@: :               \n");
	printf("      .,:,@#           #+,#;@# .@@@,   `,#'@.   `@+::@         ;`     @@@#    .+#@+     '@@@@            `#@@@    `:@#@     ``@@@       :@@`   @.@@+                  \n");
	printf("     `;,:.;`'        ;+#@@@`:    @@@@@''#@@@   `@@@@@@        .@@@@,   ;@@@@+'+#@@      '@@@#@             `@@@@#';#@@.     #@@@ ; :@`@@@@@@` :#`@..                  \n");
	printf("   :@@@@@@@@@+`     :  `` `  `     ;+@@@+'`         :'                   :+@@@#'.     '@@@@@@@@              ,;@@@@+;     ;:+@@+,:;';':,,@'@`'#+@@':                  \n");
	printf("                                                                                                                                             ``+;                     \n");
	printf("\n								Press Enter To Continue the Game                                                                          \n");
	
}


void start(int *playersturn1 , int *playersturn2 )
{	
	int a ;
	int judge1=0;
	char enter ;
	gotoxy(65,21);
	puts("�Ы� 'R'+'ENTER' �ӨM�w�֥��}�l");
	while(judge1==0)
	{
	gotoxy(65,22);
	scanf("%c", &enter);
	rowdicemusic();
	if(enter=='R')
	{
			
		srand(time(NULL));
		a = (rand()%6)+1;
		judge1++;
	}
	
			
	}
	if(a==1 || a==2 || a==3)
	{
		gotoxy(65,23);
		printf("�C����1���}�l!");
		*playersturn1=1 ;		
	}
	else{
		gotoxy(65,23);
		printf("�C����2���}�l!");
		*playersturn2=1 ;
	}
	
	gotoxy(65,24);
	
}
int gameover(int p1 , int p2)
{
	if( p1<=0 || p2<=0)
	return -1;
	else
	return 1 ; 
	
}

void map(void)
{
	printf("                                 _____________________________________________________________________________________________________                                 \n");
	printf("                                |                |                |                |                |                |                |                                \n");
	printf("                                |  XX�Ȯa�ǰ|XX  |  XX ���j�� XX  |  XX �z�ǰ| XX  |  XX�y������XX  |  XX �P��� XX  |  XX  �R�B  XX  |                                \n");
	printf("                                |                |                |                |                |                |                |                                \n");
	printf("       @@@@@#      @@@@         |                |                |                |                |                |                |        @@@@@#      @@@@@       \n");
	printf("       @@  @@      @@@@         |________________|________________|________________|________________|________________|________________|        @@  @@     @@  @@@      \n");
	printf("       @@  @@       @@@         |                |                                                                   |                |        @@  @@        .@@       \n");
	printf("       @@@@@        @@@         |  XX ��a�� XX  |                                                                   |  XX�ժ��x��XX  |        @@@@@       .@@         \n");
	printf("       @@           @@@         |                |                                                                   |                |        @@         @@@          \n");
	printf("       @@           @@@         |                |                                                                   |                |        @@        @@@           \n");
	printf("       @@          @@@@@        |________________|                                                                   |________________|        @@       ;@@@@@@@       \n");
	printf("                                |                |                                                                   |                |                                \n");
	printf("                                |  XX �x�y�� XX  |                                                                   |  XX ���� XX  |                                \n");
	printf("     ���� :                     |                |                                                                   |                |      ���� :                    \n");
	printf("                                |                |                                                                   |                |                                \n");
	printf("                                |________________|                                                                   |________________|                                \n");
	printf("                                |                |                                                                   |                |                                \n");	                                              
	printf("                                |  XX �̤��� XX  |                                                                   |  XX���j�ժ�XX  |                                \n");
	printf("                                |                |                                                                   |                |                                \n");
	printf("                                |                |                                                                   |                |                                \n"); 
	printf("                                |________________|                                                                   |________________|                                \n");
	printf("                                |                |                                                                   |                |                                \n");	                                                               
	printf("  ____________________________  |  XX�q�T�t�]XX  |                                                                   |  XX §  �� XX  |  ____________________________  \n");
	printf(" |                            | |                |                                                                   |                | |                            | \n");
	printf(" |                            | |                |                                                                   |                | |                            | \n"); 
	printf(" |                            | |________________|                                                                   |________________| |                            | \n");
	printf(" |                            | |                |                                                                   |                | |                            | \n");
	printf(" |                            | |  XX�k�@��|XX  |                                                                   |  XX �C���] XX  | |                            | \n");
	printf(" |                            | |                |                                                                   |                | |                            | \n");
	printf(" |                            | |                |                                                                   |                | |                            | \n"); 
	printf(" |                            | |________________|___________________________________________________________________|________________| |                            | \n");
	printf(" |                            | |                |                |                |                |                |                | |                            | \n");
	printf(" |                            | |  XX  ���|  XX  |  XX �k�T�� XX  |  XX �d�]�� XX  |  XX�k�Q�|��XX  |  XX���׮ѧ�XX  |  XX�k�Q�T��XX  | |                            | \n");
	printf(" |                            | |                |                |                |                |                |                | |                            | \n");
	printf(" |____________________________| |                |                |                |                |                |                | |____________________________| \n");
	printf("                                |________________|________________|________________|________________|________________|________________|                                \n");
	
	gotoxy(0,37);
	printf("                                ��J�̫��O:");
	

	

}

void movepos(int play, int *pyr,int player1 ,int player2 , int playerturn1, int playerturn2 , int *playermoney1 , int *playermoney2, int playerland1[] , int playerland2[], int land_bought[],int playercar)
{
	int dicef(int playercar);
	int judge = 0;
	int t ;
	gotoxy(60,10);
	cout<<"�Ы� 'R'+'ENTER'!!  ";
	
	int qw  = *pyr;
	int ps ;
	
	if(play==1) ps = 0 ;
	else ps = 5 ;
	
	
	
	while(judge==0)
	{
	char enter ;
	gotoxy(43,37); 
	scanf("%c", &enter);
	gotoxy(43,37); 
	printf("  ");
	
	if(enter=='R')
	{	
		rowdicemusic();
		t = dicef(playercar) ;
		*pyr+=t;
	if(*pyr>=22)
	{
		*pyr -=22;
		
		if(play==1) 
		{
			*playermoney1 += 2000 ;
			printplayer1money(*playermoney1) ;
			
		}
		else {
			*playermoney2 += 2000 ;
			printplayer2money(*playermoney2) ;
		}
		
		
	}
	 gotoxy(60,12);
	 cout<<"�A���ثe��m�� "<< land[*pyr] ;
	  

	 for(int i = 0 ; i < t;i++){
	 	 int l = qw + i ;	
	 	if(l >=22) l-=22 ;
	 	
	 	gotoxy(positionxy[l][0]+ps,positionxy[l][1]);
	 	printf("  ");
	 	
	 	if(l+1>=22) l-=22;
	 	gotoxy(positionxy[l+1][0]+ps,positionxy[l+1][1]);
	 	if(play==1)printf("P1");
	 	else printf("P2");
	 	 delay(300);
	 	
	 }
	 
	 
	 
	 
	 
	 judge++ ;  
	}
	
	
	}
}

int dicef(int playercar)
{
	int a ;
	int b ;
	if (playercar==0)
	{
		srand(time(NULL));
		a = (rand()%6)+1;
		
		for(int i = 0 ; i < 20 ; i++){
			
			b = (rand()%6)+1;
			dicedisplay(b);
			delay(70);
		}
		
		dicedisplay(a);
		delay(200);
		gotoxy(60,11);
		printf("�A�o�� %d",a);
	}
	else if (playercar==1){
		srand(time(NULL));
		a = ((rand()%6)+1)*2;
		
			for(int i = 0 ; i < 20 ; i++){
			
			b = (rand()%6)+1;
			dicedisplay(b);
			delay(50);
		}
		
		dicedisplay(a/2);
		delay(200);
		
		
		gotoxy(60,11);
		printf("�A�o�� %d",a);
	}
	
	
	
	return a;
}

void destiny (int *position,int player)
{
	
	int qw = 0 ;
	if(player==2) qw+=5 ;
	int a ;
	srand(time(NULL));
	a = (rand()%4)+1;
	
	gotoxy(60,13);
	printf("�A��� �R�B�P");
	
	switch(a){
		case 1 : *position = 0 ;
				  gotoxy(positionxy[5][0]+qw,positionxy[5][1]);
				  printf("  ");
				  gotoxy(positionxy[0][0]+qw,positionxy[0][1]);
				  if(player==1)printf("P1");
	 		   	  else if (player==2)printf("P2");
				  printf("\a");
				 MessageBox(0,"�^�a������� �T�T!!","�R�B",0); 
				 
				 break;
				 
		case 2 :  *position-= 3 ;
				gotoxy(positionxy[5][0]+qw,positionxy[5][1]);
				  printf("  ");
				  gotoxy(positionxy[2][0]+qw,positionxy[2][1]);
				  if(player==1)printf("P1");
	 		   	  else if (player==2)printf("P2");
				printf("\a");
				MessageBox(0,"�˰h�T��","�R�B",0);
				break;
				
		case 3 : *position += 2 ;
				gotoxy(positionxy[5][0]+qw,positionxy[5][1]);
				  printf("  ");
				  gotoxy(positionxy[7][0]+qw,positionxy[7][1]);
				  if(player==1)printf("P1");
	 		   	  else if (player==2)printf("P2");
	 		   	  printf("\a");
	 		   	  MessageBox(0,"�e�i���","�R�B",0);
				
				break;
				
		case 4 :  *position += 4 ;
			gotoxy(positionxy[5][0]+qw,positionxy[5][1]);
			printf("  ");
				  gotoxy(positionxy[9][0]+qw,positionxy[9][1]);
				  if(player==1)printf("P1");
	 		   	  else if (player==2)printf("P2");
	 		   	  printf("\a");
	 		   	  MessageBox(0,"�e�i�|��","�R�B",0);
			
			
				break;
	}
	
}

void opport (int player, int *playermoney, int *oplayermoney)
{
	int a ;
	
	srand(time(NULL));
	a = (rand()%6)+1;
	
	gotoxy(60,13);
	printf("�A��� ���|�P");
	
	int hold ; 
	
	switch(a){
		case 1 :
				if(player==1)
				{
					*playermoney += 10000;	
					printplayer1money(*playermoney);
				}
				else if (player==2) {
					*playermoney += 10000;
					printplayer2money(*playermoney);
				}
				printf("\a");
				MessageBox(0,"�A�o�� 10000 ��!!","���|",0);
				
				break;
		
		case 2 :if(player==1)
				{
					*playermoney -= 10000;	
					printplayer1money(*playermoney);
				}
				else if (player==2) {
					*playermoney -= 10000;
					printplayer2money(*playermoney);
				}
				printf("\a");
				MessageBox(0,"�A���h 10000 ��!!","���|",0);
				break;
		
		case 3 :
	         	if(player==1)
				{
					*playermoney += 5000;	
					printplayer1money(*playermoney);
				}
				else if (player==2) {
					*playermoney += 5000;
					printplayer2money(*playermoney);
				}
				printf("\a");
				MessageBox(0,"�A�o�� 5000 ��!!","���|",0); 
			
				break;
		
		case 4 : hold= *oplayermoney ;
				 *oplayermoney = *playermoney ;
				 *playermoney = hold ;
				if(player==1){
						printplayer1money(*playermoney);
						printplayer2money(*oplayermoney);
				}
				else if (player==2){
					printplayer1money(*oplayermoney);
					printplayer2money(*playermoney);
				}
				printf("\a");
				MessageBox(0,"�A�o�� 10000 ��!!","���|",0);
				 
				break;
		
		case 5 : *oplayermoney -= 5000;
				if(player==1)printplayer2money(*oplayermoney);
				else if (player==2)printplayer1money(*oplayermoney);
				printf("\a");
				MessageBox(0,"����F5000��!!","���|",0);
				
				break;
		
		case 6 : *oplayermoney += 5000;
				if(player==1)printplayer2money(*oplayermoney);
				else if (player==2)printplayer1money(*oplayermoney);
				printf("\a");
				MessageBox(0,"����F10000��!!","���|",0);
				
				break;
		
	}
}

void changeplayer(int *pt1 , int *pt2)
{
	*pt1 = 0 ;
	*pt2 = 1 ;
		
}

void fee(int player, int *playermoney , int *oplayermoney, int oplayerland[], int position)
{
	for (int x = 0 ; x<19 ; x++)
	{
		if (oplayerland[x]-1 == position)
		{
			*playermoney -= (land_price[position] / 5);
			*oplayermoney += (land_price[position] / 5);
			
			if(player==1)	printplayer1money(*playermoney);
			else printplayer2money(*playermoney);
			
			gotoxy(60,13);
			printf("�A�I�F %d �� ��@�L���O",(land_price[position] / 5) );
			
			break ; 
		}
	}
}

void buyfunc(int player ,int position, int land_bought[] , int *playermoney, int playerland[] )
	{
		int *b = &land_bought[position];
		int j2=0 ;
		
				
			if(land_bought[position]==0 && land_price[position]!=0)
			{
				char a;
				gotoxy(60,13);
				printf("���g�a�i�H�Q�ʶR ���欰 %d ��   ",land_price[position]);
				gotoxy(60,14);
				printf("�z�n�ʶR��? ( 1 for yes , 2 for no)");
				while(j2==0){
						
				gotoxy(43,37);
				scanf("%c",&a);
				gotoxy(43,37);
				printf("    ");
				
				if(a=='1')
				{
					*b = 1;
					*playermoney -= land_price[position];
					
					if(player==1) printplayer1money(*playermoney);
					else if (player == 2) printplayer2money(*playermoney);				
		
				for(int x = 0 ; x<19 ; x++)
				{
					if (playerland[x]==0)
				{	
					int *p = &playerland[x];
				  	*p = position + 1 ;
					
				
						gotoxy(positionxy[position][0],positionxy[position][1]-1);
						if(player==1)printf("P1����g");
						else printf("P2����g");
						
					gotoxy(60,15);
					printf("�A�w�g�R�U�F: %s ", land[position]);
					j2++;
					break;
					}
					
					
					}
			}						
			
				else if(a=='2')
				{
					gotoxy(60,15);
					printf("�z�ڵ��ʶR");
					j2++;
				}
			}
		}
			else if (position==0)
			{
				
				gotoxy(60,13);
				printf("���g�a���i�Q�ʶR");     //�_�I����Q�ʶR 
			}
		
	}

void print(void)
{
	gotoxy(52,14);
	printf("\t\t       �C���W�h\n");
	gotoxy(52,15);
	printf("\t\t               \n");
	gotoxy(44,16);
	cout<< "1. ���H�C��";
	gotoxy(44,17);
	cout<< "2. �C�H��l��m��'�Ȯa�ǰ|' ��l�]����20000�� ";
	gotoxy(44,18);
	cout<< "3. �C���̭Y�����������B�g�a�i�Q�ʶR �h�i�H�i����  " ;
	gotoxy(44,19);
	cout<< "4. �Y�C���̲��ʨ�t�@��C���̪��g�a �h�w�u�����g�a���檺�������@���L���O"; 
	gotoxy(44,20);
	cout<< "5. ���C�����]�m'���|' '�R�B'";
	gotoxy(44,21);
	cout<< "6. �u�n��C���̪�������s �h�ߧY�ѥ_"; 
	gotoxy(44,22);
	cout<< "8. ��a �� Ĺ�a �Y���J�O�p�w�ܤ@��!! " ;
	gotoxy(44,23);
	
}


void rowdicemusic(void)
{ 
int Delay = 200;
short Hz[] = { 0, 131, 147, 165, 175, 196, 220, 247, 262, 294, 330, 349, 392, 440, 494, 523, 659, 698, 783, 880, 988, };
char Tone[] = { 8,9,10,11,12,0 }, *t;
float Beat[] = { .5f,.5f,.5f,.6f,.8f,-1.f}, *b;
t = Tone; b = Beat;
while (*b >= 0)
if (*t) Beep(Hz[*t++], *b++ * Delay);
else { Sleep(*b++ * Delay); t++; }


}

void changeplayercar(int *playercar)  
{
	if(*playercar== 0 ) *playercar = 1;
	else *playercar = 0 ;
}
void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos;
    scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
}
void delay(int time)
{
    clock_t now=clock();
    while(clock()-now<time);
}

void printplayer1position(int player1)
{
	gotoxy(positionxy[player1][0],positionxy[player1][1]);
	printf("P1");
	gotoxy(0,40);
}
void printplayer2position(int player2)
{
	gotoxy(positionxy[player2][0]+5,positionxy[player2][1]);
	printf("P2");
	gotoxy(0,40);
}

void printplayer1money(int playermoney1)    
{
	gotoxy(12,13);
	printf("%d    ",playermoney1);
	gotoxy(0,40);
}
void printplayer2money(int playermoney2)
{
	gotoxy(148,13);
	printf("%d    ",playermoney2);
	gotoxy(0,40);
}

void clear1(void)
{
		for (int x = 0 ; x < 20 ; x++){
			gotoxy(60,9+x);
			printf("                                   ");
		}
	
}

void dicedisplay(int a)
{
	
	switch(a){
		

case 1:	 
gotoxy(100,22);  
printf(" ______________ ");
gotoxy(100,23);
printf("|              |");
gotoxy(100,24);
printf("|              |");
gotoxy(100,25);
printf("|     @@@@     |");
gotoxy(100,26);
printf("|    @@@@@@    |");
gotoxy(100,27);
printf("|     @@@@     |");
gotoxy(100,28);
printf("|              |");
gotoxy(100,29);
printf("|______________|");
break;

case 2 :
gotoxy(100,22);
printf(" ______________ ");
gotoxy(100,23);
printf("|              |");
gotoxy(100,24);
printf("|        @@@@  |");
gotoxy(100,25);
printf("|        @@@@  |");
gotoxy(100,26);
printf("|              |");
gotoxy(100,27);
printf("|  @@@@        |");
gotoxy(100,28);
printf("|  @@@@        |");
gotoxy(100,29);
printf("|______________|");
break;

case 3 :
gotoxy(100,22);
printf(" ______________ ");
gotoxy(100,23);
printf("|              |");
gotoxy(100,24);
printf("|  @@          |");
gotoxy(100,25);
printf("|  @@          |");
gotoxy(100,26);
printf("|      @@      |");
gotoxy(100,27);
printf("|      @@  @@  |");
gotoxy(100,28);
printf("|          @@  |");
gotoxy(100,29);
printf("|______________|");
break;

case 4:
gotoxy(100,22);
printf(" ______________ ");
gotoxy(100,23);
printf("|              |");
gotoxy(100,24);
printf("|   @@@   @@@  |");
gotoxy(100,25);
printf("|   @@@   @@@  |");
gotoxy(100,26);
printf("|              |");
gotoxy(100,27);
printf("|   @@@   @@@  |");
gotoxy(100,28);
printf("|   @@@   @@@  |");
gotoxy(100,29);
printf("|______________|");
break;

case 5 :
gotoxy(100,22);
printf(" ______________ ");
gotoxy(100,23);
printf("|              |");
gotoxy(100,24);
printf("|  @@      @@  |");
gotoxy(100,25);
printf("|              |");
gotoxy(100,26);
printf("|      @@      |");
gotoxy(100,27);
printf("|              |");
gotoxy(100,28);
printf("|  @@      @@  |");
gotoxy(100,29);
printf("|______________|");
break;

case 6 :
gotoxy(100,22);
printf(" ______________ ");
gotoxy(100,23);
printf("|              |");
gotoxy(100,24);
printf("|  @@@    @@@  |");
gotoxy(100,25);
printf("|              |");
gotoxy(100,26);
printf("|  @@@    @@@  |");
gotoxy(100,27);
printf("|              |");
gotoxy(100,28);
printf("|  @@@    @@@  |");
gotoxy(100,29);
printf("|______________|");
break;

}
}

void runbike(int player , int kind)
{
	int plus = 0 ;
	if(player==2) plus+=135 ;

	
	switch(kind){
		
	case 0 :
	gotoxy(3+plus,23);	
	printf("           `@@@         \n");
	gotoxy(3+plus,24);
	printf("          @@@@@@;       \n");
	gotoxy(3+plus,25);
	printf("          '@@@#         \n");
	gotoxy(3+plus,26);
	printf("     ,@@@@@@@@@@#       \n");
	gotoxy(3+plus,27);
	printf("   @@@  @@@@@@@@@@#     \n");
	gotoxy(3+plus,28);
	printf("  @@@  @@@@@@@    `@@@@@\n");
	gotoxy(3+plus,29);
	printf("   `  @@@@@@@@+         \n");
	gotoxy(3+plus,30);
	printf("     +@@@@ `'@@@@#`     \n");
	gotoxy(3+plus,31);
	printf("    @@@@@      @@@@@    \n");
	gotoxy(3+plus,32);
	printf("  @@@@@         @@@@.   \n");
	gotoxy(3+plus,33);
	printf("#@@@@            @@@@   \n");
	gotoxy(3+plus,34);
	printf("________________________\n");
	break;
	
	case 1:
	gotoxy(3+plus,23);                     
	printf("        .,,             ");
	gotoxy(3+plus,24);
	printf("       .;      #@@.     ");
	gotoxy(3+plus,25);
	printf("        @       @       ");
	gotoxy(3+plus,26);
	printf("       ;@@@@@@@@@       ");
	gotoxy(3+plus,27);
	printf("       #@,     @@       ");
	gotoxy(3+plus,28);
	printf("  +#,'@,`@,   @  @';#'` ");
	gotoxy(3+plus,29);
	printf(" :;  :;@ `@'  @ @@, `', ");
	gotoxy(3+plus,30);
	printf(" @   @`:;  +@@'+, @   @ ");
	gotoxy(3+plus,31);
	printf(" @  @  .;   @@@@@@@@  @ ");
	gotoxy(3+plus,32);
	printf(" @     ;;   .         @ ");
	gotoxy(3+plus,33);
	printf("  @    @        @    @` ");
	gotoxy(3+plus,34);
	printf("__;@;+# ________ @';@'__");
	break;
	
}
}

void getbike(int *playercar, int player){
	if(*playercar==0){
		int a ;
		srand(time(NULL));
		a = (rand()%10)+1;
		if(a==1){
		*playercar=1;
		runbike(player, 1);	
		printf("\a");
	MessageBox(0,"���ߧA�M��\"�p��\"�o!!","�N�~���o�{",0);
	}
	
}
}

void losebike(int *playercar, int player)
{
	if(*playercar==1){
		int a ;
		srand(time(NULL));
		a = (rand()%5)+1;
		if(a==3){
		*playercar=0;
		runbike(player, 0);
		printf("\a");	
		MessageBox(0,"SORRY�A��\"�p��\"�a���o!!","���i�ʪ��",0);
	}
	
}
}
						

