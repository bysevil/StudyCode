from PySide6.QtWidgets import QApplication,QMainWindow,QPlainTextEdit,QPushButton

app = QApplication([])


window = QMainWindow()

window.setWindowTitle("主窗口")
window.resize(300, 500)


textEdit = QPlainTextEdit(window)

textEdit.move(10, 10)
textEdit.resize(280, 430)


button = QPushButton("确定", window)

button.move(100, 460)
button.resize(100, 30)


window.show()

app.exec_()



