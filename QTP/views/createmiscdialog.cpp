#include "createmiscdialog.h"
#include "ui_createmiscdialog.h"

#include "model/staffmodel.h"
#include "stringutil.h"

CreateMiscDialog::CreateMiscDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateMiscDialog)
{
    ui->setupUi(this);

    // Connections.
    connect(this, SIGNAL(accepted()), this, SLOT(onDialogAccepted()));
    connect(this, SIGNAL(rejected()), this, SLOT(onDialogRejected()));

    QFont font = ui->firstNameLineEdit->font();
    font.setCapitalization(QFont::Capitalize);

    ui->firstNameLineEdit->setFont(font);
    ui->lastNameLineEdit->setFont(font);
}

CreateMiscDialog::~CreateMiscDialog()
{
    delete ui;
}

void CreateMiscDialog::onDialogAccepted()
{
    // Create staff.
    // Type 6 = Divers
    StaffModel::addStaff(Staff(-1, StringUtil::capitalize(ui->firstNameLineEdit->text()), StringUtil::capitalize(ui->lastNameLineEdit->text()), 6));
}

void CreateMiscDialog::onDialogRejected()
{

}
