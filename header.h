#ifndef HEADER_H
#define HEADER_H


#include <string>
#include <array>
#include "instruction.h"
#include "credit.h"
using namespace std;


class MainClass{
	private:
		Instructions *INM;
		Credits *CM;
		array <string,4> options;
		bool done=true;
		int keypress =0;
		int prevkeypress =0;
	public:
		void GameSetting();
		void Title();				//provide title on screen
		bool KeyPress(int);					// to let select option move one by one
		bool Keyrealsed(int);				// same as above. both are inter link
		int OptionSelect();					//function to have menu
		
};
#endif


