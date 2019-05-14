#ifndef CHARACTER_H
#define CHARACTER_H

#include <allegro.h>
#include "background.h"
#include "header.h"
#include "characterselect.h"
#include "score.h"
#define ScreenWidth 1200
#define ScreenHeight 600
class Character:public MainClass{
	private:
		//charcter 1st
		Score *CS1;
		BackgroundSelect BC1;
		CharacterSelect CSC1;
		int leftscore=0;
		int rightscore=0;
		int game_ender;
		int start_position;
		int Position[2] = {10, 450};		// position of 1st character
    	int currentFrame[2] = {0, 0};		//frame from picture selected
    	int Frames[2] = {3, 4};				//length and height of every frame
    	int moveSpeed = 15;				// speed of character
    	int switchFrame = 1;		//determines the speed of frames chaning  
    	int frameCounter = 0; 		//switch of frames
		int backs;
		int charl;
		int charr;
		
		//character 2nd
	    int Position1[2] = {1100, 450};			// position of 2nd character
    	int currentFrame1[2] = {0, 0};				//frame from picture selected
    	int Frames1[2] = {3, 4};			//length and height of every frame
    	int moveSpeed1 = 15;					// speed of character
   		int switchFrame1 = 1;			//determines the speed of frames chaning 
    	int frameCounter1 = 0; 					//switch frame
        bool isActive;						//check key press for 1st 
    	bool isActive1;					//check key press for 2nd
    	
    	
 	public:	 	
 		Character();			//loading view
		void left();		//move 1st left
		void down();			//move 1st on ground
		void up();				//move 1st jump
		void right();			// move 1st right
		void w();				//move 2nd jump
		void s();			//move 2nd on ground
		void a();		//move 2nd left
		void d();			//move 2nd right
		void Movement();
		void Movement1();
		int backgr();			//forms background character and check key pressed
		
		
		bool Collision(int ,int ,int ,int ,int ,int ,int ,int );		//ball collision
	
};

#endif
