#include "ScrollArea.h"
#include "ui_ScrollArea.h"
#include <QSizePolicy>

ScrollArea::ScrollArea(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::ScrollArea)
{
    ui->setupUi(this);
    ui->scrollAreaWidgetContents->setMinimumSize(120, 120);
    ui->scrollAreaWidgetContents->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    int i;
    QString str("pushButton %1");
    for (i=0; i<10; ++i)
    {
        ui->verticalLayout->addWidget(new QPushButton(str.arg(i+1), ui->widget));
    }
    ui->verticalLayout->setSizeConstraint(QVBoxLayout::SetMinAndMaxSize);

}

ScrollArea::~ScrollArea()
{
    delete ui;
}
