#include "mainwindow.h"
#include <QApplication>
#include <QFont>
#include <QHBoxLayout>
#include <QLabel>
#include <QList>
#include <QMessageBox>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>

int IntervalScroll_ter = 50;
int IntervalScroll_ier = 1000;
bool ScrollFlag = true;
int displayChar = 0;
int mode = 0;
int Ctime = 0;
int timeOutMsg = 500;
int yuanshi = 114514;
QString name[] = {"巴雷!", "包宇恒", "陈晶晶", "陈佩琪", "黄彦玮", "姜王迪", "李精锐", "刘静雯", "刘周心", "柳子恒", "马佳豪", "马文军", "潘梓豪", "沈一!", "殳楷博", "王羽郴", "王哲宇", "吴国祥", "吴家兴", "肖曦文", "徐景飏", "徐秋雨", "杨坤元", "姚杭晨", "俞佳扬", "张弛斌", "张创!", "张帅!", "张天浩", "张鑫琳", "张伊靓", "张奕阳", "张宇喆", "钟韩易", "朱妍!", "朱钰欣", "朱正天"};

QString spacekey = " ";

int gen_rnd(int gen_min = 0, int gen_max = 36);

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   QWidget w;
   QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
   w.setSizePolicy(sizePolicy);
   QTimer ter, ier, mer;
   QList<QString> rndChar;
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
   int upch = 0;
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
   ter.setInterval(IntervalScroll_ter);
   ier.setInterval(IntervalScroll_ier);
   QMessageBox startMsg, msgBoxNCD, msgYuanNum;
   startMsg.setWindowTitle("Changelog");
   startMsg.setText("更新：\n1、文本居中\n2、添加十连（待完成");
   startMsg.show();
   msgBoxNCD.setText("触发保底！");
   // msgYuanNum.setText("您的缘不足！\n建议重开\n按确定重开");
   // msgYuanNum.setWindowTitle("缘石 OS");
   msgBoxNCD.setWindowTitle("NSCD OS");
   QMessageBox announce;
   announce.setText("在做了在做了（咕咕咕");
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
                        if (!name[upch].compare(QString("张弛斌")))
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
                     announce.show(); });
   // ter.start();
   // ier.start();
   w.show();
   return a.exec();
}
