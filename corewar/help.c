/*
** EPITECH PROJECT, 2023
** help
** File description:
** display flag -h
*/

#include "corewar.h"

void display_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("./corewar [-dump nbr_cycle] ");
    my_putstr("[[-n prog_number] [-a load_address] prog_name] ...\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("-dump nbr_cycle dumps the memory ");
    my_putstr("after the nbr_cycle execution (if the round isn't\n");
    my_putstr("already over) with the following format: 32 bytes/line\n");
    my_putstr("in hexadecimal (A0BCDEFE1DD3...)\n");
    my_putstr("-n prog_number sets the next program's number.");
    my_putstr(" By default, the first free number\n");
    my_putstr("in the parameter order\n");
    my_putstr("-a load_address sets the next program's loading address.");
    my_putstr(" When no address is\nspecified, optimize the addresses ");
    my_putstr("so that the processes are as far\n");
    my_putstr("away from each other as possible.");
    my_putstr(" The addresses are MEM_SIZE modulo.\n");
}
