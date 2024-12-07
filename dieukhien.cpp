#include "dieukhien.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

// Hàm thay đổi hướng di chuyển của rắn
void dieukhien::ChangeDirection(Snake& snake, Snake::Direction input,
    Snake::Direction opposite) const {
         // Nếu hướng hiện tại của rắn không phải là hướng đối diện (hoặc nếu rắn chỉ có một đoạn)
    // thì cho phép thay đổi hướng. Điều này ngăn rắn quay ngược về hướng cũ.
    if (snake.direction != opposite || snake.size == 1) 
        snake.direction = input;// Cập nhật hướng mới.
    return;
}

void dieukhien::HandleInput(bool& running, Snake& snake) const {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        }
        else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_UP:
                ChangeDirection(snake, Snake::Direction::kUp,
                    Snake::Direction::kDown);
                break;

            case SDLK_DOWN:
                ChangeDirection(snake, Snake::Direction::kDown,
                    Snake::Direction::kUp);
                break;

            case SDLK_LEFT:
                ChangeDirection(snake, Snake::Direction::kLeft,
                    Snake::Direction::kRight);
                break;

            case SDLK_RIGHT:
                ChangeDirection(snake, Snake::Direction::kRight,
                    Snake::Direction::kLeft);
                break;
            }
        }
    }
}