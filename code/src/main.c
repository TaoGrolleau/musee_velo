#include "stdlib.h"
#include "stdio.h"
#include "mysql.h"
#include <MLV/MLV_all.h>

int main () {
  MYSQL *connect;
  MYSQL_RES *results;
  MYSQL_ROW line;

  int width = MLV_get_desktop_width();
  int height = MLV_get_desktop_height();

  char *text;
	
  
  connect = mysql_init(NULL);

  /* Connection à la BDD 'Work' avec l'ID 'root' et le MDP 'rootsql' */
  if(!mysql_real_connect(connect, "localhost", "root", "rootsql", "Work", 0, NULL, 0)) {
    fprintf(stderr, "%s\n", mysql_error(connect));
  }

  fprintf(stdout, "%s\n%s\n%s\nCheckpoint\n", mysql_get_client_info(), mysql_get_host_info(connect), mysql_get_server_info(connect));

  //Pas besoin !
  /* Création de la BDD 'Work', si déjà existante, n'écrase pas la précédente 
  fprintf(stdout, "%d %s\n", mysql_query(connect, "CREATE DATABASE Work"), mysql_error(connect));

  On se place dans la BDD Work 
  fprintf(stdout, "%d Connection à Work\n", mysql_query(connect, "use Work"));

  On crée la table Vélo et on insert les données
  printf("%d %s\n", mysql_query(connect, "source BDD/init.sql"), mysql_error(connect)); */

  /* Un exemple de requête SQL */
  fprintf(stdout, "%d\n", mysql_query(connect, "SELECT * FROM Velo"));

  results = mysql_use_result(connect);
  line = mysql_fetch_row(results);

  fprintf(stdout, "Resultat : %s %s %s\n", line[0], line[1], line[2]);

  /* On stoppe la connection à la BDD */
  mysql_close(connect);

  MLV_create_window("Affichage","Test", width, height);
  /* Empêche la fermeture instantanée */
  MLV_wait_mouse(0, 0);
}
