#include "Renderer.h"

Renderer::Renderer() : mSdlRenderer(nullptr)
{
}

//Initialize renderer
bool Renderer::Initialize(Window& rWindow)
{
    mSdlRenderer = SDL_CreateRenderer(rWindow.GetSdlWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!mSdlRenderer)
    {
        Log::Error(LogType::Video, "Failed to create Renderer");
        return false;
    }
    return true;
}

//Draw
void Renderer::BeginDraw()
{
    //Background Color
    SDL_SetRenderDrawColor(mSdlRenderer, 120, 120, 255, 255);
    SDL_RenderClear(mSdlRenderer);
}

//End Draw
void Renderer::EndDraw()
{
    SDL_RenderPresent(mSdlRenderer);
}

//Close Game
void Renderer::Close()
{
    SDL_DestroyRenderer(mSdlRenderer);
}

//Draw Rectangle
void Renderer::DrawRect(Rectangle& rRect)
{
    SDL_SetRenderDrawColor(mSdlRenderer, 255, 255, 255, 255);
    SDL_Rect sdlRect = rRect.ToSdlRect();
    SDL_RenderFillRect(mSdlRenderer, &sdlRect);
}



