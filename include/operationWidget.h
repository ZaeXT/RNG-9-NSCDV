//
// Created by Akaze Kaziha on 2024/8/1.
//
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFont>

#ifndef RNG_9_NSCDV_OPERATIONWIDGET_H
#define RNG_9_NSCDV_OPERATIONWIDGET_H


class operationWidget : public QWidget {
Q_OBJECT

signals:

    void executeSingleShots();

    void executeTenShots();

    void executeCustomShots();

public:
    explicit operationWidget(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QPushButton *singleShot;
    QPushButton *tenShot;
    QPushButton *customShot;
    QVBoxLayout *layout;

    void setupWidget();

    void adjustFontSize();
};


#endif //RNG_9_NSCDV_OPERATIONWIDGET_H
