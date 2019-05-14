#ifndef BACKGROUND_H
#define BACKGROUND_H


#include <allegro.h>
#include <string>
#include <array>
using namespace std;

class BackgroundSelect{
	private:
		int keypressb =0;
		int prevkeypressb =0;
		array <string,2> backs;
		bool doneb=true;
		int valueb=0;
		int selectb=0;
	
	public:
		bool KeyPressbackb(int);		//keys function
		bool Keyrealsedbackb(int);			//keys function
		int selector();				//background selector function
};

#endif
