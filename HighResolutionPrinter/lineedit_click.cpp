#include "lineedit_click.h"

lineedit_click::lineedit_click(QWidget *parent)
	: QLineEdit(parent)
{

}

lineedit_click::~lineedit_click()
{

}

//��дmousePressEvent�¼�,����¼������ǲ��ǵ����������
void lineedit_click::mousePressEvent(QMouseEvent *event) {
	//��������˾ʹ���clicked�ź�
	if (event->button() == Qt::LeftButton) {
		//����clicked�ź�
		emit clicked();
	}
	//�����¼��������ദ��
	QLineEdit::mousePressEvent(event);
}
