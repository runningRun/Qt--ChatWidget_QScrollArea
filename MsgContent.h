#ifndef MSGCONTENT_H
#define MSGCONTENT_H

#include <QWidget>

class QLayout;
class MsgContent : public QWidget
{
    Q_OBJECT
public:
    explicit MsgContent(QWidget *parent = 0);
    MsgContent(QString content, QWidget *parent = 0);

    virtual void readjuestSizeWithParentWidget() = 0;

signals:

public slots:

protected:
    QString m_content;
    QLayout *m_pMainLayout;
};

#endif // MSGCONTENT_H
