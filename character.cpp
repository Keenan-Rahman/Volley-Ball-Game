#include <allegro.h>
#include "character.h"
#include "header.h"
#include "characterselect.h"
#include "background.h"
#define ScreenWidth 1200
#define ScreenHeight 600
#include <math.h> 
#include <ctime>
#include <cstdlib>
#define DEGREES(x) int((x)/360.0*0xFFFFFF) 
#define l 64
#define r 128
#define u 192


Character::Character()
{
	
	
	backs=BC1.selector();
	if(backs==3)
	{
	
		OptionSelect();
	}
 	charl=CSC1.selectcharl();
 	if(charl==7)
	{
	
		OptionSelect();
	}
	charr=CSC1.selectcharr();
	if(charr==7)
	{
	
		OptionSelect();
	}
	BITMAP *Buffer = create_bitmap (ScreenWidth, ScreenHeight);		//make buffer
	BITMAP *load1  = load_bitmap("1.bmp",NULL);				//pictures of loading
	BITMAP *load2  = load_bitmap("2.bmp",NULL);					//pictures of loading
	BITMAP *load3  = load_bitmap("3.bmp",NULL);					//pictures of loading
	BITMAP *load4  = load_bitmap("4.bmp",NULL);					//pictures of loading
	BITMAP *load5  = load_bitmap("5.bmp",NULL);					//pictures of loading
	BITMAP *load6  = load_bitmap("6.bmp",NULL);					//pictures of loading
	SAMPLE *load = load_sample("loading.wav");			//sound play
	play_sample(load, 255, 127 ,1000,true); 			//play sound volume	
	masked_blit(load1, Buffer, 0, 0, 0, 0, load1->w, load1->h); 			//screen size      
	blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);
	rest(200);				//showing on the screen
    destroy_sample(load);				//destroy the sound
	rest(200);					//pause
    clear_bitmap(Buffer);				//clear
	SAMPLE *load02 = load_sample("loading.wav");				//load sound
	play_sample(load02, 255, 127 ,1000,true); 					//play sound	
	masked_blit(load2, Buffer, 0, 0, 0, 0, load2->w, load2->h); 			//showing on the screen
	blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);			//load on screen
	rest(200);				//pause
    destroy_sample(load02);					//destroy sound
	rest(200);
    clear_bitmap(Buffer);				//clear buffer
	SAMPLE *load03 = load_sample("loading.wav");					
	play_sample(load03, 255, 127 ,1000,true); //play sound	
	masked_blit(load3, Buffer, 0, 0, 0, 0, load3->w, load3->h); 			//showing on the screen
	blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);
	rest(200);
    destroy_sample(load03);
	rest(200);
    clear_bitmap(Buffer);
    SAMPLE *load04 = load_sample("loading.wav");
	play_sample(load04, 255, 127 ,1000,true); //play sound	
	masked_blit(load4, Buffer, 0, 0, 0, 0, load4->w, load4->h); 				//showing on the screen 
	blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);
	rest(200);
    destroy_sample(load04);
	rest(200);
    clear_bitmap(Buffer);
    SAMPLE *load05 = load_sample("loading.wav");
	play_sample(load05, 255, 127 ,1000,true); //play sound	
	masked_blit(load5, Buffer, 0, 0, 0, 0, load5->w, load5->h); 				//showing on the screen
	blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);rest(200);
    destroy_sample(load05);
	rest(200);
    clear_bitmap(Buffer);
    SAMPLE *load06 = load_sample("loading.wav");
	play_sample(load06, 255, 127 ,1000,true); //play sound	
	masked_blit(load6, Buffer, 0, 0, 0, 0, load6->w, load6->h); 				//showing on the screen    
	blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);rest(200);
    destroy_sample(load06);
	rest(200);
    clear_bitmap(Buffer);
	rest(200);
	
	destroy_bitmap(Buffer);   	
}

