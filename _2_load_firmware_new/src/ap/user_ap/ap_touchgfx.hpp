/*
 * ap_touchgfx.hpp
 *
 *  Created on: Oct 8, 2024
 *      Author: ksj10
 */

#ifndef AP_USER_AP_AP_TOUCHGFX_HPP_
#define AP_USER_AP_AP_TOUCHGFX_HPP_


#include "ap.h"


/*
 * @brief: Fetch .c file data and send it to screenView.cpp
 */
class ApTouchGfx
{
public:
    ApTouchGfx();
    virtual ~ApTouchGfx(){}
    virtual void init();
    virtual void loop();
private:
    virtual void readData();
};


#endif /* AP_USER_AP_AP_TOUCHGFX_HPP_ */
