#include "ui_mainwindow.h"
#include "ui_AddLine.h"
#include "mainwindow.h"
#pragma execution_character_set("utf-8")
#include <QGraphicsItem>
#include <QMessageBox>
#include <QColorDialog>
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include<QtMultimedia/QAudioInput>
#include <QDesktopServices>
#include <QUrl>
#include<queue>
#define INF 999999999

const int MAX = 50;
int board[MAX][MAX];
int root[MAX][MAX];
int best[MAX][MAX];
int m, n;
int k = 0;
int bestk = 10000;
int t = 0;
int t1, t2, more;
int dx[] = { 0, 1, -1, 0, 0 };
int dy[] = { 0, 0, 0,  1, -1 };
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    display_graph = new Graphics_view_zoom(ui->graphicsView);
    display_graph->set_modifiers(Qt::NoModifier);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    display_graph_info=new QGraphicsScene;
    display_graph_info->setSceneRect(-0,0,2060,2060);
    ui->graphicsView->setScene(display_graph_info);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    if(1)
    {
        ui->pushButton_20->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->pushButton_3->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->pushButton_4->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->pushButton_5->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->pushButton_6->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->pushButton_7->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->pushButton_8->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->pushButton_9->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->pushButton_10->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->pushButton_11->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->pushButton_12->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->pushButton_13->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->pushButton_14->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->pushButton_2->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->pushButton->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
//        ui->pushButton_->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->textBrowser_2->setStyleSheet("border-image:url(:/icon/anniu/6.png)");
        ui->graphicsView->setStyleSheet("border-image:url(:/icon/anniu/3"
                                        ".png)");
        QStatusBar* bar = ui->statusBar;
        statusLabel1 = new QLabel;
        statusLabel2 = new QLabel;
        statusLabel3 = new QLabel;
        statusLabel4 = new QLabel;
        statusLabel5 = new QLabel;
        statusLabel1->setMinimumSize(250,10);
        statusLabel2->setMinimumSize(250,10);
        statusLabel3->setMinimumSize(250,10);
        statusLabel4->setMinimumSize(250,10);
        statusLabel5->setMinimumSize(250,10);
        statusLabel1->setFrameShape(QFrame::Box);
        statusLabel2->setFrameShape(QFrame::Box);
        statusLabel3->setFrameShape(QFrame::Box);
        statusLabel4->setFrameShape(QFrame::Box);
        statusLabel5->setFrameShape(QFrame::Box);
        statusLabel5->setFrameShadow(QFrame::Plain);
        statusLabel1->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        statusLabel2->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        statusLabel3->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        statusLabel4->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        statusLabel5->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->combox_1->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->combox_3->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->combox_2->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->comboBox_2->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->pushButton_16->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->menu_A->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->pushButton_15->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        ui->menuBar->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
        bar->addWidget(statusLabel1);
        bar->addWidget(statusLabel2);
        bar->addWidget(statusLabel3);
        bar->addWidget(statusLabel4);
        bar->addWidget(statusLabel5);
        statusLabel1->setText(tr("学号:1652262"));
        statusLabel2->setText(tr("0000年00月00日 00:00:00 星期"));
        statusLabel4->setText(tr("CopyRight@TYP"));
        statusLabel5->setText(tr("同济大学"));
        QPalette pe;
        pe.setColor(QPalette::WindowText,Qt::white);
        ui->label->setPalette(pe);
        ui->label_2->setPalette(pe);
        ui->label_3->setPalette(pe);
        ui->label_22->setPalette(pe);
        ui->label_23->setPalette(pe);
        ui->radioButton_30->setPalette(pe);
        ui->radioButton_29->setPalette(pe);
        statusLabel1->setPalette(pe);
        statusLabel2->setPalette(pe);
        statusLabel3->setPalette(pe);
        statusLabel4->setPalette(pe);
        statusLabel5->setPalette(pe);
        statusLabel3->setText(tr("上海地铁站点分布图"));
        ui->label_4->setPalette(pe);
        ui->label_5->setPalette(pe);
        ui->label_6->setPalette(pe);
    }
    addLine=new AddLine(this);
    ALL_Subwang_info=new Shanghai_sub;
    if(1)
    {
        QString fileName=":/data/data/data.txt";
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QTextStream in(&file);
        while(!in.atEnd())
        {
            xianlu_info_ALL line;
            QString Info_xianluandzhandian_code, name, colour, fromTo, totalStations;
            QString longlat,color, froms, tos;
            Info_of_zhandian station;
            int total,lvIndex, svIndex1, svIndex2;
            QStringList strList;bool ok;
            in>>Info_xianluandzhandian_code>>line.Info_xianluandzhandian_code>>name>>line.name>>colour>>color>>fromTo>>froms>>tos>>totalStations>>total;
            line.color.setRgba(color.remove(0,1).toUInt(&ok, 16));
            line.fromTo.push_back(froms);
            line.fromTo.push_back(tos);
            if (ALL_Subwang_info->Info_ALLxianlu.count(line.name))
            {
                lvIndex = ALL_Subwang_info->Info_ALLxianlu[line.name];
                ALL_Subwang_info->lines[lvIndex].fromTo.push_back(froms);
                ALL_Subwang_info->lines[lvIndex].fromTo.push_back(tos);
            }
            else
            {
                lvIndex = ALL_Subwang_info->Info_ALLxianlu[line.name] = ALL_Subwang_info->lines.size();
                ALL_Subwang_info->lines.push_back(line);
            }
            for (int i=0; !in.atEnd()&&i<total; ++i)
            {
                in>>station.Info_xianluandzhandian_code>>station.name>>longlat;
                strList=longlat.split(QChar(','));
                station.Info_of_zhandian_info_1=strList.first().toDouble();
                station.Info_of_zhandian_info_2=strList.last().toDouble();
                if (ALL_Subwang_info->Info_ALLzhandian.count(station.name))
                {
                    svIndex2 = ALL_Subwang_info->Info_ALLzhandian[station.name];
                }
                else
                {
                    svIndex2 = ALL_Subwang_info->Info_ALLzhandian[station.name] = ALL_Subwang_info->stations.size();
                    ALL_Subwang_info->stations.push_back(station);
                }
                ALL_Subwang_info->stations[svIndex2].xianlu_Qset_ALL.insert(lvIndex);
                ALL_Subwang_info->lines[lvIndex].zhandian_Qset_ALL.insert(svIndex2);
                if (i)
                {
                    ALL_Subwang_info->lines[lvIndex].xianlu_ALLInfo.insert(Edge(svIndex1, svIndex2));
                    ALL_Subwang_info->lines[lvIndex].xianlu_ALLInfo.insert(Edge(svIndex2, svIndex1));
                    if(1)
                    {
                        ALL_Subwang_info->xianlu_ALLInfo.insert(Edge(svIndex1, svIndex2));
                    }
                }
                svIndex1 = svIndex2;
            }
            bool flag = Info_xianluandzhandian_code=="Line:" && name=="Linenum:" && colour=="yanse:" && fromTo=="EndandStart:"&& totalStations=="ALL:" && ok && !in.atEnd();
            if(flag==false)
            {
                file.close();
                ALL_Subwang_info->stations.clear();
                ALL_Subwang_info->lines.clear();
                ALL_Subwang_info->Info_ALLzhandian.clear();
                ALL_Subwang_info->Info_ALLxianlu.clear();
                ALL_Subwang_info->xianlu_ALLInfo.clear();
                ALL_Subwang_info->Link_Subwang.clear();
            }
            in.readLine();
        }
        file.close();
        if(1)
        {
            double distance_info1=200, distance_info2=200,distance_info3=0, distance_info4=0;
            for (auto &s : ALL_Subwang_info->stations)
            {
                distance_info1=(distance_info1>s.Info_of_zhandian_info_1)?s.Info_of_zhandian_info_1:distance_info1;
                distance_info2=(distance_info2>s.Info_of_zhandian_info_2)?s.Info_of_zhandian_info_2:distance_info2;
                distance_info3=(distance_info3<s.Info_of_zhandian_info_1)?s.Info_of_zhandian_info_1:distance_info3;
                distance_info4=(distance_info4<s.Info_of_zhandian_info_2)?s.Info_of_zhandian_info_2:distance_info4;
            }
            Info_of_zhandian::distance_info1 = distance_info1;
            Info_of_zhandian::distance_info2 = distance_info2;
            Info_of_zhandian::distance_info3 = distance_info3;
            Info_of_zhandian::distance_info4 = distance_info4;
        }
    }
    if(1)
    {
        QPalette pe;
        pe.setColor(QPalette::WindowText,Qt::white);
        QTimer *timer = new QTimer(this);
        if(1)
        {
            ui->label_7->setPalette(pe);
            connect(addLine->ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(Update_ALL(int)));
        }
        if(1)
        {
            ui->label_8->setPalette(pe);
            connect(addLine->ui->pushButton_0, SIGNAL(clicked()), this, SLOT(Tool_1()));
        }
        if(1)
        {
            ui->label_10->setPalette(pe);
            connect(addLine->ui->pushButton_1, SIGNAL(clicked()), this, SLOT(Tool_2()));
        }
        if(1)
        {
            ui->label_11->setPalette(pe);
            connect(ui->combox_3, SIGNAL(currentIndexChanged(QString)),this, SLOT(Info_of_zhandian_find_ALL(QString)));
        }
        if(1)
        {
            ui->label_12->setPalette(pe);
            connect(addLine->ui->pushButton_11, SIGNAL(clicked()), this, SLOT(Tool_3()));
        }
        if(1)
        {
            connect(addLine->ui->pushButton_12, SIGNAL(clicked()), this, SLOT(Tool_4()));
        }
        if(1)
        {
            connect(timer,SIGNAL(timeout()),this,SLOT(Info_change()));
        }
        if(1)
        {
            connect(ui->combox_1, SIGNAL(currentIndexChanged(QString)),this, SLOT(Info_of_zhandian_find(QString)));
        }
        if(1)
        {
            connect(ui->pushButton_20, SIGNAL(clicked()), this, SLOT(Search()));
        }
        timer->start(1000);
    }
    if(1)
    {
        QComboBox* comboL1=ui->combox_1;
        QComboBox* comboL2=ui->combox_3;
        QList<QString> linesList;
        comboL1->clear();
        comboL2->clear();
        if(1)
        {
            QList<QString> Info_for_all_temp;
            for (auto a:ALL_Subwang_info->lines)
            {
                Info_for_all_temp.push_back(a.name);
            }
            linesList=Info_for_all_temp;
        }
        for(auto &a:linesList)
        {
            comboL1->addItem(a);comboL2->addItem(a);
        }
        Info_of_zhandian_find(comboL1->itemText(0));
        Info_of_zhandian_find_ALL(comboL2->itemText(0));
    }
    if(1)
    {
        display_graph_info->clear();
        QList<int> zhandian_display;
        QList<Edge> xianlu_display;
        if(1)
        {
            zhandian_display.clear();
            for (int i=0; i<ALL_Subwang_info->stations.size(); ++i)
            {
                zhandian_display.push_back(i);
            }
            xianlu_display=ALL_Subwang_info->xianlu_ALLInfo.toList();
        }
        Painting_1(xianlu_display);
        Painting_2(zhandian_display);
    }
    if(1)
    {
        QPixmap pixmap;
        QGraphicsItem *item;
        pixmap.load(":/icon/color.png");
        QGraphicsScene *display_graph_info = new QGraphicsScene;
        QGraphicsView *view = new QGraphicsView(display_graph_info);
        view->setDragMode(QGraphicsView::ScrollHandDrag);
        view->setRenderHint(QPainter::Antialiasing);
        view->resize(550,150);
        view->setWindowTitle(tr("地铁线路颜色对照"));
        view->setScene(display_graph_info);
        view->setWindowIcon(QIcon(":/icon/anniu/1.png"));
        item=display_graph_info->addPixmap(pixmap);
        item->setScale(1);
        view->show();
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Info_change()//top_module_control(1,0,"",const QList<Edge> xianlu_display_more,const QList<int> zhandian_display_more)
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy年MM月dd日 hh:mm:ss dddd");
    statusLabel2->setText(str);
}
void MainWindow::Painting_1(const QList<Edge>& xianlu_display)//top_module_control(2,0,"",const QList<Edge> xianlu_display,const QList<int> zhandian_display_more)
{
    for(int i=0; i<xianlu_display.size(); ++i)
    {
        int s1=xianlu_display[i].first;
        int s2=xianlu_display[i].second;
        QList<int> linesList;
        QColor color;
        if(1)
        {
            for (auto &s : ALL_Subwang_info->stations[s1].xianlu_Qset_ALL)
            {
                if(ALL_Subwang_info->stations[s2].xianlu_Qset_ALL.contains(s))
                    linesList.push_back(s);
            }
        }
        if(1)
        {
            QColor color1=QColor(255,255,255);
            QColor color2;
            for (int i=0; i<linesList.size(); ++i)
            {
                color2=ALL_Subwang_info->lines[linesList[i]].color;
                color1.setRed(color1.red()*color2.red()/255);
                color1.setGreen(color1.green()*color2.green()/255);
                color1.setBlue(color1.blue()*color2.blue()/255);
            }
            color=color1;
        }
        QString tip=ALL_Subwang_info->stations[s1].name+"--"+ALL_Subwang_info->stations[s2].name+"\n线路:";
        if(1)
        {
            QString str;
            str+="\t";
            for (int i=0; i<linesList.size(); ++i)
            {
                str+=" ";
                str+=ALL_Subwang_info->lines[linesList[i]].name;
            }
            tip+=str;
        }
        QPointF s1Pos;
        if(1)
        {
            QPointF s_temp(ALL_Subwang_info->stations[s1].Info_of_zhandian_info_1, ALL_Subwang_info->stations[s1].Info_of_zhandian_info_2);
            QPointF minCoord=QPointF(Info_of_zhandian::distance_info1, Info_of_zhandian::distance_info2);
            QPointF maxCoord=QPointF(Info_of_zhandian::distance_info3, Info_of_zhandian::distance_info4);
            double x = (s_temp.x()-minCoord.x())/(maxCoord.x()-minCoord.x())*2000+30;
            double y = (maxCoord.y()-s_temp.y())/(maxCoord.y()-minCoord.y())*2000+30;
            s1Pos=QPointF(x,y);
        }
        QPointF s2Pos;
        if(1)
        {
            QPointF s_temp2(ALL_Subwang_info->stations[s2].Info_of_zhandian_info_1, ALL_Subwang_info->stations[s2].Info_of_zhandian_info_2);
            QPointF minCoord=QPointF(Info_of_zhandian::distance_info1, Info_of_zhandian::distance_info2);
            QPointF maxCoord=QPointF(Info_of_zhandian::distance_info3, Info_of_zhandian::distance_info4);
            double x = (s_temp2.x()-minCoord.x())/(maxCoord.x()-minCoord.x())*2000+30;
            double y = (maxCoord.y()-s_temp2.y())/(maxCoord.y()-minCoord.y())*2000+30;
            s2Pos=QPointF(x,y);
        }
        QGraphicsLineItem* edgeItem=new QGraphicsLineItem;
        edgeItem->setPen(QPen(color, 5));
        edgeItem->setCursor(Qt::PointingHandCursor);
        edgeItem->setToolTip(tip);
        edgeItem->setPos(s1Pos);
        edgeItem->setLine(0, 0, s2Pos.x()-s1Pos.x(), s2Pos.y()-s1Pos.y());
        display_graph_info->addItem(edgeItem);
    }
}
void MainWindow::Painting_2 (const QList<int>& zhandian_display)//top_module_control(3,0,"",const QList<Edge> xianlu_display,const QList<int> zhandian_display)
{
    for (int i=0; i<zhandian_display.size(); ++i)
    {
        int s=zhandian_display[i];
        QString name=ALL_Subwang_info->stations[s].name;
        QList<int> linesList=ALL_Subwang_info->stations[s].xianlu_Qset_ALL.toList();
        QColor color;
        if(1)
        {
            QColor color1=QColor(255,255,255);
            QColor color2;
            for (int i=0; i<linesList.size(); ++i)
            {
                color2=ALL_Subwang_info->lines[linesList[i]].color;
                color1.setRed(color1.red()*color2.red()/255);
                color1.setGreen(color1.green()*color2.green()/255);
                color1.setBlue(color1.blue()*color2.blue()/255);
            }
            color=color1;
        }
        QPointF s_temp3(ALL_Subwang_info->stations[s].Info_of_zhandian_info_1, ALL_Subwang_info->stations[s].Info_of_zhandian_info_2);
        QPointF longiLati=s_temp3;
        QPointF coord;
        if(1)
        {
            QPointF minCoord=QPointF(Info_of_zhandian::distance_info1, Info_of_zhandian::distance_info2);
            QPointF maxCoord=QPointF(Info_of_zhandian::distance_info3, Info_of_zhandian::distance_info4);
            double x = (longiLati.x()-minCoord.x())/(maxCoord.x()-minCoord.x())*2000+30;
            double y = (maxCoord.y()-longiLati.y())/(maxCoord.y()-minCoord.y())*2000+30;
            coord=QPointF(x,y);
        }
        QString tip="站名:  "+name+"\n"+
                "线路:";
        if(1)
        {
            QString str;
            str+="\t";
            for (int i=0; i<linesList.size(); ++i)
            {
                str+=" ";
                str+=ALL_Subwang_info->lines[linesList[i]].name;
            }
            tip+=str;
        }
        QGraphicsEllipseItem* stationItem=new QGraphicsEllipseItem;
        QGraphicsEllipseItem* stationItem2=new QGraphicsEllipseItem;
        QGraphicsTextItem* textItem=new QGraphicsTextItem;
        stationItem->setRect(-3, -3, 6, 6);
        stationItem->setPos(coord);
        stationItem->setPen(color);
        stationItem->setCursor(Qt::PointingHandCursor);
        stationItem->setToolTip(tip);
        stationItem2->setRect(-6, -6, 12, 12);
        stationItem2->setPos(coord);
        stationItem2->setPen(color);
        stationItem2->setCursor(Qt::PointingHandCursor);
        stationItem2->setToolTip(tip);
        textItem->setPlainText(name);
        textItem->setFont(QFont("楷体",4,1));
        textItem->setPos(coord.x(),coord.y()-6);
        if(linesList.size()<=1)
        {
            stationItem->setBrush(QColor(QRgb(0xffffff)));
        }
        display_graph_info->addItem(stationItem);
        display_graph_info->addItem(stationItem2);
        display_graph_info->addItem(textItem);
    }
}
void MainWindow::Request_temp()//top_module_control(4,0,"",const QList<Edge> xianlu_display_more,const QList<int> zhandian_display_more)
{
    statusLabel3->setText(tr("线路已更新@_@"));
    QComboBox* comboL1=ui->combox_1;
    QComboBox* comboL2=ui->combox_3;
    comboL1->clear();
    comboL2->clear();
    QList<QString> linesList;
    if(1)
    {
        QList<QString> Info_for_all_temp;
        for (auto a:ALL_Subwang_info->lines)
        {
            Info_for_all_temp.push_back(a.name);

        }
        linesList=Info_for_all_temp;
    }
    for(auto &a:linesList)
    {
        comboL1->addItem(a);
        comboL2->addItem(a);
    }
    Info_of_zhandian_find(comboL1->itemText(0));
    Info_of_zhandian_find_ALL(comboL2->itemText(0));
}
void MainWindow::Info_of_zhandian_find(QString Info_for_all)//top_module_control(5,0,Info_for_all[0],const QList<Edge> xianlu_display_more,const QList<int> zhandian_display_more)
{
    QComboBox* comboS1=ui->combox_2;
    comboS1->clear();

    int lineHash1;
    if(ALL_Subwang_info->Info_ALLxianlu.contains(Info_for_all))
    {
        lineHash1=ALL_Subwang_info->Info_ALLxianlu[Info_for_all];
    }
    else lineHash1=-1;
    if(lineHash1==-1){return;}
    QList<QString> zhandian_display;
    if(1)
    {
        QList<QString> stationsList1;
        for (auto &a:ALL_Subwang_info->lines[lineHash1].zhandian_Qset_ALL)
        {
            stationsList1.push_back(ALL_Subwang_info->stations[a].name);
        }
        zhandian_display=stationsList1;
    }
    for(auto &a:zhandian_display)
    {
        comboS1->addItem(a);
    }
}
void MainWindow::Info_of_zhandian_find_ALL(QString Info_for_all)//top_module_control(6,0,Info_for_all[0],const QList<Edge> xianlu_display_more,const QList<int> zhandian_display_more)
{
    QComboBox* comboS2=ui->comboBox_2;
    QList<QString> zhandian_display;
    comboS2->clear();
    int lineHash1;
    if(ALL_Subwang_info->Info_ALLxianlu.contains(Info_for_all))
    {
        lineHash1=ALL_Subwang_info->Info_ALLxianlu[Info_for_all];
    }else lineHash1=-1;
    if(lineHash1==-1){return;}
    if(1)
    {
        QList<QString> stationsList1;
        for (auto &a:ALL_Subwang_info->lines[lineHash1].zhandian_Qset_ALL){stationsList1.push_back(ALL_Subwang_info->stations[a].name);}
        zhandian_display=stationsList1;
    }
    for(auto &a:zhandian_display){comboS2->addItem(a);}
}
void MainWindow::Search()//top_module_control(7,0,"",const QList<Edge> xianlu_display_more,const QList<int> zhandian_display_more)
{
    int s1,s2,way;
    if(ui->radioButton_30->isChecked())
    {way=1;}else way=2;
    if(1)
    {
        if(ALL_Subwang_info->Info_ALLzhandian.contains(ui->combox_2->currentText()))
        {
            s1=ALL_Subwang_info->Info_ALLzhandian[ui->combox_2->currentText()];
        }
        else s1=-1;
        if(ALL_Subwang_info->Info_ALLzhandian.contains(ui->comboBox_2->currentText()))
        {
            s2=ALL_Subwang_info->Info_ALLzhandian[ui->comboBox_2->currentText()];
        }
        else s2=-1;
    }
    if(s1==-1||s2==-1)
    {
        QMessageBox box;
        box.setWindowTitle(tr("提示"));
        box.setWindowIcon(QIcon(":/icon/timg4.png"));
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("此线路无对应站点"));
        box.addButton(tr("确定"),QMessageBox::AcceptRole);
        if(box.exec()==QMessageBox::Accepted)
        {
            box.close();
        }
    }
    else
    {
        QList<int> zhandian_display;
        QList<Edge> xianlu_display;
        bool flag=true;
        if(way==1)
        {
            int length;
            int money;
            flag=ALL_Subwang_info->SearchTime(length,s1, s2, zhandian_display, xianlu_display,1);
            if(length<=6000)
                money=3;
            else
            {
                money=3+(length-6000)/10000;
            }
            if(s1==s2)
            {
               money=0;
               length=0;
            }
            QString str1="最短线路长度为"+QString::number(length)+"米,"+"票价为"+QString::number(money)+"元";
            ui->label_2->setText((str1));
        }
        else if(way==3)
        {
            int length;
            int money;
            flag=ALL_Subwang_info->SearchTime(length,s1, s2, zhandian_display, xianlu_display,2);
            if(length<=6000)
                money=3;
            else
            {
                money=3+(length-6000)/10000;
            }
            if(s1==s2)
            {
               money=0;
               length=0;
            }
            QString str1="最短线路长度为"+QString::number(length)+"米,"+"票价为"+QString::number(money)+"元";
            ui->label_2->setText((str1));
        }
        else
        {
            if(1)
            {
                std::vector<bool> linesVisted(ALL_Subwang_info->lines.size(),false);
                std::vector<int> path(ALL_Subwang_info->stations.size(),-1);
                std::queue<int> que;
                zhandian_display.clear();
                xianlu_display.clear();
                if(s1==s2)
                {
                    zhandian_display.push_back(s2);
                    zhandian_display.push_back(s1);
                    flag=true;
                }
                path[s1]=-2;
                que.push(s1);
                while(!que.empty())
                {
                    int top=que.front();
                    que.pop();
                    for (auto &l: ALL_Subwang_info->stations[top].xianlu_Qset_ALL)
                    {
                        if(!linesVisted[l])
                        {
                            linesVisted[l]=true;
                            for (auto &s: ALL_Subwang_info->lines[l].zhandian_Qset_ALL)
                            {
                                if(path[s]==-1)
                                {
                                    path[s]=top;
                                    que.push(s);
                                }
                            }
                        }
                    }
                }
                if(path[s2]==-1)
                {
                    flag=false;
                }
                int p=s2;
                while(path[p]!=-2)
                {
                    zhandian_display.push_front(p);
                    xianlu_display.push_front(Edge(path[p],p));
                    p=path[p];
                }
                zhandian_display.push_front(s1);
                flag=true;

            }
            int length;
            int money;
            QList<int> stationsList1;
            QList<Edge> edgesList1;
            ALL_Subwang_info->SearchTime(length,s1, s2, stationsList1, edgesList1,1);
            if(length<=6000)
                money=3;
            else
            {
                money=3+(length-6000)/10000;
            }
            if(s1==s2)
            {
                money=0;
                length=0;
            }
            QString str1="最短线路长度为"+QString::number(length)+"米,"+"票价为"+QString::number(money)+"元";
            ui->label_2->setText((str1));
        }


        if(flag)
        {
            statusLabel3->setText(tr("查询成功"));
            display_graph_info->clear();
            Painting_1(xianlu_display);Painting_2(zhandian_display);
            QString text=(way==1)?("本条路线经过最少时间到达目的地,一共:"+QString::number(zhandian_display.size()-1)+"个站点\n\n"):("本条路线经过换乘到达目的地,一共换乘:"+QString::number(zhandian_display.size()-1)+"条线路\n\n");
            for(int i=0; i<zhandian_display.size(); ++i)
            {
                if(i){text+="->";}text+=ALL_Subwang_info->stations[zhandian_display[i]].name;
            }
            QTextBrowser* browser=ui->textBrowser_2;
            browser->clear();browser->setText(text);
        }
        else
        {
            QMessageBox box;
            box.setWindowTitle(tr("换乘查询"));
            box.setWindowIcon(QIcon(":/icon/timg4.png"));
            box.setIcon(QMessageBox::Warning);
            box.setText(tr("起始和终止站点无路径到达-_-"));
            box.addButton(tr("确定"),QMessageBox::AcceptRole);
            if(box.exec()==QMessageBox::Accepted)
            {
                box.close();
            }
        }
    }
}


