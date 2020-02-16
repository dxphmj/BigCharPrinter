#include "roll.h"
#include <QPainter>
#include <QTimer>
#include <QEvent>
#include "mainwindow.h"
#include "paramsettingform.h"
#include "syssetting.h"

//#include <QTextCodec>

roll::roll(QWidget *parent)
	: QLabel(parent)
{
	//this->installEventFilter(this);
	
	m_curIndex = 0;//��ǰ����
	m_charWidth = fontMetrics().width("a");//ÿ���ַ��Ŀ��
	m_showText = QStringLiteral("��ܰ��ʾ���벻Ҫ�ڴ�ӡ�����аε�ī�У���ֹ���������");//��ʾ������
	QTimer *timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &roll::updateIndex);
	//connect(timer, SIGNAL(timeout()), this, SLOT(updateIndex()));
	timer->start(100);
	
}

roll::~roll()
{

}

//bool roll::eventFilter(QObject *watched, QEvent *event)
//{
//	if (watched == this && event->type() == QEvent::Paint)
//	{
//		QPainter painter(this);
//		painter.drawText(0, 47, m_showText.mid(m_curIndex));
//		painter.drawText(width() - m_charWidth*m_curIndex, 47, m_showText.left(m_curIndex));
//	}
//	return QLabel::eventFilter(watched, event);
//}

void roll::paintEvent(QPaintEvent *event)
{
	__super::paintEvent(event);
	QPainter painter(this);
	painter.drawText(0, 47, m_showText.mid(m_curIndex));
	painter.drawText(width() - m_charWidth*m_curIndex, 47, m_showText.left(m_curIndex));
}

void roll::updateIndex()
{
	update();
	m_curIndex++;
	if (m_curIndex*m_charWidth > width())
		m_curIndex = 0;
	//LanguageChanged();
}

void roll::LanguageChanged(int languageType)
{
	/*switch(languageType)
	{
	case 1:
	m_showText = QStringLiteral("��ܰ��ʾ���벻Ҫ�ڴ�ӡ�����аε�ī�У���ֹ���������");
	case 5:
	m_showText = QStringLiteral("balabalabalabala");
	}*/
}