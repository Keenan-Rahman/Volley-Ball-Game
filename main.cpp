#include <allegro.h>
#include "header.h"
#include "character.h"
#include "credit.h"
#include "instruction.h"


void init();
void deinit();
volatile int closewindow=false;

void CloseGame()
{
	closewindow=true;
	allegro_exit();
}

int main(int b)
{
	init();
	LOCK_FUNCTION(CloseGame);
	set_close_button_callback(CloseGame);
		int selectedvalue;
		MainClass MC1;				//forms object
		MC1.GameSetting();							//setting up the game screen and features
		MC1.Title();								// provide title to window title bar
		MC1.OptionSelect();			// open menu bar

	deinit();
	allegro_exit();
	return 0;
}
END_OF_MAIN()


void init() 
{
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, 0);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1200, 600, 0, 0);
	if (res != 0) 
	{
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
}

void deinit() 
{
	clear_keybuf();
	allegro_exit();
}
