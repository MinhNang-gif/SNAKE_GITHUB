#pragma once
#ifndef SNAKE_H
#define SNAKE_H
#define SDL_MAIN_HANDLED
#include <vector>
#include "SDL.h"
class Snake {
public:
    enum class Direction { kUp, kDown, kLeft, kRight };
    Snake(int grid_width, int grid_height, float speed)
        : grid_width(grid_width),
        grid_height(grid_height),
        speed(speed),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}
    void Update();
    void GrowBody();
    bool SnakeCell(int x, int y);
    Direction direction = Direction::kUp;
    float speed;
    int size{ 1 };
    bool alive{ true };
    float head_x;
    float head_y;
    std::vector<SDL_Point> body;
private:
    void UpdateHead();
    void UpdateBody(SDL_Point& current_cell, SDL_Point& prev_cell);
    bool growing{ false };
    int grid_width;
    int grid_height;
};
#endif