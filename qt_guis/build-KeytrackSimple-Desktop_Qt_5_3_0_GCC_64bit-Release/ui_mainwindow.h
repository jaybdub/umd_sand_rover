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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QTabWidget *tabWidget_3;
    QWidget *tab_6;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *connectionPanel;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *serialStatusLabel;
    QFormLayout *formLayout_4;
    QLabel *label_10;
    QComboBox *availableSerialPortsComboBox;
    QLabel *label_11;
    QComboBox *baudRateComboBox;
    QPushButton *refreshSerialOptionsButton;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *serialDisconnectButton;
    QPushButton *serialConnectButton;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *settingsPanel;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout;
    QLabel *deviceLabel;
    QLabel *label;
    QComboBox *cameraResolutionComboBox;
    QSpinBox *cameraDeviceSpinBox;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QLineEdit *markerSizeLineEdit;
    QLabel *label_6;
    QLineEdit *frameIntLineEdit;
    QCheckBox *useCalibrationCheckBox;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *calibrationFileLineEdit;
    QPushButton *browseCalibrationFileButton;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_8;
    QFormLayout *formLayout_3;
    QLabel *label_9;
    QLineEdit *doxLineEdit;
    QLabel *label_8;
    QLineEdit *doyLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *loadSettingsButton;
    QPushButton *saveSettingsButton;
    QPushButton *applySettingsButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *viewport;
    QFrame *frame;
    QVBoxLayout *verticalLayout_13;
    QStackedWidget *stackedWidget;
    QWidget *Video;
    QVBoxLayout *verticalLayout_7;
    QLabel *image;
    QWidget *page_6;
    QVBoxLayout *verticalLayout_12;
    QCustomPlot *markerTracePlot;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QComboBox *viewSelectComboBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QLineEdit *sendSerialDataLineEdit;
    QPushButton *sendSerialDataButton;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *sentDataTextEdit;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *clearSentDataButton;
    QPushButton *saveSentDataButton;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_9;
    QTextEdit *receivedDataTextEdit;
    QWidget *tab_2;
    QFrame *line_4;
    QGroupBox *groupBox_3;
    QPushButton *startRunButton;
    QPushButton *stopRunButton;
    QLabel *label_4;
    QLabel *runTimeLabel;
    QLabel *label_5;
    QLabel *framesDetectedLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1117, 774);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        tabWidget_3 = new QTabWidget(centralWidget);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget_3->sizePolicy().hasHeightForWidth());
        tabWidget_3->setSizePolicy(sizePolicy);
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        verticalLayout_11 = new QVBoxLayout(tab_6);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        connectionPanel = new QVBoxLayout();
        connectionPanel->setSpacing(6);
        connectionPanel->setObjectName(QStringLiteral("connectionPanel"));
        groupBox_5 = new QGroupBox(tab_6);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy1);
        verticalLayout_5 = new QVBoxLayout(groupBox_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        serialStatusLabel = new QLabel(groupBox_5);
        serialStatusLabel->setObjectName(QStringLiteral("serialStatusLabel"));

        verticalLayout_5->addWidget(serialStatusLabel);

        formLayout_4 = new QFormLayout();
        formLayout_4->setSpacing(6);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_10);

        availableSerialPortsComboBox = new QComboBox(groupBox_5);
        availableSerialPortsComboBox->setObjectName(QStringLiteral("availableSerialPortsComboBox"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, availableSerialPortsComboBox);

        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_11);

        baudRateComboBox = new QComboBox(groupBox_5);
        baudRateComboBox->setObjectName(QStringLiteral("baudRateComboBox"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, baudRateComboBox);

        refreshSerialOptionsButton = new QPushButton(groupBox_5);
        refreshSerialOptionsButton->setObjectName(QStringLiteral("refreshSerialOptionsButton"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, refreshSerialOptionsButton);


        verticalLayout_5->addLayout(formLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        serialDisconnectButton = new QPushButton(groupBox_5);
        serialDisconnectButton->setObjectName(QStringLiteral("serialDisconnectButton"));

        horizontalLayout_5->addWidget(serialDisconnectButton);

        serialConnectButton = new QPushButton(groupBox_5);
        serialConnectButton->setObjectName(QStringLiteral("serialConnectButton"));

        horizontalLayout_5->addWidget(serialConnectButton);


        verticalLayout_5->addLayout(horizontalLayout_5);


        connectionPanel->addWidget(groupBox_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        connectionPanel->addItem(verticalSpacer_2);


        verticalLayout_11->addLayout(connectionPanel);

        tabWidget_3->addTab(tab_6, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        verticalLayout_10 = new QVBoxLayout(tab_5);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        settingsPanel = new QVBoxLayout();
        settingsPanel->setSpacing(6);
        settingsPanel->setObjectName(QStringLiteral("settingsPanel"));
        groupBox_2 = new QGroupBox(tab_5);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        deviceLabel = new QLabel(groupBox_2);
        deviceLabel->setObjectName(QStringLiteral("deviceLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, deviceLabel);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        cameraResolutionComboBox = new QComboBox(groupBox_2);
        cameraResolutionComboBox->setObjectName(QStringLiteral("cameraResolutionComboBox"));
        sizePolicy2.setHeightForWidth(cameraResolutionComboBox->sizePolicy().hasHeightForWidth());
        cameraResolutionComboBox->setSizePolicy(sizePolicy2);

        formLayout->setWidget(1, QFormLayout::FieldRole, cameraResolutionComboBox);

        cameraDeviceSpinBox = new QSpinBox(groupBox_2);
        cameraDeviceSpinBox->setObjectName(QStringLiteral("cameraDeviceSpinBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cameraDeviceSpinBox);


        verticalLayout_4->addLayout(formLayout);


        settingsPanel->addWidget(groupBox_2);

        groupBox = new QGroupBox(tab_5);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        markerSizeLineEdit = new QLineEdit(groupBox);
        markerSizeLineEdit->setObjectName(QStringLiteral("markerSizeLineEdit"));
        sizePolicy2.setHeightForWidth(markerSizeLineEdit->sizePolicy().hasHeightForWidth());
        markerSizeLineEdit->setSizePolicy(sizePolicy2);
        markerSizeLineEdit->setMinimumSize(QSize(0, 0));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, markerSizeLineEdit);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_6);

        frameIntLineEdit = new QLineEdit(groupBox);
        frameIntLineEdit->setObjectName(QStringLiteral("frameIntLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, frameIntLineEdit);


        verticalLayout_3->addLayout(formLayout_2);

        useCalibrationCheckBox = new QCheckBox(groupBox);
        useCalibrationCheckBox->setObjectName(QStringLiteral("useCalibrationCheckBox"));

        verticalLayout_3->addWidget(useCalibrationCheckBox);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        calibrationFileLineEdit = new QLineEdit(groupBox);
        calibrationFileLineEdit->setObjectName(QStringLiteral("calibrationFileLineEdit"));

        horizontalLayout_4->addWidget(calibrationFileLineEdit);

        browseCalibrationFileButton = new QPushButton(groupBox);
        browseCalibrationFileButton->setObjectName(QStringLiteral("browseCalibrationFileButton"));

        horizontalLayout_4->addWidget(browseCalibrationFileButton);


        verticalLayout_3->addLayout(horizontalLayout_4);


        settingsPanel->addWidget(groupBox);

        groupBox_4 = new QGroupBox(tab_5);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_8 = new QVBoxLayout(groupBox_4);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_9);

        doxLineEdit = new QLineEdit(groupBox_4);
        doxLineEdit->setObjectName(QStringLiteral("doxLineEdit"));
        sizePolicy2.setHeightForWidth(doxLineEdit->sizePolicy().hasHeightForWidth());
        doxLineEdit->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, doxLineEdit);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_8);

        doyLineEdit = new QLineEdit(groupBox_4);
        doyLineEdit->setObjectName(QStringLiteral("doyLineEdit"));
        sizePolicy2.setHeightForWidth(doyLineEdit->sizePolicy().hasHeightForWidth());
        doyLineEdit->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, doyLineEdit);


        verticalLayout_8->addLayout(formLayout_3);


        settingsPanel->addWidget(groupBox_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        loadSettingsButton = new QPushButton(tab_5);
        loadSettingsButton->setObjectName(QStringLiteral("loadSettingsButton"));

        horizontalLayout_2->addWidget(loadSettingsButton);

        saveSettingsButton = new QPushButton(tab_5);
        saveSettingsButton->setObjectName(QStringLiteral("saveSettingsButton"));

        horizontalLayout_2->addWidget(saveSettingsButton);

        applySettingsButton = new QPushButton(tab_5);
        applySettingsButton->setObjectName(QStringLiteral("applySettingsButton"));

        horizontalLayout_2->addWidget(applySettingsButton);


        settingsPanel->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        settingsPanel->addItem(verticalSpacer);


        verticalLayout_10->addLayout(settingsPanel);

        tabWidget_3->addTab(tab_5, QString());

        horizontalLayout_3->addWidget(tabWidget_3);

        viewport = new QVBoxLayout();
        viewport->setSpacing(6);
        viewport->setObjectName(QStringLiteral("viewport"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_13 = new QVBoxLayout(frame);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        stackedWidget = new QStackedWidget(frame);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        Video = new QWidget();
        Video->setObjectName(QStringLiteral("Video"));
        verticalLayout_7 = new QVBoxLayout(Video);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        image = new QLabel(Video);
        image->setObjectName(QStringLiteral("image"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(image->sizePolicy().hasHeightForWidth());
        image->setSizePolicy(sizePolicy4);

        verticalLayout_7->addWidget(image);

        stackedWidget->addWidget(Video);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        verticalLayout_12 = new QVBoxLayout(page_6);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        markerTracePlot = new QCustomPlot(page_6);
        markerTracePlot->setObjectName(QStringLiteral("markerTracePlot"));

        verticalLayout_12->addWidget(markerTracePlot);

        stackedWidget->addWidget(page_6);

        verticalLayout_13->addWidget(stackedWidget);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        viewSelectComboBox = new QComboBox(frame);
        viewSelectComboBox->setObjectName(QStringLiteral("viewSelectComboBox"));

        horizontalLayout_6->addWidget(viewSelectComboBox);


        verticalLayout_13->addLayout(horizontalLayout_6);


        viewport->addWidget(frame);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy5);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_6 = new QVBoxLayout(tab);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sendSerialDataLineEdit = new QLineEdit(tab);
        sendSerialDataLineEdit->setObjectName(QStringLiteral("sendSerialDataLineEdit"));

        horizontalLayout->addWidget(sendSerialDataLineEdit);

        sendSerialDataButton = new QPushButton(tab);
        sendSerialDataButton->setObjectName(QStringLiteral("sendSerialDataButton"));

        horizontalLayout->addWidget(sendSerialDataButton);


        verticalLayout_6->addLayout(horizontalLayout);

        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(tabWidget_2->sizePolicy().hasHeightForWidth());
        tabWidget_2->setSizePolicy(sizePolicy6);
        tabWidget_2->setMinimumSize(QSize(0, 0));
        tabWidget_2->setFocusPolicy(Qt::TabFocus);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_2 = new QVBoxLayout(tab_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        sentDataTextEdit = new QTextEdit(tab_3);
        sentDataTextEdit->setObjectName(QStringLiteral("sentDataTextEdit"));
        sentDataTextEdit->setEnabled(true);
        sizePolicy4.setHeightForWidth(sentDataTextEdit->sizePolicy().hasHeightForWidth());
        sentDataTextEdit->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(sentDataTextEdit);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        clearSentDataButton = new QPushButton(tab_3);
        clearSentDataButton->setObjectName(QStringLiteral("clearSentDataButton"));

        horizontalLayout_7->addWidget(clearSentDataButton);

        saveSentDataButton = new QPushButton(tab_3);
        saveSentDataButton->setObjectName(QStringLiteral("saveSentDataButton"));

        horizontalLayout_7->addWidget(saveSentDataButton);


        verticalLayout_2->addLayout(horizontalLayout_7);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_9 = new QVBoxLayout(tab_4);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        receivedDataTextEdit = new QTextEdit(tab_4);
        receivedDataTextEdit->setObjectName(QStringLiteral("receivedDataTextEdit"));

        verticalLayout_9->addWidget(receivedDataTextEdit);

        tabWidget_2->addTab(tab_4, QString());

        verticalLayout_6->addWidget(tabWidget_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        viewport->addWidget(tabWidget);


        horizontalLayout_3->addLayout(viewport);

        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_4);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(200, 0));
        startRunButton = new QPushButton(groupBox_3);
        startRunButton->setObjectName(QStringLiteral("startRunButton"));
        startRunButton->setGeometry(QRect(100, 40, 94, 29));
        stopRunButton = new QPushButton(groupBox_3);
        stopRunButton->setObjectName(QStringLiteral("stopRunButton"));
        stopRunButton->setGeometry(QRect(0, 40, 94, 29));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 100, 81, 21));
        runTimeLabel = new QLabel(groupBox_3);
        runTimeLabel->setObjectName(QStringLiteral("runTimeLabel"));
        runTimeLabel->setGeometry(QRect(90, 100, 101, 21));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 140, 121, 21));
        framesDetectedLabel = new QLabel(groupBox_3);
        framesDetectedLabel->setObjectName(QStringLiteral("framesDetectedLabel"));
        framesDetectedLabel->setGeometry(QRect(70, 180, 68, 21));

        horizontalLayout_3->addWidget(groupBox_3);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1117, 29));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget_3->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Tracking System", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Serial", 0));
        serialStatusLabel->setText(QApplication::translate("MainWindow", "Status: Disconnected", 0));
        label_10->setText(QApplication::translate("MainWindow", "Port", 0));
        label_11->setText(QApplication::translate("MainWindow", "Baud Rate", 0));
        refreshSerialOptionsButton->setText(QApplication::translate("MainWindow", "Refresh", 0));
        serialDisconnectButton->setText(QApplication::translate("MainWindow", "Disconnect", 0));
        serialConnectButton->setText(QApplication::translate("MainWindow", "Connect", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_6), QApplication::translate("MainWindow", "Connections", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Camera", 0));
        deviceLabel->setText(QApplication::translate("MainWindow", "Device", 0));
        label->setText(QApplication::translate("MainWindow", "Resolution", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Marker Detector", 0));
        label_2->setText(QApplication::translate("MainWindow", "Marker Size", 0));
        label_6->setText(QApplication::translate("MainWindow", "Frame Int", 0));
        useCalibrationCheckBox->setText(QApplication::translate("MainWindow", "Use Calibration", 0));
        label_3->setText(QApplication::translate("MainWindow", "Calibration file path:", 0));
        browseCalibrationFileButton->setText(QApplication::translate("MainWindow", "Browse", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Pose Detection", 0));
#ifndef QT_NO_TOOLTIP
        label_9->setToolTip(QApplication::translate("MainWindow", "Distance in meters from the origin marker to the x axis marker.", 0));
#endif // QT_NO_TOOLTIP
        label_9->setText(QApplication::translate("MainWindow", "d_ox", 0));
        label_8->setText(QApplication::translate("MainWindow", "d_oy", 0));
        loadSettingsButton->setText(QApplication::translate("MainWindow", "Load", 0));
        saveSettingsButton->setText(QApplication::translate("MainWindow", "Save", 0));
        applySettingsButton->setText(QApplication::translate("MainWindow", "Apply", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_5), QApplication::translate("MainWindow", "Parameters", 0));
        image->setText(QApplication::translate("MainWindow", "Image", 0));
        viewSelectComboBox->clear();
        viewSelectComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Video", 0)
         << QApplication::translate("MainWindow", "Marker Trace", 0)
        );
        sendSerialDataButton->setText(QApplication::translate("MainWindow", "Send", 0));
        clearSentDataButton->setText(QApplication::translate("MainWindow", "Clear", 0));
        saveSentDataButton->setText(QApplication::translate("MainWindow", "Save", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Sent", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Received", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Communication", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Markers", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Run", 0));
        startRunButton->setText(QApplication::translate("MainWindow", "Start", 0));
        stopRunButton->setText(QApplication::translate("MainWindow", "End", 0));
        label_4->setText(QApplication::translate("MainWindow", "Run Time: ", 0));
        runTimeLabel->setText(QApplication::translate("MainWindow", "<run time>", 0));
        label_5->setText(QApplication::translate("MainWindow", "Frames Detected:", 0));
        framesDetectedLabel->setText(QApplication::translate("MainWindow", "<frames>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
