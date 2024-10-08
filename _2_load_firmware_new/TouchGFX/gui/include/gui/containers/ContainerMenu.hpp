#ifndef CONTAINERMENU_HPP
#define CONTAINERMENU_HPP

#include <gui_generated/containers/ContainerMenuBase.hpp>

class ContainerMenu : public ContainerMenuBase
{
public:
    ContainerMenu();
    virtual ~ContainerMenu() {}

    virtual void initialize();
protected:
};

#endif // CONTAINERMENU_HPP
