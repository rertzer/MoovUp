#include "ft_itoa.hpp"

static char*	chop_nbr_dec(char* buffer, uint16_t nb, uint16_t len);
static uint16_t ft_getlen_dec(uint16_t nb);

void ft_itoa_dec(uint16_t nb, char* buffer) {
	uint16_t len;

	len = ft_getlen_dec(nb);
	buffer[len] = '\0';
	(chop_nbr_dec(buffer, nb, len));
}

static uint16_t ft_getlen_dec(uint16_t nb) {
	uint16_t len;

	len = 1;
	while (nb / 10) {
		nb = nb / 10;
		++len;
	}
	return (len);
}

static char* chop_nbr_dec(char* buffer, uint16_t nb, uint16_t len) {
	char base[11] = "0123456789";
	while (nb / 10) {
		--len;
		buffer[len] = base[nb % 10];
		nb = nb / 10;
	}
	buffer[len - 1] = base[nb % 10];
	return (buffer);
}
