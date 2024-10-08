#include <gui/screen_screen/screenView.hpp>


screenView::screenView()
{
    ap_vm.init();
    this->image_shown = false;
}

void screenView::setupScreen()
{
    screenViewBase::setupScreen();
}

void screenView::tearDownScreen()
{
    screenViewBase::tearDownScreen();
}

void screenView::gfxTickCallback()
{
    ap_vm.loop();
    containerTest();
    wildcardTest();
    imageTest();
}

void screenView::containerTest(void)
{
    if(this->image_shown == false)
    {
        return;
    }
    static int visible_count = 0;
    const int visible_count_max = 50;
    static int table_visible_state = 0;
    /*
     *@brief: container change test
     */
    visible_count += 1;
    if(visible_count > visible_count_max)
    {
        visible_count %= visible_count_max;

        if(table_visible_state == 0)
        {
            // table 0
            table_visible_state = 1;

            container_table.setVisible(true);
            container_alc.setVisible(false);
            container_comm.setVisible(false);
            container_table.invalidate();
            container_alc.invalidate();
            container_comm.invalidate();
        }
        else if(table_visible_state == 1)
        {
            // table ALC
            table_visible_state = 2;
            container_table.setVisible(false);
            container_alc.setVisible(true);
            container_comm.setVisible(false);
            container_table.invalidate();
            container_alc.invalidate();
            container_comm.invalidate();
        }
        else
        {
            // table COMM
            table_visible_state = 0;
            container_table.setVisible(false);
            container_alc.setVisible(false);
            container_comm.setVisible(true);
            container_table.invalidate();
            container_alc.invalidate();
            container_comm.invalidate();
        }
    }
}

void screenView::imageTest(void)
{
    static int count = 0;
    const int count_max = 100;

    if(count < count_max)
    {
        count += 1;
    }
    else if(this->image_shown == false)
    {
        this->image_shown = true;
        image1.setVisible(false);
        image1.invalidate();

        container_menu.setVisible(true);
        container_descr.setVisible(true);
        container_state.setVisible(true);
        container_table.setVisible(true);
        container_menu.invalidate();
        container_descr.invalidate();
        container_state.invalidate();
        container_table.invalidate();
    }
}

void screenView::wildcardTest(void)
{
    /*
     *@brief: wild card test
     */
    if(this->image_shown == false)
    {
        return;
    }
    static int a = 0;
    static int count = 0;
    const int max_count = 1;
    static int catched = 0;
    if(count > max_count)
    {
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

