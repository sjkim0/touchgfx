#ifndef SCREENVIEW_HPP
#define SCREENVIEW_HPP

#include <gui_generated/screen_screen/screenViewBase.hpp>
#include <gui/screen_screen/screenPresenter.hpp>
#include "ap_touchgfx.hpp"

class screenView : public screenViewBase
{
public:
    screenView();
    virtual ~screenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void gfxTickCallback();
protected:
private:
    ApTouchGfx ap_touchgfx_inst;

    virtual void containerTest(void);
    virtual void wildcardTest(void);
};

#endif // SCREENVIEW_HPP
