#include "Setup.h"
#include <QBoxLayout>
#include <QCheckBox>
#include <QRadioButton>
#include <QFormLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

Setup::Setup(const OPTIONS &opt)
	:options(opt)
{
	setWindowTitle(tr("����"));

	auto* layout = new QVBoxLayout(this);
	//����
	box_fly = new QGroupBox(tr("����ģʽ"), this);
	layout->addWidget(box_fly);
	auto* gbLayout = new QHBoxLayout(box_fly);
	auto* radioButton_random = new QRadioButton(tr("�ҷ�ģʽ"));
	gbLayout->addWidget(radioButton_random);
	radioButton_random->setChecked(options.flyingMode==FLYING_RANDOM?true:false);
	auto* radioButton_deflict = new QRadioButton(tr("ײǽ����ģʽ"));
	radioButton_deflict->setChecked(options.flyingMode == FLYING_RANDOM ? false : true);
	gbLayout->addWidget(radioButton_deflict);
	group_fly = new QButtonGroup(box_fly);
	group_fly->addButton(radioButton_random,0);
	group_fly->addButton(radioButton_deflict,1);

	//����
	auto* box_shake = new QGroupBox(tr("��������"), this);
	layout->addWidget(box_shake);
	combobox_range = new QComboBox;
	combobox_count = new QComboBox;
	auto* formLayout = new QFormLayout(box_shake);
	formLayout->addRow(tr("������Χ(����)"), combobox_range);
	formLayout->addRow(tr("��������"), combobox_count);
	QStringList list1;
	QStringList list2;
	for (int i = 1; i < 101; i++)
	{
		list1 <<QString::number(i);
	}
	list2 = list1;
	for (int i = 200; i < 50000; i += 100)
	{
		list2 << QString::number(i);
	}
	combobox_range->addItems(list1);
	combobox_count->addItems(list2);
	combobox_range->setCurrentIndex(options.shakeRange - 1);
	combobox_count->setCurrentIndex(combobox_count->findText(QString::number(options.shakeCounts)));

	//
	auto* button_ok = new QPushButton(tr("ȷ��"));
	layout->addWidget(button_ok);
	connect(button_ok, SIGNAL(clicked()), this, SLOT(onOkClicked()));
}

Setup::~Setup() = default;

void Setup::onOkClicked()
{
	options.flyingMode=group_fly->checkedId();
	options.shakeRange = combobox_range->currentText().toInt();
	options.shakeCounts = combobox_count->currentText().toInt();
	accept();
}