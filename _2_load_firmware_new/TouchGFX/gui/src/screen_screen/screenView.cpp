#include <gui/screen_screen/screenView.hpp>

screenView::screenView()
{
    ap_touchgfx_inst.init();
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
        ap_touchgfx_inst.loop();
        count %= max_count;
        if(a == 0)
        {
            a = 1;
            for(int i = 0; i < 10; i++)
            {
                flxbutt_tb_0_0Buffer[i] = '\0';
                flxbutt_tb_0_1Buffer[i] = '\0';
                flxbutt_tb_0_2Buffer[i] = '\0';
                flxbutt_tb_0_3Buffer[i] = '\0';
                flxbutt_tb_1_0Buffer[i] = '\0';
                flxbutt_tb_1_1Buffer[i] = '\0';
                flxbutt_tb_1_2Buffer[i] = '\0';
                flxbutt_tb_1_3Buffer[i] = '\0';
                flxbutt_tb_2_0Buffer[i] = '\0';
                flxbutt_tb_2_1Buffer[i] = '\0';
                flxbutt_tb_2_2Buffer[i] = '\0';
                flxbutt_tb_2_3Buffer[i] = '\0';
                flxbutt_tb_3_0Buffer[i] = '\0';
                flxbutt_tb_3_1Buffer[i] = '\0';
                flxbutt_tb_3_2Buffer[i] = '\0';
                flxbutt_tb_3_3Buffer[i] = '\0';
                flxbutt_tb_4_0Buffer[i] = '\0';
                flxbutt_tb_4_1Buffer[i] = '\0';
                flxbutt_tb_4_2Buffer[i] = '\0';
                flxbutt_tb_4_3Buffer[i] = '\0';
            }
            flxbutt_tb_0_0.invalidate();
            flxbutt_tb_0_1.invalidate();
            flxbutt_tb_0_2.invalidate();
            flxbutt_tb_0_3.invalidate();
            flxbutt_tb_1_0.invalidate();
            flxbutt_tb_1_1.invalidate();
            flxbutt_tb_1_2.invalidate();
            flxbutt_tb_1_3.invalidate();
            flxbutt_tb_2_0.invalidate();
            flxbutt_tb_2_1.invalidate();
            flxbutt_tb_2_2.invalidate();
            flxbutt_tb_2_3.invalidate();
            flxbutt_tb_3_0.invalidate();
            flxbutt_tb_3_1.invalidate();
            flxbutt_tb_3_2.invalidate();
            flxbutt_tb_3_3.invalidate();
            flxbutt_tb_4_0.invalidate();
            flxbutt_tb_4_1.invalidate();
            flxbutt_tb_4_2.invalidate();
            flxbutt_tb_4_3.invalidate();
        }

        Unicode::snprintf(flxbutt_tb_0_0Buffer, FLXBUTT_TB_0_0_SIZE, "%d", catched);
        Unicode::snprintf(flxbutt_tb_0_1Buffer, FLXBUTT_TB_0_1_SIZE, "%d", catched);
        Unicode::snprintf(flxbutt_tb_0_2Buffer, FLXBUTT_TB_0_2_SIZE, "%d", catched);
        Unicode::snprintf(flxbutt_tb_0_3Buffer, FLXBUTT_TB_0_3_SIZE, "%d", catched);

        Unicode::snprintf(flxbutt_tb_1_0Buffer, FLXBUTT_TB_0_0_SIZE, "%d", catched);
        Unicode::snprintf(flxbutt_tb_1_1Buffer, FLXBUTT_TB_0_1_SIZE, "%d", catched);
        Unicode::snprintf(flxbutt_tb_1_2Buffer, FLXBUTT_TB_0_2_SIZE, "%d", catched);
        Unicode::snprintf(flxbutt_tb_1_3Buffer, FLXBUTT_TB_0_3_SIZE, "%d", catched);

        Unicode::snprintf(flxbutt_tb_2_0Buffer, FLXBUTT_TB_0_0_SIZE, "%d", catched);
        Unicode::snprintf(flxbutt_tb_2_1Buffer, FLXBUTT_TB_0_1_SIZE, "%d", catched);
        Unicode::snprintf(flxbutt_tb_2_2Buffer, FLXBUTT_TB_0_2_SIZE, "%d", catched);
        Unicode::snprintf(flxbutt_tb_2_3Buffer, FLXBUTT_TB_0_3_SIZE, "%d", catched);

        Unicode::snprintf(flxbutt_tb_3_0Buffer, FLXBUTT_TB_0_0_SIZE, "%d", catched);
        Unicode::snprintf(flxbutt_tb_3_1Buffer, FLXBUTT_TB_0_1_SIZE, "%d", catched);
        Unicode::snprintf(flxbutt_tb_3_2Buffer, FLXBUTT_TB_0_2_SIZE, "%d", catched);
        Unicode::snprintf(flxbutt_tb_3_3Buffer, FLXBUTT_TB_0_3_SIZE, "%d", catched);

        Unicode::snprintf(flxbutt_tb_4_0Buffer, FLXBUTT_TB_0_0_SIZE, "%d", catched);
        Unicode::snprintf(flxbutt_tb_4_1Buffer, FLXBUTT_TB_0_1_SIZE, "%d", catched);
        Unicode::snprintf(flxbutt_tb_4_2Buffer, FLXBUTT_TB_0_2_SIZE, "%d", catched);
        Unicode::snprintf(flxbutt_tb_4_3Buffer, FLXBUTT_TB_0_3_SIZE, "%d", catched);

        flxbutt_tb_0_0.invalidate();
        flxbutt_tb_0_1.invalidate();
        flxbutt_tb_0_2.invalidate();
        flxbutt_tb_0_3.invalidate();
        flxbutt_tb_1_0.invalidate();
        flxbutt_tb_1_1.invalidate();
        flxbutt_tb_1_2.invalidate();
        flxbutt_tb_1_3.invalidate();
        flxbutt_tb_2_0.invalidate();
        flxbutt_tb_2_1.invalidate();
        flxbutt_tb_2_2.invalidate();
        flxbutt_tb_2_3.invalidate();
        flxbutt_tb_3_0.invalidate();
        flxbutt_tb_3_1.invalidate();
        flxbutt_tb_3_2.invalidate();
        flxbutt_tb_3_3.invalidate();
        flxbutt_tb_4_0.invalidate();
        flxbutt_tb_4_1.invalidate();
        flxbutt_tb_4_2.invalidate();
        flxbutt_tb_4_3.invalidate();
        catched += 1;
    }
    count += 1;
}
