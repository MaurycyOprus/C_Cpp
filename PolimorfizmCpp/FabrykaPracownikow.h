#pragma once
#include "Pracownik.h"
#include "FabrykaOsob.h"

class FabrykaPracownikow: public FabrykaOsob
{
    public:
        Pracownik *utworz();
};