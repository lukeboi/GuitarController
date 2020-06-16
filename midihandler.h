#ifndef MIDIHANDLER_H
#define MIDIHANDLER_H

#include <qqml.h>
#include <QObject>
#include <QMidiOut.h>
#include <QMidiFile.h>

class MidiHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString filePath READ filePath WRITE setFilePath NOTIFY filePathChanged)
    QML_ELEMENT
public:
    explicit MidiHandler(QObject *parent = nullptr);

    QString filePath();
    void setFilePath(const QString &filePath);

signals:
    void filePathChanged();

private:
    QString m_filePath;
    QMidiFile* midiFile;
    void loadMidiFile();
};

#endif // MIDIHANDLER_H
