#include<stdio.h>
#include <time.h>
#include <iostream>
#include <windows.h>
#define SIZE 22
using namespace std;

const char *land[SIZE] = {"客家學院","中大湖","理學院","語言中心","鬆餅屋","命運","校長官邸","打氣站",
						  "中大校門","禮  堂","遊藝館","男十三舍","敦煌書局","女十四舍","宵夜街","男三舍",
						  "機會","女一到四","通訊系館","依仁堂","籃球場","游泳池",}; 

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
	int playerland1[19]={0}, playerland2[19]={0} ;                // 0 代表沒有  1代表A  2代表B .....  全部加1 
	int land_bought[SIZE] = {0};                                  // 表示哪些土地已被購買 
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
			cout<<"請遊戲者1 擲骰                  ";
			
			
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
			cout<<"請遊戲者2 擲骰               ";
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
		MessageBox(0,"遊戲者1沒摳摳了呦~\n\n~~~~~~遊戲者2 獲勝!!~~~~~~","遊戲結束",0);
		else if (playermoney2<=0)
		MessageBox(0,"遊戲者2沒摳摳了呦~\n\n~~~~~~遊戲者1 獲勝!!~~~~~~","遊戲結束",0);
		
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
	puts("請按 'R'+'ENTER' 來決定誰先開始");
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
		printf("遊戲者1先開始!");
		*playersturn1=1 ;		
	}
	else{
		gotoxy(65,23);
		printf("遊戲者2先開始!");
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
	printf("                                |  XX客家學院XX  |  XX 中大湖 XX  |  XX 理學院 XX  |  XX語言中心XX  |  XX 鬆餅屋 XX  |  XX  命運  XX  |                                \n");
	printf("                                |                |                |                |                |                |                |                                \n");
	printf("       @@@@@#      @@@@         |                |                |                |                |                |                |        @@@@@#      @@@@@       \n");
	printf("       @@  @@      @@@@         |________________|________________|________________|________________|________________|________________|        @@  @@     @@  @@@      \n");
	printf("       @@  @@       @@@         |                |                                                                   |                |        @@  @@        .@@       \n");
	printf("       @@@@@        @@@         |  XX 游泳池 XX  |                                                                   |  XX校長官邸XX  |        @@@@@       .@@         \n");
	printf("       @@           @@@         |                |                                                                   |                |        @@         @@@          \n");
	printf("       @@           @@@         |                |                                                                   |                |        @@        @@@           \n");
	printf("       @@          @@@@@        |________________|                                                                   |________________|        @@       ;@@@@@@@       \n");
	printf("                                |                |                                                                   |                |                                \n");
	printf("                                |  XX 籃球場 XX  |                                                                   |  XX 打氣站 XX  |                                \n");
	printf("     金錢 :                     |                |                                                                   |                |      金錢 :                    \n");
	printf("                                |                |                                                                   |                |                                \n");
	printf("                                |________________|                                                                   |________________|                                \n");
	printf("                                |                |                                                                   |                |                                \n");	                                              
	printf("                                |  XX 依仁堂 XX  |                                                                   |  XX中大校門XX  |                                \n");
	printf("                                |                |                                                                   |                |                                \n");
	printf("                                |                |                                                                   |                |                                \n"); 
	printf("                                |________________|                                                                   |________________|                                \n");
	printf("                                |                |                                                                   |                |                                \n");	                                                               
	printf("  ____________________________  |  XX通訊系館XX  |                                                                   |  XX 禮  堂 XX  |  ____________________________  \n");
	printf(" |                            | |                |                                                                   |                | |                            | \n");
	printf(" |                            | |                |                                                                   |                | |                            | \n"); 
	printf(" |                            | |________________|                                                                   |________________| |                            | \n");
	printf(" |                            | |                |                                                                   |                | |                            | \n");
	printf(" |                            | |  XX女一到四XX  |                                                                   |  XX 遊藝館 XX  | |                            | \n");
	printf(" |                            | |                |                                                                   |                | |                            | \n");
	printf(" |                            | |                |                                                                   |                | |                            | \n"); 
	printf(" |                            | |________________|___________________________________________________________________|________________| |                            | \n");
	printf(" |                            | |                |                |                |                |                |                | |                            | \n");
	printf(" |                            | |  XX  機會  XX  |  XX 男三舍 XX  |  XX 宵夜街 XX  |  XX女十四舍XX  |  XX敦煌書局XX  |  XX男十三舍XX  | |                            | \n");
	printf(" |                            | |                |                |                |                |                |                | |                            | \n");
	printf(" |____________________________| |                |                |                |                |                |                | |____________________________| \n");
	printf("                                |________________|________________|________________|________________|________________|________________|                                \n");
	
	gotoxy(0,37);
	printf("                                輸入者指令:");
	

	

}

