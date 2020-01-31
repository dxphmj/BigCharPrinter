﻿#include "keyboard.h"
#include "ui_keyboard.h"
#include <QAction>
#include <QtWidgets/QStackedWidget>
#include "lineedit_click.h"
#include "language.h"

keyboard::keyboard(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::keyboard)

{
	ui->setupUi(this);
	languageWidget = new language(this);
	languageWidget->setVisible(false);

	connect(ui->A_KBBut,SIGNAL(clicked()),this,SLOT(A_KBBut_clicked()));
	connect(ui->B_KBBut,SIGNAL(clicked()),this,SLOT(B_KBBut_clicked()));
	connect(ui->C_KBBut,SIGNAL(clicked()),this,SLOT(C_KBBut_clicked()));
	connect(ui->D_KBBut,SIGNAL(clicked()),this,SLOT(D_KBBut_clicked()));
	connect(ui->E_KBBut,SIGNAL(clicked()),this,SLOT(E_KBBut_clicked()));
	connect(ui->F_KBBut,SIGNAL(clicked()),this,SLOT(F_KBBut_clicked()));
	connect(ui->G_KBBut,SIGNAL(clicked()),this,SLOT(G_KBBut_clicked()));
	connect(ui->H_KBBut,SIGNAL(clicked()),this,SLOT(H_KBBut_clicked()));
	connect(ui->I_KBBut,SIGNAL(clicked()),this,SLOT(I_KBBut_clicked()));
	connect(ui->J_KBBut,SIGNAL(clicked()),this,SLOT(J_KBBut_clicked()));
	connect(ui->K_KBBut,SIGNAL(clicked()),this,SLOT(K_KBBut_clicked()));
	connect(ui->L_KBBut,SIGNAL(clicked()),this,SLOT(L_KBBut_clicked()));
	connect(ui->M_KBBut,SIGNAL(clicked()),this,SLOT(M_KBBut_clicked()));
	connect(ui->N_KBBut,SIGNAL(clicked()),this,SLOT(N_KBBut_clicked()));
	connect(ui->O_KBBut,SIGNAL(clicked()),this,SLOT(O_KBBut_clicked()));
	connect(ui->P_KBBut,SIGNAL(clicked()),this,SLOT(P_KBBut_clicked()));
	connect(ui->Q_KBBut,SIGNAL(clicked()),this,SLOT(Q_KBBut_clicked()));
	connect(ui->R_KBBut,SIGNAL(clicked()),this,SLOT(R_KBBut_clicked()));
	connect(ui->S_KBBut,SIGNAL(clicked()),this,SLOT(S_KBBut_clicked()));
	connect(ui->T_KBBut,SIGNAL(clicked()),this,SLOT(T_KBBut_clicked()));
	connect(ui->U_KBBut,SIGNAL(clicked()),this,SLOT(U_KBBut_clicked()));
	connect(ui->V_KBBut,SIGNAL(clicked()),this,SLOT(V_KBBut_clicked()));
	connect(ui->W_KBBut,SIGNAL(clicked()),this,SLOT(W_KBBut_clicked()));
	connect(ui->X_KBBut,SIGNAL(clicked()),this,SLOT(X_KBBut_clicked()));
	connect(ui->Y_KBBut,SIGNAL(clicked()),this,SLOT(Y_KBBut_clicked()));
	connect(ui->Z_KBBut,SIGNAL(clicked()),this,SLOT(Z_KBBut_clicked()));
	connect(ui->one_KBBut,SIGNAL(clicked()),this,SLOT(num1_KBBut_clicked()));
	connect(ui->two_KBBut,SIGNAL(clicked()),this,SLOT(num2_KBBut_clicked()));
	connect(ui->three_KBBut,SIGNAL(clicked()),this,SLOT(num3_KBBut_clicked()));
	connect(ui->four_KBBut,SIGNAL(clicked()),this,SLOT(num4_KBBut_clicked()));
	connect(ui->five_KBBut,SIGNAL(clicked()),this,SLOT(num5_KBBut_clicked()));
	connect(ui->six_KBBut,SIGNAL(clicked()),this,SLOT(num6_KBBut_clicked()));
	connect(ui->seven_KBBut,SIGNAL(clicked()),this,SLOT(num7_KBBut_clicked()));
	connect(ui->eight_KBBut,SIGNAL(clicked()),this,SLOT(num8_KBBut_clicked()));
	connect(ui->nine_KBBut,SIGNAL(clicked()),this,SLOT(num9_KBBut_clicked()));
	connect(ui->zero_KBBut,SIGNAL(clicked()),this,SLOT(num0_KBBut_clicked()));
	connect(ui->space_KBBut,SIGNAL(clicked()),this,SLOT(space_KBBut_clicked()));
	connect(ui->comma_KBBut,SIGNAL(clicked()),this,SLOT(comma_KBBut_clicked()));
	connect(ui->period_KBBut,SIGNAL(clicked()),this,SLOT(period_KBBut_clicked()));

	connect(ui->enter_KBBut,SIGNAL(clicked()),this,SLOT(enter_KBBut_clicked()));
	connect(ui->backspace_KBBut,SIGNAL(clicked()),this,SLOT(backspace_KBBut_clicked()));
	connect(ui->language_KBBut,SIGNAL(clicked()),this,SLOT(language_KBBut_clicked()));
	//connect(ui->shift_KBBut,SIGNAL(clicked()),this,SLOT(caps_KBBut_clicked()));
	connect(ui->shift_KBBut,SIGNAL(clicked()),this,SLOT(caps1_kBBut_clicked()));
	connect(ui->symbol_KBBut,SIGNAL(clicked()),this,SLOT(symbol_KBBut_clicked()));



	m_LanType = English;
	m_Upper = false;
	m_LantypeReverse = EnglishSymbol;
	m_symbol = true;
}

keyboard::~keyboard()
{
	
}

void keyboard::SetLineEdit(lineedit_click* pInputEdit)
{
	m_pInputEdit = pInputEdit;
	SetPosition();
	setVisible(true);
}

void keyboard::SetPosition()
{
	QRect rectLineEdit;
	rectLineEdit = m_pInputEdit->geometry();
	QRect rectKeyboard;
	rectKeyboard = geometry();
	QRect rect(rectLineEdit.left(),rectLineEdit.bottom()+50,rectKeyboard.width(),rectKeyboard.height());
	setGeometry(rect);
}

void keyboard::enter_KBBut_clicked()
{
	this->setVisible(false);
}

void keyboard::backspace_KBBut_clicked()
{
	m_pInputEdit->backspace();
	QString str1 = m_pInputEdit->text();
}

void keyboard::language_KBBut_clicked()
{
	languageWidget->setVisible(true);
}

