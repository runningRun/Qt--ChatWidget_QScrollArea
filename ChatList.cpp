#include "ChatList.h"
#include "ChatWidgetItem.h"

#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QPixmap>
#include <QCheckBox>
#include <QScrollBar>
#include <QResizeEvent>
#include <QDebug>

#if DE_CONSTRUCT_FUNCTIONS
ChatList::ChatList(QWidget *parent) : QWidget(parent)
{
    this->m_pInputWidget = new QWidget();
    this->m_pInputWidget->setWindowTitle("输入框");

    this->m_pInputWidgetTextEdit = new QTextEdit("Hello QLineEdit Hello QLineEdit 接天莲叶无穷碧，映日荷花别样红", this->m_pInputWidget);
    this->m_pInputWidgetLayout = new QVBoxLayout(this->m_pInputWidget);
    this->m_pInputWidgetButton = new QPushButton("发送", this->m_pInputWidget);
    this->m_pInputWidgetCheckBox = new QCheckBox("坐席", this->m_pInputWidget);

    this->m_pInputWidgetButton->setFixedSize(this->m_pInputWidgetButton->sizeHint());
    connect(this->m_pInputWidgetButton, SIGNAL(clicked(bool)),
            this, SLOT(btnClicked(bool)));

    this->m_pInputWidgetLayout->addWidget(this->m_pInputWidgetButton);
    this->m_pInputWidgetLayout->addWidget(this->m_pInputWidgetCheckBox);
    this->m_pInputWidgetLayout->addWidget(this->m_pInputWidgetTextEdit);
    QPushButton *btn;
    this->m_pInputWidgetLayout->addWidget(btn = new QPushButton("按钮2", this));
    connect(btn, SIGNAL(clicked(bool)),
            this, SLOT(btn2Clicked(bool)));


    this->m_pInputWidget->setLayout(this->m_pInputWidgetLayout);
    this->m_pInputWidget->show();

    this->m_pItemList = new QList<ChatWidgetItem*> ();
    initComponent();
}

ChatList::~ChatList()
{
    delete m_pChatListScrollArea;
}

#endif  //DE_CONSTRUCT_FUNCTIONS

//重写事件函数
#ifdef REIMPLEMENT_EVENT_FUNCTIONS

void ChatList::resizeEvent(QResizeEvent *resizeEvent)
{

    m_pScrollWidget->setFixedWidth(this->m_pChatListScrollArea->width() - 20);

    QList<ChatWidgetItem*>::Iterator beginIter = this->m_pItemList->begin();
    for (; beginIter != this->m_pItemList->end(); ++beginIter)
    {
        (*beginIter)->readjuestSizeWithParentWidget();
        qDebug() << "ChatList::resizeEvent item" << *beginIter << " after readjuestSizeWithParentWidget() size: " << (*beginIter)->size();
    }

    qDebug() << "ChatList::resizeEvent ScrollWidget " << this->m_pScrollWidget << "size: " << this->m_pScrollWidget->size();
    qDebug() << "ChatList::resizeEvent ScrollArea size: " << this->m_pChatListScrollArea->size();
    qDebug() << "ChatList::resizeEvent " << this << "size: " << this->size();

}

#endif //REIMPLEMENT_EVENT_FUNCTIONS

#if PRIVATE_FUNCTIONS

void ChatList::initComponent()
{
    this->m_pChatListScrollArea = new QScrollArea(this);
    this->m_pChatListScrollArea->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    this->m_pChatListScrollArea->setWidgetResizable(true);

    this->m_pMainLayout = new QVBoxLayout(this);
    this->m_pMainLayout->setMargin(LAYOUT_MARGIN);
    m_pMainLayout->addWidget(this->m_pChatListScrollArea);
    this->setLayout(m_pMainLayout);

    this->m_pSCVLayout = new QVBoxLayout();
    this->m_pSCVLayout->setMargin(CHILD_LAYOUT_MARGIN);
    this->m_pSCVLayout->setSizeConstraint(QVBoxLayout::SetFixedSize);

    m_pScrollWidget =this->m_pChatListScrollArea->widget();
    if (NULL == m_pScrollWidget)
    {
        m_pScrollWidget = new QWidget();
    }
    m_pScrollWidget->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Ignored));
    m_pScrollWidget->setFixedWidth(this->m_pChatListScrollArea->width() - 20);

    m_pScrollWidget->setLayout(this->m_pSCVLayout);
    this->m_pChatListScrollArea->setWidget(m_pScrollWidget);

    qDebug() << "ChatList::initComponent() size: " << this->size();
    qDebug() << "ChatList::initComponent() m_pScrollWidget" << this->m_pScrollWidget << " size: " << this->m_pScrollWidget->size();
}

#endif

#if PRIVATE_SLOTS

void ChatList::btnClicked(bool)
{
    static QPixmap *pixmap = new QPixmap("./res/agent.png");

    QString str = this->m_pInputWidgetTextEdit->toPlainText();
    ChatWidgetItem *newItem = new ChatWidgetItem(pixmap, QString("hello"), TEXT, str, this->m_pInputWidgetCheckBox->isChecked(), this->m_pScrollWidget);
    this->m_pSCVLayout->addWidget(newItem);
    this->m_pItemList->append(newItem);

}

void ChatList::btn2Clicked(bool)
{
    this->resize(this->width() + 2, this->height() + 1);
}

#endif  //PRIVATE_SLOTS
