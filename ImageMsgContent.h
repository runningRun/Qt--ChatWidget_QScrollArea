#ifndef IMAGEMSGCONTENT_H
#define IMAGEMSGCONTENT_H
#include "MsgContent.h"

class ImageMsgContent : public MsgContent
{
public:
    ImageMsgContent();
    ImageMsgContent(QString &content, QWidget* parent = 0);

    void readjuestSizeWithParentWidget() override;
};

#endif // IMAGEMSGCONTENT_H
