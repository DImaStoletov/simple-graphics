#include "func.h"

SDL_Rect buttons[MAX_DEPTH];
int current_depth = 0;

void drawButton(SDL_Renderer* renderer, int index, bool selected) {
    SDL_Color color = selected ? (SDL_Color){0, 0, 0, 255} : (SDL_Color){200, 200, 200, 255};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &buttons[index]);

}


void initButtons() {
    int total_width = (BUTTON_WIDTH + BUTTON_MARGIN) * (MAX_DEPTH + 1) - BUTTON_MARGIN;
    int start_x = (WINDOW_WIDTH - total_width) / 2;

    for (int i = 0; i <= MAX_DEPTH; i++) {
        buttons[i] = (SDL_Rect){
            start_x + i * (BUTTON_WIDTH + BUTTON_MARGIN),
            BUTTON_MARGIN,
            BUTTON_WIDTH,
            BUTTON_HEIGHT
        };
    }
}


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

    initButtons();
    bool flag = true;
    SDL_Event event;

    while (flag) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                flag = false;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = event.button.x;
                int mouseY = event.button.y;

                // Проверяем нажатие на кнопки
                for (int i = 0; i <= MAX_DEPTH; i++) {
                    if (mouseX >= buttons[i].x && mouseX <= buttons[i].x + buttons[i].w &&
                        mouseY >= buttons[i].y && mouseY <= buttons[i].y + buttons[i].h) {
                        current_depth = i;
                        break;
                    }
                }
            }
            draw(renderer);
        }

    }

    // Освобождение ресурсов
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

