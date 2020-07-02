#include "guitaritem.h"

guitarItem::guitarItem(QObject *parent) : QObject(parent)
{

}

guitarItem::guitarItem(const QString &name, const int &note, QObject *parent) : QObject(parent), m_name(name), m_note(note)
{

}

QString guitarItem::name()
{
    return m_name;
}

int guitarItem::note()
{
    return m_note;
}

void guitarItem::setName(const QString &name)
{
    if (name == m_name) //make sure it isn't a duplicate
        return;

    m_name = name;

    emit nameChanged();
}

void guitarItem::setNote(const int &note)
{
    if (note == m_note) //make sure it isn't a duplicate
        return;

    m_note = note;

    emit noteChanged();
}
