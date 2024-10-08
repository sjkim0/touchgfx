#ifndef CONTAINERCOMM_HPP
#define CONTAINERCOMM_HPP

#include <gui_generated/containers/ContainerCommBase.hpp>

class ContainerComm : public ContainerCommBase
{
public:
    ContainerComm();
    virtual ~ContainerComm() {}

    virtual void initialize();
protected:
};

#endif // CONTAINERCOMM_HPP
