/* Includes ------------------------------------------------------------------*/
#include "ap_lcd.h"
//#include "stm32H750_qspi.h"

/* Global Variables ------------------------------------------------------------------*/
//volatile uint16_t LCD_HEIGHT = LCD_SCREEN_HEIGHT;
//volatile uint16_t LCD_WIDTH	 = LCD_SCREEN_WIDTH;

#define BACKLIGHT_TIMER			htim16		// LCD BackLight 채널1이 PWM 출력으로 설정된 타이머.  펄스는 최대 100으로 설정.


#define LtdcHandler		hltdc
#define ABS(X)  			((X) > 0 ? (X) : -(X))
#define POLY_X(Z)     ((int32_t)((Points + Z)->X))
#define POLY_Y(Z)     ((int32_t)((Points + Z)->Y))

uint32_t ActiveLayer;


void LCD_Init(void)
{
  /* Initialize the SDRAM */
//  BSP_SDRAM_Init();
////  LCD_SelectLayer(1);
  /* Clear the LCD Foreground layer */
////  LCD_SetLayerVisible(1, DISABLE);
  /* Set Foreground Layer */
  LCD_SelectLayer(0);
  LCD_SetLayerVisible(1, DISABLE);
  LCD_SetLayerVisible(0, ENABLE);

  LCD_Clear(BLACK);
  HAL_Delay(10);
	LCD_SetBackLight(50);
  HAL_TIM_PWM_Start(&BACKLIGHT_TIMER, TIM_CHANNEL_1);
}

/**
  * @brief  Fills buffer.
  * @param  LayerIndex: layer index
  * @param  pDst: output color
  * @param  xSize: buffer width
  * @param  ySize: buffer height
  * @param  OffLine: offset
  * @param  ColorIndex: color Index
  */
static void FillBuffer(uint32_t LayerIndex, void * pDst, uint32_t xSize, uint32_t ySize, uint32_t OffLine, uint32_t ColorIndex)
{
	register uint32_t Color;

  hdma2d.Instance = DMA2D;
	hdma2d.Init.Mode = DMA2D_R2M;		/* Register to memory mode */
	hdma2d.Init.ColorMode = DMA2D_OUTPUT_RGB565;

  Color = ((ColorIndex & RED) << 8) | ((ColorIndex & GREEN ) << 5) | ((ColorIndex & BLUE) << 3); // 32bit Color로 만들기
  hdma2d.Init.OutputOffset = OffLine;

  /* DMA2D Initialization */
  if(HAL_DMA2D_Init(&hdma2d) == HAL_OK)
  {
    if(HAL_DMA2D_ConfigLayer(&hdma2d, LayerIndex) == HAL_OK)
    {
      if (HAL_DMA2D_Start(&hdma2d, Color, (uint32_t)pDst, xSize, ySize) == HAL_OK)
      {
        /* Polling For DMA transfer */
        HAL_DMA2D_PollForTransfer(&hdma2d, 1000);
      }
    }
  }
}

/*
*********************************************************************************************************
*   함수명    : _DMA2D_Fill
*   기능 설명 : DMA2D 색상 채우기 기능
*   매게 변수 : pDst          색상 데이터 대상 주소
*               xSize         X 축의 색상 블록 크기, 즉 라인 당 픽셀 수
*               ySize         컬러 블록의 Y 축 크기, 즉 행 수
*               OffLine       전경 이미지의 라인 오프셋
*               ColorIndex    색상 블록의 ColorIndex 색상 값
*               PixelFormat   대상 영역 색상 형식
*   반환 값   : 없음
*********************************************************************************************************
*/
void _DMA2D_Fill(void *   pDst,
                 uint32_t xSize,
                 uint32_t ySize,
                 uint32_t OffLine,
                 uint32_t ColorIndex,
                 uint32_t PixelFormat)
{

    /* DMA2D는 레지스터 대 메모리 모드를 사용합니다. 이 모드는 전경 및 배경 레이어를 사용하지 않습니다. */
    DMA2D->CR      = 0x00030000UL | (1 << 9);
    DMA2D->OCOLR   = ColorIndex;
    DMA2D->OMAR    = (uint32_t)pDst;
    DMA2D->OOR     = OffLine;
    DMA2D->OPFCCR  = PixelFormat;
    DMA2D->NLR     = (uint32_t)(xSize << 16) | (uint16_t)ySize;

    /* 전송 시작 */
    DMA2D->CR   |= DMA2D_CR_START;

    /* DMA2D 전송이 완료 될 때까지 기다립니다. */
    while (DMA2D->CR & DMA2D_CR_START) {}
}


