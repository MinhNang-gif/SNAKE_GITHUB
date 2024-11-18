#include "dieukhien.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void dieukhien::ChangeDirection(Snake& snake, Snake::Direction input,
    Snake::Direction opposite) const {
    if (snake.direction != opposite || snake.size == 1) snake.direction = input;
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
                if (snake.direction != Snake::Direction::kDown) {
                    ChangeDirection(snake, Snake::Direction::kUp,
                        Snake::Direction::kDown);
                }
                break;

            case SDLK_DOWN:
                if (snake.direction != Snake::Direction::kUp) {
                    ChangeDirection(snake, Snake::Direction::kDown,
                        Snake::Direction::kUp);
                }
                break;

            case SDLK_LEFT:
                if (snake.direction != Snake::Direction::kRight) {
                    ChangeDirection(snake, Snake::Direction::kLeft,
                        Snake::Direction::kRight);
                }
                break;

            case SDLK_RIGHT:
                if (snake.direction != Snake::Direction::kLeft) {
                    ChangeDirection(snake, Snake::Direction::kRight,
                        Snake::Direction::kLeft);
                }
                break;
            }
        }
    }
}
