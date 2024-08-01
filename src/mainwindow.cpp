#include "../include/mainwindow.h"
#include "../include/displayWidget.h"
#include "../include/operationWidget.h"


extern QVector<QString> name;
extern bool UniqueFlag;

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent) {
    resize(230, 210);
    // 菜单栏
    QMenu *configMenu = menuBar()->addMenu("配置");
    QMenu *toolsMenu = menuBar()->addMenu("工具");
    // 配置菜单
    QAction *getList = new QAction("导入名单", this);
    QMenu *configUnique = new QMenu("去重");
    QAction *configAll = new QAction("设置", this);
    // 工具菜单
    QAction *listProcess = new QAction("名单处理", this);
    // 配置栏添加组件
    configMenu->addAction(getList);
    configMenu->addMenu(configUnique);
    configMenu->addAction(configAll);
    // 工具栏添加组件
    toolsMenu->addAction(listProcess);
    // 导入名单
    connect(getList, &QAction::triggered, this, &MainWindow::getList);
    // 去重
    // 用QActionGroup实现单选
    QActionGroup *uniqueGroup = new QActionGroup(this);
    uniqueGroup->setExclusive(true);
    // 创建两个选项
    QAction *uniqueEnable = new QAction("开启", this);
    QAction *uniqueDisable = new QAction("关闭", this);
    // 设置为可选
    uniqueEnable->setCheckable(true);
    uniqueDisable->setCheckable(true);
    // 默认
    uniqueDisable->setChecked(true);
    // 添加到QActionGroup
    uniqueGroup->addAction(uniqueEnable);
    uniqueGroup->addAction(uniqueDisable);
    // 添加到去重子菜单
    configUnique->addAction(uniqueEnable);
    configUnique->addAction(uniqueDisable);
    // 处理选择
    connect(uniqueEnable, &QAction::toggled, this, [=](bool checked) {
        if (checked) {
            UniqueFlag = true;
        }
    });
    connect(uniqueDisable, &QAction::toggled, this, [=](bool checked) {
        if (checked) {
            UniqueFlag = false;
        }
    });
    // 设置主界面
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *Vlayout = new QVBoxLayout(centralWidget);
    // 显示区
    displayWidget *dispWidget = new displayWidget(centralWidget);
    // 操作区
    operationWidget *operWidget = new operationWidget(centralWidget);

    Vlayout->addWidget(dispWidget);
    Vlayout->addWidget(operWidget);


}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QSize size = event->size();
    int newWidth = size.width();
    int newHeight = size.height();
    float curRatio = (float) newWidth / (float) newHeight;
    if (newWidth < 230) {
        newWidth = 230;
    }
    if (newHeight < 210) {
        newHeight = 210;
    }
    if (curRatio < minRatio) {
        newWidth = (int) (newHeight * minRatio);
        newHeight = newWidth / minRatio;
    }
    qDebug() << curRatio << " " << newWidth << " " << newHeight;
    resize(newWidth, newHeight);
    event->ignore();

}

void MainWindow::getList() {
    QString fileName = QFileDialog::getOpenFileName(this, "选择名单文件", ".", "文本文件(*.txt)");
    if (!fileName.isEmpty()) {
        QFile listFile(fileName);
        if (listFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream getInput(&listFile);
            while (!getInput.atEnd()) {
                QString line = getInput.readLine();
                name.push_back(line);
            }
            if (name.size() > 0) {
                QMessageBox::information(this, "成功", "名单导入成功", QMessageBox::Ok);
            } else {
                QMessageBox::information(this, "失败", "名单导入失败", QMessageBox::Ok);
            }
        } else {
            QMessageBox::information(this, "失败", "文件打开失败！", QMessageBox::Ok);
        }
    } else {
        QMessageBox::information(this, "失败", "请选择有效文件！", QMessageBox::Ok);
    }
}

MainWindow::~MainWindow() {
}

