#pragma once
#include <QMainWindow>
#include <QTableWidget>
#include <QHeaderView>
#include <QTimer>
#include <memory>
#include "../macOS/ProcessExplorer.hpp" // was trying to work on that but couldn't figure it out beter :(
#include "Clicker.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    std::unique_ptr<QTableWidget> pTable;
    std::unique_ptr<Clicker> clicker; 
    void setUI();           
    void loadProcesses();     
};
