/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProgressBar.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 09:06:51 by nrechati          #+#    #+#             */
/*   Updated: 2019/12/05 12:20:04 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/RayTracer.hpp"

/*
** Constructor / Destructor
*/
ProgressBar::ProgressBar(void) : bar_length(100), iterations(100) {
		time(&(this->clock));
		this->percent = 0;
		this->done_iter = 0;
		this->tick_rate = 0;
}

ProgressBar::ProgressBar(double iterations) : bar_length(100)
											, iterations(iterations) {
	time(&(this->clock));
	this->percent = 0;
	this->done_iter = 0;
	this->tick_rate = 0;
}

ProgressBar::~ProgressBar(void) { ; }

/*
** Set/Getters
*/
uint8_t				ProgressBar::getLength(void) const { return this->bar_length; }

double				ProgressBar::getIterations(void) const { return this->iterations; }
void				ProgressBar::setIterations(double iterations) {
	this->iterations = iterations;
}


/*
** Method and Member fucntion
*/

void				ProgressBar::update(double iterator) {
	time_t	timestamp;

	this->done_iter = iterator;
	this->percent = (int)(((float)this->done_iter / (float)this->iterations) * 100);

	double time_delta = difftime(time(&timestamp), this->clock);
	this->tick_rate = time_delta;

	time(&this->clock);
	this->eta = 0;

	std::cout << *this;
}

/*
** Static Overload operator
*/
std::ostream		&operator<<(std::ostream &out, ProgressBar const &rhs) {
	std::string		bar = "";
	std::string		pad = "";
	for (int i = 0; i < rhs.percent; i++) {
		bar += "█";
	}
	for (int i = 0; i < 100 - rhs.percent; i++) {
		bar += " ";
	}
	out << "Rendering ... " << rhs.percent << "% | "
		<< bar << pad
		<< " | ETA : NaN. sec"
		<< "\r";
	return (out);
}
