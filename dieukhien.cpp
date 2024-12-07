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

// Hàm xử lý đầu vào từ người chơi
void dieukhien::HandleInput(bool& running, Snake& snake) const {
    SDL_Event e; // Biến lưu sự kiện SDL.
    // Vòng lặp kiểm tra các sự kiện trong hàng đợi sự kiện
    while (SDL_PollEvent(&e)) {
        // Nếu sự kiện là thoát (QUIT), dừng chương trình.
        if (e.type == SDL_QUIT) {
            running = false;
        }
        // Nếu sự kiện là nhấn phím (KEYDOWN)
        else if (e.type == SDL_KEYDOWN) {
            // Xác định phím nào được nhấn
            switch (e.key.keysym.sym) {
           case SDLK_UP: // Phím mũi tên lên
                // Thay đổi hướng sang lên nếu hướng hiện tại không phải xuống
                ChangeDirection(snake, Snake::Direction::kUp,
                    Snake::Direction::kDown);
                break;

            case SDLK_DOWN: // Phím mũi tên xuống
                // Thay đổi hướng sang xuống nếu hướng hiện tại không phải lên
                ChangeDirection(snake, Snake::Direction::kDown,
                    Snake::Direction::kUp);
                break;

           case SDLK_LEFT: // Phím mũi tên trái
                // Thay đổi hướng sang trái nếu hướng hiện tại không phải phải
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