/*
*********************************************************************************************************
*   함수명    : _DMA2D_Copy
*   기능 설명 : DMA2D를 통해 지정된 영역의 색상 데이터를 전경 레이어에서 대상 영역으로 복사
*   매개 변수 : pSrc          컬러 데이터 소스 주소
*               pDst          컬러 데이터 대상 주소
*               xSize         대상 영역의 X 축 크기, 즉 라인 당 픽셀 수
*               ySize         대상 영역의 Y 축 크기, 즉 행 수
*               OffLineSrc    전경 이미지의 라인 오프셋
*               OffLineDst    출력 라인 오프셋
*               PixelFormat   대상 영역 색상 형식
*   반환 값   : 없음
*********************************************************************************************************
*/
void _DMA2D_Copy(void *   pSrc,
                 void *   pDst,
                 uint32_t xSize,
                 uint32_t ySize,
                 uint32_t OffLineSrc,
                 uint32_t OffLineDst,
                 uint32_t PixelFormat)
{

    /* DMA2D는 DMA2D 입력으로 전경 레이어 인 메모리 대 메모리 모드를 사용합니다. */
    DMA2D->CR      = 0x00000000UL | (1 << 9);
    DMA2D->FGMAR   = (uint32_t)pSrc;
    DMA2D->OMAR    = (uint32_t)pDst;
    DMA2D->FGOR    = OffLineSrc;
    DMA2D->OOR     = OffLineDst;

    /* 전경 레이어와 출력 영역 모두에서 사용되는 RGB565 색상 형식 */
    DMA2D->FGPFCCR = LTDC_PIXEL_FORMAT_RGB565;
    DMA2D->OPFCCR  = LTDC_PIXEL_FORMAT_RGB565;

    DMA2D->NLR     = (uint32_t)(xSize << 16) | (uint16_t)ySize;

    /* 전송 시작 */
    DMA2D->CR      |= DMA2D_CR_START;

    /* DMA2D 전송이 완료 될 때까지 기다립니다. */
    while (DMA2D->CR & DMA2D_CR_START) {}
}

/*
*********************************************************************************************************
*   함수명    : _DMA2D_DrawAlphaBitmap
*   기능 설명 : ARGB8888 형식 비트 맵 표시
*   매게 변수 : pDst        대상 지역 주소
*               pSrc        소스 데이터 주소, 즉 비트 맵의 ​​첫 번째 주소
*               xSize       대상 영역의 X 축 크기, 즉 라인 당 픽셀 수
*               ySize       대상 영역의 Y 축 크기, 즉 행 수
*               OffLineSrc  소스 데이터 라인 오프셋
*               OffLineDst  대상 영역 라인 오프셋
*               PixelFormat 대상 영역 색상 형식
*   반환 값   : 없음
*********************************************************************************************************
*/
void _DMA2D_DrawAlphaBitmap(void  *  pDst,
                            void  *  pSrc,
                            uint32_t xSize,
                            uint32_t ySize,
                            uint32_t OffLineSrc,
                            uint32_t OffLineDst,
                            uint32_t PixelFormat)
{
    /* DMA2D는 메모리 대 메모리 모델을 채택하고이 모델의 전경 및 배경 레이어는 DMA2D 입력으로 사용되며 색상 형식 변환 및 색상 혼합을 지원합니다. */
    DMA2D->CR      = 0x00020000UL | (1 << 9);
    DMA2D->FGMAR   = (uint32_t)pSrc;
    DMA2D->BGMAR   = (uint32_t)pDst;
    DMA2D->OMAR    = (uint32_t)pDst;
    DMA2D->FGOR    = OffLineSrc;
    DMA2D->BGOR    = OffLineDst;
    DMA2D->OOR     = OffLineDst;

    /* 전경 레이어의 색상 형식은 비트 맵의 ​​색상 형식 인 LTDC_PIXEL_FORMAT_ARGB8888이며 배경 레이어 및 출력 영역의 색상 형식을 구성 할 수 있습니다. */
    DMA2D->FGPFCCR = LTDC_PIXEL_FORMAT_ARGB8888;
    DMA2D->BGPFCCR = PixelFormat;
    DMA2D->OPFCCR  = PixelFormat;
    DMA2D->NLR     = (uint32_t)(xSize << 16) | (uint16_t)ySize;

    /* 전송 시작 */
    DMA2D->CR   |= DMA2D_CR_START;

    /* DMA2D 전송이 완료 될 때까지 기다립니다. */
    while (DMA2D->CR & DMA2D_CR_START) {}
}


/*
*********************************************************************************************************
*   함수명    : _DMA2D_MixColorsBulk
*   기능 설명 : 전경 레이어와 대상 영역의 색상 혼합
*   매게 변수 : pColorFG      전경 레이어 데이터 소스 주소
*               OffLineSrcFG  전경 이미지의 라인 오프셋
*               pColorDst     대상 영역 데이터 주소
*               OffLineDst    대상 영역의 라인 오프셋
*               xSize         대상 영역의 X 축 크기, 즉 라인 당 픽셀 수
*               ySize         대상 영역의 Y 축 크기, 즉 행 수
*               Intens        전경 레이어의 투명도를 설정합니다. 255는 완전히 불투명 함, 0은 완전히 투명 함을 의미합니다.
*   반환 값   : 없음
*********************************************************************************************************
*/
void _DMA2D_MixColorsBulk(uint32_t * pColorFG,
                          uint32_t OffLineSrcFG,
                          uint32_t * pColorDst,
                          uint32_t OffLineDst,
                          uint32_t xSize,
                          uint32_t ySize,
                          uint8_t Intens)
{
    /* DMA2D는 메모리 대 메모리 모델을 채택하고이 모델의 전경 및 배경 레이어는 DMA2D 입력으로 사용되며 색상 형식 변환 및 색상 혼합을 지원합니다. */
    DMA2D->CR      = 0x00020000UL | (1 << 9);
    DMA2D->FGMAR   = (uint32_t)pColorFG;
    DMA2D->BGMAR   = (uint32_t)pColorDst;
    DMA2D->OMAR    = (uint32_t)pColorDst;
    DMA2D->FGOR    = OffLineSrcFG;
    DMA2D->BGOR    = OffLineDst;
    DMA2D->OOR     = OffLineDst;

    /* 전경 레이어, 배경 레이어 및 출력 영역은 모두 RGB565 형식입니다. */
    DMA2D->FGPFCCR = LTDC_PIXEL_FORMAT_RGB565
                 | (1UL << 16)
                 | ((uint32_t)Intens << 24);
    DMA2D->BGPFCCR = LTDC_PIXEL_FORMAT_RGB565;
    DMA2D->OPFCCR  = LTDC_PIXEL_FORMAT_RGB565;

    DMA2D->NLR     = (uint32_t)(xSize << 16) | (uint16_t)ySize;

    /* 전송 시작 */
    DMA2D->CR   |= DMA2D_CR_START;

    /* DMA2D 전송이 완료 될 때까지 기다립니다. */
    while (DMA2D->CR & DMA2D_CR_START) {}
}

