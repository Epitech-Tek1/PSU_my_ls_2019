/*
** EPITECH PROJECT, 2019
** 104intersection
** File description:
** function
*/

#ifndef FUNCTION_H_
#define FUNCTION_H_


////////////////////////////////////////////////////////////
/// \brief Init all variables
///
/// \param main_s Struct contains programm's informations
/// \param ac nomber of argument
/// \param av string contains arguments
///
/// \return 84 if an error occured. else return 0
////////////////////////////////////////////////////////////
int initialisation(main_s *main_s, int ac, char **av);


////////////////////////////////////////////////////////////
/// \brief Check if there is an error
///
/// \param main_s Struct contains programm's informations
///
/// \return 84 if an error occured. else return 0
////////////////////////////////////////////////////////////
int error_handling(main_s *main_s);


////////////////////////////////////////////////////////////
/// \brief Process programm's
///
/// \param main_s Struct contains programm's informations
///
/// \return void
////////////////////////////////////////////////////////////
void process(main_s *main_s);


////////////////////////////////////////////////////////////
/// \brief Display results
///
/// \param main_s Struct contains programm's informations
///
/// \return void
////////////////////////////////////////////////////////////
void display(main_s *main_s);


////////////////////////////////////////////////////////////
/// \brief Assign color
///
/// \param main_s Struct contains programm's informations
///
/// \return void
////////////////////////////////////////////////////////////
void color(main_s *main_s);

void get_authorization(struct stat fileStat);

void get_inform(struct stat fileStat);

void my_ls_l(char **info);

void my_ls_d(char **info);

void my_ls_t(char **info);

void my_ls_R(char **info);

void my_ls_r(char **info);

int total_block(main_s *main_s);

int rep_error(main_s *main_s, char *flag);

void display_rmaj(main_s *main_s);

void display_basics(main_s *main_s);

void display_t(main_s *main_s);

int preg_match(main_s *main_s, char *flag);

#endif /* !FUNCTION_H_ */