#include "stdafx.h"
#include "CLaptop.h"

//������������ �� ������������ ������� ����� � ������� 
//��������� �� ������������ �� ������������
CLaptop::CLaptop()
{
	m_strProducer = "";
	m_npScreenSize = new int;
	*m_npScreenSize = 0;
}

//����������� � 2 ����������. ������� ����� � ������� 
//����������� �� �����������
CLaptop::CLaptop(std::string oem, int screenSize)
{
	assert(screenSize >= 0);
	m_strProducer = oem;
	m_npScreenSize = new int;
	*m_npScreenSize = screenSize;
}

//����������� � ���� ��������� (screenSize)
//������� ������������ � 2 ����������, ���� �� ������ ������
//������ ������
CLaptop::CLaptop(int screenSize) : CLaptop("", screenSize) {}

//����������� �� �����. ����� deap coppy �� ������,
//���� ������� �����, ���������� ����������� � ������ ��������
CLaptop::CLaptop(const CLaptop &obj)
{
	m_strProducer = obj.m_strProducer;
	m_npScreenSize = new int;
	*m_npScreenSize = *obj.m_npScreenSize;
}

//����������, ����� ����������� �������
CLaptop::~CLaptop()
{
	delete	m_npScreenSize;
}

//����� �� ������� �� ���������� �� ������� �� ������
//����� �� ������ ��������, � ��������� ��� �������. ����
//����� ������ �� ����� �������� � ����� �� �������� ������ �� ��������
//�� ������� ����
int * CLaptop::GetScreenSize()
{
	return this->m_npScreenSize;
}

//����� �� �������������
std::string CLaptop::GetProducer()
{
	return m_strProducer;
}

///////////////////////////////////////
//������������� �� ����������� �� ������ ����������� � ���������



std::ostream& operator<< (std::ostream &out, const CLaptop &obj)
{
	out << "Vendor: " << obj.m_strProducer << std::endl
		<< "Screen Size: " << *obj.m_npScreenSize << "\"";
	return out;
}

std::istream& operator >> (std::istream &in, CLaptop &obj)
{
	in >> obj.m_strProducer;
	in >> *obj.m_npScreenSize;

	return in;
}

CLaptop& CLaptop::operator= (const CLaptop &obj)
{
	if (m_npScreenSize) delete m_npScreenSize;

	m_strProducer = obj.m_strProducer;

	m_npScreenSize = new int;
	m_npScreenSize = obj.m_npScreenSize;

	return *this;
}

bool operator> (const CLaptop &obj1, const CLaptop &obj2)
{
	return *obj1.m_npScreenSize > *obj2.m_npScreenSize;
}

bool operator>= (const CLaptop &obj1, const CLaptop &obj2)
{
	return *obj1.m_npScreenSize >= *obj2.m_npScreenSize;
}

bool operator< (const CLaptop &obj1, const CLaptop &obj2)
{
	return *obj1.m_npScreenSize < *obj2.m_npScreenSize;
}

bool operator<= (const CLaptop &obj1, const CLaptop &obj2)
{
	return *obj1.m_npScreenSize <= *obj2.m_npScreenSize;
}

