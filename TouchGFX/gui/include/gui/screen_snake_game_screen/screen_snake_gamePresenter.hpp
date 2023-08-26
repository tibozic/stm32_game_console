#ifndef SCREEN_SNAKE_GAMEPRESENTER_HPP
#define SCREEN_SNAKE_GAMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class screen_snake_gameView;

class screen_snake_gamePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    screen_snake_gamePresenter(screen_snake_gameView& v);

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

    virtual ~screen_snake_gamePresenter() {}

private:
    screen_snake_gamePresenter();

    screen_snake_gameView& view;
};

#endif // SCREEN_SNAKE_GAMEPRESENTER_HPP