/*
*********************************************************************************************************
*   함수명    : _DMA2D_AlphaBlendingBulk
*   기능 설명 : 전경 레이어와 배경 레이어의 색상 혼합
*   매게 변수 : pColorFG      전경 레이어 소스 데이터 주소
*               OffLineSrcFG  전경 레이어 소스 데이터 라인 오프셋
*               pColorBG      배경 레이어 소스 데이터 주소
*               OffLineSrcBG  배경 레이어 소스 데이터 라인 오프셋
*               pColorDst     대상 지역 주소
*               OffLineDst    대상 영역 라인 오프셋
*               xSize         대상 영역의 X 축 크기, 즉 라인 당 픽셀 수
*               ySize         대상 영역의 Y 축 크기, 즉 행 수
*   반환 값   : 없음
*********************************************************************************************************
*/
void _DMA2D_AlphaBlendingBulk(uint32_t * pColorFG,
                              uint32_t OffLineSrcFG,
                              uint32_t * pColorBG,
                              uint32_t OffLineSrcBG,
                              uint32_t * pColorDst,
                              uint32_t OffLineDst,
                              uint32_t xSize,
                              uint32_t ySize)
{
    /* DMA2D는 메모리 대 메모리 모델을 채택하고이 모델의 전경 및 배경 레이어는 DMA2D 입력으로 사용되며 색상 형식 변환 및 색상 혼합을 지원합니다. */
    DMA2D->CR      = 0x00020000UL | (1 << 9);
    DMA2D->FGMAR   = (uint32_t)pColorFG;
    DMA2D->BGMAR   = (uint32_t)pColorBG;
    DMA2D->OMAR    = (uint32_t)pColorDst;
    DMA2D->FGOR    = OffLineSrcFG;
    DMA2D->BGOR    = OffLineSrcBG;
    DMA2D->OOR     = OffLineDst;

    /* 전경 레이어, 배경 레이어는 ARGB8888 형식을, 출력 영역은 RGB565 형식을 채택 */
    DMA2D->FGPFCCR = LTDC_PIXEL_FORMAT_ARGB8888;
    DMA2D->BGPFCCR = LTDC_PIXEL_FORMAT_ARGB8888;
    DMA2D->OPFCCR  = LTDC_PIXEL_FORMAT_RGB565;
    DMA2D->NLR     = (uint32_t)(xSize << 16) | (uint16_t)ySize;

    /* 전송 시작 */
    DMA2D->CR   |= DMA2D_CR_START;

    /* DMA2D 전송이 완료 될 때까지 기다립니다. */
    while (DMA2D->CR & DMA2D_CR_START) {}
}

/**
  * @brief  Gets the LCD X size.
  * @retval Used LCD X size
  */
uint16_t LCD_GetXSize(void)
{
  return hltdc.LayerCfg[ActiveLayer].ImageWidth;
}

/**
  * @brief  Gets the LCD Y size.
  * @retval Used LCD Y size
  */
uint16_t LCD_GetYSize(void)
{
  return hltdc.LayerCfg[ActiveLayer].ImageHeight;
}


/**
  * @brief  Writes Pixel.
  * @param  Xpos: the X position
  * @param  Ypos: the Y position
  * @param  RGB_Code: the pixel color in ARGB mode (8-8-8-8)
  */
void LCD_DrawPixel(uint16_t Xpos, uint16_t Ypos, uint32_t RGB_Code)
{
  if((Xpos >= LCD_GetXSize()) || (Ypos >= LCD_GetYSize())) return;

  /* Write data value to all SDRAM memory */
  //*(__IO uint32_t*) (LtdcHandler.LayerCfg[ActiveLayer].FBStartAdress + (4*(Ypos*LCD_GetXSize() + Xpos))) = RGB_Code;		// 32bit color
	*(__IO uint16_t*) (LtdcHandler.LayerCfg[ActiveLayer].FBStartAdress + (2*(Ypos*LCD_GetXSize() + Xpos))) = RGB_Code;			// 16bit color
}

/**
  * @brief  Reads Pixel.
  * @param  Xpos: the X position
  * @param  Ypos: the Y position
  * @retval RGB pixel color
  */
