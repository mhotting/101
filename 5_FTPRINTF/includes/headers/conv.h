/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 10:21:29 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 21:25:24 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CONV_H
# define CONV_H

int		ft_atoi(const char *nptr);
char	*ft_itoa(long long int n);
char	*ft_uitoa(unsigned long long int n);
char	*ft_itoabase(long long int n, int base);
char	*ft_uitoabase(unsigned long long int n, int base);
char	*ft_ctoa(char c);
char	*ft_ldtoa(long double f, size_t prec);

#endif
