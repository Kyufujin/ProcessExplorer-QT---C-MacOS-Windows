#pragma once
#include <QObject>
#include <QWidget>
#include <QMenu>
#include <QPoint>

class Clicker : public QObject {
    Q_OBJECT

public:
    explicit Clicker(QWidget *parent = nullptr);

signals:
    void processToRemove(pid_t pid);   

private slots:
    void showContextMenu(const QPoint &pos);

private:
    QMenu *contextMenu;
    pid_t selectedPid;
};