//test测试用函数
struct Graph
{
    int arrAcc[100][100];
    int verCount;
    int arcCount;
};
void floyd(Graph *p, int dis[100][100])
{
    for(int k = 1; k < p->verCount; ++k)
        for(int i = 1; i <= p->verCount; ++i)
            for(int j = 1; j <= p->verCount; ++j)
            {
                if(dis[i][j] > dis[i][k] + dis[k][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
}
int transform(QString c)
{
    int i;
    QString s[38] = {"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10","A11","A12","A13","A14","A15","A16","A17","A18","B1","B2","B3","B4","B5","B6","B7","B8","B9","B10","B11","B12","B13","B14","B15","T1","T2"};
    for(i = 1; i <= 38; i++)
        if(s[i - 1] == c)
            return i;
    return -1;


}
void change_train()
{
    Graph g;
    QString start;
    QString end;
    g.arcCount = 35;
    g.verCount = 37;
    for(int i = 1; i <= g.verCount; i++)
        for(int j = 1; j <= g.verCount; j++)
        {
            if(i == j)
                g.arrAcc[i][j] = 0;
            else
                g.arrAcc[i][j] = 1000;
        }

        int a[21] = {1,2,3,4,5,6,7,8,9,34,10,11,12,13,35,14,15,16,17,18,1};
        for(int i = 0; i < 20; i++)
        {
            g.arrAcc[a[i]][a[i+1]] = 1;
            g.arrAcc[a[i+1]][a[i]] = 1;
        }
        int b[17] = {19,20,21,22,23,34,24,25,26,27,28,35,29,30,31,32,33};
        for(int i = 0; i < 16; i++)
        {
            g.arrAcc[b[i]][b[i+1]] = 1;
            g.arrAcc[b[i+1]][b[i]] = 1;
        }
        floyd(&g,g.arrAcc);


}

void MainWindow::Update_ALL(int index)//top_module_control(8,index,"",const QList<Edge> xianlu_display_more,const QList<int> zhandian_display_more)
{
    QWidget* widget=addLine->ui->tabWidget->currentWidget();
    if(widget==addLine->More_addTab[1])
    {
        if(1)
        {
            QList<QString> Info_for_all_temp;
            for (auto a:ALL_Subwang_info->lines)
            {
                Info_for_all_temp.push_back(a.name);

            }
            addLine->Info_for_all_temp=Info_for_all_temp;
        }
        if(1)
        {
            QListWidget* listWidget=addLine->ui->listWidget;
            for(int i=0; i<addLine->Info_for_all_temp.size(); ++i)
            {
                QListWidgetItem *item =listWidget->takeItem(i);
                delete item;
            }
            listWidget->clear();
            addLine->Info_for_all_2.clear();

            for(int i=0; i<addLine->Info_for_all_temp.size(); ++i)
            {
                QListWidgetItem *item=new QListWidgetItem(addLine->Info_for_all_temp[i]);
                item->setFlags(item->flags()|Qt::ItemIsUserCheckable);
                item->setCheckState(Qt::Unchecked);
                listWidget->addItem(item);
            }
        }
    }
    else if(widget==addLine->More_addTab[2])
    {
        addLine->Info_for_all_temp;
        if(1)
        {
            QList<QString> Info_for_all_temp;
            for (auto a:ALL_Subwang_info->lines)
            {
                Info_for_all_temp.push_back(a.name);

            }
            addLine->Info_for_all_temp=Info_for_all_temp;
        }
        if(1)
        {
            QList<QString> list;
            for (auto &a: ALL_Subwang_info->stations)
            {
                list.push_back(a.name);
            }
            addLine->Info_for_all_final=list;
        }
        addLine->ui->comboBoxConnectStation1->setMaxCount(addLine->Info_for_all_final.size());
        addLine->ui->comboBoxConnectStation2->setMaxCount(addLine->Info_for_all_final.size());
        addLine->ui->comboBoxConnectLine->setMaxCount(addLine->Info_for_all_temp.size());
        if(1)
        {
            addLine->ui->comboBoxConnectStation1->clear();
            addLine->ui->comboBoxConnectStation2->clear();
            addLine->ui->comboBoxConnectLine->clear();

            for (auto &a: addLine->Info_for_all_final)
            {
                addLine->ui->comboBoxConnectStation1->addItem(a);
                addLine->ui->comboBoxConnectStation2->addItem(a);
            }
            for (auto &a:addLine->Info_for_all_temp)
            {
                addLine->ui->comboBoxConnectLine->addItem(a);
            }
        }
    }
    Q_UNUSED(index);
}
void MainWindow::Tool_1()//top_module_control(9,0,"",const QList<Edge> xianlu_display_more,const QList<int> zhandian_display_more)
{
    QMessageBox box;
    box.setWindowTitle(tr("添加线路"));
    box.setWindowIcon(QIcon(":/icon/aaabbb1.png"));
    int hash_temp;
    if(1)
    {
        if(ALL_Subwang_info->Info_ALLxianlu.contains(addLine->Info_for_all[0]))
        {
            hash_temp=ALL_Subwang_info->Info_ALLxianlu[addLine->Info_for_all[0]];
        }
        hash_temp=-1;
    }
    if(addLine->Info_for_all[0].isEmpty())
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请输入线路名称"));
    }
    else if(hash_temp==-1)
    {
        box.setIcon(QMessageBox::Information);
        box.setText(tr("线路:")+addLine->Info_for_all[0]+tr("添加successful\-_-/!"));
        ALL_Subwang_info->Info_ALLxianlu[addLine->Info_for_all[0]]=ALL_Subwang_info->lines.size();
        ALL_Subwang_info->lines.push_back(xianlu_info_ALL(addLine->Info_for_all[0],addLine->Yanse_xianlu_info));
        Request_temp();
    }
    else
    {
        box.setIcon(QMessageBox::Critical);
        box.setText(tr("添加failed-_-!线路已有"));
    }
    box.addButton(tr("确定"),QMessageBox::AcceptRole);
    if(box.exec()==QMessageBox::Accepted)
    {
        box.close();
    }
    Request_temp();
}
void MainWindow::Tool_2()//top_module_control(10,0,"",const QList<Edge> xianlu_display_more,const QList<int> zhandian_display_more)
{
    QMessageBox box;
    box.setWindowTitle(tr("添加站点"));

    if(addLine->Info_for_all[1].isEmpty())
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请输入站点名称!"));
    }
    else if(addLine->Info_for_all_2.isEmpty())
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请选择站点所属线路!"));
    }
    else
    {
        int s_temp;
        if(1)
        {
            if(ALL_Subwang_info->Info_ALLzhandian.contains(addLine->Info_for_all[1]))
            {
                s_temp=ALL_Subwang_info->Info_ALLzhandian[addLine->Info_for_all[1]];
            }
            else s_temp=-1;
        }

        if(s_temp!=-1)
        {
            box.setIcon(QMessageBox::Critical);
            box.setText(tr("添加失败!站点已存在"));
        }
        else
        {
            QList<int> hashList111;
            if(1)
            {
                for (auto &a:addLine->Info_for_all_2)
                {
                    int hash_temp;
                    if(1)
                    {
                        if(ALL_Subwang_info->Info_ALLxianlu.contains(a))
                        {
                            hash_temp=ALL_Subwang_info->Info_ALLxianlu[a];
                        }
                        else hash_temp=-1;
                    }
                    hashList111.push_back(hash_temp);
                }
            }
            Info_of_zhandian s(addLine->Info_for_all[1], addLine->Info_of_zhandian_info_1, addLine->Info_of_zhandian_info_2,hashList111);
            if(1)
            {
                int hash=ALL_Subwang_info->stations.size();
                ALL_Subwang_info->Info_ALLzhandian[s.name]=hash;
                ALL_Subwang_info->stations.push_back(s);
                for (auto &a: s.xianlu_Qset_ALL)
                {
                    ALL_Subwang_info->lines[a].zhandian_Qset_ALL.insert(hash);
                }
                if(1)
                {
                    double distance_info1=200, distance_info2=200;
                    double distance_info3=0, distance_info4=0;

                    for (auto &s : ALL_Subwang_info->stations)
                    {
                        distance_info1 =(distance_info1>s.Info_of_zhandian_info_1)?s.Info_of_zhandian_info_1:distance_info1;
                        distance_info2 = (distance_info2>s.Info_of_zhandian_info_2)?s.Info_of_zhandian_info_2:distance_info2;
                        distance_info3 = (distance_info3>s.Info_of_zhandian_info_1)?distance_info3:s.Info_of_zhandian_info_1;
                        distance_info4 = (distance_info4>s.Info_of_zhandian_info_2)?distance_info4:s.Info_of_zhandian_info_2;
                    }
                    Info_of_zhandian::distance_info1 = distance_info1;
                    Info_of_zhandian::distance_info2 = distance_info2;
                    Info_of_zhandian::distance_info3 = distance_info3;
                    Info_of_zhandian::distance_info4 = distance_info4;
                }
            }
            box.setText(tr("站点:")+addLine->Info_for_all[1]+tr(" 添加成功!"));
            Request_temp();
        }
    }

    box.addButton(tr("确定"),QMessageBox::AcceptRole);
    if(box.exec()==QMessageBox::Accepted)
    {
        box.close();
    }
    Request_temp();
    on_pushButton_15_clicked();
}
int turn_valueSTR(QCharRef a)
{
   if(a=='0')return 0;
   else if(a=='1')return 1;
   else if(a=='2')return 2;
   else if(a=='3')return 3;
   else if(a=='4')return 4;
   else if(a=='5')return 5;
   else if(a=='6')return 6;
   else if(a=='7')return 7;
   else if(a=='8')return 8;
   else if(a=='9')return 9;
   else return false;
}
int graph_nodirection_nopower_judge(int graph_style,int **&link_matrix,QString valueSTR,int &length_link)
{
    if(graph_style==1)//无权无向图输入正确性判断
    {
        int linenum=0;
        int queue=0;
        for(int i=0;i<valueSTR.length();i++)
        {
           if(valueSTR[i]=='0'||valueSTR[i]=='1')
           {
               linenum++;//计算输入数字个数判断是否为完全平方数
               if(i+1<valueSTR.length())
               {
                   if(valueSTR[i+1]==' '||valueSTR[i+1]=='\n')
                       ;
                   else
                      return false;

               }
           }
           else if(valueSTR[i]==' '||valueSTR[i]=='\n')
               ;
           else
               return false;
        }
        if(linenum!=int(sqrt(linenum))*int(sqrt(linenum)))
            return false;
        link_matrix=new int*[int(sqrt(linenum))];
        for(int i=0;i<int(sqrt(linenum));i++)
            link_matrix[i]=new int[int(sqrt(linenum))];

        for(int i=0;i<valueSTR.length();i++)
        {
           if(valueSTR[i]=='0'||valueSTR[i]=='1')
           {

               link_matrix[int(queue/int(sqrt(linenum)))][queue%int(sqrt(linenum))]=turn_valueSTR(valueSTR[i]);
               queue++;
           }
        }
        for(int i=0;i<int(sqrt(linenum));i++)
            for(int j=0;j<int(sqrt(linenum));j++)
                if(link_matrix[i][j]!=link_matrix[j][i]||link_matrix[i][i]==1)
                {
                    for(int i=0;i<int(sqrt(linenum));i++)
                        delete link_matrix[i];
                    delete link_matrix;
                    return false;
                }
        length_link=int(sqrt(linenum));
        return true;
    }
    else if(graph_style==2)//无权有向图输入正确性判断
    {

        int linenum=0;
        for(int i=0;i<valueSTR.length();i++)
        {
           if(valueSTR[i]=='0')
           {
               linenum++;//计算输入数字个数判断是否为完全平方数

           }
           else if(valueSTR[i]=='1')
           {
               linenum++;
           }
           else if(valueSTR[i]==' '||valueSTR[i]=='\n')
               ;
           else return false;
        }
        if(linenum!=int(sqrt(linenum))*int(sqrt(linenum)))
            return false;

        link_matrix=new int*[int(sqrt(linenum))];
        for(int i=0;i<int(sqrt(linenum));i++)
            link_matrix[i]=new int[int(sqrt(linenum))];


        int link_place=0;
        for(int i=0;i<valueSTR.length();i++)
        {
          if(valueSTR[i]=='0'||valueSTR[i]=='1')
          {
              link_matrix[link_place/int(sqrt(linenum))][link_place%int(sqrt(linenum))]=turn_valueSTR(valueSTR[i]);
              link_place++;
          }
//          if(valueSTR[i]>='0'&&valueSTR[i]<='9')
//          {
//            int j;
//            int count;
//            int num=0;
//            for(j=i;j<valueSTR.length()&&(valueSTR[j]>='0'&&valueSTR[j]<='9');j++);

//            for(count=j-1;count>=i;count--)
//            {
//                int data=turn_valueSTR(valueSTR[count]);
//                num= num+data*pow(10,count-j+1);
//            }
//            i=j;
//            link_matrix[link_place/int(sqrt(linenum))][link_place%int(sqrt(linenum))]=num;
//            link_place++;
//          }
        }
        for(int i=0;i<int(sqrt(linenum));i++)
            if(link_matrix[i][i]==1)
                return false;
        length_link=int(sqrt(linenum));

        return true;
    }
    else if(graph_style==3)//有权无向图输入正确性判断
    {
        int linenum=0;
        for(int i=0;i<valueSTR.length();i++)
        {
           if(valueSTR[i]=='0')
           {
               linenum++;//计算输入数字个数判断是否为完全平方数

           }
           else if(valueSTR[i]>='1'&&valueSTR[i]<='9')
           {
               int j;
               for(j=i;j<valueSTR.length()&&(valueSTR[j]>='1'&&valueSTR[j]<='9');j++);
               linenum++;
               i=j;
           }
           else if(valueSTR[i]==' '||valueSTR[i]=='\n')
               ;
           else return false;
        }
        if(linenum!=int(sqrt(linenum))*int(sqrt(linenum)))
            return false;

        link_matrix=new int*[int(sqrt(linenum))];
        for(int i=0;i<int(sqrt(linenum));i++)
            link_matrix[i]=new int[int(sqrt(linenum))];


        int link_place=0;
        for(int i=0;i<valueSTR.length();i++)
        {
          if(valueSTR[i]>='0'&&valueSTR[i]<='9')
          {
            int j;
            int count;
            int num=0;
            for(j=i;j<valueSTR.length()&&(valueSTR[j]>='0'&&valueSTR[j]<='9');j++);

            for(count=j-1;count>=i;count--)
            {
                int data=turn_valueSTR(valueSTR[count]);
                num= num+data*pow(10,count-j+1);
            }
            i=j;
            link_matrix[link_place/int(sqrt(linenum))][link_place%int(sqrt(linenum))]=num;
            link_place++;
          }
        }
        for(int i=0;i<int(sqrt(linenum));i++)
            for(int j=0;j<int(sqrt(linenum));j++)
                if(link_matrix[i][j]!=link_matrix[j][i]||link_matrix[i][i]>0)
                {
                    for(int i=0;i<int(sqrt(linenum));i++)
                        delete link_matrix[i];
                    delete link_matrix;
                    return false;
                }
        length_link=int(sqrt(linenum));
        return true;
    }
    else if(graph_style==4)//有权有向图输入正确性性判断
    {
        int linenum=0;
        for(int i=0;i<valueSTR.length();i++)
        {
           if(valueSTR[i]=='0')
           {
               linenum++;//计算输入数字个数判断是否为完全平方数

           }
           else if(valueSTR[i]>='1'&&valueSTR[i]<='9')
           {
               int j;
               for(j=i;j<valueSTR.length()&&(valueSTR[j]>='1'&&valueSTR[j]<='9');j++);
               linenum++;
               i=j;
           }
           else if(valueSTR[i]==' '||valueSTR[i]=='\n')
               ;
           else return false;
        }
        if(linenum!=int(sqrt(linenum))*int(sqrt(linenum)))
            return false;

        link_matrix=new int*[int(sqrt(linenum))];
        for(int i=0;i<int(sqrt(linenum));i++)
            link_matrix[i]=new int[int(sqrt(linenum))];


        int link_place=0;
        for(int i=0;i<valueSTR.length();i++)
        {
          if(valueSTR[i]>='0'&&valueSTR[i]<='9')
          {
            int j;
            int count;
            int num=0;
            for(j=i;j<valueSTR.length()&&(valueSTR[j]>='0'&&valueSTR[j]<='9');j++);

            for(count=j-1;count>=i;count--)
            {
                int data=turn_valueSTR(valueSTR[count]);
                num= num+data*pow(10,count-j+1);
            }
            i=j;
            link_matrix[link_place/int(sqrt(linenum))][link_place%int(sqrt(linenum))]=num;
            link_place++;
          }
        }
        for(int i=0;i<int(sqrt(linenum));i++)
            if(link_matrix[i][i]>0)
                return false;
        length_link=int(sqrt(linenum));
        return true;
    }
    return true;
}
void MainWindow::Tool_3()//top_module_control(11,0,"",const QList<Edge> xianlu_display_more,const QList<int> zhandian_display_more)
{
    QString station1=addLine->ui->comboBoxConnectStation1->currentText();
    QString station2=addLine->ui->comboBoxConnectStation2->currentText();
    int s1,s2;
    if(1)
    {
        if(ALL_Subwang_info->Info_ALLzhandian.contains(station1))
        {
            s1=ALL_Subwang_info->Info_ALLzhandian[station1];
        }
        else s1=-1;

        if(ALL_Subwang_info->Info_ALLzhandian.contains(station2))
        {
            s2=ALL_Subwang_info->Info_ALLzhandian[station2];
        }
        else s2=-1;
    }

    int l;
    if(1)
    {
        if(ALL_Subwang_info->Info_ALLxianlu.contains(addLine->ui->comboBoxConnectLine->currentText()))
        {
            l=ALL_Subwang_info->Info_ALLxianlu[addLine->ui->comboBoxConnectLine->currentText()];
        }
        else l=-1;
    }
    QMessageBox box;
    box.setWindowTitle(tr("添加连接"));
    if(s1==-1||s2==-1||l==-1)
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("请选择已有的站点和线路!"));
    }
    else if(s1==s2)
    {
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("同一站点不需要连接!"));
    }
    else if(!ALL_Subwang_info->stations[s1].xianlu_Qset_ALL.toList().contains(l))
    {
        box.setIcon(QMessageBox::Critical);
        box.setText(tr("连接失败,线路不包含站点1"));
    }
    else if(!ALL_Subwang_info->stations[s2].xianlu_Qset_ALL.toList().contains(l))
    {
        box.setIcon(QMessageBox::Critical);
        box.setText(tr("连接失败,线路不包含站点2"));
    }
    else
    {
        box.setIcon(QMessageBox::Information);
        box.setText(tr("成功连接@—@"));
        if(1)
        {
            if (ALL_Subwang_info->xianlu_ALLInfo.contains(Edge(s1, s2)) || ALL_Subwang_info->xianlu_ALLInfo.contains(Edge(s2, s1)));
            ALL_Subwang_info->xianlu_ALLInfo.insert(Edge(s1, s2));
        }
        ALL_Subwang_info->lines[l].xianlu_ALLInfo.insert(Edge(s1,s2));
        ALL_Subwang_info->lines[l].xianlu_ALLInfo.insert(Edge(s2,s1));
    }
    if(box.exec()==QMessageBox::Accepted)
    {
        box.close();
    }
    Request_temp();
    on_pushButton_15_clicked();
}

