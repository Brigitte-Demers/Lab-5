//==============================================================================
#include "CApp.h"
#include <stdlib.h>
#include <time.h>
//==============================================================================
bool CApp::OnInit()
{

    int i;

    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK)<0)
    {
        return false;
    }
    window = SDL_CreateWindow("Basic SDL 2.0 Scrolling",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window)
        return false;
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
        return false;

    srand(time(NULL));

    for (i = 0; i < NUM_SPRITES; ++i) {
		allplayers[i] = CPlayer("snowflake.bmp", 0, 0, 0, 0);
        allplayers[i].loadPlayer(renderer);
        allplayers[i].position.x = rand() % (window_w);
        allplayers[i].position.y = rand() % (window_h);
        //allplayers[i].velocity.x = 0;
        allplayers[i].velocity.y = 0;
        while (!allplayers[i].velocity.x && !allplayers[i].velocity.y) {
            //allplayers[i].velocity.x = (rand() % (MAX_SPEED * 2 + 1)) - MAX_SPEED;
            allplayers[i].velocity.y = (rand() % (MAX_SPEED * 2 + 1)) - MAX_SPEED;
        }
    }

	PlayerCharacter = CDodger("orangeshipspritesheet.bmp", WINDOW_WIDTH/2, 50, 0, 0); // Initializes the object with its image.
	PlayerCharacter.load_ship_sheet(renderer);
	PlayerCharacter.set_sheet("orangeshipspritesheet.bmp"); // Added to try to animate ship.
	if (PlayerCharacter.load_ship_sheet(renderer) != 0)
	{
		printf("Bad load of Player Character animation file\n");
	}
	// Added to try to animate ship.
	PlayerCharacter.config_sheet(5, 0, 50, 91, 144, 5, 1, 0); // Spritesheet configuration. 
	PlayerCharacter.position.h = PlayerCharacter.images[0].h;
	PlayerCharacter.position.h = PlayerCharacter.images[0].w;
	PlayerCharacter.position.x = 50;
	PlayerCharacter.position.y = 510;
    return true;
}




//==============================================================================
