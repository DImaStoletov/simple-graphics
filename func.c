#include "func.h"

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
