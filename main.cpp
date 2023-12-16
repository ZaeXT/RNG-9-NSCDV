#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QFont>
#include <QHBoxLayout>
#include <QLabel>
#include <QList>
#include <QMainWindow>
#include <QMessageBox>
#include <QOBject>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

const int IntervalScroll_ter = 50;
const int IntervalScroll_ier = 1000;
bool ScrollFlag = true;
int displayChar = 0;
int mode = 0;
int Ctime = 0;
const int timeOutMsg = 500;
int yuanshi = 114514;
QString name[] = {"巴雷!", "包宇恒", "陈晶晶", "陈佩琪", "黄彦玮", "姜王迪", "李精锐", "刘静雯", "刘周心", "柳子恒", "马佳豪", "马文军", "潘梓豪", "沈一!", "殳楷博", "王羽郴", "王哲宇", "吴国祥", "吴家兴", "肖曦文", "徐景飏", "徐秋雨", "杨坤元", "姚杭晨", "俞佳扬", "张弛斌", "张创!", "张帅!", "张天浩", "张鑫琳", "张伊靓", "张奕阳", "张宇喆", "钟韩易", "朱妍!", "朱钰欣", "朱正天", "姚董轩"};

QString spacekey = " ";

int gen_rnd(int gen_min = 0, int gen_max = 37);

