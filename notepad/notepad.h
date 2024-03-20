#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class notepad;
}
QT_END_NAMESPACE

class notepad : public QMainWindow
{
    Q_OBJECT

public:
    notepad(QWidget *parent = nullptr);
    ~notepad();

private slots:
    void on_actionQuit_triggered();
    void on_actionSave_triggered();
    void on_actionAbout_qt_triggered();
    void on_actionOpen_triggered();
    void documentModified(); // Aggiunta della dichiarazione della funzione documentModified come membro privato

private:
    Ui::notepad *ui;
    bool isModified;
};

#endif // NOTEPAD_H
