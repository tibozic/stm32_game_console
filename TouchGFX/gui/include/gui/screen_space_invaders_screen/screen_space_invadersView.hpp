#ifndef SCREEN_SPACE_INVADERSVIEW_HPP
#define SCREEN_SPACE_INVADERSVIEW_HPP

#include <gui_generated/screen_space_invaders_screen/screen_space_invadersViewBase.hpp>
#include <gui/screen_space_invaders_screen/screen_space_invadersPresenter.hpp>
#include <images/BitmapDatabase.hpp>

#define NUM_OF_ENEMIES_PER_ROW 6
#define NUM_OF_ROWS_OF_ENEMIES 2
#define NUM_OF_ENEMIES NUM_OF_ENEMIES_PER_ROW*NUM_OF_ROWS_OF_ENEMIES

#define SPACE_BETWEEN_ENEMIES_X 15
#define SPACE_BETWEEN_ENEMIES_Y 0

#define BULLET_MOVE_SPEED 10
#define SHIP_MOVE_SPEED 10
#define ENEMY_MOVE_SPEED 10

#define MOVE_LEFT 0
#define MOVE_RIGHT 1
#define MOVE_UP 2
#define MOVE_DOWN 3

#define SCREEN_WIDTH 470
#define SCREEN_HEIGHT 262

class screen_space_invadersView : public screen_space_invadersViewBase
{
public:
    screen_space_invadersView();
    virtual ~screen_space_invadersView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();

    virtual void fire_bullet();
    virtual void check_bullet_hitbox();
    virtual void check_game_over();

    virtual int pseudo_random(int tick);
protected:
};

#endif // SCREEN_SPACE_INVADERSVIEW_HPP
