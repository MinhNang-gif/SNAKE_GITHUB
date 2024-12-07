
#pragma once  // Chỉ thị này giúp đảm bảo file header chỉ được include một lần trong quá trình biên dịch.

// Kiểm tra định nghĩa macro để tránh việc include file header nhiều lần.
#ifndef GAME_H
#define GAME_H

#include <random>  // Sử dụng để sinh số ngẫu nhiên.
#include "SDL.h"   // Thư viện SDL để quản lý đồ họa và đầu vào.
#include "dieukhien.h"  // Header định nghĩa lớp điều khiển (controller).
#include "dohoa.h"      // Header định nghĩa lớp đồ họa (renderer).
#include "snake.h"      // Header định nghĩa lớp Snake (rắn)
// Định nghĩa lớp `game`, quản lý logic trò chơi.
class game {
public:
    // Constructor: Khởi tạo trò chơi với kích thước lưới và tốc độ ban đầu.
    game(std::size_t grid_width, std::size_t grid_height, float speed);

    // Hàm điều khiển vòng lặp chính của trò chơi.
    void Run(dieukhien const& controller, dohoa& renderer,
             std::size_t target_frame_duration);

    // Hàm trả về điểm số hiện tại.
    int GetScore() const;

    // Hàm trả về kích thước hiện tại của rắn.
    int GetSize() const;

private:
    Snake snake;  // Đối tượng rắn đại diện cho người chơi.
    SDL_Point food;  // Tọa độ của thức ăn trên bản đồ.
    std::size_t grid_width;  // Chiều rộng của lưới trò chơi.
    std::size_t grid_height; // Chiều cao của lưới trò chơi.

    // Các công cụ sinh số ngẫu nhiên.
    std::random_device dev;  // Sinh số ngẫu nhiên dựa trên phần cứng.
    std::mt19937 engine;     // Bộ tạo số ngẫu nhiên (Mersenne Twister).
    std::uniform_int_distribution<int> random_w;  // Phân phối ngẫu nhiên trong phạm vi chiều rộng.
    std::uniform_int_distribution<int> random_h;  // Phân phối ngẫu nhiên trong phạm vi chiều cao.

    int score{ 0 };  // Biến lưu trữ điểm số hiện tại.

    // Đặt vị trí ngẫu nhiên cho thức ăn.
    void PlaceFood();

    // Cập nhật trạng thái trò chơi (rắn, thức ăn, điểm số, ...).
    void Update();
};

#endif

