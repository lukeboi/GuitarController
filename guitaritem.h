#ifndef GUITARITEM_H
#define GUITARITEM_H

#include <QObject>

class guitarItem : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int note READ note WRITE setNote NOTIFY noteChanged)
public:
    explicit guitarItem(QObject *parent = nullptr);
    explicit guitarItem(const QString &name, const int &note, QObject *parent = nullptr);

    QString name();
    void setName(const QString &name);

    int note();
    void setNote(const int &note);
signals:
    void nameChanged();
    void noteChanged();

private:
    QString m_name;
    int m_note;
};

#endif // GUITARITEM_H
