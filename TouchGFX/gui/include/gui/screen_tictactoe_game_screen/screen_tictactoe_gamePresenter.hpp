#ifndef SCREEN_TICTACTOE_GAMEPRESENTER_HPP
#define SCREEN_TICTACTOE_GAMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class screen_tictactoe_gameView;

class screen_tictactoe_gamePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    screen_tictactoe_gamePresenter(screen_tictactoe_gameView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~screen_tictactoe_gamePresenter() {}

private:
    screen_tictactoe_gamePresenter();

    screen_tictactoe_gameView& view;
};

#endif // SCREEN_TICTACTOE_GAMEPRESENTER_HPP
