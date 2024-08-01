//
// Created by Akaze Kaziha on 2024/8/1.
//
#include <QWidget>
#include <QPainter>
#include <QResizeEvent>

#ifndef RNG_9_NSCDV_DISPLAYWIDGET_H
#define RNG_9_NSCDV_DISPLAYWIDGET_H


class displayWidget : public QWidget {
Q_OBJECT

public:
    explicit displayWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;


public slots:

    void onExecuteSingleShot();

    void onExecuteTenShots();

    void onExecuteCustomShots();
};


#endif //RNG_9_NSCDV_DISPLAYWIDGET_H
