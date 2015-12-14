#include "VoiceMsgContent.h"

VoiceMsgContent::VoiceMsgContent()
{

}

VoiceMsgContent::VoiceMsgContent(QString &content, QWidget *parent)
{
    this->setParent(parent);
    this->m_content = content;
}

void VoiceMsgContent::readjuestSizeWithParentWidget()
{

}
