#include "ImageMsgContent.h"

ImageMsgContent::ImageMsgContent()
{

}

ImageMsgContent::ImageMsgContent(QString &content, QWidget *parent)
{
    this->setParent(parent);
    this->m_content = content;
}

void ImageMsgContent::readjuestSizeWithParentWidget()
{

}
