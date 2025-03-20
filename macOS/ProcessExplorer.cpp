#include "ProcessExplorer.hpp"
#include <memory>
#include <array>
#include <exception>

std::vector<ProcessUnit> ProcessExplorer::getProcessList(){
    std::vector<ProcessUnit> pList;

    std::array<int, 3> mib= {CTL_KERN, KERN_PROC, KERN_PROC_ALL};
    size_t size;
    if (sysctl(mib.data(), mib.size(), nullptr, &size, nullptr, 0) == -1) {
        throw std::runtime_error("List of the processes could not be collected");
        return pList;
    }

    int procCount = static_cast<int>(size / sizeof(kinfo_proc));
    auto procList = std::make_unique<kinfo_proc[]>(procCount);

    if (sysctl(mib.data(), mib.size(), procList.get(), &size, nullptr, 0) == -1) {
        throw std::runtime_error("List of the processes could not be collected");
        return pList;
    }
   
    for (int i = 0; i < procCount; ++i) {
        ProcessUnit pInfo;
        pInfo.setpID(procList[i].kp_proc.p_pid);
        pInfo.setpName(procList[i].kp_proc.p_comm);
        pList.push_back(pInfo);
    }

    return pList;
}

