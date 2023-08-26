#ifndef SCREEN_SNAKE_GAMEVIEW_HPP
#define SCREEN_SNAKE_GAMEVIEW_HPP

#include <gui_generated/screen_snake_game_screen/screen_snake_gameViewBase.hpp>
#include <gui/screen_snake_game_screen/screen_snake_gamePresenter.hpp>
#include <touchgfx/Color.hpp>

#include "stm32h7xx_hal.h"

#define PIXEL_WIDTH 10
#define PIXEL_HEIGHT 10

#define SCREEN_WIDTH 470
#define SCREEN_HEIGHT 262

// snake stuff
#define SNAKE_SPEED 10 // higher number lower speed
#define SNAKE_MOVE 10
#define MAX_SNAKE_PIECES 2048

// directions
#define SNAKE_RIGHT 0
#define SNAKE_UP 1
#define SNAKE_LEFT 2
#define SNAKE_DOWN 3

// snake struct
typedef struct snake_piece {
	snake_piece *next;
	snake_piece *prev;
	touchgfx::Box *pixel;
	int old_x, old_y;
} snake_piece;



class screen_snake_gameView : public screen_snake_gameViewBase
{
public:
    screen_snake_gameView();
    virtual ~screen_snake_gameView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();

    virtual void game_snake_start();

    virtual void change_direction_up();
    virtual void change_direction_down();
    virtual void change_direction_left();
    virtual void change_direction_right();

    virtual int pseudo_random(int tick);
    virtual int pseudo_random2(int tick);

    virtual void error();
protected:
};

#endif // SCREEN_SNAKE_GAMEVIEW_HPP
