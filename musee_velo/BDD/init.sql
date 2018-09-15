drop table Velo;

create table Velo (
	numero INT PRIMARY KEY,
   	nom VARCHAR(30),
	prenom VARCHAR(20),
	image VARCHAR(20),
	texte VARCHAR(500)
);

LOAD DATA LOCAL INFILE '/home/tao/musee_velo/musee_velo/BDD/dat.txt' INTO TABLE Velo FIELDS TERMINATED BY '\t'  LINES TERMINATED BY '\n' IGNORE 1 LINES;
