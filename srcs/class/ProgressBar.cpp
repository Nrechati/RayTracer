/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProgressBar.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 09:06:51 by nrechati          #+#    #+#             */
/*   Updated: 2020/01/22 12:15:22 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/RayTracer.hpp"

/*
** Constructor / Destructor
*/
ProgressBar::ProgressBar(void) : bar_length(100), iterations(100) {
		this->percent = 0;
		this->done_iter = 0;
		this->tick_rate = 0;
		this->eta = 0;
		this->clock = std::chrono::high_resolution_clock::now();
		this->start = this->clock;
}

ProgressBar::ProgressBar(size_t iterations) : bar_length(100)
											, iterations(iterations) {
	system("tput civis");
	this->percent = 0;
	this->done_iter = 0;
	this->tick_rate = 0;
	this->eta = 0;
	this->clock = std::chrono::high_resolution_clock::now();
	this->start = this->clock;
}

ProgressBar::~ProgressBar(void) { system("tput cnorm"); }

/*
** Set/Getters
*/
uint8_t				ProgressBar::getLength(void) const { return this->bar_length; }
size_t				ProgressBar::getIterations(void) const { return this->iterations; }
void				ProgressBar::setIterations(size_t iterations) {
	this->iterations = iterations;
}

/*
** Method and Member fucntion
*/

void				ProgressBar::update(size_t iterator) {
	std::chrono::steady_clock::time_point tmp_time = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> tick_time = tmp_time - this->clock;
	this->clock = tmp_time;
	this->done_iter = iterator;
	this->percent = (int)(((float)this->done_iter / (float)this->iterations) * 100); //NO C Cast
	this->tick_rate = tick_time.count();
	this->eta = this->tick_rate * (this->iterations - this->done_iter);
	std::cout << *this;
}

/*
** Static Overload operator
*/
std::ostream		&operator<<(std::ostream &out, ProgressBar const &rhs) {
	std::string		bar = "";
	std::string		percent_pad="";
	std::chrono::duration<double> total_time = rhs.clock - rhs.start;
	for (int i = 0; i < rhs.percent; i++) { bar += "█";	}
	for (int i = 0; i < 100 - rhs.percent; i++) {bar += " ";}
	if (rhs.percent < 10)
		percent_pad = "  ";
	else if (rhs.percent == 100)
		percent_pad = "";
	else
		percent_pad = " ";
	out << "\033[1;32m";
	out << "Rendering ... " << percent_pad << rhs.percent << "% | ";
	out	<< bar;
	if (rhs.eta >= 60)
		out	<< " | ETA : "<< std::setprecision(2) << rhs.eta / 60 << "min ";
	else
		out << " | ETA : " << std::setprecision(2) << rhs.eta << "sec ";
	out	<< "| Iterations : " << rhs.done_iter + 1 << "/" << rhs.getIterations() + 1;
	if (total_time.count() >= 60)
		out << " | Elapsed time : " << total_time.count() / 60 << "min";
	else
		out << " | Elapsed time : " << total_time.count() << "sec";
	out << "     \033[1;0m\r";
	return (out);
}
