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

#ifndef LIGHT_H
# define LIGHT_H
# include <iostream>

class Light
{
	public:
		Light(void);
		Light(Light const& src);
		virtual ~Light(void);

		Light& operator=(Light const& rhs);

	private:
};

std::ostream	&operator<< (std::ostream &out, const Light &rhs);

#endif
