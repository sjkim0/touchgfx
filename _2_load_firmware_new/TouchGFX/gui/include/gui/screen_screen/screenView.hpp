#ifndef SCREENVIEW_HPP
#define SCREENVIEW_HPP

#include <ap_viewmodel.hpp>
#include <gui_generated/screen_screen/screenViewBase.hpp>
#include <gui/screen_screen/screenPresenter.hpp>

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
    bool image_shown;
    ApViewModel ap_vm;

    virtual void containerTest(void);
    virtual void wildcardTest(void);
    virtual void imageTest(void);
};

class TouchControllerMy : public TouchController
{

};


#endif // SCREENVIEW_HPP
