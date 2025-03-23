#pragma once
#include <QMainWindow>
#include <QTableWidget>
#include <QHeaderView>
#include <QTimer>
#include <memory>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    std::unique_ptr<QTableWidget> pTable; 
    void setUI();           
    void loadProcesses();     
};
