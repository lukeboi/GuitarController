#ifndef MIDIHANDLER_H
#define MIDIHANDLER_H

#include <qqml.h>
#include <QObject>

class midiHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString filePath READ filePath WRITE setFilePath NOTIFY filePathChanged)
    QML_ELEMENT
public:
    explicit midiHandler(QObject *parent = nullptr);

    QString filePath();
    void setFilePath(const QString &filePath);

signals:
    void filePathChanged();

private:
    QString m_filePath;
};

#endif // MIDIHANDLER_H
