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
    connect(clicker.get(), &Clicker::processToRemove, this, &MainWindow::removeProcess);
}

void MainWindow::loadProcesses() {
    ProcessExplorer explorer;
    auto processes = explorer.getProcessList();

    pTable->clearContents(); 
    pTable->setRowCount(processes.size());

    for (int i = 0; i < processes.size(); ++i) {
        const auto &process = processes[i];
        pTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(process.getpName())));
        pTable->setItem(i, 1, new QTableWidgetItem(QString::number(process.getpID())));
        pTable->setItem(i, 2, new QTableWidgetItem(QString::number(process.getpCPU())));
        pTable->setItem(i, 3, new QTableWidgetItem(QString::number(process.getpRAM())));
        pTable->setItem(i, 4, new QTableWidgetItem(QString::number(process.getpVMEMORY())));
    }
}

void MainWindow::removeProcess(pid_t pid) {
    ProcessExplorer explorer; 
    try {
        explorer.ProcessTerminator(pid, true); 
        qDebug() << "PID: " << pid << "removed";
    } catch (const std::runtime_error &e) {
        qDebug() << "PID: " << pid << ". Could not be removed:" << e.what();
    }
}
