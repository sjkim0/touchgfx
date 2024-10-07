#include <gui/screen_screen/screenView.hpp>

screenView::screenView()
{

}

void screenView::setupScreen()
{
    screenViewBase::setupScreen();
}

void screenView::tearDownScreen()
{
    screenViewBase::tearDownScreen();
}

int a = 0;
int count = 0;
int max_count = 1;
int catched = 0;

void screenView::gfxTickCallback()
{
    if(count > max_count)
    {
        count %= max_count;
        if(a == 0)
        {
            a = 1;
            for(int i = 0; i < 10; i++)
            {
                flxbutt_tb_0_0Buffer[i] = '\0';
            }
            flxbutt_tb_0_0.invalidate();
        }

        Unicode::snprintf(flxbutt_tb_0_0Buffer, FLXBUTT_TB_0_0_SIZE, "%d", catched);

        flxbutt_tb_0_0.invalidate();
        catched += 1;
    }
    count += 1;
}
