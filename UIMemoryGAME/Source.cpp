#include <QApplication>
#include <QPushButton>
#include "Hehee.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QPushButton button("Hello, Qt!");
    button.resize(200, 100);
    button.show();

	adunare(2, 3);

    return app.exec();
}