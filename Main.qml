import QtQuick
import QtQuick.Controls
import QmlCppIntegration  // 必须匹配 CMake 中的 URI

Window {
    width: 400
    height: 500
    visible: true
    title: "QML & C++ Integration"

    Column {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 15

        // 1. 单例 Backend 展示
        GroupBox {
            title: "Global Backend (Singleton)"
            width: parent.width
            Row {
                spacing: 20
                Text {
                    text: "Counter: " + Backend.counter
                    font.pixelSize: 18
                    anchors.verticalCenter: parent.verticalCenter
                }
                Button {
                    text: "Increment"
                    onClicked: Backend.increment()
                }
                Button {
                    text: "decrement"
                    onClicked: Backend.decrement()
                }
            }
        }

        // 2. DataModel 列表展示
        GroupBox {
            title: "Data List (QAbstractListModel)"
            width: parent.width
            height: 300

            Column {
                anchors.fill: parent
                spacing: 10

                ListView {
                    id: listView
                    width: parent.width
                    height: 200
                    clip: true
                    model: DataModel { id: myModel } // 实例化并命名 id

                    delegate: ItemDelegate {
                        width: listView.width
                        contentItem: Row {
                            spacing: 10
                            Text {
                                text: itemName  // 对应 C++ 中的 NameRole
                                width: 150
                            }
                            Button {
                                text: "Remove"
                                display: AbstractButton.TextOnly
                                onClicked: myModel.removeItem(index) // 调用 C++ removeItem
                            }
                        }
                    }
                }

                // 3. 添加数据的交互区域
                Row {
                    spacing: 10
                    width: parent.width
                    TextField {
                        id: inputField
                        placeholderText: "Enter name..."
                        width: 200
                    }
                    Button {
                        text: "Add Item"
                        enabled: inputField.text.length > 0
                        onClicked: {
                            myModel.addItem(inputField.text); // 调用 C++ addItem
                            inputField.clear();
                        }
                    }
                }
            }
        }
    }
}
