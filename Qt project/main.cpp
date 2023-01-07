#include<QApplication>
#include"newWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    newWindow nw;
    nw.show();
    return a.exec();
}
