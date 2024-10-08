#ifndef CONTAINERSTATE_HPP
#define CONTAINERSTATE_HPP

#include <gui_generated/containers/ContainerStateBase.hpp>

class ContainerState : public ContainerStateBase
{
public:
    ContainerState();
    virtual ~ContainerState() {}

    virtual void initialize();
protected:
};

#endif // CONTAINERSTATE_HPP
