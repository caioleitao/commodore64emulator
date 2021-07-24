//
// Created by Kyle on 7/11/21.
//

#ifndef COMMODORE64EMULATOR_IO_H
#define COMMODORE64EMULATOR_IO_H

#include <SDL.h>
#include <queue>
#include <chrono>
#include <thread>
#include <vector>
#include <utility>
#include <unordered_map>

#include "cpu.h"
#include "util.h"

class IO {
private:
    *cpu_;
    SDL_Window *window_;
    SDL_Renderer *renderer;
    SDL_Texture *texture_;
    SDL_PixelFormat *format_;
    uint32_t *frame;
    size_t cols_;
    size_t rows_;
    unsigned int color_palette[16];
    uint8_t keyboard_matrix_[8];
    bool retval_ = true;

    std::unordered_map<SDL_Keycode,std::pair<int,int>> keymap_;
    std::unordered_map<char,std::vector<SDL_Keycode>> charmap_;
    enum kKeyEvent {
        kPress,
        kRelease,
    };

    std::quene<std::pair<kKeyEvent,SDL_Keycode>> key_event_queue_;
    unsigned int next_key_event_at_;
    static const int kWait = 18000;

    std::chrono::high_resolution_clock::time_point prev_frame_was_at_;
    void vsync();

public:
    IO();
    ~IO();
    bool emulate();
    void process_events();
    void cpu(Cpu *v){cpu_=v;};
    void init_color_palette();
    void handle_keyboard(SDL_Keycode k);
    void handle_keyup(SDL_Keycode k);
    void type_character(char c);
    inline uint8_t  keyboard_matrix_row(int col){return keyboard_matrix_[col];};
    void screen_update_pixel(int x,int y, int color);
    void screen_draw_rect(int x,int y, int n, int color);
    void screen_draw_border(int y, int color);
    void screen_refresh();
};

inline void IO::screen_update_pixel(int x,int y,int color) {
  frame_[y * cols_ + x] = color_palette[color & 0xf];
};
#endif //COMMODORE64EMULATOR_IO_H
