#include "../inc/affichage.h"

void init_fenetre() {
  int width = MLV_get_desktop_width();
  int height = MLV_get_desktop_height();
  
  MLV_create_window("Vélo de grand-mère","Vélo de grand-mère", width, height);
  MLV_clear_window(MLV_COLOR_WHITE);
  MLV_actualise_window();
}

void affich_text_err_connec() {
  int width = MLV_get_desktop_width();
  int height = MLV_get_desktop_height();
  
  MLV_clear_window(MLV_COLOR_WHITE);
  
  MLV_draw_text_box(0,0,
		    width,height,
		    "Erreur lors de la connection à la base de données.\nPour plus de détails, consultez le fichier error.log.",
		    10,
		    MLV_COLOR_WHITE, MLV_COLOR_BLACK,
		    MLV_COLOR_WHITE,
		    MLV_TEXT_CENTER,
		    MLV_HORIZONTAL_CENTER,
		    MLV_VERTICAL_CENTER
		);
  
  MLV_actualise_window();
  MLV_wait_seconds(10);
  MLV_free_window();
}

void affich_text_err_nom_bdd() {
  int width = MLV_get_desktop_width();
  int height = MLV_get_desktop_height();
  
  MLV_clear_window(MLV_COLOR_WHITE);
  
  MLV_draw_text_box(0,0,
		    width,height,
		    "Le nom que vous recherchez n'est pas dans la base de données.\nVous allez être redirigés sur la page de recherche.",
		    10,
		    MLV_COLOR_WHITE, MLV_COLOR_BLACK,
		    MLV_COLOR_WHITE,
		    MLV_TEXT_CENTER,
		    MLV_HORIZONTAL_CENTER,
		    MLV_VERTICAL_CENTER
		);
  
  MLV_actualise_window();
  MLV_wait_seconds(3);
}

char* affich_demande () {
  char* nom;
  
  MLV_clear_window(MLV_COLOR_WHITE);
  
  MLV_draw_text_box(
                10,70,
                600,150,
                "Est-ce que ta grand-mère fait du vélo ?",
                9,
                MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
                MLV_TEXT_CENTER,
                MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
        );
  MLV_wait_input_box(
                10,280,
                200,90,
                MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
                "Nom de famille : ",
                &nom
        );

  MLV_actualise_window();

  return nom;
}

void affich_resultat(char* chaine) {
  int width = MLV_get_desktop_width();
  int height = MLV_get_desktop_height();
  
  MLV_clear_window(MLV_COLOR_WHITE);

  MLV_draw_text(width/2,height/2,
		chaine,
		MLV_COLOR_BLACK
		);

  MLV_draw_text(0,0,
		"Appuyez sur la touche \'Espace\' pour retourner à la page de recherche.",
		MLV_COLOR_BLACK
		);
  
  MLV_actualise_window();
}

void affich_resultat_ligne(char* chaine, int y) {
  int width = MLV_get_desktop_width();
  int height = MLV_get_desktop_height();
  
  MLV_draw_text(300, 100+y,
		chaine,
		MLV_COLOR_BLACK
		);
  MLV_actualise_window();
}


char* affich_demande_prenom () {
  char* prenom;
  
  MLV_draw_text(
                300,20,
                "Merci de préciser le prénom (présent dans la liste ci-dessous)",
                MLV_COLOR_BLACK
        );
  MLV_wait_input_box(
                10,280,
                200,90,
                MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
                "Prénom : ",
                &prenom
        );

  MLV_actualise_window();

  return prenom;
}

void affich_text_err_prenom_bdd() {
  int width = MLV_get_desktop_width();
  int height = MLV_get_desktop_height();
  
  MLV_clear_window(MLV_COLOR_WHITE);
  
  MLV_draw_text_box(0,0,
		    width,height,
		    "Le prenom que vous recherchez n'est présent dans la liste.\nMerci de vérifier que vous l'avez bien orthografié.\nVous allez être redirigés sur la page de recherche.",
		    10,
		    MLV_COLOR_WHITE, MLV_COLOR_BLACK,
		    MLV_COLOR_WHITE,
		    MLV_TEXT_CENTER,
		    MLV_HORIZONTAL_CENTER,
		    MLV_VERTICAL_CENTER
		);
  
  MLV_actualise_window();
  MLV_wait_seconds(5);
}
