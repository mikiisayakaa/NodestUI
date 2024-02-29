#pragma once

#include "Extension/abstractextension.h"

namespace Nodest{

enum class ExtensionType;

class ExtensionFactory
{
public:
    ExtensionFactory();

    static AbstractExtension* createExtension(ExtensionType type, QObject* parent);
};

}
