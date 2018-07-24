#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "mysql.h"
#include "../inc/affichage.h"

int main () {
  MYSQL* connect;
  MYSQL_RES *results;
  MYSQL_ROW line;

  MLV_Keyboard_button touche;

  char* nom_recup;
  char* prenom_recup;
  
  char* requete;
  char* requete_tte_infos;
  
  char* resultat;
  char* resultat_tte_infos;

  my_ulonglong nombre_lignes;

  int i = 0;
  
  requete = (char*) malloc(80);

  resultat = (char*) malloc(50);

  requete_tte_infos = (char*) malloc(80);

  resultat_tte_infos = (char*) malloc(300);
  
  init_fenetre();
  connect = mysql_init(NULL);

  if(!mysql_real_connect(connect, "localhost", "root", "rootsql", "Work", 0, NULL, 0)) {
    /* Problème lors de la connexion à la BDD. */
    fprintf(stderr, "%s\n", mysql_error(connect));
    affich_text_err_connec();
    
    return -1;
  }

  while (1) {
    touche = MLV_KEYBOARD_a;
    //Réinitialisation des requêtes SQL et des résultats
    strcpy(requete, "select numero, nom, prenom from Velo where nom = \"");
    strcpy(requete_tte_infos, "select * from Velo where nom = \"");
    strcpy(resultat, "");
    strcpy(resultat_tte_infos, "");
  
    /* Page de demande de nom de famille */
    nom_recup = affich_demande();
    strcat(requete, nom_recup);
    strcat(requete, "\"");

    fprintf(stdout, "%s\n", requete);
    mysql_real_query(connect, requete, strlen(requete));
  
    results = mysql_store_result(connect);  
    nombre_lignes = mysql_num_rows(results);
  
    if (nombre_lignes != 0) {
      MLV_clear_window(MLV_COLOR_WHITE);
    
      for (i = 0; i < nombre_lignes; i++) {
	line = mysql_fetch_row(results);
      
	strcpy(resultat, "");
	strcat(resultat, line[1]);
	strcat(resultat, " ");
	strcat(resultat, line[2]);

	affich_resultat_ligne(resultat, (i+1)*50);
      }

      /* Page de demande du prénom */
      prenom_recup = affich_demande_prenom();
      strcat(requete_tte_infos, nom_recup);
      strcat(requete_tte_infos, "\" and prenom = \"");
      strcat(requete_tte_infos, prenom_recup);
      strcat(requete_tte_infos, "\" COLLATE FRENCH_CI_AI");

      fprintf(stdout, "%s\n", requete_tte_infos);
      
      mysql_real_query(connect, requete_tte_infos, strlen(requete_tte_infos));
      
      fprintf(stderr, "%s\n", mysql_error(connect));
      results = mysql_store_result(connect);
      nombre_lignes = mysql_num_rows(results);

      if (nombre_lignes != 1) {
	affich_text_err_prenom_bdd();
	continue;
      }
      else {
	line = mysql_fetch_row(results);

	// Texte de réponse à insérer, puis à afficher
	strcpy(resultat_tte_infos, "");
	strcat(resultat_tte_infos, line[1]);
	strcat(resultat_tte_infos, " ");
	strcat(resultat_tte_infos, line[5]);

	affich_resultat(resultat_tte_infos);
	
	fprintf(stdout, "%s %s %s %s %s %s %s %s %s %s %s %s %s\n", line[0], line[1], line[2], line[3], line[4], line[5], line[6], line[7], line[8], line[9], line[10], line[11], line[12]);

	/* L'utilisateur doit appuyer sur la barre d'espace du clavier pour retourner à l'accueil. */
	while (touche != MLV_KEYBOARD_SPACE) {
	  MLV_wait_keyboard(&touche, NULL, NULL);
	}
      }
    }
    else {
      /* Aucun nom ne correspond à la recherche */
      affich_text_err_nom_bdd();
      continue;
    }
  }
  /* On libère le ResultSet */
  mysql_free_result(results);
  
  /* On stoppe la connection à la BDD */
  mysql_close(connect);
}
