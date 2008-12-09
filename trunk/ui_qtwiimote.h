/********************************************************************************
** Form generated from reading ui file 'qtwiimote.ui'
**
** Created: Wed Oct 22 18:06:21 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QTWIIMOTE_H
#define UI_QTWIIMOTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWiiMoteClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSlider *xAccel;
    QSlider *yAccel;
    QSlider *zAccel;
    QLabel *label_2;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout_3;
    QPushButton *connectButton;
    QLabel *connectLabel;
    QCheckBox *rumbleBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QSlider *pitchSlider;
    QSlider *rollSlider;

    void setupUi(QWidget *QtWiiMoteClass)
    {
    if (QtWiiMoteClass->objectName().isEmpty())
        QtWiiMoteClass->setObjectName(QString::fromUtf8("QtWiiMoteClass"));
    QtWiiMoteClass->resize(342, 281);
    verticalLayout = new QVBoxLayout(QtWiiMoteClass);
    verticalLayout->setSpacing(6);
    verticalLayout->setMargin(11);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setSpacing(6);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    label = new QLabel(QtWiiMoteClass);
    label->setObjectName(QString::fromUtf8("label"));

    verticalLayout_2->addWidget(label);

    xAccel = new QSlider(QtWiiMoteClass);
    xAccel->setObjectName(QString::fromUtf8("xAccel"));
    xAccel->setMaximum(500);
    xAccel->setOrientation(Qt::Horizontal);

    verticalLayout_2->addWidget(xAccel);

    yAccel = new QSlider(QtWiiMoteClass);
    yAccel->setObjectName(QString::fromUtf8("yAccel"));
    yAccel->setMaximum(500);
    yAccel->setOrientation(Qt::Horizontal);

    verticalLayout_2->addWidget(yAccel);

    zAccel = new QSlider(QtWiiMoteClass);
    zAccel->setObjectName(QString::fromUtf8("zAccel"));
    zAccel->setMaximum(500);
    zAccel->setOrientation(Qt::Horizontal);

    verticalLayout_2->addWidget(zAccel);

    label_2 = new QLabel(QtWiiMoteClass);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    verticalLayout_2->addWidget(label_2);

    graphicsView = new QGraphicsView(QtWiiMoteClass);
    graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

    verticalLayout_2->addWidget(graphicsView);


    horizontalLayout->addLayout(verticalLayout_2);

    verticalLayout_3 = new QVBoxLayout();
    verticalLayout_3->setSpacing(6);
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    connectButton = new QPushButton(QtWiiMoteClass);
    connectButton->setObjectName(QString::fromUtf8("connectButton"));

    verticalLayout_3->addWidget(connectButton);

    connectLabel = new QLabel(QtWiiMoteClass);
    connectLabel->setObjectName(QString::fromUtf8("connectLabel"));

    verticalLayout_3->addWidget(connectLabel);

    rumbleBox = new QCheckBox(QtWiiMoteClass);
    rumbleBox->setObjectName(QString::fromUtf8("rumbleBox"));

    verticalLayout_3->addWidget(rumbleBox);

    checkBox = new QCheckBox(QtWiiMoteClass);
    checkBox->setObjectName(QString::fromUtf8("checkBox"));

    verticalLayout_3->addWidget(checkBox);

    checkBox_2 = new QCheckBox(QtWiiMoteClass);
    checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

    verticalLayout_3->addWidget(checkBox_2);

    line = new QFrame(QtWiiMoteClass);
    line->setObjectName(QString::fromUtf8("line"));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    verticalLayout_3->addWidget(line);

    verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_3->addItem(verticalSpacer);


    horizontalLayout->addLayout(verticalLayout_3);

    pitchSlider = new QSlider(QtWiiMoteClass);
    pitchSlider->setObjectName(QString::fromUtf8("pitchSlider"));
    pitchSlider->setMinimum(-180);
    pitchSlider->setMaximum(180);
    pitchSlider->setOrientation(Qt::Vertical);

    horizontalLayout->addWidget(pitchSlider);


    verticalLayout->addLayout(horizontalLayout);

    rollSlider = new QSlider(QtWiiMoteClass);
    rollSlider->setObjectName(QString::fromUtf8("rollSlider"));
    rollSlider->setMinimum(-180);
    rollSlider->setMaximum(180);
    rollSlider->setOrientation(Qt::Horizontal);

    verticalLayout->addWidget(rollSlider);


    retranslateUi(QtWiiMoteClass);

    QMetaObject::connectSlotsByName(QtWiiMoteClass);
    } // setupUi

    void retranslateUi(QWidget *QtWiiMoteClass)
    {
    QtWiiMoteClass->setWindowTitle(QApplication::translate("QtWiiMoteClass", "QtWiiMote", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("QtWiiMoteClass", "Accelerometers", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("QtWiiMoteClass", "Infra-Red", 0, QApplication::UnicodeUTF8));
    connectButton->setText(QApplication::translate("QtWiiMoteClass", "Connect", 0, QApplication::UnicodeUTF8));
    connectLabel->setText(QString());
    rumbleBox->setText(QApplication::translate("QtWiiMoteClass", "Rumble", 0, QApplication::UnicodeUTF8));
    checkBox->setText(QApplication::translate("QtWiiMoteClass", "IR", 0, QApplication::UnicodeUTF8));
    checkBox_2->setText(QApplication::translate("QtWiiMoteClass", "Acc", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(QtWiiMoteClass);
    } // retranslateUi

};

namespace Ui {
    class QtWiiMoteClass: public Ui_QtWiiMoteClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIIMOTE_H
