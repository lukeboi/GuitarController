#include "midihandler.h"
#include <QDebug>

midiHandler::midiHandler(QObject *parent) : QObject(parent)
{

}

QString midiHandler::filePath()
{
    return m_filePath;
}

void midiHandler::setFilePath(const QString &filePath)
{
    if (filePath == m_filePath)
        return;

    m_filePath = filePath;
    qInfo("Hello from midi class");
    emit filePathChanged();
}