void keyboard::caps1_kBBut_clicked()
{
	if ( m_Upper == true )//如果当前为小写
	{
		switch (m_LanType)
		{

		case 0:  //chinese
			{
				LanChineseSmall();
				break;
			}
		case 1:  //Japanese
			{
				LanJapaneseSmall();
				break;
			}
		case 3: //Chinese_others
		case 7:  //English
		case 21://Japanese_others
			{
				LanEnglishBig();
				break;
			}
		case 22: //Korean_others
			{
				LanKoreanSmall();
				break;
			}
		case 8:  //Czech
			{
				LanCzechBig();
				break;
			}
		case 9:  //Dutch
			{
				LanDutchBig();
				break;
			}
		case 10:  //German
			{
				LanGermanBig();
				break;
			}
		case 11:  //Finnish
			{
				LanFarsiBig();
				break;
			}
		case 12:  //Hindi
			{
				LanHindiBig();
				break;
			}
		}

		//case 5:  //Arabic
		//	{
		//		break;
		//	}
		//case 6:  //Farsi
		//	{
		//		break;
		//	}
		//case 8:  //Czech
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Y"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ů"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("'"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Ú"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ˇ"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("É"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("Í"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("Á"));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("Ý"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("Ž"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("Ř"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("Č"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("Š"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("Ě"));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("°"));
		//		break;
		//	}
		//case 9:  //Dutch
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("="));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("`"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("±"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T(">"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("|"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("^"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("~"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("'"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("§"));
		//		break;
		//	}
		//case 10: //German
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("-"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Y"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ä"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ö"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("'"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("*"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Ú"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("+"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("§"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("^"));
		//		break;
		//	}
		//case 11:  //Finnish
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ä"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ö"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("'"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("´"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Å"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("`"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("¤"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("½"));
		//		break;
		//	}
		//case 12:  //Hindi
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("य़"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("।"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("ष"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("श"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ळ"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("ऴ"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("ऩ"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("ण"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ँ"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ऎ"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ठ"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("छ"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("थ"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("ख"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("ऱ"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("फ"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("उ"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("इ"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("अ"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("ए"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ओ"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ऑ"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("ञ"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ढ"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("झ"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ध"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("घ"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ङ"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("भ"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ऊ"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ई"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("आ"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ऐ"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("औ"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ऋ"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("ः"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("श्र"));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("क्ष"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("त्र"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("ज्ञ"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("र्"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("्र"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("ॅ"));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("ऍ"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ऒ"));
		//		break;
		//	}
		//case 13:  //Hungarian
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Y"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Á"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("É"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("Ű"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("Ú"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Ő"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("Ó"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("Ü"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("Ö"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("="));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("/"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("+"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("'"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("§"));
		//		break;
		//	}
		//case 14:  //Italian
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("°"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ç"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("§"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("*"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("é"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Y"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("^"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("£"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("|"));
		//		break;
		//	}
		//case 15:  //Portuguese
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(">"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("<"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("^"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ç"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("}"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("{"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("`"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Y"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("+"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("——"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("）"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("（"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("*"));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("&&"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("^"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("@"));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("\""));
		//		break;
		//	}
		//case 16:  //Russian
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("."));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("Ю"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("Б"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("Ь"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("Т"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("И"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("М"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("С"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("Ч"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Я"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Э"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ж"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("Д"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("Л"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("О"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("Р"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("П"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("А"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("В"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("Ы"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("Ф"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("\\"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("Ъ"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Х"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("З"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("Щ"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("Ш"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("Г"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Н"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("Е"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("К"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("У"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("Ц"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Й"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("+"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("）"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("*"));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T(";"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("№"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("Ё"));
		//		break;
		//	}
		//case 17:  //Spanish
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("¨"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ñ"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("Ç"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("*"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("^"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Y"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("¿"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("·"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ª"));
		//		break;
		//	}
		//case 18:  //Swedish
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ä"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ö"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("*"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("^"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Å"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Y"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("`"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("¤"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("½"));
		//		break;
		//	}
		//case 19:  //Thai
		//	{

		//	}
		//case 20:  //Turkish
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T(","));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("B"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("S"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("Z"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("Ç"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("C"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("V"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("Ö"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("J"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ş"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Y"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("M"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("K"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("T"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("Ü"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("A"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("E"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("İ"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("U"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("X"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("W"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Q"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("H"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("N"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("R"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("D"));
		//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("O"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("I"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("Ğ"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("G"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("F"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("_"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("'"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("^"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
//		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("*"));
//		//	}*/
//		m_Upper = true;
//	}
//	else
//	{
//		btnTextSel(m_LanType);
//		m_Upper = false;
//	}
//	
//}


//void keyboard::symbol_KBBut_clicked()
//{
//
//	if ( m_LantypeReverse == false )
//	{
//		switch (m_LantypeReverse)
//		{
//
//		case 24://SymbolR_others
//
//			ui->A_KBBut->setText("]");
//			/*ui->B_KBBut->setText("~");
//			ui->C_KBBut->setText("\");
//			ui->D_KBBut->setText("");
//			ui->E_KBBut->setText("#");
//			ui->F_KBBut->setText("");
//			ui->G_KBBut->setText(""");
//			ui->H_KBBut->setText(""");
//			ui->I_KBBut->setText("+");
//			ui->J_KBBut->setText("<");
//			ui->K_KBBut->setText(">");
//			ui->L_KBBut->setText("");
//			ui->M_KBBut->setText("M");
//			ui->N_KBBut->setText("N");
//			ui->O_KBBut->setText("O");
//			ui->P_KBBut->setText("P");
//			ui->Q_KBBut->setText("Q");
//			ui->R_KBBut->setText("R");
//			ui->S_KBBut->setText("S");
//			ui->T_KBBut->setText("T");
//			ui->U_KBBut->setText("U");
//			ui->V_KBBut->setText("V");
//			ui->W_KBBut->setText("W");
//			ui->X_KBBut->setText("X");
//			ui->Y_KBBut->setText("Y");
//			ui->Z_KBBut->setText("Z");*/
//			break;
		m_Upper = false;
		m_symbol = true;
	}
	else //当前为大写
	{
		btnLanguageSel(m_LanType);
		m_Upper = true;
		m_symbol = true;
	}

}

void keyboard::symbol_KBBut_clicked()
{
	if ( m_symbol == true )//如果当前为字母
	{
		switch (m_LantypeReverse)
		{
		case 0://English
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral(":"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral(";"));
				ui->G_KBBut->setText(QStringLiteral("\""));
				ui->H_KBBut->setText(QStringLiteral("\""));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("!"));
				ui->R_KBBut->setText(QStringLiteral("$"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("?"));
				break;
			}
		case 1://Chinese
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral("："));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral("；"));
				ui->G_KBBut->setText(QStringLiteral("“"));
				ui->H_KBBut->setText(QStringLiteral("”"));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("！"));
				ui->R_KBBut->setText(QStringLiteral("￥"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("？"));
				break;
			}
		case 2://Kore
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral("："));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral("；"));
				ui->G_KBBut->setText(QStringLiteral("“"));
				ui->H_KBBut->setText(QStringLiteral("”"));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("！"));
				ui->R_KBBut->setText(QStringLiteral("￥"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("？"));
				break;
			}
		case 3://Czech
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral(":"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral(";"));
				ui->G_KBBut->setText(QStringLiteral("\""));
				ui->H_KBBut->setText(QStringLiteral("\""));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("!"));
				ui->R_KBBut->setText(QStringLiteral("$"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("?"));
				ui->one_KBBut->setText("1");
				ui->two_KBBut->setText("2");
				ui->three_KBBut->setText("3");
				ui->four_KBBut->setText("4");
				ui->five_KBBut->setText("5");
				ui->six_KBBut->setText("6");
				ui->seven_KBBut->setText("7");
				ui->eight_KBBut->setText("8");
				ui->nine_KBBut->setText("9");
				ui->zero_KBBut->setText("0");
				break;
			}
		case 4://Japanese
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral(":"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral(";"));
				ui->G_KBBut->setText(QStringLiteral("\""));
				ui->H_KBBut->setText(QStringLiteral("\""));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("!"));
				ui->R_KBBut->setText(QStringLiteral("$"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("?"));
				break;
			}
		case 5://Dutch
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral(":"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral(";"));
				ui->G_KBBut->setText(QStringLiteral("\""));
				ui->H_KBBut->setText(QStringLiteral("\""));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("!"));
				ui->R_KBBut->setText(QStringLiteral("$"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("?"));
				ui->one_KBBut->setText("1");
				ui->two_KBBut->setText("2");
				ui->three_KBBut->setText("3");
				ui->four_KBBut->setText("4");
				ui->five_KBBut->setText("5");
				ui->six_KBBut->setText("6");
				ui->seven_KBBut->setText("7");
				ui->eight_KBBut->setText("8");
				ui->nine_KBBut->setText("9");
				ui->zero_KBBut->setText("0");
				break;
			}
		case 6://German
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral(":"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral(";"));
				ui->G_KBBut->setText(QStringLiteral("\""));
				ui->H_KBBut->setText(QStringLiteral("\""));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("!"));
				ui->R_KBBut->setText(QStringLiteral("$"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("?"));
				ui->one_KBBut->setText("1");
				ui->two_KBBut->setText("2");
				ui->three_KBBut->setText("3");
				ui->four_KBBut->setText("4");
				ui->five_KBBut->setText("5");
				ui->six_KBBut->setText("6");
				ui->seven_KBBut->setText("7");
				ui->eight_KBBut->setText("8");
				ui->nine_KBBut->setText("9");
				ui->zero_KBBut->setText("0");
				break;
			}
		case 7://Farsi
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral(":"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral(";"));
				ui->G_KBBut->setText(QStringLiteral("\""));
				ui->H_KBBut->setText(QStringLiteral("\""));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("!"));
				ui->R_KBBut->setText(QStringLiteral("$"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("?"));
				ui->one_KBBut->setText("1");
				ui->two_KBBut->setText("2");
				ui->three_KBBut->setText("3");
				ui->four_KBBut->setText("4");
				ui->five_KBBut->setText("5");
				ui->six_KBBut->setText("6");
				ui->seven_KBBut->setText("7");
				ui->eight_KBBut->setText("8");
				ui->nine_KBBut->setText("9");
				ui->zero_KBBut->setText("0");
				break;
			}
		case 8://Hindi
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral(":"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral(";"));
				ui->G_KBBut->setText(QStringLiteral("\""));
				ui->H_KBBut->setText(QStringLiteral("\""));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("《"));
				ui->K_KBBut->setText(QStringLiteral("》"));
				ui->L_KBBut->setText(QStringLiteral("、"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("…"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("!"));
				ui->R_KBBut->setText(QStringLiteral("$"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("?"));
				ui->one_KBBut->setText("1");
				ui->two_KBBut->setText("2");
				ui->three_KBBut->setText("3");
				ui->four_KBBut->setText("4");
				ui->five_KBBut->setText("5");
				ui->six_KBBut->setText("6");
				ui->seven_KBBut->setText("7");
				ui->eight_KBBut->setText("8");
				ui->nine_KBBut->setText("9");
				ui->zero_KBBut->setText("0");
				break;
			}
		}
		m_symbol = false;
	}
	else //当前为符号
	{
		btnSymbolSel(m_LantypeReverse);
		m_symbol = true;
	}
}

void keyboard::A_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->A_KBBut->text());
}

void keyboard::B_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->B_KBBut->text());
}

void keyboard::C_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->C_KBBut->text());
}

void keyboard::D_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->D_KBBut->text());
}

void keyboard::E_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->E_KBBut->text());
}

void keyboard::F_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->F_KBBut->text());
}

void keyboard::G_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->G_KBBut->text());
}

void keyboard::H_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->H_KBBut->text());
}

void keyboard::I_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->I_KBBut->text());
}

void keyboard::J_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->J_KBBut->text());
}

void keyboard::K_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->K_KBBut->text());
}

void keyboard::L_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->L_KBBut->text());
}

void keyboard::M_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->M_KBBut->text());
}

void keyboard::N_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->N_KBBut->text());
}

void keyboard::O_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->O_KBBut->text());
}

void keyboard::P_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->P_KBBut->text());
}

void keyboard::Q_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->Q_KBBut->text());
}

void keyboard::R_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->R_KBBut->text());
}

void keyboard::S_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->S_KBBut->text());
}

void keyboard::T_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->T_KBBut->text());
}

void keyboard::U_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->U_KBBut->text());
}

