#ifndef GUITAROBJECT_H
#define GUITAROBJECT_H

#include <QObject>

class GuitarObject : public QObject
{
    Q_OBJECT
public:
    explicit GuitarObject(QObject *parent = nullptr);

signals:

};

#endif // GUITAROBJECT_H
