#ifndef EDITOR_HH
#define EDITOR_HH

#include <QWidget>
#include <QString>

namespace Ui {
class Editor;
}

class Editor : public QWidget
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = 0);
    ~Editor();

private slots:
    void on_saveButton_clicked();
    void on_quitButton_clicked();
    void on_textEditor_textChanged();
    void on_loadButton_clicked();

private:
    Ui::Editor *ui;

    QString filename;
    bool text_modified;
};

#endif // EDITOR_HH
