#include "IRegle.h"
#pragma once
class RegleJDLV: public IRegle
{

public:
    RegleJDLV(){}
    ~RegleJDLV()override{}
    bool Vivant(int nb_cote)override;
    bool Morte(int nb_cote)override;

};

