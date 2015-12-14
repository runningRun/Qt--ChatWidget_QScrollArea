/*
 * zwl 2015.12.09
 * 该类是ChatWidget的条目类，
 * 该类封装了头像、昵称以及消息内容等
 * 在创建该类的对象时，通过对rawData解析，能够解析出消息的发出者、消息类别(文本、语音、视频、图片)、消息内容
 * 并且根据消息类别，来自动创建不同的控件(TextMsgContent、VoiceMsgContent、VideoMsgContent、ImageMsgContent)
 * 如果消息来自坐席，则使用伪右对齐，
 * 如果消息来自客户，则使用伪左对齐
 */

#ifndef CHATWIDGETITEM_H
#define CHATWIDGETITEM_H
#include <QWidget>
#include "globalvar.h"

#define DE_CONSTRUCT_FUNCTIONS          1
#define PROTECTED_FUCTIONS              1

#define MARGIN                          5

class QLabel;
class MsgContent;
class QPixMap;
class QBoxLayout;
class QGridLayout;

class ChatWidgetItemManuLayout : public QWidget
{
    Q_OBJECT
public:
    explicit ChatWidgetItemManuLayout(QWidget *parent = 0);
    ChatWidgetItemManuLayout(QPixmap *headPixmap, const QString &nickName, MSGTYPE msgtype, QString msgContent, bool isFromAgent, QWidget *parent = 0);
    ~ChatWidgetItemManuLayout();

signals:

public slots:

protected:
    void initCWI();
    static const QString styleSheetStr;

private:
    bool m_rightFlag;            //用于标识在头像、昵称等控件在左边还是在右边，true表示在左边，false表示在右边
    QLabel *m_pHeadPixLabel;
    QLabel *m_pNickNameLabel;
    MsgContent *m_pMsgContent;
    QGridLayout *m_pRightLayout;
};

#endif // CHATWIDGETITEM_H
