#include "Lib.h"
#pragma once
class ICell
{

public:
    virtual ~ICell(){}
    virtual bool GetEtat()=0;
    virtual void SetEtat(bool a)=0;
};
