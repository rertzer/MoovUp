/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:50:03 by fguarrac          #+#    #+#             */
/*   Updated: 2025/04/11 19:28:39 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int		main(void)
{
	enum e_state	state;
	Arm				arm;

	arm.init();
	state = E_GRAB;

	while (42)
	{
		switch (state)
		{
			case E_GRAB:
			{
				//	Wait for target pressure to be read
					//	if (some_finger's_pressure > grab pressure)
						//	state = E_CLOSE;
				break ;
			}
			case E_CLOSE:
			{
				//	Make little hand movement to acknowledge glass is in hand ?
				//	Close hand
				//	state = E_WAIT_BEFORE_SERVE;
				break ;
			}
			case E_WAIT_BEFORE_SERVE:
			{
				//	Delay
				//	Make little hand movement to annonce movement will start ?
				//	state = E_MOVE_TO_SERVE;
				break ;
			}
			case E_MOVE_TO_SERVE:
			{
				//	arm.move(E_ARM_SERV_POS);	//	Make it smooth !
				//	state = E_SERV;
				break ;
			}
			case E_SERV:
			{
				//	Wait for target pressure to be read
					//	if (some_finger's_pressure > release pressure)
						//	state = E_OPEN;
				break ;
			}
			case E_OPEN:
			{
				//	Start opening hand by pinky finger
				//	Then ring finger
				//	...
				//	Maybe keep thumb not fully open to still hold glass ?
				//	state = E_WAIT_BEFORE_GRAB;
				break ;
			}
			case E_WAIT_BEFORE_GRAB:
			{
				//	Delay
				//	Make little hand movement to annonce movement will start ?
				//	Fully open thumb ?
				//	state = E_MOVE_TO_GRAB;
				break ;
			}
			case E_MOVE_TO_GRAB:
			{
				//	arm.move(E_ARM_GRAB_POS);	//	Make it smooth !
				//	state = E_GRAB;
				break ;
			}
		}
		for (int i = 0; i < 5; i++)
			arm.getHand().getFinger(i).setPressure();
	}
}
