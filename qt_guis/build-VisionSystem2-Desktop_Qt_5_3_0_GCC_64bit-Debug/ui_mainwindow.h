/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *mainHBoxLayout;
    QVBoxLayout *leftVBoxLayout;
    QTabWidget *leftTabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *communicationVBoxLayout;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *settingsVBoxLayout;
    QFormLayout *settingsFormLayout;
    QLabel *label;
    QSpinBox *cameraDeviceSpinBox;
    QLabel *label_2;
    QComboBox *cameraResolutionComboBox;
    QLabel *label_3;
    QLineEdit *frameRateLineEdit;
    QLabel *label_4;
    QLineEdit *markerSizeLineEdit;
    QLabel *label_5;
    QLineEdit *arenaWidthLineEdit;
    QLabel *label_6;
    QLineEdit *arenaHeightLineEdit;
    QLabel *label_7;
    QLineEdit *calibrationFileLineEdit;
    QLabel *label_8;
    QLabel *label_9;
    QSlider *cameraBrightnessSlider;
    QLabel *label_10;
    QSlider *cameraSharpnessSlider;
    QLabel *label_11;
    QSlider *cameraFocusSlider;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *calibrationFilePushButton;
    QFrame *line;
    QHBoxLayout *settingsButtonsHBoxLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *applySettingsPushButton;
    QVBoxLayout *rightVBoxLayout;
    QLabel *imageLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(851, 567);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        mainHBoxLayout = new QHBoxLayout();
        mainHBoxLayout->setSpacing(6);
        mainHBoxLayout->setObjectName(QStringLiteral("mainHBoxLayout"));
        leftVBoxLayout = new QVBoxLayout();
        leftVBoxLayout->setSpacing(6);
        leftVBoxLayout->setObjectName(QStringLiteral("leftVBoxLayout"));
        leftTabWidget = new QTabWidget(centralWidget);
        leftTabWidget->setObjectName(QStringLiteral("leftTabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftTabWidget->sizePolicy().hasHeightForWidth());
        leftTabWidget->setSizePolicy(sizePolicy);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        communicationVBoxLayout = new QVBoxLayout();
        communicationVBoxLayout->setSpacing(6);
        communicationVBoxLayout->setObjectName(QStringLiteral("communicationVBoxLayout"));

        verticalLayout_3->addLayout(communicationVBoxLayout);

        leftTabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        settingsVBoxLayout = new QVBoxLayout();
        settingsVBoxLayout->setSpacing(6);
        settingsVBoxLayout->setObjectName(QStringLiteral("settingsVBoxLayout"));
        settingsFormLayout = new QFormLayout();
        settingsFormLayout->setSpacing(6);
        settingsFormLayout->setObjectName(QStringLiteral("settingsFormLayout"));
        settingsFormLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));

        settingsFormLayout->setWidget(0, QFormLayout::LabelRole, label);

        cameraDeviceSpinBox = new QSpinBox(tab_2);
        cameraDeviceSpinBox->setObjectName(QStringLiteral("cameraDeviceSpinBox"));

        settingsFormLayout->setWidget(0, QFormLayout::FieldRole, cameraDeviceSpinBox);

        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        settingsFormLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        cameraResolutionComboBox = new QComboBox(tab_2);
        cameraResolutionComboBox->setObjectName(QStringLiteral("cameraResolutionComboBox"));
        cameraResolutionComboBox->setEditable(false);

        settingsFormLayout->setWidget(1, QFormLayout::FieldRole, cameraResolutionComboBox);

        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        settingsFormLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        frameRateLineEdit = new QLineEdit(tab_2);
        frameRateLineEdit->setObjectName(QStringLiteral("frameRateLineEdit"));

        settingsFormLayout->setWidget(2, QFormLayout::FieldRole, frameRateLineEdit);

        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        settingsFormLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        markerSizeLineEdit = new QLineEdit(tab_2);
        markerSizeLineEdit->setObjectName(QStringLiteral("markerSizeLineEdit"));

        settingsFormLayout->setWidget(3, QFormLayout::FieldRole, markerSizeLineEdit);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        settingsFormLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        arenaWidthLineEdit = new QLineEdit(tab_2);
        arenaWidthLineEdit->setObjectName(QStringLiteral("arenaWidthLineEdit"));

        settingsFormLayout->setWidget(4, QFormLayout::FieldRole, arenaWidthLineEdit);

        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        settingsFormLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        arenaHeightLineEdit = new QLineEdit(tab_2);
        arenaHeightLineEdit->setObjectName(QStringLiteral("arenaHeightLineEdit"));

        settingsFormLayout->setWidget(5, QFormLayout::FieldRole, arenaHeightLineEdit);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        settingsFormLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        calibrationFileLineEdit = new QLineEdit(tab_2);
        calibrationFileLineEdit->setObjectName(QStringLiteral("calibrationFileLineEdit"));

        settingsFormLayout->setWidget(6, QFormLayout::FieldRole, calibrationFileLineEdit);

        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        settingsFormLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        settingsFormLayout->setWidget(8, QFormLayout::LabelRole, label_9);

        cameraBrightnessSlider = new QSlider(tab_2);
        cameraBrightnessSlider->setObjectName(QStringLiteral("cameraBrightnessSlider"));
        cameraBrightnessSlider->setMaximum(255);
        cameraBrightnessSlider->setOrientation(Qt::Horizontal);

        settingsFormLayout->setWidget(8, QFormLayout::FieldRole, cameraBrightnessSlider);

        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        settingsFormLayout->setWidget(9, QFormLayout::LabelRole, label_10);

        cameraSharpnessSlider = new QSlider(tab_2);
        cameraSharpnessSlider->setObjectName(QStringLiteral("cameraSharpnessSlider"));
        cameraSharpnessSlider->setMaximum(255);
        cameraSharpnessSlider->setOrientation(Qt::Horizontal);

        settingsFormLayout->setWidget(9, QFormLayout::FieldRole, cameraSharpnessSlider);

        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        settingsFormLayout->setWidget(10, QFormLayout::LabelRole, label_11);

        cameraFocusSlider = new QSlider(tab_2);
        cameraFocusSlider->setObjectName(QStringLiteral("cameraFocusSlider"));
        cameraFocusSlider->setMaximum(255);
        cameraFocusSlider->setOrientation(Qt::Horizontal);

        settingsFormLayout->setWidget(10, QFormLayout::FieldRole, cameraFocusSlider);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        calibrationFilePushButton = new QPushButton(tab_2);
        calibrationFilePushButton->setObjectName(QStringLiteral("calibrationFilePushButton"));

        horizontalLayout_3->addWidget(calibrationFilePushButton);


        settingsFormLayout->setLayout(7, QFormLayout::FieldRole, horizontalLayout_3);


        settingsVBoxLayout->addLayout(settingsFormLayout);

        line = new QFrame(tab_2);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        settingsVBoxLayout->addWidget(line);

        settingsButtonsHBoxLayout = new QHBoxLayout();
        settingsButtonsHBoxLayout->setSpacing(6);
        settingsButtonsHBoxLayout->setObjectName(QStringLiteral("settingsButtonsHBoxLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        settingsButtonsHBoxLayout->addItem(horizontalSpacer);

        applySettingsPushButton = new QPushButton(tab_2);
        applySettingsPushButton->setObjectName(QStringLiteral("applySettingsPushButton"));

        settingsButtonsHBoxLayout->addWidget(applySettingsPushButton);


        settingsVBoxLayout->addLayout(settingsButtonsHBoxLayout);


        verticalLayout_2->addLayout(settingsVBoxLayout);

        leftTabWidget->addTab(tab_2, QString());

        leftVBoxLayout->addWidget(leftTabWidget);


        mainHBoxLayout->addLayout(leftVBoxLayout);

        rightVBoxLayout = new QVBoxLayout();
        rightVBoxLayout->setSpacing(6);
        rightVBoxLayout->setObjectName(QStringLiteral("rightVBoxLayout"));
        imageLabel = new QLabel(centralWidget);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy1);

        rightVBoxLayout->addWidget(imageLabel);


        mainHBoxLayout->addLayout(rightVBoxLayout);


        horizontalLayout_2->addLayout(mainHBoxLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 851, 29));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        leftTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        leftTabWidget->setTabText(leftTabWidget->indexOf(tab), QApplication::translate("MainWindow", "Communication", 0));
        label->setText(QApplication::translate("MainWindow", "Camera Device", 0));
        label_2->setText(QApplication::translate("MainWindow", "Camera Resolution", 0));
        cameraResolutionComboBox->clear();
        cameraResolutionComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "640x480", 0)
         << QApplication::translate("MainWindow", "1920x1080", 0)
        );
        label_3->setText(QApplication::translate("MainWindow", "Frame Rate (ms)", 0));
        label_4->setText(QApplication::translate("MainWindow", "Marker Size (m)", 0));
        label_5->setText(QApplication::translate("MainWindow", "Arena Width (m)", 0));
        label_6->setText(QApplication::translate("MainWindow", "Arena Height (m)", 0));
        label_7->setText(QApplication::translate("MainWindow", "Calibration File", 0));
        label_8->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "Camera Brightness", 0));
        label_10->setText(QApplication::translate("MainWindow", "Camera Sharpness", 0));
        label_11->setText(QApplication::translate("MainWindow", "Camera Focus", 0));
        calibrationFilePushButton->setText(QApplication::translate("MainWindow", "Browse", 0));
        applySettingsPushButton->setText(QApplication::translate("MainWindow", "Apply", 0));
        leftTabWidget->setTabText(leftTabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Settings", 0));
        imageLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
