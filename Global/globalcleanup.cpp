#include <QObject>

#include "globalcleanup.h"
#include "globalitems.h"
#include "Interface/abstractgraphobject.h"
#include "Interface/abstractnodeobject.h"

void NodestGlobal::cleanupGraph()
{
    delete NodestGlobal::globalGraphObject;
}

