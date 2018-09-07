#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QDesktopWidget>
#define time 95553666
double Info_of_zhandian::distance_info1 = 200;
double Info_of_zhandian::distance_info2 = 200;
double Info_of_zhandian::distance_info3 = 0;
double Info_of_zhandian::distance_info4 = 0;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap(":/icon/splash.png");
    QSplashScreen splash(pixmap);
    MainWindow w;
    QPixmap pixmap1(":/icon/14.png");//设定图片
    QPalette palette;
    long long int count=0;
    while(count!=time)
    {
        count++;
        splash.show();
    }
    palette.setBrush(w.backgroundRole(),QBrush(pixmap1));
    w.setPalette(palette);
    w.setAutoFillBackground(true);
    w.setWindowIcon(QIcon(":/icon/timg4.png"));
    w.show();
    w.music_display();
    //palette.setBrush(AddLine.backgroundRole(),QBrush(pixmap1));
    //AddLine.setPalette(palette);
    //AddLine.setAutoFillBackground(true);
    splash.finish(&w);
    return a.exec();
}
