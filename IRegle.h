#pragma once
class IRegle
{

public: 
    virtual ~IRegle(){}
    virtual bool Vivant(int nb_cote)=0;
    virtual bool Morte(int nb_cote)=0;
};
