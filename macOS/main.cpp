#include <QApplication>
#include <QPushButton>
#include "ProcessControler.hpp"
int main(int argc, char *argv[]) {
    
    /*QApplication app(argc, argv); 
    QPushButton button("Hello from Process Explorer!");
    button.resize(300, 100);
    button.show();
    return app.exec();*/

    //////////////// --> as for now,    QT seems to work, let's focus on functionality instead :)
    try {
        ProcessExplorer explorer;
        ProcessControler controler{explorer};

        controler.printProcesses();

        pid_t pid;
        std::cout << "\nProvide pid of process to monitor: ";
        std::cin >> pid;

        controler.monitorProcess(pid, 2); 

    } catch (const std::runtime_error& e) {
        std::cerr << "error: " << e.what() << "\n";
    }
    return 0;
}
