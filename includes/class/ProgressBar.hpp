/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProgressBar.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:57:19 by nrechati          #+#    #+#             */
/*   Updated: 2019/12/05 11:59:08 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRESSBAR_H
# define PROGRESSBAR_H
# include "core/RayTracer.hpp"

class ProgressBar {
	public:
		ProgressBar(void);
		ProgressBar(double iterations);
		virtual ~ProgressBar(void);

		uint8_t			getLength(void) const;
		void			setIterations(const double);
		double			getIterations(void) const;

		void			update(double iterator);

		time_t			clock;
		int				percent;
		double			done_iter;
		double			tick_rate;
		double			eta;

	private:
		const uint8_t	bar_length;
		double			iterations;
};

std::ostream	&operator<< (std::ostream &out, const ProgressBar &rhs);

#endif