void change(int i, int j)
{
    root[i][j] = 1;
    k++;
    for (int d = 0; d <= 4; d++)
    {
        int p = i + dx[d];
        int q = j + dy[d];
        board[p][q]++;
        if (board[p][q] == 1)
            t++;
    }
}

void restore(int i, int j)
{
    root[i][j] = 0;
    k--;
    for (int d = 0; d <= 4; d++)
    {
        int p = i + dx[d];
        int q = j + dy[d];
        board[p][q]--;
        if (board[p][q] == 0)
            t++;
    }
}

void backtrack(int i, int j)
{
    do  //找到未被监视的方格
    {
        j++;
        if (j > n)
        {
            i++;
            j = 1;
        }
    } while (board[i][j] != 0 && i <= n);

    if (i>n)  //到达叶结点，复制最优解
    {
        if (k < bestk)
        {
            bestk = k;
            for (int i = 1; i <= m; i++)
                for (int j = 1; j <= n; j++)
                    best[i][j] = root[i][j];
        }
    }
    if (k + (t1 - t) / 5 >= bestk)  //剪枝
        return;
    if (i< n - 1 && (k + (t2 - t) / 5 >= bestk))  //剪枝
        return;
    if (i<n)
    {
        change(i + 1, j);  //放置机器人，并改变状态
        backtrack(i, j);
        restore(i + 1, j); //撤销机器人，并恢复状态
    }
    if (j<m && (board[i][j + 1] == 0 || board[i][j + 2] == 0))
    {
        change(i, j + 1);
        backtrack(i, j);
        restore(i, j + 1);
    }
    if (board[i + 1][j] == 0 && board[i][j + 1] == 0)
    {
        change(i, j);
        backtrack(i, j);
        restore(i, j);
    }
}

