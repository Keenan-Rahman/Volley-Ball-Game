#include <allegro.h>
#include "background.h"
#include <string>
using namespace std;

#define ScreenWidth 1200
#define ScreenHeight 600


bool BackgroundSelect::KeyPressbackb(int keyValue)			//check key press
		{
			if(keypressb==keyValue && prevkeypressb!=keyValue)
				return true;
			
			return false;
		}

bool BackgroundSelect::Keyrealsedbackb(int keyValue)				//check last key press
		{
			if(keypressb!=keyValue && prevkeypressb==keyValue)
				return true;
			
			return false;
		}
int BackgroundSelect::selector()
{
				
	backs[0]="CLOUDY BACKGROUND";
	backs[1]="SUNNY BACKGROUND";
	doneb=true;
	
	BITMAP *buffer=create_bitmap(ScreenWidth,ScreenHeight);				//make bitmap
	int value=0;
	int select=0;
	FONT *Font11=load_font("option.pcx",NULL,NULL);
	while(1)
	{
		textout_centre_ex(screen,font,"Press Backspace To see Menu",150,590,makecol(44,117,255),-1);
		if(key[KEY_BACKSPACE])
		{
			return 3;
		}
		prevkeypressb=keypressb;
		for(int i=0 ; i< KEY_MAX ; i++)				// for key press
		{
			if(key[i])
			{
				keypressb=i;
				break;
			}
			else
			keypressb=NULL;
		
		}
		if(Keyrealsedbackb(KEY_DOWN))				// check down key
		{
			selectb++;
		}
		else if(KeyPressbackb(KEY_UP))			//check up key
		{
			selectb--;
		}
		if(selectb<0)			//keep in range
		{
			selectb=0;
		}					
		
		if(selectb>1)			//keep in range
		{
			selectb=1;
		}
			
		valueb=selectb;
		textout_centre_ex(buffer,Font11,"SELECT BACKGROUND",ScreenWidth/2,100,makecol(255,0,0),-1);
		textout_centre_ex(screen,font,"Press Backspace To see Menu",150,590,makecol(44,117,255),-1);
		textout_centre_ex(screen,font,"Press SpaceBar to Continue",600,590,makecol(44,117,255),-1);
		for(int i=0 ; i<2 ; i++)			//print the menu 
		{
			if(i==selectb)
			{
				continue;
			}
			textout_centre_ex(buffer,Font11,backs[i].c_str(),ScreenWidth/2,(i+1)*200,makecol(255,0,0),-1);
			if(i==0)
			{
				BITMAP *back1  = load_bitmap("see1.bmp",NULL);	    
				masked_blit(back1, buffer, 0, 0, 500, 220, 200,100);
			}
			if(i==1)
			{
				BITMAP *back1  = load_bitmap("see2.bmp",NULL);	    
				masked_blit(back1, buffer, 0, 0, 500, 420, 200,100);
			}
		}
		textout_centre_ex(buffer,Font11,backs[selectb].c_str(),ScreenWidth/2,(selectb+1)*200,makecol(255,255,0),-1);			// highlight the selected item
		if(selectb==0)			//load small image
		{
			BITMAP *back1  = load_bitmap("see1.bmp",NULL);	    
			masked_blit(back1, buffer, 0, 0, 500, 220, 200,100);

		}
		if(selectb==1)			//load small image
		{
			BITMAP *back1  = load_bitmap("see2.bmp",NULL);	    
			masked_blit(back1, buffer, 0, 0, 500, 420, 200,100);				
			
		}
					
							
		blit(buffer,screen,0,0,0,0,1200,600);
		if(key[KEY_SPACE])			//when u select an option
		{
			if (selectb==0)		//background 1
			{	
				destroy_bitmap(buffer);
				destroy_font(Font11);
				return 1;
			}
			if (selectb==1)			//background 2
			{
				destroy_bitmap(buffer);
				destroy_font(Font11);
				return 2;
			}
		}
	}
}
