/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:03:17 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/25 18:46:10 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

//compile avec -lreadline pour avoir les fonctions de readline
//le bash doit fonctionner sur bash, pas zsh

int main()
{
    char *line = readline("Entrez quelque chose : ");
    
    if (line)
	{
        // Remplacer la ligne actuelle par un texte différent
        rl_replace_line("Ligne remplacée!", 0);
        
        // Afficher la nouvelle ligne après remplacement
        printf("Ligne après remplacement : %s\n", rl_line_buffer);
        
        free(line);  // Libérer la mémoire allouée
    }
    
    return 0;
}