#include "ui_mainwindow.h"
#include "ui_AddLine.h"
#include "mainwindow.h"
#include <math.h>
#include <QIcon>
#include <QDesktopWidget>
#include <QRect>
#include <QPoint>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QDir>
#include <QWidget>
#include <QPushButton>
#include <QTextBrowser>
#include <QStackedWidget>
#include <QListWidget>
#include <QPixmap>
#include <QColorDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <queue>
#define INF 999999999
#pragma execution_character_set("utf-8")
AddLine::AddLine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLine)
{

    ui->setupUi(this);
    More_addTab.push_back(ui->tab_1);
    More_addTab.push_back(ui->tab_2);
    More_addTab.push_back(ui->tab_3);
    More_addTab.push_back(ui->tab_4);
    More_addIcon.push_back(QIcon(QPixmap(":/icon/23.png")));
    More_addIcon.push_back(QIcon(QPixmap(":/icon/23.png")));
    More_adderam.push_back(tr("添加线路"));
    More_adderam.push_back(tr("添加站点"));
    More_adderam.push_back(tr("添加连接"));
    More_adderam.push_back(tr("文本形式添加线路"));

    More_addIcon.push_back(QIcon(QPixmap(":/icon/23.png")));
    More_addIcon.push_back(QIcon(QPixmap(":/icon/23.png")));
    ui->comboBoxConnectLine->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->comboBoxConnectStation1->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->comboBoxConnectStation2->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->doubleSpinBoxLatitude->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->doubleSpinBoxLongitude->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    //ui->label->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->labelLatitude->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->labelLongitude->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->label_3->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->label_4->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->label_5->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->label_6->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->label_7->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->label_8->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    //ui->label_9->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    //ui->label_10->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->label_11->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->label_11->setFont(QFont("楷体",11,1));
    ui->comboBoxConnectLine->setFont(QFont("楷体",11,1));
    ui->comboBoxConnectStation1->setFont(QFont("楷体",11,1));
    ui->comboBoxConnectStation2->setFont(QFont("楷体",11,1));
    ui->doubleSpinBoxLatitude->setFont(QFont("楷体",11,1));
    ui->doubleSpinBoxLongitude->setFont(QFont("楷体",11,1));
    ui->label_5->setFont(QFont("楷体",11,1));
    ui->label_6->setFont(QFont("楷体",11,1));
    ui->label_7->setFont(QFont("楷体",9,1));
    ui->listWidget->setFont(QFont("楷体",11,1));
    ui->pushButton_12->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->pushButton_0->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->pushButton_1->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->pushButton_11->setStyleSheet("border-image:url(:/icon/anniu/2.png)");
    ui->pushButtonChooseColor->setStyleSheet("border-image:url(:/icon/anniu/2.png)");

    ui->tab_4->setStyleSheet("border-image:url(:/icon/anniu/timg111.png)");
    ui->tab_3->setStyleSheet("border-image:url(:/icon/anniu/timg111.png)");
    ui->tab_1->setStyleSheet("border-image:url(:/icon/anniu/timg111.png)");
    ui->tab_2->setStyleSheet("border-image:url(:/icon/anniu/timg111.png)");
   // ui->tabWidget->setStyleSheet("border-image:url(:/icon/anniu/timg111.png)");
    //AddLine.setBackgroundRole();
    QString temp_read=tr("提示:添加请按照data.txt中线路对应的格式添加数据\n");
    ui->textEdit->setPlaceholderText(temp_read);
}
AddLine::~AddLine(){delete ui;}
void AddLine::on_pushButtonChooseColor_clicked()
{
    QColorDialog colorDialog;colorDialog.setStyleSheet("border-image:url(:/icon/2.png)");colorDialog.setOptions(QColorDialog::ShowAlphaChannel);colorDialog.exec();Yanse_xianlu_info=colorDialog.currentColor();
}

