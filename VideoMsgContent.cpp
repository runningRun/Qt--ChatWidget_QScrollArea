#include "VideoMsgContent.h"

VideoMsgContent::VideoMsgContent()
{

}

VideoMsgContent::VideoMsgContent(QString &content, QWidget *parent)
{
    this->setParent(parent);
    this->m_content = content;
}

void VideoMsgContent::readjuestSizeWithParentWidget()
{

}
