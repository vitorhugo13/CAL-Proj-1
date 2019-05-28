#ifndef DAY_H
#define DAY_H

#include <vector>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <limits>

/**
 * Excepcao
 */
class DataInvalida { };

/**
 * Excepcao
 */
class FormatoStringInvalido { };

/**
 * @brief Class that handles days in this project.
 * 
 */
class Day
{
	unsigned int ano, mes, dia;

public:
	/**
	 * Contrutor de datas por inteiros
	 * @param a Ano
	 * @param m Mes
	 * @param d Dia
	 */
	Day(unsigned int a, unsigned int m, unsigned int d);

	/**
	 * Construtor de datas por strings\n
	 * Faz parse a string tem excepcoes para formatos errados
	 * @param d String com data no formato DD-MM-AAAA
	 */
	Day(std::string d);

	/**
	 * @return Ano
	 */
	unsigned int getAno() const;

	/**
	 * @return Mes
	 */
	unsigned int getMes() const;

	/**
	 * @return Dia
	 */
	unsigned int getDia() const;

	/**
	 * @return Numero de horas totais desde o ano 2000, util para comparacao direta
	 * de um momento especifico
	 */
	double getTotalHours() const;

	/**
	 * Redefinicao do operador maior
	 * @param d1 Referencia para a data com a qual se vai comparar
	 * @return True se d1 e menor
	 */
	bool operator>(const Day &d1);

	/**
	 * Redefinicao do operador comparacao
	 * @param d1 Referencia para a data com a qual se vai comparar
	 * @return True se as duas datas sao iguais
	 */
	bool operator==(const Day &d1);

	/**
	 * Redefinicao do operador menor
	 * @param Referencia para a data com a qual se vai comparar
	 * @return True se d1 e maior
	 */
	bool operator<(const Day &d1);

	friend std::ostream& operator<< (std::ostream &os, const Day &d);
};

#endif
