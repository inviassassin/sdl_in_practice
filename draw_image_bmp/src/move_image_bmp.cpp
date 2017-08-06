#include <SDL2/SDL.h>

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *pWindow = SDL_CreateWindow("Move", 100, 100, 800, 480, 0);
    SDL_Surface *pWindowSurface = SDL_GetWindowSurface(pWindow);

    SDL_Surface* pImageSurface = SDL_LoadBMP("assassin.bmp");

    SDL_Rect dstRect = {0, 0, 0, 0};
    int speed = 1;

    bool isRunning = true;
    SDL_Event event;
    while(isRunning)
    {
        //draw
        SDL_FillRect(pWindowSurface, NULL, 0x3b5999);
        SDL_BlitSurface(pImageSurface, NULL, pWindowSurface, &dstRect);
        SDL_UpdateWindowSurface(pWindow);

        //update
        dstRect.x += speed;
        if (dstRect.x > 700 || dstRect.x < 0)
            speed = -speed;

        //handle input
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
    }

    //destroy
    SDL_FreeSurface(pImageSurface);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}
