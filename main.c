#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

// Размеры окна/глубина рекурсии
#define WINDOW_WIDTH  729
#define WINDOW_HEIGHT 729
#define MAX_DEPTH 6

// Рекурсивная функция рисования ковра Серпинского
void drawCarpet(SDL_Renderer* renderer, int x, int y, int size, int depth);


int main(int argc, char* argv[]) {

    // Создание окна
    SDL_Window* window = SDL_CreateWindow(
        "Sierpinski carpet",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );


    // Создание рендерера
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
//      делаем экран белым
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

//      рисуем черные квадраты
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        drawCarpet(renderer, 0, 0, WINDOW_WIDTH, MAX_DEPTH);

        SDL_RenderPresent(renderer);
    }

    // Освобождение ресурсов
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}







void drawCarpet(SDL_Renderer* renderer, int x, int y, int size, int depth) {
    if (depth == 0) {
        SDL_Rect rect = {x, y, size, size};
        SDL_RenderFillRect(renderer, &rect);
        return;
    }

    int nSize = size / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            drawCarpet(renderer,
                               x + i * nSize,
                               y + j * nSize,
                               nSize,
                               depth - 1);
        }
    }
}
