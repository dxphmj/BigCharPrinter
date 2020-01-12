#include "roll.h"
#include <QPainter>
#include <QTimer>
//#include <QTextCodec>

roll::roll(QWidget *parent)
	: QLabel(parent)
{
	m_curIndex = 0;//��ǰ����
	m_showText = QStringLiteral("��ܰ��ʾ���벻Ҫ�ڴ�ӡ�����аε�ī�У���ֹ���������");//��ʾ������
	m_charWidth = fontMetrics().width("a");//ÿ���ַ��Ŀ��

	QTimer *timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &roll::updateIndex);
	//connect(timer, SIGNAL(timeout()), this, SLOT(updateIndex()));
	timer->start(100);
}

roll::~roll()
{

}

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
}