void Character::left()			//function to move right character to left
{
	enum Source1 {S, A, D, W}; 
	if(Position1[0]>605)
    {
		Position1[0] -= moveSpeed1;
        currentFrame1[1] = A;
    }
}

void Character::down()				//function to move right character to down to position 450
{
	enum Source1 {S, A, D, W}; 
	if(Position1[1]<450)
		Position1[1] += moveSpeed1; 
	currentFrame1[1] = S;			
}

void Character::up()				//function to move right character to jump
{
	enum Source1 {S, A, D, W}; 
    Position1[1] -= moveSpeed1;
	currentFrame1[1] = W;			
}

void Character::right()				//function to move right character to right
{
	enum Source1 {S, A, D, W}; 
	if(Position1[0]<=1140)
	{
		Position1[0] += moveSpeed1;
		currentFrame1[1] = D;

	}
}

void Character::w()				//function to move left character to jump
{
	enum Source {Down, Left, Right, Up};
	Position[1] -= moveSpeed;
	currentFrame[1] = Up;
}
	
void Character::s()				//function to move left character to down 450
{
	enum Source {Down, Left, Right, Up};
	if(Position[1]<450)
		Position[1] += moveSpeed; 
	currentFrame[1] = Down;
}

void Character::a()				//function to move left character to left
{
	enum Source {Down, Left, Right, Up};
	if(Position[0]>0)
	{
		Position[0] -= moveSpeed;
		currentFrame[1] = Left;
    }			
}

void Character::d()				//function to move left character to right
{
	enum Source {Down, Left, Right, Up};
  	if(Position[0]<=520)
	{
		Position[0] += moveSpeed;
        currentFrame[1] = Right;
    }
}
	
int Character::backgr()				//return bacground selection from class background
{
	return backs;
}