uint32_t LCD_ReadPixel(uint16_t Xpos, uint16_t Ypos)
{
  uint32_t ret = 0;

  if(hltdc.LayerCfg[ActiveLayer].PixelFormat == LTDC_PIXEL_FORMAT_ARGB8888)
  {
    /* Read data value from SDRAM memory */
    ret = *(__IO uint32_t*) (hltdc.LayerCfg[ActiveLayer].FBStartAdress + (4*(Ypos*LCD_GetXSize() + Xpos)));
  }
  else if(hltdc.LayerCfg[ActiveLayer].PixelFormat == LTDC_PIXEL_FORMAT_RGB888)
  {
    /* Read data value from SDRAM memory */
    ret = (*(__IO uint32_t*) (hltdc.LayerCfg[ActiveLayer].FBStartAdress + (4*(Ypos*LCD_GetXSize() + Xpos))) & 0x00FFFFFF);
  }
  else if((hltdc.LayerCfg[ActiveLayer].PixelFormat == LTDC_PIXEL_FORMAT_RGB565) || \
          (hltdc.LayerCfg[ActiveLayer].PixelFormat == LTDC_PIXEL_FORMAT_ARGB4444) || \
          (hltdc.LayerCfg[ActiveLayer].PixelFormat == LTDC_PIXEL_FORMAT_AL88))
  {
    /* Read data value from SDRAM memory */
    ret = *(__IO uint16_t*) (hltdc.LayerCfg[ActiveLayer].FBStartAdress + (2*(Ypos*LCD_GetXSize() + Xpos)));
  }
  else
  {
    /* Read data value from SDRAM memory */
    ret = *(__IO uint8_t*) (hltdc.LayerCfg[ActiveLayer].FBStartAdress + (2*(Ypos*LCD_GetXSize() + Xpos)));
  }

  return ret;
}

/**
  * @brief  Clears the hole LCD.
  * @param  Color: the color of the background
  */
void LCD_Clear(uint32_t Color)
{
  /* Clear the LCD */
  FillBuffer(ActiveLayer, (uint32_t *)(hltdc.LayerCfg[ActiveLayer].FBStartAdress), LCD_GetXSize(), LCD_GetYSize(), 0, Color);
}

/**
  * @brief  Selects the LCD Layer.
  * @param  LayerIndex: the Layer foreground or background.
  */
void LCD_SelectLayer(uint32_t LayerIndex)
{
  ActiveLayer = LayerIndex;
}

/**
  * @brief  Sets a LCD Layer visible.
  * @param  LayerIndex: the visible Layer.
  * @param  state: new state of the specified layer.
  *    This parameter can be: ENABLE or DISABLE.
  */
void LCD_SetLayerVisible(uint32_t LayerIndex, FunctionalState state)
{
  if(state == ENABLE)
  {
    __HAL_LTDC_LAYER_ENABLE(&LtdcHandler, LayerIndex);
  }
  else
  {
    __HAL_LTDC_LAYER_DISABLE(&LtdcHandler, LayerIndex);
  }
  __HAL_LTDC_RELOAD_CONFIG(&LtdcHandler);
}

/**
  * @brief  Sets an LCD Layer visible without reloading.
  * @param  LayerIndex: Visible Layer
  * @param  State: New state of the specified layer
  *          This parameter can be one of the following values:
  *            @arg  ENABLE
  *            @arg  DISABLE
  * @retval None
  */
void LCD_SetLayerVisible_NoReload(uint32_t LayerIndex, FunctionalState State)
{
  if(State == ENABLE)
  {
    __HAL_LTDC_LAYER_ENABLE(&LtdcHandler, LayerIndex);
  }
  else
  {
    __HAL_LTDC_LAYER_DISABLE(&LtdcHandler, LayerIndex);
  }
  /* Do not Sets the Reload  */
}

/**
  * @brief  Configures the Transparency.
  * @param  LayerIndex: the Layer foreground or background.
  * @param  Transparency: the Transparency,
  *    This parameter must range from 0x00 to 0xFF.
  */
void LCD_SetTransparency(uint32_t LayerIndex, uint8_t Transparency)
{
  HAL_LTDC_SetAlpha(&LtdcHandler, Transparency, LayerIndex);
}

/**
  * @brief  Configures the transparency without reloading.
  * @param  LayerIndex: Layer foreground or background.
  * @param  Transparency: Transparency
  *           This parameter must be a number between Min_Data = 0x00 and Max_Data = 0xFF
  * @retval None
  */
void LCD_SetTransparency_NoReload(uint32_t LayerIndex, uint8_t Transparency)
{
  HAL_LTDC_SetAlpha_NoReload(&LtdcHandler, Transparency, LayerIndex);
}

/**
  * @brief  Sets a LCD layer frame buffer address.
  * @param  LayerIndex: specifies the Layer foreground or background
  * @param  Address: new LCD frame buffer value
  */
void LCD_SetLayerAddress(uint32_t LayerIndex, uint32_t Address)
{
  HAL_LTDC_SetAddress(&LtdcHandler, Address, LayerIndex);
}

/**
  * @brief  Sets an LCD layer frame buffer address without reloading.
  * @param  LayerIndex: Layer foreground or background
  * @param  Address: New LCD frame buffer value
  * @retval None
  */
void LCD_SetLayerAddress_NoReload(uint32_t LayerIndex, uint32_t Address)
{
  HAL_LTDC_SetAddress_NoReload(&LtdcHandler, Address, LayerIndex);
}

