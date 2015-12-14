#ifndef SCROLLAREAWIDGET_H
#define SCROLLAREAWIDGET_H

#include <QWidget>

namespace Ui {
class ScrollAreaWidget;
}

class ScrollAreaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScrollAreaWidget(QWidget *parent = 0);
    ~ScrollAreaWidget();

private:
    Ui::ScrollAreaWidget *ui;
};

#endif // SCROLLAREAWIDGET_H
