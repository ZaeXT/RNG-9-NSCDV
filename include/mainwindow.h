#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QWidgetAction>
#include <QCheckBox>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QVector>
#include <QActionGroup>
#include <QVBoxLayout>
#include <QPainter>
#include <QResizeEvent>
#include <QDebug>
#include <QPoint>

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    const float minRatio = 0.8;
private slots:

    void getList();
};

#endif // MAINWINDOW_H
