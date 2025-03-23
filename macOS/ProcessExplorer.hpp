#pragma once
#include <iostream>
#include <libproc.h>
#include <sys/sysctl.h>
#include <vector>
#include <string>
#include "ProcessUnit.hpp"
#include <optional>

class ProcessExplorer{
    public:
        int  getProcessPriority(pid_t pid);
        void ProcessTerminator(pid_t pid, bool isForced); //// I'LL BE BACK
        void changeProcessPriority(pid_t pid, int delta);
        std::vector<ProcessUnit> getProcessList();
    };