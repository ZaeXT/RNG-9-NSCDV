//
// Created by Akaze Kaziha on 2024/8/1.
//

#include "../include/operationWidget.h"
#include "../include/displayWidget.h"

operationWidget::operationWidget(QWidget *parent) : QWidget(parent) {
    setupWidget();
    //connect(this, &QWidget::resizeEvent, this, &operationWidget::resizeEvent);
}

void operationWidget::resizeEvent(QResizeEvent *event) {
    Q_UNUSED(event);
    adjustFontSize();
}

void operationWidget::setupWidget() {
    layout = new QVBoxLayout(this);
    singleShot = new QPushButton("单抽", this);
    tenShot = new QPushButton("十连", this);
    customShot = new QPushButton("自定义", this);
    layout->addWidget(singleShot);
    layout->addWidget(tenShot);
    layout->addWidget(customShot);

    connect(singleShot, &QPushButton::clicked, [=]() {
        emit executeSingleShots();
    });
    connect(tenShot, &QPushButton::clicked, [=]() {
        emit executeTenShots();
    });
    connect(customShot, &QPushButton::clicked, [=]() {
        emit executeCustomShots();
    });

    setLayout(layout);
    adjustFontSize();
}

void operationWidget::adjustFontSize() {
    int fontSize = height() * 0.1;
    QFont font = this->font();
    font.setPointSize(fontSize);

    singleShot->setFont(font);
    tenShot->setFont(font);
    customShot->setFont(font);
}