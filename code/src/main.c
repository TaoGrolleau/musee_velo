#include "stdlib.h"
#include "stdio.h"
#include "mysql.h"

int main () {
  MYSQL *connect;
  MYSQL_RES *results;
  MYSQL_ROW line;
  
  connect = mysql_init(NULL);
  
  mysql_real_connect(connect, "localhost", "root", "rootsql", "Work", 0, NULL, 0);

  printf("%s\n%s\n%s\nCheckpoint\n", mysql_get_client_info(), mysql_get_host_info(connect), mysql_get_server_info(connect));

  printf("%d\n", mysql_query(connect, "SELECT * FROM Velo"));

  results = mysql_use_result(connect);
  line = mysql_fetch_row(results);

  printf("Resultat : %s %s %s\n", line[0], line[1], line[2]);
}
