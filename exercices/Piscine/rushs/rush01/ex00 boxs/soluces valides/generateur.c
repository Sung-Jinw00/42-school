/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generateur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:44:46 by marvin            #+#    #+#             */
/*   Updated: 2024/10/28 16:44:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9

// Fonction pour vérifier si un numéro peut être placé dans la grille
int isSafe(int **grid, int row, int col, int num)
{
    int x, y;

    // Vérifie la ligne
    for (x = 0; x < N; x++)
    {
        if (grid[row][x] == num)
            return 0;
    }

    // Vérifie la colonne
    for (y = 0; y < N; y++)
    {
        if (grid[y][col] == num)
            return 0;
    }

    return 1; // Le numéro peut être placé
}

// Fonction récursive pour résoudre le puzzle
int solveSkyscraper(int **grid)
{
    int row, col;

    // Trouver une case vide
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
            {
                for (int num = 1; num <= N; num++)
                {
                    if (isSafe(grid, row, col, num))
                    {
                        grid[row][col] = num; // Place le numéro
                        if (solveSkyscraper(grid))
                            return 1;
                        grid[row][col] = 0; // Backtrack
                    }
                }
                return 0; // Si aucun numéro ne convient
            }
        }
    }
    return 1; // Si la grille est complètement remplie
}

// Fonction pour générer une grille valide
void generateValidGrid(int **grid)
{
    int num;
    int row, col;

    // Initialiser la grille à zéro
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            grid[row][col] = 0;
        }
    }

    // Remplir la grille avec des numéros aléatoires
    for (num = 1; num <= N; num++)
    {
        row = rand() % N;
        col = rand() % N;
        while (!isSafe(grid, row, col, num))
        {
            row = rand() % N;
            col = rand() % N;
        }
        grid[row][col] = num;
    }

    // Résoudre la grille pour remplir les cases restantes
    solveSkyscraper(grid);
}

// Fonction pour extraire les conditions d'une grille valide
void extractConditions(int **grid, int conditions[N][4])
{
    int i, j;
    
    // Pour chaque ligne, calculer les conditions
    for (i = 0; i < N; i++)
    {
        // Conditions pour chaque bord
        conditions[i][0] = conditions[i][1] = conditions[i][2] = conditions[i][3] = 0;

        // Vérifier les bâtiments visibles depuis le haut
        int max = 0, visible = 0;
        for (j = 0; j < N; j++)
        {
            if (grid[j][i] > max)
            {
                max = grid[j][i];
                visible++;
            }
        }
        conditions[i][0] = visible; // Haut

        // Vérifier les bâtiments visibles depuis le bas
        max = 0;
        visible = 0;
        for (j = N - 1; j >= 0; j--)
        {
            if (grid[j][i] > max)
            {
                max = grid[j][i];
                visible++;
            }
        }
        conditions[i][1] = visible; // Bas

        // Vérifier les bâtiments visibles depuis la gauche
        max = 0;
        visible = 0;
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] > max)
            {
                max = grid[i][j];
                visible++;
            }
        }
        conditions[i][2] = visible; // Gauche

        // Vérifier les bâtiments visibles depuis la droite
        max = 0;
        visible = 0;
        for (j = N - 1; j >= 0; j--)
        {
            if (grid[i][j] > max)
            {
                max = grid[i][j];
                visible++;
            }
        }
        conditions[i][3] = visible; // Droite
    }
}

// Fonction pour afficher la grille
void printGrid(int **grid)
{
    int row, col;
    
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Fonction pour afficher les conditions
void printConditions(int conditions[N][4])
{
    int i;
    printf("Conditions:\n");
    for (i = 0; i < N; i++)
    {
        printf("Ligne %d: Haut = %d, Bas = %d, Gauche = %d, Droite = %d\n", 
               i + 1, conditions[i][0], conditions[i][1], conditions[i][2], conditions[i][3]);
    }
}

int main()
{
    int **grid;
    int conditions[N][4];

    // Allocation de mémoire pour la grille
    grid = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        grid[i] = malloc(N * sizeof(int));
    }

    srand(time(NULL)); // Initialiser le générateur de nombres aléatoires

    // Générer une grille valide
    generateValidGrid(grid);
    
    // Extraire les conditions de la grille
    extractConditions(grid, conditions);
    
    // Afficher la grille et les conditions
    printf("Grille générée :\n");
    printGrid(grid);
    printConditions(conditions);

    // Libérer l'espace mémoire
    for (int i = 0; i < N; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
