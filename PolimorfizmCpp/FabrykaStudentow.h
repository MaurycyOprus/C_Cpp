#pragma once
#include "Student.h"
#include "FabrykaOsob.h"

class FabrykaStudentow: public FabrykaOsob
{
    public:
        Student *utworz();
};