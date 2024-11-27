#pragma once
#ifndef GAME_H
#define GAME_H
#include <random>
#include "SDL.h"
#include "dieukhien.h"
#include "dohoa.h"
#include "snake.h"

class game {
public:
    game(std::size_t grid_width, std::size_t grid_height, float speed);
    void Run(dieukhien const& controller, dohoa& renderer,
        std::size_t target_frame_duration);
    int GetScore() const;
    int GetSize() const;
private:
    Snake snake;
    SDL_Point food;
    std::size_t grid_width;
    std::size_t grid_height;
    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;
    int score{ 0 };
    void PlaceFood();
    void Update();
};
#endif