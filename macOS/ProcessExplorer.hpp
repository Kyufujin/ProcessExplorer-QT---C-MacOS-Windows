#pragma once
#include <iostream>
#include <libproc.h>
#include <sys/sysctl.h>
#include <vector>
#include <string>
#include "ProcessUnit.hpp"

class ProcessExplorer{
    public:
        std::vector<ProcessUnit> getProcessList();
    };