bool Character::Collision(int c,int dd,int width,int height,int c1,int d1,int width1,int height1)				//function to detect collision of character and ball
{
	if(c > c1+width1 || c+width < c1 || dd> d1+height1 || dd+height1 < d1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Character::Movement()				//MAJOR GAME LOOP FUNCTION
{
	srand(time(0));			// for line 200	 		
	BITMAP *Buffer = create_bitmap (ScreenWidth, ScreenHeight);			//MAKE BUFFER	
	
	BITMAP *greenfield;
	if(backs==2)
	{
		greenfield  = load_bitmap("back2.bmp",NULL);			//load background
		
	}
	else if(backs==1)
	{
		greenfield  = load_bitmap("back1.bmp",NULL);			//load background
		
	}

	BITMAP *ball=load_bitmap("ball.bmp",NULL) ; 				//load ball
	
	BITMAP *PlayerImage1;
	
	
	if(charl==1)
	{
		 PlayerImage1= load_bitmap("man.bmp", NULL);			//load character
	}
	else if(charl==2)
	{
		 PlayerImage1= load_bitmap("man1.bmp", NULL);			//load character
	}
	else if(charl==3)
	{
		 PlayerImage1= load_bitmap("man2.bmp", NULL);			//load character
	}

	else if(charl==4)
	{
		 PlayerImage1= load_bitmap("man3.bmp", NULL);			//load character
	}

	else if(charl==5)
	{
		 PlayerImage1= load_bitmap("man4.bmp", NULL);			//load character
	}

	else if(charl==6)
	{
		 PlayerImage1= load_bitmap("man5.bmp", NULL);			//load character
	}

	
	BITMAP *PlayerImage2;
	if(charr==1)
	{
		 PlayerImage2= load_bitmap("man.bmp", NULL);			//load character
	}
	else if(charr==2)
	{
		 PlayerImage2= load_bitmap("man1.bmp", NULL);			//load character
	}
	else if(charr==3)
	{
		 PlayerImage2= load_bitmap("man2.bmp", NULL);			//load character
	}

	else if(charr==4)
	{
		 PlayerImage2= load_bitmap("man3.bmp", NULL);			//load character
	}

	else if(charr==5)
	{
		 PlayerImage2= load_bitmap("man4.bmp", NULL);			//load character
	}

	else if(charr==6)
	{
		 PlayerImage2= load_bitmap("man5.bmp", NULL);			//load character
	}

	

	mee:
	
	int xaxis=1136, yaxis=450, p=0, q=450; 			//initial coordinate of characters
	int angle=120; 							//initial angle of ball
	
	float multi=2;				//give y-axis inclination
	float theta = DEGREES(angle); 			//calculate degree to move ball  
	
    int check=0;				//check ball collision with net
	float velocity = 20;  			//velocity of ball
	float dt = 1.0; 			//ball move speed
	float x = 80.0; 			//initial position of ball on x-axis
	p:
	float y = rand()%400 ;					//calculate y-axis randomly
	if(y<290)			//condition to give value of y-axis of range 290-400
	{
		goto p;
	}				// 280-410 random 
	 
	float velocityX = velocity * cos(theta) *multi; 		// x component of velocity 
	
	
	start:
		
	start_position=x;				//int to see ball position when collide with ball
	dt=1.0;					//time for ball
		
	while(Position[1]!=450)				//when character jump it bring it to position 450 if it go above or below it right
	{
		if(Position[1]<450)
		Position[1] +=1;
		if(Position[1]>450)
		Position[1] -=1;
	}
	
	while(Position1[1]!=450)				//when character jump it bring it to position 450 if it go above or below it left
	{
		if(Position1[1]<450)
		Position1[1] +=1;
		if(Position1[1]>450)
		Position1[1] -=1;
	}
	float velocityY = velocity * sin(theta);				 // y component of velocity 

	n:	
	bool done = false;			//check loop of game
    
	int Dimensions[2] = {PlayerImage1->w / Frames[0], PlayerImage1->h / Frames[1]};					//position of character
	int Dimensions1[2] = {PlayerImage2->w / Frames1[0], PlayerImage2->h / Frames1[1]};	 			//position of character
	enum Source {Down, Left, Right, Up};				//for right
	enum Source1 {S, A, D, W}; 					//for left
    bool pause=false;				//for game loop
	while(!done)
	{
	
		// Update Loop
		while(!key[KEY_P])				//loop of game
		{
       
			float velocityX = velocity * cos(theta) *multi; // x component of velocity 
			x = x + (velocityX*dt); // updating the x position  
			velocityY = velocityY +dt; // updating the y component of the velocity  
     		y = y + (velocityY*dt) + 0.5*(dt*dt);// updating the y position. 
       

	   		masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h); 			//green field      
        	masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);			//forms player 1
			masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	    	//forms player 2
			masked_blit(ball, Buffer,0, 0, x, y, 1200,600); 						//forms ball      
			blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);		//blit to screen
        	clear_bitmap(Buffer);				//clear buffer

			//right character
			if(Collision(Position1[0],Position1[1]+20,32,32,x,y,50,50))				//collision check for right character
			{
				if(x>=500 && x<=600)
				{
				    angle=350;
					multi=-3;	
					goto start;
				}
			
				if(x>=600 && x<=700)
				{
			    	angle=300;
			    	multi=-3;
					goto start;	
				}
				if(x>=700 && x<=850)
				{
       				angle=270;
       				multi=-3;
					goto start;	
				}
				if(x>=850 && x<=1180)
				{
       				angle=300;
       				multi=-2;
					goto start;	
				}
			
			
	   		}
			masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h);				 //green field      
        	masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);		//player 1
			masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	    //player 2
			masked_blit(ball, Buffer,0, 0, x, y, 1200,600); 						//ball
			blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);rest(5);		//blit to screen
   		    clear_bitmap(Buffer);
	   
	 		  //left character neela wala
	   		if(Collision(Position[0]+30,Position[1]+20,32,32,x,y,50,50))			//collision check for left
			{
       			if(x>=20 && x<=300)
				{
       				angle=330;
       				multi=2;
					goto start;	   	
				}
			
       			if(x>=300 && x<=420)
				{
       				angle=240;
       				multi=2;
       				goto start;
				}	
			
				if(x>=420 && x<=500)
				{
       				angle=210;
       				multi=2;
					goto start;	
				}
			
				if(x>=500 && x<=580)
				{
       				angle=270;
       				multi=2;
       				goto start;
				}
			
       		
			}
			masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h); //green field      
        	masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);
			masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	    
			masked_blit(ball, Buffer,0, 0, x, y, 1200,600); //green field      

			blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);rest(5);
    	    clear_bitmap(Buffer);
	   
		   //these condition check the collision with ground or out of crease
		   
    	   if(y>=460 && x>=10 && x<=550)			//y>=460 && x>=10 && x<=550 
			{
    			x=565;
				y=380;
				check=1;
				goto stick;
			}	
		   else if(y>=460 && x<=1190 && x>=640)			//y>=460 && x<=1190 && x>=640
			{
	    		x=565;
				y=380;	
				check=2;
				goto stick;
			}
		   else if(x>1190)
			{
			   	x=565;
				y=380;
				check=1;
				goto stick;
			}
		   else if(x<=10)
			{
	   			x=565;
				y=380;
				check=2;
				goto stick;
			}
	   
			   //till here
	   
	   
	   
			masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h); //green field      
    	    masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);
			masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	    
			masked_blit(ball, Buffer,0, 0, x, y, 1200,600); //ball     

			blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);rest(5);
        	clear_bitmap(Buffer);
        	
        	//check the collision with net
			if((x>=560 && x<=600)&& (y>=385 && y<=580))
			{
				if(start_position<=550)
				check=1;				//right ka ++
				else
				check=2;				//left ka ++
			
			
				x=565;
				y=380;
				goto stick;
			}
		   /*
		    
		   if((x>=560 && x<=600)&& (y>=385 && y<=580))
		   {
				if(start_position<=550)
				check=1;				//right ka ++
				else
				check=2;				//left ka ++
			
			
				x=565;
				y=380;
				goto stick;
		   }*/
			     
			if(key[KEY_ESC])
			{
	   			pause=true;
				goto k;
			}
	 		if(key[KEY_Q])
			{
				goto over;
	 		}

 
	       	isActive = true;			//change frame condition
			isActive1 = true;			//change frame condition 
            
			
			if(key[KEY_D])			//right key
    		{
				d();
     		}
      		if(key[KEY_A])			//left
			{
    	  		a();
			}
            if(key[KEY_S])			//down
            {
            	s();
            }
            if(key[KEY_W])				//jump
            {
  				w();
            	goto f;
            }
			
			
			if(key[KEY_RIGHT])			//right
            {
				right();
            }
            if(key[KEY_LEFT])			//left
            {
            	left();
   	        }
            if(key[KEY_DOWN])				//down
            {
 				down();
	        }
           	if(key[KEY_UP])				//jump
            {
            	up();
				goto m;	
   			}
            else				//if no key not pressed
            {
            	isActive = false;
                isActive1 = false;
            }
 
 		    if(isActive)					//picture frames changer for character 1
        	{
           		frameCounter++;
           		if(frameCounter >= switchFrame)
				{
            		currentFrame[0] += Dimensions[0];
            		frameCounter = 0;
				}
            	if(currentFrame[0] >= PlayerImage1->w)
            		currentFrame[0] = 0;
            }
           	else
           	{
            	currentFrame[0] = 0;
                frameCounter = 0;
            }
			
			if(isActive1)				//picture frame changer for character 2
            {
            	frameCounter1++;
            	if(frameCounter1 >= switchFrame1)
            	{
            	    currentFrame1[0] += Dimensions1[0];
                    frameCounter1 += 1;
                }
               	if(currentFrame1[0] >= PlayerImage2->w)
                    currentFrame1[0] += 1;
            }
           	else
            {
            	currentFrame1[0] = 0;
            	frameCounter1 = 0;
            }
 
            masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h); //green field      
        	masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);
			masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	  
			masked_blit(ball, Buffer,0, 0, x, y, 1200,600); 				//ball    
  
			blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);
        	clear_bitmap(Buffer);
		}

    
		masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h); //green field      
        masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);
		masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	    
		masked_blit(ball, Buffer,0, 0, x, y, 1200,600); //green field      

		blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);
        clear_bitmap(Buffer);
    }	
    
    
    
    
	m:
    while(Position1[1]>370)				//player left jump up loop
    {
    	//during jump we want ball to keep moving, so ball movement funtions also here
    	
		float velocityX = velocity * cos(theta) *multi; 		// x component of velocity 
	
		x = x + (velocityX*dt); 		// updating the x position  
	
		velocityY = velocityY +dt; 				// updating the y component of the velocity  
     
		y = y + (velocityY*dt) + 0.5*(dt*dt);			// updating the y position. 
       
	   	masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h); //background   
        masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);
		masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	    
		masked_blit(ball, Buffer,0, 0, x, y, 1200,600); //ball
		blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);rest(5);
        clear_bitmap(Buffer);

		if(Collision(Position1[0],Position1[1]+20,32,32,x,y,50,50))			//collision detects for character 1
		{
       	
			if(x>=500 && x<=600)
			{
			    angle=350;
				multi=-3;	
				goto start;
			}
			
			if(x>=600 && x<=700)
			{
			    angle=300;
			    multi=-3;
				goto start;	
			}
			if(x>=700 && x<=850)
			{
       			angle=270;
       			multi=-3;
				goto start;	
			}
			if(x>=850 && x<=1180)
			{
       			angle=300;
       			multi=-2;
				goto start;	
			}
			
			
	   }
		masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h); //background      
        masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);
		masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	    
		masked_blit(ball, Buffer,0, 0, x, y, 1200,600); //ball
		blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);rest(5);
        clear_bitmap(Buffer);
	   
	   if(Collision(Position[0]+30,Position[1]+20,32,32,x,y,50,50))				//collision detect for character 1
		{
       		if(x>=20 && x<=300)
			{
       			angle=330;
       			multi=2;
				goto start;	   	
			}
			
       		if(x>=300 && x<=420)
			{
       			angle=240;
       			multi=2;
       			goto start;
			}	
			
			if(x>=420 && x<=500)
			{
       			angle=210;
       			multi=2;
				goto start;	
			}
			
			if(x>=500 && x<=580)
			{
       			angle=270;
       			multi=2;
       			goto start;
			}
			
       		
		}
		if((x>=560 && x<=600)&& (y>=385 && y<=580))
		{
			if(start_position<=550)
			check=1;				//right ka ++
			else
			check=2;				//left ka ++
		
		
			x=565;
			y=380;
			goto stick;
		}
		
		if(key[KEY_D])			//right key
        {
			d();
        }
        if(key[KEY_A])			//left key
        {
        	a();
        }
        Position1[1] -= moveSpeed1*1;				//jump speed
        currentFrame1[1] = A;			//change frame
               		 		
        currentFrame1[0] = 0;			//change frame
        frameCounter1 = 0;
            	
		masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h); //green field      
        masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);
		masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	    
		masked_blit(ball, Buffer,0, 0, x, y, 1200,600); //green field      
		blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);rest(5);
        clear_bitmap(Buffer);
	}
    	
		
	while(Position1[1]<450)				//bring left chacter down after jump
    {
		float velocityX = velocity * cos(theta) *multi; // x component of velocity 
	
		x = x + (velocityX*dt); // updating the x position  
	
		velocityY = velocityY +dt; // updating the y component of the velocity  
     
		y = y + (velocityY*dt) + 0.5*(dt*dt);// updating the y position. 
       
		//right character grey wala
	   	masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h); //green field      
        masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);
		masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	    
		masked_blit(ball, Buffer,0, 0, x, y, 1200,600); //green field      

		blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);rest(5);
        clear_bitmap(Buffer);
		if(Collision(Position1[0],Position1[1]+20,32,32,x,y,50,50))
		{	
       	
			if(x>=500 && x<=600)
			{
			    angle=350;
				multi=-3;	
				goto start;
			}
			
			if(x>=600 && x<=700)
			{
			    angle=300;
			    multi=-3;
				goto start;	
			}
			if(x>=700 && x<=850)
			{
       			angle=270;
       			multi=-3;
				goto start;	
			}
			if(x>=850 && x<=1180)
			{
       			angle=300;
       			multi=-2;
				goto start;	
			}
			
			
		}
		if((x>=560 && x<=600)&& (y>=385 && y<=580))
		{
			if(start_position<=550)
			check=1;				//right ka ++
			else
			check=2;				//left ka ++
				
			x=565;
			y=380;
			goto stick;
		}
		masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h); //green field      
        masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);
		masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	    
		masked_blit(ball, Buffer,0, 0, x, y, 1200,600); //ball     
		blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);rest(5);
        clear_bitmap(Buffer);
	   
	   //collision for right character
	   if(Collision(Position[0]+30,Position[1]+20,32,32,x,y,50,50))
		{
       		if(x>=20 && x<=300)
			{
       			angle=330;
       			multi=2;
				goto start;	   	
			}
			
       		if(x>=300 && x<=420)
			{
       			angle=240;
       			multi=2;
       			goto start;
			}	
			
			if(x>=420 && x<=500)
			{
       			angle=210;
       			multi=2;
				goto start;	
			}
			
			if(x>=500 && x<=580)
			{
       			angle=270;
       			multi=2;
       			goto start;
			}
			
       		
		}
		if(key[KEY_D])			//move right
        {
			d();
        }
        if(key[KEY_A])			//move left
        {
        	a();
        }
        Position1[1] += moveSpeed1*1;				//jump speed
        currentFrame1[1] = A;			//frame change
               		
        currentFrame1[0] = 0;
        frameCounter1 = 0;
            	
		masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h); //green field      
        masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);
		masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	    
		masked_blit(ball, Buffer,0, 0, x, y, 1200,600); 			//balll      
		blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);
        clear_bitmap(Buffer);
	}
	
	//bring character back to 450 position after jump
	while(Position1[1]!=450)
	{
		if(Position1[1]<450)
		Position1[1] +=1;
		if(Position1[1]>450)
		Position1[1] -=1;
	}					
	goto n;
	f:
		
		//jump right charatcer up loop
	while(Position[1]>370)
    {
	
		float velocityX = velocity * cos(theta) *multi; // x component of velocity 
	
		x = x + (velocityX*dt); // updating the x position  
	
		velocityY = velocityY +dt; // updating the y component of the velocity  
     
		y = y + (velocityY*dt) + 0.5*(dt*dt);// updating the y position. 
       
	   	masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h); //background     
        masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);
		masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	    
		masked_blit(ball, Buffer,0, 0, x, y, 1200,600); //ball      
		blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);
        clear_bitmap(Buffer);
		
		//collision detect for left character
        if(Collision(Position1[0],Position1[1]+20,32,32,x,y,50,50))
		{
       	
			if(x>=500 && x<=600)
			{
			    angle=350;
				multi=-3;	
				goto start;
			}
			
			if(x>=600 && x<=700)
			{
			    angle=300;
			    multi=-3;
				goto start;	
			}
			if(x>=700 && x<=850)
			{
       			angle=270;
       			multi=-3;
				goto start;	
			}
			if(x>=850 && x<=1180)
			{
       			angle=300;
       			multi=-2;
				goto start;	
			}
					
			
		}
		masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h); 			//background      
        masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);
		masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	    
		masked_blit(ball, Buffer,0, 0, x, y, 1200,600); 			//ball
		blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);rest(5);
        clear_bitmap(Buffer);
	   if((x>=560 && x<=600)&& (y>=385 && y<=580))
		{
			if(start_position<=550)
			check=1;				//right ka ++
			else
			check=2;				//left ka ++
				
			x=565;
			y=380;
			goto stick;
		}
	   //collision detection for right charatcer
	   if(Collision(Position[0]+30,Position[1]+20,32,32,x,y,50,50))
       {
       		if(x>=20 && x<=300)
       		{
       			angle=330;
       			multi=2;
				goto start;	   	
			}
			
       		if(x>=300 && x<=420)
       		{
       			angle=240;
       			multi=2;
       			goto start;
			}	
			
			if(x>=420 && x<=500)
       		{
       			angle=210;
       			multi=2;
				goto start;	
			}
			
			if(x>=500 && x<=580)
       		{
       			angle=270;
       			multi=2;
       			goto start;
			}
			
       		
	   }
		if(key[KEY_RIGHT])			//move right
        {
			right();
        }
        if(key[KEY_LEFT])			//move left
        {
        	left();
   	    }
        Position[1] -= moveSpeed*1;				//jump speed
        currentFrame[1] = Right;				//change frame
               		
               		
        currentFrame[0] = 0;
        frameCounter = 0;
            	
		masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h);			 //background      
        masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);
		masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	    
		masked_blit(ball, Buffer,0, 0, x, y, 1200,600); 				//ball
		blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);rest(5);
        clear_bitmap(Buffer);		
	}
    
    
    
    //jump loop for right character down
	while(Position[1]<450)
    {
		float velocityX = velocity * cos(theta) *multi; // x component of velocity 
		x = x + (velocityX*dt); // updating the x position  
		velocityY = velocityY +dt; // updating the y component of the velocity  
		y = y + (velocityY*dt) + 0.5*(dt*dt);// updating the y position. 
       
       
	   	masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h); 			//background      
        masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);
		masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	    
		masked_blit(ball, Buffer,0, 0, x, y, 1200,600); 							//ball 
		blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);rest(5);
        clear_bitmap(Buffer);

        if(Collision(Position1[0],Position1[1]+20,32,32,x,y,50,50))
		{
       	
			if(x>=500 && x<=600)
			{
			    angle=350;
				multi=-3;	
				goto start;
			}
			
			if(x>=600 && x<=700)
			{
			    angle=300;
			    multi=-3;
				goto start;	
			}
			if(x>=700 && x<=850)
			{
       			angle=270;
       			multi=-3;
				goto start;	
			}
			if(x>=850 && x<=1180)
			{
       			angle=300;
       			multi=-2;
				goto start;	
			}
			
			
		}
		if((x>=560 && x<=600)&& (y>=385 && y<=580))
		{
			if(start_position<=550)
			check=1;				//right ka ++
			else
			check=2;				//left ka ++
				
			x=565;
			y=380;
			goto stick;
		}
		masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h); 			//background      
        masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);
		masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	    
		masked_blit(ball, Buffer,0, 0, x, y, 1200,600); 					//ball
		blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);
        clear_bitmap(Buffer);
	   
	   //collision check for right
	   if(Collision(Position[0]+30,Position[1]+20,32,32,x,y,50,50))
		{
       		if(x>=20 && x<=300)
			{
       			angle=330;
       			multi=2;
				goto start;	   	
			}
			
       		if(x>=300 && x<=420)
			{
       			angle=240;
       			multi=2;
       			goto start;
			}	
			
			if(x>=420 && x<=500)
			{
       			angle=210;
       			multi=2;
				goto start;	
			}
			
			if(x>=500 && x<=580)
			{
       			angle=270;
       			multi=2;
       			goto start;
			}
			
       		
		}
		if(key[KEY_RIGHT])			//move right
    	{
			right();
	    }
	    if(key[KEY_LEFT])			//move left
	    {
    		left();
   		}
    	Position[1] += moveSpeed*1;			//jump speed
    	currentFrame[1] = Right;			//change frame
    	           		           		
    	currentFrame[0] = 0;			//change fra,e
    	frameCounter = 0;
    	        	
		masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h); 				//background      
    	masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);
		masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);	    
		masked_blit(ball, Buffer,0, 0, x, y, 1200,600); 				//ball      
		blit(Buffer, screen, 0, 0, 0, 0, ScreenWidth, ScreenHeight);rest(5);
    	clear_bitmap(Buffer);
	}
	
	//bring to position 450 after collision
	while(Position[1]!=450)
	{
		if(Position[1]<450)
		Position[1] +=1;
		if(Position[1]>450)
		Position[1] -=1;
	}
						
	goto n;
	k:
	
	clear_bitmap(screen);
	
	while(pause)				//pause loop
	{
		textout_centre_ex(screen,font,"PAUSE. Press P To Resume",600,300,makecol(44,117,255),-1);			
		if(key[KEY_P])				//if pause. press P to resume
		{	
			goto n;
		}
	}
	
	//collision for left charcter
	if(Collision(Position1[0],Position1[1]+20,32,32,x,y,50,50))
	{
       	
		if(x>=500 && x<=600)
		{
		    angle=350;
			multi=-3;	
			goto start;
		}
			
		if(x>=600 && x<=700)
		{
		    angle=300;
		    multi=-3;
			goto start;	
		}
		if(x>=700 && x<=850)
		{
   			angle=270;
   			multi=-3;
			goto start;	
		}
		if(x>=850 && x<=1180)
		{
       		angle=300;
       		multi=-2;
			goto start;	
		}
			
			
	}	   
	
	//collison for right character
	if(Collision(Position[0]+30,Position[1]+20,32,32,x,y,50,50))
	{
		if(x>=20 && x<=300)
		{
       		angle=330;
       		multi=2;
			goto start;	   	
		}
			
       	if(x>=300 && x<=420)
		{
       		angle=240;
       		multi=2;
       		goto start;
		}	
		if(x>=420 && x<=500)
		{
       		angle=210;
       		multi=2;
			goto start;	
		}
			
		if(x>=500 && x<=580)
		{
       		angle=270;
       		multi=2;
       		goto start;
		}	
	}
	
	//bring ball to stick if foul or score happen
	stick:
	while(!key[KEY_ESC])
	{
		masked_blit(greenfield, Buffer, 0, 0, 0, 0, greenfield->w, greenfield->h); 				//background     
    	masked_blit(PlayerImage1, Buffer, currentFrame[0], currentFrame[1] * Dimensions[1], Position[0], Position[1], Dimensions[0], Dimensions[1]);
		masked_blit(PlayerImage2, Buffer, currentFrame1[0], currentFrame1[1] * Dimensions1[1], Position1[0], Position1[1], Dimensions1[0], Dimensions1[1]);
       	masked_blit(ball, Buffer,0, 0, x, y, 1200,600); //ball      
	   	blit(Buffer,screen,0,0,0,0,1200,600);
	   	draw_sprite(screen,Buffer,0,0);				 // drawing the buffer to the screen. 
		if(check==1)			//check for right score chances
		{ 
			rightscore++;			//right score increases
 			clear_bitmap(Buffer);	
       		game_ender=CS1->seescore(leftscore,rightscore);				//show score
  			if(game_ender==2)			//game end if score 5
			{
  				goto over;
			}
  		}
  		
  		if(check==2)				//left score chances
		{ 
			leftscore++;			//score increment
  			clear_bitmap(Buffer);	
       	 	game_ender=CS1->seescore(leftscore,rightscore);			//show score
  		 	if(game_ender==2)				//game end if 5 score
			{
				goto over;
			}
		}
  		
		rest(1000);					//wait
       	clear_bitmap(Buffer);	
		rest(400);
		goto mee;				//go back again to game continue
	}

	goto n;
	over:					//destroy everything and end game
	destroy_bitmap(Buffer); 
    destroy_bitmap(PlayerImage1);
    destroy_bitmap(PlayerImage2);
	destroy_bitmap(greenfield);
}