void compute()
{
    more = m / 4 + 1;
    if (m % 4 == 3)
        more++;
    else if (m % 4 == 2)
        more += 2;
    t2 = m * n + more + 4;
    t1 = m * n + 4;
    memset(board, 0, sizeof(board));
    memset(root, 0, sizeof(root));
    for (int i = 0; i <= n + 1; i++)      //最外层一圈为1
    {
        board[i][m + 1] = 1;
        board[i][0] = 1;
    }

    for (int i = 0; i <= m + 1; i++)
    {
        board[n + 1][i] = 1;
        board[n + 1][0] = 1;
    }

    if (n == 1 && m == 1)
        ;
    else
        backtrack(1, 0);
}
void MainWindow::Tool_4()//top_module_control(12,0,"",const QList<Edge> xianlu_display_more,const QList<int> zhandian_display_more)
{
    QString writeFile="userAdd.txt";
    QFile file(writeFile);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QMessageBox::critical(NULL, "提示", "无法创建添加文件");return;
    }
    QTextStream out(&file);
    out<<addLine->ui->textEdit->toPlainText();
    file.close();
    QMessageBox box;
    box.setWindowTitle(tr("线路文本格式添加"));
    bool flag;
    if(1)
    {
        QString fileName=writeFile;
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly))
            flag=false;
        QTextStream in(&file);
        while(!in.atEnd())
        {
            xianlu_info_ALL line;
            QString Info_xianluandzhandian_code, name, colour, fromTo, totalStations,color, froms, tos,longlat;
            QStringList strList;
            Info_of_zhandian station;
            bool ok;
            int total,lvIndex, svIndex1, svIndex2;
            in>>Info_xianluandzhandian_code>>line.Info_xianluandzhandian_code>>name>>line.name>>colour>>color>>fromTo>>froms>>tos>>totalStations>>total;
            line.color.setRgba(color.remove(0,1).toUInt(&ok, 16));
            line.fromTo.push_back(froms);
            line.fromTo.push_back(tos);
            if (ALL_Subwang_info->Info_ALLxianlu.count(line.name))
            {
                lvIndex = ALL_Subwang_info->Info_ALLxianlu[line.name];
                ALL_Subwang_info->lines[lvIndex].fromTo.push_back(froms);
                ALL_Subwang_info->lines[lvIndex].fromTo.push_back(tos);
            }
            else
            {
                lvIndex = ALL_Subwang_info->Info_ALLxianlu[line.name] = ALL_Subwang_info->lines.size();
                ALL_Subwang_info->lines.push_back(line);
            }
            for (int i=0; !in.atEnd()&&i<total; ++i)
            {
                in>>station.Info_xianluandzhandian_code>>station.name>>longlat;
                strList=longlat.split(QChar(','));
                station.Info_of_zhandian_info_1=strList.first().toDouble();
                station.Info_of_zhandian_info_2=strList.last().toDouble();

                if (ALL_Subwang_info->Info_ALLzhandian.count(station.name))
                {
                    svIndex2 = ALL_Subwang_info->Info_ALLzhandian[station.name];
                }
                else
                {
                    svIndex2 = ALL_Subwang_info->Info_ALLzhandian[station.name] = ALL_Subwang_info->stations.size();
                    ALL_Subwang_info->stations.push_back(station);
                }
                ALL_Subwang_info->stations[svIndex2].xianlu_Qset_ALL.insert(lvIndex);
                ALL_Subwang_info->lines[lvIndex].zhandian_Qset_ALL.insert(svIndex2);
                if (i)
                {
                    ALL_Subwang_info->lines[lvIndex].xianlu_ALLInfo.insert(Edge(svIndex1, svIndex2));
                    ALL_Subwang_info->lines[lvIndex].xianlu_ALLInfo.insert(Edge(svIndex2, svIndex1));
                    if(1)
                    {
                        if (ALL_Subwang_info->xianlu_ALLInfo.contains(Edge(svIndex1, svIndex2)) || ALL_Subwang_info->xianlu_ALLInfo.contains(Edge(svIndex2, svIndex1)))
                        {
                           flag=false;
                        }
                        ALL_Subwang_info->xianlu_ALLInfo.insert(Edge(svIndex1, svIndex2));
                    }
                }
                svIndex1 = svIndex2;
            }
            bool flag = Info_xianluandzhandian_code=="Line:" && name=="Linenum:" && colour=="yanse:" && fromTo=="EndandStart:"&& totalStations=="ALL:" && ok && !in.atEnd();
            if(flag==false)
            {
                file.close();
                ALL_Subwang_info->stations.clear();
                ALL_Subwang_info->lines.clear();
                ALL_Subwang_info->Info_ALLzhandian.clear();
                ALL_Subwang_info->Info_ALLxianlu.clear();
                ALL_Subwang_info->xianlu_ALLInfo.clear();
                ALL_Subwang_info->Link_Subwang.clear();
                flag=false ;
            }
            in.readLine();
        }
        file.close();
        if(1)
        {
            double distance_info1=200, distance_info2=200,distance_info3=0, distance_info4=0;
            for (auto &s : ALL_Subwang_info->stations)
            {
                distance_info1 =(distance_info1>s.Info_of_zhandian_info_1)?s.Info_of_zhandian_info_1:distance_info1;
                distance_info2 = (distance_info2>s.Info_of_zhandian_info_2)?s.Info_of_zhandian_info_2:distance_info2;
                distance_info3 = (distance_info3>s.Info_of_zhandian_info_1)?distance_info3:s.Info_of_zhandian_info_1;
                distance_info4 = (distance_info4>s.Info_of_zhandian_info_2)?distance_info4:s.Info_of_zhandian_info_2;
            }
            Info_of_zhandian::distance_info1 = distance_info1;
            Info_of_zhandian::distance_info2 = distance_info2;
            Info_of_zhandian::distance_info3 = distance_info3;
            Info_of_zhandian::distance_info4 = distance_info4;
        }
       flag=true;
    }
    if(flag)
    {
        box.setIcon(QMessageBox::Information);
        box.setText(tr("添加successful\-_-/"));
        box.setWindowIcon(QIcon(":/icon/timg4.png"));
    }
    else
    {
        box.setIcon(QMessageBox::Critical);
        box.setWindowIcon(QIcon(":/icon/timg4.png"));
        box.setText(tr("添加failed-_-!"));
    }
    box.addButton(tr("确定,返回添加"),QMessageBox::AcceptRole);
    if(box.exec()==QMessageBox::Accepted)
    {
        box.close();
    }
    Request_temp();
    on_pushButton_15_clicked();
    return;
}


