#ifndef LCD_STM32_DRIVER_H
#define LCD_STM32_DRIVER_H

#include "ap_def.h"


#define LCD_SCREEN_HEIGHT 480
#define LCD_SCREEN_WIDTH 	800

#define BURST_MAX_SIZE 	500

#define BLACK       0x0000      
#define NAVY        0x000F      
#define DARKGREEN   0x03E0      
#define DARKCYAN    0x03EF      
#define MAROON      0x7800      
#define PURPLE      0x780F      
#define OLIVE       0x7BE0      
#define LIGHTGREY   0xC618      
#define DARKGREY    0x7BEF      
#define BLUE        0x001F      
#define GREEN       0x07E0      
#define CYAN        0x07FF      
#define RED         0xF800     
#define MAGENTA     0xF81F      
#define YELLOW      0xFFE0      
#define WHITE       0xFFFF      
#define ORANGE      0xFD20      
#define GREENYELLOW 0xAFE5     
#define PINK        0xF81F

#define DARKBLUE    0X01CF
#define LIGHTBLUE   0X7D7C
#define GRAYBLUE    0X5458

#define LIGHTGREEN  0X841F
#define LIGHTGRAY   0XEF5B
#define LGRAY 			0XC618

#define LGRAYBLUE   0XA651
#define LBBLUE      0X2B12

typedef struct
{
  int16_t X;
  int16_t Y;
} Point, * pPoint;


void 			LCD_Init(void);
uint16_t  LCD_GetXSize(void);
uint16_t  LCD_GetYSize(void);

void LCD_Clear(uint32_t Color);

void LCD_DrawPixel(uint16_t Xpos, uint16_t Ypos, uint32_t RGB_Code);
uint32_t LCD_ReadPixel(uint16_t Xpos, uint16_t Ypos);
void LCD_Clear(uint32_t Color);
void LCD_SelectLayer(uint32_t LayerIndex);
void LCD_SetLayerVisible(uint32_t LayerIndex, FunctionalState state);
void LCD_SetLayerVisible_NoReload(uint32_t LayerIndex, FunctionalState State);
void LCD_SetTransparency(uint32_t LayerIndex, uint8_t Transparency);
void LCD_SetTransparency_NoReload(uint32_t LayerIndex, uint8_t Transparency);
void LCD_SetLayerAddress(uint32_t LayerIndex, uint32_t Address);
void LCD_SetLayerAddress_NoReload(uint32_t LayerIndex, uint32_t Address);
void LCD_SetLayerWindow(uint16_t LayerIndex, uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);
void LCD_SetLayerWindow_NoReload(uint16_t LayerIndex, uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);
void LCD_SetColorKeying(uint32_t LayerIndex, uint32_t RGBValue);
void LCD_SetColorKeying_NoReload(uint32_t LayerIndex, uint32_t RGBValue);
void LCD_ResetColorKeying(uint32_t LayerIndex);
void LCD_ResetColorKeying_NoReload(uint32_t LayerIndex);
void LCD_Relaod(uint32_t ReloadType);
void LCD_DrawHLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length, uint16_t Color);
void LCD_DrawVLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length, uint16_t Color);
void LCD_DrawLine(uint16_t X1, uint16_t Y1, uint16_t X2, uint16_t Y2, uint16_t Color);
void LCD_DrawRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height, uint16_t Color);
void LCD_DrawCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius, uint16_t Color);
void LCD_DrawPolygon(pPoint Points, uint16_t PointCount, uint16_t Color);
void LCD_DrawEllipse(int Xpos, int Ypos, int XRadius, int YRadius, uint16_t Color);
void LCD_DrawBitmap(uint32_t X, uint32_t Y, uint8_t *pBmp);
void LCD_FillRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height, uint16_t Color);
void LCD_FillCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius, uint16_t Color);
void LCD_FillTriangle(uint16_t X1, uint16_t X2, uint16_t X3, uint16_t Y1, uint16_t Y2, uint16_t Y3, uint16_t Color);
void LCD_FillPolygon(pPoint Points, uint16_t PointCount, uint16_t Color);
void LCD_FillEllipse(int Xpos, int Ypos, int XRadius, int YRadius, uint16_t Color);
void LCD_SetBackLight(uint16_t brightness);


void _DMA2D_Fill(void * pDst, uint32_t xSize, uint32_t ySize, uint32_t OffLine, uint32_t ColorIndex, uint32_t PixelFormat);
void _DMA2D_Copy(void * pSrc, void * pDst, uint32_t xSize, uint32_t ySize, uint32_t OffLineSrc, uint32_t OffLineDst, uint32_t PixelFormat);
void _DMA2D_DrawAlphaBitmap(void * pDst, void * pSrc, uint32_t xSize, uint32_t ySize, uint32_t OffLineSrc, uint32_t OffLineDst, uint32_t PixelFormat);
void _DMA2D_MixColorsBulk(uint32_t * pColorFG, uint32_t OffLineSrcFG, uint32_t * pColorDst, uint32_t OffLineDst, uint32_t xSize, uint32_t ySize, uint8_t Intens);
void _DMA2D_AlphaBlendingBulk(uint32_t * pColorFG, uint32_t OffLineSrcFG, uint32_t * pColorBG, uint32_t OffLineSrcBG, uint32_t * pColorDst, uint32_t OffLineDst, uint32_t xSize, uint32_t ySize);

#endif