void movepos(int play, int *pyr,int player1 ,int player2 , int playerturn1, int playerturn2 , int *playermoney1 , int *playermoney2, int playerland1[] , int playerland2[], int land_bought[],int playercar)
{
	int dicef(int playercar);
	int judge = 0;
	int t ;
	gotoxy(60,10);
	cout<<"請按 'R'+'ENTER'!!  ";
	
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
	 cout<<"你的目前位置為 "<< land[*pyr] ;
	  

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
		printf("你得到 %d",a);
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
		printf("你得到 %d",a);
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
	printf("你抽到 命運牌");
	
	switch(a){
		case 1 : *position = 0 ;
				  gotoxy(positionxy[5][0]+qw,positionxy[5][1]);
				  printf("  ");
				  gotoxy(positionxy[0][0]+qw,positionxy[0][1]);
				  if(player==1)printf("P1");
	 		   	  else if (player==2)printf("P2");
				  printf("\a");
				 MessageBox(0,"回家抱媽媽啦 掰掰!!","命運",0); 
				 
				 break;
				 
		case 2 :  *position-= 3 ;
				gotoxy(positionxy[5][0]+qw,positionxy[5][1]);
				  printf("  ");
				  gotoxy(positionxy[2][0]+qw,positionxy[2][1]);
				  if(player==1)printf("P1");
	 		   	  else if (player==2)printf("P2");
				printf("\a");
				MessageBox(0,"倒退三格","命運",0);
				break;
				
		case 3 : *position += 2 ;
				gotoxy(positionxy[5][0]+qw,positionxy[5][1]);
				  printf("  ");
				  gotoxy(positionxy[7][0]+qw,positionxy[7][1]);
				  if(player==1)printf("P1");
	 		   	  else if (player==2)printf("P2");
	 		   	  printf("\a");
	 		   	  MessageBox(0,"前進兩格","命運",0);
				
				break;
				
		case 4 :  *position += 4 ;
			gotoxy(positionxy[5][0]+qw,positionxy[5][1]);
			printf("  ");
				  gotoxy(positionxy[9][0]+qw,positionxy[9][1]);
				  if(player==1)printf("P1");
	 		   	  else if (player==2)printf("P2");
	 		   	  printf("\a");
	 		   	  MessageBox(0,"前進四格","命運",0);
			
			
				break;
	}
	
}

void opport (int player, int *playermoney, int *oplayermoney)
{
	int a ;
	
	srand(time(NULL));
	a = (rand()%6)+1;
	
	gotoxy(60,13);
	printf("你抽到 機會牌");
	
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
				MessageBox(0,"你得到 10000 元!!","機會",0);
				
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
				MessageBox(0,"你失去 10000 元!!","機會",0);
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
				MessageBox(0,"你得到 5000 元!!","機會",0); 
			
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
				MessageBox(0,"你得到 10000 元!!","機會",0);
				 
				break;
		
		case 5 : *oplayermoney -= 5000;
				if(player==1)printplayer2money(*oplayermoney);
				else if (player==2)printplayer1money(*oplayermoney);
				printf("\a");
				MessageBox(0,"對手輸了5000元!!","機會",0);
				
				break;
		
		case 6 : *oplayermoney += 5000;
				if(player==1)printplayer2money(*oplayermoney);
				else if (player==2)printplayer1money(*oplayermoney);
				printf("\a");
				MessageBox(0,"對手輸了10000元!!","機會",0);
				
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
			printf("你付了 %d 元 當作過路費",(land_price[position] / 5) );
			
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
				printf("此土地可以被購買 價格為 %d 元   ",land_price[position]);
				gotoxy(60,14);
				printf("您要購買嗎? ( 1 for yes , 2 for no)");
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
						if(player==1)printf("P1的領土");
						else printf("P2的領土");
						
					gotoxy(60,15);
					printf("你已經買下了: %s ", land[position]);
					j2++;
					break;
					}
					
					
					}
			}						
			
				else if(a=='2')
				{
					gotoxy(60,15);
					printf("您拒絕購買");
					j2++;
				}
			}
		}
			else if (position==0)
			{
				
				gotoxy(60,13);
				printf("此土地不可被購買");     //起點不能被購買 
			}
		
	}

void print(void)
{
	gotoxy(52,14);
	printf("\t\t       遊戲規則\n");
	gotoxy(52,15);
	printf("\t\t               \n");
	gotoxy(44,16);
	cout<< "1. 雙人遊戲";
	gotoxy(44,17);
	cout<< "2. 每人初始位置為'客家學院' 初始財產為20000元 ";
	gotoxy(44,18);
	cout<< "3. 遊戲者若有足夠金錢且土地可被購買 則可以進行交易  " ;
	gotoxy(44,19);
	cout<< "4. 若遊戲者移動到另一位遊戲者的土地 則針酌收取土地價格的五分之一的過路費"; 
	gotoxy(44,20);
	cout<< "5. 本遊戲有設置'機會' '命運'";
	gotoxy(44,21);
	cout<< "6. 只要當遊戲者的錢等於零 則立即敗北"; 
	gotoxy(44,22);
	cout<< "8. 輸家 請 贏家 吃巧克力小泡芙一盒!! " ;
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
	MessageBox(0,"恭喜你騎到\"小綠\"囉!!","意外的發現",0);
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
		MessageBox(0,"SORRY你的\"小綠\"壞掉囉!!","掉進百花穿",0);
	}
	
}
}
						

