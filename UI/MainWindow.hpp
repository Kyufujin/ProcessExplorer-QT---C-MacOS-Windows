#pragma once
#include <QMainWindow>
#include <QTableWidget>
#include <QHeaderView>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QTableWidget *pTable; 

    void setUI();           
    void loadProcesses();     
};
