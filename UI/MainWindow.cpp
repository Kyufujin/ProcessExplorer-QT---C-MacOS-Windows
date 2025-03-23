#include "MainWindow.hpp"
#include <QVBoxLayout>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setUI();
    loadProcesses();

    std::unique_ptr<QTimer> timer = std::make_unique<QTimer>(this);
    connect(timer.get(), &QTimer::timeout, this, &MainWindow::loadProcesses);
    timer->start(5000); 
}

void MainWindow::setUI() {
    pTable = std::make_unique<QTableWidget>(this);
    pTable->setColumnCount(5); 
    pTable->setHorizontalHeaderLabels({"Process", "PID", "CPU (%)", "RAM (MB)", "Virtual Memory (MB)"});
    pTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    pTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    QWidget *mainWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(mainWidget);
    layout->addWidget(pTable.get());

    setCentralWidget(mainWidget);
    setWindowTitle("BB Process Explorer");

    clicker = std::make_unique<Clicker>(pTable.get());
}

void MainWindow::loadProcesses() {
    ProcessExplorer explorer;
    auto processes = explorer.getProcessList();

    pTable->clearContents(); 
    pTable->setRowCount(processes.size());

    for (int i = 0; i < processes.size(); ++i) {
        const auto &process = processes[i];
        auto nameItem = std::make_unique<QTableWidgetItem>(QString::fromStdString(process.getpName()));
        auto pidItem = std::make_unique<QTableWidgetItem>(QString::number(process.getpID()));
        auto cpuItem = std::make_unique<QTableWidgetItem>(QString::number(process.getpCPU()));
        auto ramItem = std::make_unique<QTableWidgetItem>(QString::number(process.getpRAM()));
        auto vMemoryItem = std::make_unique<QTableWidgetItem>(QString::number(process.getpVMEMORY()));    

        pTable->setItem(i, 0, nameItem.release());
        pTable->setItem(i, 1, pidItem.release());
        pTable->setItem(i, 2, cpuItem.release());
        pTable->setItem(i, 3, ramItem.release());
        pTable->setItem(i, 4, vMemoryItem.release());
    }
}
