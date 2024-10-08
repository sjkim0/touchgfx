#ifndef CONTAINERFRAME_HPP
#define CONTAINERFRAME_HPP

#include <gui_generated/containers/ContainerFrameBase.hpp>

class ContainerFrame : public ContainerFrameBase
{
public:
    ContainerFrame();
    virtual ~ContainerFrame() {}

    virtual void initialize();
protected:
};

#endif // CONTAINERFRAME_HPP
