#ifndef CONTAINERALC_HPP
#define CONTAINERALC_HPP

#include <gui_generated/containers/ContainerALCBase.hpp>

class ContainerALC : public ContainerALCBase
{
public:
    ContainerALC();
    virtual ~ContainerALC() {}

    virtual void initialize();
protected:
};

#endif // CONTAINERALC_HPP
