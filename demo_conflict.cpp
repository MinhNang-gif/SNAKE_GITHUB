#include "Snake.h"
#include <cmath>
#include <iostream>
void Snake::Update() {
    SDL_Point prev_cell{
        static_cast<int>(head_x),
        static_cast<int>(head_y)
    };
    UpdateHead(); // Không đổi hàm
    SDL_Point current_cell{
        static_cast<int>(head_x),
        static_cast<int>(head_y)
    };
    if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
        UpdateBody(current_cell, prev_cell);
    }
    // Thêm log thông tin cập nhật
    std::cout << "Snake position updated: " << current_cell.x << ", " << current_cell.y << std::endl;
}

void Snake::UpdateHead() {
    switch (direction) {
    case Direction::kUp:
        head_y -= speed;
        break;

    case Direction::kDown:
        head_y += speed;
        break;

    case Direction::kLeft:
        head_x -= speed;
        break;

    case Direction::kRight:
        head_x += speed;
        break;
    }

    if (head_x < 0 || head_y < 0 || head_x >= grid_width || head_y >= grid_height) {
        alive = false;
    }
}
void Snake::UpdateBody(SDL_Point& current_head_cell, SDL_Point& prev_head_cell) {
    body.push_back(prev_head_cell);

    if (!growing) {
        body.erase(body.begin());
    }
    else {
        growing = false;
        size++;
    }
    for (auto const& item : body) {
        if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
            alive = false;
        }
    }
}
void Snake::GrowBody() {
    growing = true;
}
bool Snake::SnakeCell(int x, int y) {
    if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
        return true;
    }
    for (auto const& item : body) {
        if (x == item.x && y == item.y) {
            return true;
        }
    }
    return false;
}