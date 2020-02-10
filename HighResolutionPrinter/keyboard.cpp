#include "keyboard.h"
#include "ui_keyboard.h"
#include <QAction>
#include <QtWidgets/QStackedWidget>
#include "lineedit_click.h"
#include "language.h"
#include "fileeditchild.h"
#include <QTabWidget>
#include <QHBoxLayout>

keyboard::keyboard(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::keyboard)

{
	ui->setupUi(this);
	languageWidget = new language(this);
	languageWidget->setVisible(false);
	btnhide();
	btnArabicARhide();

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
	connect(ui->languageAdd_KBBut,SIGNAL(clicked()),this,SLOT(lanArabicAdd_KBBut_clicked()));
	connect(ui->languageRedu_KBBut,SIGNAL(clicked()),this,SLOT(lanArabicRedu_KBBut_clicked()));
	connect(ui->fontBox1_KBBut,SIGNAL(clicked()),this,SLOT(fontBox1_KBBut_clicked()));
	connect(ui->fontBox2_KBBut,SIGNAL(clicked()),this,SLOT(fontBox2_KBBut_clicked()));
	connect(ui->fontBox3_KBBut,SIGNAL(clicked()),this,SLOT(fontBox3_KBBut_clicked()));
	connect(ui->fontBox4_KBBut,SIGNAL(clicked()),this,SLOT(fontBox4_KBBut_clicked()));
	connect(ui->fontBox5_KBBut,SIGNAL(clicked()),this,SLOT(fontBox5_KBBut_clicked()));
	connect(ui->fontBox6_KBBut,SIGNAL(clicked()),this,SLOT(fontBox6_KBBut_clicked()));
	connect(ui->fontBox7_KBBut,SIGNAL(clicked()),this,SLOT(fontBox7_KBBut_clicked()));
	connect(ui->fontBox8_KBBut,SIGNAL(clicked()),this,SLOT(fontBox8_KBBut_clicked()));
	connect(ui->fontBox9_KBBut,SIGNAL(clicked()),this,SLOT(fontBox9_KBBut_clicked()));
	connect(ui->fontBox10_KBBut,SIGNAL(clicked()),this,SLOT(fontBox10_KBBut_clicked()));
	connect(ui->fontBoxRedu_KBBut,SIGNAL(clicked()),this,SLOT(fontBoxRedu_KBBut_clicked()));
	connect(ui->fontBoxAdd_KBBut,SIGNAL(clicked()),this,SLOT(fontBoxAdd_KBBut_clicked()));


	connect(ui->enter_KBBut,SIGNAL(clicked()),this,SLOT(enter_KBBut_clicked()));
	connect(ui->Esc_KBBut,SIGNAL(clicked()),this,SLOT(Esc_KBBut_clicked()));
	connect(ui->backspace_KBBut,SIGNAL(clicked()),this,SLOT(backspace_KBBut_clicked()));
	connect(ui->language_KBBut,SIGNAL(clicked()),this,SLOT(language_KBBut_clicked()));
	//connect(ui->shift_KBBut,SIGNAL(clicked()),this,SLOT(caps_KBBut_clicked()));
	connect(ui->shift_KBBut,SIGNAL(clicked()),this,SLOT(caps1_kBBut_clicked()));
	connect(ui->symbol_KBBut,SIGNAL(clicked()),this,SLOT(symbol_KBBut_clicked()));
	//connect(ui->wordCombLineEdit,SIGNAL(textChanged()),this,SLOT(languagespell()));
	//connect(ui->wordCombLineEdit,SIGNAL(textChanged()),this,SLOT(languagespell()));
	connect(ui->wordCombLineEdit,SIGNAL(textChanged(QString)),this,SLOT(languagespell()));
	

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

void keyboard::Esc_KBBut_clicked()
{
	this->setVisible(false);
}

void keyboard::backspace_KBBut_clicked()
{
	setText2KBLineedit();
	if (m_pInputEdit->text() != "")
	{
		m_pInputEdit->backspace();
	} 
	else
	{
		changeCurrentlineedit();
	    m_pInputEdit->backspace();
	}
	setText2KBLineedit();
}

void keyboard::language_KBBut_clicked()
{
	languageWidget->setVisible(true);
}

void keyboard::btnhide()
{
	ui->fontBox1_KBBut->hide();
	ui->fontBox2_KBBut->hide();
	ui->fontBox3_KBBut->hide();
	ui->fontBox4_KBBut->hide();
	ui->fontBox5_KBBut->hide();
	ui->fontBox6_KBBut->hide();
	ui->fontBox7_KBBut->hide();
	ui->fontBox8_KBBut->hide();
	ui->fontBox9_KBBut->hide();
	ui->fontBox10_KBBut->hide();
	ui->fontBoxRedu_KBBut->hide();
	ui->fontBoxAdd_KBBut->hide();
	ui->wordCombLineEdit->hide();
}

void keyboard::btnArabicARhide()
{
	ui->languageAdd_KBBut->hide();
	ui->languageRedu_KBBut->hide();
}

void keyboard::setText2KBLineedit()
{
	m_pInputEdit = ui->wordCombLineEdit;
}


void keyboard::changeCurrentlineedit()
{
	QTabWidget *qtabwidget = qobject_cast<QTabWidget*>(this->parentWidget());
	FileEditChild *pFileEditChild =qobject_cast<FileEditChild*>(qtabwidget->parentWidget());
	pFileEditChild->wordLineEdit_clicked();
}

void keyboard::languagespell()   //��ȡ���ı༭���ڵ�ƴ�� ����Ӧ�ĺ������뱸ѡ����
{
	switch (m_LanType)
	{
	case 0: //chinese
		{	
			QString key = m_pInputEdit->text();
			CreateChineseMapLan();
			QString value = ChineseLanMap[key];
			if ( value == "" )          
			{	
                        splitOut.clear();
              		i1 = 0;
				j1 = 0;
				QString Delstr = (QStringLiteral(" , , , , , , , , , , , , , , ,"));
				QStringList temp = Delstr.split(",");
				int length = temp.length();

				for ( int i =0 ;i < length;i++)
				{
					splitOut.push_back(temp.at(i));
				} 
				FontSelect();
				splitOut.clear();
			}
			else
			{
				j1 = 0;
				//value +=QStringLiteral(",");
				//splitOut = split(value);
				QStringList temp = value.split(",");//�Զ��ŷָ��ַ���������ѡ��ÿ�����ֵ����ָ��һ���ַ���
				int length = temp.length();//��ȡ�ָ����ַ�������

				for ( int i =0 ;i < length;i++)//��������ÿһ���ַ������뵽vector��Ӧ��λ��
				{
					splitOut.push_back(temp.at(i));
				} 
				if ( splitOut.size() < 11 )
				{
					i1 = 1;
				} 
				else if( splitOut.size() <21)
				{
					i1 = 11;
				}
				else if( splitOut.size() < 31)
				{
					i1 = 21;
				}
				else
				{
					i1 = 31;
				}
				FontSelect();
				//break;
			}
			break;
		}
	case 1: //Japanese
		{	
			QString key = m_pInputEdit->text();
			CreateJapaneseMapLan();
			QString value = JapaneseLanMap[key];
			if ( value == "" )          
			{	
                        splitOut.clear();
              		i1 = 0;
				j1 = 0;
				QString Delstr = (QStringLiteral(" , , , , , , , , , , , , , , ,"));
				QStringList temp = Delstr.split(",");
				int length = temp.length();

				for ( int i =0 ;i < length;i++)
				{
					splitOut.push_back(temp.at(i));
				} 
				FontSelect();
				splitOut.clear();
			}
			else
			{
				j1 = 0;
				//value +=QStringLiteral(",");
				//splitOut = split(value);
				QStringList temp = value.split(",");//�Զ��ŷָ��ַ���������ѡ��ÿ�����ֵ����ָ��һ���ַ���
				int length = temp.length();//��ȡ�ָ����ַ�������

				for ( int i =0 ;i < length;i++)//��������ÿһ���ַ������뵽vector��Ӧ��λ��
				{
					splitOut.push_back(temp.at(i));
				} 
				if ( splitOut.size() < 11 )
				{
					i1 = 1;
				} 
				else if( splitOut.size() <21)
				{
					i1 = 11;
				}
				else if( splitOut.size() < 31)
				{
					i1 = 21;
				}
				else
				{
					i1 = 31;
				}
				FontSelect();
				//break;
			}
			break;
		}
	case 22: //Korean
		{	
			QString key = m_pInputEdit->text();
			CreateKoreanMapLan();
			QString value = KoreanLanMap[key];
			if ( value == "" )          
			{	
                        splitOut.clear();
              		i1 = 0;
				j1 = 0;
				QString Delstr = (QStringLiteral(" , , , , , , , , , , , , , , ,"));
				QStringList temp = Delstr.split(",");
				int length = temp.length();

				for ( int i =0 ;i < length;i++)
				{
					splitOut.push_back(temp.at(i));
				} 
				FontSelect();
				splitOut.clear();
			}
			else
			{
				j1 = 0;
				//value +=QStringLiteral(",");
				//splitOut = split(value);
				QStringList temp = value.split(",");//�Զ��ŷָ��ַ���������ѡ��ÿ�����ֵ����ָ��һ���ַ���
				int length = temp.length();//��ȡ�ָ����ַ�������

				for ( int i =0 ;i < length;i++)//��������ÿһ���ַ������뵽vector��Ӧ��λ��
				{
					splitOut.push_back(temp.at(i));
				} 
				if ( splitOut.size() < 11 )
				{
					i1 = 1;
				} 
				else if( splitOut.size() <21)
				{
					i1 = 11;
				}
				else if( splitOut.size() < 31)
				{
					i1 = 21;
				}
				else
				{
					i1 = 31;
				}
				FontSelect();
				//break;
			}
			break;
		}

	}
}

void keyboard::CreateChineseMapLan()//�����ֿ�

{
	ChineseLanMap[QStringLiteral("an")] = QStringLiteral("��,��,��,��,��,��,��,��,��, , , , , , ");
	ChineseLanMap[QStringLiteral("ai")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��, , ");
	ChineseLanMap[QStringLiteral("a")] = QStringLiteral("��,��, , , , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("yi")] = QStringLiteral("һ,��,��,ҽ,��,ҿ,Ҽ,Ҿ,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , ");
	ChineseLanMap[QStringLiteral("ang")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("ao")] = QStringLiteral("��,��,��,��,��,��,��,��,��, , , , , , ");
	ChineseLanMap[QStringLiteral("ba")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bai")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");
	ChineseLanMap[QStringLiteral("ban")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��");
	ChineseLanMap[QStringLiteral("bang")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��, , , ");
	ChineseLanMap[QStringLiteral("bao")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bei")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��");
	ChineseLanMap[QStringLiteral("ben")] = QStringLiteral("��,��,��,��,��, , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("beng")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , ,");

	ChineseLanMap[QStringLiteral("bi")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , ");
	ChineseLanMap[QStringLiteral("bian")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��, , , ");
	ChineseLanMap[QStringLiteral("biao")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bie")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bin")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bing")] = QStringLiteral("��,��,��,��,��,��,��,��,��, , , , , , ");
	ChineseLanMap[QStringLiteral("bo")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("bu")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��, , , , , ");
	ChineseLanMap[QStringLiteral("ca")] = QStringLiteral("��, , , , , , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("cai")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��, , , , ");
	ChineseLanMap[QStringLiteral("can")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");
	ChineseLanMap[QStringLiteral("cang")] = QStringLiteral("��,��,��,��,��, , , , , , , , , , ");
	ChineseLanMap[QStringLiteral("cao")] = QStringLiteral("��,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ce")] = QStringLiteral("��,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ceng")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cha")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,ɲ, , , ");


	ChineseLanMap[QStringLiteral("chai")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chan")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��, , , , , ");


	ChineseLanMap[QStringLiteral("chang")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��, , , ");


	ChineseLanMap[QStringLiteral("chao")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��, , , , , ");


	ChineseLanMap[QStringLiteral("che")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chen")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��, , , , , ");


	ChineseLanMap[QStringLiteral("cheng")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��");


	ChineseLanMap[QStringLiteral("chi")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��");


	ChineseLanMap[QStringLiteral("chong")] = QStringLiteral("��,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chou")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��, , , ");


	ChineseLanMap[QStringLiteral("chu")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chuai")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chuan")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("chuang")] = QStringLiteral("��,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("chun")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("chuo")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ci")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��, , , ");


	ChineseLanMap[QStringLiteral("cong")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cou")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cu")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cuan")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cui")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("cun")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("cuo")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("da")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dai")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��, , , ");


	ChineseLanMap[QStringLiteral("dan")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��");


	ChineseLanMap[QStringLiteral("dang")] = QStringLiteral("��,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dao")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��, , , ");


	ChineseLanMap[QStringLiteral("de")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("deng")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("di")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dian")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("diao")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("die")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("ding")] = QStringLiteral("��,��,��,��,��,��,��,��,��, , , , , , ");


	ChineseLanMap[QStringLiteral("diu")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dong")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��, , , , , ");


	ChineseLanMap[QStringLiteral("dou")] = QStringLiteral("��,�� ,��,��,��,��,��,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("du")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��, ");


	ChineseLanMap[QStringLiteral("duan")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dui")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("dun")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("duo")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��, , , ");


	ChineseLanMap[QStringLiteral("e")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��, , ");


	ChineseLanMap[QStringLiteral("en")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("er")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("fa")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");



	ChineseLanMap[QStringLiteral("fan")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("fang")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("fei")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��, , , ");


	ChineseLanMap[QStringLiteral("fen")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��");


	ChineseLanMap[QStringLiteral("feng")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��");


	ChineseLanMap[QStringLiteral("fo")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("fou")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("fu")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, ");


	ChineseLanMap[QStringLiteral("ga")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gai")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gan")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("gang")] = QStringLiteral("��,��,��,��,��,��,��,��,��, , , , , , ");


	ChineseLanMap[QStringLiteral("gao")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��, , , , , ");


	ChineseLanMap[QStringLiteral("ge")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gei")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gen")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("geng")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("gong")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��");


	ChineseLanMap[QStringLiteral("gou")] = QStringLiteral("��,��,��,��,��,��,��,��,��, , , , , , ");


	ChineseLanMap[QStringLiteral("gu")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gua")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("guai")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("guan")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("guang")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gui")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("gun")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("guo")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ha")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hai")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("han")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hang")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hao")] = QStringLiteral("��,��,��,��,��,��,��,��,��, , , , , , ");


	ChineseLanMap[QStringLiteral("he")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hei")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hen")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("heng")] = QStringLiteral("��,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hong")] = QStringLiteral("��,��,��,��,��,��,��,��,��, , , , , , ");


	ChineseLanMap[QStringLiteral("hou")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("hu")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hua")] = QStringLiteral("��,��,��,��,��,��,��,��,��, , , , , , ");


	ChineseLanMap[QStringLiteral("huai")] = QStringLiteral("��,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("huan")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��, ");


	ChineseLanMap[QStringLiteral("huang")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��, ");


	ChineseLanMap[QStringLiteral("hui")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("hun")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("huo")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��, , , , , ");


	ChineseLanMap[QStringLiteral("ji")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , ");


	ChineseLanMap[QStringLiteral("jia")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,Ю, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("jian")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , ");


	ChineseLanMap[QStringLiteral("jiang")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��, , ");


	ChineseLanMap[QStringLiteral("jiao")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , ");


	ChineseLanMap[QStringLiteral("jie")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , ");


	ChineseLanMap[QStringLiteral("jin")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("jing")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , ");


	ChineseLanMap[QStringLiteral("jiong")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("jiu")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ju")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("juan")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("jue")] = QStringLiteral("��,��,��,��,��,��,��,��,��, , , , , , ");


	ChineseLanMap[QStringLiteral("jun")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("ka")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kai")] = QStringLiteral("��,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kan")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("kang")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("kao")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ke")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��");


	ChineseLanMap[QStringLiteral("ken")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("keng")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kong")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kou")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ku")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("kua")] = QStringLiteral("��,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kuai")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kuan")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kuang")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("kui")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("kun")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("kuo")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("la")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("lai")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lan")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��");


	ChineseLanMap[QStringLiteral("lang")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("lao")] = QStringLiteral("��,��,��,��,��,��,��,��,��, , , , , , ");


	ChineseLanMap[QStringLiteral("le")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lei")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("leng")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("li")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lian")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��, ");


	ChineseLanMap[QStringLiteral("liang")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��, , , ");


	ChineseLanMap[QStringLiteral("liao")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��, , , ");


	ChineseLanMap[QStringLiteral("lie")] = QStringLiteral("��,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lin")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��, , , ");


	ChineseLanMap[QStringLiteral("ling")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��, ");


	ChineseLanMap[QStringLiteral("liu")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("long")] = QStringLiteral("��,��,��,��,¡,��,¤,¢,£, , , , , , ");


	ChineseLanMap[QStringLiteral("lou")] = QStringLiteral("¦,¥,§,¨,ª,©, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lu")] = QStringLiteral("¶,¬,®,«,¯,­,±,²,°,³,½,¼,¸,¹,»,µ,·,¾,º,´, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("luan")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lue")] = QStringLiteral("��,�� , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("lun")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("luo")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��, , , ");


	ChineseLanMap[QStringLiteral("lv")] = QStringLiteral("��,¿,��,��,��,��,��,��,��,��,��,��,��,��, ");


	ChineseLanMap[QStringLiteral("ma")] = QStringLiteral("��,��,��,��,��,��,��,��,��, , , , , , ");


	ChineseLanMap[QStringLiteral("mai")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("man")] = QStringLiteral("��,��,��,��,��,á,��,��,��, , , , , , ");


	ChineseLanMap[QStringLiteral("mang")] = QStringLiteral("æ,â,ä,ã,ç,å, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("mao")] = QStringLiteral("è,ë,ì,é,ê,î,í,ï,ð,ó,ñ,ò, , , ");


	ChineseLanMap[QStringLiteral("me")] = QStringLiteral("ô, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("mei")] = QStringLiteral("û,ö,õ,ü,÷,ý,ú,ø,ù,ÿ,��,þ,��,��,��,��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("men")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("meng")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("mi")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��, ");


	ChineseLanMap[QStringLiteral("mian")] = QStringLiteral("��,��,��,��,��,��,��,��,��, , , , , , ");


	ChineseLanMap[QStringLiteral("miao")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("mie")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("min")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ming")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("miu")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("mo")] = QStringLiteral("��,��,ġ,ģ,Ĥ,Ħ,ĥ,Ģ,ħ,Ĩ,ĩ,ĭ,İ,Ī,į,Į,ī,Ĭ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("mou")] = QStringLiteral("Ĳ,ı,ĳ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("mu")] = QStringLiteral("ĸ,Ķ,ĵ,ķ,Ĵ,ľ,Ŀ,��,ļ,Ĺ,Ļ,��,Ľ,ĺ,��");


	ChineseLanMap[QStringLiteral("na")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("nai")] = QStringLiteral("��,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nan")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nang")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ne")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nao")] = QStringLiteral("��,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nei")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nen")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("neng")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ni")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("nian")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("niang")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("niao")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nie")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("nin")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nuan")] = QStringLiteral("ů, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ning")] = QStringLiteral("��,š,��,��,��,Ţ, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("niu")] = QStringLiteral("ţ,Ť,Ŧ,ť, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nong")] = QStringLiteral("ũ,Ũ,ŧ,Ū, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nu")] = QStringLiteral("ū,Ŭ,ŭ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nue")] = QStringLiteral("ű,Ű, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nuo")] = QStringLiteral("Ų,ŵ,ų,Ŵ, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("nv")] = QStringLiteral("Ů, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("o")] = QStringLiteral("Ŷ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ou")] = QStringLiteral("ŷ,Ź,Ÿ,Ż,ż,ź,Ž, , , , , , , , ");


	ChineseLanMap[QStringLiteral("pa")] = QStringLiteral("ſ,ž,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("pai")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pan")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("pang")] = QStringLiteral("��,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pao")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("pei")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("pen")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("peng")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��, ");


	ChineseLanMap[QStringLiteral("pi")] = QStringLiteral("��,��,��,��,��,��,��,Ƥ,��,ƣ,ơ,��,Ƣ,ƥ,Ʀ,ƨ,Ƨ,Ʃ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pian")] = QStringLiteral("Ƭ,ƫ,ƪ,ƭ, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("piao")] = QStringLiteral("Ư,Ʈ,ư,Ʊ, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pie")] = QStringLiteral("Ʋ,Ƴ, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pin")] = QStringLiteral("ƴ,ƶ,Ƶ,Ʒ,Ƹ, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ping")] = QStringLiteral("ƹ,ƽ,��,ƾ,ƺ,ƻ,��,ƿ,Ƽ, , , , , , ");


	ChineseLanMap[QStringLiteral("po")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("pou")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("pu")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��");


	ChineseLanMap[QStringLiteral("qi")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("qia")] = QStringLiteral("��,ǡ,Ǣ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("qian")] = QStringLiteral("ǧ,Ǫ,Ǥ,Ǩ,ǥ,ǣ,Ǧ,ǫ,ǩ,ǰ,Ǯ,ǯ,Ǭ,Ǳ,ǭ,ǳ,ǲ,Ǵ,Ƿ,ǵ,Ƕ,Ǹ, , , , , , , , ");


	ChineseLanMap[QStringLiteral("qiang")] = QStringLiteral("Ǻ,Ǽ,ǹ,ǻ,ǿ,ǽ,Ǿ,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("qiao")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��");


	ChineseLanMap[QStringLiteral("qie")] = QStringLiteral("��,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("qin")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("qing")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��, , ");


	ChineseLanMap[QStringLiteral("qiong")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("qiu")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("qu")] = QStringLiteral("��,��,��,��,��,��,��,��,ȡ,Ȣ,ȣ,ȥ,Ȥ, , ");


	ChineseLanMap[QStringLiteral("quan")] = QStringLiteral("Ȧ,ȫ,Ȩ,Ȫ,ȭ,Ȭ,ȩ,ȧ,Ȯ,Ȱ,ȯ, , , , ");


	ChineseLanMap[QStringLiteral("que")] = QStringLiteral("Ȳ,ȱ,ȳ,ȴ,ȸ,ȷ,ȵ,ȶ, , , , , , , ");


	ChineseLanMap[QStringLiteral("qun")] = QStringLiteral("ȹ,Ⱥ, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ran")] = QStringLiteral("Ȼ,ȼ,Ƚ,Ⱦ, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("rang")] = QStringLiteral("ȿ,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("rao")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("re")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ren")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��, , , , , ");


	ChineseLanMap[QStringLiteral("reng")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ri")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("rong")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��, , , , , ");


	ChineseLanMap[QStringLiteral("rou")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ru")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��, , , , , ");


	ChineseLanMap[QStringLiteral("ruan")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("rui")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("run")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ruo")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sa")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sai")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("san")] = QStringLiteral("��,��,ɡ,ɢ, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sang")] = QStringLiteral("ɣ,ɤ,ɥ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sao")] = QStringLiteral("ɦ,ɧ,ɨ,ɩ, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("se")] = QStringLiteral("ɫ,ɬ,ɪ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sen")] = QStringLiteral("ɭ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("seng")] = QStringLiteral("ɮ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sha")] = QStringLiteral("ɱ,ɳ,ɴ,ɰ,ɯ,ɵ,ɶ,ɷ,��, , , , , , ");


	ChineseLanMap[QStringLiteral("shai")] = QStringLiteral("ɸ,ɹ, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shan")] = QStringLiteral("ɽ,ɾ,ɼ,��,ɺ,ɿ,��,��,��,ɻ,��,��,��,��,��,��,դ, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shang")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("shao")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("she")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��, , , ");


	ChineseLanMap[QStringLiteral("shen")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,ʲ, , , , , , , , , , , , , ");



	ChineseLanMap[QStringLiteral("sheng")] = QStringLiteral("��,��,��,��,ʤ,��,��,ʡ,ʥ,ʢ,ʣ, , , , ");


	ChineseLanMap[QStringLiteral("shi")] = QStringLiteral("��,ʬ,ʧ,ʦ,ʭ,ʫ,ʩ,ʨ,ʪ,ʮ,ʯ,ʱ,ʶ,ʵ,ʰ,ʴ,ʳ,ʷ,ʸ,ʹ,ʼ,ʻ,ʺ,ʿ,��,��,��,��,ʾ,ʽ,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shou")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��, , , , , ");


	ChineseLanMap[QStringLiteral("shu")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,ˡ,��,��,��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shua")] = QStringLiteral("ˢ,ˣ, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shuai")] = QStringLiteral("˥,ˤ,˦,˧, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shuan")] = QStringLiteral("˩,˨, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shuang")] = QStringLiteral("˫,˪,ˬ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shui")] = QStringLiteral("˭,ˮ,˰,˯, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shun")] = QStringLiteral("˱,˳,˴,˲, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("shuo")] = QStringLiteral("˵,˸,˷,˶, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("si")] = QStringLiteral("˿,˾,˽,˼,˹,˻,˺,��,��,��,��,��,��,��,��");


	ChineseLanMap[QStringLiteral("song")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("sou")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("su")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("suan")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("sui")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("sun")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("suo")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("ta")] = QStringLiteral("��,��,��,��,��,̡,̢,̤,̣, , , , , , ");


	ChineseLanMap[QStringLiteral("tai")] = QStringLiteral("̥,̨,̧,̦,̫,̭,̬,̩,̪, , , , , , ");


	ChineseLanMap[QStringLiteral("tan")] = QStringLiteral("̮,̰,̯,̲,̱,̳,̸,̵,̷,̶,̴,̹,̻,̺,̾,̿,̽,̼, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tang")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��, , ");


	ChineseLanMap[QStringLiteral("tao")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("te")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("teng")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ti")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��");


	ChineseLanMap[QStringLiteral("tian")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("tiao")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tie")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ting")] = QStringLiteral("��,͡,��,��,͢,ͤ,ͥ,ͣ,ͦ,ͧ, , , , , ");


	ChineseLanMap[QStringLiteral("tong")] = QStringLiteral("ͨ,ͬ,ͮ,ͩ,ͭ,ͯ,ͪ,ͫ,ͳ,ͱ,Ͱ,Ͳ,ʹ, , ");


	ChineseLanMap[QStringLiteral("tou")] = QStringLiteral("͵,ͷ,Ͷ,͸, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tu")] = QStringLiteral("͹,ͺ,ͻ,ͼ,ͽ,Ϳ,;,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("tuan")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tui")] = QStringLiteral("��,��,��,��,��,��, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tun")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("tuo")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("wa")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("wai")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("wan")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("wang")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��, , , , , ");


	ChineseLanMap[QStringLiteral("wei")] = QStringLiteral("Σ,��,΢,Ρ,Ϊ,Τ,Χ,Υ,Φ,Ψ,Ω,ά,Ϋ,ΰ,α,β,γ,έ,ί,ή,��,δ,λ,ζ,η,θ,ξ,ν,ι,μ,ε,ο,κ, , , , , , , , , , , , ");



	ChineseLanMap[QStringLiteral("wen")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��, , , , , ");


	ChineseLanMap[QStringLiteral("weng")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("wo")] = QStringLiteral("��,��,��,��,��,��,��,��,��, , , , , , ");


	ChineseLanMap[QStringLiteral("wu")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, ");


	ChineseLanMap[QStringLiteral("xi")] = QStringLiteral("Ϧ,ϫ,��,��,ϣ,��,��,��,Ϣ,��,Ϥ,ϧ,ϩ,��,��,Ϭ,ϡ,Ϫ,��,Ϩ,��,��,ϥ,ϰ,ϯ,Ϯ,ϱ,ϭ,ϴ,ϲ,Ϸ,ϵ,ϸ,϶, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("xia")] = QStringLiteral("Ϻ,Ϲ,ϻ,��,Ͽ,��,Ͼ,Ͻ,ϼ,��,��,��, , , ");


	ChineseLanMap[QStringLiteral("xian")] = QStringLiteral("ϳ,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , ");


	ChineseLanMap[QStringLiteral("xiang")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("xiao")] = QStringLiteral("��,��,��,��,��,��,��,��,С,��,Т,Ф,��,Ч,У,Ц,Х, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("xie")] = QStringLiteral("Щ,Ш,Ъ,Ы,Э,а,в,б,г,Я,Ь,д,й,к,ж,м,е,л,и,з, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("xin")] = QStringLiteral("��,��,о,��,��,п,��,н,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("xing")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��, ");


	ChineseLanMap[QStringLiteral("xiong")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("xiu")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��, , , , , ");


	ChineseLanMap[QStringLiteral("xu")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("xuan")] = QStringLiteral("��,��,��,��,��,��,ѡ,Ѣ,Ѥ,ѣ, , , , , ");


	ChineseLanMap[QStringLiteral("xue")] = QStringLiteral("��,ѥ,Ѧ,Ѩ,ѧ,ѩ,Ѫ, , , , , , , , ");


	ChineseLanMap[QStringLiteral("xun")] = QStringLiteral("ѫ,Ѭ,Ѱ,Ѳ,Ѯ,ѱ,ѯ,ѭ,ѵ,Ѷ,Ѵ,Ѹ,ѷ,ѳ, ");


	ChineseLanMap[QStringLiteral("ya")] = QStringLiteral("Ѿ,ѹ,ѽ,Ѻ,ѻ,Ѽ,��,ѿ,��,��,��,��,��,��,��,��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yan")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yang")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yao")] = QStringLiteral("��,��,��,��,Ң,Ҧ,Ҥ,ҥ,ҡ,ң,��,ҧ,Ҩ,ҩ,Ҫ,ҫ,Կ, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ye")] = QStringLiteral("Ҭ,ҭ,ү,Ү,Ҳ,ұ,Ұ,ҵ,Ҷ,ҷ,ҳ,ҹ,Ҵ,Һ,Ҹ, , , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yin")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,ӡ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("ying")] = QStringLiteral("Ӧ,Ӣ,Ӥ,ӧ,ӣ,ӥ,ӭ,ӯ,ӫ,Ө,ө,Ӫ,Ӭ,Ӯ,ӱ,Ӱ,ӳ,Ӳ, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yo")] = QStringLiteral("Ӵ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yong")] = QStringLiteral("Ӷ,ӵ,Ӹ,ӹ,Ӻ,ӷ,��,ӽ,Ӿ,��,ӿ,��,Ӽ,ӻ,��");


	ChineseLanMap[QStringLiteral("you")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yu")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,Ԧ,��,��,��,��,��,ԡ,Ԥ,��,��,��,Ԣ,��,ԣ,��,��,��,ԥ, ");


	ChineseLanMap[QStringLiteral("yuan")] = QStringLiteral("ԩ,ԧ,Ԩ,Ԫ,Ա,԰,ԫ,ԭ,Բ,Ԭ,Ԯ,Ե,Դ,Գ,ԯ,Զ,Է,Թ,Ժ,Ը, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("yue")] = QStringLiteral("Ի,Լ,��,��,��,��,Ծ,��,Խ, , , , , , ");


	ChineseLanMap[QStringLiteral("yun")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��, , , ");


	ChineseLanMap[QStringLiteral("za")] = QStringLiteral("��,��,��,զ, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zai")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("zan")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zang")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zao")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��, ");


	ChineseLanMap[QStringLiteral("ze")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zei")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zen")] = QStringLiteral("��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zeng")] = QStringLiteral("��,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zha")] = QStringLiteral("��,��,��,��,��,բ,ա,գ,է,թ,ը,ե,��, , ");


	ChineseLanMap[QStringLiteral("zhai")] = QStringLiteral("ի,ժ,լ,��,խ,ծ,կ, , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhan")] = QStringLiteral("մ,ձ,ճ,ղ,հ,ն,չ,յ,ո,շ,ռ,ս,ջ,վ,��,տ,պ, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhang")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhao")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,צ, , , , ");


	ChineseLanMap[QStringLiteral("zhe")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("zhen")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,֡, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zheng")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,֤,֣,��,֢, ");


	ChineseLanMap[QStringLiteral("zhi")] = QStringLiteral("֮,֧,֭,֥,֨,֦,֪,֯,֫,֬,֩,ִ,ֶ,ֱ,ֵ,ְ,ֲ,ֳ,ֹ,ֻ,ּ,ַ,ֽ,ָ,ֺ,��,־,��,��,��,��,��,��,ֿ,��,��,��,��,��,��,��,��,��, , ");


	ChineseLanMap[QStringLiteral("zhong")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("zhou")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��, ");


	ChineseLanMap[QStringLiteral("zhu")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��,��,ס,��,ע,��,פ,��,ף,��,��,��,��, , , , ");


	ChineseLanMap[QStringLiteral("zhua")] = QStringLiteral("ץ, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhuai")] = QStringLiteral("ק, , , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhuan")] = QStringLiteral("ר,ש,ת,׫,׭, , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhuang")] = QStringLiteral("ױ,ׯ,׮,װ,׳,״,��,ײ, , , , , , ,");


	ChineseLanMap[QStringLiteral("zhui")] = QStringLiteral("׷,׵,׶,׹,׺,׸, , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhun")] = QStringLiteral("׻,׼, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zhuo")] = QStringLiteral("׿,׾,׽,��,��,��,��,��,��,��, , , , , ");


	ChineseLanMap[QStringLiteral("zi")] = QStringLiteral("��,��,��,��,��,��,��,��,��,��,��,��,��,��, ");


	ChineseLanMap[QStringLiteral("zong")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");


	ChineseLanMap[QStringLiteral("zou")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zu")] = QStringLiteral("��,��,��,��,��,��,��,��, , , , , , , ");


	ChineseLanMap[QStringLiteral("zuan")] = QStringLiteral("׬,��,��, , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zui")] = QStringLiteral("��,��,��,��, , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zun")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	ChineseLanMap[QStringLiteral("zuo")] = QStringLiteral("��,��,��,��,��,��,��, , , , , , , , ");
}//�����ֿ�

void keyboard::CreateJapaneseMapLan()
{
	JapaneseLanMap[QStringLiteral("a")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ka")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("sa")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ta")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("na")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ha")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ma")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ya")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ra")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("wa")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("n")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("i")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ki")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("shi")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("chi")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ni")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("hi")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("mi")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ri")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("u")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("ku")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("su")] = QStringLiteral("��,��, , , , , , , , , , , , , ");



	JapaneseLanMap[QStringLiteral("tsu")] = QStringLiteral("��,��, , , , , , , , , , , , , ");

	JapaneseLanMap[QStringLiteral("nu")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("fu")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("mu")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("yu")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ru")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("e")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ke")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("se")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("te")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ne")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("he")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("me")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("re")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("o")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ko")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("so")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("to")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("no")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ho")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("mo")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("yo")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ro")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("wo")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ga")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("za")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("da")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ba")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("gi")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ji")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("zi")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("di")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("bi")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("gu")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("zu")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("du")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("bu")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ge")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ze")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("de")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("be")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("go")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("zo")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("do")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("bo")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("pa")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("pi")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("pu")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("pe")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("po")] = QStringLiteral("��,��, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("kya")] = QStringLiteral("����,����, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("gya")] = QStringLiteral("����,����, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("sha")] = QStringLiteral("����,����, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ja")] = QStringLiteral("����,����,�¥�, , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("cha")] = QStringLiteral("����,����, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("nya")] = QStringLiteral("�ˤ�,�˥�, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("dya")] = QStringLiteral("�¤�, , , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("hya")] = QStringLiteral("�Ҥ�,�ҥ�, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("bya")] = QStringLiteral("�Ӥ�,�ӥ�, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("pya")] = QStringLiteral("�Ԥ�,�ԥ�, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("mya")] = QStringLiteral("�ߤ�,�ߥ�, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("rya")] = QStringLiteral("���,���, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("kyu")] = QStringLiteral("����,����, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("gyu")] = QStringLiteral("����,����, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("shu")] = QStringLiteral("����,����, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ju")] = QStringLiteral("����,����,�¥�, , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("chu")] = QStringLiteral("����,����, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("nyu")] = QStringLiteral("�ˤ�,�˥�, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("hyu")] = QStringLiteral("�Ҥ�,�ҥ�, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("byu")] = QStringLiteral("�Ӥ�,�ӥ�, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("pyu")] = QStringLiteral("�Ԥ�,�ԥ�, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("myu")] = QStringLiteral("�ߤ�,�ߥ�, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ryu")] = QStringLiteral("���,���, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("kyo")] = QStringLiteral("����,����, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("gyo")] = QStringLiteral("����,����, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("sho")] = QStringLiteral("����,����, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("jo")] = QStringLiteral("����,����,����, , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("cho")] = QStringLiteral("����,����, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("dyo")] = QStringLiteral("�¤�, , , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("nyo")] = QStringLiteral("�ˤ�,�˥�, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("hyo")] = QStringLiteral("�Ҥ�,�ҥ�, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("byo")] = QStringLiteral("�Ӥ�,�ӥ�, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("pyo")] = QStringLiteral("�Ԥ�,�ԥ�, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("myo")] = QStringLiteral("�ߤ�,�ߥ�, , , , , , , , , , , , , ");


	JapaneseLanMap[QStringLiteral("ryo")] = QStringLiteral("���,���, , , , , , , , , , , , , ");
}

