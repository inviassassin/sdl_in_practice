#include <SDL2/SDL.h>

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Hello World", 100, 100, 320, 320, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    bool isRunning = true;
    SDL_Event event;
    while (isRunning)
    {
        SDL_PollEvent(&event);

        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
