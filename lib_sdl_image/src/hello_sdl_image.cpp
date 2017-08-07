#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *pWindow = SDL_CreateWindow("SDL_image", 100, 100, 500, 500, 0);
    SDL_Surface *pWindowSurface = SDL_GetWindowSurface(pWindow);

    IMG_Init(IMG_INIT_PNG);
    SDL_Surface *pImageSurface = IMG_Load("assassin.png");

    SDL_FillRect(pWindowSurface, NULL, 0x3b5999);
    SDL_BlitSurface(pImageSurface, NULL, pWindowSurface, NULL);
    SDL_UpdateWindowSurface(pWindow);

    SDL_Delay(5000);

    SDL_FreeSurface(pImageSurface);
    SDL_DestroyWindow(pWindow);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
