#include <iostream>
#include <vector>

//// On veut représenter l'environnement dans lequel circuleront des robots.
//
// L'environnement est une grille 2D
//Chaque élément de la grille peut contenir un autre robot, un obstacle, ou être vide.

class Environnement {
private:
    int largeur;
    int hauteur;
    std::vector<std::vector<int>> grille;

public:
    // Constructeur pour créer un environnement avec une grille vide
    Environnement(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur) {
        grille = std::vector<std::vector<int>>(largeur, std::vector<int>(hauteur, 0));
    }
    
    // Placer un robot 
    void placerRobot(int x, int y) {
        if (x >= 0 && x < largeur && y >= 0 && y < hauteur) {
            grille[x][y] = 1;
        } else {
            std::cout << "Coordonnées hors de la grille." << std::endl;
        }
    }

    // Placer un obstacle 
    void placerObstacle(int x, int y) {
        if (x >= 0 && x < largeur && y >= 0 && y < hauteur) {
            grille[x][y] = 2;
        } else {
            std::cout << "Coordonnées hors de la grille." << std::endl;
        }
    }

    // Afficher l'environnement
    void afficherEnvironnement() {
        for (int x = 0; x < largeur; x++) {
            for (int y = 0; y < hauteur; y++) {
                if (grille[x][y] == 0) {
                    std::cout << " *"; // Cellule vide
                } else if (grille[x][y] == 1) {
                    std::cout << " R"; // Robot
                } else if (grille[x][y] == 2) {
                    std::cout << " X"; // Obstacle
                };
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Environnement environnement(10, 10);
    environnement.placerRobot(0, 0);
    environnement.placerObstacle(5, 5);
    environnement.afficherEnvironnement();
    return 0;
}