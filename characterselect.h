#ifndef CHARACTERSELECT_H
#define CHARACTERSELECT_H


#include <allegro.h>
#include <string>
#include <array>
using namespace std;

class CharacterSelect{
	protected:
		int keypressc =0;
		int prevkeypressc =0;
		array <string,6> characters;
		bool donec=true;
		int valuec=0;
		int selectc=0;
	
	public:
		bool KeyPressbackc(int);		//keys function
		bool Keyrealsedbackc(int);			//keys function
		int selectcharl();				//charcter left selector function
		int selectcharr();				//charcter  right selector function
		
		
};

#endif
