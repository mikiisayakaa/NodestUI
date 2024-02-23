#pragma once

#include "Core/abstractboolevalnode.h"

#ifndef BOOLNODE
#define BOOLNODE(nodeName, funcName) \
    class nodeName : public Nodest::AbstractBoolEvalNode{ \
    public: \
        using FuncType = decltype (&funcName); \
        using TP = Nodest::TupleTypes<FuncType>; \
        using InArgsType = TP::InputArgumentTypes; \
         \
        nodeName(const nodeName& node) = delete; \
        explicit nodeName() : Nodest::AbstractBoolEvalNode(), m_func(funcName){ \
            m_nodeNameID = QString(#nodeName); \
            m_outValid = false; \
            constructImpl<FuncType>(); \
        } \
         \
        ~nodeName(){ \
            destruct<FuncType>(); \
        } \
        nodeName* clone() const { \
            nodeName* newNode = new nodeName(); \
            return newNode; \
        } \
         \
        void eval(){ \
            evalImpl<FuncType>(m_func); \
        } \
         \
        void setValue(int slotIndex, void* ptr){ \
            setValueImpl<FuncType>(slotIndex, ptr); \
        } \
        void bindSetter(QQuickItem* item, int index) { \
            bindInputSettersImpl<FuncType>(item, index); \
        } \
         \
    private: \
        FuncType m_func; \
    }; \

#endif
