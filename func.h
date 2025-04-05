#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

// Размеры окна/глубина рекурсии
#define WINDOW_WIDTH  729
#define WINDOW_HEIGHT 800
#define MAX_DEPTH 6
#define BUTTON_WIDTH 100
#define BUTTON_HEIGHT 25
#define BUTTON_MARGIN 10
extern int current_depth;
// Рекурсивная функция рисования ковра Серпинского
void drawCarpet(SDL_Renderer* renderer, int x, int y, int size, int depth);

void draw(SDL_Renderer* renderer);
#endif // FUNC_H_INCLUDED
