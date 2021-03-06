//==============================================================================
// SDL Tutorial 1
//==============================================================================
#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL.h>
#include "mywindow.h"
#include "CPlayer.h"
#include "CDodger.h" // Includes the CDodger header file.

#define TICK_INTERVAL    10
#define NUM_SPRITES     12
#define MAX_SPEED       1

//==============================================================================
class CApp
{
private:
    bool            Running;
    Uint32 next_time;
    SDL_Window *window;
    SDL_Renderer *renderer;
    CPlayer allplayers[NUM_SPRITES];
	CDodger PlayerCharacter; // Creates a CDodger object.

public:
    CApp();
    Uint32 time_left(void);
    int OnExecute();

public:
    bool OnInit();

    void OnEvent(SDL_Event* Event);

    void OnLoop();

    void OnRender();
    int LoadSprite(char *file, SDL_Texture* &psprite, SDL_Rect *prect);
    void MoveSprites();

    void OnCleanup();
};

//==============================================================================

#endif