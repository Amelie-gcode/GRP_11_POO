#include "ICell.h"
#pragma once

class Cell:public ICell
{
private:
    bool etat;
public:
    Cell();
    ~Cell();
    bool GetEtat()override;
    void SetEtat(bool a)override;
};

