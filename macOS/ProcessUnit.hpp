#pragma once
#include <string>
#include <libproc.h>
#include <sys/sysctl.h>
#include <vector>
#include <signal.h>

class ProcessUnit{
private:
    pid_t pid_;
    std::string pName_;
    size_t pRAM_;
    size_t pCPU_;
    size_t PVMEMORY_;
public:
    ProcessUnit()
        : pid_(0), pName_("none"), pRAM_(0), PVMEMORY_(0), pCPU_(0) {}

    pid_t getpID() const;
    std::string  getpName() const;
    size_t getpRAM() const;
    size_t getpCPU() const;
    size_t getpVMEMORY() const;
    void setpID(pid_t id);
    void setpName(std::string name);
    void setpMemory(size_t RAM, size_t vMemory);
    void setpCPUtime(size_t cpuTime);
    //double getpRAM();
    //double getpCPU();
};
