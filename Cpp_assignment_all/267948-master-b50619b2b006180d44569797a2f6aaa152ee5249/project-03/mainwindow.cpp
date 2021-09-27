#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->height_spinBox->setSuffix("cm");
    ui->weight_spinBox->setSuffix("kg");
    // set function slot for dropdown Action(reset/quit)
    connect(ui->actionQuit,SIGNAL(triggered(bool)),this,SLOT(close()));
    connect(ui->actionReset,SIGNAL(triggered(bool)),this,SLOT(action_reset()));

//alternate gender on click and select current gender value.
    QActionGroup *menuGender= new QActionGroup(this);
    menuGender->addAction(ui->actionFemale);
    menuGender->addAction(ui->actionMale);
    menuGender->setExclusive(true);

// select gender from dropdown menu and set to a variable named "gender_sel_value"
    connect(ui->actionFemale,SIGNAL(triggered(bool)),this,SLOT(gender_selection()));
    connect(ui->actionMale,SIGNAL(triggered(bool)),this,SLOT(gender_selection()));
// calculate BMI with change of value of weight and height
    connect(ui->height_spinBox,SIGNAL(valueChanged(int)),this,SLOT(BMI_interpretation()));
    connect(ui->weight_spinBox,SIGNAL(valueChanged(int)),this,SLOT(BMI_interpretation()));



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::BMI_interpretation(){

std::vector<double> BMI_limits;
if(ui->actionMale->isChecked()){
    BMI_limits={20.7, 26.4, 27.8, 31.1};

} else {BMI_limits={19.1, 25.8, 27.3, 32.2};}

double height=ui->height_spinBox->value();
double weight=ui->weight_spinBox->value();

if(height !=0 and weight !=0){
    double BMI=weight/((0.01*height)*(0.01*height));
    QString showBMI=QString::number(BMI);

    if(BMI<=BMI_limits[0]){
        ui->show_BMI_label->setText(showBMI);
        ui->show_intrp_label->setText("underweight");
    }
    else if (BMI<=BMI_limits[1]){
        ui->show_BMI_label->setText(showBMI);
        ui->show_intrp_label->setText("normal");
    }
    else if (BMI<=BMI_limits[2]){
        ui->show_BMI_label->setText(showBMI);
        ui->show_intrp_label->setText("slightly overweight");
    }
    else if(BMI>BMI_limits[3]){
        ui->show_BMI_label->setText(showBMI);
        ui->show_intrp_label->setText("overweight");
    }
    else if(BMI<=BMI_limits[3]){
        ui->show_BMI_label->setText(showBMI);
        ui->show_intrp_label->setText("much underweight");
    }
    else {
        ui->show_BMI_label->setText("invalid");
        ui->show_intrp_label->setText("invalid");
    }


} else {
    ui->show_BMI_label->setText("invalid for o");
    ui->show_intrp_label->setText("invalid for 0");
}



}


void MainWindow::action_reset(){

    ui->show_gen_label->setText("female");
    ui->height_spinBox->setValue(0);
    ui->weight_spinBox->setValue(0);
//    ui->height_spinBox->setMinimum(0);
//    ui->height_spinBox->setPrefix("0");

}



void MainWindow::gender_selection(){

    QString gender_sel_value;
    if(ui->actionFemale->isChecked()){
        gender_sel_value="female";
        ui->show_gen_label->setText(gender_sel_value);
    } else if(ui->actionMale->isChecked()){
        gender_sel_value="male";
    ui->show_gen_label->setText(gender_sel_value);
    } else ui->show_gen_label->setText("Female");

}
