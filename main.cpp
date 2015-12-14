#include "ChatList.h"
#include "ScrollArea.h"
#include "TextMsgContent.h"
#include <QApplication>
#include <QVBoxLayout>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

//    QWidget w;
//    ScrollArea scrollArea(&w);
//    QVBoxLayout vLayout(&w);
//    vLayout.addWidget(&scrollArea);
//    w.setLayout(&vLayout);
//    w.show();

    ChatList chatList;
    chatList.show();

    return app.exec();
}