void MainWindow::on_actionAuthor_triggered()
{
    QMessageBox box(QMessageBox::NoIcon,tr("作者"),tr("School:同济大学\n\n""Major:计算机科学与技术\n\n""Author:涂远鹏\n\n""Emai:2458048592@qq.com\n\n""Github:https://github.com/Nevertorlate\n"));
    box.setWindowIcon(QIcon(":/icon/9.png"));
    box.setIconPixmap(QPixmap(":/icon/aaa.png"));
    box.addButton(tr("确定"),QMessageBox::AcceptRole);
    box.addButton(tr("访问主页"),QMessageBox::YesRole);
    if(box.exec() == QMessageBox::Accepted)
    {
        const QUrl regUrl(QLatin1String("https://github.com/Nevertorlate"));
        QDesktopServices::openUrl(regUrl);
        box.close();

    }
}
void MainWindow::on_pushButton_clicked()
{
    int s1;
    int s2;
    QList<int> zhandian_display;
    QList<Edge> xianlu_display;
    QString text;
    QString station_1,station_2;
    if(ui->radioButton->isChecked())
    {
        station_1="莘庄";
        station_2="富锦路";
        statusLabel3->setText(tr("1号线"));
        text=("轨交1号线简介:\n上海轨道交通1号线（Shanghai Metro xianlu_info_ALL 1）是上海的第一条地铁，亦为上海轨道交通最为繁忙、最重要的大动脉，由上海地铁第一运营有限公司负责运营。该线于1993年1月10日建成南段（锦江乐园站至徐家汇站）上行线，于1993年5月28日开始试运营；此后先后开通南段线路、南延伸段、北延伸段、北北延伸段。截至2014年8月，该线途经宝山区、静安区、黄浦区、徐汇区、闵行区5个区，全长36.89公里，共设28个车站，其中换乘车站8座\n");
        ui->label_2->setText("线路全长为36890米");
    }
    else if(ui->radioButton_2->isChecked())
    {
        station_1="广兰路";
        station_2="徐泾东";
        statusLabel3->setText(tr("2号线"));
        text=("轨交2号线简介:\n上海轨道交通2号线（Shanghai Metro xianlu_info_ALL 2）是上海第二条地下铁路线路，由上海地铁第二运营有限公司负责运营，该线于2000年6月11日正式通车。此后，先后开通东延伸段、西延伸段、东东延伸段、西西延伸段、虹桥火车站、张江高科站地下车站。西起青浦徐泾东站，经过南京路，穿越黄浦江，到达浦东新区张江高科技园区，并且再续经唐镇、川沙等地，最后到达浦东国际机场。截至2014年8月，该线全长64公里，共设30座车站，其中换乘车站9座\n");
        ui->label_2->setText("线路全长为64000米");
    }
    else if(ui->radioButton_3->isChecked())
    {
        station_1="上海南站";
        station_2="江杨北路";
        statusLabel3->setText(tr("3号线"));
        text=("轨交3号线简介:\n上海轨道交通3号线（Shanghai Metro xianlu_info_ALL 3），又称明珠线，是上海首条高架轨道交通线路，利用老沪杭铁路内环线和淞沪铁路高架改造而成。该线于2000年12月26日一期通车。2006年12月18日，北延伸段通车。该线从徐汇区的上海南站站至虹口区江湾镇站再至江杨北路站，是一条环绕上海中心城区以高架为主的地铁线路。截至2014年8月，该线全长40.3公里，共设29座车站，其中换乘车站12座（含与4号线共线区段换乘站）\n");
        ui->label_2->setText("线路全长为40300米");
    }
    else if(ui->radioButton_4->isChecked())
    {
        station_1="宜山路";
        station_2="虹桥路";
        statusLabel3->setText(tr("4号线"));
        text=("轨交4号线简介:\n上海轨道交通4号线（Shanghai Metro xianlu_info_ALL 4），是上海轨道交通系统中唯一的一条环线。该线途径徐汇、黄浦、浦东、杨浦、虹口、静安、普陀、长宁8个区，与1、2号线组成“申”字，构筑起上海轨道交通的基本框架。该线于2005年12月31日投入运营形成C字形线路。2007年9月21日，全线贯通形成O字形。该线为环线结构，无固定终点站，末班车通过宜山路站回库。截至2014年8月，该线全长33.6公里，共设26座车站，其中换乘车站17座\n");
        ui->label_2->setText("线路全长为33600米");
    }
    else if(ui->radioButton_5->isChecked())
    {
        station_1="莘庄";
        station_2="闵行开发区";
        statusLabel3->setText(tr("5号线"));
        text=("轨交5号线简介:\n上海轨道交通5号线（Shanghai Metro xianlu_info_ALL 5），又称莘闵线，是上海轨道交通第4条建成通车的线路，由上海地铁第一运营有限公司负责运营。5号线于2003年11月25日试运营，后期有延伸规划。该线均在闵行区内，北起闵行区莘庄站，南至闵行开发区站。截至2014年8月，该线全长17.2公里，共设11座车站，其中换乘车站1座，\n");
        ui->label_2->setText("线路全长为17200米");
    }
    else if(ui->radioButton_6->isChecked())
    {
        station_1="港城路";
        station_2="东方体育中心";
        statusLabel3->setText(tr("6号线"));
        text=("轨交6号线简介:\n上海轨道交通6号线（Shanghai Metro xianlu_info_ALL 6），贯穿整个浦东新区，北起高桥镇港城路，南至三林地区，由上海地铁第四运营有限公司负责运营。该线于2007年12月29日试运营。2011年4月12日，开通运行东方体育中心站。截至2014年底，曾三次增加运能。截至2014年8月，该线仅途径浦东新区1个区，全长36.1公里，共设27座车站，其中换乘车站5座\n");
        ui->label_2->setText("线路全长为36100米");
    }
    else if(ui->radioButton_7->isChecked())
    {
        station_1="花木路";
        station_2="美兰湖";
        statusLabel3->setText(tr("7号线"));
        text=("轨交7号线简介:\n上海轨道交通7号线（Shanghai Metro xianlu_info_ALL 7），是上海轨道交通系统中第9条开通运营的线路，途径宝山、普陀、静安、徐汇、浦东新区5个区。该线于2009年12月5日部分车站通车。此后，先后开通后滩站、北延伸段、祁华路站。该线从宝山区美兰湖（沪太公路美丹路）起，穿越上海市中心城区，至浦东新区花木路，线路全长约44.35km，共有33座车站，其中换乘车站9座\n");
        ui->label_2->setText("线路全长为44350米");
    }
    else if(ui->radioButton_8->isChecked())
    {
        station_1="沈杜公路";
        station_2="市光路";
        statusLabel3->setText(tr("8号线"));
        text=("轨交8号线简介:\n上海轨道交通8号线（Shanghai Metro xianlu_info_ALL 8），又称杨浦线，是上海轨道交通第七条地铁，由上海地铁第四运营有限公司负责运营。该线于2007年12月29日北段通车。此后，先后开通南延伸段、东方体育中心站、中华艺术宫站。该线北起杨浦区中原小区市光路，经过上海市中心人民广场，穿越黄浦江，到达浦东新区上海东方体育中心，最后到达闵行区浦江镇沈杜公路。截至2014年8月，该线全长37.4公里，共设30座车站，其中换乘车站10座\n");
        ui->label_2->setText("线路全长为37400米");
    }
    else if(ui->radioButton_9->isChecked())
    {
        station_1="松江南站";
        station_2="杨高中路";
        statusLabel3->setText(tr("9号线"));
        text=("轨交9号线简介:\n上海轨道交通9号线（Shanghai Metro xianlu_info_ALL 9），也称作申松线，以天蓝色为标志色，列车编组采用6节编组方式。该线由上海港铁建设有限公司负责建设，由上海地铁第一运营有限公司负责运营。该线于2007年12月29日一期通车。此后，先后开通一期遗留段、二期、二期遗留段、南延伸段、三期。该线是一条东西走向为主的线路，穿越徐家汇、花木两个城市副中心，是横穿上海的一条主要干线。截至2017年12月，该线全长45.6公里，共设35座车站，其中换乘车站8座\n");
        ui->label_2->setText("线路全长为45600米");
    }
    else if(ui->radioButton_10->isChecked())
    {
        station_1="新江湾城";
        station_2="虹桥火车站";
        statusLabel3->setText(tr("10号线"));
        text=("轨交10号线简介:\n上海轨道交通10号线（Shanghai Metro xianlu_info_ALL 10），编号M1，是国内首条无人驾驶轨道交通线，一期由新江湾城站至虹桥火车站，主线在龙溪路站连接支线，抵达航中路站。线路全长36千米，其中龙溪路站以东及支线部分于2010年4月10日先期开通试运营，而主线龙溪路站以西于2010年11月28日开通。第二期将由新江湾城站延伸至基隆路，长10.08公里，共设6站，为上海2010～2020年规划建设线路。由于沿途经过新天地、豫园老城厢、南京路、淮海路、四川路、五角场城市副中心等上海中心区域，因此被称为“白金线路”。\n");
        ui->label_2->setText("线路全长为10800米");
    }
    else if(ui->radioButton_11->isChecked())
    {
        station_1="花桥";
        station_2="迪士尼";
        statusLabel3->setText(tr("11号线"));
        text=("轨交11号线简介:\n上海轨道交通11号线（Shanghai Metro xianlu_info_ALL 11），又称申嘉线、沪苏线、（中国大陆）迪士尼线。是上海第10条建成并运营的地铁线路。以咖啡色为标志色，列车采用A型车6节编组方式，由上海地铁第二运营有限公司负责运营。于2007年3月1日正式动工建设，2009年12月31日正式开通运营。线路大致呈“西北—东南”走向，途经上海市浦东新区、徐汇区、长宁区、普陀区、嘉定区和江苏苏州昆山，总长约82.4公里，超过英国伦敦地铁中央线（Central xianlu_info_ALL），是世界最长的地铁线路(不包括日本等发达国家的‘通勤铁路’)，亦是国内第一条跨省地铁线路。该线现有车站38座，其中换乘车站8座。\n");
        ui->label_2->setText("线路全长为82400米");
    }
    else if(ui->radioButton_12->isChecked())
    {
        station_1="七莘路";
        station_2="金海路";
        statusLabel3->setText(tr("12号线"));
        text=("轨交12号线简介:\n上海轨道交通12号线（Shanghai Metro xianlu_info_ALL 12）是上海市第十三条建成运营的地铁线路，于2008年12月30日开工建设，2013年12月29日开通运营东段（金海路站至天潼路站），2014年5月10日开通运营曲阜路站，2015年12月19日开通运营西段（曲阜路站至七莘路站），标志色为翠绿色。上海地铁12号线，线路西起闵行区七莘路站，途经徐汇区、黄浦区、静安区、虹口区、杨浦区、浦东新区，终点止于浦东新区金海路站。上海地铁12号线全长40.4公里，全部为地下线；共设32座车站，全部为地下车站；列车采用6节编组A型列车，由长春长客-庞巴迪轨道车辆有限公司制造。\n");
        ui->label_2->setText("线路全长为40400米");
    }
    else if(ui->radioButton_13->isChecked())
    {
        station_1="金运路";
        station_2="世博大道";
        statusLabel3->setText(tr("13号线"));
        text=("轨交13号线简介:\n上海轨道交通13号线（Shanghai Metro xianlu_info_ALL 13）是上海一条正在建设中且运营中的轨道交通路线，分为一期、二期和三期工程。线路全长38千米，均为地下线，共有31座车站和2座车场，分别为北翟路停车场（与2号线共享）及川杨河辅助停车场（与11、16号线共享）。本线现已开通19站，二期工程长寿路站至世博大道站于2015年12月19日开通运营。\n");
        ui->label_2->setText("线路全长为38000米");
    }
    else if(ui->radioButton_16->isChecked())
    {
        station_1="滴水湖";
        station_2="龙阳路";
        statusLabel3->setText(tr("16号线"));
        text=("轨交16号线简介:\n上海轨道交通16号线（Shanghai Metro xianlu_info_ALL 16 ），北起龙阳路站，南至滴水湖站。全长58.96公里，其中地下线长约13.74公里，高架线长约45.22公里，共设车站13座，是一条市域通勤铁路，其车辆采用最大时速为120公里的6节编组A型车。轨道交通16号线极大地缩短了南汇新城与中心城区的距离，将南汇新城与中心城区快速联系起来，为解决上海市东南地区的居民出行提供了一条重要的交通干线。轨道交通16号线采用了接触网和第三轨双受流供电的列车，正线采用第三轨，出入段线及入库采用接触网。2010年3月22日，轨道交通16号线开工典礼在南汇新城滴水湖畔举行。2012年11月底，轨道15-2标上下行全部贯通，由龙阳路站至滴水湖站。2013年12月29日，罗山路——滴水湖段开通运营。作为市域线，上海轨道交通16号线担任着临港、书院、万祥、惠南、新场等地区与市区的通勤任务，所以也称为临港市域快速轨道。\n");
        ui->label_2->setText("线路全长为45220米");
    }
    else if(ui->radioButton_14->isChecked())
    {
        station_1="虹桥火车站";
        station_2="东方绿舟";
        statusLabel3->setText(tr("17号线"));
        text=("轨交17号线简介:\n上海轨道交通17号线（Shanghai Metro xianlu_info_ALL 17）是上海市第十五条建成运营的地铁线路，在上海轨道交通网络中属于市域线，由上海地铁第二运营有限公司运营，于2017年12月30日载客试运营（东方绿舟站至虹桥火车站站），标志色为暗橙色。上海轨道交通17号线东起闵行区虹桥火车站站，途径闵行区、青浦区，西至青浦区东方绿舟站。上海轨道交通17号线全长35.3公里；共设13座车站，其中地下站7座，高架站6座；列车采用6节编组A型列车。\n");
        ui->label_2->setText("线路全长为35300米");
    }
    else if(ui->radioButton_15->isChecked())
    {
        station_1="沈杜公路";
        station_2="汇臻路";
        statusLabel3->setText(tr("浦江线"));
        text=("浦江号线简介:\n上海轨道交通浦江线(Shanghai Metro Pujiang xianlu_info_ALL)是上海建成运营的首条APM轨道交通线(全自动旅客捷运系统)，于2018年3月31日试运营，标志色为灰色。 [1-2] 上海轨道交通浦江线，线路起于沈杜公路站，途径浦江镇，止于汇臻路站，大致呈南北走向。上海轨道交通浦江线线路全长6.68千米，全部为高架线；共设置6座车站，全部为高架车站；列车采用胶轮4节编组列车。\n");
        ui->label_2->setText("线路全长为6680米");
    }
    if(1)
    {
        if(ALL_Subwang_info->Info_ALLzhandian.contains(station_1))
        {
            s1=ALL_Subwang_info->Info_ALLzhandian[station_1];
        }
        else s1=-1;
        if(ALL_Subwang_info->Info_ALLzhandian.contains(station_2))
        {
            s2=ALL_Subwang_info->Info_ALLzhandian[station_2];
        }
        else s2=-1;
    }
    display_graph_info->clear();
    if(1)
    {
        int em_flag=0;
        std::vector<bool> linesVisted(ALL_Subwang_info->lines.size(),false);
        std::vector<int> path(ALL_Subwang_info->stations.size(),-1);
        std::queue<int> que;
        zhandian_display.clear();
        xianlu_display.clear();
        if(s1==s2)
        {
            zhandian_display.push_back(s2);
            zhandian_display.push_back(s1);
            em_flag=1;
        }
        path[s1]=-2;
        que.push(s1);
        while(!em_flag&&!que.empty())
        {
            int top=que.front();
            que.pop();
            for (auto &l: ALL_Subwang_info->stations[top].xianlu_Qset_ALL)
            {
                if(!linesVisted[l])
                {
                    linesVisted[l]=true;
                    for (auto &s: ALL_Subwang_info->lines[l].zhandian_Qset_ALL)
                    {
                        if(path[s]==-1)
                        {
                            path[s]=top;
                            que.push(s);
                        }
                    }
                }
            }
        }
        int p=s2;
        while(path[p]!=-2)
        {
            zhandian_display.push_front(p);
            xianlu_display.push_front(Edge(path[p],p));
            p=path[p];
        }
        zhandian_display.push_front(s1);
    }
    Painting_1(xianlu_display);
    Painting_2(zhandian_display);
    QTextBrowser* browser=ui->textBrowser_2;
    browser->clear();
    browser->setText(text);
}
void MainWindow::on_pushButton_2_clicked()
{

    QPixmap pixmap;
    QGraphicsItem *item;
    pixmap.load(":/icon/shanghai.png");
    QGraphicsScene *display_graph_info = new QGraphicsScene;
    QGraphicsView *view = new QGraphicsView(display_graph_info);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->setRenderHint(QPainter::Antialiasing);
    view->resize(2000,2000);
    view->setWindowTitle(tr("地铁视图"));
    view->setScene(display_graph_info);
    view->setWindowIcon(QIcon(":/icon/timg4.png"));
    item=display_graph_info->addPixmap(pixmap);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setScale(0.5); //默认加载比例
    view->show();
}
void MainWindow::on_pushButton_3_clicked()
{
    QPixmap pixmap;
    QGraphicsItem *item;
    double x_scale=1;
    QString line;
    if(ui->radioButton->isChecked())
    {
       line="1号线";
       pixmap.load(":/icon/subway1/1.png");
    }
    else if(ui->radioButton_2->isChecked())
    {
       line="2号线";
       pixmap.load(":/icon/subway1/2.png");
    }
    else if(ui->radioButton_3->isChecked())
    {
       line="3号线";
       pixmap.load(":/icon/subway1/3.png");
    }
    else if(ui->radioButton_4->isChecked())
    {
       line="4号线";
       pixmap.load(":/icon/subway1/4.png");
    }
    else if(ui->radioButton_5->isChecked())
    {
       line="5号线";
       pixmap.load(":/icon/subway1/5.png");
    }
    else if(ui->radioButton_6->isChecked())
    {
       line="6号线";
       pixmap.load(":/icon/subway1/6.png");
    }
    else if(ui->radioButton_7->isChecked())
    {
       line="7号线";
       pixmap.load(":/icon/subway1/7.png");
    }
    else if(ui->radioButton_8->isChecked())
    {
       line="8号线";
       pixmap.load(":/icon/subway1/8.png");
    }
    else if(ui->radioButton_9->isChecked())
    {
       line="9号线";
       pixmap.load(":/icon/subway1/9.png");
    }
    else if(ui->radioButton_10->isChecked())
    {
       line="10号线";
       pixmap.load(":/icon/subway1/10.png");
    }
    else if(ui->radioButton_11->isChecked())
    {
       line="11号线";
       pixmap.load(":/icon/subway1/11.png");
    }
    else if(ui->radioButton_12->isChecked())
    {
       line="12号线";
       pixmap.load(":/icon/subway1/12.png");
    }
    else if(ui->radioButton_13->isChecked())
    {
       line="13号线";
       pixmap.load(":/icon/subway1/13.png");
    }
    else if(ui->radioButton_16->isChecked())
    {
       line="16号线";
       pixmap.load(":/icon/subway1/16.png");
    }
    else if(ui->radioButton_14->isChecked())
    {
       line="17号线";
       pixmap.load(":/icon/subway1/17.png");
    }
    else if(ui->radioButton_15->isChecked())
    {
       line="浦江线";
       pixmap.load(":/icon/subway1/18.png");
    }
    QGraphicsScene *display_graph_info = new QGraphicsScene;
    QGraphicsView *view = new QGraphicsView(display_graph_info);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->setRenderHint(QPainter::Antialiasing);
    view->resize(1000,1000);
    view->setWindowTitle(line+tr("首末班时刻表"));
    view->setScene(display_graph_info);
    view->setWindowIcon(QIcon(":/icon/metro.png"));
    item=display_graph_info->addPixmap(pixmap);
    item->setScale(x_scale);
    view->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    const QUrl regUrl(QLatin1String("http://service.shmetro.com/gxyxqk/index.htm"));
    QDesktopServices::openUrl(regUrl);
}

