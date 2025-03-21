#pragma once
#include <iostream>
#include <libproc.h>
#include <sys/sysctl.h>
#include <vector>
#include <string>
#include "ProcessUnit.hpp"

class ProcessExplorer{
    private:
        void ProcessTerminator(pid_t pid, bool isForced); //// I'LL BE BACK
    public:
        std::vector<ProcessUnit> getProcessList();
    };