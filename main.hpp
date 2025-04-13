/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:49:44 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/11 19:07:14 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include "Arm.hpp"

enum e_state
{
	E_GRAB,
	E_CLOSE,
	E_WAIT_BEFORE_SERVE,
	E_MOVE_TO_SERVE,
	E_SERV,
	E_OPEN,
	E_WAIT_BEFORE_GRAB,
	E_MOVE_TO_GRAB
};

#endif
