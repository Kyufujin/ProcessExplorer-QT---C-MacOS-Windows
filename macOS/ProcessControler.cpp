#include "ProcessControler.hpp"

void ProcessControler::printProcesses()
{
    std::cout << "ID --- Name --- RAM --- Virtual Memory --- CPU\n";
    auto processes = explorer_.getProcessList();
    for (const auto& process : processes) {
        std::cout << process.getpID() << "\t" << process.getpName()
                  << "\t" << process.getpRAM() << "\t" << process.getpVMEMORY()
                  << "\t" << process.getpCPU() << "\n";
    }
}


void ProcessControler::monitorProcess(pid_t pid, int frequency) {
    while (true) {
        try {
            auto processes = explorer_.getProcessList();
            auto it = std::find_if(processes.begin(), processes.end(),
                [pid](const ProcessUnit& process) { return process.getpID() == pid; });
    
            if (it != processes.end()) {
                const auto& process = *it;
                std::cout << "PID: " << pid << "\n";
                std::cout << "RAM: " << process.getpRAM() << " MB\n";
                std::cout << "Virtual Memory: " << process.getpVMEMORY() << " MB\n";
                std::cout << "CPU: " << process.getpCPU() << " ms\n";
            } else {
                std::cerr << "Process:" << pid << " Does not exist.\n";
                break;
            }
    
               
            std::this_thread::sleep_for(std::chrono::seconds(frequency));
        } catch (const std::runtime_error& e) {
            std::cerr << "error: " << e.what() << "\n";
            break;
        }
    }
}

