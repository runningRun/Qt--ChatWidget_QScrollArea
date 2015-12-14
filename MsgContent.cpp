#include "MsgContent.h"

MsgContent::MsgContent(QWidget *parent) :
    QWidget(parent)
{

}

MsgContent::MsgContent(QString content, QWidget *parent) :
    QWidget(parent)
{
    this->m_content = content;
}

