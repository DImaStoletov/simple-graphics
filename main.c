#include "func.h"
int main(int argc, char* argv[]) {

    // �������� ����
    SDL_Window* window = SDL_CreateWindow(
        "Sierpinski carpet",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );


    // �������� ���������
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );


    bool flag = true;
    SDL_Event event;

    while (flag) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                flag = false;
            }
        }
//      ������ ����� �����
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

//      ������ ������ ��������
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        drawCarpet(renderer, 0, 0, WINDOW_WIDTH, MAX_DEPTH);

        SDL_RenderPresent(renderer);
    }

    // ������������ ��������
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

