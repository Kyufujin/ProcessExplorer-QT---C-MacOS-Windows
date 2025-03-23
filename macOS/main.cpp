#include <QApplication>
#include <QPushButton>
#include <MainWindow.hpp>
int main(int argc, char *argv[]) {
    
    QApplication app(argc, argv); // Tworzenie aplikacji Qt

    MainWindow mainWindow;        // Tworzenie głównego okna
    mainWindow.show();            // Wyświetlanie okna

    return app.exec();            // Uruchomienie pętli zdarzeń Qt
}
