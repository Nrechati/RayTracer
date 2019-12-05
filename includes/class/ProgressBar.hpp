/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProgressBar.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:57:19 by nrechati          #+#    #+#             */
/*   Updated: 2019/12/05 13:34:55 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRESSBAR_H
# define PROGRESSBAR_H
# include "core/RayTracer.hpp"
# include <chrono>

class ProgressBar {
	public:
		ProgressBar(void);
		ProgressBar(size_t iterations);
		virtual ~ProgressBar(void);

		uint8_t			getLength(void) const;
		void			setIterations(const size_t);
		size_t			getIterations(void) const;

		void			update(size_t iterator);

		int										percent;
		size_t									done_iter;
		double									tick_rate;
		double									eta;
		std::chrono::steady_clock::time_point	clock;
		std::chrono::steady_clock::time_point	start;

	private:
		const uint8_t	bar_length;
		size_t			iterations;
};

std::ostream	&operator<< (std::ostream &out, const ProgressBar &rhs);

#endif
