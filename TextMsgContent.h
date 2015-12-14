#ifndef TEXTMSGCONTENT_H
#define TEXTMSGCONTENT_H

#define EVENT_FUNCTIONS         1
#define DE_CONSTRUCT_FUNCTIOINS 1
#define PUBLIC_FUNCTIONS        1
#define PROTECTED_FUNCTIONS     1
#define PRIVATE_FUNCTIONS       1

#define MARGIN                  5


#include "MsgContent.h"

class QVBoxLayout;
class QLabel;
class TextMsgContent : public MsgContent
{
public:
    TextMsgContent(QString &content, QWidget *parent = 0);
    void readjuestSizeWithParentWidget() override;
protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent*);

protected:
    void initContentLabel();
    void changeSizeWidthParentWidget();
private:
    QLabel *m_pContentLabel;
    QString m_styleSheetStr;
};

#endif // TEXTMSGCONTENT_H