void MainWindow::on_pushButton_6_clicked()
{
    QPixmap pixmap;
    QGraphicsItem *item;
    pixmap.load(":/icon/subway1/cesuo.png");
    QGraphicsScene *display_graph_info = new QGraphicsScene;
    QGraphicsView *view = new QGraphicsView(display_graph_info);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->setRenderHint(QPainter::Antialiasing);
    view->resize(2000,2000);
    view->setWindowTitle(tr("地铁卫生间分布图"));
    view->setScene(display_graph_info);
    view->setWindowIcon(QIcon(":/icon/timg.png"));
    item=display_graph_info->addPixmap(pixmap);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setScale(2);
    view->show();
}

void MainWindow::on_pushButton_7_clicked()
{
    QPixmap pixmap;
    QGraphicsItem *item;
    pixmap.load(":/icon/subway1/MAP1031.png");
    QGraphicsScene *display_graph_info = new QGraphicsScene;
    QGraphicsView *view = new QGraphicsView(display_graph_info);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->setRenderHint(QPainter::Antialiasing);
    view->resize(2000,2000);
    view->setWindowTitle(tr("地铁无障碍设施分布图"));
    view->setScene(display_graph_info);
    view->setWindowIcon(QIcon(":/icon/noapp.png"));
    item=display_graph_info->addPixmap(pixmap);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setScale(2);
    view->show();


}

