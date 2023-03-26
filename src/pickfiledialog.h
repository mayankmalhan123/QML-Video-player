#ifndef PICKFILEDIALOG_H
#define PICKFILEDIALOG_H

#include <QObject>
#include <QQuickItem>
#include <QMediaPlayer>

class PickFileDialog : public QObject
{
    Q_OBJECT

    QObject* m_player;

public:
    PickFileDialog(QObject* player);
    void openPickFileDialog();

public slots:
    void changeVideoSlot() {
        openPickFileDialog();
    }
};

#endif // PICKFILEDIALOG_H
