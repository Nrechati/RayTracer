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

#ifndef CAMERA_H
# define CAMERA_H
# include <iostream>

class Camera
{
	public:
		Camera(void);
		Camera(Camera const& src);
		virtual ~Camera(void);

		Camera& operator=(Camera const& rhs);

	private:
};

std::ostream	&operator<< (std::ostream &out, const Camera &rhs);

#endif
