/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hand.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:58:57 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/11 19:17:22 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAND_HPP
#define HAND_HPP

#include "Finger.hpp"

class Hand {
	Finger _fingers[5];	 //	Usefull here ?	//	Use enum with finger names ?

   public:
	Hand(void);
	Hand(Hand const&);
	Hand& operator=(Hand const&);
	~Hand(void);

	Finger getFinger(int) const;

	void init(void) const;
	void close(void) const;
	void open(void) const;
	//	Animate hand
	//	Rock, paper, scissors
	//	..
};

#endif