/**
  * @brief  Sets the Display window.
  * @param  LayerIndex: layer index
  * @param  Xpos: LCD X position
  * @param  Ypos: LCD Y position
  * @param  Width: LCD window width
  * @param  Height: LCD window height
  */
void LCD_SetLayerWindow(uint16_t LayerIndex, uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height)
{
  /* reconfigure the layer size */
  HAL_LTDC_SetWindowSize(&LtdcHandler, Width, Height, LayerIndex);

  /* reconfigure the layer position */
  HAL_LTDC_SetWindowPosition(&LtdcHandler, Xpos, Ypos, LayerIndex);
}

/**
  * @brief  Sets display window without reloading.
  * @param  LayerIndex: Layer index
  * @param  Xpos: LCD X position
  * @param  Ypos: LCD Y position
  * @param  Width: LCD window width
  * @param  Height: LCD window height
  * @retval None
  */
void LCD_SetLayerWindow_NoReload(uint16_t LayerIndex, uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height)
{
  /* Reconfigure the layer size */
  HAL_LTDC_SetWindowSize_NoReload(&LtdcHandler, Width, Height, LayerIndex);

  /* Reconfigure the layer position */
  HAL_LTDC_SetWindowPosition_NoReload(&LtdcHandler, Xpos, Ypos, LayerIndex);
}

/**
  * @brief  Configures and sets the color Keying.
  * @param  LayerIndex: the Layer foreground or background
  * @param  RGBValue: the Color reference
  */
void LCD_SetColorKeying(uint32_t LayerIndex, uint32_t RGBValue)
{
  /* Configure and Enable the color Keying for LCD Layer */
  HAL_LTDC_ConfigColorKeying(&LtdcHandler, RGBValue, LayerIndex);
  HAL_LTDC_EnableColorKeying(&LtdcHandler, LayerIndex);
}

/**
  * @brief  Configures and sets the color keying without reloading.
  * @param  LayerIndex: Layer foreground or background
  * @param  RGBValue: Color reference
  * @retval None
  */
void LCD_SetColorKeying_NoReload(uint32_t LayerIndex, uint32_t RGBValue)
{
  /* Configure and Enable the color Keying for LCD Layer */
  HAL_LTDC_ConfigColorKeying_NoReload(&LtdcHandler, RGBValue, LayerIndex);
  HAL_LTDC_EnableColorKeying_NoReload(&LtdcHandler, LayerIndex);
}

/**
  * @brief  Disables the color Keying.
  * @param  LayerIndex: the Layer foreground or background
  */
void LCD_ResetColorKeying(uint32_t LayerIndex)
{
  /* Disable the color Keying for LCD Layer */
  HAL_LTDC_DisableColorKeying(&LtdcHandler, LayerIndex);
}

/**
  * @brief  Disables the color keying without reloading.
  * @param  LayerIndex: Layer foreground or background
  * @retval None
  */
void LCD_ResetColorKeying_NoReload(uint32_t LayerIndex)
{
  /* Disable the color Keying for LCD Layer */
  HAL_LTDC_DisableColorKeying_NoReload(&LtdcHandler, LayerIndex);
}

/**
  * @brief  Disables the color keying without reloading.
  * @param  ReloadType: can be one of the following values
  *         - LCD_RELOAD_IMMEDIATE
  *         - LCD_RELOAD_VERTICAL_BLANKING
  * @retval None
  */
void LCD_Relaod(uint32_t ReloadType)
{
  HAL_LTDC_Relaod (&LtdcHandler, ReloadType);
}


/**
  * @brief  Displays an horizontal line.
  * @param  Xpos: the X position
  * @param  Ypos: the Y position
  * @param  Length: line length
  */
void LCD_DrawHLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length, uint16_t Color)
{
  uint32_t xaddress = 0;

  /* Get the line address */
  xaddress = (LtdcHandler.LayerCfg[ActiveLayer].FBStartAdress) + 2 * (LCD_GetXSize()*Ypos + Xpos);

  /* Write line */
  FillBuffer(ActiveLayer, (uint32_t *)xaddress, Length, 1, 0, Color);
}

/**
  * @brief  Displays a vertical line.
  * @param  Xpos: the X position
  * @param  Ypos: the Y position
  * @param  Length: line length
  */
void LCD_DrawVLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length, uint16_t Color)
{
  uint32_t xaddress = 0;

  /* Get the line address */
  xaddress = (LtdcHandler.LayerCfg[ActiveLayer].FBStartAdress) + 2 * (LCD_GetXSize()*Ypos + Xpos);

  /* Write line */
  FillBuffer(ActiveLayer, (uint32_t *)xaddress, 1, Length, (LCD_GetXSize() - 1), Color);
}

/**
  * @brief  Displays an uni-line (between two points).
  * @param  X1: the point 1 X position
  * @param  Y1: the point 1 Y position
  * @param  X2: the point 2 X position
  * @param  Y2: the point 2 Y position
  */
