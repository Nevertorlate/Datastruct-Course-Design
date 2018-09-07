#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "graphics_view_zoom.h"
#include <Windows.h>
#include <QMainWindow>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include<QtMultimedia/QMediaPlayer>
#include <QDialog>
#include <QVector>
#include <QTabWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QIcon>
#include <QString>
#include <QPoint>
#include <QHash>
#include <QColor>
#include <QPair>
#include <QSet>
#include <QPointF>
#include <QSet>
#include <math.h>
class Shanghai_sub;
class QTextStream;
typedef QPair<int,int> Edge;
class Info_of_zhandian
{
public:
    int Info_xianluandzhandian_code;QString name;QSet<int> xianlu_Qset_ALL;
    static double distance_info1, distance_info2, distance_info3, distance_info4;double Info_of_zhandian_info_1, Info_of_zhandian_info_2;
    Info_of_zhandian(){}
    Info_of_zhandian(QString nameStr, double longi, double lati, QList<int> linesList);
protected:friend class Shanghai_sub;friend class QTextStream;
};
class xianlu_info_ALL
{
public:
    int Info_xianluandzhandian_code;
    QString name;QColor color;
    QVector <QString> fromTo;QSet<int> zhandian_Qset_ALL;QSet<Edge> xianlu_ALLInfo;
    xianlu_info_ALL(){}
    xianlu_info_ALL(QString Info_for_all, QColor Yanse_xianlu_info):name(Info_for_all), color(Yanse_xianlu_info){}
    friend class Shanghai_sub;friend class QTextStream;
};
class Info_of_distance{
public:
    int zhandian_intInfo;double distance;
    Info_of_distance(){}
    Info_of_distance(int s, double dist) :zhandian_intInfo(s), distance(dist){}
    bool operator > (const Info_of_distance& n) const{return distance>n.distance;}
};
class Shanghai_sub
{
public:QVector<Info_of_zhandian> stations; QVector<xianlu_info_ALL> lines;QVector<QVector<Info_of_distance>> Link_Subwang;
    QHash<QString, int> Info_ALLzhandian,Info_ALLxianlu;QSet<Edge> xianlu_ALLInfo;
    Shanghai_sub(){}
    bool SearchTime(int &length,int s1, int s2,QList<int>&zhandian_display,QList<Edge>&xianlu_display,int temp);
};
class MainWindow;
namespace Ui {class AddLine;}
class AddLine : public QDialog
{
    Q_OBJECT
private slots:
    void on_pushButtonChooseColor_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_lineEditLineName_textChanged(const QString &arg1){Info_for_all[0]=arg1;}
    void on_lineEditStationName_textChanged(const QString &arg1){Info_for_all[1]=arg1;}
    void on_doubleSpinBoxLatitude_valueChanged(double arg1){Info_of_zhandian_info_2=arg1;}
    void on_doubleSpinBoxLongitude_valueChanged(double arg1){Info_of_zhandian_info_1=arg1;}
public:
    explicit AddLine(QWidget *parent = 0);
    ~AddLine();
protected:
    Ui::AddLine *ui;
    double Info_of_zhandian_info_1,Info_of_zhandian_info_2;
    QVector<QWidget*> More_addTab;QVector<QIcon> More_addIcon;QVector<QString> More_adderam;
    QString Info_for_all[2];
    QColor Yanse_xianlu_info;QList<QString> Info_for_all_temp,Info_for_all_2,Info_for_all_final;
    friend class MainWindow;
};
namespace Ui {class MainWindow;}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();void music_display();
    QLabel* statusLabel1, *statusLabel2, *statusLabel3,*statusLabel4,*statusLabel5;
    QMediaPlayer* player1;
    QMediaPlaylist* playlist;
protected:
    Ui::MainWindow *ui;Graphics_view_zoom *display_graph;
    QGraphicsScene *display_graph_info;Shanghai_sub* ALL_Subwang_info;AddLine* addLine;
    void Painting_1 (const QList<Edge>& xianlu_display);void Painting_2 (const QList<int>& zhandian_display);
public slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void Info_change();
    void on_pushButton_7_clicked();
    void Tool_2();
    void on_pushButton_10_clicked();
    void on_pushButton_15_clicked();
    void Tool_4();
    void Request_temp();
    void on_pushButton_14_clicked();
    void Info_of_zhandian_find(QString Info_for_all);
    void on_pushButton_11_clicked();
    void Info_of_zhandian_find_ALL(QString Info_for_all);
    void Search();
    void on_pushButton_8_clicked();
    void Tool_1();
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();
    void Update_ALL(int index);
    void on_pushButton_5_clicked();
    void Tool_3();
    void on_actionAuthor_triggered();
    void on_pushButton_9_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_16_clicked();
};
#endif
