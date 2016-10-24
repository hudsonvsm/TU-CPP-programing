#include "stdafx.h"
#include "CLaptopShop.h"
#include <vector>
#include <iostream>
#include <string>


CLaptopShop::CLaptopShop() {}

CLaptopShop::~CLaptopShop() {}

CLaptopShop::CLaptopShop(std::vector<CLaptop> vctr)
{
	m_vSales = vctr;
}

//����� �� �������� �� ������
void CLaptopShop::AddLaptop(CLaptop &element)
{
	m_vSales.push_back(element);
}

//������������ �� ������ �������, ���� �� ��������
//���� �������������� �������� �� ���������� � ostream '<<'
void CLaptopShop::Show()
{
	for each (auto element in m_vSales)
	{
		std::cout << element << std::endl;
	}
}

//����� �� ����������� �� ������ ������� �� ����� ������������
void CLaptopShop::MaxSalesByProducer(IN std::string strProducer, OUT int& nNum)
{
	nNum = 0;

	for each (CLaptop element in m_vSales)
	{
		std::string b = element.GetProducer();
		if (b == strProducer)
		{
			nNum++;
		}
	}
}

//����� �� ����������� �� ������ ������� �� ������ �� ������
void CLaptopShop::MaxSalesByScreenSize(IN const int& nScreenSize, OUT int& nNum)
{
	nNum = 0;

	for each (auto element in m_vSales)
	{
		if (*element.GetScreenSize() == nScreenSize)
		{
			nNum++;
		}
	}
}