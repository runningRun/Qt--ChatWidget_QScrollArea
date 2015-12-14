#include "ScrollAreaWidget.h"
#include "ui_ScrollAreaWidget.h"

ScrollAreaWidget::ScrollAreaWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScrollAreaWidget)
{
    ui->setupUi(this);
}

ScrollAreaWidget::~ScrollAreaWidget()
{
    delete ui;
}