void AddLine::on_listWidget_itemClicked(QListWidgetItem *item)
{
    Q_UNUSED(item);
    QString str;
    Info_for_all_2.clear();
    for (int i=0; i<ui->listWidget->count(); ++i)
    {
        QListWidgetItem* item=ui->listWidget->item(i);
        if(item->checkState()==Qt::Checked)
        {Info_for_all_2.push_back(item->text());str+=item->text(); str+="\n";}}
}
bool Shanghai_sub::SearchTime(int &length,int s1, int s2, QList<int>&zhandian_display, QList<Edge>&xianlu_display,int temp)
{
    zhandian_display.clear();xianlu_display.clear();
    if(s1==s2){zhandian_display.push_back(s2);zhandian_display.push_back(s1);return true;}
    if(1)
    {
        Link_Subwang.clear();Link_Subwang=QVector<QVector<Info_of_distance>>(stations.size(), QVector<Info_of_distance>());
        for (auto &a : xianlu_ALLInfo)
        {
            double dist;
            if(1)
            {
                const double temp_radius=6378.137;
                double radLat1 =stations[a.first].Info_of_zhandian_info_2*3.1415926535898/180.0;double radLat2 =stations[a.second].Info_of_zhandian_info_2*3.1415926535898/180.0;double de = radLat1 - radLat2;
                double b = stations[a.first].Info_of_zhandian_info_1*3.1415926535898/180.0 - stations[a.second].Info_of_zhandian_info_1*3.1415926535898/180.0;double s = 2 * asin(sqrt(pow(sin(de/2),2) + cos(radLat1)*cos(radLat2)*pow(sin(b/2),2)));
                s = s * temp_radius;
                s = (int)(s * 10000000) / 10000;
                dist=s;
            }
            Link_Subwang[a.first].push_back(Info_of_distance(a.second, dist));Link_Subwang[a.second].push_back(Info_of_distance(a.first, dist));
        }
    }
    std::vector<int> path(stations.size(), -1);
    std::vector<double> dist(stations.size(), INF);
    dist[s1]=0;
    std::priority_queue<Info_of_distance, std::vector<Info_of_distance>, std::greater<Info_of_distance>> priQ;
    priQ.push(Info_of_distance(s1, 0));
    while(!priQ.empty())
    {
        Info_of_distance top=priQ.top();
        priQ.pop();
        if(top.zhandian_intInfo==s2)
        {
            break;
        }
        for (int i=0; i<Link_Subwang[top.zhandian_intInfo].size(); ++i)
        {
            Info_of_distance &adjNode=Link_Subwang[top.zhandian_intInfo][i];
            if(temp==1)
            {
                if(top.distance+adjNode.distance<dist[adjNode.zhandian_intInfo])
                {
                   path[adjNode.zhandian_intInfo]=top.zhandian_intInfo;
                   dist[adjNode.zhandian_intInfo]=top.distance+adjNode.distance;
                   length=dist[adjNode.zhandian_intInfo];
                   priQ.push(Info_of_distance(adjNode.zhandian_intInfo, dist[adjNode.zhandian_intInfo]));
                }
            }
            else if(temp==2)
            {
                if(top.distance+adjNode.distance>dist[adjNode.zhandian_intInfo])
                {
                   path[adjNode.zhandian_intInfo]=top.zhandian_intInfo;
                   dist[adjNode.zhandian_intInfo]=top.distance+adjNode.distance;
                   length=dist[adjNode.zhandian_intInfo];
                   priQ.push(Info_of_distance(adjNode.zhandian_intInfo, dist[adjNode.zhandian_intInfo]));
                }
            }
         }
    }

    if(path[s2]==-1)
    {
        return false;
    }
    int p=s2;
    while(path[p]!=-1)
    {
        zhandian_display.push_front(p);
        xianlu_display.push_front(Edge(path[p],p));
        p=path[p];
    }
    zhandian_display.push_front(s1);
    return true;
}
Info_of_zhandian::Info_of_zhandian(QString nameStr, double longi, double lati, QList<int> linesList):name(nameStr), Info_of_zhandian_info_1(longi), Info_of_zhandian_info_2(lati){xianlu_Qset_ALL=linesList.toSet();}

void MainWindow::music_display()
{
    player1 = new QMediaPlayer;
    connect(player1, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    player1->setMedia(QUrl::fromLocalFile("D:/360zip/QTproject/untitled1/image/a.mp3"));
    player1->setVolume(30);
    player1->play();
}
