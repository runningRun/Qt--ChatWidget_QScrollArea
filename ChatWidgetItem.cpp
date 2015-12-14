#include "ChatWidgetItem.h"
#include "XMLDataParse.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QResizeEvent>
#include <QDebug>
#include "TextMsgContent.h"
#include "VoiceMsgContent.h"
#include "VideoMsgContent.h"
#include "ImageMsgContent.h"

const QString ChatWidgetItem::styleSheetStr = "";

//构造、析构函数
#if DE_CONSTRUCT_FUNCTIONS

ChatWidgetItem::ChatWidgetItem(QWidget *parent) : QWidget(parent)
{

}

ChatWidgetItem::ChatWidgetItem(QPixmap *headPixmap, const QString &nickName, MSGTYPE msgtype, QString msgContent, bool isFromAgent, QWidget *parent) :
    QWidget(parent),
    m_rightFlag(isFromAgent)
{
    qDebug() << "ChatWidgetItem::ChatWidgetItem, Parent size:" << this->parentWidget()->size();
    if (NULL != this->parentWidget())
    {
        this->setFixedWidth(this->parentWidget()->width() - (2 * CHILD_LAYOUT_MARGIN) - (2 * LINE_WIDTH));
    }

    this->m_pHeadPixLabel = new QLabel(this);
    this->m_pHeadPixLabel->setPixmap((*headPixmap));
    this->m_pHeadPixLabel->setFixedSize(HEAD_PIXMAP_WIDTH, HEAD_PIXMAP_HEIGHT);

    this->m_pNickNameLabel = new QLabel(nickName, this);
    this->m_pNickNameLabel->adjustSize();

    this->m_pMainLayout = new QHBoxLayout(this);
    this->m_pMainLayout->setMargin(CHILD_LAYOUT_MARGIN);
    this->m_pMainLayout->setSpacing(LAYOUT_SPACING);

    this->m_pHeadPixLayout = new QHBoxLayout();
    this->m_pHeadPixLayout->setMargin(0);
    this->m_pHeadPixLayout->setSpacing(0);

    this->m_pRightLayout = new QGridLayout();
    this->m_pRightLayout->setMargin(0);
    this->m_pRightLayout->setSpacing(0);

    this->setAutoFillBackground(true);
    this->setStyleSheet(ChatWidgetItem::styleSheetStr);

    qDebug() << "ChatWidgetItem::ChatWidgetItem, " << this << " after this->setFixedWidth() size:" << this->size();
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

    this->m_pHeadPixLayout->addWidget(this->m_pHeadPixLabel);
    if (isFromAgent)
    {
        //消息来自坐席
        this->m_pNickNameLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        this->m_pRightLayout->addWidget(this->m_pNickNameLabel, 1, 1, 1, 1, Qt::AlignRight);
        this->m_pRightLayout->addWidget(this->m_pMsgContent, 2, 1, 1, 1, Qt::AlignRight);
        this->m_pMainLayout->addLayout(this->m_pRightLayout);
        this->m_pMainLayout->addLayout(this->m_pHeadPixLayout);
    }
    else
    {
        this->m_pNickNameLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        this->m_pRightLayout->addWidget(this->m_pNickNameLabel, 1, 1, 1, 1, Qt::AlignLeft);
        this->m_pRightLayout->addWidget(this->m_pMsgContent, 2, 1, 1, 1, Qt::AlignLeft);
        this->m_pMainLayout->addLayout(this->m_pHeadPixLayout);
        this->m_pMainLayout->addLayout(this->m_pRightLayout);
    }

    this->m_pMainLayout->setAlignment(this->m_pHeadPixLayout, Qt::AlignTop);
    this->setLayout(this->m_pMainLayout);
    this->setMinimumHeight(this->m_pMainLayout->sizeHint().height());
    this->setMaximumHeight(this->m_pMainLayout->sizeHint().height());

    qDebug() << "ChatWidgetItem::ChatWidgetItem, after create all component QWidget " << this << " size:" << this->size();
    qDebug() << "ChatWidgetItem::ChatWidgetItem, Parent" << this->parentWidget() << " after item create all components size:" << this->parentWidget()->size();
}

ChatWidgetItem::~ChatWidgetItem()
{

}

#endif //DE_CONSTRUCT_FUNCTIONS

//公有访问权限函数
#if PUBLIC_FUNCTIONS

void ChatWidgetItem::readjuestSizeWithParentWidget()
{
    qDebug() << "ChatWidgetItem::readjuestSizeWithParentWidget, Parent" << this->parentWidget() << "size:" << this->parentWidget()->size();
    qDebug() << "ChatWidgetItem::readjuestSizeWithParentWidget, " << this << " size:" << this->size();
    if (NULL != this->parentWidget())
    {
        this->setFixedWidth(this->parentWidget()->width() - (2 * CHILD_LAYOUT_MARGIN) - (2 * LINE_WIDTH));
    }
    this->m_pMsgContent->readjuestSizeWithParentWidget();

    this->setMinimumHeight(this->m_pMainLayout->sizeHint().height());
    this->setMaximumHeight(this->m_pMainLayout->sizeHint().height());

    qDebug() << "ChatWidgetItem::readjuestSizeWithParentWidget, " << this << " after readjuest the m_pMainLayout size:" << this->size();
}

#endif //PUBLIC_FUNCTIONS


//重写函数
#if REIMPLEMENT_EVENT_FUNCTIONS

void ChatWidgetItem::resizeEvent(QResizeEvent *)
{
    qDebug() << "ChatWidgetItem::resizeEvent, parent " << this->parentWidget() << "size()" << this->parentWidget()->size();
}

#endif //REIMPLEMENT_EVENT_FUNCTIONS
