#include "Backend.h"

// 如果在构造函数中不需要特殊处理，可保持默认
// Backend::Backend(QObject *parent) : QObject(parent), m_counter(0) {}

int Backend::counter() const
{
    return m_counter;
}



void Backend::increment() {
    // 逻辑处理
    m_counter++;

    // 必须发送信号，否则 QML 界面不会感知到数值变化
    emit counterChanged();
}

void Backend::decrement()
{
    // 逻辑处理
    m_counter--;

    // 必须发送信号，否则 QML 界面不会感知到数值变化
    emit counterChanged();
}
