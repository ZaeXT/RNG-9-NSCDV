//
// Created by Akaze Kaziha on 2024/8/1.
//

#include "../include/displayWidget.h"
#include "../include/operationWidget.h"

extern QString displayName;

displayWidget::displayWidget(QWidget *parent) : QWidget(parent) {
    operationWidget *opWidget = new operationWidget(this);
    connect(opWidget, &operationWidget::executeSingleShots, this, &displayWidget::onExecuteSingleShot);
    connect(opWidget, &operationWidget::executeTenShots, this, &displayWidget::onExecuteTenShots);
    connect(opWidget, &operationWidget::executeCustomShots, this, &displayWidget::onExecuteCustomShots);
};

void displayWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QSize size = this->size();
    int fontSize = size.height() * 0.5;
    QFont font = painter.font();
    font.setPointSize(fontSize);
    painter.setFont(font);
    painter.drawText(QRect(0, 0, size.width(), size.height()), Qt::AlignCenter, displayName);
}

void displayWidget::resizeEvent(QResizeEvent *event) {
    Q_UNUSED(event);
    update();
}

void displayWidget::onExecuteSingleShot() {

}

void displayWidget::onExecuteTenShots() {

}

void displayWidget::onExecuteCustomShots() {

}