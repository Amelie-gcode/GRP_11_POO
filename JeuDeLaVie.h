#pragma once
#include "FichierEcrire.h"
#include "FichierLire.h"
class JeuDeLaVie
{
public:
    virtual ~JeuDeLaVie(){}
    virtual void run()=0;
};

