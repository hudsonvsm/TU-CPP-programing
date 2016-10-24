#pragma once
#include <string>
#include <cassert>

//���� ����� ������ ������.
//������� 2 ������, ���� � ����� �� � ����������� �����. ������� � ���� �� ��� std::string,
//����� ��� �� ����� �� ���������� � ���������������. ������� � *int, �� ����� ����� CLaptop
//������� � ��������� ����� � �� ����� �� ����������������� �� memory leaks
class CLaptop
{
	//Constructors
public:
	CLaptop();
	CLaptop(std::string oem, int screenSize);
	CLaptop(int screenSize);
	CLaptop(const CLaptop &obj);
	~CLaptop();

	//Public Member Functions
public:
	int* GetScreenSize();
	std::string GetProducer();

	//Operator Overload
public:
	friend std::ostream& operator<< (std::ostream &out, const CLaptop &obj);
	friend std::istream& operator >> (std::istream &in, CLaptop &obj);
	CLaptop& operator= (const CLaptop &str);
	friend bool operator> (const CLaptop &obj1, const CLaptop &obj2);
	friend bool operator>= (const CLaptop &obj1, const CLaptop &obj2);
	friend bool operator< (const CLaptop &obj1, const CLaptop &obj2);
	friend bool operator<= (const CLaptop &obj1, const CLaptop &obj2);

	//Private fields
private:
	std::string m_strProducer;	//OEM
	int *m_npScreenSize;		//Screen size in Inch
};


