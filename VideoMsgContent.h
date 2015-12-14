#ifndef VIDEOMSGCONTENT_H
#define VIDEOMSGCONTENT_H
#include "MsgContent.h"

class VideoMsgContent : public MsgContent
{
public:
    VideoMsgContent();
    VideoMsgContent(QString &content, QWidget* parent = 0);

    void readjuestSizeWithParentWidget() override;
};

#endif // VIDEOMSGCONTENT_H
