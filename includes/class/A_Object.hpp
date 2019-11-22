/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstract.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:14:08 by nrechati          #+#    #+#             */
/*   Updated: 2019/10/22 08:39:34 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_OBJECT_H
# define A_OBJECT_H
# include <iostream>

class A_Object
{
	public:
		A_Object(void);
		A_Object(A_Object const& src);
		virtual ~A_Object(void);

		A_Object& operator=(A_Object const& rhs);

		virtual void function() const = 0;

	private:
};

std::ostream	&operator<< (std::ostream &out, const A_Object &rhs);

#endif
