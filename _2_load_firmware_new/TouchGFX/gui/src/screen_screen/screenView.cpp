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
        // container_table.isVisible()
        count %= max_count;
        if(a == 0)
        {
            a = 1;
            for(int i = 0; i < 10; i++)
            {
                table_cell_0_0Buffer[i] = '\0';
                table_cell_0_1Buffer[i] = '\0';
                table_cell_0_2Buffer[i] = '\0';
                table_cell_0_3Buffer[i] = '\0';
                table_cell_1_0Buffer[i] = '\0';
                table_cell_1_1Buffer[i] = '\0';
                table_cell_1_2Buffer[i] = '\0';
                table_cell_1_3Buffer[i] = '\0';
                table_cell_2_0Buffer[i] = '\0';
                table_cell_2_1Buffer[i] = '\0';
                table_cell_2_2Buffer[i] = '\0';
                table_cell_2_3Buffer[i] = '\0';
                table_cell_3_0Buffer[i] = '\0';
                table_cell_3_1Buffer[i] = '\0';
                table_cell_3_2Buffer[i] = '\0';
                table_cell_3_3Buffer[i] = '\0';
                table_cell_4_0Buffer[i] = '\0';
                table_cell_4_1Buffer[i] = '\0';
                table_cell_4_2Buffer[i] = '\0';
                table_cell_4_3Buffer[i] = '\0';
            }
            table_cell_0_0.invalidate();
            table_cell_0_1.invalidate();
            table_cell_0_2.invalidate();
            table_cell_0_3.invalidate();
            table_cell_1_0.invalidate();
            table_cell_1_1.invalidate();
            table_cell_1_2.invalidate();
            table_cell_1_3.invalidate();
            table_cell_2_0.invalidate();
            table_cell_2_1.invalidate();
            table_cell_2_2.invalidate();
            table_cell_2_3.invalidate();
            table_cell_3_0.invalidate();
            table_cell_3_1.invalidate();
            table_cell_3_2.invalidate();
            table_cell_3_3.invalidate();
            table_cell_4_0.invalidate();
            table_cell_4_1.invalidate();
            table_cell_4_2.invalidate();
            table_cell_4_3.invalidate();
        }

        Unicode::snprintf(table_cell_0_0Buffer, TABLE_CELL_0_0_SIZE, "%d", catched);
        Unicode::snprintf(table_cell_0_1Buffer, TABLE_CELL_0_1_SIZE, "%d", catched);
        Unicode::snprintf(table_cell_0_2Buffer, TABLE_CELL_0_2_SIZE, "%d", catched);
        Unicode::snprintf(table_cell_0_3Buffer, TABLE_CELL_0_3_SIZE, "%d", catched);

        Unicode::snprintf(table_cell_1_0Buffer, TABLE_CELL_1_0_SIZE, "%d", catched);
        Unicode::snprintf(table_cell_1_1Buffer, TABLE_CELL_1_1_SIZE, "%d", catched);
        Unicode::snprintf(table_cell_1_2Buffer, TABLE_CELL_1_2_SIZE, "%d", catched);
        Unicode::snprintf(table_cell_1_3Buffer, TABLE_CELL_1_3_SIZE, "%d", catched);

        Unicode::snprintf(table_cell_2_0Buffer, TABLE_CELL_2_0_SIZE, "%d", catched);
        Unicode::snprintf(table_cell_2_1Buffer, TABLE_CELL_2_1_SIZE, "%d", catched);
        Unicode::snprintf(table_cell_2_2Buffer, TABLE_CELL_2_2_SIZE, "%d", catched);
        Unicode::snprintf(table_cell_2_3Buffer, TABLE_CELL_2_3_SIZE, "%d", catched);
        Unicode::snprintf(table_cell_3_0Buffer, TABLE_CELL_3_0_SIZE, "%d", catched);
        Unicode::snprintf(table_cell_3_1Buffer, TABLE_CELL_3_1_SIZE, "%d", catched);
        Unicode::snprintf(table_cell_3_2Buffer, TABLE_CELL_3_2_SIZE, "%d", catched);
        Unicode::snprintf(table_cell_3_3Buffer, TABLE_CELL_3_3_SIZE, "%d", catched);
        Unicode::snprintf(table_cell_4_0Buffer, TABLE_CELL_4_0_SIZE, "%d", catched);
        Unicode::snprintf(table_cell_4_1Buffer, TABLE_CELL_4_1_SIZE, "%d", catched);
        Unicode::snprintf(table_cell_4_2Buffer, TABLE_CELL_4_2_SIZE, "%d", catched);
        Unicode::snprintf(table_cell_4_3Buffer, TABLE_CELL_4_3_SIZE, "%d", catched);

        table_cell_0_0.invalidate();
        table_cell_0_1.invalidate();
        table_cell_0_2.invalidate();
        table_cell_0_3.invalidate();
        table_cell_1_0.invalidate();
        table_cell_1_1.invalidate();
        table_cell_1_2.invalidate();
        table_cell_1_3.invalidate();
        table_cell_2_0.invalidate();
        table_cell_2_1.invalidate();
        table_cell_2_2.invalidate();
        table_cell_2_3.invalidate();
        table_cell_3_0.invalidate();
        table_cell_3_1.invalidate();
        table_cell_3_2.invalidate();
        table_cell_3_3.invalidate();
        table_cell_4_0.invalidate();
        table_cell_4_1.invalidate();
        table_cell_4_2.invalidate();
        table_cell_4_3.invalidate();
        catched += 1;
    }
    count += 1;
}
