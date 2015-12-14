#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include "ChatList.h"

class ChatWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChatWidget(QWidget *parent = 0);

signals:

public slots:

private:
    QList<ChatList*> *m_pHistoryChatWidgetList;
};

#endif // CHATWIDGET_H
