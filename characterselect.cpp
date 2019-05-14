#include <allegro.h>
#include "characterselect.h"
#include <string>
using namespace std;

#define ScreenWidth 1200
#define ScreenHeight 600


bool CharacterSelect::KeyPressbackc(int keyValue)			//check key press
{
	if(keypressc==keyValue && prevkeypressc!=keyValue)
		return true;
	
	return false;
}

bool CharacterSelect::Keyrealsedbackc(int keyValue)				//check last key press
{
	if(keypressc!=keyValue && prevkeypressc==keyValue)
		return true;
		
	return false;
}


int CharacterSelect::selectcharl()
{
	
				
	characters[0]="JEGURA";				//name
	characters[1]="CHOLRA";				//name
	characters[2]="SIROON";				//name
	characters[3]="DAMUZA";				//name
	characters[4]="SINGEERA";				//name
	characters[5]="FEERANGA";				//name
	donec=true;
	
	BITMAP *buffer=create_bitmap(ScreenWidth,ScreenHeight);				//make bitmap
	int valuec=0;
	int selectc=0;
	FONT *Font11=load_font("option.pcx",NULL,NULL);				//font
	while(1)
	{
		if(key[KEY_BACKSPACE])						//back to menu
		{
			return 7;
		}
		textout_centre_ex(screen,font,"Press Backspace To see Menu",150,590,makecol(44,117,255),-1);
		prevkeypressc=keypressc;
		for(int i=0 ; i< KEY_MAX ; i++)				// for key press
		{
			if(key[i])
			{
				keypressc=i;
				break;
			}
			else
			keypressc=NULL;
		
		}
		if(Keyrealsedbackc(KEY_DOWN))				// check down key
		{
			selectc++;
		}
		else if(KeyPressbackc(KEY_UP))			//check up key
		{
			selectc--;
		}
		if(selectc<0)			//keep in range
		{
			selectc=0;
		}					
		
		if(selectc>5)			//keep in range
		{
			selectc=5;
		}
			
		valuec=selectc;
		textout_centre_ex(screen,font,"Press Backspace To see Menu",150,590,makecol(44,117,255),-1);
		textout_centre_ex(screen,font,"Press ENTER to Continue",600,590,makecol(44,117,255),-1);
		for(int i=0 ; i<6 ; i++)			//print the menu 
		{
			textout_centre_ex(buffer,Font11,"SELECT PLAYER LEFT",ScreenWidth/2,50,makecol(255,0,0),-1);
			if(i==selectc)
			{
				continue;
			}
			textout_centre_ex(buffer,Font11,characters[i].c_str(),ScreenWidth/2,(i+1)*80,makecol(255,0,0),-1);
			if(i==0)					//player 1
			{
				BITMAP *back1  = load_bitmap("manf.bmp",NULL);	    
				masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(i+1)*80, 64,64);
			}
			if(i==1)					//player 2
			{
				BITMAP *back1  = load_bitmap("manf1.bmp",NULL);	    
				masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(i+1)*80, 64,64);
			}
			
			if(i==2)					//player 3
			{
				BITMAP *back1  = load_bitmap("manf2.bmp",NULL);	    
				masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(i+1)*80, 64,64);
			}
			if(i==3)					//player 4
			{
				BITMAP *back1  = load_bitmap("manf3.bmp",NULL);	    
				masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(i+1)*80, 64,64);
			}
			if(i==4)					//player 5
			{
				BITMAP *back1  = load_bitmap("manf4.bmp",NULL);	    
				masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(i+1)*80, 64,64);
			}
			if(i==5)					//player 6
			{
				BITMAP *back1  = load_bitmap("manf5.bmp",NULL);	    
				masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(i+1)*80, 64,64);
			}
		}
		textout_centre_ex(buffer,Font11,characters[selectc].c_str(),ScreenWidth/2,(selectc+1)*80,makecol(255,255,0),-1);			// highlight the selected item
		
		if(selectc==0)					//player 1
		{
			BITMAP *back1  = load_bitmap("manf.bmp",NULL);	    
			masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(selectc+1)*80, 64,64);
		}
		if(selectc==1)					//player 2
		{
			BITMAP *back1  = load_bitmap("manf1.bmp",NULL);	    
			masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(selectc+1)*80, 64,64);
		}
		
		if(selectc==2)					//player 3
		{
			BITMAP *back1  = load_bitmap("manf2.bmp",NULL);	    
			masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(selectc+1)*80, 64,64);
		}
		if(selectc==3)					//player 4
		{
			BITMAP *back1  = load_bitmap("manf3.bmp",NULL);	    
			masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(selectc+1)*80, 64,64);
		}
		if(selectc==4)					//player 5
		{
			BITMAP *back1  = load_bitmap("manf4.bmp",NULL);	    
			masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(selectc+1)*80, 64,64);
		}
		if(selectc==5)					//player 6
		{
			BITMAP *back1  = load_bitmap("manf5.bmp",NULL);	    
			masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(selectc+1)*80, 64,64);
		}
					
							
		blit(buffer,screen,0,0,0,0,1200,600);
		if(key[KEY_ENTER])			//when u select an option
		{
			if (selectc==0)					//player 1
			{	
				destroy_bitmap(buffer);
				destroy_font(Font11);
				return 1;
			}
			if (selectc==1)					//player 2
			{
				destroy_bitmap(buffer);
				destroy_font(Font11);
				return 2;
			}
			if (selectc==2)					//player 3
			{
				destroy_bitmap(buffer);
				destroy_font(Font11);
				return 3;
			}
			if (selectc==3)					//player 4
			{
				destroy_bitmap(buffer);
				destroy_font(Font11);
				return 4;
			}
			if (selectc==4)						//player 5
			{
				destroy_bitmap(buffer);
				destroy_font(Font11);
				return 5;
			}
			if (selectc==5)						//player 6
			{
				destroy_bitmap(buffer);
				destroy_font(Font11);
				return 6;
			}
		}
	}
}




