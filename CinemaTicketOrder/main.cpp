#include "Login.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // set the app stylesheet
    QFile styleSheetFile(":/qss/Fibrary.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);

    Login w;
    w.show();
    return a.exec();
}