void LCD_DrawLine(uint16_t X1, uint16_t Y1, uint16_t X2, uint16_t Y2, uint16_t Color)
{
  int16_t deltax = 0, deltay = 0, x = 0, y = 0, xinc1 = 0, xinc2 = 0,
  yinc1 = 0, yinc2 = 0, den = 0, num = 0, numadd = 0, numpixels = 0,
  curpixel = 0;

  deltax = ABS(X2 - X1);        /* The difference between the x's */
  deltay = ABS(Y2 - Y1);        /* The difference between the y's */
  x = X1;                       /* Start x off at the first pixel */
  y = Y1;                       /* Start y off at the first pixel */

  if (X2 >= X1)                 /* The x-values are increasing */
  {
    xinc1 = 1;
    xinc2 = 1;
  }
  else                          /* The x-values are decreasing */
  {
    xinc1 = -1;
    xinc2 = -1;
  }

  if (Y2 >= Y1)                 /* The y-values are increasing */
  {
    yinc1 = 1;
    yinc2 = 1;
  }
  else                          /* The y-values are decreasing */
  {
    yinc1 = -1;
    yinc2 = -1;
  }

  if (deltax >= deltay)         /* There is at least one x-value for every y-value */
  {
    xinc1 = 0;                  /* Don't change the x when numerator >= denominator */
    yinc2 = 0;                  /* Don't change the y for every iteration */
    den = deltax;
    num = deltax / 2;
    numadd = deltay;
    numpixels = deltax;         /* There are more x-values than y-values */
  }
  else                          /* There is at least one y-value for every x-value */
  {
    xinc2 = 0;                  /* Don't change the x for every iteration */
    yinc1 = 0;                  /* Don't change the y when numerator >= denominator */
    den = deltay;
    num = deltay / 2;
    numadd = deltax;
    numpixels = deltay;         /* There are more y-values than x-values */
  }

  for (curpixel = 0; curpixel <= numpixels; curpixel++)
  {
    LCD_DrawPixel(x, y, Color);   /* Draw the current pixel */
    num += numadd;                            /* Increase the numerator by the top of the fraction */
    if (num >= den)                           /* Check if numerator >= denominator */
    {
      num -= den;                             /* Calculate the new numerator value */
      x += xinc1;                             /* Change the x as appropriate */
      y += yinc1;                             /* Change the y as appropriate */
    }
    x += xinc2;                               /* Change the x as appropriate */
    y += yinc2;                               /* Change the y as appropriate */
  }
}

/**
  * @brief  Displays a rectangle.
  * @param  Xpos: the X position
  * @param  Ypos: the Y position
  * @param  Height: display rectangle height
  * @param  Width: display rectangle width
  */
void LCD_DrawRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height, uint16_t Color)
{
  /* Draw horizontal lines */
  LCD_DrawHLine(Xpos, Ypos, Width,Color);
  LCD_DrawHLine(Xpos, (Ypos+ Height), Width, Color);

  /* Draw vertical lines */
  LCD_DrawVLine(Xpos, Ypos, Height, Color);
  LCD_DrawVLine((Xpos + Width), Ypos, Height, Color);
}

/**
  * @brief  Displays a circle.
  * @param  Xpos: the X position
  * @param  Ypos: the Y position
  * @param  Radius: the circle radius
  */
void LCD_DrawCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius, uint16_t Color)
{
	if(Radius == 0) return;

  int32_t  d;/* Decision Variable */
  uint32_t  curx;/* Current X Value */
  uint32_t  cury;/* Current Y Value */

  d = 3 - (Radius << 1);
  curx = 0;
  cury = Radius;

  while (curx <= cury)
  {
    LCD_DrawPixel((Xpos + curx), (Ypos - cury), Color);
    LCD_DrawPixel((Xpos - curx), (Ypos - cury), Color);
    LCD_DrawPixel((Xpos + cury), (Ypos - curx), Color);
    LCD_DrawPixel((Xpos - cury), (Ypos - curx), Color);
    LCD_DrawPixel((Xpos + curx), (Ypos + cury), Color);
    LCD_DrawPixel((Xpos - curx), (Ypos + cury), Color);
    LCD_DrawPixel((Xpos + cury), (Ypos + curx), Color);
    LCD_DrawPixel((Xpos - cury), (Ypos + curx), Color);

    if (d < 0)
    {
      d += (curx << 2) + 6;
    }
    else
    {
      d += ((curx - cury) << 2) + 10;
      cury--;
    }
    curx++;
  }
}

/**
  * @brief  Displays an poly-line (between many points).
  * @param  Points: pointer to the points array
  * @param  PointCount: Number of points
  */
void LCD_DrawPolygon(pPoint Points, uint16_t PointCount, uint16_t Color)
{
  int16_t x = 0, y = 0;

  if(PointCount < 2)
  {
    return;
  }

  LCD_DrawLine(Points->X, Points->Y, (Points+PointCount-1)->X, (Points+PointCount-1)->Y, Color);

  while(--PointCount)
  {
    x = Points->X;
    y = Points->Y;
    Points++;
    LCD_DrawLine(x, y, Points->X, Points->Y, Color);
  }
}

/**
  * @brief  Displays an Ellipse.
  * @param  Xpos: the X position
  * @param  Ypos: the Y position
  * @param  XRadius: the X radius of ellipse
  * @param  YRadius: the Y radius of ellipse
  */
