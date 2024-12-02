#include "IRegle.h"

class RegleJDLV: public IRegle
{

public:
    RegleJDLV(){}
    ~RegleJDLV(){}
    bool Vivant(int nb_cote)override;
    bool Morte(int nb_cote)override;

};

