#include <SDL2/SDL.h>

int main()
{
    //init
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* pWindow = SDL_CreateWindow("Move", 100, 100, 500, 500, 0);
    SDL_Surface* pWindowSurface = SDL_GetWindowSurface(pWindow);
    SDL_FillRect(pWindowSurface, NULL, 0x3b5999);

    //load image
    SDL_Surface* pImageSurface = SDL_LoadBMP("assassin.bmp");

    SDL_Rect srcRect = {30, 30, 120, 120};

    //draw image
    SDL_BlitSurface(pImageSurface, &srcRect, pWindowSurface, NULL);
    SDL_UpdateWindowSurface(pWindow);
    SDL_Delay(5000);

    //destroy
    SDL_FreeSurface(pImageSurface);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}
