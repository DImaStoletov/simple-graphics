#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

// ������� ����/������� ��������
#define WINDOW_WIDTH  729
#define WINDOW_HEIGHT 729
#define MAX_DEPTH 6

// ����������� ������� ��������� ����� �����������
void drawCarpet(SDL_Renderer* renderer, int x, int y, int size, int depth);
#endif // FUNC_H_INCLUDED
