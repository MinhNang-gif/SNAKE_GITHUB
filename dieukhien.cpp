#include "dieukhien.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

class Snake {
public:
    enum class Direction { kUp, kDown, kLeft, kRight };
    Direction direction;
    int size;
    Uint32 last_direction_change; // Khai báo biến này để lưu thời gian thay đổi hướng

    // Constructor
    Snake() : direction(Direction::kUp), size(1), last_direction_change(0) {}
    // Hoặc khởi tạo mặc định trong hàm khởi tạo của bạn
};

// Thêm khoảng thời gian trì hoãn để tránh thay đổi hướng quá nhanh
constexpr Uint32 kDirectionChangeDelay = 100; // tính bằng mili giây

void dieukhien::ChangeDirection(Snake& snake, Snake::Direction input,
    Snake::Direction opposite) const {
    Uint32 current_time = SDL_GetTicks();
    if ((current_time - snake.last_direction_change) >= kDirectionChangeDelay) {
        if (snake.direction != opposite || snake.size == 1) {
            snake.direction = input;
            snake.last_direction_change = current_time; // Cập nhật thời gian thay đổi
        }
    }
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
