#include "MainWindow.hpp"
#include "ProcessExplorer.hpp"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setUI();
    loadProcesses();
}

