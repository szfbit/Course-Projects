// ggg.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include "Form1.h"
#include "Form2.h"
#include "SInter.h"


using namespace ggg;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �ڴ����κοؼ�֮ǰ���� Windows XP ���ӻ�Ч��
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// ���������ڲ�������
	Application::Run(gcnew Form1());

	return 0;
}
