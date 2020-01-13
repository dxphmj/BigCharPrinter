#ifndef LINEEDIT_CLICK_H
#define LINEEDIT_CLICK_H

#include <QLineEdit>
#include <QMouseEvent>


class lineedit_click : public QLineEdit
{
	Q_OBJECT

public:
	lineedit_click(QWidget *parent);
	~lineedit_click();

protected:
	//��дmousePressEvent�¼�
	virtual void mousePressEvent(QMouseEvent *event);

signals:
	//�Զ���clicked()�ź�,��mousePressEvent�¼�����ʱ����
	void clicked();

public slots:

private:
	
};

#endif // LINEEDIT_CLICK_H
