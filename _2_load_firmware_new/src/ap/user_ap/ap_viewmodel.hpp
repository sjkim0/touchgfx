/*
 * ap_touchgfx.hpp
 *
 *  Created on: Oct 8, 2024
 *      Author: ksj10
 */

#ifndef AP_USER_AP_AP_VIEWMODEL_HPP_
#define AP_USER_AP_AP_VIEWMODEL_HPP_


#include "ap.h"


/*
 * @brief: Fetch .c file data and send it to screenView.cpp
 */
class ApViewModel
{
public:
    ApViewModel();
    virtual ~ApViewModel(){}
    virtual void init();
    virtual void loop();
private:
    virtual void checkPropertyChanged();
    virtual void setProperty();
};


#endif /* AP_USER_AP_AP_VIEWMODEL_HPP_ */
