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
 * @brief exception class
 * 
 */
class DataInvalida { };

/**
 * @brief exception class
 * 
 */
class FormatoStringInvalido { };


class Day
{	
	/**
	 * @brief day's attribute
	 * 
	 */
	unsigned int ano, mes, dia;

public:
	
	/**
	 * @brief Construct a new Day object
	 * 
	 * @param a year
	 * @param m month
	 * @param d day
	 */
	Day(unsigned int a, unsigned int m, unsigned int d);

	/**
	 * @brief Construct a new Day object
	 * 
	 * @param d date's string
	 */
	Day(std::string d);

	/**
	 * @brief Gets the year of the object
	 * 
	 * @return unsigned int date's year
	 */
	unsigned int getAno() const;

	/**
	 * @brief Gets the month of the object
	 * 
	 * @return unsigned int date's month
	 */
	unsigned int getMes() const;

	/**
	 * @brief Gets the day of the object
	 * 
	 * @return unsigned int date's day
	 */
	unsigned int getDia() const;

	/**
	 * @brief Get the Total Hours object
	 * 
	 * @return double total hours
	 */
	double getTotalHours() const;

	/**
	 * @brief Overload of operand greater
	 * 
	 * @param d1 reference to the day that we going to compare
	 *
	 * @return True if d1 is lower and false otherwise
	 */
	bool operator>(const Day &d1);

	/**
	 * @brief Overload of operand equal
	 * @param d1 reference to the day that we going to compare
	 * @return True if days are equal and false otherwise
	 */
	bool operator==(const Day &d1);

	/**
	 * @brief Overload of the operand less
	 * @param d1 reference to the day that we going to compare
	 * @return True if d1 is greater and false otherwise
	 */
	bool operator<(const Day &d1);

	/**
	 * @brief Outstream operator overload for class Day
	 * 
	 * @param os Output stream
	 * @param d day wanted
	 * @return ostream& Output stream
	 */
	friend std::ostream& operator<< (std::ostream &os, const Day &d);
};

#endif
