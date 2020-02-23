//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnRender()
{
	// Try to put all objects that are being rendered in here. Be careful of your render order!

    /* Update the screen! */
    SDL_RenderPresent(renderer);
    SDL_Delay(10);
    SDL_Delay(time_left());
    next_time += TICK_INTERVAL;
}

//==============================================================================