void MainWindow::on_pushButton_5_clicked()
{
    ui->pushButton_5->setStyleSheet("border-image:url(:/icon/qt.png)");
    ui->pushButton_5->resize(50,50);
    const QUrl regUrl(QLatin1String("http://service.shmetro.com/cczn/index.htm"));
    QDesktopServices::openUrl(regUrl);
}

void MainWindow::on_pushButton_8_clicked()
{
    const QUrl regUrl(QLatin1String("http://service.shmetro.com/yygg/index.htm"));
    QDesktopServices::openUrl(regUrl);
}


void MainWindow::on_pushButton_9_clicked()
{
    const QUrl regUrl(QLatin1String("http://service.shmetro.com/klssxx/index.htm"));
    QDesktopServices::openUrl(regUrl);
}

void MainWindow::on_pushButton_12_clicked()
{
    QPixmap pixmap;
    QGraphicsItem *item;
    pixmap.load(":/icon/subway1/erweima.png");
    QGraphicsScene *display_graph_info = new QGraphicsScene;
    QGraphicsView *view = new QGraphicsView(display_graph_info);
    view->setRenderHint(QPainter::Antialiasing);
    view->resize(1000,200);
    view->setWindowTitle(tr("二维码"));
    view->setScene(display_graph_info);
    view->setWindowIcon(QIcon(":/icon/timg1.png"));
    item=display_graph_info->addPixmap(pixmap);
    item->setScale(1);
    view->show();
}

