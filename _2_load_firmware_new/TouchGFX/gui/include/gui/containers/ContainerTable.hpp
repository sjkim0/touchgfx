#ifndef CONTAINERTABLE_HPP
#define CONTAINERTABLE_HPP

#include <gui_generated/containers/ContainerTableBase.hpp>

class ContainerTable : public ContainerTableBase
{
public:
    ContainerTable();
    virtual ~ContainerTable() {}

    virtual void initialize();
protected:
};

#endif // CONTAINERTABLE_HPP
