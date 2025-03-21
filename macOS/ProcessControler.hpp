#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include "ProcessExplorer.hpp"

class ProcessControler{
public:
    ProcessControler(ProcessExplorer& explorer) : explorer_(explorer) {}
    void printProcesses();
    void monitorProcess(pid_t pid, int frequency);

private:
    ProcessExplorer& explorer_; 
};