void HappyTen(QWidget &wi, QSizePolicy &sizePolicy);
QList<QString> rndChar;

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QMessageBox msgBoxNCD;
   QWidget w;

   QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
   w.setSizePolicy(sizePolicy);

   QTimer ter, ier;
   int upch = 0;
   rndChar << "!"
           << "@"
           << "#"
           << "$"
           << "%"
           << "^"
           << "&"
           << "&"
           << "*"
           << "("
           << ")"
           << "_"
           << "+";
   QVBoxLayout *Vlayout = new QVBoxLayout(&w);
   QHBoxLayout *Hlayout = new QHBoxLayout(&w);
   QLabel *text_show = new QLabel(&w);
   QFont font, yuanfont;
   font.setPointSize(24);
   yuanfont.setPointSize(10);
   Vlayout->addWidget(text_show);
   text_show->setText("开抽！");
   text_show->setFont(font);
   text_show->setAlignment(Qt::AlignCenter);
   text_show->setSizePolicy(sizePolicy);
   ter.setInterval(IntervalScroll_ter);
   ier.setInterval(IntervalScroll_ier);
   QMessageBox startMsg, msgYuanNum;
   startMsg.setWindowTitle("Changelog");
   startMsg.setText("更新：\n1、文本居中\n2、添加十连（待完成");
   startMsg.show();
   msgBoxNCD.setText("触发保底！");
   msgBoxNCD.setWindowTitle("NSCD OS");
   QObject::connect(&ter, &QTimer::timeout, [&]()
                    { if (ScrollFlag && displayChar == 0 && mode == 0)
                     {
                        text_show->setText(name[upch][0]+spacekey+rndChar[gen_rnd(0,int(rndChar.size())-1)]+spacekey+rndChar[gen_rnd(0,int(rndChar.size())-1)]);
                     }
                     else if (ScrollFlag && displayChar == 1 && mode == 0)
                     {
                        text_show->setText(name[upch][0]+spacekey+name[upch][1]+spacekey+rndChar[gen_rnd(0,int(rndChar.size())-1)]);
                     }
                     else if (ScrollFlag && displayChar == 2 && mode == 0)
                     {
                        text_show->setText(name[upch][0]+spacekey+name[upch][1]+spacekey+name[upch][2]);
                        ScrollFlag = false;
                        Ctime++;
                     }
                     else if (ScrollFlag && displayChar == 0 && mode == 1)
                     {
                        text_show->setText(name[upch][0] + spacekey + name[gen_rnd()][1] + spacekey + name[gen_rnd()][2]);
                     }
                     else if (ScrollFlag && displayChar == 1 && mode == 1)
                     {
                        text_show->setText(name[upch][0]+spacekey+name[upch][1]+spacekey+name[gen_rnd()][2]);
                     }
                     else if (ScrollFlag && displayChar == 2 && mode == 1)
                     {
                        text_show->setText(name[upch][0] + spacekey + name[upch][1] + spacekey + name[upch][2]);
                        ScrollFlag = false;
                        if (upch == 25)
                        {
                           Ctime = 0;
                        }
                        else
                        {
                           Ctime++;
                        }
                     }
                     else if (Ctime >= 30 && name[upch][2] != QString("斌"))
                     {
                        text_show->setText("张 弛 斌");
                        QTimer::singleShot(timeOutMsg, &msgBoxNCD, &QMessageBox::accept);
                        msgBoxNCD.show();
                        Ctime = 0;
                     } });
   QObject::connect(&ier, &QTimer::timeout, [&]()
                    { displayChar++; });
   QPushButton *buttom160 = new QPushButton("160缘", &w);
   QPushButton *buttom1600 = new QPushButton("1600缘", &w);
   Hlayout->addWidget(buttom160);
   Hlayout->addWidget(buttom1600);
   Vlayout->addLayout(Hlayout);
   QLabel *YuanNum = new QLabel("您的缘还有：114514", &w);
   YuanNum->setFont(yuanfont);
   YuanNum->setAlignment(Qt::AlignCenter);
   Vlayout->addWidget(YuanNum);
   QObject::connect(buttom160, &QPushButton::clicked, [&]
                    {
                       if (yuanshi >= 160)
                       {
                          yuanshi -= 160;
                          YuanNum->setText("您的缘还有：" + QString::number(yuanshi));
                          ter.start();
                          ier.start();
                          ScrollFlag = true;
                          displayChar = 0;
                          mode = gen_rnd(0, 1);
                          upch = gen_rnd();
                       }
                       else
                       {
                          QMessageBox::StandardButton reply;
                          reply = QMessageBox::question(&w, "您的缘不足！", "您的缘不足！\n建议重开",
                                                        QMessageBox::Yes | QMessageBox::No);
                          if (reply == QMessageBox::Yes)
                          {
                             QApplication::quit();
                           }
                       } });
   QObject::connect(buttom1600, &QPushButton::clicked, [&]
                    {
                       yuanshi -= 1600;
                       QMessageBox::StandardButton Enreply;
                       Enreply = QMessageBox::question(&w, "确认：", "即将切换到：\nEnhanced Mode\n确认继续？", QMessageBox::Yes | QMessageBox::No);
                       if (Enreply == QMessageBox::Yes)
                       {
                           QWidget *enhanced=new QWidget;
                           enhanced->setWindowTitle("NSCD-9-RNG-Deluxe_Edition.");
                           enhanced->setSizePolicy(sizePolicy);
                           HappyTen(*enhanced, sizePolicy);
                           QTimer dWidget;
                           dWidget.singleShot(100, [&]()
                           {
                              enhanced->deleteLater();
                           });

                           //   enhanced.hide();
                       }
                       else
                       {
                          QMessageBox noenhanced;
                          noenhanced.setWindowTitle("Feedback");
                          noenhanced.setText("Aborted.\nTips:Yuanshi subed.");
                          noenhanced.show();
                       }
                       YuanNum->setText("您的缘还有：" + QString::number(yuanshi)); });
   w.show();
   return app.exec();
}
// 逐个输出十个名字
void HappyTen(QWidget &wi, QSizePolicy &sizePolicy)
{
   int upch = 0;
   bool ScrollFlag[10] = {true};
   int displayChar[10] = {0};
   int mode[10] = {0};
   QVBoxLayout *Vlayout = new QVBoxLayout(&wi);
   wi.show();
   QLabel *tenTitle = new QLabel;
   tenTitle->setText("喜报！");
   tenTitle->setAlignment(Qt::AlignCenter);
   Vlayout->addWidget(tenTitle);
   QHBoxLayout *Hlayout = new QHBoxLayout(&wi);
   Vlayout->addLayout(Hlayout);
   QTimer *ter = new QTimer[10];
   // QTimer *ier = new QTimer[10];
   QLabel *text_show[10];
   int i = 0;
   for (int i = 0; i < 10; i++)
   {
      text_show[i] = new QLabel(&wi);
   }
   for (int i = 0; i < 10; i++)
   {
      QTimer mer;
      mer.singleShot(i * 750, [=]() mutable
                     {
                        ScrollFlag[i] = true;
                        displayChar[i] = 0;
                        mode[i] = gen_rnd(0, 1);
                        upch = gen_rnd();
                        //QLabel *text_showi = new QLabel(&wi);
                        Hlayout->addWidget(text_show[i]);
                        QFont font;
                        font.setPointSize(24);
                        text_show[i]->setFont(font);
                        text_show[i]->setAlignment(Qt::AlignCenter);
                        text_show[i]->setSizePolicy(sizePolicy);
                        ter[i].setInterval(IntervalScroll_ter);
                        // ier[i].setInterval(IntervalScroll_ier);
                        ter[i].start();
                        //ier[i].start();
                        QObject::connect(&ter[i], &QTimer::timeout, [=]() mutable
                                         { 
                        qDebug()<<ScrollFlag[i]<< ' '<<displayChar[i]<< ' '<<mode[i]<<'\n';
                     if (ScrollFlag[i] && displayChar[i] == 0 && mode[i] == 0)
                     {
                        text_show[i]->setText(name[upch][0]+spacekey+rndChar[gen_rnd(0,int(rndChar.size())-1)]+spacekey+rndChar[gen_rnd(0,int(rndChar.size())-1)]);
                        // QTimer::singleShot(IntervalScroll_ier, [=]() mutable
                        //                    {
                                              displayChar[i]++;
                                          //  });
                     }
                     else if (ScrollFlag[i] && displayChar[i] == 1 && mode[i] == 0)
                     {
                        text_show[i]->setText(name[upch][0]+spacekey+name[upch][1]+spacekey+rndChar[gen_rnd(0,int(rndChar.size())-1)]);
                        // QTimer::singleShot(IntervalScroll_ier, [=]() mutable
                        //                    {
                                              displayChar[i]++;
                                          //  });
                     }
                     else if (ScrollFlag[i] && displayChar[i] == 2 && mode[i] == 0)
                     {
                        text_show[i]->setText(name[upch][0]+spacekey+name[upch][1]+spacekey+name[upch][2]);
                        ScrollFlag[i] = false;
                        Ctime++;
                     }
                     else if (ScrollFlag[i] && displayChar[i] == 0 && mode[i] == 1)
                     {
                        text_show[i]->setText(name[upch][0] + spacekey + name[gen_rnd()][1] + spacekey + name[gen_rnd()][2]);
                        // QTimer::singleShot(IntervalScroll_ier, [=]() mutable
                        //                    {
                                              displayChar[i]++;
                                          //  });
                     }
                     else if (ScrollFlag[i] && displayChar[i] == 1 && mode[i] == 1)
                     {
                        text_show[i]->setText(name[upch][0]+spacekey+name[upch][1]+spacekey+name[gen_rnd()][2]);
                        // QTimer::singleShot(IntervalScroll_ier, [=]() mutable
                        //                    {
                                              displayChar[i]++;
                                          //  });
                     }
                     else if (ScrollFlag[i] && displayChar[i] == 2 && mode[i] == 1)
                     {
                        text_show[i]->setText(name[upch][0] + spacekey + name[upch][1] + spacekey + name[upch][2]);
                        ScrollFlag[i] = false;
                        if (upch == 25)
                        {
                          Ctime = 0;
                        }
                        else
                        {
                          Ctime++;
                        }
                     }
                     else if (Ctime >= 30 && name[upch][2] != QString("斌"))
                     {
                        text_show[i]->setText("张 弛 斌");
                        QMessageBox msgBoxNCD;
                        msgBoxNCD.setText("触发保底！");
                        msgBoxNCD.setWindowTitle("NSCD OS");
                        QTimer::singleShot(timeOutMsg, &msgBoxNCD, &QMessageBox::accept);
                        msgBoxNCD.show();
                        Ctime = 0;
                     } }); });
      // QObject::connect(&ier[i], &QTimer::timeout, [=]() mutable
      //                  {
      //                     displayChar[i]++; }); });
   }
   return;
}
