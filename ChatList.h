#ifndef CHATLIST_H
#define CHATLIST_H

#include <QWidget>
#include "globalvar.h"

class QScrollArea;
class QVBoxLayout;
class QLabel;
class QTextEdit;
class QCheckBox;
class QPushButton;
class ChatWidgetItem;

class ChatList : public QWidget
{
    Q_OBJECT
public:
    explicit ChatList(QWidget *parent = 0);
    ~ChatList();

protected:
    void resizeEvent(QResizeEvent *);

private:
    void initComponent();

signals:

public slots:

private slots:
    void btnClicked(bool);
    void btn2Clicked(bool);
private:
    QScrollArea* m_pChatListScrollArea;
    QVBoxLayout* m_pSCVLayout;
    QVBoxLayout* m_pMainLayout;
    QLabel* m_pLabel;
    QWidget* m_pScrollWidget;
    QTextEdit* m_pTextEdit;
    QCheckBox* m_pisAgentCheckBox;
    ChatWidgetItem* m_pChatWidgetIemt;

    QWidget* m_pInputWidget;
    QTextEdit* m_pInputWidgetTextEdit;
    QVBoxLayout* m_pInputWidgetLayout;
    QPushButton* m_pInputWidgetButton;
    QCheckBox* m_pInputWidgetCheckBox;

    QList<ChatWidgetItem* > *m_pItemList;
};

#endif // CHATLIST_H
