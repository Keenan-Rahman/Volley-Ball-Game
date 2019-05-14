#include <allegro.h>

#include "header.h"
#include "credit.h"
#include "character.h"
#include "instruction.h"

#define ScreenWidth 1200
#define ScreenHeight 600


void MainClass::GameSetting()
{
	done=true;
	options[0]="New Game";
	options[1]="Instructions";
	options[2]="Credits";
	options[3]="Exit";
	set_window_title("VOLLEY BALL GAME");
}
void MainClass::Title()
{
	BITMAP *buffer=create_bitmap(ScreenWidth,ScreenHeight);				//make bitmap
	int count=0;
	FONT *Font1=load_font("Mainstart.pcx",NULL,NULL);			//add font style
	string heading="VOLLEY BALL GAME";						// heading to print on screen
	string set="";
	int x,y;
	int red, green, blue, color;	
	int k=0;
	srand(time(0));
	SAMPLE *mymusic = load_sample("gamestart.wav");
	play_sample(mymusic, 255, 127 ,1000,true); //play sound	
	while(k<=400)			//screen start pixel color
	{
		
		x = 10 + rand() % (SCREEN_W-20);
		y = 10 + rand() % (SCREEN_H-20);
		red = rand() % 255;
		green = rand() % 255;
		blue = rand() % 255;
		color = makecol(red,green,blue);
		putpixel(buffer, x, y, color);					//colors pixel
		blit(buffer,screen,0,0,0,0,ScreenWidth,ScreenHeight);
		k++;
		rest(10);
	}
	destroy_sample(mymusic);			//destroy music
	destroy_bitmap(buffer);
	SAMPLE *title = load_sample("title.wav");
	play_sample(title, 255, 127 ,1000,true); 						//play sound	
	BITMAP *buffer1=create_bitmap(ScreenWidth,ScreenHeight);				//make bitmap
	BITMAP *start = load_bitmap("start.bmp", NULL);
	masked_blit(start, buffer1, 0, 0, 0, 0, start->w, start->h);
	while(count<heading.length())					// loop print heading one by one
	{
		
		masked_blit(start, buffer1, 0, 0, 0, 0, start->w, start->h);
		set+=heading[count];
		count++;
		textout_centre_ex(buffer1, Font1,set.c_str(),SCREEN_W / 2, SCREEN_H / 2,makecol(44,117,255),-1);
		blit(buffer1,screen,0,0,0,0,ScreenWidth,ScreenHeight);
		rest(200);
		clear_bitmap(buffer);
	}
	textout_centre_ex(screen, Font1,set.c_str(),SCREEN_W / 2, SCREEN_H / 2,makecol(44,117,255),-1);
	rest(1000);
	destroy_sample(title);
	destroy_font(Font1);			//destroy everything so memory leak is not caused
	clear_bitmap(screen);
}
bool MainClass::KeyPress(int keyValue)				//check key press
{
	if(keypress==keyValue && prevkeypress!=keyValue)
		return true;
	
	return false;
}

bool MainClass::Keyrealsed(int keyValue)		//check previous key press
{
	if(keypress!=keyValue && prevkeypress==keyValue)
		return true;
	
	return false;
}


int MainClass::OptionSelect()					//function to have menu
{
	start:
	BITMAP *buffer=create_bitmap(ScreenWidth,ScreenHeight);				//make bitmap
	BITMAP *start = load_bitmap("opt.bmp", NULL);
	masked_blit(start, buffer, 0, 0, 0, 0, start->w, start->h);
	options[0]="New Game";
	options[1]="Instructions";
	options[2]="Credits";
	options[3]="Exit";
	FONT *Font8=load_font("option.pcx",NULL,NULL);				//load font
	done=true;
	int value=0;
	int select=0;
	while(done)					//loop of option
	{
		if(key[KEY_ESC])
		{
			done=false;
		}
		prevkeypress=keypress;
		for(int i=0 ; i< KEY_MAX ; i++)
		{
			if(key[i])
			{	
				keypress=i;
				break;
			}
			else
			keypress=NULL;
	
		}
		if(Keyrealsed(KEY_DOWN))				// check down key
		{
			select++;
		}
		else if(KeyPress(KEY_UP))			//check up key
		{
			select--;
		}
		if(select<0)			//check range
		{
			select=0;
		}					
			
		if(select>3)				//check range
		{
			select=3;
		}
			
		value=select;
		for(int i=0 ; i<4 ; i++)			//print the menu 
		{
			if(i==select)
			{
				continue;
			}
			textout_centre_ex(buffer,Font8,options[i].c_str(),ScreenWidth/2,(i+1)*75,makecol(255,0,0),-1);
		}
		textout_centre_ex(buffer,Font8,options[select].c_str(),ScreenWidth/2,(select+1)*75,makecol(255,255,0),-1);			// highlight the selected item
		blit(buffer,screen,0,0,0,0,ScreenWidth,ScreenHeight);
		if(key[KEY_ENTER])			//when u select an option
		{
			if (select==0)		//new game
			{
				destroy_font(Font8);
				destroy_bitmap(buffer);
				Character CM1;
				int s=CM1.backgr();
								//check background
				CM1.Movement();			//call game function if returns 2
				goto start;
			}
			if (select==1)			//instructions
			{
				INM->howtoplay();
				goto start;
			}
			if (select==2)				//credits
			{
				CM->view();
				goto start;
			}
			if (select==3)			//exit game
			{
				destroy_bitmap(buffer);
				allegro_exit();
			}
		}
	}
	destroy_bitmap(buffer);
}