int CharacterSelect::selectcharr()
{
	
				
	characters[0]="JEGURA";
	characters[1]="CHOLRA";
	characters[2]="SIROON";
	characters[3]="DAMUZA";
	characters[4]="SINGEERA";
	characters[5]="FEERANGA";
	donec=true;
	
	BITMAP *buffer=create_bitmap(ScreenWidth,ScreenHeight);				//make bitmap
	int valuec=0;
	int selectc=0;
	FONT *Font11=load_font("option.pcx",NULL,NULL);
	while(1)
	{
		if(key[KEY_BACKSPACE])				//back to menu
		{
			return 7;
		}
		textout_centre_ex(screen,font,"Press Backspace To see Menu",150,590,makecol(44,117,255),-1);
		prevkeypressc=keypressc;
		for(int i=0 ; i< KEY_MAX ; i++)				// for key press
		{
			if(key[i])
			{
				keypressc=i;
				break;
			}
			else
			keypressc=NULL;
		
		}
		if(Keyrealsedbackc(KEY_DOWN))				// check down key
		{
			selectc++;
		}
		else if(KeyPressbackc(KEY_UP))			//check up key
		{
			selectc--;
		}
		if(selectc<0)			//keep in range
		{
			selectc=0;
		}					
		
		if(selectc>5)			//keep in range
		{
			selectc=5;
		}
			
		valuec=selectc;
		textout_centre_ex(screen,font,"Press Backspace To see Menu",150,590,makecol(44,117,255),-1);
		textout_centre_ex(screen,font,"Press SpaceBar to Continue",600,590,makecol(44,117,255),-1);
		for(int i=0 ; i<6 ; i++)			//print the menu 
		{
			textout_centre_ex(buffer,Font11,"SELECT PLAYER RIGHT",ScreenWidth/2,50,makecol(255,0,0),-1);
			if(i==selectc)
			{
				continue;
			}
			textout_centre_ex(buffer,Font11,characters[i].c_str(),ScreenWidth/2,(i+1)*80,makecol(255,0,0),-1);
			if(i==0)					//player 1
			{
				BITMAP *back1  = load_bitmap("manf.bmp",NULL);	    
				masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(i+1)*80, 64,64);
			}
			if(i==1)					//player 2
			{
				BITMAP *back1  = load_bitmap("manf1.bmp",NULL);	    
				masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(i+1)*80, 64,64);
			}
			
			if(i==2)					//player 3
			{
				BITMAP *back1  = load_bitmap("manf2.bmp",NULL);	    
				masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(i+1)*80, 64,64);
			}
			if(i==3)					//player 4
			{
				BITMAP *back1  = load_bitmap("manf3.bmp",NULL);	    
				masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(i+1)*80, 64,64);
			}
			if(i==4)					//player 5
			{
				BITMAP *back1  = load_bitmap("manf4.bmp",NULL);	    
				masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(i+1)*80, 64,64);
			}
			if(i==5)					//player 6
			{
				BITMAP *back1  = load_bitmap("manf5.bmp",NULL);	    
				masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(i+1)*80, 64,64);
			}
		}
		textout_centre_ex(buffer,Font11,characters[selectc].c_str(),ScreenWidth/2,(selectc+1)*80,makecol(255,255,0),-1);			// highlight the selected item
		
		if(selectc==0)					//player 1
		{
			BITMAP *back1  = load_bitmap("manf.bmp",NULL);	    
			masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(selectc+1)*80, 64,64);
		}
		if(selectc==1)					//player 2
		{
			BITMAP *back1  = load_bitmap("manf1.bmp",NULL);	    
			masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(selectc+1)*80, 64,64);
		}
		
		if(selectc==2)					//player 3
		{
			BITMAP *back1  = load_bitmap("manf2.bmp",NULL);	    
			masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(selectc+1)*80, 64,64);
		}
		if(selectc==3)					//player 4
		{
			BITMAP *back1  = load_bitmap("manf3.bmp",NULL);	    
			masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(selectc+1)*80, 64,64);
		}
		if(selectc==4)					//player 5
		{
			BITMAP *back1  = load_bitmap("manf4.bmp",NULL);	    
			masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(selectc+1)*80, 64,64);
		}
		if(selectc==5)					//player 6
		{
			BITMAP *back1  = load_bitmap("manf5.bmp",NULL);	    
			masked_blit(back1, buffer, 0, 0,ScreenWidth/2+100,(selectc+1)*80, 64,64);
		}
					
							
		blit(buffer,screen,0,0,0,0,1200,600);
		if(key[KEY_SPACE])			//when u select an option
		{
			if (selectc==0)					//player 1
			{
				destroy_bitmap(buffer);
				destroy_font(Font11);
				return 1;
			}
			if (selectc==1)						//player 2
			{
				destroy_bitmap(buffer);
				destroy_font(Font11);
				return 2;
			}
			if (selectc==2)						//player 3
			{
				destroy_bitmap(buffer);
				destroy_font(Font11);
				return 3;
			}
			if (selectc==3)						//player 4
			{
				destroy_bitmap(buffer);
				destroy_font(Font11);
				return 4;
			}
			if (selectc==4)						//player 5
			{
				destroy_bitmap(buffer);
				destroy_font(Font11);
				return 5;
			}
			if (selectc==5)						//player 6
			{
				destroy_bitmap(buffer);
				destroy_font(Font11);
				return 6;
			}
		}
	}
}