void keyboard::CreateKoreanMapLan()
{
	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("?"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");


	KoreanLanMap[QStringLiteral("??"

		)] = QStringLiteral("?, , , , , , , , , , , , , , ");
}

void keyboard::FontSelect()
{
	ui->fontBox1_KBBut->setText(splitOut[j1]);
	ui->fontBox2_KBBut->setText(splitOut[j1+1]);
	ui->fontBox3_KBBut->setText(splitOut[j1+2]);
	ui->fontBox4_KBBut->setText(splitOut[j1+3]);
	ui->fontBox5_KBBut->setText(splitOut[j1+4]);
	ui->fontBox6_KBBut->setText(splitOut[j1+5]);
	ui->fontBox7_KBBut->setText(splitOut[j1+6]);
	ui->fontBox8_KBBut->setText(splitOut[j1+7]);
	ui->fontBox9_KBBut->setText(splitOut[j1+8]);
	ui->fontBox10_KBBut->setText(splitOut[j1+9]);
}


void keyboard::caps1_kBBut_clicked()
{
	if ( m_Upper == true )//�����ǰΪСд
	{
		switch (m_LanType)
		{

		case 0:  //chinese
			{
				LanChineseSmall();
				btnshow();
				btnArabicARhide();
				break;
			}
		case 1:  //Japanese
			{
				LanJapaneseSmall();
				btnshow();
				btnArabicARhide();
				break;
			}
		case 5:  //Arabic
			{
				LanArabic1();
				btnhide();
				btnArabicARshow();
				break;

			}
		case 3: //Chinese_others
		case 7:  //English
		case 21://Japanese_others
			{
				LanEnglishBig();
				btnArabicARhide();
				btnhide();
				break;
			}
		case 22: //Korean_others
			{
				LanKoreanSmall();
				btnshow();
				btnArabicARhide();
				break;
			}
		case 8:  //Czech
			{
				LanCzechBig();
				btnhide();
				btnArabicARhide();
				break;

			}
		case 9:  //Dutch
			{
				LanDutchBig();
				btnhide();
				btnArabicARhide();
				break;
			}
		case 10:  //German
			{
				LanGermanBig();
				btnArabicARhide();
				btnhide();
				break;
			}
		case 11:  //Finnish
			{
				LanFarsiBig();
				btnArabicARhide();
				btnhide();
				break;
			}
		case 12:  //Hindi
			{
				LanHindiBig();
				btnArabicARhide();
				btnhide();
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
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Y"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("'"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("1"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("��"));
		//		break;
		//	}
		//case 9:  //Dutch
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("="));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("`"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral(">"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("|"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("^"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("~"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("'"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("#"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("��"));
		//		break;
		//	}
		//case 10: //German
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("-"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Y"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("'"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("*"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("+"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("^"));
		//		break;
		//	}
		//case 11:  //Finnish
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("'"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("`"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("#"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));
		//		break;
		//	}
		//case 12:  //Hindi
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("???"));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("???"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("???"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("???"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("??"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("??"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));
		//		break;
		//	}
		//case 13:  //Hungarian
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Y"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("="));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("/"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("+"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("'"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("��"));
		//		break;
		//	}
		//case 14:  //Italian
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("*"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Y"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("^"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("|"));
		//		break;
		//	}
		//case 15:  //Portuguese
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(">"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("<"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("^"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("}"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("{"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("`"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Y"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("+"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("����"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("*"));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("&&"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("^"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("#"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("@"));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("\""));
		//		break;
		//	}
		//case 16:  //Russian
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("."));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("\\"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("+"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("*"));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral(";"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("��"));
		//		break;
		//	}
		//case 17:  //Spanish
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("*"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("^"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Y"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));
		//		break;
		//	}
		//case 18:  //Swedish
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(";"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("*"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("^"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Y"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("`"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("/"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("��"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("#"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));
		//		break;
		//	}
		//case 19:  //Thai
		//	{

		//	}
		//case 20:  //Turkish
		//	{
		//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral(","));
		//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("."));
		//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("B"));
		//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("S"));
		//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("Z"));
		//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("C"));
		//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("V"));
		//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("J"));
		//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("Y"));
		//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
		//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("M"));
		//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("K"));
		//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("T"));
		//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("A"));
		//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("E"));
		//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("U"));
		//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("X"));
		//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("W"));
		//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("Q"));
		//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
		//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("H"));
		//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("N"));
		//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("R"));
		//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("D"));
		//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("O"));
		//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("I"));
		//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("G"));
		//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("F"));
		//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("_"));
		//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
		//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("="));
		//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
		//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
		//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("'"));
		//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&&"));
		//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
		//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("$"));
		//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("^"));
		//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
		//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
//		//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("*"));
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
	else //��ǰΪ��д
	{
		btnLanguageSel(m_LanType);
		m_Upper = true;
		m_symbol = true;
	}

}

void keyboard::symbol_KBBut_clicked()
{
	if ( m_symbol == true )//�����ǰΪ��ĸ
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
				ui->J_KBBut->setText(QStringLiteral("��"));
				ui->K_KBBut->setText(QStringLiteral("��"));
				ui->L_KBBut->setText(QStringLiteral("��"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("��"));
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
				ui->D_KBBut->setText(QStringLiteral("��"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral("��"));
				ui->G_KBBut->setText(QStringLiteral("��"));
				ui->H_KBBut->setText(QStringLiteral("��"));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("��"));
				ui->K_KBBut->setText(QStringLiteral("��"));
				ui->L_KBBut->setText(QStringLiteral("��"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("��"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("��"));
				ui->R_KBBut->setText(QStringLiteral("��"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("��"));
				break;
			}
		case 2://Kore
			{
				ui->A_KBBut->setText(QStringLiteral("("));
				ui->B_KBBut->setText(QStringLiteral("~"));
				ui->C_KBBut->setText(QStringLiteral("\\"));
				ui->D_KBBut->setText(QStringLiteral("��"));
				ui->E_KBBut->setText(QStringLiteral("#"));
				ui->F_KBBut->setText(QStringLiteral("��"));
				ui->G_KBBut->setText(QStringLiteral("��"));
				ui->H_KBBut->setText(QStringLiteral("��"));
				ui->I_KBBut->setText(QStringLiteral("+"));
				ui->J_KBBut->setText(QStringLiteral("��"));
				ui->K_KBBut->setText(QStringLiteral("��"));
				ui->L_KBBut->setText(QStringLiteral("��"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("��"));
				ui->O_KBBut->setText(QStringLiteral("-"));
				ui->P_KBBut->setText(QStringLiteral("="));
				ui->Q_KBBut->setText(QStringLiteral("��"));
				ui->R_KBBut->setText(QStringLiteral("��"));
				ui->S_KBBut->setText(QStringLiteral(")"));
				ui->T_KBBut->setText(QStringLiteral("%"));
				ui->U_KBBut->setText(QStringLiteral("*"));
				ui->V_KBBut->setText(QStringLiteral("|"));
				ui->W_KBBut->setText(QStringLiteral("@"));
				ui->X_KBBut->setText(QStringLiteral("/"));
				ui->Y_KBBut->setText(QStringLiteral("&&"));
				ui->Z_KBBut->setText(QStringLiteral("_"));
				ui->comma_KBBut->setText(QStringLiteral(">"));
				ui->period_KBBut->setText(QStringLiteral("��"));
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
				ui->J_KBBut->setText(QStringLiteral("��"));
				ui->K_KBBut->setText(QStringLiteral("��"));
				ui->L_KBBut->setText(QStringLiteral("��"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("��"));
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
				ui->J_KBBut->setText(QStringLiteral("��"));
				ui->K_KBBut->setText(QStringLiteral("��"));
				ui->L_KBBut->setText(QStringLiteral("��"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("��"));
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
				ui->J_KBBut->setText(QStringLiteral("��"));
				ui->K_KBBut->setText(QStringLiteral("��"));
				ui->L_KBBut->setText(QStringLiteral("��"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("��"));
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
				ui->J_KBBut->setText(QStringLiteral("��"));
				ui->K_KBBut->setText(QStringLiteral("��"));
				ui->L_KBBut->setText(QStringLiteral("��"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("��"));
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
				ui->J_KBBut->setText(QStringLiteral("��"));
				ui->K_KBBut->setText(QStringLiteral("��"));
				ui->L_KBBut->setText(QStringLiteral("��"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("��"));
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
		case 8://Arabic
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
				ui->J_KBBut->setText(QStringLiteral("��"));
				ui->K_KBBut->setText(QStringLiteral("��"));
				ui->L_KBBut->setText(QStringLiteral("��"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("��"));
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
		case 9://Arabic2
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
				ui->J_KBBut->setText(QStringLiteral("��"));
				ui->K_KBBut->setText(QStringLiteral("��"));
				ui->L_KBBut->setText(QStringLiteral("��"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("��"));
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
		case 10://Arabic3
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
				ui->J_KBBut->setText(QStringLiteral("��"));
				ui->K_KBBut->setText(QStringLiteral("��"));
				ui->L_KBBut->setText(QStringLiteral("��"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("��"));
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
		case 11://Arabic4
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
				ui->J_KBBut->setText(QStringLiteral("��"));
				ui->K_KBBut->setText(QStringLiteral("��"));
				ui->L_KBBut->setText(QStringLiteral("��"));
				ui->M_KBBut->setText(QStringLiteral("<"));
				ui->N_KBBut->setText(QStringLiteral("��"));
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
		btnhide();
	}
	else //��ǰΪ����
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

void keyboard::fontBox1_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox1_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox2_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox2_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox3_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox3_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox4_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox4_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox5_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox5_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox6_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox6_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox7_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox7_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox8_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox8_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox9_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox9_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBox10_KBBut_clicked()
{
	changeCurrentlineedit();
	m_pInputEdit->cursorPosition();
	m_pInputEdit->insert(ui->fontBox10_KBBut->text());
	setText2KBLineedit();
	m_pInputEdit->setText("");
}

void keyboard::fontBoxRedu_KBBut_clicked()
{
	if(i1 != 0)
	{
		j1 = j1 - 10;
		if ( j1 >= 0 )
		{
			FontSelect();
		} 
		else if( j1 < 1 )
		{
			j1 = 0;
	    }
	}
}

void keyboard::fontBoxAdd_KBBut_clicked()
{
	if(i1 != 0)
	{
		j1 = j1 + 10;
		if ( j1 < i1  )
		{
			FontSelect();
		} 
		else if( j1 > i1 )
		{
			j1 = i1 - 1;
			j1 = j1 - 10;
		}
	}
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

void keyboard::lanArabicAdd_KBBut_clicked()
{
	if (m_LanType == 5)
	{
		m_LanType = 23;
		m_LantypeReverse = 9;
		LanArabic2();
	}
	else if (m_LanType == 23)
	{
		m_LanType = 24;
		m_LantypeReverse = 10;
		LanArabic3();
	} 
	else if (m_LanType == 24)
	{
		m_LanType = 25;
		m_LantypeReverse= 11;
		LanArabic4();
	} 
	else if (m_LanType  == 25)
	{
		m_LanType =5;
		m_LantypeReverse = 8;
		LanArabic1();
	} 
}

void keyboard::lanArabicRedu_KBBut_clicked()
{

	if (m_LanType == 5)
	{
		m_LanType = 25;
		LanArabic4();
	}
	else if (m_LanType == 25)
	{
		m_LanType = 24;
		LanArabic3();
	} 
	else if (m_LanType == 24)
	{
		m_LanType = 23;
		LanArabic2();
	} 
	else if (m_LanType  == 23)
	{
		m_LanType =5;
		LanArabic1();
	} 
}

void keyboard::btnshow()
{
	//QWidget *qw=new QWidget(this);
	//qw->setGeometry(20,10,750,30);
	//QHBoxLayout *qb=new QHBoxLayout(qw);
	//QPushButton *pb2=new QPushButton("first");
	//qb->addWidget(pb2);
	ui->fontBox1_KBBut->show();
	ui->fontBox2_KBBut->show();
	ui->fontBox3_KBBut->show();
	ui->fontBox4_KBBut->show();
	ui->fontBox5_KBBut->show();
	ui->fontBox6_KBBut->show();
	ui->fontBox7_KBBut->show();
	ui->fontBox8_KBBut->show();
	ui->fontBox9_KBBut->show();
	ui->fontBox10_KBBut->show();
	ui->fontBoxRedu_KBBut->show();
	ui->fontBoxAdd_KBBut->show();
	ui->wordCombLineEdit->show();

}

void keyboard::btnArabicARshow()
{
	ui->languageAdd_KBBut->show();
	ui->languageRedu_KBBut->show();
}

void keyboard::btnLanguageSel(int m_LanType)
{
	switch (m_LanType)
	{

	case 0:  //chinese
	case 1:  //Japanese
		{
			LanJapaneseBig();
			btnhide();
			break;
		}
	case 3:  //Chinese_others
	case 21: //Japanese_others
		{
			LanChineseBig();
			btnhide();
		//	pWnd->btnShow();
		//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
	case 2:  //Korean
	case 22: //Korean_others
		{
			LanKoreanBig();
			btnhide();
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
			btnhide();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 8:  //Czech
		{
			LanCzechSmall();
			btnhide();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 9:  //Dutch
		{
		    LanDutchSmall();
			btnhide();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 10: //German
		{
			LanGermanSmall();
			btnhide();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 11:  //FarsiSmall
		{
		    LanFarsiSmall();
			btnhide();
		//	pWnd->btnHide();
		//	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 12:  //Hindi
		{
		    LanHindiSmall();
			btnhide();
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
		case 0: //��ǰΪEnglishSymbol
		{
			SymbolToEnglish();
			btnhide();

			//	pWnd->btnShow();
			//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 1: //��ǰΪChineseSymbol
		{
			SymbolToChinese();
			//	pWnd->btnShow();
			//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 2: //��ǰΪKoreSymbol
		{
			SymbolToKore();
				//	pWnd->btnShow();
				//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 3: //��ǰΪKoreSymbol
		{
			SymbolToCzech();
			btnhide();
				//	pWnd->btnShow();
				//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 4: //��ǰΪKoreSymbol
		{
			SymbolToJapanese();
				//	pWnd->btnShow();
				//	pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
		case 5:
		{
			SymbolToDutch();
			btnhide();
			break;
		}
		case 6:
		{
			SymbolToGerman();
			btnhide();
			break;
		}
		case 7:
		{
			SymbolToFarsi();
			btnhide();
			break;
		}
		case 8://��ǰΪArabicSymbol
		{
			SymbolToArabic();
			btnhide();
			break;
		}
		case 9://��ǰΪArabic2Symbol
			{
				SymbolToArabic2();
				btnhide();
				break;
			}
		case 10://��ǰΪArabic3Symbol
			{
				SymbolToArabic3();
				btnhide();
				break;
			}
		case 11://��ǰΪArabic4Symbol
			{
				SymbolToArabic4();
				btnhide();
				break;
			}
	}

}

void keyboard::LanArabic1()
{
	ui->A_KBBut->setText(QStringLiteral("?"));
	ui->B_KBBut->setText(QStringLiteral("?"));
	ui->C_KBBut->setText(QStringLiteral("?"));
	ui->D_KBBut->setText(QStringLiteral("?"));
	ui->E_KBBut->setText(QStringLiteral("?"));
	ui->F_KBBut->setText(QStringLiteral("?"));
	ui->G_KBBut->setText(QStringLiteral("?"));
	ui->H_KBBut->setText(QStringLiteral("?"));
	ui->I_KBBut->setText(QStringLiteral("?"));
	ui->J_KBBut->setText(QStringLiteral("?"));
	ui->K_KBBut->setText(QStringLiteral("?"));
	ui->L_KBBut->setText(QStringLiteral("?"));
	ui->M_KBBut->setText(QStringLiteral("?"));
	ui->N_KBBut->setText(QStringLiteral("?"));
	ui->O_KBBut->setText(QStringLiteral("?"));
	ui->P_KBBut->setText(QStringLiteral("?"));
	ui->Q_KBBut->setText(QStringLiteral("?"));
	ui->R_KBBut->setText(QStringLiteral("?"));
	ui->S_KBBut->setText(QStringLiteral("?"));
	ui->T_KBBut->setText(QStringLiteral("?"));
	ui->U_KBBut->setText(QStringLiteral("?"));
	ui->V_KBBut->setText(QStringLiteral("?"));
	ui->W_KBBut->setText(QStringLiteral("?"));
	ui->X_KBBut->setText(QStringLiteral("?"));
	ui->Y_KBBut->setText(QStringLiteral("?"));
	ui->Z_KBBut->setText(QStringLiteral("?"));
	ui->comma_KBBut->setText(QStringLiteral("?"));
	ui->period_KBBut->setText(QStringLiteral("?"));
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("?"));
	ui->three_KBBut->setText(QStringLiteral("?"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("?"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("?"));
	ui->nine_KBBut->setText(QStringLiteral("?"));
	ui->zero_KBBut->setText(QStringLiteral("?"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("?"));//����
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("?"));//����
	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));*/
}

void keyboard::LanArabic2()
{
	ui->A_KBBut->setText(QStringLiteral("?"));
	ui->B_KBBut->setText(QStringLiteral("?"));
	ui->C_KBBut->setText(QStringLiteral("?"));
	ui->D_KBBut->setText(QStringLiteral("?"));
	ui->E_KBBut->setText(QStringLiteral("?"));
	ui->F_KBBut->setText(QStringLiteral("?"));
	ui->G_KBBut->setText(QStringLiteral("?"));
	ui->H_KBBut->setText(QStringLiteral("?"));
	ui->I_KBBut->setText(QStringLiteral("?"));
	ui->J_KBBut->setText(QStringLiteral("?"));
	ui->K_KBBut->setText(QStringLiteral("?"));
	ui->L_KBBut->setText(QStringLiteral("?"));
	ui->M_KBBut->setText(QStringLiteral("?"));
	ui->N_KBBut->setText(QStringLiteral("?"));
	ui->O_KBBut->setText(QStringLiteral("?"));
	ui->P_KBBut->setText(QStringLiteral("?"));
	ui->Q_KBBut->setText(QStringLiteral("?"));
	ui->R_KBBut->setText(QStringLiteral("?"));
	ui->S_KBBut->setText(QStringLiteral("?"));
	ui->T_KBBut->setText(QStringLiteral("?"));
	ui->U_KBBut->setText(QStringLiteral("?"));
	ui->V_KBBut->setText(QStringLiteral("?"));
	ui->W_KBBut->setText(QStringLiteral("?"));
	ui->X_KBBut->setText(QStringLiteral("?"));
	ui->Y_KBBut->setText(QStringLiteral("?"));
	ui->Z_KBBut->setText(QStringLiteral("?"));
	ui->comma_KBBut->setText(QStringLiteral("?"));
	ui->period_KBBut->setText(QStringLiteral("?"));
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("?"));
	ui->three_KBBut->setText(QStringLiteral("?"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("?"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("?"));
	ui->nine_KBBut->setText(QStringLiteral("?"));
	ui->zero_KBBut->setText(QStringLiteral("?"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("?"));//����
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("?"));//����
	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));*/
}

void keyboard::LanArabic3()
{
	ui->A_KBBut->setText(QStringLiteral("?"));
	ui->B_KBBut->setText(QStringLiteral("?"));
	ui->C_KBBut->setText(QStringLiteral("?"));
	ui->D_KBBut->setText(QStringLiteral("?"));
	ui->E_KBBut->setText(QStringLiteral("?"));
	ui->F_KBBut->setText(QStringLiteral("?"));
	ui->G_KBBut->setText(QStringLiteral("?"));
	ui->H_KBBut->setText(QStringLiteral("?"));
	ui->I_KBBut->setText(QStringLiteral("?"));
	ui->J_KBBut->setText(QStringLiteral("?"));
	ui->K_KBBut->setText(QStringLiteral("?"));
	ui->L_KBBut->setText(QStringLiteral("?"));
	ui->M_KBBut->setText(QStringLiteral("?"));
	ui->N_KBBut->setText(QStringLiteral("?"));
	ui->O_KBBut->setText(QStringLiteral("?"));
	ui->P_KBBut->setText(QStringLiteral("?"));
	ui->Q_KBBut->setText(QStringLiteral("?"));
	ui->R_KBBut->setText(QStringLiteral("?"));
	ui->S_KBBut->setText(QStringLiteral("?"));
	ui->T_KBBut->setText(QStringLiteral("?"));
	ui->U_KBBut->setText(QStringLiteral("?"));
	ui->V_KBBut->setText(QStringLiteral("?"));
	ui->W_KBBut->setText(QStringLiteral("?"));
	ui->X_KBBut->setText(QStringLiteral("?"));
	ui->Y_KBBut->setText(QStringLiteral("?"));
	ui->Z_KBBut->setText(QStringLiteral("?"));
	ui->comma_KBBut->setText(QStringLiteral("?"));
	ui->period_KBBut->setText(QStringLiteral("?"));
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("?"));
	ui->three_KBBut->setText(QStringLiteral("?"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("?"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("?"));
	ui->nine_KBBut->setText(QStringLiteral("?"));
	ui->zero_KBBut->setText(QStringLiteral("?"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("?"));//����
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("?"));//����
	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));*/
}

void keyboard::LanArabic4()
{
	ui->A_KBBut->setText(QStringLiteral("?"));
	ui->B_KBBut->setText(QStringLiteral(""));
	ui->C_KBBut->setText(QStringLiteral(""));
	ui->D_KBBut->setText(QStringLiteral(""));
	ui->E_KBBut->setText(QStringLiteral("?"));
	ui->F_KBBut->setText(QStringLiteral(""));
	ui->G_KBBut->setText(QStringLiteral(""));
	ui->H_KBBut->setText(QStringLiteral(""));
	ui->I_KBBut->setText(QStringLiteral("?"));
	ui->J_KBBut->setText(QStringLiteral(""));
	ui->K_KBBut->setText(QStringLiteral(""));
	ui->L_KBBut->setText(QStringLiteral(""));
	ui->M_KBBut->setText(QStringLiteral(""));
	ui->N_KBBut->setText(QStringLiteral(""));
	ui->O_KBBut->setText(QStringLiteral("?"));
	ui->P_KBBut->setText(QStringLiteral("?"));
	ui->Q_KBBut->setText(QStringLiteral("?"));
	ui->R_KBBut->setText(QStringLiteral("?"));
	ui->S_KBBut->setText(QStringLiteral(""));
	ui->T_KBBut->setText(QStringLiteral("?"));
	ui->U_KBBut->setText(QStringLiteral("?"));
	ui->V_KBBut->setText(QStringLiteral(""));
	ui->W_KBBut->setText(QStringLiteral("?"));
	ui->X_KBBut->setText(QStringLiteral(""));
	ui->Y_KBBut->setText(QStringLiteral("?"));
	ui->Z_KBBut->setText(QStringLiteral(""));
	ui->comma_KBBut->setText(QStringLiteral(""));
	ui->period_KBBut->setText(QStringLiteral(""));
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("?"));
	ui->three_KBBut->setText(QStringLiteral("?"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("?"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("?"));
	ui->nine_KBBut->setText(QStringLiteral("?"));
	ui->zero_KBBut->setText(QStringLiteral("?"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral(""));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral(""));

	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));*/
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
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("/"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("z"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("'"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral(";"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("\\"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("]"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("["));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("y"));
	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("="));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("-"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("`"));
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
	btnshow();
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

void keyboard::LanKoreanSmall()//����Сд
{
	ui->A_KBBut->setText(QStringLiteral("?"));
	ui->B_KBBut->setText(QStringLiteral("?"));
	ui->C_KBBut->setText(QStringLiteral("?"));
	ui->D_KBBut->setText(QStringLiteral("?"));
	ui->E_KBBut->setText(QStringLiteral("?"));
	ui->F_KBBut->setText(QStringLiteral("?"));
	ui->G_KBBut->setText(QStringLiteral("?"));
	ui->H_KBBut->setText(QStringLiteral("?"));
	ui->I_KBBut->setText(QStringLiteral("?"));
	ui->J_KBBut->setText(QStringLiteral("?"));
	ui->K_KBBut->setText(QStringLiteral("?"));
	ui->L_KBBut->setText(QStringLiteral("?"));
	ui->M_KBBut->setText(QStringLiteral("?"));
	ui->N_KBBut->setText(QStringLiteral("?"));
	ui->O_KBBut->setText(QStringLiteral("?"));
	ui->P_KBBut->setText(QStringLiteral("?"));
	ui->Q_KBBut->setText(QStringLiteral("?"));
	ui->R_KBBut->setText(QStringLiteral("?"));
	ui->S_KBBut->setText(QStringLiteral("?"));
	ui->T_KBBut->setText(QStringLiteral("?"));
	ui->U_KBBut->setText(QStringLiteral("?"));
	ui->V_KBBut->setText(QStringLiteral("?"));
	ui->W_KBBut->setText(QStringLiteral("?"));
	ui->X_KBBut->setText(QStringLiteral("?"));
	ui->Y_KBBut->setText(QStringLiteral("?"));
	ui->Z_KBBut->setText(QStringLiteral("?"));
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
	btnshow();

//
//
//
//	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("/"));
//	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("."));
//	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(","));
//	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("'"));
//	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral(";"));
//	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("\\"));
//	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("]"));
//	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("["));
//	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("?"));
//	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("="));
//	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("-"));
//	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("0"));
//	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("9"));
//	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("8"));
//	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("7"));
//	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("6"));
//	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("5"));
//	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("4"));
//	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("3"));
//	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("2"));
//	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("1"));
//	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("`"));*/
//}
}

void keyboard::LanKoreanBig()
{
	ui->A_KBBut->setText(QStringLiteral("?"));
	ui->B_KBBut->setText(QStringLiteral("?"));
	ui->C_KBBut->setText(QStringLiteral("?"));
	ui->D_KBBut->setText(QStringLiteral("?"));
	ui->E_KBBut->setText(QStringLiteral("?"));
	ui->F_KBBut->setText(QStringLiteral("?"));
	ui->G_KBBut->setText(QStringLiteral("?"));
	ui->H_KBBut->setText(QStringLiteral("?"));
	ui->I_KBBut->setText(QStringLiteral(""));
	ui->J_KBBut->setText(QStringLiteral("?"));
	ui->K_KBBut->setText(QStringLiteral("?"));
	ui->L_KBBut->setText(QStringLiteral("?"));
	ui->M_KBBut->setText(QStringLiteral(""));
	ui->N_KBBut->setText(QStringLiteral("?"));
	ui->O_KBBut->setText(QStringLiteral("?"));
	ui->P_KBBut->setText(QStringLiteral("?"));
	ui->Q_KBBut->setText(QStringLiteral("?"));
	ui->R_KBBut->setText(QStringLiteral("?"));
	ui->S_KBBut->setText(QStringLiteral("?"));
	ui->T_KBBut->setText(QStringLiteral("?"));
	ui->U_KBBut->setText(QStringLiteral(""));
	ui->V_KBBut->setText(QStringLiteral("?"));
	ui->W_KBBut->setText(QStringLiteral("?"));
	ui->X_KBBut->setText(QStringLiteral("?"));
	ui->Y_KBBut->setText(QStringLiteral(""));
	ui->Z_KBBut->setText(QStringLiteral("?"));
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
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("��"));
	ui->three_KBBut->setText(QStringLiteral("?"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("?"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("��"));
	ui->nine_KBBut->setText(QStringLiteral("��"));
	ui->zero_KBBut->setText(QStringLiteral("��"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("/"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("y"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("��"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("��"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral(")"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("��"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("z"));
	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("="));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("��"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("��"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("��"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("��"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("+"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral(";"));*/
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
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("?"));
	ui->three_KBBut->setText(QStringLiteral("?"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("?"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("?"));
	ui->nine_KBBut->setText(QStringLiteral("?"));
	ui->zero_KBBut->setText(QStringLiteral("?"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("_"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Y"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("!"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("'"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("("));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Z"));
	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("��"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("%"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("��"));*/
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
	btnshow();
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
	//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("="));
	//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
	//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(";"));
	//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
	//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
	//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
	//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
	//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
	//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
	//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Z"));
	//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("`"));
	//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("��"));
	//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
	//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
	//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
	//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
	//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
	//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
	//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
	//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
	//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
	//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral(">"));
	//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("|"));
	//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("^"));
	//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
	//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
	//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
	//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
	//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Z"));
	//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
	//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
	//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
	//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
	//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
	//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("~"));
	//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("'"));
	//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
	//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
	//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("_"));
	//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&"));
	//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
	//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("$"));
	//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("#"));
	//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
	//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
	//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("��"));
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
	ui->comma_KBBut->setText(QStringLiteral("?"));
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
	ui->comma_KBBut->setText(QStringLiteral("?"));//��������û�ж���
	ui->period_KBBut->setText(QStringLiteral("?"));//�����ר������
	ui->one_KBBut->setText(QStringLiteral("!"));
	ui->two_KBBut->setText(QStringLiteral("\\"));
	ui->three_KBBut->setText(QStringLiteral("��"));
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
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("��"));
	ui->three_KBBut->setText(QStringLiteral("`"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("'"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("?"));
	ui->nine_KBBut->setText(QStringLiteral("��"));
	ui->zero_KBBut->setText(QStringLiteral("��"));
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
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("��"));
	ui->three_KBBut->setText(QStringLiteral("`"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("'"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("?"));
	ui->nine_KBBut->setText(QStringLiteral("��"));
	ui->zero_KBBut->setText(QStringLiteral("��"));
	//		GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("_"));
	//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral(":"));
	//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(";"));
	//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("M"));
	//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("N"));
	//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("B"));
	//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("V"));
	//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("C"));
	//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("X"));
	//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("Z"));
	//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("L"));
	//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("K"));
	//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("J"));
	//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("H"));
	//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("G"));
	//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("F"));
	//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("D"));
	//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("S"));
	//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("A"));
	//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("'"));
	//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("P"));
	//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("O"));
	//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("I"));
	//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("U"));
	//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("Z"));
	//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("T"));
	//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("R"));
	//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("E"));
	//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("W"));
	//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("Q"));
	//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("`"));
	//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("="));
	//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral(")"));
	//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("("));
	//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("/"));
	//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("&"));
	//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("%"));
	//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("��"));
	//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("#"));
	//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("\""));
	//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("!"));
	//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));
	//		break;
	//	}
}

void keyboard::LanHindiSmall()
{
	ui->A_KBBut->setText(QStringLiteral("?"));
	ui->B_KBBut->setText(QStringLiteral("?"));
	ui->C_KBBut->setText(QStringLiteral("?"));
	ui->D_KBBut->setText(QStringLiteral("?"));
	ui->E_KBBut->setText(QStringLiteral("?"));
	ui->F_KBBut->setText(QStringLiteral("?"));
	ui->G_KBBut->setText(QStringLiteral("?"));
	ui->H_KBBut->setText(QStringLiteral("?"));
	ui->I_KBBut->setText(QStringLiteral("?"));
	ui->J_KBBut->setText(QStringLiteral("?"));
	ui->K_KBBut->setText(QStringLiteral("?"));
	ui->L_KBBut->setText(QStringLiteral("?"));
	ui->M_KBBut->setText(QStringLiteral("?"));
	ui->N_KBBut->setText(QStringLiteral("?"));
	ui->O_KBBut->setText(QStringLiteral("?"));
	ui->P_KBBut->setText(QStringLiteral("?"));
	ui->Q_KBBut->setText(QStringLiteral("?"));
	ui->R_KBBut->setText(QStringLiteral("?"));
	ui->S_KBBut->setText(QStringLiteral("?"));
	ui->T_KBBut->setText(QStringLiteral("?"));
	ui->U_KBBut->setText(QStringLiteral("?"));
	ui->V_KBBut->setText(QStringLiteral("?"));
	ui->W_KBBut->setText(QStringLiteral("?"));
	ui->X_KBBut->setText(QStringLiteral("?"));
	ui->Y_KBBut->setText(QStringLiteral("?"));
	ui->Z_KBBut->setText(QStringLiteral("?"));
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("?"));
	ui->three_KBBut->setText(QStringLiteral("??"));
	ui->four_KBBut->setText(QStringLiteral("?"));
	ui->five_KBBut->setText(QStringLiteral("?"));
	ui->six_KBBut->setText(QStringLiteral("?"));
	ui->seven_KBBut->setText(QStringLiteral("?"));
	ui->eight_KBBut->setText(QStringLiteral("?"));
	ui->nine_KBBut->setText(QStringLiteral("?"));
	ui->zero_KBBut->setText(QStringLiteral("?"));
	/*GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("-"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));*/
}

void keyboard::LanHindiBig()
{                                                //�ܶ����û�з���
	ui->A_KBBut->setText(QStringLiteral("?"));
	ui->B_KBBut->setText(QStringLiteral("?"));
	ui->C_KBBut->setText(QStringLiteral("?"));
	ui->D_KBBut->setText(QStringLiteral("?"));
	ui->E_KBBut->setText(QStringLiteral("?"));
	ui->F_KBBut->setText(QStringLiteral("?"));
	ui->G_KBBut->setText(QStringLiteral("?"));
	ui->H_KBBut->setText(QStringLiteral("?"));
	ui->I_KBBut->setText(QStringLiteral("?"));
	ui->J_KBBut->setText(QStringLiteral("?"));
	ui->K_KBBut->setText(QStringLiteral("?"));
	ui->L_KBBut->setText(QStringLiteral("?"));
	ui->M_KBBut->setText(QStringLiteral("?"));
	ui->N_KBBut->setText(QStringLiteral("?"));
	ui->O_KBBut->setText(QStringLiteral("?"));
	ui->P_KBBut->setText(QStringLiteral("?"));
	ui->Q_KBBut->setText(QStringLiteral("?"));
	ui->R_KBBut->setText(QStringLiteral("?"));
	ui->S_KBBut->setText(QStringLiteral("?"));
	ui->T_KBBut->setText(QStringLiteral("?"));
	ui->U_KBBut->setText(QStringLiteral("?"));
	ui->V_KBBut->setText(QStringLiteral("?"));
	ui->W_KBBut->setText(QStringLiteral("?"));
	ui->X_KBBut->setText(QStringLiteral("?"));
	ui->Y_KBBut->setText(QStringLiteral("?"));
	ui->Z_KBBut->setText(QStringLiteral("?"));
	ui->comma_KBBut->setText(",");
	ui->period_KBBut->setText(".");
	ui->one_KBBut->setText(QStringLiteral("?"));
	ui->two_KBBut->setText(QStringLiteral("?"));
	ui->three_KBBut->setText(QStringLiteral("??"));
	ui->four_KBBut->setText(QStringLiteral("??"));
	ui->five_KBBut->setText(QStringLiteral("???"));
	ui->six_KBBut->setText(QStringLiteral("???"));
	ui->seven_KBBut->setText(QStringLiteral("???"));
	ui->eight_KBBut->setText(QStringLiteral("???"));
	ui->nine_KBBut->setText(QStringLiteral("("));
	ui->zero_KBBut->setText(QStringLiteral(")"));
	//      GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(QStringLiteral("?"));  û����
	//		GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(QStringLiteral("?"));   û����
	//		GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(QStringLiteral("?"));   û����
	//		GetDlgItem(IDC_MIAN_M)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_N)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_B)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_V)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_C)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_X)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_Z)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(QStringLiteral("?"));   û����
	//		GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(QStringLiteral("?"));    û����
	//		GetDlgItem(IDC_MIAN_L)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_K)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_J)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_H)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_G)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_F)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_D)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_S)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_A)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(QStringLiteral("?"));   û����
	//		GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(QStringLiteral("?"));    û����
	//		GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(QStringLiteral("?"));     û����
	//		GetDlgItem(IDC_MIAN_P)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_O)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_I)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_U)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_Y)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIANQStringLiteral)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_R)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_E)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_W)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_Q)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(QStringLiteral("?"));    û����
	//		GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_0)->SetWindowText(QStringLiteral(")"));
	//		GetDlgItem(IDC_MIAN_9)->SetWindowText(QStringLiteral("("));
	//		GetDlgItem(IDC_MIAN_8)->SetWindowText(QStringLiteral("???"));
	//		GetDlgItem(IDC_MIAN_7)->SetWindowText(QStringLiteral("???"));
	//		GetDlgItem(IDC_MIAN_6)->SetWindowText(QStringLiteral("???"));
	//		GetDlgItem(IDC_MIAN_5)->SetWindowText(QStringLiteral("???"));
	//		GetDlgItem(IDC_MIAN_4)->SetWindowText(QStringLiteral("??"));
	//		GetDlgItem(IDC_MIAN_3)->SetWindowText(QStringLiteral("??"));
	//		GetDlgItem(IDC_MIAN_2)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_1)->SetWindowText(QStringLiteral("?"));
	//		GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(QStringLiteral("?"));
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

void keyboard::SymbolToArabic()
{
	LanArabic1();
	m_Upper = false;
}

void keyboard::SymbolToArabic2()
{
	LanArabic2();
	m_Upper = false;
}

void keyboard::SymbolToArabic3()
{
	LanArabic3();
	m_Upper = false;
}

void keyboard::SymbolToArabic4()
{
	LanArabic4();
	m_Upper = false;
}
