#include "Clicker.hpp"

#include "Clicker.hpp"
#include <QTableWidget>
#include <QAction>
#include <QDebug>

Clicker::Clicker(QWidget *parent) : QObject(parent), selectedPid(-1) {
    contextMenu = new QMenu(parent);
    QAction *removeAction = contextMenu->addAction("Usuń proces");
    contextMenu->addAction("Zmień priorytet");

    parent->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(parent, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
    connect(removeAction, &QAction::triggered, [this]() {
        if (selectedPid != -1) {
            emit processToRemove(selectedPid);
        }
    });
}

void Clicker::showContextMenu(const QPoint &pos) {
    QTableWidget *table = qobject_cast<QTableWidget *>(parent());
    if (!table) return;

    QModelIndex index = table->indexAt(pos);
    if (index.isValid()) {
        selectedPid = table->item(index.row(), 1)->text().toInt();
        contextMenu->exec(table->mapToGlobal(pos));
    } else {
        selectedPid = -1; 
    }
}
