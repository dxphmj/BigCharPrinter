#include "BarcodeOBJ.h"
#include "QFileInfo"
#include "backend\zint.h"

CBarcodeOBJ::CBarcodeOBJ(void)
{
}

CBarcodeOBJ::~CBarcodeOBJ(void)
{
}

void CBarcodeOBJ::Create2Dcode()
{
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	int batch_mode;
	int mirror_mode;
	char filetype[4];
	int i;
	int longth;
	int derta;
	derta=1;
	longth=0;
	error_number = 0;
	rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = UNICODE_MODE;
	my_symbol->symbology = intBarcodeType;
	int heightvalue1 = intLineSize;
	if (heightvalue1<28)
	{	
		my_symbol->height =5;	 
	} 
	else
	{
		my_symbol->height=heightvalue1-23;
	}
	/*QString zoomvalue=ui->zoomShowBarCodeLab->text();
	float zoomvalue1=zoomvalue.toFloat();*/
	my_symbol->scale =1;
	batch_mode = 0;
	mirror_mode = 0;
	
	my_symbol->whitespace_width = 9;//�ı����������߿հ�������,�հ������Ȼ�Ӱ��������Ŀ�ȣ�ֻ������������������Ŀհ�
	//if (ui->typerimComBox->currentIndex()==0)
	//{
	//	my_symbol->output_options= 1;
	//} 
	//else if(ui->typerimComBox->currentIndex()==1)
	//{
	//	my_symbol->output_options=2;
	//}
	//else
	//{
	//	my_symbol->output_options=4;
	//}
	//���ޱ߿�֮��Ŀ���;1:�ޱ߿�2�����������߽��ߣ�4�������߿�
	//QString rimwide=ui->rimwideLab->text();
	//int rimwide1=rimwide.toInt();
	//my_symbol->border_width=rimwide1;//�ı�߿���           

	//int show_hrt;            //����Ϊ1 ��ʾ�ı�������ͼƬ���� ����Ϊ0 ����ʾ
	//if (ui->showNumCheckBox->isChecked())
	//{
	//	my_symbol->show_hrt=1;
	//} 

	//else  {my_symbol->show_hrt=0;}

	strcpy_s(my_symbol->outfile, "User/logo/output.bmp");
	ZBarcode_Encode(my_symbol, (unsigned char*) strCodeContent.c_str(), 0);
	generated=1;
	int error_num = ZBarcode_Print(my_symbol, 0);

	if (error_num != 0)
	//{
	//	/* some error occurred */
	//	//printf("%s\n", my_symbol->errtxt);
	//}

	ZBarcode_Delete(my_symbol);
		
	char* strFileName = "User/logo/output.bmp";
	QPixmap pLoad;
	pLoad.load(strFileName);
	int nW = pLoad.width();
	int nH = pLoad.height();
	QImage pImage;
	pImage = pLoad.toImage();
	pImage = pImage.scaled(pImage.width(),heightvalue1, Qt::IgnoreAspectRatio, Qt::SmoothTransformation); 

	//intLineStart = 0;
	//intRowStart = 0;
	strType1 = "text";
	strType2 = "2Dcode";
	//strText = strFileName;
	intLineSize = pImage.height();
	intRowSize = pImage.width(); 
	//intSW=1;
	//intSS=0;
	//booNEG=false;
	//booBWDx=false;
	//booBWDy=false;

	for(int y = 0; y< pImage.height(); y++)
	{  
		QRgb* line = (QRgb *)pImage.scanLine(y);  
		for(int x = 0; x< pImage.width(); x++)
		{  
			int average = (qRed(line[x]) + qGreen(line[x]) + qRed(line[x]))/3;  
			if(average < 200)
				boDotBmp[intRowStart +x][intLineStart+intLineSize -y-1] = true;
			else
				boDotBmp[intRowStart +x][intLineStart+intLineSize -y-1] = false;
		}  

	}  
	booFocus = true;
	QString get = QString(QLatin1String(strFileName)).toUtf8();
	//ɾ���ļ�
	QFile::remove(get);
}