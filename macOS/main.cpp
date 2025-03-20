#include <QApplication>
#include <QPushButton>
#include "ProcessExplorer.hpp"

int main(int argc, char *argv[]) {
    
    /*QApplication app(argc, argv); 
    QPushButton button("Hello from Process Explorer!");
    button.resize(300, 100);
    button.show();
    return app.exec();*/

    //////////////// --> as for now,    QT seems to work, let's focus on functionality instead :)
    try{
    ProcessExplorer explorer;
    auto processes = explorer.getProcessList();
    for(const auto& process : processes) {
        std::cout << process.getpID() << "\t" << process.getpName() << "\n";
    }
    }catch(const std::runtime_error& e){
        std::cerr << "error: " << e.what();
    }
    return 0;
}
