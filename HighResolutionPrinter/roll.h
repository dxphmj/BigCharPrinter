#ifndef ROLL_H
#define ROLL_H

#include <QLabel>
#include <QString>

class roll : public QLabel
{
	Q_OBJECT

public:
	roll(QWidget *parent);
	~roll();

	QTimer* timer;

protected:
	void paintEvent(QPaintEvent *);
	void updateIndex();
	void chooseLan();
	
public:
	int m_charWidth; //�ַ������
	int m_curIndex;
    QString m_showText; //��Ҫ��ʾ���ַ���
	int curlanguage;

public:
QString getText()
{
	return  m_showText;
}
	
};

#endif // ROLL_H
