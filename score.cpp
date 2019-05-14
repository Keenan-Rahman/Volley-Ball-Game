#include <allegro.h>

#include "score.h"
#define ScreenWidth 1200
#define ScreenHeight 600


int Score::seescore(int left, int right)
{
	FONT *Font9=load_font("score.pcx",NULL,NULL);			//add font style
	textprintf(screen, Font9,ScreenWidth/2-120,200,makecol(44,117,255), "%i      ", left,-1);		//print left score
	textprintf(screen, Font9,ScreenWidth/2,200,makecol(44,117,255), ":", 0,-1);
	textprintf(screen, Font9,ScreenWidth/2+100,200,makecol(44,117,255), "%i", right,-1);		//print right score
	destroy_font(Font9);			//detroy font
	FONT *Font10=load_font("win.pcx",NULL,NULL);			//win font
	if(left==5)			//if left=5 left win condition
	{		
		SAMPLE *goal = load_sample("goal.wav");
		play_sample(goal, 255, 127 ,1000,true); //play sound
		textout_centre_ex(screen,Font10,"LEFT PLAYER WINS",ScreenWidth/2,ScreenHeight/2,makecol(44,117,255),-1);
		rest(6000);
		destroy_font(Font10);
		destroy_sample(goal);
		return 2;
	}
	if(right==5)			//if right=5 right win condition
	{
		SAMPLE *goal = load_sample("goal.wav");
		play_sample(goal, 255, 127 ,1000,true); //play sound
		textout_centre_ex(screen,Font10,"RIGHT PLAYER WINS",ScreenWidth/2,ScreenHeight/2,makecol(44,117,255),-1);
		rest(6000);
		destroy_font(Font10);
		destroy_sample(goal);
		return 2;
	}
	x:
	destroy_font(Font10);
	rest(1000);
}
