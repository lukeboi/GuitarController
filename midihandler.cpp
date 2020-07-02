#include "midihandler.h"
#include <QDebug>
#include <QObject>
#include <QStringRef>
#include <QDir>
#include <QMidiOut.h>
#include <QMidiFile.h>

MidiHandler::MidiHandler(QObject *parent) : QObject(parent)
{

}

QString MidiHandler::filePath()
{
    return m_filePath;
}

void MidiHandler::setFilePath(const QString &filePath)
{
    if (filePath == m_filePath) //make sure it isn't a duplicate
        return;

    m_filePath = filePath;

    if(!m_filePath.endsWith(".mid")) { //check to see if it's a midi file
        m_filePath = "Please Select a .mid file";
        return;
    }

    emit filePathChanged();

    loadMidiFile();
}

void MidiHandler::loadMidiFile() {
    //qInfo(m_filePath.toStdString().c_str());

    QDir thisDir = QDir::current();
    //qInfo(thisDir.absolutePath().toStdString().c_str());

    QString relativeFilePath = thisDir.relativeFilePath(
                m_filePath.right(m_filePath.size() - 8) //this removes the "file:///" from the start of the m_filePath
                );
    //qInfo(m_filePath.right(m_filePath.size() - 8).toStdString().c_str());
    qInfo(relativeFilePath.toStdString().c_str());

    midiFile = new QMidiFile;
    midiFile->load(relativeFilePath);

    QList<QMidiEvent*> events = midiFile->events();
    for (QMidiEvent* e : events) {
        if (e->type() != QMidiEvent::Meta) {
            int n = e->note();
            qInfo() << n; //QString::number(n).toStdString().c_str());
        }

    }

    qInfo("loaded");

}
