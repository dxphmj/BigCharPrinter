#include "DMcodeOBJ.h"
#include "backend\zint.h"

CDMcodeOBJ::CDMcodeOBJ(void)
{
}

CDMcodeOBJ::~CDMcodeOBJ(void)
{
}

void CDMcodeOBJ::CreateDMcode()
{
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	int batch_mode;
	int mirror_mode;
	char filetype[4];
	int i;

	error_number = 0;

	rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = 1;
	my_symbol->symbology = 71;
	my_symbol->scale =0.5;

	my_symbol->option_2 = intDMsize;

	batch_mode = 0;
	mirror_mode = 0;
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strDMContent.c_str(),strDMContent.length(),rotate_angle);

	generated = 1;

	int xPos=0;
	int yPos=0;
	/*for(int i=0;i<OBJ_Vec.size();i++)
	{
		if (booFocus)
		{
			booFocus=false;
			yPos = intLineStart;
			xPos = intRowSize+intRowStart;
		}
	}*/

	
	intLineStart=yPos;
	intRowStart=xPos;
	strType1="text";
	strType2="datamatrix";
	intLineSize=my_symbol->bitmap_height;
	intRowSize=my_symbol->bitmap_width;
	//intDMsize = nType;
	//bmpObj.strDMContent = strContent.toStdString();
	//bmpObj.strText = strContent.toStdString();
	//������д��
	/*bmpObj.intSW=1;
	bmpObj.intSS=1;
	bmpObj.booNEG=false;
	bmpObj.booBWDx=false;
	bmpObj.booBWDy=false;*/
	i = 0;
	int r, g, b;

	for (int row = 0; row < my_symbol->bitmap_height; row++)
	{
		for (int col = 0;col < my_symbol->bitmap_width; col++)
		{
			r = my_symbol->bitmap[i];
			g = my_symbol->bitmap[i + 1];
			b = my_symbol->bitmap[i + 2];
			i += 3;
			if (r == 0 && g == 0 && b == 0)
			{
				//		bmpObj.boDotBmp[col][row-proportion] = true; //��������ϵ��ԭ�����±���ߵ�
				boDotBmp[col][my_symbol->bitmap_height-row-1] = true;
			}
			else
			{
				//		bmpObj.boDotBmp[col][row-proportion] = false;
				boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
			}
		}
	}
	booFocus = true;
}
