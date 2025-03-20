#pragma once
#include <string>
#include <libproc.h>
#include <sys/sysctl.h>
#include <vector>

class ProcessUnit{
private:
    pid_t pid_;
    std::string pName_;
    double pRAM_;
    double pCPU_;
public:
    pid_t getpID() const;
    std::string  getpName() const;
    void setpID(pid_t id);
    void setpName(std::string name);
    //double getpRAM();
    //double getpCPU();
};
