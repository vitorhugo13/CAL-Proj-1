#include "Day.h"

Day::Day(unsigned int a, unsigned int m, unsigned int d)
{
	if (d > 31 || d < 1 || m > 12 || m < 1)
		throw DataInvalida();
	ano = a;
	mes = m;
	dia = d;
}

Day::Day(std::string d)
{
	std::string tempDia = "";
	std::string tempMes = "";
	std::string tempAno = "";

	if (d.length() != 10)
		throw FormatoStringInvalido();

	for (unsigned int i = 0; i < d.length(); i++)
	{

		if (d.at(i) < '0' && d.at(i) > '9' && d.at(i) != '-'&& d.at(i) != '/')
			throw FormatoStringInvalido();

		if (d.at(i) == '-' || d.at(i) == '/')
		{
			continue;
		}

		if (tempDia.length() < 2)
		{
			tempDia += d.at(i);
			continue;
		}
		if (tempMes.length() < 2)
		{
			tempMes += d.at(i);
			continue;
		}
		if (tempAno.length() < 4)
		{
			tempAno += d.at(i);
			continue;
		}
		else
			break;
	}

	if (tempDia.length() < 2)
		throw FormatoStringInvalido();

	if (tempMes.length() < 2)
		throw FormatoStringInvalido();

	if (tempAno.length() < 4)
		throw FormatoStringInvalido();

	int tDia = std::stoi(tempDia);
	int tMes = std::stoi(tempMes);
	int tAno = std::stoi(tempAno);

	if (tDia > 31 || tDia < 1 || tMes > 12 || tMes < 1)
		throw DataInvalida();

	dia = tDia;
	mes = tMes;
	ano = tAno;
}

unsigned int Day::getAno() const { return ano; }

unsigned int Day::getMes() const { return mes; }

unsigned int Day::getDia() const { return dia; }

double Day::getTotalHours() const
{

	double hours = (ano - 2000) * 365.2425;

	switch (mes)
	{
	case 2:
		hours += 31;
		break;
	case 3:
		hours += 59;
		break;
	case 4:
		hours += 90;
		break;
	case 5:
		hours += 120;
		break;
	case 6:
		hours += 151;
		break;
	case 7:
		hours += 181;
		break;
	case 8:
		hours += 212;
		break;
	case 9:
		hours += 243;
		break;
	case 10:
		hours += 273;
		break;
	case 11:
		hours += 304;
		break;
	case 12:
		hours += 334;
		break;
	}

	hours += dia;

	return hours * 24;
}



bool Day::operator>(const Day &d1)
{

	if (this->ano > d1.ano)
		return true;
	if (this->ano == d1.ano)
	{
		if (this->mes > d1.mes)
			return true;
		if (this->mes == d1.mes)
		{
			if (this->dia > d1.dia)
				return true;
		}
	}
	return false;
}

bool Day::operator==(const Day &d1)
{
	if (this->ano == d1.ano && this->mes == d1.mes && this->dia == d1.dia)
		return true;

	return false;
}

bool Day::operator<(const Day &d1)
{
	if (this->ano < d1.ano)
		return true;
	if (this->ano == d1.ano)
	{
		if (this->mes < d1.mes)
			return true;
		if (this->mes == d1.mes)
		{
			if (this->dia < d1.dia)
				return true;
		}
	}
	return false;
}

std::ostream& operator<< (std::ostream &os, const Day &d){
	if(d.getDia() < 10){
		os << "0";
	}
	os << d.getDia() << "/";
	if (d.getMes() < 10){
		os << "0";
	}
	os << d.getMes() << "/" << d.getAno();
	return os;
}
