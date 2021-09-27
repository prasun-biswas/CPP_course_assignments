#include "widget.h"
      #include "ui_widget.h"

      Widget::Widget(QWidget *parent) :
          QWidget(parent),
          ui(new Ui::Widget)
      {
          ui->setupUi(this);

          connect(ui->clear_button, SIGNAL(clicked()),
                  this, SLOT(clear_button_clicked()));
      }

      Widget::~Widget()
      {
          delete ui;
      }

      void Widget::clear_button_clicked()
      {
          ui->kmh_spinbox->setValue(0);

          ui->miles_lcd->display(0.0);  // Not really neccessary after the program is finished.
      }
