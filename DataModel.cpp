#include "DataModel.h"

// 返回行数
int DataModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) return 0;
    return m_items.size();
}

// 返回指定行和角色的数据
QVariant DataModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) return QVariant();

    int row = index.row();
    if (row < 0 || row >= m_items.size()) return QVariant();

    if (role == NameRole) {
        return m_items.at(row);
    }

    return QVariant();
}

// 定义在 QML 中访问的变量名
QHash<int, QByteArray> DataModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "itemName"; // QML 中通过 model.itemName 或 itemName 访问
    return roles;
}

// 示例：向模型添加数据的方法（需在头文件中声明为 Q_INVOKABLE）
void DataModel::addItem(const QString &name) {
    // 关键：通知视图即将插入行
    beginInsertRows(QModelIndex(), m_items.size(), m_items.size());
    m_items.append(name);
    endInsertRows(); // 关键：结束插入，View 会自动刷新
}

// 示例：从模型删除数据
void DataModel::removeItem(int index) {
    if (index < 0 || index >= m_items.size()) return;

    beginRemoveRows(QModelIndex(), index, index);
    m_items.removeAt(index);
    endRemoveRows();
}