void keyboard::V_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->V_KBBut->text());
}

void keyboard::W_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->W_KBBut->text());
}

void keyboard::X_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->X_KBBut->text());
}

void keyboard::Y_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->Y_KBBut->text());
}

void keyboard::Z_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->Z_KBBut->text());
}

void keyboard::num1_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->one_KBBut->text());
}

void keyboard::num2_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->two_KBBut->text());
}

void keyboard::num3_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->three_KBBut->text());
}

void keyboard::num4_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->four_KBBut->text());
}

void keyboard::num5_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->five_KBBut->text());
}

void keyboard::num6_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->six_KBBut->text());
}

void keyboard::num7_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->seven_KBBut->text());
}

void keyboard::num8_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->eight_KBBut->text());
}

void keyboard::num9_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->nine_KBBut->text());
}

void keyboard::num0_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->zero_KBBut->text());
}

void keyboard::space_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(" ");
}

void keyboard::comma_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->comma_KBBut->text());
}

void keyboard::period_KBBut_clicked()
{
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->period_KBBut->text());
}

void keyboard::btnLanguageSel(int m_LanType)
{
	switch (m_LanType)
	{

	case 0:  //chinese
	case 1:  //Japanese
		{
			LanJapaneseBig();
			break;
		}
	case 3:  //Chinese_others
	case 21: //Japanese_others
		{
			LanChineseBig();
		//	pWnd->btnShow();
		//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
	case 2:  //Korean
	case 22: //Korean_others
		{
			LanKoreanBig();
		//	pWnd->btnShow();
		//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
	case 5:  //Arabic
		{
		//	LanArabic1();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 6:  //Farsi
		{
		//	LanArabic1();
	//		pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 7:  //English
		{
			LanEnglishSmall();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 8:  //Czech
		{
			LanCzechSmall();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 9:  //Dutch
		{
		    LanDutchSmall();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 10: //German
		{
			LanGermanSmall();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 11:  //FarsiSmall
		{
		    LanFarsiSmall();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 12:  //Hindi
		{
		    LanHindiSmall();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 13:  //Hungarian
		{
		    //LanHindiBig();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 14:  //Italian
		{
		//	LanItalian();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 15:  //Portuguese
		{
		//	LanPortuguese();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 16:  //Russian
		{
		//	LanRussian();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 17:  //Spanish
		{
		//	LanSpanish();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 18:  //Swedish
		{
		//	LanSwedish();
	//		pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 19:  //Thai
		{
		//	LanThai();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 20:  //Turkish
		{
		//	LanTurkish();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	
	}
}

void keyboard::btnSymbolSel(int m_LantypeReverse)
{
	switch (m_LantypeReverse)
	{
		case 0: //当前为EnglishSymbol
		{
			SymbolToEnglish();
			//	pWnd->btnShow();
			//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 1: //当前为ChineseSymbol
		{
			SymbolToChinese();
			//	pWnd->btnShow();
			//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 2: //当前为KoreSymbol
		{
			SymbolToKore();
				//	pWnd->btnShow();
				//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 3: //当前为KoreSymbol
		{
			SymbolToCzech();
				//	pWnd->btnShow();
				//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 4: //当前为KoreSymbol
		{
			SymbolToJapanese();
				//	pWnd->btnShow();
				//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 5:
		{
			SymbolToDutch();
			break;
		}
		case 6:
		{
			SymbolToGerman();
			break;
		}
		case 7:
		{
			SymbolToFarsi();
			break;
		}
		case 8:
		{
			SymbolToHindi();
			break;
		}
		
	}

}

void keyboard::LanEnglishSmall()
{
	ui->A_KBBut->setText("a");
	ui->B_KBBut->setText("b");
	ui->C_KBBut->setText("c");
	ui->D_KBBut->setText("d");
	ui->E_KBBut->setText("e");
	ui->F_KBBut->setText("f");
	ui->G_KBBut->setText("g");
	ui->H_KBBut->setText("h");
	ui->I_KBBut->setText("i");
	ui->J_KBBut->setText("j");
	ui->K_KBBut->setText("k");
	ui->L_KBBut->setText("l");
	ui->M_KBBut->setText("m");
	ui->N_KBBut->setText("n");
	ui->O_KBBut->setText("o");
	ui->P_KBBut->setText("p");
	ui->Q_KBBut->setText("q");
	ui->R_KBBut->setText("r");
	ui->S_KBBut->setText("s");
	ui->T_KBBut->setText("t");
	ui->U_KBBut->setText("u");
	ui->V_KBBut->setText("v");
	ui->W_KBBut->setText("w");
	ui->X_KBBut->setText("x");
	ui->Y_KBBut->setText("y");
	ui->Z_KBBut->setText("z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
	/*
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("/"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("z"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("'"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T(";"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("\\"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("]"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("["));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("y"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("="));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("`"));
	*/
}

void keyboard::LanEnglishBig()
{
	ui->A_KBBut->setText("A");
	ui->B_KBBut->setText("B");
	ui->C_KBBut->setText("C");
	ui->D_KBBut->setText("D");
	ui->E_KBBut->setText("E");
	ui->F_KBBut->setText("F");
	ui->G_KBBut->setText("G");
	ui->H_KBBut->setText("H");
	ui->I_KBBut->setText("I");
	ui->J_KBBut->setText("J");
	ui->K_KBBut->setText("K");
	ui->L_KBBut->setText("L");
	ui->M_KBBut->setText("M");
	ui->N_KBBut->setText("N");
	ui->O_KBBut->setText("O");
	ui->P_KBBut->setText("P");
	ui->Q_KBBut->setText("Q");
	ui->R_KBBut->setText("R");
	ui->S_KBBut->setText("S");
	ui->T_KBBut->setText("T");
	ui->U_KBBut->setText("U");
	ui->V_KBBut->setText("V");
	ui->W_KBBut->setText("W");
	ui->X_KBBut->setText("X");
	ui->Y_KBBut->setText("Y");
	ui->Z_KBBut->setText("Z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
}

void keyboard::LanChineseSmall()
{
	ui->A_KBBut->setText("a");
	ui->B_KBBut->setText("b");
	ui->C_KBBut->setText("c");
	ui->D_KBBut->setText("d");
	ui->E_KBBut->setText("e");
	ui->F_KBBut->setText("f");
	ui->G_KBBut->setText("g");
	ui->H_KBBut->setText("h");
	ui->I_KBBut->setText("i");
	ui->J_KBBut->setText("j");
	ui->K_KBBut->setText("k");
	ui->L_KBBut->setText("l");
	ui->M_KBBut->setText("m");
	ui->N_KBBut->setText("n");
	ui->O_KBBut->setText("o");
	ui->P_KBBut->setText("p");
	ui->Q_KBBut->setText("q");
	ui->R_KBBut->setText("r");
	ui->S_KBBut->setText("s");
	ui->T_KBBut->setText("t");
	ui->U_KBBut->setText("u");
	ui->V_KBBut->setText("v");
	ui->W_KBBut->setText("w");
	ui->X_KBBut->setText("x");
	ui->Y_KBBut->setText("y");
	ui->Z_KBBut->setText("z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
}

void keyboard::LanChineseBig()
{
	ui->A_KBBut->setText("A");
	ui->B_KBBut->setText("B");
	ui->C_KBBut->setText("C");
	ui->D_KBBut->setText("D");
	ui->E_KBBut->setText("E");
	ui->F_KBBut->setText("F");
	ui->G_KBBut->setText("G");
	ui->H_KBBut->setText("H");
	ui->I_KBBut->setText("I");
	ui->J_KBBut->setText("J");
	ui->K_KBBut->setText("K");
	ui->L_KBBut->setText("L");
	ui->M_KBBut->setText("M");
	ui->N_KBBut->setText("N");
	ui->O_KBBut->setText("O");
	ui->P_KBBut->setText("P");
	ui->Q_KBBut->setText("Q");
	ui->R_KBBut->setText("R");
	ui->S_KBBut->setText("S");
	ui->T_KBBut->setText("T");
	ui->U_KBBut->setText("U");
	ui->V_KBBut->setText("V");
	ui->W_KBBut->setText("W");
	ui->X_KBBut->setText("X");
	ui->Y_KBBut->setText("Y");
	ui->Z_KBBut->setText("Z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
}

void keyboard::LanKoreanSmall()//韩语小写
{
	ui->A_KBBut->setText(QStringLiteral("ㅁ"));
	ui->B_KBBut->setText(QStringLiteral("ㅠ"));
	ui->C_KBBut->setText(QStringLiteral("ㅊ"));
	ui->D_KBBut->setText(QStringLiteral("ㅇ"));
	ui->E_KBBut->setText(QStringLiteral("ㄷ"));
	ui->F_KBBut->setText(QStringLiteral("ㄹ"));
	ui->G_KBBut->setText(QStringLiteral("ㅎ"));
	ui->H_KBBut->setText(QStringLiteral("ㅗ"));
	ui->I_KBBut->setText(QStringLiteral("ㅑ"));
	ui->J_KBBut->setText(QStringLiteral("ㅓ"));
	ui->K_KBBut->setText(QStringLiteral("ㅏ"));
	ui->L_KBBut->setText(QStringLiteral("ㅣ"));
	ui->M_KBBut->setText(QStringLiteral("ㅡ"));
	ui->N_KBBut->setText(QStringLiteral("ㅜ"));
	ui->O_KBBut->setText(QStringLiteral("ㅐ"));
	ui->P_KBBut->setText(QStringLiteral("ㅔ"));
	ui->Q_KBBut->setText(QStringLiteral("ㅂ"));
	ui->R_KBBut->setText(QStringLiteral("ㄱ"));
	ui->S_KBBut->setText(QStringLiteral("ㄴ"));
	ui->T_KBBut->setText(QStringLiteral("ㅅ"));
	ui->U_KBBut->setText(QStringLiteral("ㅕ"));
	ui->V_KBBut->setText(QStringLiteral("ㅍ"));
	ui->W_KBBut->setText(QStringLiteral("ㅈ"));
	ui->X_KBBut->setText(QStringLiteral("ㅌ"));
	ui->Y_KBBut->setText(QStringLiteral("ㅛ"));
	ui->Z_KBBut->setText(QStringLiteral("ㅋ"));
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");

//
//
//
//	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("/"));
//	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
//	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
//	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("ㅡ"));
//	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ㅜ"));
//	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("ㅠ"));
//	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("ㅍ"));
//	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("ㅊ"));
//	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ㅌ"));
//	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ㅋ"));
//	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("'"));
//	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T(";"));
//	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("ㅣ"));
//	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("ㅏ"));
//	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("ㅓ"));
//	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("ㅗ"));
//	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("ㅎ"));
//	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("ㄹ"));
//	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("ㅇ"));
//	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("ㄴ"));
//	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ㅁ"));
//	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("\\"));
//	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("]"));
//	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("["));
//	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("ㅔ"));
//	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ㅐ"));
//	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("ㅑ"));
//	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ㅕ"));
//	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("ㅛ"));
//	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ㅅ"));
//	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ㄱ"));
//	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ㄷ"));
//	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ㅈ"));
//	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("ㅂ"));
//	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("="));
//	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("-"));
//	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
//	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
//	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
//	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
//	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
//	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
//	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
//	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
//	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
//	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
//	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("`"));*/
//}
}

void keyboard::LanKoreanBig()
{
	ui->A_KBBut->setText(QStringLiteral("ㅁ"));
	ui->B_KBBut->setText(QStringLiteral("파"));
	ui->C_KBBut->setText(QStringLiteral("카"));
	ui->D_KBBut->setText(QStringLiteral("나"));
	ui->E_KBBut->setText(QStringLiteral("ㄸ"));
	ui->F_KBBut->setText(QStringLiteral("다"));
	ui->G_KBBut->setText(QStringLiteral("라"));
	ui->H_KBBut->setText(QStringLiteral("마"));
	ui->I_KBBut->setText(QStringLiteral(""));
	ui->J_KBBut->setText(QStringLiteral("바"));
	ui->K_KBBut->setText(QStringLiteral("사"));
	ui->L_KBBut->setText(QStringLiteral("아"));
	ui->M_KBBut->setText(QStringLiteral(""));
	ui->N_KBBut->setText(QStringLiteral("하"));
	ui->O_KBBut->setText(QStringLiteral("ㅒ"));
	ui->P_KBBut->setText(QStringLiteral("ㅖ"));
	ui->Q_KBBut->setText(QStringLiteral("ㅃ"));
	ui->R_KBBut->setText(QStringLiteral("ㄲ"));
	ui->S_KBBut->setText(QStringLiteral("가"));
	ui->T_KBBut->setText(QStringLiteral("ㅆ"));
	ui->U_KBBut->setText(QStringLiteral(""));
	ui->V_KBBut->setText(QStringLiteral("타"));
	ui->W_KBBut->setText(QStringLiteral("ㅉ"));
	ui->X_KBBut->setText(QStringLiteral("차"));
	ui->Y_KBBut->setText(QStringLiteral(""));
	ui->Z_KBBut->setText(QStringLiteral("자"));
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
}

void keyboard::LanCzechSmall()
{
	ui->A_KBBut->setText("a");
	ui->B_KBBut->setText("b");
	ui->C_KBBut->setText("c");
	ui->D_KBBut->setText("d");
	ui->E_KBBut->setText("e");
	ui->F_KBBut->setText("f");
	ui->G_KBBut->setText("g");
	ui->H_KBBut->setText("h");
	ui->I_KBBut->setText("i");
	ui->J_KBBut->setText("j");
	ui->K_KBBut->setText("k");
	ui->L_KBBut->setText("l");
	ui->M_KBBut->setText("m");
	ui->N_KBBut->setText("n");
	ui->O_KBBut->setText("o");
	ui->P_KBBut->setText("p");
	ui->Q_KBBut->setText("q");
	ui->R_KBBut->setText("r");
	ui->S_KBBut->setText("s");
	ui->T_KBBut->setText("t");
	ui->U_KBBut->setText("u");
	ui->V_KBBut->setText("v");
	ui->W_KBBut->setText("w");
	ui->X_KBBut->setText("x");
	ui->Y_KBBut->setText("z");
	ui->Z_KBBut->setText("y");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("ů"));
	ui->two_KBBut->setText(QStringLiteral("ě"));
	ui->three_KBBut->setText(QStringLiteral("š"));
	ui->four_KBBut->setText(QStringLiteral("č"));
	ui->five_KBBut->setText(QStringLiteral("ř"));
	ui->six_KBBut->setText(QStringLiteral("ž"));
	ui->seven_KBBut->setText(QStringLiteral("ý"));
	ui->eight_KBBut->setText(QStringLiteral("á"));
	ui->nine_KBBut->setText(QStringLiteral("í"));
	ui->zero_KBBut->setText(QStringLiteral("é"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("/"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("y"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("§"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ů"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("¨"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T(")"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ú"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("z"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("´"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("="));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("é"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("í"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("á"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("ý"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("ž"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("ř"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("č"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("š"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("ě"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("+"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T(";"));*/
}

void keyboard::LanCzechBig()
{
	ui->A_KBBut->setText("A");
	ui->B_KBBut->setText("B");
	ui->C_KBBut->setText("C");
	ui->D_KBBut->setText("D");
	ui->E_KBBut->setText("E");
	ui->F_KBBut->setText("F");
	ui->G_KBBut->setText("G");
	ui->H_KBBut->setText("H");
	ui->I_KBBut->setText("I");
	ui->J_KBBut->setText("J");
	ui->K_KBBut->setText("K");
	ui->L_KBBut->setText("L");
	ui->M_KBBut->setText("M");
	ui->N_KBBut->setText("N");
	ui->O_KBBut->setText("O");
	ui->P_KBBut->setText("P");
	ui->Q_KBBut->setText("Q");
	ui->R_KBBut->setText("R");
	ui->S_KBBut->setText("S");
	ui->T_KBBut->setText("T");
	ui->U_KBBut->setText("U");
	ui->V_KBBut->setText("V");
	ui->W_KBBut->setText("W");
	ui->X_KBBut->setText("X");
	ui->Y_KBBut->setText("Z");
	ui->Z_KBBut->setText("Y");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("Ú"));
	ui->two_KBBut->setText(QStringLiteral("Ě"));
	ui->three_KBBut->setText(QStringLiteral("Š"));
	ui->four_KBBut->setText(QStringLiteral("Č"));
	ui->five_KBBut->setText(QStringLiteral("Ř"));
	ui->six_KBBut->setText(QStringLiteral("Ž"));
	ui->seven_KBBut->setText(QStringLiteral("Ý"));
	ui->eight_KBBut->setText(QStringLiteral("Á"));
	ui->nine_KBBut->setText(QStringLiteral("Í"));
	ui->zero_KBBut->setText(QStringLiteral("É"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("?"));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Y"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("!"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ů"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("'"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("("));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Ú"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ˇ"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("%"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("É"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("Í"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("Á"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("Ý"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("Ž"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("Ř"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("Č"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("Š"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("Ě"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("°"));*/
}

void keyboard::LanJapaneseSmall()
{
	ui->A_KBBut->setText("a");
	ui->B_KBBut->setText("b");
	ui->C_KBBut->setText("c");
	ui->D_KBBut->setText("d");
	ui->E_KBBut->setText("e");
	ui->F_KBBut->setText("f");
	ui->G_KBBut->setText("g");
	ui->H_KBBut->setText("h");
	ui->I_KBBut->setText("i");
	ui->J_KBBut->setText("j");
	ui->K_KBBut->setText("k");
	ui->L_KBBut->setText("l");
	ui->M_KBBut->setText("m");
	ui->N_KBBut->setText("n");
	ui->O_KBBut->setText("o");
	ui->P_KBBut->setText("p");
	ui->Q_KBBut->setText("q");
	ui->R_KBBut->setText("r");
	ui->S_KBBut->setText("s");
	ui->T_KBBut->setText("t");
	ui->U_KBBut->setText("u");
	ui->V_KBBut->setText("v");
	ui->W_KBBut->setText("w");
	ui->X_KBBut->setText("x");
	ui->Y_KBBut->setText("y");
	ui->Z_KBBut->setText("z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
}

void keyboard::LanJapaneseBig()
{
	ui->A_KBBut->setText("A");
	ui->B_KBBut->setText("B");
	ui->C_KBBut->setText("C");
	ui->D_KBBut->setText("D");
	ui->E_KBBut->setText("E");
	ui->F_KBBut->setText("F");
	ui->G_KBBut->setText("G");
	ui->H_KBBut->setText("H");
	ui->I_KBBut->setText("I");
	ui->J_KBBut->setText("J");
	ui->K_KBBut->setText("K");
	ui->L_KBBut->setText("L");
	ui->M_KBBut->setText("M");
	ui->N_KBBut->setText("N");
	ui->O_KBBut->setText("O");
	ui->P_KBBut->setText("P");
	ui->Q_KBBut->setText("Q");
	ui->R_KBBut->setText("R");
	ui->S_KBBut->setText("S");
	ui->T_KBBut->setText("T");
	ui->U_KBBut->setText("U");
	ui->V_KBBut->setText("V");
	ui->W_KBBut->setText("W");
	ui->X_KBBut->setText("X");
	ui->Y_KBBut->setText("Y");
	ui->Z_KBBut->setText("Z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
}

void keyboard::LanDutchSmall()
{
	ui->A_KBBut->setText("a");
	ui->B_KBBut->setText("b");
	ui->C_KBBut->setText("c");
	ui->D_KBBut->setText("d");
	ui->E_KBBut->setText("e");
	ui->F_KBBut->setText("f");
	ui->G_KBBut->setText("g");
	ui->H_KBBut->setText("h");
	ui->I_KBBut->setText("i");
	ui->J_KBBut->setText("j");
	ui->K_KBBut->setText("k");
	ui->L_KBBut->setText("l");
	ui->M_KBBut->setText("m");
	ui->N_KBBut->setText("n");
	ui->O_KBBut->setText("o");
	ui->P_KBBut->setText("p");
	ui->Q_KBBut->setText("q");
	ui->R_KBBut->setText("r");
	ui->S_KBBut->setText("s");
	ui->T_KBBut->setText("t");
	ui->U_KBBut->setText("u");
	ui->V_KBBut->setText("v");
	ui->W_KBBut->setText("w");
	ui->X_KBBut->setText("x");
	ui->Y_KBBut->setText("y");
	ui->Z_KBBut->setText("z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
}

void keyboard::LanDutchBig()
{
	ui->A_KBBut->setText("A");
	ui->B_KBBut->setText("B");
	ui->C_KBBut->setText("C");
	ui->D_KBBut->setText("D");
	ui->E_KBBut->setText("E");
	ui->F_KBBut->setText("F");
	ui->G_KBBut->setText("G");
	ui->H_KBBut->setText("H");
	ui->I_KBBut->setText("I");
	ui->J_KBBut->setText("J");
	ui->K_KBBut->setText("K");
	ui->L_KBBut->setText("L");
	ui->M_KBBut->setText("M");
	ui->N_KBBut->setText("N");
	ui->O_KBBut->setText("O");
	ui->P_KBBut->setText("P");
	ui->Q_KBBut->setText("Q");
	ui->R_KBBut->setText("R");
	ui->S_KBBut->setText("S");
	ui->T_KBBut->setText("T");
	ui->U_KBBut->setText("U");
	ui->V_KBBut->setText("V");
	ui->W_KBBut->setText("W");
	ui->X_KBBut->setText("X");
	ui->Y_KBBut->setText("Y");
	ui->Z_KBBut->setText("Z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("!"));
	ui->two_KBBut->setText(QStringLiteral("\\"));
	ui->three_KBBut->setText(QStringLiteral("#"));
	ui->four_KBBut->setText(QStringLiteral("$"));
	ui->five_KBBut->setText(QStringLiteral("%"));
	ui->six_KBBut->setText(QStringLiteral("&&"));
	ui->seven_KBBut->setText(QStringLiteral("_"));
	ui->eight_KBBut->setText(QStringLiteral("("));
	ui->nine_KBBut->setText(QStringLiteral(")"));
	ui->zero_KBBut->setText(QStringLiteral("'"));
	//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("="));
	//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
	//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
	//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
	//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
	//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
	//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
	//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
	//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
	//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
	//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("`"));
	//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("±"));
	//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
	//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
	//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
	//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
	//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
	//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
	//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
	//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
	//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
	//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T(">"));
	//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("|"));
	//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("^"));
	//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
	//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
	//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
	//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
	//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
	//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
	//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
	//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
	//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
	//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
	//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("~"));
	//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
	//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("'"));
	//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
	//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
	//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("_"));
	//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&"));
	//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
	//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
	//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
	//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
	//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
	//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("§"));
	//		break;
}

void keyboard::LanGermanSmall()
{
	ui->A_KBBut->setText("a");
	ui->B_KBBut->setText("b");
	ui->C_KBBut->setText("c");
	ui->D_KBBut->setText("d");
	ui->E_KBBut->setText("e");
	ui->F_KBBut->setText("f");
	ui->G_KBBut->setText("g");
	ui->H_KBBut->setText("h");
	ui->I_KBBut->setText("i");
	ui->J_KBBut->setText("j");
	ui->K_KBBut->setText("k");
	ui->L_KBBut->setText("l");
	ui->M_KBBut->setText("m");
	ui->N_KBBut->setText("n");
	ui->O_KBBut->setText("o");
	ui->P_KBBut->setText("p");
	ui->Q_KBBut->setText("q");
	ui->R_KBBut->setText("r");
	ui->S_KBBut->setText("s");
	ui->T_KBBut->setText("t");
	ui->U_KBBut->setText("u");
	ui->V_KBBut->setText("v");
	ui->W_KBBut->setText("w");
	ui->X_KBBut->setText("x");
	ui->Y_KBBut->setText("z");
	ui->Z_KBBut->setText("y");
	ui->comma_KBBut->setText(QStringLiteral("ä"));
	ui->period_KBBut->setText(QStringLiteral("ö"));
	ui->one_KBBut->setText("1");
	ui->two_KBBut->setText("2");
	ui->three_KBBut->setText("3");
	ui->four_KBBut->setText("4");
	ui->five_KBBut->setText("5");
	ui->six_KBBut->setText("6");
	ui->seven_KBBut->setText("7");
	ui->eight_KBBut->setText("8");
	ui->nine_KBBut->setText("9");
	ui->zero_KBBut->setText("0");
}

void keyboard::LanGermanBig()
{
	ui->A_KBBut->setText("A");
	ui->B_KBBut->setText("B");
	ui->C_KBBut->setText("C");
	ui->D_KBBut->setText("D");
	ui->E_KBBut->setText("E");
	ui->F_KBBut->setText("F");
	ui->G_KBBut->setText("G");
	ui->H_KBBut->setText("H");
	ui->I_KBBut->setText("I");
	ui->J_KBBut->setText("J");
	ui->K_KBBut->setText("K");
	ui->L_KBBut->setText("L");
	ui->M_KBBut->setText("M");
	ui->N_KBBut->setText("N");
	ui->O_KBBut->setText("O");
	ui->P_KBBut->setText("P");
	ui->Q_KBBut->setText("Q");
	ui->R_KBBut->setText("R");
	ui->S_KBBut->setText("S");
	ui->T_KBBut->setText("T");
	ui->U_KBBut->setText("U");
	ui->V_KBBut->setText("V");
	ui->W_KBBut->setText("W");
	ui->X_KBBut->setText("X");
	ui->Y_KBBut->setText("Z");
	ui->Z_KBBut->setText("Y");
	ui->comma_KBBut->setText(QStringLiteral("Ä"));//德语这里没有逗号
	ui->period_KBBut->setText(QStringLiteral("Ö"));//德语的专属符号
	ui->one_KBBut->setText(QStringLiteral("!"));
	ui->two_KBBut->setText(QStringLiteral("\\"));
	ui->three_KBBut->setText(QStringLiteral("§"));
	ui->four_KBBut->setText(QStringLiteral("$"));
	ui->five_KBBut->setText(QStringLiteral("%"));
	ui->six_KBBut->setText(QStringLiteral("&&"));
	ui->seven_KBBut->setText(QStringLiteral("_"));
	ui->eight_KBBut->setText(QStringLiteral("("));
	ui->nine_KBBut->setText(QStringLiteral(")"));
	ui->zero_KBBut->setText(QStringLiteral("'"));
}

void keyboard::LanFarsiSmall()
{
	ui->A_KBBut->setText("a");
	ui->B_KBBut->setText("b");
	ui->C_KBBut->setText("c");
	ui->D_KBBut->setText("d");
	ui->E_KBBut->setText("e");
	ui->F_KBBut->setText("f");
	ui->G_KBBut->setText("g");
	ui->H_KBBut->setText("h");
	ui->I_KBBut->setText("i");
	ui->J_KBBut->setText("j");
	ui->K_KBBut->setText("k");
	ui->L_KBBut->setText("l");
	ui->M_KBBut->setText("m");
	ui->N_KBBut->setText("n");
	ui->O_KBBut->setText("o");
	ui->P_KBBut->setText("p");
	ui->Q_KBBut->setText("q");
	ui->R_KBBut->setText("r");
	ui->S_KBBut->setText("s");
	ui->T_KBBut->setText("t");
	ui->U_KBBut->setText("u");
	ui->V_KBBut->setText("v");
	ui->W_KBBut->setText("w");
	ui->X_KBBut->setText("x");
	ui->Y_KBBut->setText("y");
	ui->Z_KBBut->setText("z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("½"));
	ui->two_KBBut->setText(QStringLiteral("¤"));
	ui->three_KBBut->setText(QStringLiteral("`"));
	ui->four_KBBut->setText(QStringLiteral("å"));
	ui->five_KBBut->setText(QStringLiteral("´"));
	ui->six_KBBut->setText(QStringLiteral("'"));
	ui->seven_KBBut->setText(QStringLiteral("ä"));
	ui->eight_KBBut->setText(QStringLiteral("ö"));
	ui->nine_KBBut->setText(QStringLiteral("§"));
	ui->zero_KBBut->setText(QStringLiteral("¨"));
}

void keyboard::LanFarsiBig()
{
	ui->A_KBBut->setText("A");
	ui->B_KBBut->setText("B");
	ui->C_KBBut->setText("C");
	ui->D_KBBut->setText("D");
	ui->E_KBBut->setText("E");
	ui->F_KBBut->setText("F");
	ui->G_KBBut->setText("G");
	ui->H_KBBut->setText("H");
	ui->I_KBBut->setText("I");
	ui->J_KBBut->setText("J");
	ui->K_KBBut->setText("K");
	ui->L_KBBut->setText("L");
	ui->M_KBBut->setText("M");
	ui->N_KBBut->setText("N");
	ui->O_KBBut->setText("O");
	ui->P_KBBut->setText("P");
	ui->Q_KBBut->setText("Q");
	ui->R_KBBut->setText("R");
	ui->S_KBBut->setText("S");
	ui->T_KBBut->setText("T");
	ui->U_KBBut->setText("U");
	ui->V_KBBut->setText("V");
	ui->W_KBBut->setText("W");
	ui->X_KBBut->setText("X");
	ui->Y_KBBut->setText("Y");
	ui->Z_KBBut->setText("Z");
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("½"));
	ui->two_KBBut->setText(QStringLiteral("¤"));
	ui->three_KBBut->setText(QStringLiteral("`"));
	ui->four_KBBut->setText(QStringLiteral("Å"));
	ui->five_KBBut->setText(QStringLiteral("´"));
	ui->six_KBBut->setText(QStringLiteral("'"));
	ui->seven_KBBut->setText(QStringLiteral("Ä"));
	ui->eight_KBBut->setText(QStringLiteral("Ö"));
	ui->nine_KBBut->setText(QStringLiteral("§"));
	ui->zero_KBBut->setText(QStringLiteral("¨"));
	//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
	//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
	//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
	//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
	//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
	//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
	//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
	//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
	//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
	//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
	//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ä"));
	//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ö"));
	//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
	//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
	//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
	//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
	//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
	//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
	//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
	//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
	//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
	//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("'"));
	//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("´"));
	//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Å"));
	//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
	//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
	//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
	//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
	//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
	//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
	//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
	//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
	//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
	//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
	//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("`"));
	//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
	//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
	//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
	//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
	//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
	//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&"));
	//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
	//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("¤"));
	//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
	//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
	//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
	//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("½"));
	//		break;
	//	}
}

void keyboard::LanHindiSmall()
{
	ui->A_KBBut->setText(QStringLiteral("ो"));
	ui->B_KBBut->setText(QStringLiteral("व"));
	ui->C_KBBut->setText(QStringLiteral("म"));
	ui->D_KBBut->setText(QStringLiteral("्"));
	ui->E_KBBut->setText(QStringLiteral("ा"));
	ui->F_KBBut->setText(QStringLiteral("ि"));
	ui->G_KBBut->setText(QStringLiteral("ु"));
	ui->H_KBBut->setText(QStringLiteral("प"));
	ui->I_KBBut->setText(QStringLiteral("ग"));
	ui->J_KBBut->setText(QStringLiteral("र"));
	ui->K_KBBut->setText(QStringLiteral("क"));
	ui->L_KBBut->setText(QStringLiteral("त"));
	ui->M_KBBut->setText(QStringLiteral("स"));
	ui->N_KBBut->setText(QStringLiteral("ल"));
	ui->O_KBBut->setText(QStringLiteral("द"));
	ui->P_KBBut->setText(QStringLiteral("ज"));
	ui->Q_KBBut->setText(QStringLiteral("ौ"));
	ui->R_KBBut->setText(QStringLiteral("ी"));
	ui->S_KBBut->setText(QStringLiteral("े"));
	ui->T_KBBut->setText(QStringLiteral("ू"));
	ui->U_KBBut->setText(QStringLiteral("ह"));
	ui->V_KBBut->setText(QStringLiteral("न"));
	ui->W_KBBut->setText(QStringLiteral("ै"));
	ui->X_KBBut->setText(QStringLiteral("ं"));
	ui->Y_KBBut->setText(QStringLiteral("ब"));
	ui->Z_KBBut->setText(QStringLiteral("ॆ"));
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("ऍ"));
	ui->two_KBBut->setText(QStringLiteral("ॅ"));
	ui->three_KBBut->setText(QStringLiteral("्य"));
	ui->four_KBBut->setText(QStringLiteral("ट"));
	ui->five_KBBut->setText(QStringLiteral("च"));
	ui->six_KBBut->setText(QStringLiteral("ॉ"));
	ui->seven_KBBut->setText(QStringLiteral("़"));
	ui->eight_KBBut->setText(QStringLiteral("ड"));
	ui->nine_KBBut->setText(QStringLiteral("ृ"));
	ui->zero_KBBut->setText(QStringLiteral("ॊ"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("य"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("स"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ल"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("व"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("न"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("म"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ं"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ॆ"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ट"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("च"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("त"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("क"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("र"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("प"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("ु"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("ि"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("्"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("े"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ो"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ॉ"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("़"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ड"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("ज"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("द"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("ग"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ह"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("ब"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ू"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ी"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ा"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ै"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("ौ"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ृ"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ॊ"));*/
}

void keyboard::LanHindiBig()
{                                                //很多符号没有放上
	ui->A_KBBut->setText(QStringLiteral("ओ"));
	ui->B_KBBut->setText(QStringLiteral("ऴ"));
	ui->C_KBBut->setText(QStringLiteral("ण"));
	ui->D_KBBut->setText(QStringLiteral("अ"));
	ui->E_KBBut->setText(QStringLiteral("आ"));
	ui->F_KBBut->setText(QStringLiteral("इ"));
	ui->G_KBBut->setText(QStringLiteral("उ"));
	ui->H_KBBut->setText(QStringLiteral("फ"));
	ui->I_KBBut->setText(QStringLiteral("ँ"));
	ui->J_KBBut->setText(QStringLiteral("ऱ"));
	ui->K_KBBut->setText(QStringLiteral("ख"));
	ui->L_KBBut->setText(QStringLiteral("थ"));
	ui->M_KBBut->setText(QStringLiteral("श"));
	ui->N_KBBut->setText(QStringLiteral("ळ"));
	ui->O_KBBut->setText(QStringLiteral("ध"));
	ui->P_KBBut->setText(QStringLiteral("झ"));
	ui->Q_KBBut->setText(QStringLiteral("औ"));
	ui->R_KBBut->setText(QStringLiteral("ई"));
	ui->S_KBBut->setText(QStringLiteral("ए"));
	ui->T_KBBut->setText(QStringLiteral("घ"));
	ui->U_KBBut->setText(QStringLiteral("ङ"));
	ui->V_KBBut->setText(QStringLiteral("ऩ"));
	ui->W_KBBut->setText(QStringLiteral("ऐ"));
	ui->X_KBBut->setText(QStringLiteral("ँ"));
	ui->Y_KBBut->setText(QStringLiteral("भ"));
	ui->Z_KBBut->setText(QStringLiteral("ऎ"));
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("ऒ"));
	ui->two_KBBut->setText(QStringLiteral("ः"));
	ui->three_KBBut->setText(QStringLiteral("्र"));
	ui->four_KBBut->setText(QStringLiteral("र्"));
	ui->five_KBBut->setText(QStringLiteral("ज्ञ"));
	ui->six_KBBut->setText(QStringLiteral("त्र"));
	ui->seven_KBBut->setText(QStringLiteral("क्ष"));
	ui->eight_KBBut->setText(QStringLiteral("श्र"));
	ui->nine_KBBut->setText(QStringLiteral("("));
	ui->zero_KBBut->setText(QStringLiteral(")"));
	//      GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("य़"));  没放上
	//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("।"));   没放上
	//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("ष"));   没放上
	//		GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("श"));
	//		GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ळ"));
	//		GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("ऴ"));
	//		GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("ऩ"));
	//		GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("ण"));
	//		GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ँ"));
	//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ऎ"));
	//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ठ"));   没放上
	//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("छ"));    没放上
	//		GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("थ"));
	//		GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("ख"));
	//		GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("ऱ"));
	//		GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("फ"));
	//		GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("उ"));
	//		GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("इ"));
	//		GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("अ"));
	//		GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("ए"));
	//		GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ओ"));
	//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ऑ"));   没放上
	//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("ञ"));    没放上
	//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ढ"));     没放上
	//		GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("झ"));
	//		GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ध"));
	//		GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("घ"));
	//		GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ङ"));
	//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("भ"));
	//		GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ऊ"));
	//		GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ई"));
	//		GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("आ"));
	//		GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ऐ"));
	//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("औ"));
	//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ऋ"));    没放上
	//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("ः"));
	//		GetDlgItem(IDC_MIAN_0)->SetWindowText(_T(")"));
	//		GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("("));
	//		GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("श्र"));
	//		GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("क्ष"));
	//		GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("त्र"));
	//		GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("ज्ञ"));
	//		GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("र्"));
	//		GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("्र"));
	//		GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("ॅ"));
	//		GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("ऍ"));
	//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ऒ"));
	//		break;
}

void keyboard::SymbolToEnglish()
{
	LanEnglishBig();
	m_Upper = false;
}

void keyboard::SymbolToChinese()
{
	LanChineseSmall();
	m_Upper = false;
}

void keyboard::SymbolToKore()
{
	LanKoreanSmall();
	m_Upper = false;
}

void keyboard::SymbolToCzech()
{
	LanCzechBig();
	m_Upper = false;
}

void keyboard::SymbolToJapanese()
{
	LanJapaneseSmall();
	m_Upper = false;
}

void keyboard::SymbolToDutch()
{
	LanDutchBig();
	m_Upper = false;
}

void keyboard::SymbolToGerman()
{
	LanGermanBig();
	m_Upper = false;
}

void keyboard::SymbolToFarsi()
{
	LanFarsiBig();
	m_Upper = false;
}

void keyboard::SymbolToHindi()
{
	LanHindiBig();
	m_Upper = false;
}
