#include "TextMsgContent.h"
#include "globalvar.h"
#include <QPaintEvent>
#include <QGridLayout>
#include <QLabel>
#include <QResizeEvent>
#include <QDebug>

//构造析构函数区
#if DE_CONSTRUCT_FUNCTIOINS

TextMsgContent::TextMsgContent(QString &content, QWidget *parent)
{
    this->setParent(parent);
    this->m_styleSheetStr = "border:2px groove green;border-radius:10px;padding:2px 4px;";
    this->m_pContentLabel = new QLabel(this);
    this->m_content = content;
    initContentLabel();
}

#endif  //DE_CONSTRUCTION_FUNCTIONS

//public访问权限函数
#if PUBLIC_FUNCTIONS

void TextMsgContent::readjuestSizeWithParentWidget()
{
    changeSizeWidthParentWidget();
}

#endif  //PUBLIC_FUNCTIONS

//protected访问权限函数
#if PROTECTED_FUNCTIONS

void TextMsgContent::initContentLabel()
{
    qDebug() << "TextMsgContent::initContentLabel, Parent" << this->parentWidget() <<" size:" <<this->parentWidget()->size();
    this->m_pContentLabel->setStyleSheet(this->m_styleSheetStr);
    this->m_pContentLabel->setText(this->m_content);
    changeSizeWidthParentWidget();
}

void TextMsgContent::changeSizeWidthParentWidget()
{
    /*
     * zwl 2015.12.10
     * 这里TextMsgContent的宽度不但要减去边框的空白，还是减去头像的宽度
     * 因为ChatWidgetItem中包含headPixmap、NickName、msgContent
     */

    this->m_pContentLabel->setMaximumWidth(
                this->parentWidget()->width() - HEAD_PIXMAP_WIDTH
                - CHILD_LAYOUT_MARGIN * 2 - LAYOUT_SPACING - LINE_WIDTH * 2);

    QFontMetrics tmpFontMetrics = this->fontMetrics();
    int lineleading = tmpFontMetrics.leading();
    int linesCount = tmpFontMetrics.width(this->m_content) / this->m_pContentLabel->maximumWidth() + 1;
    int totalLineLeading = lineleading * (linesCount - 1);
    int lineHeight = tmpFontMetrics.height();
    int totalLineHeight = linesCount * lineHeight;
    int totalHeight = this->m_pContentLabel->contentsMargins().top()
                        + this->m_pContentLabel->contentsMargins().bottom()
                        + totalLineLeading + totalLineHeight;
    this->m_pContentLabel->setFixedHeight(totalHeight);

    if (fontMetrics().width(this->m_content) > this->m_pContentLabel->maximumWidth())
    {
        this->m_pContentLabel->setFixedWidth(this->m_pContentLabel->maximumWidth());
        this->m_pContentLabel->setWordWrap(true);
    }
    else
    {

    }
    this->m_pContentLabel->adjustSize();
    this->m_pContentLabel->setFixedSize(this->m_pContentLabel->sizeHint());
    this->m_pContentLabel->setGeometry(0, 0, this->m_pContentLabel->size().width(), this->m_pContentLabel->size().height());
    this->setFixedSize(this->m_pContentLabel->size());


    qDebug() << "TextMsgContent::changeSizeWidthParentWidget, Parent " << this->parentWidget() <<" size:" <<this->parentWidget()->size();
    qDebug() << "TextMsgContent::changeSizeWidthParentWidget, Size: " << this->size();
}

#endif  //PROTECTED_FUNCTIONS

//重写事件函数区
#if EVENT_FUNCTIONS

void TextMsgContent::paintEvent(QPaintEvent *paintEvent)
{
    this->m_pContentLabel->setMaximumWidth(this->width());
    this->m_pContentLabel->clear();
    this->m_pContentLabel->setText(this->m_content);
    this->m_pContentLabel->adjustSize();
}

void TextMsgContent::resizeEvent(QResizeEvent *resizeEvent)
{/*
    qDebug() << "TextMsgContent::resizeEvent, old size" << resizeEvent->oldSize();
    qDebug() << "TextMsgContent::resizeEvent, new size" << resizeEvent->size();

    this->m_pContentLabel->setMaximumWidth(resizeEvent->size().width());
    this->m_pContentLabel->adjustSize();

    if (fontMetrics().width(this->m_content) > this->m_pContentLabel->maximumWidth())
    {
        this->m_pContentLabel->setFixedWidth(this->m_pContentLabel->maximumWidth());
        this->m_pContentLabel->setWordWrap(true);
    }

    this->m_pContentLabel->setFixedSize(this->m_pContentLabel->sizeHint());
    this->setFixedSize(this->m_pContentLabel->sizeHint());

    qDebug() << "TextMsgContent::resizeEvent, size" << this->size();*/
}

#endif  //EVENT_FUNCTIONS
