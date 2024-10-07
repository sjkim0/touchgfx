/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen_screen/screenViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

screenViewBase::screenViewBase()
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    container_frame.setPosition(0, 0, 800, 480);
    box4.setPosition(0, 190, 800, 290);
    box4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 50));
    container_frame.add(box4);

    box5.setPosition(0, 0, 800, 191);
    box5.setColor(touchgfx::Color::getColorFromRGB(0, 0, 90));
    container_frame.add(box5);

    add(container_frame);

    container_descript.setPosition(0, 0, 800, 191);
    textArea1.setXY(278, 28);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(70, 255, 255));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GK1D));
    container_descript.add(textArea1);

    textArea1_1.setXY(541, 28);
    textArea1_1.setColor(touchgfx::Color::getColorFromRGB(70, 255, 255));
    textArea1_1.setLinespacing(0);
    textArea1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QFGC));
    container_descript.add(textArea1_1);

    textArea1_1_1.setXY(694, 28);
    textArea1_1_1.setColor(touchgfx::Color::getColorFromRGB(70, 255, 255));
    textArea1_1_1.setLinespacing(0);
    textArea1_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_VXC4));
    container_descript.add(textArea1_1_1);

    boxWithBorder1.setPosition(174, 132, 150, 50);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(70, 255, 255));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorder1.setBorderSize(2);
    container_descript.add(boxWithBorder1);

    flexButton1.setBoxWithBorderPosition(0, 0, 65, 50);
    flexButton1.setBorderSize(2);
    flexButton1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255));
    flexButton1.setText(TypedText(T___SINGLEUSE_0RKS));
    flexButton1.setTextPosition(0, 12, 65, 50);
    flexButton1.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton1.setPosition(326, 132, 65, 50);
    container_descript.add(flexButton1);

    flexButton1_1.setBoxWithBorderPosition(0, 0, 65, 50);
    flexButton1_1.setBorderSize(2);
    flexButton1_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255));
    flexButton1_1.setText(TypedText(T___SINGLEUSE_R0Y6));
    flexButton1_1.setTextPosition(0, 12, 65, 50);
    flexButton1_1.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton1_1.setPosition(562, 132, 65, 50);
    container_descript.add(flexButton1_1);

    textArea2.setXY(214, 91);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(70, 255, 255));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QIZY));
    container_descript.add(textArea2);

    textArea2_1.setXY(455, 91);
    textArea2_1.setColor(touchgfx::Color::getColorFromRGB(70, 255, 255));
    textArea2_1.setLinespacing(0);
    textArea2_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_C4CN));
    container_descript.add(textArea2_1);

    textArea2_1_1.setXY(684, 91);
    textArea2_1_1.setColor(touchgfx::Color::getColorFromRGB(70, 255, 255));
    textArea2_1_1.setLinespacing(0);
    textArea2_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_JLP2));
    container_descript.add(textArea2_1_1);

    flexButton2.setBoxWithBorderPosition(0, 0, 150, 50);
    flexButton2.setBorderSize(2);
    flexButton2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton2.setText(TypedText(T___SINGLEUSE_E2Z8));
    flexButton2.setTextPosition(0, 12, 150, 50);
    flexButton2.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton2.setPosition(10, 12, 150, 50);
    container_descript.add(flexButton2);

    flexButton2_1.setBoxWithBorderPosition(0, 0, 150, 50);
    flexButton2_1.setBorderSize(2);
    flexButton2_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255));
    flexButton2_1.setText(TypedText(T___SINGLEUSE_MRQ0));
    flexButton2_1.setTextPosition(0, 12, 150, 50);
    flexButton2_1.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton2_1.setPosition(10, 72, 150, 50);
    container_descript.add(flexButton2_1);

    flexButton2_1_1.setBoxWithBorderPosition(0, 0, 150, 50);
    flexButton2_1_1.setBorderSize(2);
    flexButton2_1_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255));
    flexButton2_1_1.setText(TypedText(T___SINGLEUSE_YQKX));
    flexButton2_1_1.setTextPosition(0, 12, 150, 50);
    flexButton2_1_1.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton2_1_1.setPosition(10, 132, 150, 50);
    container_descript.add(flexButton2_1_1);

    flexButton3.setBoxWithBorderPosition(0, 0, 150, 50);
    flexButton3.setBorderSize(2);
    flexButton3.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton3.setText(TypedText(T___SINGLEUSE_E3W3));
    flexButton3.setTextPosition(0, 12, 150, 50);
    flexButton3.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton3.setPosition(174, 132, 150, 50);
    container_descript.add(flexButton3);

    flexButton3_1.setBoxWithBorderPosition(0, 0, 150, 50);
    flexButton3_1.setBorderSize(2);
    flexButton3_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton3_1.setText(TypedText(T___SINGLEUSE_MIC9));
    flexButton3_1.setTextPosition(0, 12, 150, 50);
    flexButton3_1.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton3_1.setPosition(409, 132, 150, 50);
    container_descript.add(flexButton3_1);

    flexButton3_1_1.setBoxWithBorderPosition(0, 0, 150, 50);
    flexButton3_1_1.setBorderSize(2);
    flexButton3_1_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton3_1_1.setText(TypedText(T___SINGLEUSE_RJKW));
    flexButton3_1_1.setTextPosition(0, 12, 150, 50);
    flexButton3_1_1.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton3_1_1.setPosition(640, 132, 150, 50);
    container_descript.add(flexButton3_1_1);

    line1.setPosition(690, 56, 100, 4);
    line1Painter.setColor(touchgfx::Color::getColorFromRGB(70, 255, 255));
    line1.setPainter(line1Painter);
    line1.setStart(2, 2);
    line1.setEnd(198, 2);
    line1.setLineWidth(4);
    line1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    container_descript.add(line1);

    line1_2.setPosition(482, 56, 200, 4);
    line1_2Painter.setColor(touchgfx::Color::getColorFromRGB(70, 255, 255));
    line1_2.setPainter(line1_2Painter);
    line1_2.setStart(2, 2);
    line1_2.setEnd(208, 2);
    line1_2.setLineWidth(4);
    line1_2.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    container_descript.add(line1_2);

    line1_1.setPosition(174, 56, 300, 4);
    line1_1Painter.setColor(touchgfx::Color::getColorFromRGB(70, 255, 255));
    line1_1.setPainter(line1_1Painter);
    line1_1.setStart(2, 2);
    line1_1.setEnd(340, 2);
    line1_1.setLineWidth(4);
    line1_1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    container_descript.add(line1_1);

    add(container_descript);

    container_menu.setPosition(-7, 191, 160, 289);
    flexButton2_1_1_1.setBoxWithBorderPosition(0, 0, 150, 50);
    flexButton2_1_1_1.setBorderSize(2);
    flexButton2_1_1_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255));
    flexButton2_1_1_1.setText(TypedText(T___SINGLEUSE_RGM6));
    flexButton2_1_1_1.setTextPosition(0, 12, 150, 50);
    flexButton2_1_1_1.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton2_1_1_1.setPosition(10, 49, 150, 50);
    container_menu.add(flexButton2_1_1_1);

    flexButton2_1_1_2.setBoxWithBorderPosition(0, 0, 150, 50);
    flexButton2_1_1_2.setBorderSize(2);
    flexButton2_1_1_2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255));
    flexButton2_1_1_2.setText(TypedText(T___SINGLEUSE_U7DZ));
    flexButton2_1_1_2.setTextPosition(0, 12, 150, 50);
    flexButton2_1_1_2.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton2_1_1_2.setPosition(10, 109, 150, 50);
    container_menu.add(flexButton2_1_1_2);

    flexButton2_1_1_2_1.setBoxWithBorderPosition(0, 0, 150, 50);
    flexButton2_1_1_2_1.setBorderSize(2);
    flexButton2_1_1_2_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255));
    flexButton2_1_1_2_1.setText(TypedText(T___SINGLEUSE_XLUH));
    flexButton2_1_1_2_1.setTextPosition(0, 12, 150, 50);
    flexButton2_1_1_2_1.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton2_1_1_2_1.setPosition(10, 169, 150, 50);
    container_menu.add(flexButton2_1_1_2_1);

    flexButton2_1_1_2_2.setBoxWithBorderPosition(0, 0, 150, 50);
    flexButton2_1_1_2_2.setBorderSize(2);
    flexButton2_1_1_2_2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255));
    flexButton2_1_1_2_2.setText(TypedText(T___SINGLEUSE_0UWV));
    flexButton2_1_1_2_2.setTextPosition(0, 12, 150, 50);
    flexButton2_1_1_2_2.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton2_1_1_2_2.setPosition(10, 229, 150, 50);
    container_menu.add(flexButton2_1_1_2_2);

    add(container_menu);

    container_state.setPosition(160, 191, 640, 49);
    flexButton4.setBoxWithBorderPosition(0, 0, 50, 34);
    flexButton4.setBorderSize(2);
    flexButton4.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 50, 30), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton4.setText(TypedText(T___SINGLEUSE_7ISG));
    flexButton4.setTextPosition(0, 4, 50, 34);
    flexButton4.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton4.setPosition(14, 7, 50, 34);
    container_state.add(flexButton4);

    flexButton4_1.setBoxWithBorderPosition(0, 0, 50, 34);
    flexButton4_1.setBorderSize(2);
    flexButton4_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton4_1.setText(TypedText(T___SINGLEUSE_8TGA));
    flexButton4_1.setTextPosition(0, 4, 50, 34);
    flexButton4_1.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton4_1.setPosition(230, 7, 50, 34);
    container_state.add(flexButton4_1);

    flexButton4_1_4.setBoxWithBorderPosition(0, 0, 50, 34);
    flexButton4_1_4.setBorderSize(2);
    flexButton4_1_4.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton4_1_4.setText(TypedText(T___SINGLEUSE_2899));
    flexButton4_1_4.setTextPosition(0, 4, 50, 34);
    flexButton4_1_4.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton4_1_4.setPosition(580, 7, 50, 34);
    container_state.add(flexButton4_1_4);

    flexButton4_1_4_1.setBoxWithBorderPosition(0, 0, 94, 34);
    flexButton4_1_4_1.setBorderSize(2);
    flexButton4_1_4_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton4_1_4_1.setText(TypedText(T___SINGLEUSE_QFI9));
    flexButton4_1_4_1.setTextPosition(0, 4, 94, 34);
    flexButton4_1_4_1.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton4_1_4_1.setPosition(483, 7, 94, 34);
    container_state.add(flexButton4_1_4_1);

    flexButton4_1_4_1_1.setBoxWithBorderPosition(0, 0, 94, 34);
    flexButton4_1_4_1_1.setBorderSize(2);
    flexButton4_1_4_1_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 50, 30), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton4_1_4_1_1.setText(TypedText(T___SINGLEUSE_AP0J));
    flexButton4_1_4_1_1.setTextPosition(0, 4, 94, 34);
    flexButton4_1_4_1_1.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton4_1_4_1_1.setPosition(386, 7, 94, 34);
    container_state.add(flexButton4_1_4_1_1);

    flexButton4_1_3.setBoxWithBorderPosition(0, 0, 50, 34);
    flexButton4_1_3.setBorderSize(2);
    flexButton4_1_3.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton4_1_3.setText(TypedText(T___SINGLEUSE_1ZMM));
    flexButton4_1_3.setTextPosition(0, 4, 50, 34);
    flexButton4_1_3.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton4_1_3.setPosition(176, 7, 50, 34);
    container_state.add(flexButton4_1_3);

    flexButton4_1_2.setBoxWithBorderPosition(0, 0, 50, 34);
    flexButton4_1_2.setBorderSize(2);
    flexButton4_1_2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton4_1_2.setText(TypedText(T___SINGLEUSE_UV5U));
    flexButton4_1_2.setTextPosition(0, 4, 50, 34);
    flexButton4_1_2.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton4_1_2.setPosition(122, 7, 50, 34);
    container_state.add(flexButton4_1_2);

    flexButton4_1_1.setBoxWithBorderPosition(0, 0, 50, 34);
    flexButton4_1_1.setBorderSize(2);
    flexButton4_1_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton4_1_1.setText(TypedText(T___SINGLEUSE_7EYP));
    flexButton4_1_1.setTextPosition(0, 4, 50, 34);
    flexButton4_1_1.setTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton4_1_1.setPosition(68, 7, 50, 34);
    container_state.add(flexButton4_1_1);

    add(container_state);

    container_table.setPosition(175, 240, 615, 230);
    box3.setPosition(0, 0, 615, 230);
    box3.setColor(touchgfx::Color::getColorFromRGB(148, 148, 148));
    container_table.add(box3);

    flexButton5_2_1.setBoxWithBorderPosition(0, 0, 153, 45);
    flexButton5_2_1.setBorderSize(0);
    flexButton5_2_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton5_2_1.setWildcardText(TypedText(T___SINGLEUSE_O2SH));
    Unicode::snprintf(flexButton5_2_1Buffer, FLEXBUTTON5_2_1_SIZE, "%s", TypedText(T___SINGLEUSE_QBS3).getText());
    flexButton5_2_1.setWildcardTextBuffer(flexButton5_2_1Buffer);
    flexButton5_2_1.setWildcardTextPosition(0, 10, 153, 45);
    flexButton5_2_1.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton5_2_1.setPosition(0, 0, 153, 45);
    container_table.add(flexButton5_2_1);

    flexButton5_4.setBoxWithBorderPosition(0, 0, 153, 45);
    flexButton5_4.setBorderSize(0);
    flexButton5_4.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton5_4.setWildcardText(TypedText(T___SINGLEUSE_2LNP));
    Unicode::snprintf(flexButton5_4Buffer, FLEXBUTTON5_4_SIZE, "%s", TypedText(T___SINGLEUSE_GVAJ).getText());
    flexButton5_4.setWildcardTextBuffer(flexButton5_4Buffer);
    flexButton5_4.setWildcardTextPosition(0, 10, 153, 45);
    flexButton5_4.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton5_4.setPosition(308, 0, 153, 45);
    container_table.add(flexButton5_4);

    flexButton5_3_1.setBoxWithBorderPosition(0, 0, 153, 45);
    flexButton5_3_1.setBorderSize(0);
    flexButton5_3_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton5_3_1.setWildcardText(TypedText(T___SINGLEUSE_4X9M));
    Unicode::snprintf(flexButton5_3_1Buffer, FLEXBUTTON5_3_1_SIZE, "%s", TypedText(T___SINGLEUSE_0FQ6).getText());
    flexButton5_3_1.setWildcardTextBuffer(flexButton5_3_1Buffer);
    flexButton5_3_1.setWildcardTextPosition(0, 10, 153, 45);
    flexButton5_3_1.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton5_3_1.setPosition(462, 0, 153, 45);
    container_table.add(flexButton5_3_1);

    flexButton5_1_1.setBoxWithBorderPosition(0, 0, 153, 45);
    flexButton5_1_1.setBorderSize(0);
    flexButton5_1_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton5_1_1.setWildcardText(TypedText(T___SINGLEUSE_55BG));
    Unicode::snprintf(flexButton5_1_1Buffer, FLEXBUTTON5_1_1_SIZE, "%s", TypedText(T___SINGLEUSE_SUVP).getText());
    flexButton5_1_1.setWildcardTextBuffer(flexButton5_1_1Buffer);
    flexButton5_1_1.setWildcardTextPosition(0, 10, 153, 45);
    flexButton5_1_1.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton5_1_1.setPosition(154, 0, 153, 45);
    container_table.add(flexButton5_1_1);

    flxbutt_tb_0_0.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_0_0.setBorderSize(0);
    flxbutt_tb_0_0.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_0_0.setWildcardText(TypedText(T___SINGLEUSE_QT99));
    Unicode::snprintf(flxbutt_tb_0_0Buffer, FLXBUTT_TB_0_0_SIZE, "%s", TypedText(T___SINGLEUSE_ZH4J).getText());
    flxbutt_tb_0_0.setWildcardTextBuffer(flxbutt_tb_0_0Buffer);
    flxbutt_tb_0_0.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_0_0.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_0_0.setPosition(0, 0, 153, 45);
    container_table.add(flxbutt_tb_0_0);

    flxbutt_tb_0_2.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_0_2.setBorderSize(0);
    flxbutt_tb_0_2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_0_2.setWildcardText(TypedText(T___SINGLEUSE_V63P));
    Unicode::snprintf(flxbutt_tb_0_2Buffer, FLXBUTT_TB_0_2_SIZE, "%s", TypedText(T___SINGLEUSE_DKCO).getText());
    flxbutt_tb_0_2.setWildcardTextBuffer(flxbutt_tb_0_2Buffer);
    flxbutt_tb_0_2.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_0_2.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_0_2.setPosition(308, 0, 153, 45);
    container_table.add(flxbutt_tb_0_2);

    flxbutt_tb_0_3.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_0_3.setBorderSize(0);
    flxbutt_tb_0_3.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_0_3.setWildcardText(TypedText(T___SINGLEUSE_TLVX));
    Unicode::snprintf(flxbutt_tb_0_3Buffer, FLXBUTT_TB_0_3_SIZE, "%s", TypedText(T___SINGLEUSE_9S0U).getText());
    flxbutt_tb_0_3.setWildcardTextBuffer(flxbutt_tb_0_3Buffer);
    flxbutt_tb_0_3.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_0_3.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_0_3.setPosition(462, 0, 153, 45);
    container_table.add(flxbutt_tb_0_3);

    flxbutt_tb_0_1.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_0_1.setBorderSize(0);
    flxbutt_tb_0_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_0_1.setWildcardText(TypedText(T___SINGLEUSE_9YIX));
    Unicode::snprintf(flxbutt_tb_0_1Buffer, FLXBUTT_TB_0_1_SIZE, "%s", TypedText(T___SINGLEUSE_BZCP).getText());
    flxbutt_tb_0_1.setWildcardTextBuffer(flxbutt_tb_0_1Buffer);
    flxbutt_tb_0_1.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_0_1.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_0_1.setPosition(154, 0, 153, 45);
    container_table.add(flxbutt_tb_0_1);

    flxbutt_tb_1_0.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_1_0.setBorderSize(0);
    flxbutt_tb_1_0.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_1_0.setWildcardText(TypedText(T___SINGLEUSE_0ERG));
    Unicode::snprintf(flxbutt_tb_1_0Buffer, FLXBUTT_TB_1_0_SIZE, "%s", TypedText(T___SINGLEUSE_SU4Z).getText());
    flxbutt_tb_1_0.setWildcardTextBuffer(flxbutt_tb_1_0Buffer);
    flxbutt_tb_1_0.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_1_0.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_1_0.setPosition(0, 46, 153, 45);
    container_table.add(flxbutt_tb_1_0);

    flxbutt_tb_1_2.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_1_2.setBorderSize(0);
    flxbutt_tb_1_2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_1_2.setWildcardText(TypedText(T___SINGLEUSE_2FL7));
    Unicode::snprintf(flxbutt_tb_1_2Buffer, FLXBUTT_TB_1_2_SIZE, "%s", TypedText(T___SINGLEUSE_6F0Y).getText());
    flxbutt_tb_1_2.setWildcardTextBuffer(flxbutt_tb_1_2Buffer);
    flxbutt_tb_1_2.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_1_2.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_1_2.setPosition(308, 46, 153, 45);
    container_table.add(flxbutt_tb_1_2);

    flxbutt_tb_1_3.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_1_3.setBorderSize(0);
    flxbutt_tb_1_3.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_1_3.setWildcardText(TypedText(T___SINGLEUSE_GCNC));
    Unicode::snprintf(flxbutt_tb_1_3Buffer, FLXBUTT_TB_1_3_SIZE, "%s", TypedText(T___SINGLEUSE_8TDU).getText());
    flxbutt_tb_1_3.setWildcardTextBuffer(flxbutt_tb_1_3Buffer);
    flxbutt_tb_1_3.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_1_3.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_1_3.setPosition(462, 46, 153, 45);
    container_table.add(flxbutt_tb_1_3);

    flxbutt_tb_1_1.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_1_1.setBorderSize(0);
    flxbutt_tb_1_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_1_1.setWildcardText(TypedText(T___SINGLEUSE_5XLQ));
    Unicode::snprintf(flxbutt_tb_1_1Buffer, FLXBUTT_TB_1_1_SIZE, "%s", TypedText(T___SINGLEUSE_KT8G).getText());
    flxbutt_tb_1_1.setWildcardTextBuffer(flxbutt_tb_1_1Buffer);
    flxbutt_tb_1_1.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_1_1.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_1_1.setPosition(154, 46, 153, 45);
    container_table.add(flxbutt_tb_1_1);

    flxbutt_tb_2_0.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_2_0.setBorderSize(0);
    flxbutt_tb_2_0.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_2_0.setWildcardText(TypedText(T___SINGLEUSE_0Q1X));
    Unicode::snprintf(flxbutt_tb_2_0Buffer, FLXBUTT_TB_2_0_SIZE, "%s", TypedText(T___SINGLEUSE_N6Y7).getText());
    flxbutt_tb_2_0.setWildcardTextBuffer(flxbutt_tb_2_0Buffer);
    flxbutt_tb_2_0.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_2_0.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_2_0.setPosition(0, 92, 153, 45);
    container_table.add(flxbutt_tb_2_0);

    flxbutt_tb_2_2.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_2_2.setBorderSize(0);
    flxbutt_tb_2_2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_2_2.setWildcardText(TypedText(T___SINGLEUSE_ZHXK));
    Unicode::snprintf(flxbutt_tb_2_2Buffer, FLXBUTT_TB_2_2_SIZE, "%s", TypedText(T___SINGLEUSE_O51M).getText());
    flxbutt_tb_2_2.setWildcardTextBuffer(flxbutt_tb_2_2Buffer);
    flxbutt_tb_2_2.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_2_2.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_2_2.setPosition(308, 92, 153, 45);
    container_table.add(flxbutt_tb_2_2);

    flxbutt_tb_2_3.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_2_3.setBorderSize(0);
    flxbutt_tb_2_3.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_2_3.setWildcardText(TypedText(T___SINGLEUSE_8Y8N));
    Unicode::snprintf(flxbutt_tb_2_3Buffer, FLXBUTT_TB_2_3_SIZE, "%s", TypedText(T___SINGLEUSE_UQR9).getText());
    flxbutt_tb_2_3.setWildcardTextBuffer(flxbutt_tb_2_3Buffer);
    flxbutt_tb_2_3.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_2_3.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_2_3.setPosition(462, 92, 153, 45);
    container_table.add(flxbutt_tb_2_3);

    flxbutt_tb_2_1.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_2_1.setBorderSize(0);
    flxbutt_tb_2_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_2_1.setWildcardText(TypedText(T___SINGLEUSE_I7D2));
    Unicode::snprintf(flxbutt_tb_2_1Buffer, FLXBUTT_TB_2_1_SIZE, "%s", TypedText(T___SINGLEUSE_FRKK).getText());
    flxbutt_tb_2_1.setWildcardTextBuffer(flxbutt_tb_2_1Buffer);
    flxbutt_tb_2_1.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_2_1.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_2_1.setPosition(154, 92, 153, 45);
    container_table.add(flxbutt_tb_2_1);

    flxbutt_tb_3_0.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_3_0.setBorderSize(0);
    flxbutt_tb_3_0.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_3_0.setWildcardText(TypedText(T___SINGLEUSE_FZV3));
    Unicode::snprintf(flxbutt_tb_3_0Buffer, FLXBUTT_TB_3_0_SIZE, "%s", TypedText(T___SINGLEUSE_OG2J).getText());
    flxbutt_tb_3_0.setWildcardTextBuffer(flxbutt_tb_3_0Buffer);
    flxbutt_tb_3_0.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_3_0.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_3_0.setPosition(0, 138, 153, 45);
    container_table.add(flxbutt_tb_3_0);

    flxbutt_tb_3_2.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_3_2.setBorderSize(0);
    flxbutt_tb_3_2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_3_2.setWildcardText(TypedText(T___SINGLEUSE_WOPH));
    Unicode::snprintf(flxbutt_tb_3_2Buffer, FLXBUTT_TB_3_2_SIZE, "%s", TypedText(T___SINGLEUSE_1CQF).getText());
    flxbutt_tb_3_2.setWildcardTextBuffer(flxbutt_tb_3_2Buffer);
    flxbutt_tb_3_2.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_3_2.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_3_2.setPosition(308, 138, 153, 45);
    container_table.add(flxbutt_tb_3_2);

    flxbutt_tb_3_3.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_3_3.setBorderSize(0);
    flxbutt_tb_3_3.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_3_3.setWildcardText(TypedText(T___SINGLEUSE_9OWI));
    Unicode::snprintf(flxbutt_tb_3_3Buffer, FLXBUTT_TB_3_3_SIZE, "%s", TypedText(T___SINGLEUSE_5KEG).getText());
    flxbutt_tb_3_3.setWildcardTextBuffer(flxbutt_tb_3_3Buffer);
    flxbutt_tb_3_3.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_3_3.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_3_3.setPosition(462, 138, 153, 45);
    container_table.add(flxbutt_tb_3_3);

    flxbutt_tb_3_1.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_3_1.setBorderSize(0);
    flxbutt_tb_3_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_3_1.setWildcardText(TypedText(T___SINGLEUSE_QPUO));
    Unicode::snprintf(flxbutt_tb_3_1Buffer, FLXBUTT_TB_3_1_SIZE, "%s", TypedText(T___SINGLEUSE_YAPT).getText());
    flxbutt_tb_3_1.setWildcardTextBuffer(flxbutt_tb_3_1Buffer);
    flxbutt_tb_3_1.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_3_1.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_3_1.setPosition(154, 138, 153, 45);
    container_table.add(flxbutt_tb_3_1);

    flxbutt_tb_4_0.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_4_0.setBorderSize(0);
    flxbutt_tb_4_0.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_4_0.setWildcardText(TypedText(T___SINGLEUSE_EYOJ));
    Unicode::snprintf(flxbutt_tb_4_0Buffer, FLXBUTT_TB_4_0_SIZE, "%s", TypedText(T___SINGLEUSE_7686).getText());
    flxbutt_tb_4_0.setWildcardTextBuffer(flxbutt_tb_4_0Buffer);
    flxbutt_tb_4_0.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_4_0.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_4_0.setPosition(0, 184, 153, 45);
    container_table.add(flxbutt_tb_4_0);

    flxbutt_tb_4_2.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_4_2.setBorderSize(0);
    flxbutt_tb_4_2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_4_2.setWildcardText(TypedText(T___SINGLEUSE_8SHV));
    Unicode::snprintf(flxbutt_tb_4_2Buffer, FLXBUTT_TB_4_2_SIZE, "%s", TypedText(T___SINGLEUSE_BJW4).getText());
    flxbutt_tb_4_2.setWildcardTextBuffer(flxbutt_tb_4_2Buffer);
    flxbutt_tb_4_2.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_4_2.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_4_2.setPosition(308, 184, 153, 45);
    container_table.add(flxbutt_tb_4_2);

    flxbutt_tb_4_3.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_4_3.setBorderSize(0);
    flxbutt_tb_4_3.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_4_3.setWildcardText(TypedText(T___SINGLEUSE_05UP));
    Unicode::snprintf(flxbutt_tb_4_3Buffer, FLXBUTT_TB_4_3_SIZE, "%s", TypedText(T___SINGLEUSE_7ESH).getText());
    flxbutt_tb_4_3.setWildcardTextBuffer(flxbutt_tb_4_3Buffer);
    flxbutt_tb_4_3.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_4_3.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_4_3.setPosition(462, 184, 153, 45);
    container_table.add(flxbutt_tb_4_3);

    flxbutt_tb_4_1.setBoxWithBorderPosition(0, 0, 153, 45);
    flxbutt_tb_4_1.setBorderSize(0);
    flxbutt_tb_4_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(70, 255, 255), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flxbutt_tb_4_1.setWildcardText(TypedText(T___SINGLEUSE_JFL3));
    Unicode::snprintf(flxbutt_tb_4_1Buffer, FLXBUTT_TB_4_1_SIZE, "%s", TypedText(T___SINGLEUSE_5VND).getText());
    flxbutt_tb_4_1.setWildcardTextBuffer(flxbutt_tb_4_1Buffer);
    flxbutt_tb_4_1.setWildcardTextPosition(0, 10, 153, 45);
    flxbutt_tb_4_1.setWildcardTextColors(touchgfx::Color::getColorFromRGB(10, 10, 10), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flxbutt_tb_4_1.setPosition(154, 184, 153, 45);
    container_table.add(flxbutt_tb_4_1);

    add(container_table);
}

screenViewBase::~screenViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void screenViewBase::setupScreen()
{

}

void screenViewBase::handleTickEvent()
{
    //Interaction1
    //When every N tick call virtual function
    //Call gfxTickCallback
    gfxTickCallback();
}
