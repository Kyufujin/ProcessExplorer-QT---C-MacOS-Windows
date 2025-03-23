#include "Clicker.hpp"

Clicker::Clicker(QWidget *parent) : QObject(parent) {
    contextMenu = new QMenu(parent);
    contextMenu->addAction("remove process");
    contextMenu->addAction("change priority");

    parent->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(parent, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
}

void Clicker::showContextMenu(const QPoint &pos) {
    QAction *selectedAction = contextMenu->exec(static_cast<QWidget *>(parent())->mapToGlobal(pos));
    if (selectedAction) {
        if (selectedAction->text() == "remove") {
            qDebug() << "removed";
        } else if (selectedAction->text() == "change prio") {
            qDebug() << "prio changed";
        }
    }
}