void MainWindow::on_pushButton_11_clicked()
{
    QPixmap pixmap;
    QGraphicsItem *item;
    double x_scale=1;
    QString line;
    if(ui->radioButton->isChecked())
    {
       line="1号线";
       pixmap.load(":/icon/subway2/1.png");
    }
    else if(ui->radioButton_2->isChecked())
    {
       line="2号线";
       pixmap.load(":/icon/subway2/2.png");
    }
    else if(ui->radioButton_3->isChecked())
    {
       line="3号线";
       pixmap.load(":/icon/subway2/3.png");
    }
    else if(ui->radioButton_4->isChecked())
    {
       line="4号线";
       pixmap.load(":/icon/subway2/4.png");
    }
    else if(ui->radioButton_5->isChecked())
    {
       line="5号线";
       pixmap.load(":/icon/subway2/5.png");
    }
    else if(ui->radioButton_6->isChecked())
    {
       line="6号线";
       pixmap.load(":/icon/subway2/6.png");
    }
    else if(ui->radioButton_7->isChecked())
    {
       line="7号线";
       pixmap.load(":/icon/subway2/7.png");
    }
    else if(ui->radioButton_8->isChecked())
    {
       line="8号线";
       pixmap.load(":/icon/subway2/8.png");
    }
    else if(ui->radioButton_9->isChecked())
    {
       line="9号线";
       pixmap.load(":/icon/subway2/9.png");
    }
    else if(ui->radioButton_10->isChecked())
    {
       line="10号线";
       pixmap.load(":/icon/subway2/10.png");
    }
    else if(ui->radioButton_11->isChecked())
    {
       line="11号线";
       pixmap.load(":/icon/subway2/11.png");
    }
    else if(ui->radioButton_12->isChecked())
    {
       line="12号线";
       pixmap.load(":/icon/subway2/12.png");
    }
    else if(ui->radioButton_13->isChecked())
    {
       line="13号线";
       pixmap.load(":/icon/subway2/13.png");
    }
    else if(ui->radioButton_16->isChecked())
    {
       line="16号线";
       pixmap.load(":/icon/subway2/16.png");
    }
    else if(ui->radioButton_14->isChecked())
    {
       line="17号线";
       pixmap.load(":/icon/subway2/17.png");
    }
    else if(ui->radioButton_15->isChecked())
    {
       line="浦江线";
       pixmap.load(":/icon/subway2/18.png");
    }
    QGraphicsScene *display_graph_info = new QGraphicsScene;
    QGraphicsView *view = new QGraphicsView(display_graph_info);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->setRenderHint(QPainter::Antialiasing);
    view->resize(500,1000);
    view->setWindowTitle(line+tr("车站信息"));
    view->setScene(display_graph_info);
    view->setWindowIcon(QIcon(":/icon/timg2.png"));
    item=display_graph_info->addPixmap(pixmap);
    item->setScale(x_scale);
    view->show();

}

void MainWindow::on_pushButton_10_clicked()
{
    QPixmap pixmap;
    QGraphicsItem *item;
    pixmap.load(":/icon/subway2/konw.png");
    QGraphicsScene *display_graph_info = new QGraphicsScene;
    QGraphicsView *view = new QGraphicsView(display_graph_info);
    view->setRenderHint(QPainter::Antialiasing);
    view->resize(1200,1000);
    view->setWindowTitle(tr("乘客须知"));
    view->setScene(display_graph_info);
    view->setWindowIcon(QIcon(":/icon/timg3.png"));
    item=display_graph_info->addPixmap(pixmap);
    item->setScale(1);
    view->show();
}

void MainWindow::on_pushButton_13_clicked()
{
    QMessageBox box(QMessageBox::NoIcon,tr("票价计算规则"),tr("计价规则:按照市物价主管部门批复的轨道交通网络票价体系，即：轨道交通实行按里程计价的多级票价:\n"
                                                    "1.0~6公里3元，6公里之后每10公里增加1元;\n2.票价计算采用最短路径法，即：当两个站点之间有超过"
                                                    "1条换乘路径时，选取里程最短的一条路径作为两站间票价计算依据。"));
    box.setIconPixmap(QPixmap(":/icon/money.png"));
    box.addButton(tr("确定"),QMessageBox::AcceptRole);
    box.setWindowIcon(QIcon(":/icon/money0.png"));
    if(box.exec() == QMessageBox::Accepted)
    {
        box.close();
    }
}
void MainWindow::on_pushButton_14_clicked()
{
    const QUrl regUrl(QLatin1String("http://service.shmetro.com/cpxz/index.htm"));
    QDesktopServices::openUrl(regUrl);
}

void MainWindow::on_pushButton_15_clicked()
{
    statusLabel3->setText(tr("上海地铁站点分布图"));
    ui->textBrowser_2->setText("");
    display_graph_info->clear();
    QList<int> zhandian_display;
    QList<Edge> xianlu_display;
    if(1)
    {
        zhandian_display.clear();
        for (int i=0; i<ALL_Subwang_info->stations.size(); ++i)
        {
            zhandian_display.push_back(i);
        }
        xianlu_display=ALL_Subwang_info->xianlu_ALLInfo.toList();
    }
    Painting_1(xianlu_display);
    Painting_2(zhandian_display);
}

void MainWindow::on_pushButton_16_clicked()
{
    addLine->setWindowIcon(QIcon(":/icon/aaabbb.png"));
    addLine->ui->tabWidget->clear();addLine->ui->tabWidget->addTab(addLine->More_addTab[0],addLine->More_addIcon[0],addLine->More_adderam[0]);
    addLine->ui->tabWidget->addTab(addLine->More_addTab[1],addLine->More_addIcon[1],addLine->More_adderam[1]);addLine->ui->tabWidget->addTab(addLine->More_addTab[2],addLine->More_addIcon[2],addLine->More_adderam[2]);addLine->ui->tabWidget->addTab(addLine->More_addTab[3],addLine->More_addIcon[3],addLine->More_adderam[3]);statusLabel3->setText(tr("添加工具"));addLine->show();
}
