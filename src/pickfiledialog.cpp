#include "pickfiledialog.h"
#include <QFileDialog>
#include <QWidget>

PickFileDialog::PickFileDialog(QObject* player) : m_player(player)
{

}

void PickFileDialog::openPickFileDialog()
{
    QString fileName = QFileDialog::getOpenFileName(0, "Open a video file", QDir::homePath());
    qDebug() << "fileName = " << fileName;

    // Invoke function change_video()
    QString returnedValue;
    QMetaObject::invokeMethod(m_player, "change_video",
            Q_RETURN_ARG(QString, returnedValue),
            Q_ARG(QString, fileName));
}
