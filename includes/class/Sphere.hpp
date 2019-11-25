/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:13:58 by nrechati          #+#    #+#             */
/*   Updated: 2019/11/25 14:16:04 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include <iostream>

class Sphere
{
	public:
		Sphere(void);
		Sphere(Sphere const& src);
		virtual ~Sphere(void);

		Sphere& operator=(Sphere const& rhs);

	private:
};

std::ostream	&operator<< (std::ostream &out, const Sphere &rhs);

#endif
