
#ifndef INSTRUCTION_H
#define INSTRUCTION_H


#include <string>
using namespace std;


class Instructions{
	private:
		string line0="INSTRUCTIONS";
		string line1="Keys For Player 1:";					//instructions
		string line2="Press UP key to jump, Press LEFT key to move left, Press RIGHT key to move right";
		string line3="Keys For Player 2:";
		string line4="Press W key to jump, Press A key to move left, Press D key to move right";
		string line5="This is a Volleyball game. Don't let the ball to fall on the ground.";
		string line6="Hit the ball to throw it to your opponent side. First to score 5 goals is Winner.";
		bool loop=true;
	public:
		void howtoplay();
};

#endif
