#ifndef CALCULATORPLUGIN_H
#define CALCULATORPLUGIN_H


#include "Interfaces.h"
#include "Utils.h"

#include <cmath>

#include <QObject>
#include <QtPlugin>
#include <QString>
#include <QWidget>
#include <QImage>
#include <QLineEdit>
#include <QStandardPaths>


QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE
class Button;

class CalculatorPlugin : public QObject, public Interface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.MAH.Interface" FILE "CalculatorPlugin.json")
    Q_INTERFACES(Interface)

public:
    QString pname()  override;
    QString pdesc()  override;
    void initialize() override;
    QWidget *pcontent()  override;
private:
    QLineEdit *display;
    enum { NumDigitButtons = 10 };
    Button *digitButtons[NumDigitButtons];
    Button *createButton(const QString &text, const char *member);
    bool waitingForOperand;
    double sumSoFar;
    double factorSoFar;
    double sumInMemory;
    QString pendingAdditiveOperator;
    QString pendingMultiplicativeOperator;
    void abortOperation();
    bool calculate(double rightOperand, const QString &pendingOperator);
    QString m_logPath;
    QString logDir;
    QString confDir;
private slots:
    void digitClicked();
    void unaryOperatorClicked();
    void additiveOperatorClicked();
    void multiplicativeOperatorClicked();
    void equalClicked();
    void pointClicked();
    void changeSignClicked();
    void backspaceClicked();
    void clear();
    void clearAll();
    void clearMemory();
    void readMemory();
    void setMemory();
    void addToMemory();
};
#endif
