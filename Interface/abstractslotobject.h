#pragma once

#include <QObject>
#include <QQuickItem>

#include "Core/abstractslot.h"

namespace Nodest{

class AbstractSlotObject : public QObject
{
    Q_OBJECT
public:
    explicit AbstractSlotObject(AbstractSlot* slot, QObject *parent = nullptr);

    virtual ~AbstractSlotObject() {}

    virtual void createWidgets() = 0;

    virtual void bindWidgets() = 0;

    virtual void setWidgetsLayout() = 0;

    AbstractSlot* getSlot() const {return m_slot;}

    QQuickItem* getItem(int index) const {return m_items[index];}

signals:

public slots:

protected:
    AbstractSlot* m_slot;

    std::vector<QQuickItem*> m_items;
};

}