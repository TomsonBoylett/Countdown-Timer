#include "countdowntimer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CountdownTimer w;
    w.show();

    return a.exec();
}
