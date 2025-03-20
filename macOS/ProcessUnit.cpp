#include "ProcessUnit.hpp"

pid_t ProcessUnit::getpID() const{
    return pid_;
}
    
std::string  ProcessUnit::getpName() const{
    return pName_;
}

void ProcessUnit::setpID(pid_t id){
    pid_ = id;
}

void ProcessUnit::setpName(std::string name){
     pName_= name;
}