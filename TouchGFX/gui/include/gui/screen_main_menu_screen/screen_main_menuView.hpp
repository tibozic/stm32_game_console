#ifndef SCREEN_MAIN_MENUVIEW_HPP
#define SCREEN_MAIN_MENUVIEW_HPP

#include <gui_generated/screen_main_menu_screen/screen_main_menuViewBase.hpp>
#include <gui/screen_main_menu_screen/screen_main_menuPresenter.hpp>

class screen_main_menuView : public screen_main_menuViewBase
{
public:
    screen_main_menuView();
    virtual ~screen_main_menuView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREEN_MAIN_MENUVIEW_HPP
