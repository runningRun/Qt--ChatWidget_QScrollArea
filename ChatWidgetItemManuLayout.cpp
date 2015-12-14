#include "ChatWidgetItemManuLayout.h"
#include "XMLDataParse.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>
#include "TextMsgContent.h"
#include "VoiceMsgContent.h"
#include "VideoMsgContent.h"
#include "ImageMsgContent.h"

const QString ChatWidgetItemManuLayout::styleSheetStr = "";

//构造、析构函数
#if DE_CONSTRUCT_FUNCTIONS

ChatWidgetItemManuLayout::ChatWidgetItemManuLayout(QWidget *parent) : QWidget(parent)
{

}

ChatWidgetItemManuLayout::ChatWidgetItemManuLayout(QPixmap *headPixmap, const QString &nickName, MSGTYPE msgtype, QString msgContent, bool isFromAgent, QWidget *parent) :
    QWidget(parent),
    m_rightFlag(isFromAgent)
{
    qDebug() << "ChatWidgetItemManuLayout::ChatWidgetItemManuLayout, Parent size:" << this->parentWidget()->size();

    int headPixmapX, headPixmapY;
    int nickNameX, nickNameY;
    int msgContentX, msgContentY;

    this->m_pHeadPixLabel = new QLabel(this);
    this->m_pHeadPixLabel->setPixmap((*headPixmap));
    this->m_pHeadPixLabel->setFixedSize(HEAD_PIXMAP_WIDTH, HEAD_PIXMAP_HEIGHT);

    this->m_pNickNameLabel = new QLabel(nickName, this);
    this->m_pNickNameLabel->adjustSize();

    this->setAutoFillBackground(true);
    this->setStyleSheet(ChatWidgetItemManuLayout::styleSheetStr);

    if (NULL != this->parentWidget())
    {
        this->setFixedWidth(this->parentWidget()->width() - (2 * CHILD_LAYOUT_MARGIN) - (2 * LINE_WIDTH) );
    }
    switch (msgtype) {
    case TEXT:
        this->m_pMsgContent = new TextMsgContent(msgContent, this);
        break;
    case VOICE:
        this->m_pMsgContent = new VoiceMsgContent(msgContent, this);
        break;
    case VIDEO:
        this->m_pMsgContent = new VideoMsgContent(msgContent, this);
        break;
    case PICTURE:
        this->m_pMsgContent = new ImageMsgContent(msgContent, this);
        break;
    default:
        break;
    }

    if (isFromAgent)
    {
        //消息来自坐席
        this->m_pNickNameLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

        headPixmapX = this->width() - m_pHeadPixLabel->width() - 5;
        headPixmapY = 5;

        nickNameX = headPixmapX - m_pNickNameLabel->width() - 3;
        nickNameY = 5;

        msgContentX = headPixmapX - m_pMsgContent->width();
        msgContentY = nickNameY + m_pNickNameLabel->width() + 3;
    }
    else
    {
        this->m_pNickNameLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    }

    this->m_pHeadPixLabel->setGeometry(headPixmapX, headPixmapY, this->m_pHeadPixLabel->sizeHint().width(), this->m_pHeadPixLabel->sizeHint().height());
    this->m_pNickNameLabel->setGeometry(nickNameX, nickNameY, this->m_pNickNameLabel->sizeHint().width(), this->m_pHeadPixLabel->sizeHint().height());
    this->m_pMsgContent->setGeometry(msgContentX, msgContentY, this->m_pMsgContent->sizeHint().width(), this->m_pMsgContent->sizeHint().height());

    this->m_pHeadPixLabel->show();
    this->m_pNickNameLabel->show();
    this->m_pMsgContent->show();
    this->setFixedSize(this->sizeHint());
    this->show();

    qDebug() << "ChatWidgetItemManuLayout::ChatWidgetItemManuLayout, size:" << this->parentWidget()->size();
    qDebug() << "ChatWidgetItemManuLayout::ChatWidgetItemManuLayout, size after sizeHint:" << this->parentWidget()->size();
}

ChatWidgetItemManuLayout::~ChatWidgetItemManuLayout()
{

}

#endif //DE_CONSTRUCT_FUNCTIONS

