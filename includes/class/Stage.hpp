/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:13:58 by nrechati          #+#    #+#             */
/*   Updated: 2019/10/22 08:39:11 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAGE_H
# define STAGE_H
# include <iostream>

class Stage
{
	public:
		Stage(void);
		Stage(Stage const& src);
		virtual ~Stage(void);

		Stage& operator=(Stage const& rhs);

	private:
};

std::ostream	&operator<< (std::ostream &out, const Stage &rhs);

#endif
