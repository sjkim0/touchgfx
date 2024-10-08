#ifndef CONTAINERDESCRIPTION_HPP
#define CONTAINERDESCRIPTION_HPP

#include <gui_generated/containers/ContainerDescriptionBase.hpp>

class ContainerDescription : public ContainerDescriptionBase
{
public:
    ContainerDescription();
    virtual ~ContainerDescription() {}

    virtual void initialize();
protected:
};

#endif // CONTAINERDESCRIPTION_HPP
