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
	//bool eventFilter(QObject *watched, QEvent *event);
	void LanguageChanged(int languageType);

protected:
	void paintEvent(QPaintEvent *);
	void updateIndex();
	
public:
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
