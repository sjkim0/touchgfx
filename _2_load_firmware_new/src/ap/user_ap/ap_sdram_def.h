/*
 * ap_sdram_def.h
 *
 *  Created on: Sep 28, 2024
 *      Author: ksj10
 */

#ifndef AP_USER_AP_AP_SDRAM_DEF_H_
#define AP_USER_AP_AP_SDRAM_DEF_H_


#ifdef __cplusplus
extern "C" {
#endif


#define DEF_FMC_SDRAM_BK_1_SR_1_MEM_ADDR             (0xC0000000U)

#define DEF_SDRAM_TIMEOUT                            ((uint32_t)0xFFFF)
#define DEF_REFRESH_COUNT                            ((uint32_t)0x0603)   /* SDRAM refresh counter (100Mhz SD clock) */
#define DEF_SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
#define DEF_SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
#define DEF_SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
#define DEF_SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)
#define DEF_SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
#define DEF_SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
#define DEF_SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
#define DEF_SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)
#define DEF_SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define DEF_SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
#define DEF_SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)


#ifdef __cplusplus
}
#endif


#endif /* AP_USER_AP_AP_SDRAM_DEF_H_ */