void LCD_DrawEllipse(int Xpos, int Ypos, int XRadius, int YRadius, uint16_t Color)
{
  int x = 0, y = -YRadius, err = 2-2*XRadius, e2;
  float k = 0, rad1 = 0, rad2 = 0;

  rad1 = XRadius;
  rad2 = YRadius;

  k = (float)(rad2/rad1);

  do {
    LCD_DrawPixel((Xpos-(uint16_t)(x/k)), (Ypos+y), Color);
    LCD_DrawPixel((Xpos+(uint16_t)(x/k)), (Ypos+y), Color);
    LCD_DrawPixel((Xpos+(uint16_t)(x/k)), (Ypos-y), Color);
    LCD_DrawPixel((Xpos-(uint16_t)(x/k)), (Ypos-y), Color);

    e2 = err;
    if (e2 <= x) {
      err += ++x*2+1;
      if (-y == x && e2 <= y) e2 = 0;
    }
    if (e2 > y) err += ++y*2+1;
  }
  while (y <= 0);
}

/**
  * @brief  Displays a bitmap picture loaded in the internal Flash (32 bpp).
  * @param  X: the bmp x position in the LCD
  * @param  Y: the bmp Y position in the LCD
  * @param  pBmp: Bmp picture address in the internal Flash
  */
void LCD_DrawBitmap(uint32_t X, uint32_t Y, uint8_t *pBmp)
{
  uint32_t index = 0, width = 0, height = 0, bitpixel = 0;
  uint32_t address;

  /* Get bitmap data address offset */
  index = pBmp[10] + (pBmp[11] << 8) + (pBmp[12] << 16)  + (pBmp[13] << 24);

  /* Read bitmap width */
  width = pBmp[18] + (pBmp[19] << 8) + (pBmp[20] << 16)  + (pBmp[21] << 24);

  /* Read bitmap height */
  height = pBmp[22] + (pBmp[23] << 8) + (pBmp[24] << 16)  + (pBmp[25] << 24);

  /* Read bit/pixel */
  bitpixel = pBmp[28] + (pBmp[29] << 8);

  /* Set Address */
  address = LtdcHandler.LayerCfg[ActiveLayer].FBStartAdress + (((LCD_GetXSize()*Y) + X)*(4));

  /* bypass the bitmap header */
  pBmp += (index + (width * (height - 1) * (bitpixel / 8)));

  /* Convert picture to ARGB8888 pixel format */
  for(index=0; index < height; index++)
  {
  /* Increment the source and destination buffers */
  	address +=  ((LCD_GetXSize() - width + width) * 4);
  	pBmp -= width * (bitpixel / 8);
  }
}

/**
  * @brief  Displays a full rectangle.
  * @param  Xpos: the X position
  * @param  Ypos: the Y position
  * @param  Height: rectangle height
  * @param  Width: rectangle width
  */
void LCD_FillRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height, uint16_t Color)
{
  uint32_t xaddress = 0;

  if((Xpos >= LCD_GetXSize()) || (Ypos >= LCD_GetYSize())) return;
  if(Width == 0 || Height == 0) return;

  /* Get the rectangle start address */
  xaddress = (LtdcHandler.LayerCfg[ActiveLayer].FBStartAdress) + 2 * (LCD_GetXSize()*Ypos + Xpos);

  /* Fill the rectangle */
  FillBuffer(ActiveLayer, (uint32_t *)xaddress, Width, Height, (LCD_GetXSize() - Width), Color);
}

/**
  * @brief  Displays a full circle.
  * @param  Xpos: the X position
  * @param  Ypos: the Y position
  * @param  Radius: the circle radius
  */
void LCD_FillCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius, uint16_t Color)
{
  int32_t  d;    /* Decision Variable */
  uint32_t  curx;/* Current X Value */
  uint32_t  cury;/* Current Y Value */

  if(Radius == 0) return;

  d = 3 - (Radius << 1);

  curx = 0;
  cury = Radius;

  while (curx <= cury)
  {
    if(cury > 0)
    {
      LCD_DrawHLine(Xpos - cury, Ypos + curx, 2*cury, Color);
      LCD_DrawHLine(Xpos - cury, Ypos - curx, 2*cury, Color);
    }

    if(curx > 0)
    {
      LCD_DrawHLine(Xpos - curx, Ypos - cury, 2*curx, Color);
      LCD_DrawHLine(Xpos - curx, Ypos + cury, 2*curx, Color);
    }
    if (d < 0)
    {
      d += (curx << 2) + 6;
    }
    else
    {
      d += ((curx - cury) << 2) + 10;
      cury--;
    }
    curx++;
  }

  LCD_DrawCircle(Xpos, Ypos, Radius, Color);
}

/**
  * @brief  Fill triangle.
  * @param  X1: the point 1 x position
  * @param  Y1: the point 1 y position
  * @param  X2: the point 2 x position
  * @param  Y2: the point 2 y position
  * @param  X3: the point 3 x position
  * @param  Y3: the point 3 y position
  */
