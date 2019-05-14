#include <allegro.h>
#include <string>
#include "instruction.h"
#define ScreenWidth 1200
#define ScreenHeight 600



void Instructions::howtoplay()
{
	bool loop=true;
	string line0="INSTRUCTIONS";
	string line1="Keys For Player 1:";											//instructions
	string line2="Press UP key to jump, Press LEFT key to move left, Press RIGHT key to move right";								//instructions
	string line3="Keys For Player 2:";								//instructions
	string line4="Press W key to jump, Press A key to move left, Press D key to move right";								//instructions
	string line5="This is a Volleyball game. Don't let the ball to fall on the ground.";								//instructions
	string line6="Hit the ball to throw it to your opponent side. First too score 5 goals is Winner.";								//instructions
	textout_centre_ex(screen,font,"Press Backspace To see Menu",150,590,makecol(44,117,255),-1);		//back to menu
				
	FONT *Font2=load_font("credits.pcx",NULL,NULL);
	FONT *Font3=load_font("instruction.pcx",NULL,NULL);
	BITMAP *buffer=create_bitmap(ScreenWidth,ScreenHeight);
	clear_bitmap(screen);
	while(loop)					//displaying the instructions
	{
		if(key[KEY_ESC])
		{
			loop=false;
		}
		textout_centre_ex(screen,font,"Press Backspace To see Menu",150,590,makecol(44,117,255),-1);				
		textout_centre_ex(screen,Font2,line0.c_str(),450,(ScreenHeight/6),makecol(44,117,255),-1);			
		textout_ex(screen,Font3,line1.c_str(),0,(ScreenHeight/6)+50,makecol(44,117,255),-1);			//write on screen
		textout_ex(screen,Font3,line2.c_str(),0,(ScreenHeight/6)+70,makecol(44,117,255),-1);			//write on screen
		textout_ex(screen,Font3,line3.c_str(),0,(ScreenHeight/6)+120,makecol(44,117,255),-1);			//write on screen
		textout_ex(screen,Font3,line4.c_str(),0,(ScreenHeight/6)+140,makecol(44,117,255),-1);			//write on screen
		textout_ex(screen,Font3,line5.c_str(),0,(ScreenHeight/6)+200,makecol(44,117,255),-1);			//write on screen
		textout_ex(screen,Font3,line6.c_str(),0,(ScreenHeight/6)+230,makecol(44,117,255),-1);			//write on screen
		if(key[KEY_BACKSPACE])			//go back to menu
		{
			goto m;		
		}
	}
	m:
	destroy_font(Font2);			//destroy everything so memory leak is not caused
	destroy_font(Font3);			//destroy everything so memory leak is not caused
	destroy_bitmap(buffer);
}

