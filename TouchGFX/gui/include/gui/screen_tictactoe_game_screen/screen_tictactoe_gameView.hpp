#ifndef SCREEN_TICTACTOE_GAMEVIEW_HPP
#define SCREEN_TICTACTOE_GAMEVIEW_HPP

#include <gui_generated/screen_tictactoe_game_screen/screen_tictactoe_gameViewBase.hpp>
#include <gui/screen_tictactoe_game_screen/screen_tictactoe_gamePresenter.hpp>
#include <touchgfx/Color.hpp>

class screen_tictactoe_gameView : public screen_tictactoe_gameViewBase
{
public:
    screen_tictactoe_gameView();
    virtual ~screen_tictactoe_gameView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void pos1_clicked();
    virtual void pos2_clicked();
    virtual void pos3_clicked();
    virtual void pos4_clicked();
    virtual void pos5_clicked();
    virtual void pos6_clicked();
    virtual void pos7_clicked();
    virtual void pos8_clicked();
    virtual void pos9_clicked();

    virtual short is_game_over(int x, int y);

    virtual void handleTickEvent();
protected:
};

#endif // SCREEN_TICTACTOE_GAMEVIEW_HPP