void LCD_FillTriangle(uint16_t X1, uint16_t X2, uint16_t X3, uint16_t Y1, uint16_t Y2, uint16_t Y3, uint16_t Color)
{
  int16_t deltax = 0, deltay = 0, x = 0, y = 0, xinc1 = 0, xinc2 = 0,
  yinc1 = 0, yinc2 = 0, den = 0, num = 0, numadd = 0, numpixels = 0,
  curpixel = 0;

  deltax = ABS(X2 - X1);        /* The difference between the x's */
  deltay = ABS(Y2 - Y1);        /* The difference between the y's */
  x = X1;                       /* Start x off at the first pixel */
  y = Y1;                       /* Start y off at the first pixel */

  if (X2 >= X1)                 /* The x-values are increasing */
  {
    xinc1 = 1;
    xinc2 = 1;
  }
  else                          /* The x-values are decreasing */
  {
    xinc1 = -1;
    xinc2 = -1;
  }

  if (Y2 >= Y1)                 /* The y-values are increasing */
  {
    yinc1 = 1;
    yinc2 = 1;
  }
  else                          /* The y-values are decreasing */
  {
    yinc1 = -1;
    yinc2 = -1;
  }

  if (deltax >= deltay)         /* There is at least one x-value for every y-value */
  {
    xinc1 = 0;                  /* Don't change the x when numerator >= denominator */
    yinc2 = 0;                  /* Don't change the y for every iteration */
    den = deltax;
    num = deltax / 2;
    numadd = deltay;
    numpixels = deltax;         /* There are more x-values than y-values */
  }
  else                          /* There is at least one y-value for every x-value */
  {
    xinc2 = 0;                  /* Don't change the x for every iteration */
    yinc1 = 0;                  /* Don't change the y when numerator >= denominator */
    den = deltay;
    num = deltay / 2;
    numadd = deltax;
    numpixels = deltay;         /* There are more y-values than x-values */
  }

  for (curpixel = 0; curpixel <= numpixels; curpixel++)
  {
    LCD_DrawLine(x, y, X3, Y3, Color);

    num += numadd;              /* Increase the numerator by the top of the fraction */
    if (num >= den)             /* Check if numerator >= denominator */
    {
      num -= den;               /* Calculate the new numerator value */
      x += xinc1;               /* Change the x as appropriate */
      y += yinc1;               /* Change the y as appropriate */
    }
    x += xinc2;                 /* Change the x as appropriate */
    y += yinc2;                 /* Change the y as appropriate */
  }
}

/**
  * @brief  Displays a full poly-line (between many points).
  * @param  Points: pointer to the points array
  * @param  PointCount: Number of points
  */
void LCD_FillPolygon(pPoint Points, uint16_t PointCount, uint16_t Color)
{

  int16_t x = 0, y = 0, x2 = 0, y2 = 0, xcenter = 0, ycenter = 0, xfirst = 0, yfirst = 0, pixelx = 0, pixely = 0, counter = 0;
  uint16_t  imageleft = 0, imageright = 0, imagetop = 0, imagebottom = 0;

  imageleft = imageright = Points->X;
  imagetop= imagebottom = Points->Y;

  for(counter = 1; counter < PointCount; counter++)
  {
    pixelx = POLY_X(counter);
    if(pixelx < imageleft)
    {
      imageleft = pixelx;
    }
    if(pixelx > imageright)
    {
      imageright = pixelx;
    }

    pixely = POLY_Y(counter);
    if(pixely < imagetop)
    {
      imagetop = pixely;
    }
    if(pixely > imagebottom)
    {
      imagebottom = pixely;
    }
  }

  if(PointCount < 2)
  {
    return;
  }

  xcenter = (imageleft + imageright)/2;
  ycenter = (imagebottom + imagetop)/2;

  xfirst = Points->X;
  yfirst = Points->Y;

  while(--PointCount)
  {
    x = Points->X;
    y = Points->Y;
    Points++;
    x2 = Points->X;
    y2 = Points->Y;

    LCD_FillTriangle(x, x2, xcenter, y, y2, ycenter, Color);
    LCD_FillTriangle(x, xcenter, x2, y, ycenter, y2, Color);
    LCD_FillTriangle(xcenter, x2, x, ycenter, y2, y, Color);
  }

  LCD_FillTriangle(xfirst, x2, xcenter, yfirst, y2, ycenter, Color);
  LCD_FillTriangle(xfirst, xcenter, x2, yfirst, ycenter, y2, Color);
  LCD_FillTriangle(xcenter, x2, xfirst, ycenter, y2, yfirst, Color);
}

/**
  * @brief  Draw a full ellipse.
  * @param  Xpos: the X position
  * @param  Ypos: the Y position
  * @param  XRadius: X radius of ellipse
  * @param  YRadius: Y radius of ellipse.
  */
void LCD_FillEllipse(int Xpos, int Ypos, int XRadius, int YRadius, uint16_t Color)
{
  int x = 0, y = -YRadius, err = 2-2*XRadius, e2;
  float K = 0, rad1 = 0, rad2 = 0;

  rad1 = XRadius;
  rad2 = YRadius;
  K = (float)(rad2/rad1);

  do
  {
    LCD_DrawHLine((Xpos-(uint16_t)(x/K)), (Ypos+y), (2*(uint16_t)(x/K) + 1), Color);
    LCD_DrawHLine((Xpos-(uint16_t)(x/K)), (Ypos-y), (2*(uint16_t)(x/K) + 1), Color);

    e2 = err;
    if (e2 <= x)
    {
      err += ++x*2+1;
      if (-y == x && e2 <= y) e2 = 0;
    }
    if (e2 > y) err += ++y*2+1;
  }
  while (y <= 0);
}

// LCD 백라이트를 조절하여 빩기를 변화시킵니다.  인수는 0(꺼짐)에서 100(완전히 켜짐) 까지 입니다.
void LCD_SetBackLight(uint16_t brightness)	// brightness 0 ~ 100 %
{
	BACKLIGHT_TIMER.Instance->CCR1 = brightness;
}

