#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv); 

    QPushButton button("Hello from Process Explorer!");
    button.resize(300, 100);
    button.show();

    return app.exec();
}
