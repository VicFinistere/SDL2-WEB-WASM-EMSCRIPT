#include <assert.h>
#include <SDL2/SDL.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

SDL_Window * window;
SDL_Renderer * renderer;

int done = 0; // Main loop flag (in desktop mode)
int frameCount = 0;

void render()
{
    int w,h;
    SDL_GetWindowSize(window, &w,&h);

    // Clear background
    SDL_SetRenderDrawColor(renderer, 10, 25, 50, 255);
    SDL_RenderClear(renderer);

    // Draw some lines
    frameCount +=1;
    for (int r=frameCount %20; r<w; r+=20)
    {
        SDL_SetRenderDrawColor(renderer, 64-r/20, 64-r/10, 255-r/3, 255);
        SDL_RenderDrawLine(renderer, 0, 0, r, h);
        SDL_RenderDrawLine(renderer, w, h, w-r,0);
    }
    SDL_RenderPresent(renderer);
}

void mainloop_func(void)
{
    // Draw our Scene
    render();
    // Check for SDL Events
    SDL_Event event;
    while( SDL_PollEvent( &event ) )
    {
        switch(event.type)
        {
        case SDL_QUIT:
            done = 1;
            break;
        default:
            printf("[%u] Event Type=%d\n", SDL_GetTicks(), event.type);  //to stdout
            //SDL_Log("[%u] Event Type=%d", SDL_GetTicks(), event.type); //to JS console
            break;
        }
    }
}

int main(int argc, char* argv[])
{
    // Initialize SDL ideo subsystem and create a 640x480 window, and a renderer
    assert(SDL_Init(SDL_INIT_VIDEO) == 0);
    SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
#ifdef EMSCRIPTEN
    // Setup periodic call of our mainloop. Framerate is controlled by the web browser.
    emscripten_set_main_loop(mainloop_func, 0, 0);
    // Exit main() but keep web application running
    emscripten_exit_with_live_runtime();
#else
    // In desktop mode, we call continuously our main loop function, and wait 10mili seconds.
    while(done==0)
    {
        mainloop_func();
        SDL_Delay(10);
    }
#endif
    // This is actually never executed with EMSCRIPTEN enabled
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
