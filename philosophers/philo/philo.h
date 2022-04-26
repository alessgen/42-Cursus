
#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

/* Struct dell'inizializzazione */
// is_dead = 0 (vivo) - is_dead = 1 (morto).
typedef struct s_init
{
	int				num_philo;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				n_toeat;
	int				is_dead;
	int				alleat;
	long			timestart;
	pthread_mutex_t	*ph_forks;
	pthread_mutex_t	locker;
	pthread_mutex_t	checkeat;
	pthread_mutex_t	allate;
	pthread_mutex_t death;
	pthread_mutex_t meal;
}				t_init;

/* Struct dei vari filosofi */
typedef struct s_philo
{
	int			ph_id;
	int			lfork;
	int			rfork;
	int			n_meals;
	long long	last_meal;
	t_init		*init_ph;
}				t_philo;

/* Utils */
int			one_philo(t_philo *philo);
int 		ft_check_input(int ac, char **av);
int 		check_is_died(t_philo *philo);
int			check_all_eat(t_philo *philo);
int			ft_atoi(const char *str);
int			ft_check_args(int argc, char **argv);
long long	ft_get_time(void);
void		ft_printing(t_philo *philo, char *string);
void 		ft_smart_action(long long time, t_philo *philo);
/* Start Initialization */
t_philo		*ft_fill_philo(t_init *init);
int			ft_init_philo(t_init *init, char **argv);
void		check_if_dead(t_philo *philo);
void		*ft_one_philo(t_philo *philo);

#endif