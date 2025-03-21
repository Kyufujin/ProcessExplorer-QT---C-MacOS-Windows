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

        struct proc_taskinfo tInfo;
        if (proc_pidinfo(procList[i].kp_proc.p_pid, PROC_PIDTASKINFO, 0, &tInfo, sizeof(tInfo)) > 0) {
            size_t residentMB = tInfo.pti_resident_size / 1024 / 1024;
            size_t virtualMB = tInfo.pti_virtual_size / 1024 / 1024;
            size_t cpuTimeMS = (tInfo.pti_total_user + tInfo.pti_total_system) / 1000000;
        
            pInfo.setpMemory(residentMB, virtualMB);
            pInfo.setpCPUtime(cpuTimeMS);
        }

        pList.push_back(pInfo);
    }

    return pList;
}

void ProcessExplorer::ProcessTerminator(pid_t pid, bool isForced){
    int signal = isForced ? SIGKILL : SIGTERM;
    if (kill(pid, signal) == -1) {
        std::cerr << "process could not be killed\n" << pid << "\n";
    } else {
        std::cout << "Process: " << pid << " was terminated.\n";
    }
}

int ProcessExplorer::getProcessPriority(pid_t pid){
    errno = 0;
    int priority = getpriority(PRIO_PROCESS, pid);

    if (errno != 0) {
        throw std::runtime_error("Process priority could not be obtained for: " + std::to_string(pid));
    }

    return priority;
}

void ProcessExplorer::changeProcessPriority(pid_t pid, int delta){
    errno = 0; 
    int currentPriority = getpriority(PRIO_PROCESS, pid);

    if (errno != 0) { 
        throw std::runtime_error("couldn't get the priority");
    }

    int newPriority = std::clamp(currentPriority + delta, -20, 19);

    if (setpriority(PRIO_PROCESS, pid, newPriority) == -1) {
        throw std::runtime_error("couldn't change the priority");
    }
}

