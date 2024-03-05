#include "bits/stdc++.h"
#include "SDL.h"

using namespace std;

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;
const char* WINDOW_TITLE = "Hello World!";

void logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

SDL_Window* initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logErrorAndExit("SDL_Init", SDL_GetError());

    SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //full screen
    //SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

    return window;
}

SDL_Renderer* createRenderer(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy trong máy ảo (ví dụ phòng máy ở trường)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

    if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    return renderer;
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) ) return;
        //if (e.type == SDL_QUIT) return;
        SDL_Delay(10);
    }
}

void clrscr(SDL_Renderer* renderer)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

void drawFilledCircle(SDL_Renderer *renderer, int centerX, int centerY, int radius) {
    for(int i = -radius; i <= radius; i++)
        for(int j = -radius; j <= radius; j++)
            {
                if (i * i + j * j <= radius * radius)
                    { SDL_RenderDrawPoint(renderer, centerX + i, centerY + j); }
            }
}

void drawCircleLine(SDL_Renderer *renderer, int centerX, int centerY, int radius)
    {

        for(int i = -radius; i <= radius; i++)
            for(int j = -radius; j <= radius; j++)
                {
                    if (i * i + j * j == radius * radius)
                        { SDL_RenderDrawPoint(renderer, centerX + i, centerY + j); }
                }
    }

void drawSomething(SDL_Window* window, SDL_Renderer* renderer)
{
    // SDL_Rect filled_rect;
    // filled_rect.x = SCREEN_WIDTH / 2 - 600;
    // filled_rect.y = SCREEN_HEIGHT / 2- 300;
    // filled_rect.w = 1200;
    // filled_rect.h = 600;
    // SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // green
    // SDL_RenderFillRect(renderer, &filled_rect);

    // SDL_Rect inner_rect;
    // inner_rect.x = filled_rect.x + 20;
    // inner_rect.y = filled_rect.y + 20;
    // inner_rect.w = 1160;
    // inner_rect.h = 560;
    // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
    // SDL_RenderFillRect(renderer, &inner_rect);

    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white

    // SDL_Rect filled_rect;
    // filled_rect.x = SCREEN_WIDTH / 2 - 600;
    // filled_rect.y = SCREEN_HEIGHT / 2 - 300;
    // filled_rect.w = 1200;
    // filled_rect.h = 600;
    // SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // green
    // SDL_RenderFillRect(renderer, &filled_rect);

    // SDL_Rect inner_rect;
    // inner_rect.x = filled_rect.x + 20;
    // inner_rect.y = filled_rect.y + 20;
    // inner_rect.w = 1160;
    // inner_rect.h = 560;
    // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
    // SDL_RenderFillRect(renderer, &inner_rect);

    // for(int i = 1; i <= 150; i++)
    //     {
    //         SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
    //         drawFilledCircle(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, i);

    //         SDL_RenderPresent(renderer);
    //     }

    // for(int i = 150; i > 0; i--)
    //     {
    //         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
    //         drawFilledCircle(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, i);

    //         SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
    //         drawFilledCircle(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, i - 1);

    //         SDL_RenderPresent(renderer);
    //     }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
    drawCircleLine(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 300);
    SDL_RenderPresent(renderer);
}

void doSomeThing(SDL_Window* window, SDL_Renderer* renderer)
    {
        drawSomething(window, renderer);
    }

int main(int argc, char* argv[])
{
    //Khởi tạo môi trường đồ họa
    SDL_Window* window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Renderer* renderer = createRenderer(window);

    //Xóa màn hình
    SDL_RenderClear(renderer);

    //Vẽ gì đó
    doSomeThing(window, renderer);

    //Hiện bản vẽ ra màn hình
    //Khi chạy tại môi trường bình thường
    //Khi chạy trong máy ảo (ví dụ phòng máy ở trường)
    //SDL_UpdateWindowSurface(window);

    //waitUntilKeyPressed();
    //clrscr(renderer);

    //Đợi phím bất kỳ trước khi đóng môi trường đồ họa và kết thúc chương trình
    waitUntilKeyPressed();
    quitSDL(window, renderer);

    return 0;
}
