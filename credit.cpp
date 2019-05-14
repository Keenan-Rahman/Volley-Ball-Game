#include <allegro.h>
#include "credit.h"
#define ScreenWidth 1200
#define ScreenHeight 600


void Credits::view()
{
	clear_bitmap(screen);
	string credit[50]={"Developers","  ","Keenan Rahman","Arslan Khalid","Ahmed Ali Sabir","  ","  ","  ","Sound","  ","Keenan Rahman","  ","  ","  ","Background","  ","Arslan Khalid","  ","  ","  ","Special Thanks To","  ","Proffessor Kahsif Khan","  ","  ","  ","THANKYOU FOR PLAYING","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "};
	int position[50][2];
	for(int i=0 ; i<50 ; i++)
	{
		position[i][0]=ScreenWidth/2;
		position[i][1]=ScreenHeight+10;
	}
	string space="    ";
	int direction[1][2]={ScreenWidth/2,ScreenHeight+10};				//position of credits
	BITMAP *buffer=create_bitmap(ScreenWidth,ScreenHeight-20);			//form buffer
	FONT *Font2=load_font("credits.pcx",NULL,NULL);					//load font
	int j=1;
	for(int i=0 ; i<50 ; i++)			//print the credits
	{
		clear_bitmap(buffer);
		for(int k=0 ; k<i ; k++)
			{
				textout_centre_ex(screen,font,"Press Backspace To see Menu",150,590,makecol(44,117,255),-1);
				textout_centre_ex(buffer,Font2,credit[k].c_str(),position[k][0],position[k][j]-=30,makecol(44,117,255),-1);			//credits
				blit(buffer,screen,0,0,0,0,ScreenWidth,ScreenHeight);
				if(k+1==i)			//rest
				{
					rest(200);	
				}
				if(key[KEY_ESC])		//break
				{	
					break;
				}
				if(key[KEY_BACKSPACE])			//goto menu
				{
					goto n;
				}
				
					
			}
	}
	n:
	destroy_font(Font2);			//destroy everything so memory leak is not caused
	destroy_bitmap(buffer);
}


