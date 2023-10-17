# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'U03.ui'
##
## Created by: Qt User Interface Compiler version 6.5.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWebEngineWidgets import QWebEngineView
from PySide6.QtWidgets import (QApplication, QMainWindow, QPlainTextEdit, QPushButton,
    QSizePolicy, QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(678, 358)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.TextEdit = QPlainTextEdit(self.centralwidget)
        self.TextEdit.setObjectName(u"TextEdit")
        self.TextEdit.setGeometry(QRect(10, 10, 201, 221))
        self.button = QPushButton(self.centralwidget)
        self.button.setObjectName(u"button")
        self.button.setGeometry(QRect(60, 260, 101, 41))
        self.webview = QWebEngineView(self.centralwidget)
        self.webview.setObjectName(u"webview")
        self.webview.setGeometry(QRect(240, 10, 421, 321))
        self.webview.setUrl(QUrl(u"about:blank"))
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"\u85aa\u8d44\u7edf\u8ba1", None))
#if QT_CONFIG(tooltip)
        self.TextEdit.setToolTip(QCoreApplication.translate("MainWindow", u"<html><head/><body><p>\u8bf7\u8f93\u5165\u85aa\u8d44</p><p><br/></p></body></html>", None))
#endif // QT_CONFIG(tooltip)
        self.TextEdit.setPlainText("")
        self.TextEdit.setPlaceholderText(QCoreApplication.translate("MainWindow", u"\u8bf7\u8f93\u5165\u85aa\u8d44", None))
        self.button.setText(QCoreApplication.translate("MainWindow", u"\u5f00\u59cb\u7edf\u8ba1", None))
    # retranslateUi

