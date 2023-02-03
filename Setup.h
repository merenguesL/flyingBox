#pragma once
#include <QDialog>
#include <QGroupBox>
#include <QComboBox>
#include <QButtonGroup>

using OPTIONS = struct {
	int flyingMode;
	int shakeRange;
	int shakeCounts;
};

enum FLYINGMODE
{
	FLYING_RANDOM,	//ÂÒ·É
	FLYING_DEFLECT	//·´µ¯
};

class Setup :public QDialog
{
	Q_OBJECT

public:
	Setup(const OPTIONS &opt);
	~Setup();

private slots:
	void onOkClicked();

public:
	
	OPTIONS getOption() { return options; }

private:

	OPTIONS options;

	QGroupBox* box_fly;
	QGroupBox* box_shake;
	QButtonGroup* group_fly;

	QComboBox* combobox_range;
	QComboBox* combobox_count;

};

