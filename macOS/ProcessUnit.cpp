#include "ProcessUnit.hpp"

pid_t ProcessUnit::getpID() const{
    return pid_;
}
    
std::string  ProcessUnit::getpName() const{
    return pName_;
}

size_t ProcessUnit::getpRAM() const
{
    return pRAM_;
}

size_t ProcessUnit::getpCPU() const
{
    return pCPU_;
}

size_t ProcessUnit::getpVMEMORY() const
{
    return PVMEMORY_;
}

void ProcessUnit::setpID(pid_t id){
    pid_ = id;
}

void ProcessUnit::setpName(std::string name){
     pName_= name;
}

void ProcessUnit::setpMemory(size_t RAM, size_t vMemory)
{
    pRAM_ = RAM;
    PVMEMORY_ = vMemory;
}

void ProcessUnit::setpCPUtime(size_t cpuTime)
{
    pCPU_ = cpuTime;
}
