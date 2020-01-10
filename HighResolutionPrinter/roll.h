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

protected:
	void paintEvent(QPaintEvent *);
	void updateIndex();

private:
	int m_charWidth; //�ַ������
	int m_curIndex;
    QString m_showText; //��Ҫ��ʾ���ַ���

public:
QString getText()
{
	return  m_showText;
}
	
};

#endif // ROLL_H
