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

    MLV_Font* font = MLV_load_font("/home/tao/musee_velo/musee_velo/arial.ttf",25);
    
    MLV_clear_window(MLV_COLOR_WHITE);
  
    MLV_draw_text_box_with_font(0,0,
                      width,height,
                      "Erreur lors de la connection à la base de données.\nPour plus de détails, consultez le fichier error.log.",
                                font,
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

    MLV_Font* font = MLV_load_font("/home/tao/musee_velo/musee_velo/arial.ttf",25);
  
    MLV_clear_window(MLV_COLOR_WHITE);
  
    MLV_draw_text_box_with_font(0,0,
                      width,height,
                      "Le nom que vous recherchez n'est pas dans la base de données.\nVous allez être redirigés sur la page de recherche.",
                                font,
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

    MLV_Font* font = MLV_load_font("/home/tao/musee_velo/musee_velo/arial.ttf",40);
    
    MLV_clear_window(MLV_COLOR_WHITE);

    MLV_draw_text_box_with_font(
        MLV_get_desktop_width()/2-350,300,
        700,200,
        "Est-ce que ta grand-mère fait du vélo ?",
        font,
        10,
        MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_COLOR_WHITE,
        MLV_TEXT_CENTER,
        MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
        );
    
    MLV_wait_input_box(
        MLV_get_desktop_width()/2-150,500,
        300,200,
        MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_COLOR_WHITE,
        "Nom de famille : ",
        &nom
        );
    
    MLV_actualise_window();

    return nom;
}

void affich_resultat(char* chaine, char* image) {
    int width = MLV_get_desktop_width();
    int height = MLV_get_desktop_height();
    int width_texte;
    int height_texte;
    MLV_Image* affichage;
    
    MLV_Font* font = MLV_load_font("/home/tao/musee_velo/musee_velo/arial.ttf",30);
    
    MLV_get_size_of_text(chaine, &width_texte, &height_texte);
    
    MLV_clear_window(MLV_COLOR_WHITE);

    MLV_draw_text_with_font(width/2-width_texte,height/2+height_texte*15,
                            chaine,
                            font,
                            MLV_COLOR_BLACK
        );
    
    affichage = MLV_load_image(image);

    MLV_draw_text(0,0,
                  "Appuyez sur la touche \'Espace\' pour retourner à la page de recherche.",
                  MLV_COLOR_BLACK
        );

    MLV_draw_image(affichage, width/2-MLV_get_image_width(affichage)/2, 80);

    printf("test\n");
  
    MLV_actualise_window();
}

void affich_resultat_ligne(char* chaine, int y) {
    int width = MLV_get_desktop_width();
    int height = MLV_get_desktop_height();

    MLV_Font* font = MLV_load_font("/home/tao/musee_velo/musee_velo/arial.ttf",20);
  
    MLV_draw_text_with_font(300, 100+y,
                  chaine,
                            font,
                  MLV_COLOR_BLACK
        );
    MLV_actualise_window();
}


char* affich_demande_prenom () {
    char* prenom;
    
    MLV_Font* font = MLV_load_font("/home/tao/musee_velo/musee_velo/arial.ttf",40);
  
    MLV_draw_text_with_font(
        300,20,
        "Merci de préciser le prénom (présent dans la liste ci-dessous)",
        font,
        MLV_COLOR_BLACK
        );
    MLV_wait_input_box(
        MLV_get_desktop_width()/2,600,
        200,90,
        MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_COLOR_WHITE,
        "Prénom : ",
        &prenom
        );

    MLV_actualise_window();

    return prenom;
}

void affich_text_err_prenom_bdd() {
    int width = MLV_get_desktop_width();
    int height = MLV_get_desktop_height();

    MLV_Font* font = MLV_load_font("/home/tao/musee_velo/musee_velo/arial.ttf",25);
  
    MLV_clear_window(MLV_COLOR_WHITE);
  
    MLV_draw_text_box_with_font(0,0,
                      width,height,
                      "Le prenom que vous recherchez n'est présent dans la liste.\nMerci de vérifier que vous l'avez bien orthografié.\nVous allez être redirigés sur la page de recherche.",
                      font,
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
