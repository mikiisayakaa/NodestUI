#pragma once

#include <QString>
#include <QByteArray>
#include <QHash>
#include <QSet>
#include <QQmlComponent>

#include <vector>
#include <utility>

namespace NodestGlobal{

struct setGetInfo{
    QQmlComponent* data;
    QString typeName;
};

extern QSet<QString> qmlFileNames;

extern QString slotHandleDefault;
extern QHash<QString, QQmlComponent*> slotHandleMap;

//filename and setter id
extern QSet<QString> slotSetterDefault;
extern QHash<QString, setGetInfo> slotSetterMap;

extern QSet<QString> slotGetterDefault;
extern QHash<QString, setGetInfo> slotGetterMap;

extern QString textLabelDefault;
extern QHash<QString, QQmlComponent*> textLabelMap;

extern QString nodeBaseDefault;
extern QHash<QString, QQmlComponent*> nodeBaseMap;

//used to take a place for missing getters and setters
extern QString dummyFile;
extern QQmlComponent* dummy;

//global background Rectangle for the node editor
extern QString backgroundFile;
extern QQmlComponent* bgd;

//only supports one kind of connection line for the whole graph
extern QString lineFile;
extern QQmlComponent* connectionLine;

}